//////////////////////////////////////////////////////////////////////
// ��TGameObjMap���н�һ����װ����֧�����ݿ��¼��
// XSW, 2009.4.22
//˵��	1. ��װ�Ķ����������Ϸ�����һ���֧�����½ӿڣ�
//			Create(db::IRecord* pRes)��pRes������Ϸ����ӹ�
//			Update(bool bSync=true)
//////////////////////////////////////////////////////////////////////

#ifndef _TQ_TDBDATAMAP_H_
#define _TQ_TDBDATAMAP_H_

#include "DB/IDB.h"
#include "BaseCode/TGameObjMap.h"

NAMESPACE_BEGIN(tq)


template < typename T >
class TDBDataMap : public TGameObjMap < T >
{
    typedef typename TGameObjMap<T>::GETKEY GETKEY;
public:
    static TDBDataMap<T>*	CreateNew(bool bOwner = true, GETKEY fnGetKey = &T::GetKey) { return new TDBDataMap<T>(bOwner, fnGetKey); }

	//�������뷽ʽ
//	bool		Create(LPCTSTR szSQL, db::MODE eMode);
	bool		Create(db::IRecordset* pRes);	//�ɱ��ӿ��ͷ�
	bool		Create(db::REC_VEC& vec);		//�ɱ��ӿ��ͷ�

	void		SetAutoUpdate(bool bVal)					{ m_bAutoSave = bVal; }
	void		Update(bool bSync = true);
protected:
	TDBDataMap(bool bOwner, GETKEY fnGetKey) :TGameObjMap<T>(bOwner, fnGetKey), m_bAutoSave(true)	{}
	TDBDataMap() :TGameObjMap<T>(true, &T::GetKey), m_bAutoSave(true)						{}
	virtual ~TDBDataMap()								{ if (m_bAutoSave) Update(true); }
private:
	bool		m_bAutoSave;
};

//////////////////////////////////////////////////////////////////////
//template<class T>
//bool TDBDataMap<T>::Create(LPCTSTR szSQL, db::MODE eMode)
//{
//	db::IRecordset* pRecSet = db::InstanceGet().CreateRecordset(szSQL, eMode);
//	if (!this->Create(pRecSet))
//	{
//		return false;
//	}
//	return true;
//}

//////////////////////////////////////////////////////////////////////
template<class T>
bool TDBDataMap<T>::Create(db::IRecordset* pResSet)
{
	if (!pResSet)
		return false;
	for (unsigned int i = 0; i < pResSet->CountRecord(); i++)
	{
		pResSet->Move(i);
		db::IRecord* pRecord = pResSet->GetRecord();
		IF_NOT(pRecord)
			continue;

		T* pData = T::CreateNew();
		if (!pData)
		{
			SAFE_RELEASE(pRecord);
			SAFE_RELEASE(pResSet);
			return false;
		}

		if (!pData->Create(pRecord))
		{
			SAFE_RELEASE(pData);
			SAFE_RELEASE(pRecord);
			SAFE_RELEASE(pResSet);
			return false;
		}

		this->AddObj(pData);
	}

	SAFE_RELEASE(pResSet);
	return true;
}

//////////////////////////////////////////////////////////////////////
template	< class T >
bool TDBDataMap<T>::Create(db::REC_VEC& vec)
{
	for (db::REC_VEC::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		db::IRecord* pRecord = *it;
		IF_NOT(pRecord)
			continue;

		T* pData = T::CreateNew();
		if (!pData)
		{
			SAFE_RELEASE(pRecord);
			continue;
		}

		if (!pData->Create(pRecord))
		{
			SAFE_RELEASE(pRecord);
			continue;
		}

		this->AddObj(pData);
	}

	vec.clear();

	return true;
}

//////////////////////////////////////////////////////////////////////
template<class T>
void TDBDataMap<T>::Update(bool bSync/*=true*/)
{
	typename TGameObjMap<T>::Iterator pData = TGameObjMap<T>::NewEnum();
	while (pData.Next())
		pData->Update(bSync);
}




NAMESPACE_END(tq)

#endif 
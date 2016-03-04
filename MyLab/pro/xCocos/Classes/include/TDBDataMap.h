//////////////////////////////////////////////////////////////////////
// 对TGameObjMap进行进一步封装，以支持数据库记录集
// XSW, 2009.4.22
//说明	1. 封装的对象必须是游戏对象，且还需支持以下接口：
//			Create(db::IRecord* pRes)，pRes将被游戏对象接管
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

	//数据载入方式
//	bool		Create(LPCTSTR szSQL, db::MODE eMode);
	bool		Create(db::IRecordset* pRes);	//由本接口释放
	bool		Create(db::REC_VEC& vec);		//由本接口释放

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
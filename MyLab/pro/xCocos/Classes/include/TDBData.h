//////////////////////////////////////////////////////////////////////
// 封装数据库的单条数据操作
// XSW, 2009.4.22
//////////////////////////////////////////////////////////////////////

#ifndef _TQ_TDBDATA_H_
#define _TQ_TDBDATA_H_

#include <db/IDB.h>
#include "Macro.h"

NAMESPACE_BEGIN(tq)

//////////////////////////////////////////////////////////////////////////
//template TDBData
template<typename T>
class TDBData
{
public:
	static TDBData* CreateNew() 	{ TDBData* p = new TDBData; ASSERT(p); return p; }	\
	uint32_t	Release() 				{ delete this; return 0; }	\
public: // by set
	int64_t				GetKey()	const				{ IF_NOT(m_pRecord) return 0; return const_cast<db::IData&>(m_pRecord->Key()); }
public:
	db::IData&			Data(T idx);
	const db::IData&	Data(T idx) const;
	db::IData&			Data(const char* pszName);
	const db::IData&	Data(const char* pszName) const;
	
public:
	//数据载入方式
//	bool		Create(OBJID id, LPCTSTR pKey, LPCTSTR pTable, db::IDatabase& db, db::MODE eMode);
	bool		Create(db::IRecord* pRecord);

	//创建一条新数据
//	bool		Create(db::IDatabase& db, LPCTSTR pTable);
	
	db::IRecord* Clone();
	void		ClsEditFlag();
	bool		bValidRecord() const;
	bool		Update(bool bSync=true)					{ IF_NOT(m_pRecord)return false; return m_pRecord->Update(bSync); }
	bool		DestroyRecord(bool bSync = true)		{ IF_NOT(m_pRecord)return false; return m_pRecord->Delete(bSync); }
	bool		Insert(bool bSync = true)				{ IF_NOT(m_pRecord)return false; return m_pRecord->Insert(bSync); }
	
protected:
  	TDBData():m_pRecord(NULL){}
  	virtual ~TDBData(){SAFE_RELEASE(m_pRecord);}
protected:
	db::IRecord*	m_pRecord;
// 	TDBData(){}
// 	virtual ~TDBData(){}
// protected:
// 	tq::CAutoPtr<db::IRecord>	m_pRecord;
};


//////////////////////////////////////////////////////////////////////////
template<class T>
db::IData& TDBData<T>::Data(T idx)
{ 

	try
	{
		return m_pRecord->Field(idx); 
	}
	catch(...)
	{
		tq::LogSave("Module","%s %d enum=%s, idx=%d",__FILE__, __LINE__, typeid(T).name(), idx);
		throw "Data(idx) fail";
	}
}

//////////////////////////////////////////////////////////////////////////
template<class T>
const db::IData& TDBData<T>::Data(T idx) const
{ 
	try
	{
		return m_pRecord->Field(idx); 
	}
	catch(...)
	{
		tq::LogSave("Module","%s %d enum=%s, idx=%d",__FILE__, __LINE__, (typeid(T)).name(), idx);
		throw "const Data(idx) fail";
	}
}

//////////////////////////////////////////////////////////////////////////
template<class T>
db::IData& TDBData<T>::Data(const char* pszName)		
{ 
	try
	{
		return m_pRecord->Field(pszName); 
	}
	catch(...)
	{
		tq::LogSave("Module","%s %d enum=%s, idx=%s", __FILE__, __LINE__, typeid(T).name(), pszName);
		throw "Data(name) fail";
	}
}

//////////////////////////////////////////////////////////////////////////
template<class T>
const db::IData& TDBData<T>::Data(const char* pszName) const	
{ 
	try
	{
		return m_pRecord->Field(pszName); 
	}
	catch(...)
	{
		tq::LogSave("Module","%s %d enum=%s, idx=%s", __FILE__, __LINE__, typeid(T).name(), pszName);
		throw "const Data(name)";
	}
}

//////////////////////////////////////////////////////////////////////////
//template<class T>
//bool TDBData<T>::Create(OBJID id, LPCTSTR pKey, LPCTSTR pTable, db::IDatabase& db, db::MODE eMode)
//{
//	IF_NOT(pKey)
//	{
//		return false;
//	}
//	IF_NOT(pTable)
//	{
//		return false;
//	}
//	IF_NOT(!m_pRecord)
//	{
//		return false;
//	}
//
//	char sql[1024] = {0};
//	_snprintf(sql, sizeof(sql)-1, "select %s FROM %s", pKey, pTable);
//	
//	db::IRecordset* pRecSet = db.CreateRecordset(sql, eMode);
//	IF_NOT(pRecSet)
//	{
//		return false;
//	}
//	ASSERT(pRecSet->CountRecord() <= 1);	//id唯一检查
//	
//	if(pRecSet->CountRecord() >= 1)			//id不唯一时容错
//	{
//		m_pRecord = pRecSet->GetRecord();
//		ASSERT(m_pRecord);
//	}
//	SAFE_RELEASE(pRecSet);
//	return m_pRecord != NULL;
//}

//////////////////////////////////////////////////////////////////////////
template<class T>
bool TDBData<T>::Create(db::IRecord* pRecord)
{ 
	IF_NOT(pRecord)
	{
		return false;
	}
	IF_NOT(!m_pRecord)
	{
		return false;
	}
	m_pRecord = pRecord; 
	return m_pRecord != NULL; 
}

//////////////////////////////////////////////////////////////////////////
//template<typename T>
//bool TDBData<T>::Create(db::IDatabase& db, LPCTSTR pTable)
//{
//	IF_NOT(pTable)
//	{
//		return false;
//	}
//	IF_NOT(!m_pRecord)
//	{
//		return false;
//	}
//
//	m_pRecord = db.MakeDefRecord(pTable);
//	IF_NOT(m_pRecord)
//	{
//		return false;
//	}
//
////	if (!m_pRecord->Insert())
////	{
////		m_pRecord = NULL;	//由AutoPtr释放
////		return false;
////	}
//
//	return m_pRecord!=NULL;
//}

//////////////////////////////////////////////////////////////////////////
template<typename T>
db::IRecord* TDBData<T>::Clone()
{
	if (m_pRecord)
		return m_pRecord->Clone();
	else
		return NULL;
}

//////////////////////////////////////////////////////////////////////////
template<typename T>
void TDBData<T>::ClsEditFlag()
{
	IF_NOT(m_pRecord)
	{
		return;
	}
	m_pRecord->ClsEditFlag();
}

//////////////////////////////////////////////////////////////////////////
template<typename T>
bool TDBData<T>::bValidRecord() const
{
	return (m_pRecord != NULL);
}



NAMESPACE_END(tq)

#endif 
////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, TQ Digital Entertainment, 
// All Rights Reserved
//
// Author:  MILO
// Created: 12/08/2015
//
// Brief:   
////////////////////////////////////////////////////////////////////////
#pragma once

#include "DataModel/data/sqlEntity.h"
#include "Log.h"

#define DBOBJ_DECLARATION(TOBJ, TDB)	\
	public: \
		typedef TDB MyData;\
	public:	\
		static TOBJ* CreateNew(const MyData& data);\
	protected:\
		bool	Create(const MyData& data);\
	private:\
		MyData m_data;\

#define DBOBJ_IMPLEMENT(TOBJ)\
	TOBJ* TOBJ::CreateNew(const MyData& data)\
	{\
		TOBJ* pObj = TOBJ::CreateNew();\
		IF_NOT(pObj)\
		{\
			return NULL;\
		}\
		IF_NOT(pObj->Create(data))\
		{\
			SAFE_DELETE(pObj);\
			return NULL;\
		}\
		return pObj;\
	}\
	bool TOBJ::Create(const MyData& data)\
	{\
		m_data = data;\
		return true;\
	}

#define DBATTR_DECLARATION(ETYPE) \
	public:\
	typedef  std::map<ETYPE, std::string> DB_FIELD_MAP;\
	static DB_FIELD_MAP s_mapDbField;\
	private:\
	dbase::IType	GetDbAttr(ETYPE eKey) const;\
	dbase::IType	GetDbAttr(const std::string& strKey) const;\
	public:\
	I64				GetAttr(ETYPE eType)	const;\
	const char*		GetStr(ETYPE eType)		const;\
	double GetReal(ETYPE eType)	const;\

#define DBATTR_IMPLEMENT(TOBJ, ETYPE) \
	dbase::IType TOBJ::GetDbAttr(ETYPE eKey) const\
	{\
		DB_FIELD_MAP::const_iterator it = s_mapDbField.find(eKey);\
		IF_NOT(it != s_mapDbField.end())\
		{\
			tq::LogSave("DBATTR","%s %d ¡ïAttr:%d¡ï ", __FILE__, __LINE__, eKey);\
			return dbase::IType();\
		}\
		return m_data[it->second];\
	}\
	dbase::IType TOBJ::GetDbAttr(const string& strKey) const\
	{\
		return m_data[strKey];\
	}\
	I64 TOBJ::GetAttr(ETYPE eType) const\
	{\
		return (I64)(long long)GetDbAttr(eType);\
	}\
	const char* TOBJ::GetStr(ETYPE eType) const\
	{\
		return ((std::string)(GetDbAttr(eType))).c_str();\
	}\
	double TOBJ::GetReal(ETYPE eType) const\
	{\
		return GetDbAttr(eType);\
	}\


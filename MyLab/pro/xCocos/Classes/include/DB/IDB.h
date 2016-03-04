// ********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created: 2005/07/25
//
// ********************************************************************

#ifndef _DB_IDB_H_
#define _DB_IDB_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <limits.h>

////////////////////////////////////////////////////////////////////////
// MySQL��������ת������
//
// 1��MySQL�������͵ķ��ţ�Ҫ�ϸ�ƥ��C++�������͵ķ���
// 2��MySQL�������� �� C++�������� �Ķ�Ӧ��ϵ����:
//    MySQL��������    C++��������    �ֽ���
//     varchar          char*              
//     char             char           1byte
//     tinyint          char, bool     1byte
//     smallint         short          2byte
//     int, integer     int, long      4byte
//     bigint           _int64         8byte
//     float            float
//     double           double
//	   tinyblob         unsighed char* xxbyte
// 3���ֽ�������MySQL�������� �� �ֽ����̵�C++�������� ��ֵת��ʱ�����ܲ������ݽضϣ�
//    ���ݿ�ײ�ᱨ���棨Debugģʽ�������־��Releaseģʽ����
//    ��ֵ�������C++����������ʽת���Ĺ���
// 4������3�����ɱ���ʱ���ɲ�����ʽ��������ת�����Ժ������ݿ�ײ�ľ������־��
////////////////////////////////////////////////////////////////////////

#define DB_API


#include <Types.h>

namespace db
{

	struct DB_INFO
	{
		uint32_t dwTotalSQL;
		uint32_t dwSQLPer5Min;
		uint32_t dwSQLRunPer5Min;
		uint32_t dwSQLAvgPer5Min;
		uint32_t dwSQLMaxPer5Min;
		
		uint32_t dwSelectPer5Min;
		uint32_t dwSelectRunPer5Min;
		uint32_t dwSelectAvgPer5Min;
		uint32_t dwSelectMaxPer5Min;
		
		uint32_t dwUpdatePer5Min;
		uint32_t dwUpdateRunPer5Min;
		uint32_t dwUpdateAvgPer5Min;
		uint32_t dwUpdateMaxPer5Min;
		
		uint32_t dwInsertPer5Min;
		uint32_t dwInsertRunPer5Min;
		uint32_t dwInsertAvgPer5Min;
		uint32_t dwInsertMaxPer5Min;
		
		uint32_t dwDeletePer5Min;
		uint32_t dwDeleteRunPer5Min;
		uint32_t dwDeleteAvgPer5Min;
		uint32_t dwDeleteMaxPer5Min;
	};
	
	//////////////////////////////////////////////////////////////////////
	class DB_API IData
	{
	public:
		virtual	unsigned short	Release(void) = 0;

		// conversion function
		virtual					operator bool() const				= 0;

		virtual					operator char() const				= 0;
		virtual					operator unsigned char() const		= 0;

		virtual					operator short() const				= 0;
		virtual					operator unsigned short() const		= 0;
		
		virtual					operator long() const				= 0;
 		virtual					operator unsigned long() const		= 0;

		virtual					operator int() const				= 0;
		virtual					operator unsigned int() const		= 0;
		
		virtual					operator int64_t() const			= 0;
		virtual					operator uint64_t() const	= 0;
		
		virtual					operator float() const				= 0;
		virtual					operator double() const				= 0;
		
		virtual					operator char* () const				= 0;
		virtual					operator const char* () const		= 0;
		
		// overload assignment operator
		virtual IData&			operator = (bool bOp)				= 0;

		virtual IData&			operator = (char chOp)				= 0;
		virtual IData&			operator = (unsigned char chOp)		= 0;
		
		virtual IData&			operator = (short nOp)				= 0;
		virtual IData&			operator = (unsigned short unOp)	= 0;
		
		//virtual IData&			operator = (long lOp)				= 0;
		//virtual IData&			operator = (unsigned long lOp )		= 0;
		
		virtual IData&			operator = (int iOp)				= 0;
		virtual IData&			operator = (unsigned int uOp)		= 0;
		
		virtual IData&			operator = (int64_t uOp)			= 0;
		virtual IData&			operator = (uint64_t uOp)	= 0;
		
		virtual IData&			operator = (float fltOp)			= 0;
		virtual IData&			operator = (double dblOp)			= 0;
		
		virtual IData&			operator = (const char* szVal)		= 0;
	};
	
    const UINT INVALID_KEY = UINT_MAX;
	//////////////////////////////////////////////////////////////////////
	class DB_API IRecord
	{
	public:
		virtual	unsigned short	Release		(void)					= 0;

		// return field data by field index
		virtual IData&			Field		(unsigned int idx)		= 0;
		virtual IData&			Field		(unsigned int idx) const= 0;
		
		// return field data by field name
		virtual IData&			Field		(const char* pszName)	= 0;
		virtual IData&			Field		(const char* pszName) const= 0;
		
		// return the key data of this record
		virtual IData&			Key			(void)					= 0;
		virtual IRecord*		Clone		(void)					= 0;
		
		// ͨ�� UPDATE ��������� �޸Ĺ� �����ݵ����ݿ⣬
		// ȱʡʹ��ͬ����ʽ��������Ҫ�ȴ����ݿ������ɺ󷵻ء�
		// Ҳ��ָ���첽��ʽ�������߲���Ҫ�ȴ����ݿ������ɣ�ֱ�ӷ���true
		virtual bool			Update		(bool bSync = true)		= 0;
		virtual bool			Delete		(bool bSync = true)		= 0;
		virtual bool			Insert		(bool bSync = true)		= 0;
		
		// clear the edit flag of all field in this record, so update operation will ignored.
		virtual void			ClsEditFlag	(void)					= 0;


	};
	
	//////////////////////////////////////////////////////////////////////
	class DB_API IRecordset
	{
	public:
		virtual	unsigned short	Release		(void)					= 0;

        // return field data of current record
        virtual IData&			RecordField	(unsigned int idx)		= 0;
        virtual IData&			RecordField	(unsigned int idx) const= 0;
        virtual IData&			RecordField	(const char* pszName)	= 0;
        virtual IData&			RecordField	(const char* pszName) const= 0;
        virtual IData&			RecordKey	(void)					= 0;
        
        // move to specified record
        virtual void			Move		(unsigned int index)	= 0;

        // get a new record from record set 
		virtual IRecord*		GetRecord	(void)					= 0;
		
		// count record in set.	 return -1: error
		virtual unsigned long	CountRecord	(void) const			= 0;
	};
	
	//////////////////////////////////////////////////////////////////////
	enum MODE { MODE_NONE = 0,	MODE_READ, 	MODE_EDIT };
	typedef	std::vector<IRecord*>	REC_VEC;
	class DB_API IDatabase
	{
	public:
		virtual	unsigned short	Release(void)										= 0;
		
		// make a new default record by "insert" sql.
		virtual IRecord*		MakeDefRecord(const char* szTable)					= 0;
		
		// create a record by specified "select" sql
		virtual IRecord*		CreateRecord(const char* szSQL, MODE eMode)			= 0;
		
		// create a record set by specified "select" sql
		virtual IRecordset*		CreateRecordset(const char* szSQL, MODE eMode)		= 0;
		
		// create a record set by specified "select" sql
		virtual bool			PreCreateRecordset(OBJID idKey, const char* szSQL)	= 0;
		
		// create a record set by specified "select" sql
		virtual bool    		QueryRecordset(OUT REC_VEC& rSetRecord, OBJID idKey, const char* szSQL)	= 0;
		
		//add by ccw
		virtual bool			LoadMemRecordset(int nKey1, int nKey2, const char* szSQL, bool bCreateDefult = false)				= 0;
		virtual bool    		QueryMemRecordset(OUT REC_VEC& rSetRecord, int nKey1, int nKey2, bool bReleaseOwner = true)			= 0;

		virtual void			FreeMemRecordset(int nKey1)											= 0;
		virtual void			FreeMemRecordset(int nKey1, int nKey2)								= 0;
		
		// execute a SQL statement, default synchronic
		virtual bool			ExecuteSQL(const char* pszSQL, bool bSync = true)	= 0;
        
		// ping
		virtual	bool			Ping(void)											= 0;

        virtual bool			IsDeadline(void)									= 0;
        virtual I64             GetLastInsertedID(void)								= 0;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	// create IDatabase interface
	//////////////////////////////////////////////////////////////////////
	extern "C" DB_API bool			DatabaseInit(void);
	extern "C" DB_API void			DatabaseUnInit(void);
	extern "C" DB_API IDatabase&	InstanceGet(void);
	extern "C" DB_API bool			InstanceDelete(void);
	extern "C" DB_API void			StatInfoUpdate(DB_INFO& infoDB);
	
}


#endif // end of define _DB_IDB_H_


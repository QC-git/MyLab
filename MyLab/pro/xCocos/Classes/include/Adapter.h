////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, TQ Digital Entertainment, 
// All Rights Reserved
//
// Author:  ZH/MILO
// Created: 11/26/2015
//
// Brief:   原来INI转换为SQLite的适配接口
////////////////////////////////////////////////////////////////////////
#pragma once

#include "Define.h"
#include "DataModel/dbutils.h"

namespace tq
{
	/************************************************************************/
	//使用CSqlIni例子 根据数据库的数据初始化后，可以获取KEY值，及其根据字段名获取字段值
	/************************************************************************/

	template <class T/*, const std::string& KeyFieldName = "_id"*/>
	class CSqlIni
	{
	public:
		CSqlIni(T& cData): m_cData(cData){}
		~CSqlIni() {}

		const char* GetKeyName() const
		{
			std::string data = m_cData["_id"/*KeyFieldName*/];
			return data.c_str();
		}

		const char* Change(char* buffer, const char* valuename) const
		{
			sprintf(buffer, "_%s", valuename);
			size_t len = strlen(buffer);
			for (int i = 0; i < len; i++)
			{
				buffer[i] = tolower(buffer[i]);
			}
			return buffer;
		}

		std::string GetValue(const char* keyname, const char* valuename)
		{
			char buffer[32] = { 0 };
			const char* str = Change(buffer, valuename);
			std::string data = m_cData[str];
			return data;
		}

		std::string GetValueEx(const char* keyname, const char* valuename)
		{
			char buffer[32] = { 0 };
			const char* str = Change(buffer, valuename);
			std::string data = m_cData[str];
			return data;
		}

		int GetValueI(const char* keyname, const char* valuename)
		{
			char buffer[32] = {0};
			const char* str = Change(buffer, valuename);
			return dbase::to<int>(m_cData[str]);
		}

		int GetValueIByKey(const std::string& valuename)
		{
			return dbase::to<int>(valuename.c_str());
		}

		double GetValueF(const char* keyname, const char* valuename)
		{
			char buffer[32] = { 0 };
			const char* str = Change(buffer, valuename);
			return dbase::to<double>(m_cData[str]);
		}

		int GetValueHex(const char* keyname, const char* valuename)
		{
			int hex;
			std::string val = GetValueEx(keyname, valuename);
            const char *p = val.c_str();
			if ('\0' == *p)
			{
				hex = 0;
			}
			else
			{
				sscanf(p, "%X", &hex);
			}
			return hex;
		}

		const T& GetData()
		{
			return m_cData;
		}

	private:
		T& m_cData;
	};

	/************************************************************************/
	//使用CSqlIniAdapter例子 根据传入的KEY值和每个字段的字段名获取字段值
	/************************************************************************/

	template<typename T >
	class CSqlIniAdapter
	{
	public:
		typedef bool(*GET_DB_RESULT)(const std::string&, T&);

	public:
		CSqlIniAdapter(GET_DB_RESULT fnGetDbResult) : m_fnGetDbResult(fnGetDbResult) {}
		virtual ~CSqlIniAdapter() {}

	public:
		const char* Change(char* buffer, const char* valuename) const
		{
			sprintf(buffer, "_%s", valuename);
			size_t len = strlen(buffer);
			for (int i = 0; i < len; i++)
			{
				buffer[i] = tolower(buffer[i]);
			}
			return buffer;
		}

		const char* GetValue(const string& keyname, const string& valuename, const char* defaultValue = nullptr)
		{
			return GetValue(keyname.c_str(), valuename.c_str(), defaultValue);
		}

		const char* GetValue(const char* keyname, const char* valuename, const char* defaultValue = nullptr)
		{
			IF_NOT(m_fnGetDbResult)
			{
				return defaultValue;
			}

			IF_NOT(m_fnGetDbResult(keyname, m_data))
			{
				return defaultValue;
			}

			char buffer[32];
			const char* str = Change(buffer, valuename);

			std::string data = m_data[str];
			return data.c_str();
		}

		int GetValueI(const char* keyname, const char* valuename, int defaultValue = 0)
		{
			IF_NOT(m_fnGetDbResult)
			{
				return defaultValue;
			}

			IF_NOT(m_fnGetDbResult(keyname, m_data))
			{
				return defaultValue;
			}

			char buffer[32];
			const char* str = Change(buffer, valuename);

			return dbase::to<int>(m_data[str]);
		}

		double GetValueF(const char* keyname, const char* valuename, double defaultValue = 0.0)
		{
			IF_NOT(m_fnGetDbResult)
			{
				return defaultValue;
			}

			IF_NOT(m_fnGetDbResult(keyname, m_data))
			{
				return defaultValue;
			}

			char buffer[32] = {0};
			const char* str = Change(buffer, valuename);

			return dbase::to<double>(m_data[str]);
		}

		double GetValueF(const string& keyname, const string& valuename, double defaultValue = 0)
		{
			return GetValueF(keyname.c_str(), valuename.c_str(), defaultValue);
		}

	private:
		GET_DB_RESULT m_fnGetDbResult;
		T m_data;
	};

} //namespace tq

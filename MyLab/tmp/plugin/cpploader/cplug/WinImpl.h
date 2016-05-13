
#ifndef CWIN_LOADER_H_
#define CWIN_LOADER_H_

#include <Windows.h>
#include "Log.h"
#include <string>

typedef LogOutput (*InitLogFunc) (unsigned int leastLvl, const char* name, LogOutput output);
typedef bool (*CreateFunc) (const char* sid, const char* env);
typedef void (*UpdateFunc) (void);
typedef void (*DestoryFunc) (void);

class CWinLoader
{
public:
	CWinLoader()
		:m_hins(NULL)
        ,m_pInitLogFunc(NULL)
        ,m_pCreateFunc(NULL)
        ,m_pUpdateFunc(NULL)
        ,m_pDestoryFunc(NULL)
	{

	}

	~CWinLoader()
	{
        if(m_hins)
        {
            FreeLibrary(m_hins);
            m_hins = NULL;
            m_pUpdateFunc = NULL;
        }
	}

public:
    bool Load(const char* module)
    {
        LOG_TRC("Enter CServerPlugLoader::Create");
        std::string path("./cpp_modules/");
        path+=module;
        path+=".dll";

        m_hins = LoadLibrary(path.c_str());
        if(NULL == m_hins)
        {
            LOG_ERR("LoadLibrary fail");
            DWORD dwCode = GetLastError();
            LOG_ERR("the errCode is %d", dwCode);
            return false;
        }

        m_pInitLogFunc = (InitLogFunc)GetProcAddress(m_hins, "InitLogEngine");
        m_pCreateFunc  = (CreateFunc)GetProcAddress(m_hins, "Create");
        m_pUpdateFunc  = (UpdateFunc)GetProcAddress(m_hins, "Update");
        m_pDestoryFunc = (DestoryFunc)GetProcAddress(m_hins, "Destory");
        if(!m_pUpdateFunc || !m_pCreateFunc || !m_pUpdateFunc || !m_pDestoryFunc)
        {
            LOG_ERR("cannot find the module's update ProcAddr");
            DWORD dwCode = GetLastError();
            LOG_ERR("the errCode is %d", dwCode);
			return false;
        }
        LOG_TRC("Exit CServerPlugLoader::Create");
		return true;
    }

    
    LogOutput InitLog(unsigned int logLev, const char* name)
    {
		if(!m_pInitLogFunc)
			return NULL;

        try
        {
            return m_pInitLogFunc(logLev, name, NULL);
        }
        catch (...)
        {
            LOG_ERR("CServerPlugLoader::InitLog fail");
            return NULL;
        }
    }

	bool Create(const char* sid, const char* env)
	{
        LOG_TRC("Enter CServerPlugLoader::Create");
		if(!m_pCreateFunc)
			return false;

        try
        {
            return m_pCreateFunc(sid, env);
        }
        catch (...)
        {
            LOG_ERR("CServerPlugLoader::Create fail");
            return false;
        }
		LOG_TRC("Enter CServerPlugLoader::Create");
	}

	void Destory()
	{
		if(!m_pDestoryFunc)
			return;

        LOG_TRC("Enter CServerPlugLoader::Destory");
        try
        {
            m_pDestoryFunc();
        }
        catch (...)
        {
            LOG_ERR("CServerPlugLoader::Destory fail");
        }
        LOG_TRC("Enter CServerPlugLoader::Destory");
	}

	void Update()
	{
		if(!m_pUpdateFunc)
			return;

		try
		{
			m_pUpdateFunc();
		}
		catch (...)
		{
			//todo
		}
	}

private:
    InitLogFunc m_pInitLogFunc;
    CreateFunc	m_pCreateFunc;
    UpdateFunc	m_pUpdateFunc;
    DestoryFunc	m_pDestoryFunc;
	HINSTANCE	m_hins;
};

#endif

#ifndef CLINUX_LOADER_H_
#define CLINUX_LOADER_H_

#include "Log.h"
#include <string>
#include <dlfcn.h>


typedef LogOutput (*InitLogFunc) (unsigned int leastLvl, const char* name, LogOutput output);
typedef bool (*CreateFunc) (const char* sid, const char* env);
typedef void (*UpdateFunc) (void);
typedef void (*DestoryFunc) (void);

class CLinuxLoader
{
public:
	CLinuxLoader()
		:m_hins(NULL)
        ,m_pInitLogFunc(NULL)
        ,m_pCreateFunc(NULL)
        ,m_pUpdateFunc(NULL)
        ,m_pDestoryFunc(NULL)
	{

	}

	~CLinuxLoader()
	{
        if(m_hins)
        {
            dlclose(m_hins);
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
        path+=".so";

        m_hins = dlopen(path.c_str(), RTLD_LAZY);
        if(NULL == m_hins)
        {
            LOG_ERR("dlopen fail");
            char* error = dlerror();
            if(error != NULL)
            {
                LOG_ERR("the err is %s", error);
            }
            return false;
        }

        m_pInitLogFunc = (InitLogFunc)dlsym(m_hins, "InitLogEngine");
        m_pCreateFunc  = (CreateFunc)dlsym(m_hins, "Create");
        m_pUpdateFunc  = (UpdateFunc)dlsym(m_hins, "Update");
        m_pDestoryFunc = (DestoryFunc)dlsym(m_hins, "Destory");
        if(!m_pUpdateFunc || !m_pCreateFunc || !m_pUpdateFunc || !m_pDestoryFunc)
        {
            LOG_ERR("cannot find the module's update ProcAddr");
            char* error = dlerror();
            if(error != NULL)
            {
                LOG_ERR("the errCode is %s", error);
            }
			return false;
        }
        LOG_TRC("Exit CServerPlugLoader::Create");
		return true;
    }

    
    LogOutput InitLog(unsigned int logLev, const char* name)
    {
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
	void        *m_hins;
};

#endif

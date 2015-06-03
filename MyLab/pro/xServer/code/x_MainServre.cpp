#include "x_MainServre.h"

#include "x_util.h"
#include "x_container.h"
#include "x_thread.h"
//#include "x_boost.h"
 
#pragma comment(lib, "xService.lib")

unsigned int ServerVersion()
{
	static U8_T uX = 1;
	static U8_T uY = 0;
	static U8_T uZ = 0;

	return 10000 * uX + 100 * uY + uZ;
}

X_SERVER_BEGIN

CMainServer::CMainServer()
{
	LOGD_F("CMainServer::CMainServer()");

}

CMainServer::~CMainServer()
{
	LOGD_F("CMainServer::~CMainServer()");

}

IModule* g_pModule1 = NULL;
IModule* g_pModule2 = NULL;

ERR_T  CMainServer::OnInit()
{
	LOGD_F("CMainServer::OnInit()");

	const CHAR_T* sModule1 = "xModuleA.dll";
	const CHAR_T* sModule2 = "xModuleB.dll";
	
	typedef IModule* (*FUNC_GET_MODULE_INSTANCE)();

	STATUS_T nStatus = 0;
	do 
	{
		nStatus--;
		{
			HMODULE hMod = ::LoadLibrary(sModule1);
			if ( NULL == hMod ) break;
			
			FUNC_GET_MODULE_INSTANCE func = (FUNC_GET_MODULE_INSTANCE)::GetProcAddress(hMod, "GetModuleInstance");
			if ( !func ) break;
			
			IModule* pMod = func();
			if ( NULL == pMod ) break;

			if ( 0 != pMod->Init(this) ) break;

			pMod->Register();

			g_pModule1 = pMod;
		}

		nStatus--;
		{
			HMODULE hMod = ::LoadLibrary(sModule2);
			if ( NULL == hMod ) break;

			FUNC_GET_MODULE_INSTANCE func = (FUNC_GET_MODULE_INSTANCE)::GetProcAddress(hMod, "GetModuleInstance");
			if ( !func ) break;

			IModule* pMod = func();
			if ( NULL == pMod ) break;

			if ( 0 != pMod->Init(this) ) break;

			pMod->Register();

			g_pModule2 = pMod;
		}

		g_pModule1->MethodInit();
		g_pModule2->MethodInit();

		return 0;
	} while (false);


	return nStatus;
}

VOID_T CMainServer::OnDestroy()
{
	LOGD_F("CMainServer::OnDestroy()");
	if (g_pModule1)
	{
		g_pModule1->Destroy();
	}
	if (g_pModule2)
	{
		g_pModule2->Destroy();
	}

}

ERR_T  CMainServer::OnStart()
{
	LOGD_F("CMainServer::OnStart()");

	g_pModule1->Send(g_pModule2);  //test
	g_pModule2->Send(g_pModule1);

	return 0;
}

VOID_T CMainServer::OnStop()
{
	LOGD_F("CMainServer::OnStop()");

}

ERR_T CMainServer::OnConfigure(VOID_T* pObj)
{
	LOGD_F("CMainServer::OnConfigure()");

	return -1;
}

VOID_T CMainServer::OnStep()
{
	LOGD_F("CMainServer::OnStep()");

}

ERR_T CMainServer::OnRecieve(VOID_T* pObj)
{
	LOGD_F("CMainServer::OnRecieve() pObj = %d", pObj);

	return -1;
}


ERR_T CMainServer::OnBind()
{
	LOGD_F("CMainServer::OnBind()");

	return -1;
}

IServer* GetServerInstance()
{
	static CMainServer g_cMainServer;

	return (IServer*)&g_cMainServer;
}

X_SERVER_END
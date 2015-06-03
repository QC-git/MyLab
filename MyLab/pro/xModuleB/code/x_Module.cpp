#include "x_Module.h"

#include "x_util.h"
#include "x_container.h"
#include "x_thread.h"
//#include "x_boost.h"

#pragma comment(lib, "xService.lib")

X_SERVER_NAME::IServer* g_pServer = NULL;

CModuleImpl::CModuleImpl()
{
	LOGD_F("CModuleImpl::CModuleImpl(), module = %s", X_MODULE_NAME);
	
}

CModuleImpl::~CModuleImpl()
{
	LOGD_F("CModuleImpl::~CModuleImpl(), module = %s", X_MODULE_NAME);

}

ERR_T  CModuleImpl::OnInit(X_SERVER_NAME::IServer* pServer)
{
	LOGD_F("CModuleImpl::OnInit(), module = %s", X_MODULE_NAME);
	if ( NULL != g_pServer || NULL == pServer )
		return -1;

	pServer->Send((VOID_T*)222);
	g_pServer = pServer;

	return 0;
}

VOID_T CModuleImpl::OnDestroy()
{
	LOGD_F("CModuleImpl::OnDestroy(), module = %s", X_MODULE_NAME);

}

VOID_T CModuleImpl::OnCallToRegister()
{
	LOGD_F("CModuleImpl::OnCallToRegister(), module = %s", X_MODULE_NAME);

}

VOID_T CModuleImpl::OnCallToMethodInit()
{
	LOGD_F("CModuleImpl::OnCallToMethodInit(), module = %s", X_MODULE_NAME);

}

ERR_T CModuleImpl::OnRecieve(VOID_T* pObj)
{
	LOGD_F("CModuleImpl::OnRecieve(), ((CModuleImpl*)pObj)->Test(), module = %s", X_MODULE_NAME);
	((CModuleImpl*)pObj)->Test();
	return 0;
}

VOID_T CModuleImpl::OnCallToTest()
{
	LOGD_F("Hello ! here is %s", X_MODULE_NAME);
}

X_SERVER_NAME::IModule* GetModuleInstance() 
{
	static CModuleImpl cModule;
	return (X_SERVER_NAME::IModule*)(&cModule);
}
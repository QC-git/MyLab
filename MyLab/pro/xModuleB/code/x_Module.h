#pragma once

#include "x_util.h"
#include "x_Interface.h"

#define X_MODULE_NAME "ModuleB"

class CModuleImpl : public X_SERVER_NAME::IModule
{
public:
	CModuleImpl();
	virtual ~CModuleImpl();

public:
	//@override
	X_ERR  Init(X_SERVER_NAME::IServer* pServer) { return (ERR_T)this->OnInit(pServer); }

	//@override
	X_VOID Destroy() { OnDestroy(); }

	//@override
	X_VOID Register() { OnCallToRegister(); }

	//@override
	X_VOID MethodInit() { OnCallToMethodInit(); }

	//@override
	virtual X_ERR Send(X_OBJ pObj) { return OnRecieve(pObj); }

	//@override
	virtual X_VOID Test() { OnCallToTest(); }

protected:
	virtual ERR_T  OnInit(X_SERVER_NAME::IServer* pServer);

	virtual VOID_T OnDestroy();

	virtual VOID_T OnCallToRegister();

	virtual VOID_T OnCallToMethodInit();

	virtual ERR_T  OnRecieve(VOID_T* pObj);

	virtual VOID_T OnCallToTest();

};

extern "C" X_SERVICE_EXPORT X_SERVER_NAME::IModule* GetModuleInstance();
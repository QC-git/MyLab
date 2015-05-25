#pragma once

#include "x_util.h"
#include "include/x_Interface.h"

X_SERVER_BEGIN

class CMainServer: public IServer
{
public:
	CMainServer();
	virtual ~CMainServer();

public:
	X_ERR  Init() { return (X_ERR)this->OnInit(); }
	X_VOID Destroy() { this->OnDestroy(); }

	X_ERR  Start() { return (X_ERR)this->OnStart(); }
	X_VOID Stop() { this->OnStop(); }

	X_ERR Set(X_OBJ pObj) { return(X_ERR)this->OnConfigure((VOID_T*)pObj); }

	X_VOID Step() { this->OnStep(); }

	X_ERR Send(X_OBJ pObj) { return (X_ERR)this->OnRecieve((VOID_T*)pObj); }

	X_ERR Bind() { return (X_ERR)this->OnBind(); }

protected:
	virtual ERR_T  OnInit();
	virtual VOID_T OnDestroy();

	virtual ERR_T  OnStart();
	virtual VOID_T OnStop();

	virtual ERR_T OnConfigure(VOID_T* pObj);

	virtual VOID_T OnStep();

	virtual ERR_T OnRecieve(VOID_T* pObj);

	virtual ERR_T OnBind();

};








X_SERVER_END
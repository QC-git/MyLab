#pragma once

#define X_SERVER_NAME x_server
#define X_SERVER_BEGIN namespace X_SERVER_NAME{
#define X_SERVER_END   }
#define X_SERVICE_EXPORT __declspec(dllexport)
#define X_VOID void
#define X_ERR int
#define X_OBJ void*

X_SERVICE_EXPORT unsigned int ServerVersion();

// �ӿ�I��ѡ����Я����Я���߱�����ָ����ʽ����

X_SERVER_BEGIN
class X_SERVICE_EXPORT IServer
{
public:
	virtual X_ERR  Init() = 0;
	virtual X_VOID Destroy() = 0;

	virtual X_ERR  Start() = 0;
	virtual X_VOID Stop() = 0;

	virtual X_ERR Set(X_OBJ) = 0;

	virtual X_VOID Step() = 0;

	virtual X_ERR Send(X_OBJ) = 0;

	virtual X_ERR Bind() = 0;

protected:
	IServer() {;}
	virtual ~IServer() {;}

};

class X_SERVICE_EXPORT IModule
{
public:
	virtual X_ERR  Init(IServer* pServer) = 0;
	virtual X_VOID Destroy() = 0;

	virtual X_VOID Register() = 0;      // ע��������
	virtual X_VOID MethodInit() = 0;    // ��ȡ����ģ�麯��

	virtual X_ERR  Send(X_OBJ) = 0;

	virtual X_VOID Test() = 0;

protected:
	IModule() {;}
	virtual ~IModule() {;}

};

X_SERVICE_EXPORT IServer* GetServerInstance();

#define X_HSER	x_server::GetServerInstance()

X_SERVER_END
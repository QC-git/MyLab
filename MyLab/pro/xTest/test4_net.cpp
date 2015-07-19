
#include "xTest.h"


class CListenHandler : public X::CNetHanlder
{
public:
	CListenHandler() {;}
	~CListenHandler() {;}

public:
	virtual VOID_T OnAccept(X::CNetPoint* pNewPonit)
	{

		LEN_T uLen = 0;
		ERR_T nErr = pNewPonit->Write("welcome to net1", strlen("welcome to net1")+1, uLen);
		LOG_F("pNewPonit->Write, nErr = %d, uLen = %d", nErr, uLen);
		while(true)
		{
			X::Sleep_f(1);
		}

		delete pNewPonit;
	}

	virtual VOID_T OnRecieve(X::CNetIp* pRemoteIp, CHAR_T* pData, LEN_T uDataLen)
	{
		;
	}

};


void TaskFunc(void*)
{
	CListenHandler cb;
	X::CNetIp* pIp = X::NetManager()->CreateIp("127.0.0.1", 1234);
	HANDLE_T h = X::NetManager()->CreateListener(X::EM_NET_TCP, pIp, &cb);

	LOG_F("X::NetManager()->CreateListener(), h = %d", h);
}
X::CThreadCreater g_cThreadCreater;



void test_net()
{

	{
		//X::NetManager()->Local(X::EM_NET_MANAGER_BOOST);
		X::NetManager()->Local(X::EM_NET_MANAGER_KBE);

		g_cThreadCreater.CreateThread(TaskFunc, NULL);

		X::Sleep_f(5000);
		X::CNetIp* pIp = X::NetManager()->CreateIp("127.0.0.1", 1234);
		X::CNetPoint* pNetP = X::NetManager()->CreatePoint();
		pNetP->Connect(pIp);

		//X::Sleep_f(5000);
		CHAR_T pBuffer[100];
		pBuffer[99] = '\0';
		LEN_T uLen = 0;
		ERR_T nErr = pNetP->Read(pBuffer, 99, uLen);
		LOG_F("pNetP->Read, nErr = %d, uLen = %d, %s", nErr, uLen, pBuffer);


	}

	while(true)
	{
		X::Sleep_f(1);
	}
}
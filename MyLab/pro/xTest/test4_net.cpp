
#include "xTest.h"

namespace space_test_net
{



class CListenCallBack : public X::CNetListener::CallBack
{
public:
	CListenCallBack() {;}
	~CListenCallBack() {;}

public:
	virtual VOID_T OnAccept(X::CNetPoint* pNewPonit)
	{

		LEN_T uLen = 0;
		const CHAR_T* sMsg = "welcome to X::net";
		ERR_T nErr = pNewPonit->Write(sMsg, strlen(sMsg)+1, uLen);
		LOG_F("pNewPonit->Write, nErr = %d, uLen = %d", nErr, uLen);
		while(true)
		{
			X::Sleep_f(1);
		}

		delete pNewPonit;
	}

};


void TaskFunction(void*)
{
	CListenCallBack cb;
	ERR_T nRet;

	X::CNetIp* pIp = X::NetManager()->CreateIp("127.0.0.1", 1234);
	X::CNetListener* pListener = X::NetManager()->CreateListener(X::ENetType_TCP);

	nRet = pListener->Listen(pIp);
	assert(0==nRet);

	nRet = pListener->Run(&cb);
	assert(0==nRet);

}
X::CThreadCreater g_cThreadCreater;

}

void test_net()
{

	{
		X::NetManager()->Local(X::ENetManagerType_BOOST);
		//X::NetManager()->Local(X::ENetManagerType_KBE);

		space_test_net::g_cThreadCreater.CreateThread(space_test_net::TaskFunction, NULL);

		X::Sleep_f(5000);
		X::CNetIp* pIp = X::NetManager()->CreateIp("127.0.0.1", 1234);
		X::CNetPoint* pNetP = X::NetManager()->CreatePoint();
		pNetP->Connect(pIp);

		X::Sleep_f(5000);
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
// xTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <windows.h>

// #include "x_dummy.h"
// #include "x_util.h"
// #include "x_thread.h"
// #include "x_container.h"
// #include "x_net.h"

#include "x_all.h"

#include "x_Interface.h"
#include<windows.h>
 
#pragma comment(lib, "xService.lib")
#pragma comment(lib, "xServer.lib")

namespace hhhh
{

#include <stdio.h>
	typedef signed char             S8ss_T;
	void func()
	{
		;
	}
#define FUNC hhhh::func
}

// stl 特化参考
// template <class _Iterator>
// struct iterator_traits {
// 	typedef typename _Iterator::iterator_category iterator_category;
// 	typedef typename _Iterator::value_type        value_type;
// 	typedef typename _Iterator::difference_type   difference_type;
// 	typedef typename _Iterator::pointer           pointer;
// 	typedef typename _Iterator::reference         reference;
// };
// 
// // specialize for _Tp*
// template <class _Tp>
// struct iterator_traits<_Tp*> {
// 	typedef random_access_iterator_tag iterator_category;
// 	typedef _Tp                         value_type;
// 	typedef ptrdiff_t                   difference_type;
// 	typedef _Tp*                        pointer;
// 	typedef _Tp&                        reference;
// };
// 
// // specialize for const _Tp*
// template <class _Tp>
// struct iterator_traits<const _Tp*> {
// 	typedef random_access_iterator_tag iterator_category;
// 	typedef _Tp                         value_type;
// 	typedef ptrdiff_t                   difference_type;
// 	typedef const _Tp*                  pointer;
// 	typedef const _Tp&                  reference;
// };


template <typename T> 
class Singleton
{
protected:
	static T* singleton_;

public:
	Singleton(void)
	{
		assert(!singleton_);
		singleton_ = static_cast< T* >(this);
	}


	~Singleton(void){  assert(singleton_);  singleton_ = 0; }

	static T& getSingleton(void) { assert(singleton_);  return (*singleton_); }
	static T* getSingletonPtr(void){ return singleton_; }

	//template <>	 TYPE * Singleton< TYPE >::singleton_ = 0;
};

#define KBE_SINGLETON_INIT( TYPE )							\
	template <>	 TYPE * Singleton< TYPE >::singleton_ = 0;	\

#define KBE_SINGLETON_INIT_TEST( TYPE )							\
	TYPE * Singleton< TYPE >::singleton_ = 0;	   // 特化与非特化区别 ？ 经测试带不带都可以 ~~, 区别于类或函数特化 ~~


class CHello
{
public:
	CHello() {;}
	~CHello() {;}

public:
	int Value() { return 123; }

};

class CHello2
{
public:
	CHello2() {;}
	~CHello2() {;}

public:
	int Value() { return 123; }

};

template<int a>
struct A
{
	static int n;
};

// A<1> g1;
// A<2> g2;

KBE_SINGLETON_INIT_TEST(CHello)
//KBE_SINGLETON_INIT_TEST(CHello)
//KBE_SINGLETON_INIT(CHello)

// KBE_SINGLETON_INIT(CHello)
// KBE_SINGLETON_INIT(CHello2)

//KBE_SINGLETON_INIT_TEST(CHello)
//KBE_SINGLETON_INIT_TEST(CHello2)

class CListenHandler : public X::CNetHanlder
{
public:
	CListenHandler() {;}
	~CListenHandler() {;}

public:
	virtual VOID_T OnAccept(X::CNetPoint* pNewPonit)
	{

		LEN_T uLen = 0;
		ERR_T nErr = pNewPonit->Write("hello123", strlen("hello123")+1, uLen);
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

// X::CNetListener g_cNetSvr(X::EM_NET_TCP);
// 
void TaskFunc(void*)
{
	CListenHandler cb;
	X::CNetIp* pIp = X::CNetIp::Create("127.0.0.1", 1234);
	HANDLE_T h = X::CreateNetListener_f(X::EM_NET_TCP, pIp, &cb);

	LOG_F("X::CreateNetListener_f, h = %d", h);
}
X::CThreadCreater g_cThreadCreater;

// #define sas  #define AAA 111
// sas
int _tmain(int argc, _TCHAR* argv[])
{
	LOG_F("xTest main()");

	{
		int n = 1;
		auto a = n;
		double d1 = n;
		double d2 = a;

		auto a1 = [](int i) { return i; };
		auto a2 = a1(2);
		while(true)
		{
			X::Sleep_f(1);
		}
	}

// 	{
// 		int n = X::Init(NULL);
// 		LOGD_F(" n = %d", n);
// 
// 		X_HSER->Init();
// 		X_HSER->Start();
// 
// 		X_HSER->Stop();
// 		X_HSER->Destroy();
// 	}

// 	{
// 		g_cThreadCreater.CreateThread(TaskFunc, NULL);
// 		X::Sleep_f(500);
// 		X::CNetIp* pIp = X::CNetIp::Create("127.0.0.1", 1234);
// 		X::CNetPoint* pNetP = X::CNetPoint::Create();
// 		pNetP->Connect(pIp);
// 		CHAR_T pBuffer[100];
// 		pBuffer[99] = '\0';
// 		LEN_T uLen = 0;
// 		ERR_T nErr = pNetP->Read(pBuffer, 99, uLen);
// 		LOG_F("pNetP->Read, nErr = %d, uLen = %d, %s", nErr, uLen, pBuffer);
// 
// 		while(true)
// 		{
// 			X::Sleep_f(1);
// 		}
// 	}
	
// 	{
// 		//CRITICAL_SECTION ds;
// 		//_SERVICE_HMUTEX d;
// 		//HMUTEX_D s;
// 		//	X::DummyTest();
// 		//	X::UtilTest();
// 		//	X::ThreadTest();
// 		//	X::ContainerTest();
// 
// 		//int n = g1.n;
// 		//n = g2.n;
// 
// 		//int nVal = Singleton<CHello>::getSingletonPtr()->Value();
// 
// 		//PRINT_F();
// 	}


// 	{
// 		//  [4/21/2015 Administrator]
// 		// 	OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
// 
// 		// 	OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
// 		// 	OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
// 		// 	OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
// 		// 	OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
// 		// 	OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
// 	}




// 	{
//	//  [4/26/2015 Administrator]
// 		HINSTANCE hnst=LoadLibrary(_T("xService.dll"));
// 		FreeLibrary(hnst);
// 
// 		HINSTANCE hnst2=LoadLibrary(_T("xService.dll"));
// 		FreeLibrary(hnst);
// 
// 	}
	
	while(true)
	{
		X::Sleep_f(1);
	}
	return 0;
}


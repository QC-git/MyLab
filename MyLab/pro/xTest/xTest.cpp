// xTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <windows.h>

#include "x_all.h"
#include "x_Interface.h"

#include "xTest.h"

//////////////////////////////////////////////////////////////////////////

extern void test_util();

extern void test_container();

extern void test_thread();

extern void test_net(int nFlag);

extern void test_boost();

extern void test_kbe();

//////////////////////////////////////////////////////////////////////////

extern void test_db();

extern void test_util_ex();

extern void test_math();

extern void test_design();

extern void test_async(int nFlag);

extern void test_lua();

extern void test_js();

extern void test_proto();

extern void test_graph();

extern void test_graph_d3d();

extern void test_cv();

extern void test_battle();

extern void test_hacker();

//////////////////////////////////////////////////////////////////////////

extern void test_tool();

//////////////////////////////////////////////////////////////////////////

extern void MainEx(int argc, char* argv[]);

//////////////////////////////////////////////////////////////////////////

int _tmain(int argc, _TCHAR* argv[])
{
	LOG_F("xTest main(), 测试 \n");


	int arg = 1013;
	switch(arg)
	{
	case 1000:
		{
			test_util_ex();
		}break;	
	case 1:
		{
			test_util();
		}break;
	case 2:
		{
			test_container();
		}break;
	case 3:
		{
			test_thread();
		}break;
	case 4:
		{
			test_net(true);
		}break;		
	case 5:
		{
			test_boost();
		}break;	
	case 6:
		{
			test_kbe();
		}break;	
	case 1001:
		{
			test_db();
		}break;	
	case 1002:
		{
			test_math();
		}break;	
	case 1003:
		{
			test_design();
		}break;	
	case 1005:
		{
			//test_net(false);
			test_async(true); 
		}break;	
	case 1006:
		{
			test_lua(); 
		}break;	
	case 1007:
		{
			test_js(); 
		}break;	
	case 1008:
		{
			test_proto(); 
		}break;	
	case 1010:
		{
			test_graph();
		}break;
	case 1011:
		{
			test_graph_d3d();
		}break;
	case 1013:
		{
			test_cv();
		}break;
	case 1015:
		{
			test_battle();
		}break;
	case 1016:
		{
			test_hacker();
		}break;
	case 1900:
		{
			test_tool();
		}break;
	default:
		{
			MainEx(argc, argv);
		}break;
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
//	//  [4/26/2015 Administrator]
// 		HINSTANCE hnst=LoadLibrary(_T("xService.dll"));
// 		FreeLibrary(hnst);
// 
// 		HINSTANCE hnst2=LoadLibrary(_T("xService.dll"));
// 		FreeLibrary(hnst);
// 
// 	}
	
	LOG_F("xTest main(), end");
	while(true)
	{
		X::Sleep_f(1);
	}
	return 0;
}


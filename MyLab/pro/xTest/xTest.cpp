// xTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <windows.h>

#include "x_all.h"
#include "x_Interface.h"

#include "xTest.h"



int _tmain(int argc, _TCHAR* argv[])
{
	LOG_F("xTest main()");


	int arg = 14;
	switch(arg)
	{
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
	case 11:
		{
			test_db();
		}break;	
	case 12:
		{
			test_math();
		}break;	
	case 13:
		{
			test_design();
		}break;	
	case 14:
		{
			//test_net(false);
			test_async(true);
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
	
	while(true)
	{
		X::Sleep_f(1);
	}
	return 0;
}



#include<stdio.h>
#include <windows.h>

#include "xTest.h"
#include "x_InterfaceEx.h"

namespace space_test_hook {

// 	int s_nDown = 0;
// 	HHOOK s_hHook = NULL;           //定义钩子句柄
// 	HINSTANCE s_hInstance = NULL;     //程序实例
// 
// 	LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam)
// 	{
// 		printf("\n HookProc");
// 		LRESULT Result = CallNextHookEx(s_hHook, nCode, wParam, lParam);
// 		if(wParam == 'M' && (lParam & 0x40000000))
// 		{
// 			printf("\n M is downed ! %d", s_nDown++);
// 		}
// 		return Result;
// 	}
// 
// 	//加载钩子
// 	BOOL Load()
// 	{
// 		s_hInstance = GetModuleHandle(0);
// 		//s_hHook =  SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)HookProc, s_hInstance, 0);
// 		s_hHook =  SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)HookProc, s_hInstance,  GetCurrentThreadId());
// 		if( !s_hHook )
// 		{
// 			printf("\n set hook fail");
// 			return FALSE;
// 		}
// 		printf("\n set hook suc");
// 		return TRUE;
// 	}
// 
// 	//卸载钩子
// 	BOOL UnLoad()
// 	{
// 		return UnhookWindowsHookEx(s_hHook);
// 	}
// 
// 	void test1()
// 	{
// 		BOOL bRet;
// 		bRet = Load();
// 		//nRet = UnLoad();
// 
// 		MSG msg;  
// 		while(::GetMessage(&msg, NULL, 0, 0) > 0)  
// 		{  
// 			TranslateMessage(&msg);  
// 			DispatchMessage(&msg);  
// 		}  
// 	}


	int KeyboardRecord(long code,long scancode,long flags)
	{
		printf("%c", (char)code);
// 		FILE* fp=NULL;
// 		if((fp=fopen("c:\\1.txt","a"))==NULL)
// 		{
// 			exit(1);
// 		}
// 		static int i = 0;
// 		if(i%2==0)
// 		{
// 			fprintf(fp,"%c",(char)code);
// 		}
// 		i++;
// 		fclose(fp);
		return 0;

	}

	void test2()
	{
		if( FALSE == setKeyBoardHook())
		{
			printf("\n set hook fail");
			return;
		}

		setHookFuncKeyBoard(KeyboardRecord);
		
		printf("\n");
		
		MSG msg;
		while ( GetMessage(&msg, NULL, 0, 0) )
		{
			if ( !TranslateAccelerator(msg.hwnd, NULL, &msg) )
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		clearAllHook();
	}

	void test3()
	{
		LPTSTR lpCommandLine="D:\\Downloads\\setup.exe";

		STARTUPINFO si;
		memset(&si,0,sizeof(si));
		si.cb=sizeof(si);
		PROCESS_INFORMATION pi;

		int nRet =CreateProcess(NULL, lpCommandLine,   NULL,   NULL,  FALSE, NORMAL_PRIORITY_CLASS,   NULL,   NULL,   &si,   &pi);

		printf("\n");
	}

}

void test_hacker()
{
	//space_test_hook::test1();
	//space_test_hook::test2();
	space_test_hook::test3();

	getchar();
}
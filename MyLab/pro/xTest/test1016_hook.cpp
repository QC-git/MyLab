
#include<stdio.h>
#include <windows.h>

#include "xTest.h"
#include "x_InterfaceEx.h"

namespace space_test_hook {

// 	int s_nDown = 0;
// 	HHOOK s_hHook = NULL;           //���平�Ӿ��
// 	HINSTANCE s_hInstance = NULL;     //����ʵ��
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
// 	//���ع���
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
// 	//ж�ع���
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

		FILE* fp=NULL;
		if((fp=fopen("c:\\1.txt","a"))==NULL)
		{
			exit(1);
		}
		static int i = 0;
		if(i%2==0)
		{
			fprintf(fp,"%c",(char)code);
		}
		i++;
		fclose(fp);
		return 0;

	}

	void test2()
	{
		MSG msg;
		HACCEL hAccelTable;
		BOOL bKeyboard;

		if((bKeyboard=setKeyBoardHook())==TRUE)
			setHookFuncKeyBoard(KeyboardRecord);

		while (GetMessage(&msg, NULL, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		clearAllHook();
	}

}

void test_hook()
{
	//space_test_hook::test1();
	space_test_hook::test2();

	getchar();
}
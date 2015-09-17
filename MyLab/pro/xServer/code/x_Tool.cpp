
#define X_SERVER

#include "x_Tool.h"
#include "include/x_InterfaceEx.h"

HINSTANCE g_hInst;

void AttachProcess(HINSTANCE hInst)
{
	g_hInst = hInst;
}

void DetachProcess()
{
	{
		clearAllHook();
	}

	g_hInst = NULL;
}

HHOOK hookkeyboard = NULL;

static LRESULT WINAPI KeyBoardProc(int nCode,WPARAM wparam,LPARAM lparam);
FucOnKeyBoard g_ptfuckeyboard;

__declspec(dllexport) BOOL setKeyBoardHook()
{

	if (hookkeyboard!=NULL)
	{
		return TRUE;
	}

	hookkeyboard = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProc, g_hInst, 0);
	if(hookkeyboard!=NULL)
	{ /* success */

		return TRUE;

	}
	return FALSE; // failed to set hook

}


__declspec(dllexport) void setHookFuncKeyBoard(FucOnKeyBoard ptFuc)
{

	g_ptfuckeyboard = ptFuc;

}



__declspec(dllexport) BOOL clearAllHook()
{


	UnhookWindowsHookEx(hookkeyboard);
	return TRUE;
}

static LRESULT WINAPI KeyBoardProc(int nCode,WPARAM wparam,LPARAM lparam)

{
	if(nCode>=0)
	{

		LPKBDLLHOOKSTRUCT pKeyBoardHook =(LPKBDLLHOOKSTRUCT)lparam;

		//如果截获到键盘消息就利用函数指针传递

		if(g_ptfuckeyboard)

		{

			g_ptfuckeyboard(pKeyBoardHook->vkCode,pKeyBoardHook->scanCode,pKeyBoardHook->flags);

		}

	}

	return CallNextHookEx(hookkeyboard,nCode,wparam,lparam);

}
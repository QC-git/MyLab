// ********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created: 2006/11/02
//
// ********************************************************************
#ifndef _TQ_COMMON_H_
#define _TQ_COMMON_H_

#define USE_THREAD_LOG 1

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMON_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PUBLIC_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if BS_DLL && WIN32//定义动态库且为WINDOWS 则需要到处标志 //MILO
#ifdef PUBLIC_EXPORTS
	#define PUBLIC_API __declspec(dllexport)
#else
	#define PUBLIC_API __declspec(dllimport)
#endif
#else
#define PUBLIC_API
#endif


#ifndef _DEBUG
#define cprintf(x1,x2,x3,x4,x5,x6,x7,x8,x9)
#else
#include "locale.h"
//#include <conio.h>
#define cprintf _cprintf
#endif
#include "Types.h"

// #pragma comment(lib,"crashdump.lib")

namespace tq
{	

	//////////////////////////////////////////////////////////////////////
	// Cn_str.txt
	//////////////////////////////////////////////////////////////////////
	const INT MAX_KEY_SIZE = 64;
	const INT MAX_CNSTR_SIZE = 255;
	extern "C" PUBLIC_API bool			CnStrInit(void);
	extern "C" PUBLIC_API const char*	CnStrGet(const char* pszStrIndex);
	extern "C" PUBLIC_API bool			CnTableInit(void);
	extern "C" PUBLIC_API const char*	CnTableGet(const char* pszStrIndex);
	extern "C" PUBLIC_API bool			NameFilterInit(void);
	extern "C" PUBLIC_API bool			NameFilterCheck(const char* pszStrIndex);
	extern "C" PUBLIC_API bool			WordFilterInit(void);
	extern "C" PUBLIC_API bool			WordFilterCheck(const char* pszStrIndex);

	//temp notes by lgg
//	bool								StrCheck(const char* pszString, bool bNewLineEnable=false);
//	extern "C" PUBLIC_API bool			NameStrCheck(const char* pszString);
//	extern "C" PUBLIC_API bool			LegalStrCheck(const char* pszString, bool bNewLineEnable=false);
    extern "C" PUBLIC_API bool          CaclInsvrDigest(const char *szSvrName, const char *szName, const char *szPasswd
                                                        , const char *szNonce, char *szDigestMd5, unsigned int size);
}


#endif // end of define _TQ_COMMON_H_

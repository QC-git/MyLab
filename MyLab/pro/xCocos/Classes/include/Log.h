// ********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: chen yongcheng
// Created: 2010/11/02
// Describe:日志输出功能，5分钟定时输出日志；日志队列条数总数为5k，超过4k则写日志
// ********************************************************************
#ifndef _TQ_COMMON_LOG_H_
#define _TQ_COMMON_LOG_H_


#include <stdarg.h>
#include <cassert>
#include <cstring>

#include "bs_type.h"
extern ConfigData g_config_data;

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMON_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
//   functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef _DEBUG
#define cprintf(x1,x2,x3,x4,x5,x6,x7,x8,x9)
#else
#include "locale.h"
//#include <conio.h>
#define cprintf _cprintf
#endif
/*#include "Types.h"*/

//#if (defined _DEBUG || defined DEBUG)
//#    pragma comment(lib, "Log.lib")
//#else
//#    pragma comment(lib, "Log.lib")
//#endif

namespace tq
{
	//////////////////////////////////////////////////////////////////////
	// Log Define
	//////////////////////////////////////////////////////////////////////
	const int	_MAX_PATHSIZE = 256;
	const int	_MAX_CONTEXTSIZE = 4096*2;	
	struct   LOG_INFO
	{
		int		nLogLevel;
		char	szName[64];
		char	szPath[_MAX_PATHSIZE];
		char	szInfo[_MAX_CONTEXTSIZE];
	};

	class   ILog 
	{
	public:
		virtual bool	Read(LOG_INFO& info)			= 0;
		virtual void	Write(const char* pszName, const char* pszInfo, const char* pszPath=NULL, int nLevel = 1) = 0;
		virtual void	WriteEx(const char* pszName, const char* pszInfo, const char* pszPath=NULL) = 0;
	};
	extern   ILog&		LogInstanceGet(void);

	//////////////////////////////////////////////////////////////////////
	// Function
	//////////////////////////////////////////////////////////////////////
    inline   void	InitLogPath(const char *szPath = "Syslog"){};
    inline   void	SetPathSubfix(const char *szSubFix = NULL){};
    inline   void	LogSave(const char* pszName, const char* fmt, ...){
      va_list vl;
      va_start(vl, fmt);
      auto nameLen = strlen(pszName);
      char data[256] = { 0 };
      if (nameLen > 256)
      {
        assert(0);
      }
      memcpy(data, pszName, nameLen);
      vsnprintf(data + nameLen, 256 - nameLen, fmt, vl);
      g_config_data.logger->Info(data);
    };
    inline   void	LogSaveEx(const char* pszName, const char* fmt, ...){};
    inline   void	GmLogSave(const char* pszName, const char* fmt, ...){};
    inline   void	TaskLogSave(const char* pszName, const char* fmt, ...){};
    inline   void	SysLogSave(const char* fmt, ...){
      va_list vl;
      va_start(vl, fmt);
      char data[256] = { 0 };
      vsnprintf(data, 256, fmt, vl);
      g_config_data.logger->Info(data);
  };
	inline   void	DumpLogSave	(const char* fmt, ...){};
	inline   void	DebugLogSave(const char* fmt, ...){
        va_list vl;
        va_start(vl, fmt);
        char data[256] = { 0 };
        vsnprintf(data, 256, fmt, vl);
        g_config_data.logger->Debug(data);
    };
	inline   void	ErrorMsg	(const char* fmt, ...){
        va_list vl;
        va_start(vl, fmt);
        char data[256] = { 0 };
        vsnprintf(data, 256, fmt, vl);
        g_config_data.logger->Error(data);
    };
	inline   void	DebugMsg	(const char* fmt, ...){
    va_list vl;
    va_start(vl, fmt);
    char data[256] = { 0 };
    vsnprintf(data, 256, fmt, vl);
    g_config_data.logger->Debug(data);
  };

    inline   void	DumpBuf(const char* pBuf, uint32_t nSize, bool bFormat = true){};

	//////////////////////////////////////////////////////////////////////
	// 重定向console输出相关（调试用）
	//////////////////////////////////////////////////////////////////////
	inline   void	Trace		(const char* fmt, ...){};
	inline   void	TraceError	(const char* fmt, ...){};
	inline   void	TraceWarning(const char* fmt, ...){};

#ifdef _DEBUG
    typedef     void(*CONS_CMD_CALLBACK)(char* pBuff, int nbufLen);
    inline   bool ConsoleRead(char* pBuff, uint32_t dwBufLen, uint32_t& dwRetCnt){ return true; };
    inline   bool SetConsCmdCallback(CONS_CMD_CALLBACK fCmdCb){ return true; };
#endif

	//开启重定向console输出
    extern "C" inline  void			InitReConsole(){};
	//关闭重定向console输出
    extern "C"  inline void			FreeReConsole(){};
	
	//0 = 黑色 8 = 灰色
	//1 = 蓝色 9 = 亮蓝色
	//2 = 绿色 A = 亮绿色
	//3 = 湖蓝色 B = 亮湖蓝色
	//4 = 红色 C = 亮红色
	//5 = 紫色 D = 亮紫色
	//6 = 黄色 E = 亮黄色
	//7 = 白色 F = 亮白色
	/*inline void SetColor(unsigned short ForeColor=4,unsigned short BackGroundColor=0) //给参数默认值，使它                                                                                                          //可以接受0/1/2个参数
	{
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);    //本例以输出为例
		SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor);
	};*/ 

	//强制输出日志队列中的信息 bStopThread = true 强制停止线程
    extern inline  void	ForceLogOut(bool bStopThread = false){};
}


#endif // end of define _TQ_COMMON_H_

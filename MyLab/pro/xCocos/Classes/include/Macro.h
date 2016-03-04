// **********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: xxx
// Created:	2004/11/03   0:19
//
// **********************************************************************

#pragma once

#include "Types.h"
#include "Log.h"
#include <assert.h>
//////////////////////////////////////////////////////////////////////

// macro...
#undef	SAFE_DELETE
#define SAFE_DELETE(ptr)		{ if(ptr){ try{ delete (ptr); }catch(...){ CRASH_SAFE_DELETE_MSG(ptr); } (ptr) = 0; } }

#undef	SAFE_RELEASE
#define SAFE_RELEASE(ptr)		{ if(ptr){ try{ (ptr)->Release(); }catch(...){ CRASH_SAFE_RELEASE_MSG(ptr); } (ptr) = 0; } }

#undef	ASSERT
#undef	CHECK
#undef  CHECKF
#undef  CHECK_
#undef	IF_OK
#undef	IF_NOT

#define DB_ASSERT(x)

//控制台输出
#define DBGMSG	tq::DebugMsg

//自定义文件名日志
#define LOG		tq::LogSave
#define LOGGM	tq::GmLogSave

//全局日志
#define LOGSYS			tq::SysLogSave
#define ERRMSG			tq::ErrorMsg
#define LOGDBG			tq::DebugLogSave

#define CRASH_SAFE_DELETE_MSG(ptr)	ERRMSG("CATCH: *** SAFE_DELETE() crash! *** at %s, %d",  __FILE__, __LINE__);
#define CRASH_SAFE_RELEASE_MSG(ptr)	ERRMSG("CATCH: *** SAFE_RELEASE() crash! *** at %s, %d", __FILE__, __LINE__);

#define LOGMODERR		tq::log_InlineLogError
#define LOGMODINFO		tq::log_InlineLogInfo 
#ifdef _DEBUG
#define LOGMODDBG		tq::log_InlineLogDebug
#else
#define LOGMODDBG		tq::log_InlineLogDebug
#endif // _DEBUG

#define COMPILETIME_ASSERT(expr) typedef char assert_type[(expr) ? 1 : -1]

#ifdef	_DEBUG
#define		ASSERT(x)		assert(x)
//在没有资源释放问题可以使用CHECK
#define		CHECK(x)	    do{ if(!(x)) { tq::LogSave("Module","%s %d CHECK: "#x, __FILE__, __LINE__ ); return; } }while(0)
#define		CHECKF(x)    	do{ if(!(x)) { tq::LogSave("Module","%s %d CHECKF: "#x, __FILE__, __LINE__); return 0; } }while(0)
#define		CHECK_(r,x)	    do{ if(!(x)) { tq::LogSave("Module","%s %d CHECK_: "#x, __FILE__, __LINE__); return (r); } }while(0)
#define		IF_OK(x)		if( ((x)) ? 1 :  0 ) //todo duqisong if( ((x)) ? 1 : ( tq::LogSave("Module","%s %d ★IF_OK(%s)★", __FILE__, __LINE__, #x), assert(!(#x)), 0 ) )
//#define		IF_NOT(x)		if( (!(x)) ? ( tq::LogSave("Module","%s %d ★IF_NOT(%s)★", __FILE__, __LINE__, #x), assert(!(#x)), 1 ) : 0 )
#define		IF_NOT(x)		if( (!(x)) ? 1 : 0 )
#define     DYNAMIC_CAST(type,obj) (dynamic_cast<type>(obj))

#define		PURE_VIRTUAL		= 0;
#define		PURE_VIRTUAL_0		= 0;
#define		PURE_VIRTUAL_(x)	= 0;
#define		PURE_VIRTUAL_DEFAULT	= 0;
#else	//release
#define		ASSERT(x)		(void)( (x) || ( tq::LogSave("Module","%s %d ASSERT: "#x, __FILE__, __LINE__ ), 0) )
//#define		CHECK(x)	    do{ if(!(x)) { tq::LogSave("Module","%s %d CHECK: "#x, __FILE__, __LINE__ ); return; } }while(0)
#define		CHECKF(x)    	do{ if(!(x)) { tq::LogSave("Module","%s %d CHECKF: "#x, __FILE__, __LINE__); return 0; } }while(0)
#define		CHECK_(r,x)	    do{ if(!(x)) { tq::LogSave("Module","%s %d CHECK_: "#x, __FILE__, __LINE__); return (r); } }while(0)
#define		IF_OK(x)		if( ((x)) ? 1 : ( tq::LogSave("Module","%s %d ★IF_OK(%s)★", __FILE__, __LINE__, #x),0 ) )
#define		IF_NOT(x)		if( (!(x)) ? ( tq::LogSave("Module","%s %d ★IF_NOT(%s)★ ", __FILE__, __LINE__, #x),1 ) : 0 )
#define     DYNAMIC_CAST(type,obj) (dynamic_cast<type>(obj))


#define		PURE_VIRTUAL			{ ASSERT(!"PURE_VIRTUAL_FUNCTION"); }
#define		PURE_VIRTUAL_0			{ ASSERT(!"PURE_VIRTUAL_FUNCTION_0"); return 0; }
#define		PURE_VIRTUAL_(x)		{ ASSERT(!"PURE_VIRTUAL_FUNCTION_X"); return x(); }
#define		PURE_VIRTUAL_DEFAULT	= 0;

#endif

//////////////////////////////////////////////////////////////////////////
//带类名的断言log
#ifdef LOG_CLASSNAME
#ifdef _DEBUG
#define		ASSERT_T(x)		assert(x)
#define		CHECK_T(x)		do{ if(!(x)) { tq::LogSave("Module","%s %d [%s]CHECK:  "#x, __FILE__, __LINE__, typeid(*this).name()); assert(!(#x)); return; } }while(0)
#define		CHECKF_T(x)		do{ if(!(x)) { tq::LogSave("Module","%s %d [%s]CHECKF: "#x, __FILE__, __LINE__, typeid(*this).name()); assert(!(#x)); return 0; } }while(0)
#define		IF_OK_T(x)		if( ((x)) ? 1 : ( tq::LogSave("Module","%s %d [%s]★IF_OK(%s)★", __FILE__, __LINE__, typeid(*this).name(), #x) , assert(!(#x)) ,0 ) )
#define		IF_NOT_T(x)		if( (!(x)) ? ( tq::LogSave("Module","%s %d [%s]★IF_NOT(%s)★", __FILE__, __LINE__, typeid(*this).name(), #x) , assert(!(#x)) ,1 ) : 0 )
#else	//release
#define		ASSERT_T(x)		(void)( (x) || (tq::LogSave("Module","%s %d [%s]ASSERT: "#x, __FILE__, __LINE__, typeid(*this).name()), 0) )
#define		CHECK_T(x)	    do{ if(!(x)) { tq::LogSave("Module","%s %d [%s]CHECK: "#x, __FILE__, __LINE__, typeid(*this).name()); return; } }while(0)
#define		CHECKF_T(x)    	do{ if(!(x)) { tq::LogSave("Module","%s %d [%s]CHECKF: "#x, __FILE__, __LINE__, typeid(*this).name()); return 0; } }while(0)
#define		IF_OK_T(x)		if( ((x)) ? 1 : ( tq::LogSave("Module","%s %d [%s]★IF_OK(%s)★", __FILE__, __LINE__, typeid(*this).name(), #x),0 ) )
#define		IF_NOT_T(x)		if( (!(x)) ? ( tq::LogSave("Module","%s %d [%s]★IF_NOT(%s)★ ", __FILE__, __LINE__, typeid(*this).name(), #x),1 ) : 0 )
#endif	//_DEBUG

#else	//close LOG_CLASSNAME 
#define		ASSERT_T(x)		ASSERT(x)
#define		CHECK_T(x)		CHECK(x)	
#define		CHECKF_T(x)		CHECKF(x)		
#define		IF_OK_T(x)		IF_OK(x)		
#define		IF_NOT_T(x)		IF_NOT(x)		

#endif	//LOG_CLASSNAME
//////////////////////////////////////////////////////////////////////////


#define		DEAD_LOOP_BREAK(x,n)	{ if(++(x) > (n)) { ASSERT(!"DEAD_LOCK_BREAK"); break; } }

// #define		DEBUG_TRY				try{
// #define		DEBUG_CATCH(s)			}catch(tq::IException& ex){char szBuf[4096]; ex.TraceStack(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];tq::LogSave("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__, tq::DumpFuncAddress(6, szFuncDump)); }
// #define		DEBUG_CATCH2(s,x)		}catch(tq::IException& ex){char szBuf[4096]; ex.TraceStack(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];tq::LogSave("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x), tq::DumpFuncAddress(6, szFuncDump)); }
// #define		DEBUG_CATCH3(s,x,y)		}catch(tq::IException& ex){char szBuf[4096]; ex.TraceStack(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];tq::LogSave("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x),(y), tq::DumpFuncAddress(6, szFuncDump)); }
// #define		DEBUG_CATCH4(s,x,y,z)	}catch(tq::IException& ex){char szBuf[4096]; ex.TraceStack(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];tq::LogSave("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x),(y),(z), tq::DumpFuncAddress(6, szFuncDump)); }
// #define		DEBUG_CATCH5(s,x,y,z,h)	}catch(tq::IException& ex){char szBuf[4096]; ex.TraceStack(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];tq::LogSave("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x),(y),(z),(h), tq::DumpFuncAddress(6, szFuncDump)); }
// #define		DEBUG_CATCH_RUN(s,x)	}catch(tq::IException& ex){char szBuf[4096]; ex.TraceStack(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];tq::LogSave("CATCH(...): *** %s %d {" s "} crash. %s***", __FILE__, __LINE__, tq::DumpFuncAddress(6, szFuncDump)); (x); }

#ifdef _DEBUG

#define		DEBUG_TRY
#define		DEBUG_CATCH(s)
#define		DEBUG_CATCH2(s,x)
#define		DEBUG_CATCH3(s,x,y)
#define		DEBUG_CATCH4(s,x,y,z)
#define		DEBUG_CATCH5(s,x,y,z,h)
#define		DEBUG_CATCH_RUN(s,x)

#else

#define		DEBUG_TRY
#define		DEBUG_CATCH(s)
#define		DEBUG_CATCH2(s,x)
#define		DEBUG_CATCH3(s,x,y)
#define		DEBUG_CATCH4(s,x,y,z)
#define		DEBUG_CATCH5(s,x,y,z,h)
#define		DEBUG_CATCH_RUN(s,x)


//#define		DEBUG_TRY		try{
//#define		DEBUG_CATCH(s)			}catch(tq::IException& ex){char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! ***\n%s", __FILE__, __LINE__, tq::DumpFuncAddress(10, szFuncDump, ex.GetExceptionInfo())); char szBuf[4096]; ex.TraceStack(szBuf);	ERRMSG("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf); }catch(...){ char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__, tq::DumpFuncAddress(10, szFuncDump)); }
//#define		DEBUG_CATCH2(s,x)		}catch(tq::IException& ex){char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! ***\n%s", __FILE__, __LINE__,(x), tq::DumpFuncAddress(6, szFuncDump, ex.GetExceptionInfo())); char szBuf[4096]; ex.TraceStack(szBuf);	ERRMSG("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf); }catch(...){ char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x), tq::DumpFuncAddress(6, szFuncDump)); }
//#define		DEBUG_CATCH3(s,x,y)		}catch(tq::IException& ex){char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! ***\n%s", __FILE__, __LINE__,(x),(y), tq::DumpFuncAddress(6, szFuncDump, ex.GetExceptionInfo())); char szBuf[4096]; ex.TraceStack(szBuf);	ERRMSG("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf); }catch(...){ char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x),(y), tq::DumpFuncAddress(6, szFuncDump)); }
//#define		DEBUG_CATCH4(s,x,y,z)	}catch(tq::IException& ex){char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! ***\n%s", __FILE__, __LINE__,(x),(y),(z), tq::DumpFuncAddress(6, szFuncDump, ex.GetExceptionInfo())); char szBuf[4096]; ex.TraceStack(szBuf);	ERRMSG("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x),(y),(z), tq::DumpFuncAddress(6, szFuncDump)); }
//#define		DEBUG_CATCH5(s,x,y,z,h)	}catch(tq::IException& ex){char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! ***\n%s", __FILE__, __LINE__,(x),(y),(z),(h), tq::DumpFuncAddress(6, szFuncDump, ex.GetExceptionInfo())); char szBuf[4096]; ex.TraceStack(szBuf);	ERRMSG("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash! %s***", __FILE__, __LINE__,(x),(y),(z),(h), tq::DumpFuncAddress(6, szFuncDump)); }
//#define		DEBUG_CATCH_RUN(s,x)	}catch(tq::IException& ex){char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash. ***\n%s", __FILE__, __LINE__, tq::DumpFuncAddress(6, szFuncDump, ex.GetExceptionInfo())); (x);char szBuf[4096]; ex.TraceStack(szBuf);	ERRMSG("*** Crash Begin! *** \nName:%s\n%s *** Crash End! ***", ex.GetName(), szBuf);}catch(...){ char szFuncDump[1024];ERRMSG("CATCH(...): *** %s %d {" s "} crash. %s***", __FILE__, __LINE__, tq::DumpFuncAddress(6, szFuncDump)); (x); }

#endif
// #define		STACK_TRACE {char szBuf[4096]; tq::StackTrace(szBuf);	tq::SysLogSave("*** Crash Begin! *** \nSTACK_TRACE\n%s *** Crash End! ***", szBuf);}

#define UNUSED_ARG(arg)     (arg)

#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : Warning Msg: "
#define __LOC2__ __FILE__ "("__STR1__(__LINE__)") : <TODO> "
#define todo(str)   message (__LOC2__ str)

//检查模块是否加载成功
#define		CHECKM(x)	do{ if(!(x)) { tq::LogSave("Module","%s %d CHECKM: "#x" == NULL",__FILE__, __LINE__); } }while(0)

#ifndef PACKED
#ifndef WIN32
#define PACKED __attribute__((packed))
#else
#define PACKED
#endif
#endif

#ifdef _DEBUG
#define PTR_CHECK(x) DEBUG_TRY (*((char*)x)) DEBUG_CATCH2("err ptr of 0x%08x",x)
#else
#define PTR_CHECK(x)
#endif


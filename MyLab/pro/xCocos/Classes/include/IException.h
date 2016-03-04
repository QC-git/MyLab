//////////////////////////////////////////////////////////////////////////
#ifndef EXCEPTION_IEXCEPTION_H
#define EXCEPTION_IEXCEPTION_H

//#include <windows.h>
#include <BaseCode/String.h>

namespace tq
{
    //////////////////////////////////////////////////////////////////////
    void* CatcherInitialize(void);
    void  CatcherRelease(void* pCatcher);
    bool  StackTrace(char* szBuf){ return true; };                   //打印当前线程调用栈(注意是当前线程)
    bool  StackTrace(char* szBuf, uint32_t dwThread){ return true; };   //打印指定线程调用栈(当前线程打印指定的其他线程)

    //////////////////////////////////////////////////////////////////////

    class IException 
    {
    public:
        virtual const char*			GetName() const         = 0;
        virtual bool				TraceStack(char* buf)   = 0;
		//virtual EXCEPTION_POINTERS* GetExceptionInfo(void)	= 0;
    };

	class StdException : public std::exception
	{
	public:
		explicit StdException(const char* what): message_(what){}
		virtual ~StdException() throw(){};
		virtual const char* what() const throw()
		{
			return message_.c_str();		  
		}
	private:
		CString message_;
	};
}
#ifndef THROW_STD_EXCEPTION
#define THROW_STD_EXCEPTION(x) { tq::CString str("{TID[%d] %s %s %d}", GetCurrentThreadId(), x, __FILE__, __LINE__); \
	throw tq::StdException(str.c_str());}
#endif

#ifndef ASSERT
	#ifdef _DEBUG	
	#include <crtdbg.h>
	#define	ASSERT(x) if (!(x)){_RPTF2(_CRT_ASSERT, "ASSERT %s %s", "", #x); tq::SysLogSave("★ASSERT(%s)★ in %s, %d", #x, __FILE__, __LINE__);}	
	#else
	#define	ASSERT(x)	if (!(x)){ tq::SysLogSave("★ASSERT(%s)★ in %s, %d", #x, __FILE__, __LINE__);}	
	#endif 
#endif

#endif
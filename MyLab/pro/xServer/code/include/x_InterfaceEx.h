#pragma once

#ifdef X_SERVER
#define X_SERVER_API  __declspec(dllexport)
#else
#define X_SERVER_API __declspec(dllimport)
#endif

X_SERVER_API BOOL setKeyBoardHook();
X_SERVER_API BOOL clearAllHook();
typedef int (*FucOnKeyBoard)(long code, long scancode,long flags);
X_SERVER_API void setHookFuncKeyBoard(FucOnKeyBoard ptFuc);

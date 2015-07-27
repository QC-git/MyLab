
#ifdef X_SERVICE_USE_PRAGMAONCE
#pragma once
#endif

#ifndef _SERVOCE_DOOR_NET_HEADER
#define _SERVOCE_DOOR_NET_HEADER



//////////////////////////////////////////////////////////////////////////
_SERVOCE_DOOR_BEGIN

enum ENetType{
	ENetType_TCP,
	ENetType_UDP
};

enum ENetManagerType{
	ENetManagerType_BOOST,
	ENetManagerType_KBE
};

/*
************************************************************************************************************************
*                                                    CIp
*
* Description: 网络IP
*
* Arguments  : 无
*
* Returns    : 无
*
* Note(s)    :
*
************************************************************************************************************************
*/

class CNetIp
{
public:
	CNetIp() {;}
	virtual ~CNetIp() {;}

public:
	virtual BOOL_T IsEffect() = 0;

};

/*
************************************************************************************************************************
*                                                    CNetTool
*
* Description: 网络句柄工具
*
* Arguments  : 无
*
* Returns    : 无
*
* Note(s)    : 完善缺乏的功能
*
************************************************************************************************************************
*/

class CNetTool
{
public:
	CNetTool() {;}
	virtual ~CNetTool() {;}

// public:
// 	virtual ERR_T GetFd() = 0;
// 	virtual ERR_T Bind() = 0;
// 	virtual ERR_T Set() = 0;

};

/*
************************************************************************************************************************
*                                                    CNetPoint
*
* Description: 网络端点, 类似sock
*
* Arguments  : 无
*
* Returns    : 无
*
* Note(s)    : 
*
************************************************************************************************************************
*/

class CNetPoint
{
public:
	CNetPoint() {;}
	virtual ~CNetPoint() {;}

public:

	virtual ERR_T Connect(CNetIp* pRemoteIp) = 0;

	virtual ERR_T Write(const CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp = NULL) = 0;

	virtual ERR_T Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp = NULL) = 0;

};

/*
************************************************************************************************************************
*                                                    CNetListener
*
* Description: 网络监听端
*
* Arguments  : 无
*
* Returns    : 无
*
* Note(s)    : 
*
************************************************************************************************************************
*/

class CNetListener
{
public:
	CNetListener(ENetType eType) {;}
	virtual ~CNetListener() {;}

	class CallBack
	{
	public:
		virtual VOID_T OnAccept(CNetPoint* pNewPonit) {;}    // 接受新的连接
		virtual VOID_T OnRecieve(CNetIp* pRemoteIp, CHAR_T* pData, LEN_T uDataLen) {;}   // 接受新的消息
	};

public:
	virtual ERR_T Listen(CNetIp* pHostIp) = 0;

	virtual ERR_T Run(CallBack* pCb, U32_T uFlag=0) = 0;

};

/*
************************************************************************************************************************
*                                                    CNetManager
*
* Description: 网络IP
*
* Arguments  : 无
*
* Returns    : 无
*
* Note(s)    : Local() 不支持多线程
*
************************************************************************************************************************
*/

class _SERVICE_CLASS CNetManager 
{
public:
	CNetManager() {;}
	virtual ~CNetManager() {;}

	static VOID_T Local(ENetManagerType eType);

public:
	virtual CNetIp*         CreateIp(const CHAR_T* sAddr, U16_T uPort = 0) = 0;
	virtual CNetPoint*      CreatePoint() = 0;
	virtual CNetListener*   CreateListener(ENetType eType) = 0;

};

_SERVICE_EXPORT CNetManager* NetManager();

/*
************************************************************************************************************************
*                                                    NetTest
*
* Description: 测试
*
* Arguments  : 无
*
* Returns    : 随机
*
* Note(s)    :
*
************************************************************************************************************************
*/
_SERVICE_EXPORT ERR_T NetTest();

_SERVOCE_DOOR_END
	//////////////////////////////////////////////////////////////////////////

#ifdef _SERVICE_DOOR_LOCK
#error  "this file can not include the door"
#endif

#endif
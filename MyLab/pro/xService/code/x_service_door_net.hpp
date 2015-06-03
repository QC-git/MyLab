
#ifdef X_SERVICE_USE_PRAGMAONCE
#pragma once
#endif

#ifndef _SERVOCE_DOOR_NET_HEADER
#define _SERVOCE_DOOR_NET_HEADER



//////////////////////////////////////////////////////////////////////////
_SERVOCE_DOOR_BEGIN


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

enum EM_NET_TYPE{
	EM_NET_TCP,
	EM_NET_UDP
};

class _SERVICE_CLASS CNetIp
{
public:
	CNetIp() {;}
	virtual ~CNetIp() {;}

	static CNetIp* Create(const CHAR_T* sAddr, U16_T uPort = 0);

public:
	virtual BOOL_T IsEffect() = 0;

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

class _SERVICE_CLASS CNetPoint
{
public:
	CNetPoint() {;}
	virtual ~CNetPoint() {;}

	static CNetPoint* Create();

public:
	virtual ERR_T Connect(CNetIp* pRemoteIp) = 0;

	virtual ERR_T Write(CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp = NULL) = 0;

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

class CNetHanlder
{
public:
	CNetHanlder() {;}
	virtual ~CNetHanlder() {;}

public:
	virtual VOID_T OnAccept(CNetPoint* pNewPonit) = 0;    // 接受新的连接

	virtual VOID_T OnRecieve(CNetIp* pRemoteIp, CHAR_T* pData, LEN_T uDataLen) = 0;   // 接受新的消息

};


/*
************************************************************************************************************************
*                                                    CreateNetListener
*
* Description: 创建网络监听口，支持TCP，UDP监听
*
* Arguments  : 网络类型，监听主机IP，回调句柄
*
* Returns    : 监听句柄
*
* Note(s)    :
*
************************************************************************************************************************
*/
_SERVICE_EXPORT HANDLE_T CreateNetListener_f(EM_NET_TYPE eType, CNetIp* pHostIp, CNetHanlder* pCb);

/*
************************************************************************************************************************
*                                                    NetTest
*
* Description: 销毁网络监听
*
* Arguments  : 监听句柄
*
* Returns    : 无
*
* Note(s)    :
*
************************************************************************************************************************
*/
_SERVICE_EXPORT VOID_T DestroyNetListener_f(HANDLE_T hListener);

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
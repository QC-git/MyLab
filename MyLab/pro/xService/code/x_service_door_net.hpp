
#ifdef X_SERVICE_USE_PRAGMAONCE
#pragma once
#endif

#ifndef _SERVOCE_DOOR_NET_HEADER
#define _SERVOCE_DOOR_NET_HEADER

#include <boost/asio.hpp>

//////////////////////////////////////////////////////////////////////////
_SERVOCE_DOOR_BEGIN

/*
************************************************************************************************************************
*                                                    CIp
*
* Description: IP地址
*
* Arguments  : 无
*
* Returns    : 随机
*
* Note(s)    :
*
************************************************************************************************************************
*/
class _SERVICE_CLASS CIp
{
public:
	CIp(const CHAR_T* sAddr, U16_T uPort);
	virtual ~CIp();

	typedef boost::asio::ip::address Addr_t;
	
public:
	BOOL_T IsEffect();

private:
	Addr_t m_cAddr;
	U16_T m_uPort;
};

/*
************************************************************************************************************************
*                                                    CTcp
*
* Description: TCP
*
* Arguments  : 无
*
* Returns    : 随机
*
* Note(s)    : 指针外部负责释放
*
************************************************************************************************************************
*/
class _SERVICE_CLASS CTcp
{
public:
	CTcp();
	virtual ~CTcp();

	typedef boost::asio::ip::tcp Tcp_t;

public:
	ERR_T SetHostIp(CIp* pIp);
	ERR_T SetRemoteIp(CIp* pIp);

	ERR_T Listen();
	ERR_T Connect();

	ERR_T Send();
	ERR_T Recieve();

private:
	Tcp_t m_cTcp;
	CIp* m_pHostIp;  
	CIp* m_pRemoteIp;

};

/*
************************************************************************************************************************
*                                                    CUdp
*
* Description: UDP
*
* Arguments  : 无
*
* Returns    : 随机
*
* Note(s)    :
*
************************************************************************************************************************
*/
class _SERVICE_CLASS CUdp
{
public:
	CUdp();
	virtual ~CUdp();

	typedef boost::asio::ip::udp Udp_t;

public:
	ERR_T SetHostIp(CIp* pIp);
	ERR_T SetRemoteIp(CIp* pIp);

	ERR_T Send();
	ERR_T Recieve();

private:
	Udp_t m_cUdp;
	CIp* m_pHostIp;  
	CIp* m_pRemoteIp;

};

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
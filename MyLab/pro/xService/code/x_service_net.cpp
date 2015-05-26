
#include "x_net.h"

_SERVOCE_DOOR_BEGIN

///////////////////////////////////CIp///////////////////////////////////////

CIp::CIp(const CHAR_T* sAddr, U16_T uPort)
{
	m_cAddr = m_cAddr.from_string(sAddr);
	m_uPort = uPort;
}

CIp::~CIp()
{
	;
}

BOOL_T CIp::IsEffect()
{
	if ( m_cAddr.is_v4() && m_uPort <= 65535 )
	{
		return TRUE;
	}

	return FALSE;
}

///////////////////////////////////CTcp///////////////////////////////////////

CTcp::CTcp()
	: m_cTcp(Tcp_t::v4())
	, m_pHostIp(NULL)
	, m_pRemoteIp(NULL)
{
	;
}

CTcp::~CTcp()
{
	;
}

ERR_T CTcp::SetHostIp(CIp* pIp)
{
	if ( pIp && pIp->IsEffect() )
	{
		m_pHostIp = pIp;
		return 0;
	}

	return -1;
}

ERR_T CTcp::SetRemoteIp(CIp* pIp)
{
	if ( pIp && pIp->IsEffect() )
	{
		m_pRemoteIp = pIp;
		return 0;
	}

	return -1;
}

ERR_T CTcp::Listen()
{
	return -1;
}

ERR_T Connect()
{
	return -1;
}

ERR_T CTcp::Send()
{
	return -1;
}

ERR_T CTcp::Recieve()
{
	return -1;
}

///////////////////////////////////CUdp///////////////////////////////////////

CUdp::CUdp()
	: m_cUdp(Udp_t::v4())
	, m_pHostIp(NULL)
	, m_pRemoteIp(NULL)
{
	;
}

CUdp::~CUdp()
{
	;
}

ERR_T CUdp::SetHostIp(CIp* pIp)
{
	if ( pIp && pIp->IsEffect() )
	{
		m_pHostIp = pIp;
		return 0;
	}

	return -1;
}

ERR_T CUdp::SetRemoteIp(CIp* pIp)
{
	if ( pIp && pIp->IsEffect() )
	{
		m_pRemoteIp = pIp;
		return 0;
	}

	return -1;
}

ERR_T CUdp::Send()
{
	return -1;
}

ERR_T CUdp::Recieve()
{
	return -1;
}

///////////////////////////////////BoostTest///////////////////////////////////////

_SERVICE_IMPLEMENT ERR_T BoostTest()
{
	//LOG_F("BoostTest()");

	return 0;
}

_SERVOCE_DOOR_END
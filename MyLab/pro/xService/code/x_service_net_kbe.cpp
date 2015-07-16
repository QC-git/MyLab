
#include "x_util.h"
#include "x_net.h"

#include <winsock.h>

#include "network/address.h"
#include "network/endpoint.h"

namespace net_kbe
{
	typedef KBEngine::Network::Address  Addr_t;
	typedef KBEngine::Network::EndPoint Point_t;
}

_SERVOCE_DOOR_BEGIN

///////////////////////////////////CNetIp///////////////////////////////////////

// class CNetIpImpl_ForKbe : public CNetIp
// {
// public:
// 	CNetIpImpl_ForKbe(const CHAR_T* sAddr, U16_T uPort = 0);
// 	virtual ~CNetIpImpl_ForKbe();
// 
// 	friend class CNetPointImpl_ForKbe;
// 	friend class CNetListener_ForKbe;
// 
// public:
// 	//Ovrride
// 	BOOL_T IsEffect();
// 
// 	VOID_T Debug();
// 
// private:
// 	net_kbe::Addr_t* m_pAddr;
// 	U16_T m_uPort;
// 	BOOL_T m_bInvalid;
// };
// 
// CNetIpImpl_ForKbe::CNetIpImpl_ForKbe(const CHAR_T* sAddr, U16_T uPort)
// 	: CNetIp()
// {
// 	m_bInvalid = FALSE;
// 	m_pAddr = NULL;
// 	KBEngine::u_int32_t uAddr = 0;
// 	if ( 0 == net_kbe::Addr_t::string2ip(sAddr, uAddr) ) 
// 	{
// 		m_pAddr = new net_kbe::Addr_t(uAddr, uPort);	
// 	}
// 
// 	if ( NULL != m_pAddr )
// 	{
// 		m_bInvalid = TRUE;
// 	}
// 
// 	m_uPort = uPort;
// }
// 
// CNetIpImpl_ForKbe::~CNetIpImpl_ForKbe()
// {
// 	if (m_pAddr)
// 	{
// 		delete m_pAddr;
// 	}
// }
// 
// BOOL_T CNetIpImpl_ForKbe::IsEffect()
// {
// 	if ( m_bInvalid && m_uPort <= 65535 )
// 	{
// 		return TRUE;
// 	}
// 
// 	return FALSE;
// }
// 
// VOID_T CNetIpImpl_ForKbe::Debug()
// {
// 	;
// }

_SERVOCE_DOOR_END
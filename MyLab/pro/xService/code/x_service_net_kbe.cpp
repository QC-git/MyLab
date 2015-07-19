
#include "x_util.h"
#include "x_net.h"

#include <winsock.h>

#include "network/address.h"
#include "network/endpoint.h"

namespace net_kbe
{
	typedef KBEngine::Network::Address  Addr_t;
	typedef KBEngine::Network::EndPoint Point_t;
	//typedef KBEngine::Network::Bundle   Bundle_t;
}

_SERVOCE_DOOR_BEGIN

///////////////////////////////////CNetIp///////////////////////////////////////

class CNetIpImpl_ForKbe : public CNetIp
{
public:
	CNetIpImpl_ForKbe(const CHAR_T* sAddr, U16_T uPort = 0);
	virtual ~CNetIpImpl_ForKbe();

	friend class CNetPointImpl_ForKbe;
	friend class CNetListener_ForKbe;

public:
	//Ovrride
	BOOL_T IsEffect();

	VOID_T Debug();

private:
	net_kbe::Addr_t* m_pAddr;
	U16_T m_uPort;
	BOOL_T m_bInvalid;
};

CNetIpImpl_ForKbe::CNetIpImpl_ForKbe(const CHAR_T* sAddr, U16_T uPort)
	: CNetIp()
{
	m_bInvalid = FALSE;
	m_pAddr = NULL;
	KBEngine::u_int32_t uAddr = 0;
	if ( 0 == net_kbe::Addr_t::string2ip(sAddr, uAddr) ) 
	{
		m_pAddr = new net_kbe::Addr_t(uAddr, uPort);	
	}

	if ( NULL != m_pAddr )
	{
		m_bInvalid = TRUE;
	}

	m_uPort = uPort;
}

CNetIpImpl_ForKbe::~CNetIpImpl_ForKbe()
{
	if (m_pAddr)
	{
		delete m_pAddr;
	}
}

BOOL_T CNetIpImpl_ForKbe::IsEffect()
{
	if ( m_bInvalid && m_uPort <= 65535 )
	{
		return TRUE;
	}

	return FALSE;
}

VOID_T CNetIpImpl_ForKbe::Debug()
{
	;
}


///////////////////////////////////CNetPoint///////////////////////////////////////

class CNetPointImpl_ForKbe : public CNetPoint
{
public:
	CNetPointImpl_ForKbe(BOOL_T isBlock = FALSE);
	CNetPointImpl_ForKbe(net_kbe::Point_t* pPoint);
	~CNetPointImpl_ForKbe();

	friend class CNetListener_ForBoost;

public:
	//Ovrride
	ERR_T Connect(CNetIp* pRemoteIp);

	//Ovrride
	ERR_T Write(CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp);

	//Ovrride
	ERR_T Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp);

	//Ovrride
	BOOL_T IsEffect();

	VOID_T Debug();

private:
	net_kbe::Point_t* m_pPoint;

};

CNetPointImpl_ForKbe::CNetPointImpl_ForKbe(BOOL_T isBlock)
	: m_pPoint(NULL)
{
	net_kbe::Point_t::initNetwork();
	m_pPoint = new net_kbe::Point_t;
	m_pPoint->socket(SOCK_STREAM);
	if (!isBlock)
	{
		m_pPoint->setnonblocking(true);
		m_pPoint->setnodelay(true);
	}
	
}

CNetPointImpl_ForKbe::CNetPointImpl_ForKbe(net_kbe::Point_t* pPoint)
	: m_pPoint(NULL)
{
	net_kbe::Point_t::initNetwork();
	m_pPoint = pPoint;
}

CNetPointImpl_ForKbe::~CNetPointImpl_ForKbe()
{
	if (m_pPoint)
	{
		delete m_pPoint;
	}
		
}

ERR_T CNetPointImpl_ForKbe::Connect(CNetIp* pRemoteIp)
{
	if ( NULL == pRemoteIp || !pRemoteIp->IsEffect() || !IsEffect() )
	{
		return -1;
	}

	//CNetIpImpl* p = (CNetIpImpl*)pRemoteIp;
	CNetIpImpl_ForKbe* p = dynamic_cast<CNetIpImpl_ForKbe*>(pRemoteIp) ;
	if ( NULL == p )
	{
		return -1;
	}

	m_pPoint->addr(*(p->m_pAddr));
	int nRet = m_pPoint->connect();
	if ( 0 != nRet ) 
	{
		return -2;
	}
	

	return 0;
}

ERR_T CNetPointImpl_ForKbe::Write(CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp)
{
	if ( NULL == pData || 0 == uDataLen || !IsEffect() )
	{
		return -1;
	}

	uWriteLen = 0;
	int nRet  = m_pPoint->send((const void*)pData, (int)uDataLen);
	if ( SOCKET_ERROR == nRet )
	{
		return -2;
	}

	uWriteLen = nRet;
	return 0;
}

ERR_T CNetPointImpl_ForKbe::Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp)
{
	if ( NULL == pBuffer || 0 == uBufferLen || !IsEffect() )
	{
		return -1;
	}

	uReadLen = 0;
	int nRet = m_pPoint->recv((void*)pBuffer, (int)uBufferLen); // 一般为阻塞状态， 当为0时， 代表数据中断
	if ( SOCKET_ERROR == nRet )
	{
		return -2;
	}

	uReadLen = nRet;	
	return 0;
}

BOOL_T CNetPointImpl_ForKbe::IsEffect()
{
	if ( m_pPoint && m_pPoint->good() )
	{
		return TRUE;
	}
	
	return FALSE;
}

VOID_T CNetPointImpl_ForKbe::Debug()
{
	LOG_F("CNetPoint::Debug(), %s", m_pPoint->c_str());
}

///////////////////////////////////CNetListener///////////////////////////////////////


class CNetListener_ForKbe
{
public:
	CNetListener_ForKbe(EM_NET_TYPE eType);
	virtual ~CNetListener_ForKbe();

public:
	ERR_T Process(CNetIp* pHostIp, CNetHanlder* pCb);

private:
	EM_NET_TYPE m_eType;
	CNetHanlder* m_pCb;

};

CNetListener_ForKbe::CNetListener_ForKbe(EM_NET_TYPE eType)
{
	m_eType = eType;
	m_pCb = NULL;
}

CNetListener_ForKbe::~CNetListener_ForKbe()
{
	;
}

ERR_T CNetListener_ForKbe::Process(CNetIp* pHostIp, CNetHanlder* pCb)
{
	if ( !pHostIp || !pHostIp->IsEffect() || NULL == pCb )
	{
		return -1;
	}

	m_pCb = pCb;
	//CNetIpImpl* p = (CNetIpImpl*)pHostIp;
	CNetIpImpl_ForKbe* p = dynamic_cast<CNetIpImpl_ForKbe*>(pHostIp) ;
	if ( NULL == p )
	{
		return -1;
	}

	net_kbe::Point_t* m_pPoint = new net_kbe::Point_t(*(p->m_pAddr));

	while (true)
	{
		int nRet = m_pPoint->listen();
		if ( SOCKET_ERROR == nRet )
		{
			return -2;
		}
		
		CNetPointImpl_ForKbe* pNew = NULL;
		net_kbe::Point_t* pSock = m_pPoint->accept();
		if ( pSock )
		{
			pNew = new CNetPointImpl_ForKbe(pSock);
		}

		m_pCb->OnAccept((CNetPoint*)pNew);
	}


	return 0;
}

///////////////////////////////////CNetManager///////////////////////////////////////

class CNetManagerImpl_Kbe : public CNetManager
{
public:
	CNetManagerImpl_Kbe() {;}
	virtual ~CNetManagerImpl_Kbe() {;}

public:
	virtual CNetIp*    CreateIp(const CHAR_T* sAddr, U16_T uPort = 0);
	virtual CNetPoint* CreatePoint();

	virtual HANDLE_T   CreateListener(EM_NET_TYPE eType, CNetIp* pHostIp, CNetHanlder* pCb);
	virtual VOID_T     DestroyListener(HANDLE_T hListener);
};

CNetIp* CNetManagerImpl_Kbe::CreateIp(const CHAR_T* sAddr, U16_T uPort)
{
	CNetIp* p = new CNetIpImpl_ForKbe(sAddr, uPort);
	if ( NULL == p )
	{
		return NULL;
	}

	if ( !p->IsEffect() )
	{
		delete p;
		return NULL;
	}

	return p;
}

CNetPoint* CNetManagerImpl_Kbe::CreatePoint()
{
	CNetPoint* p = new CNetPointImpl_ForKbe;
	return p;
}

HANDLE_T CNetManagerImpl_Kbe::CreateListener(EM_NET_TYPE eType, CNetIp* pHostIp, CNetHanlder* pCb)
{
	if ( NULL == pHostIp || !pHostIp->IsEffect() || NULL == pCb )
	{
		return NULL;
	}

	CNetListener_ForKbe* p = new CNetListener_ForKbe(eType);
	if ( NULL == p )
	{
		return NULL;
	}

	if ( 0 != p->Process(pHostIp, pCb) )
	{
		delete p;
		return NULL;
	}

	return p;
}

VOID_T CNetManagerImpl_Kbe::DestroyListener(HANDLE_T hListener)
{
	CNetListener_ForKbe* p = (CNetListener_ForKbe*)hListener;
	if (p)
	{
		delete p;
	}
}

static CNetManagerImpl_Kbe s_cNetMgr;
CNetManager* g_pNetMgr_Kbe = (CNetManager*)(&s_cNetMgr);

_SERVOCE_DOOR_END
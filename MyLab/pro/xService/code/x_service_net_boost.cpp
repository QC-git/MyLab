
#include "x_util.h"
#include "x_net.h"

#include <boost/asio.hpp>

_SERVOCE_DOOR_BEGIN

namespace net
{
	typedef boost::asio::ip::address Addr_t;
	typedef boost::asio::ip::tcp Tcp_t;
	typedef boost::asio::ip::udp Udp_t;
	typedef boost::asio::io_service Service_t;
	typedef boost::system::error_code Err_t;
}

///////////////////////////////////CNetIp///////////////////////////////////////

class CNetIpImpl_ForBoost : public CNetIp
{
public:
	CNetIpImpl_ForBoost(const CHAR_T* sAddr, U16_T uPort = 0);
	virtual ~CNetIpImpl_ForBoost();

	friend class CNetPointImpl_ForBoost;
	friend class CNetListener_ForBoost;

public:
	//Ovrride
	BOOL_T IsEffect();

	VOID_T Debug();

private:
	net::Addr_t m_cAddr;
	U16_T m_uPort;
};

CNetIpImpl_ForBoost::CNetIpImpl_ForBoost(const CHAR_T* sAddr, U16_T uPort)
	: CNetIp()
{
	m_cAddr = net::Addr_t::from_string(sAddr);
	m_uPort = uPort;
}

CNetIpImpl_ForBoost::~CNetIpImpl_ForBoost()
{
	;
}

BOOL_T CNetIpImpl_ForBoost::IsEffect()
{
	if ( m_cAddr.is_v4() && m_uPort <= 65535 )
	{
		return TRUE;
	}

	return FALSE;
}

VOID_T CNetIpImpl_ForBoost::Debug()
{
	;
}

///////////////////////////////////CNetServer///////////////////////////////////////

class CNetPointImpl_ForBoost : public CNetPoint
{
public:
	CNetPointImpl_ForBoost();
	~CNetPointImpl_ForBoost();

	friend class CNetListener_ForBoost;

public:
	//Ovrride
	ERR_T Connect(CNetIp* pRemoteIp);

	//Ovrride
	ERR_T Write(CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp);

	//Ovrride
	ERR_T Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp);


	VOID_T Debug();

private:
	net::Service_t m_cIo;
	net::Tcp_t::socket m_cSock;   // m_cIo 必须先于 m_cSock 被初始化
	net::Service_t* m_pOutIo;
};

CNetPointImpl_ForBoost::CNetPointImpl_ForBoost()
	: m_pOutIo(NULL)
	, m_cSock(m_cIo)
{
	;
}

CNetPointImpl_ForBoost::~CNetPointImpl_ForBoost()
{
	;
}

ERR_T CNetPointImpl_ForBoost::Connect(CNetIp* pRemoteIp)
{
	if ( NULL == pRemoteIp || !pRemoteIp->IsEffect() )
	{
		return -1;
	}

	//CNetIpImpl* p = (CNetIpImpl*)pRemoteIp;
	CNetIpImpl_ForBoost* p = dynamic_cast<CNetIpImpl_ForBoost*>(pRemoteIp) ;
	if ( NULL == p )
	{
		return -1;
	}

	net::Tcp_t::endpoint endpoint(p->m_cAddr, p->m_uPort);
	try
	{
		m_cSock.connect(endpoint);
	}
	catch (std::exception& e)
	{
		std::exception& e1 = e;
		return -2;
	}

	return 0;
}

ERR_T CNetPointImpl_ForBoost::Write(CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp)
{
	if ( NULL == pData || 0 == uDataLen )
	{
		return -1;
	}

	try
	{
		uWriteLen = 0;
		//uWriteLen = m_cSock.send(boost::asio::buffer("welcome to net server"));
		uWriteLen = m_cSock.send(boost::asio::buffer(pData, uDataLen));
	}
	catch (std::exception& e)
	{
		std::exception& e1 = e;
		return -2;
	}


	return 0;
}

ERR_T CNetPointImpl_ForBoost::Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp)
{
	if ( NULL == pBuffer || 0 == uBufferLen )
	{
		return -1;
	}

	try
	{
		uReadLen = 0;
		//CHAR_T buff[100];
		uReadLen = m_cSock.receive(boost::asio::buffer(pBuffer, uBufferLen));
		//LOG_F("CNetPoint::Read(), %s", buff);
	}
	catch (std::exception& e)
	{
		std::exception& e1 = e;
		return -2;
	}

	return 0;
}

VOID_T CNetPointImpl_ForBoost::Debug()
{
	LOG_F("CNetPoint::Debug(), %s", m_cSock.remote_endpoint().address());
}

///////////////////////////////////CNetListener///////////////////////////////////////

class CNetListener_ForBoost
{
public:
	CNetListener_ForBoost(EM_NET_TYPE eType);
	virtual ~CNetListener_ForBoost();

public:
	ERR_T Process(CNetIp* pHostIp, CNetHanlder* pCb);

private:
	EM_NET_TYPE m_eType;
	net::Service_t m_cIo;
	CNetHanlder* m_pCb;

};

CNetListener_ForBoost::CNetListener_ForBoost(EM_NET_TYPE eType)
{
	m_eType = eType;
	m_pCb = NULL;
}

CNetListener_ForBoost::~CNetListener_ForBoost()
{
	;
}

ERR_T CNetListener_ForBoost::Process(CNetIp* pHostIp, CNetHanlder* pCb)
{
	if ( !pHostIp || !pHostIp->IsEffect() || NULL == pCb )
	{
		return -1;
	}

	m_pCb = pCb;
	//CNetIpImpl* p = (CNetIpImpl*)pHostIp;
	CNetIpImpl_ForBoost* p = dynamic_cast<CNetIpImpl_ForBoost*>(pHostIp) ;
	if ( NULL == p )
	{
		return -1;
	}

	net::Tcp_t::endpoint endpoint(net::Tcp_t::v4(), p->m_uPort);
	net::Tcp_t::acceptor acceptor(m_cIo, endpoint);
	while (true)
	{
		CNetPointImpl_ForBoost* pNew = new CNetPointImpl_ForBoost;
		if ( NULL == pNew ) 
		{
			break;
		}

		try
		{
			acceptor.accept(pNew->m_cSock);
		}
		catch (std::exception& e)
		{
			std::exception& e1 = e;
			return -2;
		}

		m_pCb->OnAccept((CNetPoint*)pNew);
	}


	return 0;
}

///////////////////////////////////CNetManager///////////////////////////////////////

class CNetManagerImpl_Boost : public CNetManager
{
public:
	CNetManagerImpl_Boost() {;}
	virtual ~CNetManagerImpl_Boost() {;}

public:
	virtual CNetIp*    CreateIp(const CHAR_T* sAddr, U16_T uPort = 0);
	virtual CNetPoint* CreatePoint();

	virtual HANDLE_T   CreateListener(EM_NET_TYPE eType, CNetIp* pHostIp, CNetHanlder* pCb);
	virtual VOID_T     DestroyListener(HANDLE_T hListener);
};

CNetIp* CNetManagerImpl_Boost::CreateIp(const CHAR_T* sAddr, U16_T uPort)
{
	CNetIp* p = new CNetIpImpl_ForBoost(sAddr, uPort);
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

CNetPoint* CNetManagerImpl_Boost::CreatePoint()
{
	CNetPoint* p = new CNetPointImpl_ForBoost;
	return p;
}

HANDLE_T CNetManagerImpl_Boost::CreateListener(EM_NET_TYPE eType, CNetIp* pHostIp, CNetHanlder* pCb)
{
	if ( NULL == pHostIp || !pHostIp->IsEffect() || NULL == pCb )
	{
		return NULL;
	}

	CNetListener_ForBoost* p = new CNetListener_ForBoost(eType);
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

VOID_T CNetManagerImpl_Boost::DestroyListener(HANDLE_T hListener)
{
	CNetListener_ForBoost* p = (CNetListener_ForBoost*)hListener;
	if (p)
	{
		delete p;
	}
}

static CNetManagerImpl_Boost s_cNetMgr;
CNetManager* g_pNetMgr_Boost = (CNetManager*)(&s_cNetMgr);

_SERVOCE_DOOR_END
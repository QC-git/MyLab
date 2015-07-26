
#include "x_util.h"
#include "x_net.h"

#include <boost/asio.hpp>

_SERVOCE_DOOR_BEGIN

namespace net_boost
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
	net_boost::Addr_t m_cAddr;
	U16_T m_uPort;
};

CNetIpImpl_ForBoost::CNetIpImpl_ForBoost(const CHAR_T* sAddr, U16_T uPort)
	: CNetIp()
{
	m_cAddr = net_boost::Addr_t::from_string(sAddr);
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

///////////////////////////////////CNetPoint///////////////////////////////////////

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
	net_boost::Service_t m_cIo;
	net_boost::Tcp_t::socket m_cSock;   // m_cIo 必须先于 m_cSock 被初始化
	net_boost::Service_t* m_pOutIo;
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

	net_boost::Tcp_t::endpoint endpoint(p->m_cAddr, p->m_uPort);
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

class CNetListener_ForBoost : public CNetListener
{
public:
	CNetListener_ForBoost(EM_NET_TYPE eType);
	virtual ~CNetListener_ForBoost();

public:
	virtual ERR_T Listen(CNetIp* pHostIp);

	virtual ERR_T Run(CallBack* pCb, U32_T uFlag = 0);

private:
	EM_NET_TYPE m_eType;
	CallBack* m_pCb;
	net_boost::Tcp_t::acceptor* m_pAcceptor;

	net_boost::Service_t m_cIo;

};

CNetListener_ForBoost::CNetListener_ForBoost(EM_NET_TYPE eType)
	: CNetListener(eType)
{
	m_eType = eType;
	m_pCb = NULL;

	m_pAcceptor = new net_boost::Tcp_t::acceptor(m_cIo);

}

CNetListener_ForBoost::~CNetListener_ForBoost()
{
	if (m_pAcceptor)
	{
		delete m_pAcceptor;  //注意与成员析构函数的先后顺序
	}
}

ERR_T CNetListener_ForBoost::Listen(CNetIp* pHostIp)
{
	if ( NULL == pHostIp || !pHostIp->IsEffect() || NULL == m_pAcceptor )
	{
		return -1;
	}

	CNetIpImpl_ForBoost* p = dynamic_cast<CNetIpImpl_ForBoost*>(pHostIp) ;
	if ( NULL == p )
	{
		return -1;
	}
	
	try
	{
		net_boost::Tcp_t::endpoint endpoint(net_boost::Tcp_t::v4(), p->m_uPort);
		m_pAcceptor->open(endpoint.protocol());
		m_pAcceptor->bind(endpoint);
		m_pAcceptor->listen();		
	}
	catch (std::exception& e)
	{
		std::exception& e1 = e;
		return -2;
	}
	

	return 0;

}

ERR_T CNetListener_ForBoost::Run(CallBack* pCb, U32_T uFlag)
{
	if ( NULL == pCb || NULL == m_pAcceptor )
	{
		return -1;
	}
	m_pCb = pCb;

	do 
	{
		CNetPointImpl_ForBoost* pNew = new CNetPointImpl_ForBoost;
		if ( NULL == pNew ) 
		{
			return -2;
		}

		try
		{
			m_pAcceptor->accept(pNew->m_cSock);
		}
		catch (std::exception& e)
		{
			std::exception& e1 = e;
			return -2;
		}

		m_pCb->OnAccept(pNew);

	} while (uFlag);


	return 0;
}


///////////////////////////////////CNetManager///////////////////////////////////////

class CNetManagerImpl_Boost : public CNetManager
{
public:
	CNetManagerImpl_Boost() {;}
	virtual ~CNetManagerImpl_Boost() {;}

public:
	virtual CNetIp*			CreateIp(const CHAR_T* sAddr, U16_T uPort = 0);
	virtual CNetPoint*		CreatePoint();
	virtual CNetListener*	CreateListener(EM_NET_TYPE eType);

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

CNetListener* CNetManagerImpl_Boost::CreateListener(EM_NET_TYPE eType)
{
	CNetListener* p = new CNetListener_ForBoost(eType);
	return p;
}


static CNetManagerImpl_Boost s_cNetMgr;
CNetManager* g_pNetMgr_Boost = (CNetManager*)(&s_cNetMgr);


_SERVOCE_DOOR_END
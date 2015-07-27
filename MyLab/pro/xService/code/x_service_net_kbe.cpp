
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
	CNetPointImpl_ForKbe(BOOL_T isBlock = TRUE);
	CNetPointImpl_ForKbe(net_kbe::Point_t* pPoint);
	~CNetPointImpl_ForKbe();

	friend class CNetListener_ForBoost;

public:
	//Ovrride
	ERR_T Connect(CNetIp* pRemoteIp);

	//Ovrride
	ERR_T Write(const CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp);

	//Ovrride
	ERR_T Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp);

	//Ovrride
	BOOL_T IsEffect();

	VOID_T Debug();

private:
	net_kbe::Point_t* m_pPoint;
	BOOL_T m_isBlock;

};

CNetPointImpl_ForKbe::CNetPointImpl_ForKbe(BOOL_T isBlock)
	: m_pPoint(NULL)
	, m_isBlock(FALSE)
{
	net_kbe::Point_t::initNetwork();

	m_pPoint = new net_kbe::Point_t;
	assert(m_pPoint);
	if (m_pPoint)
	{
		m_pPoint->socket(SOCK_STREAM);		
	}

	m_isBlock = isBlock;
	
}

CNetPointImpl_ForKbe::CNetPointImpl_ForKbe(net_kbe::Point_t* pPoint)
	: m_pPoint(NULL)
{
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
	int nRet = m_pPoint->connect(m_isBlock? false: true);
	if ( 0 != nRet ) 
	{
		int nErrr = WSAGetLastError();
		return -2;
	}
	

	return 0;
}

ERR_T CNetPointImpl_ForKbe::Write(const CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp)
{
	if ( NULL == pData || 0 == uDataLen || !IsEffect() )
	{
		return -1;
	}

	uWriteLen = 0;
	int nRet  = m_pPoint->send((const void*)pData, (int)uDataLen);
	if ( SOCKET_ERROR == nRet )
	{
		int nErrr = WSAGetLastError();
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
	int nRet = m_pPoint->recv((void*)pBuffer, (int)uBufferLen); // һ��Ϊ����״̬�� ��Ϊ0ʱ�� ���������ж� // Ĭ�ϲ����� ��
	if ( SOCKET_ERROR == nRet )
	{
		int nErrr = WSAGetLastError();//EWOULDBLOCK//EAGAIN//����
		if ( WSAEINTR == nErrr || WSAEWOULDBLOCK == nErrr || EAGAIN == nErrr  )
		{
			nRet = m_pPoint->recv((void*)pBuffer, (int)uBufferLen);
			return 0; //����
		}
		/*
		WSANOTINITIALISED;//����ʹ�ô�API֮ǰӦ���ȳɹ��ص���WSAStartup()��10093

			WSAENETDOWN;//��WINDOWS�׽ӿ�ʵ�ּ�⵽������ϵͳʧЧ�� 10050

			WSAENOTCONN;//���׽ӿ�δ���ӡ� 10057

			WSAEINTR;//���������̱�WSACancelBlockingCall()ȡ���� 10004

			WSAEINPROGRESS;//��һ��������WINDOWS�׽ӿڵ������������С�10036

			WSAENOTSOCK;//�������ֲ���һ���׽ӿڡ�10038

			WSAEOPNOTSUPP;//��ָ����MSG_OOB�����׽ӿڲ���SOCK_STREAM���͵ġ�10045

			WSAESHUTDOWN;//���׽ӿ��ѱ��رա���һ���׽ӿ���0��2��how��������shutdown()�رպ��޷�����recv()�������ݡ�10058

			WSAEWOULDBLOCK;//���׽ӿڱ�ʶΪ������ģʽ�������ղ��������������10035

			WSAEMSGSIZE;//�����ݱ�̫���޷�ȫ��װ�뻺�������ʱ����С�10040

			WSAEINVAL;//���׽ӿ�δ��bind()��������10022

			WSAECONNABORTED;//�����ڳ�ʱ������ԭ�����·ʧЧ��10053

			WSAECONNRESET;//��Զ��ǿ����ֹ�����·��10054
			*/
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


class CNetListener_ForKbe : public CNetListener
{
public:
	CNetListener_ForKbe(ENetType eType);
	virtual ~CNetListener_ForKbe();

public:
	virtual ERR_T Listen(CNetIp* pHostIp);

	virtual ERR_T Run(CallBack* pCb, U32_T uFlag = 0);

private:
	ENetType m_eType;
	net_kbe::Point_t* m_pPoint;
	CallBack* m_pCb;

};

CNetListener_ForKbe::CNetListener_ForKbe(ENetType eType)
	: CNetListener(eType)
{
	net_kbe::Point_t::initNetwork();

	m_pPoint = new net_kbe::Point_t();
	assert(m_pPoint);
	if (m_pPoint)
	{
		m_pPoint->socket(SOCK_STREAM);
	}

	m_eType = eType;
	m_pCb = NULL;
	
}

CNetListener_ForKbe::~CNetListener_ForKbe()
{
	if (m_pPoint)
	{
		delete m_pPoint;
	}
}

ERR_T CNetListener_ForKbe::Listen(CNetIp* pHostIp)
{
	if ( !pHostIp || !pHostIp->IsEffect() || NULL == m_pPoint )
	{
		return -1;
	}

	CNetIpImpl_ForKbe* p = dynamic_cast<CNetIpImpl_ForKbe*>(pHostIp) ;
	if ( NULL == p )
	{
		return -1;
	}

	int nRet = m_pPoint->bind(p->m_pAddr->port, p->m_pAddr->ip);
	if ( SOCKET_ERROR == nRet )
	{
		int nErrr = WSAGetLastError();
		return -2;
	}	

	nRet = m_pPoint->listen();
	if ( SOCKET_ERROR == nRet )
	{
		int nErrr = WSAGetLastError();
		return -2;
	}

	return 0;
}

ERR_T CNetListener_ForKbe::Run(CallBack* pCb, U32_T uFlag)
{
	if ( NULL == pCb || NULL == m_pPoint ) 
	{
		return -1;
	}
	m_pCb = pCb;
	
	do 
	{
		CNetPointImpl_ForKbe* pNew = NULL;
		net_kbe::Point_t* pSock = m_pPoint->accept();
		if ( pSock )
		{
			pNew = new CNetPointImpl_ForKbe(pSock);
		}
		if ( NULL == pNew ) 
		{
			return -2;
		}

		m_pCb->OnAccept(pNew);
		
	} while (uFlag);

	return 0;
}


///////////////////////////////////CNetManager///////////////////////////////////////

class CNetManagerImpl_Kbe : public CNetManager
{
public:
	CNetManagerImpl_Kbe() {;}
	virtual ~CNetManagerImpl_Kbe() {;}

public:
	virtual CNetIp*			CreateIp(const CHAR_T* sAddr, U16_T uPort = 0);
	virtual CNetPoint*		CreatePoint();
	virtual CNetListener*   CreateListener(ENetType eType);

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

CNetListener* CNetManagerImpl_Kbe::CreateListener(ENetType eType)
{
	CNetListener* p = new CNetListener_ForKbe(eType);
	return p;
}


static CNetManagerImpl_Kbe s_cNetMgr;
CNetManager* g_pNetMgr_Kbe = (CNetManager*)(&s_cNetMgr);


_SERVOCE_DOOR_END
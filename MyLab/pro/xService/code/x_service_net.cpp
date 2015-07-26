
#include "x_util.h"
#include "x_net.h"

_SERVOCE_DOOR_BEGIN

///////////////////////////////////CNetManager///////////////////////////////////////

extern CNetManager* g_pNetMgr_Boost;
extern CNetManager* g_pNetMgr_Kbe;

static EM_NET_MANAGER s_eNetMgrType = EM_NET_MANAGER_BOOST;

VOID_T CNetManager::Local(EM_NET_MANAGER eType)
{
	s_eNetMgrType = eType;
}

CNetManager* NetManager()
{
	switch(s_eNetMgrType)
	{
	case EM_NET_MANAGER_BOOST:
		return g_pNetMgr_Boost;
	case EM_NET_MANAGER_KBE:
		return g_pNetMgr_Kbe;
	default:
		return NULL;
	}
}

///////////////////////////////////NetTest///////////////////////////////////////

_SERVICE_IMPLEMENT ERR_T NetTest()
{
	LOG_F("NetTest()");

	CNetManager::Local(EM_NET_MANAGER_BOOST);

	CNetIp* pIp1       = NetManager()->CreateIp("127.0.0.1", 9001);
	delete pIp1;

	CNetPoint* pPoint1 = NetManager()->CreatePoint();
	delete pPoint1;

	CNetListener* pListner1 = NetManager()->CreateListener(EM_NET_TCP);
	delete pListner1;

	CNetManager::Local(EM_NET_MANAGER_KBE);

	CNetIp* pIp2       = NetManager()->CreateIp("127.0.0.1", 9001);
	delete pIp2;

	CNetPoint* pPoint2 = NetManager()->CreatePoint();
	delete pPoint2;

	CNetListener* pListner2 = NetManager()->CreateListener(EM_NET_TCP);
	delete pListner2;


	return 0;
}

_SERVOCE_DOOR_END

#include "x_util.h"
#include "x_net.h"

_SERVOCE_DOOR_BEGIN

///////////////////////////////////CNetManager///////////////////////////////////////

extern CNetManager* g_pNetMgr_Boost;
extern CNetManager* g_pNetMgr_Kbe;

static ENetManagerType s_eNetMgrType = ENetManagerType_BOOST;

VOID_T CNetManager::Local(ENetManagerType eType)
{
	s_eNetMgrType = eType;
}

CNetManager* NetManager()
{
	switch(s_eNetMgrType)
	{
	case ENetManagerType_BOOST:
		return g_pNetMgr_Boost;
	case ENetManagerType_KBE:
		return g_pNetMgr_Kbe;
	default:
		return NULL;
	}
}

///////////////////////////////////NetTest///////////////////////////////////////

_SERVICE_IMPLEMENT ERR_T NetTest()
{
	LOG_F("NetTest()");

	CNetManager::Local(ENetManagerType_BOOST);

	CNetIp* pIp1       = NetManager()->CreateIp("127.0.0.1", 9001);
	delete pIp1;

	CNetPoint* pPoint1 = NetManager()->CreatePoint();
	delete pPoint1;

	CNetListener* pListner1 = NetManager()->CreateListener(ENetType_TCP);
	delete pListner1;

	CNetManager::Local(ENetManagerType_KBE);

	CNetIp* pIp2       = NetManager()->CreateIp("127.0.0.1", 9001);
	delete pIp2;

	CNetPoint* pPoint2 = NetManager()->CreatePoint();
	delete pPoint2;

	CNetListener* pListner2 = NetManager()->CreateListener(ENetType_TCP);
	delete pListner2;


	return 0;
}

_SERVOCE_DOOR_END
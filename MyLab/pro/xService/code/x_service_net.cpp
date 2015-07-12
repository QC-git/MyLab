
#include "x_util.h"
#include "x_net.h"

_SERVOCE_DOOR_BEGIN

///////////////////////////////////CNetManager///////////////////////////////////////

extern CNetManager* g_pNetMgr_Boost;

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
		return NULL;
	default:
		return NULL;
	}
}

///////////////////////////////////NetTest///////////////////////////////////////

_SERVICE_IMPLEMENT ERR_T NetTest()
{
	//LOG_F("NetTest()");

	return 0;
}

_SERVOCE_DOOR_END
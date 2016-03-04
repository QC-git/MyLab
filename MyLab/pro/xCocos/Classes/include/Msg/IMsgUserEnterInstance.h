//==========================================================================
/**
*  @file   IMsgUserEnterInstance.h
*
*  $Id: IMsgUserEnterInstance.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGUSERENTERINSTANCE_H_
#define _MSG_IMSGUSERENTERINSTANCE_H_

#include "Define.h"
namespace msguserenterinstance
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SCID        userScid;      // 玩家的SOCKET ID
		SNID        insSnid;       // 副本的ID
		
		UINT        unState;
		OBJID       idAccount;
		UINT        unVipLevel;

		OBJID       idUser;
		char        szName[256];
		char        szMonicker[256];
		INT         nLevel;
		INT         nLook;
		INT         nFace;
        INT         nMap;
	} MSG_USERENTERINSTANCE;
}
#endif

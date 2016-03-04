//==========================================================================
/**
*  @file   IMsgInsAction.h
*
*  $Id: IMsgInsAction.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGINSACTION_H_
#define _MSG_IMSGINSACTION_H_

#include "Define.h"
#include "MsgDefine.h"

namespace msginsaction
{
	enum
	{
        actionGetUserInfo,          //获得玩家信息
		//actionGetItemSet,           //获得物品信息 // TODO::MILO 11/12/2015 EntityExLogic
        actionGetEquipSet,          //获取装备信息
        actionGetSkillSet,          //获得技能信息
		actionGetInfoEnd,			//结束标志
		actionRoomEnd,			    //结束标志
	};
	
// #pragma pack(push,1)
	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;

		USHORT	    usAction;		
	    OBJID		idUser;

	} MSG_INS_ACTION;
// #pragma pack(pop,1)
}

#endif

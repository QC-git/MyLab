// MsgUserAttrib.h: interface for the CMsgItem class.
/**
 *  @file   IMsgUserAttrib.h
 *
 *  $Id: IMsgUserAttrib.h
 *
 *  @author chx <xxx@gmail.com>
 *  
 */
//==========================================================================

#ifndef _MSG_IMSGGETUSER_H_
#define _MSG_IMSGGETUSER_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
namespace msggetuser
{
	enum 
	{	
		INTERACT_NONE =0,
		actionexp,
		action_secondary_attack,
        action_killExp,
	};
//此消息用来向副本服务器 索要idRole周围的人 
	#pragma pack(push, 1)
	typedef struct
	{
		USHORT	usMsgSize;
		USHORT	usMsgType;
					
		OBJID	idRole;
        USHORT  usAttackCamp;
		USHORT  usAction;
		int     nAmount;
		union
		{
			bool bIsShareExp; 
		};
		UCHAR	ucTargetAmount;	//目标数量
		OBJID   idAryTarget[1]; //目标id集
	}MSG_GETUSER;
	#pragma pack(pop)
}

#endif


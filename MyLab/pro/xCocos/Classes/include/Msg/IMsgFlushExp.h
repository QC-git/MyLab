#ifndef _MSG_IMSGFLUSHEXP_H_
#define _MSG_IMSGFLUSHEXP_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#pragma pack(1)

namespace msgflushexp
{
	enum 
	{
		MSGFLUSHEXP_WEAPONSKILL,
		MSGFLUSHEXP_MAGIC,
		MSGFLUSHEXP_SKILL,
		MSG_USE_ANGEL_COUNTDOWN         =   4,

		MSG_USERCURSE_REMAINTIME	= 10,		// 2006.08.07 通知客户端玩家诅咒结束时间倒计时
		MSG_USERPRACTISE_POINTS		= 11,		//to c 在线练功点数，dwExp：点数,usType=1闪烁光效，usType=0 不闪烁						
		MSG_FULL_QUALITY9			= 12,		//to c 全部极品装备,dwExp=playerid  tcp 2007-1-13 add	
		MSG_MSG_USER_RECOVERY_REMAINTIME = 13,		// 通知客户端玩家加防结束时间倒计时
		MSG_USERFLY_REMAINTIME		= 15,       //通知客户端飞行时间
		MSG_USERDAMAGEDEC_REMAINTIME = 16,		//领域技能玩家伤害值减少持续时间
		MSG_RECOVER_POWER_SLOWLY	= 100,		// 2005.12.23 通知客户端发动机恢复目标值和变化速度  to Client
		MSG_RECOVER_EN_SLOWLY,					// 2005.12.23 通知客户端EN恢复目标值和变化速度  to Client
		MSG_TRANSPOS				= 106,		// 2007.3.2 通知周围玩家自己被传送  to Client	dwExp:idPlayer			
		MSG_ATTACK_MONSTER_BY_RIGHT_WEAPON_AND_MAGIC = 107,//to C 2007.3.15 周围玩家怪、物被合适的武器和技能击中
		//dwExp:idMonster
		MSG_BEGIN_ONTIMER = 108,				//to C 2007.3.26 nType:定时器的秒数 定时器效果 tcp 2007-3-26 add
		MSG_PLAYFLASH = 109,				    //to C idIndex:编号 nType:循环次数 nDelayTimes:延迟时间 tcp 2007-3-27 add		
		MSG_SCREEN_EFFECT =110,					//to C 2007.4.14 tcp add 机战新增功能需求	dwValue:屏幕效果
		MSG_STOP_EXCERSISE = 111,               //to C 练功点停止计数。服务端未使用
		MSGFLUSHEXP_LIFESKILL = 200,
	};
	typedef struct
	{
		USHORT	usMsgSize;
		USHORT	usMsgType;

        union
		{
			struct 
			{// 增加一个播放flash的action 2007-4-5 tcp add
				OBJID idIndex;
				int   nDelayTimes;
			};
			U64			u64Exp;
		};

		union
		{
			int				nType;
			U32			dwValue;//机战新增功能需求 2007-4-14 tcp add
		};
		
		USHORT			    ucAction;
	}MSG_FLUSHEXP_INFO;
}

#pragma pack()

#endif //_MSG_IMSGFLUSHEXP_H_

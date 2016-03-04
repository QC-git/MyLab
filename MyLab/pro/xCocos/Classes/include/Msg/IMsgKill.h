//==========================================================================
/**
*  @file   IMsgkill.h
*
*  $Id:  IMsgkill.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _IMSGKILL_H_
#define _IMSGKILL_H_

#include "Define.h"
#include "MsgDefine.h"

namespace msgkill
{
	enum
	{
		actionKillRole,
		actionDamageRole,
		actionRenewHpRole,
	};
	typedef struct 
	{
		USHORT usMsgSize;
		USHORT usMsgType;

		OBJID  idAttack;
        OBJID  idBeAttack;
        USHORT usAttackCamp;
        OBJID  idType;
		OBJID  idInstance;
		OBJID  idSkill;
		int    nDamage;
		USHORT usAction;
		OBJID  idTypeBeAttackParent;	// 被攻击者的父类的类型
		UCHAR  ucTargetAmount;	// 目标数量
		OBJID  idAryTarget[1];  // 目标id集
	}MSG_KILL;
}

#endif

////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2007, TQ Digital Entertainment, All Rights Reserved
// Author:      Shen Rongfei
// Created:     2011/06/14
////////////////////////////////////////////////////////////////////////

#ifndef _IMSGSKILLTOUCH_H_
#define _IMSGSKILLTOUCH_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
NAMESPACE_BEGIN(msgskilltouch)

enum MSG_SKILLTOUCH_ACTION
{
	MSG_SKILLTOUCH_TOUCH_DAMAGE	= 0,	//´¥·¢damage
	MSG_SKILLTOUCH_TOUCH_SKILL	= 1,	//´¥·¢skill
};

#pragma  pack(push)
#pragma  pack(1)
typedef struct
{
	USHORT		usMsgSize;
	USHORT		usMsgType;

	U64	u64PlayerID;
	U32	idSkill;
	U64	u64TargetID;
	USHORT	usAction;
	float	fPosX;
	float	fPosY;
	float	fPosZ;

}MSG_SKILLTOUCH;
#pragma pack(pop)
NAMESPACE_END(msgskilltouch)

#endif

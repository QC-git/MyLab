//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      yuwj
// Created:     2011/318
// 
// ר�����ԣ�����ս���츳��ս����ʯ
// 
//*********************************************************************
#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglppvegameheroes)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
	OBJID	idAccount;
	LPPVEGameHero heroes[3];
	LPPVEGameHero pet[3];
}MSG_LP_PVE_GAME_HEROES, *PMSG_LP_PVE_GAME_HEROES;
#pragma pack(pop)

NAMESPACE_END(msglppvegameheroes)

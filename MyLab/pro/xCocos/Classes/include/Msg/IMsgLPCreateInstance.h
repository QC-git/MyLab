//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      Dqs
// Created:     2015/11/05
//
//*********************************************************************

#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpcreateinstance)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
    OBJID   lpRequestId;	// LP用于标识此请求的ID，在MSG_CREATE_GAME_ACK原样发回 
	OBJID	idInstanceType;
	OBJID	gameConf;
	USHORT  idMap;
    bool    bDeny;  //反补
	USHORT  gameMode;									// 游戏模式
	OBJID   freeHeroWeek[FREE_HERO_WEEK_AMOUNT];		// 本周免费英魂
	OBJID   bossDaily[FIGHT_BOSS_DAILY_AMOUNT];			// 每日BOSS
	USHORT  usTeamAmount;								// 队伍规模:5vs5 teamAmount=5
	OBJID	captainA;
	OBJID	captainB;
    USHORT  usAmount;
    LPROOMDATA roomDatas[1];
} PACKED MSG_LPCREATE_INSTANCE, *PMSG_LPCREATE_INSTANCE;
#pragma pack(pop)

NAMESPACE_END(msglpcreateinstance)


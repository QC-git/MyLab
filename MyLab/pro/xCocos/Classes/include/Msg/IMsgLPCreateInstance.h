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
	
    OBJID   lpRequestId;	// LP���ڱ�ʶ�������ID����MSG_CREATE_GAME_ACKԭ������ 
	OBJID	idInstanceType;
	OBJID	gameConf;
	USHORT  idMap;
    bool    bDeny;  //����
	USHORT  gameMode;									// ��Ϸģʽ
	OBJID   freeHeroWeek[FREE_HERO_WEEK_AMOUNT];		// �������Ӣ��
	OBJID   bossDaily[FIGHT_BOSS_DAILY_AMOUNT];			// ÿ��BOSS
	USHORT  usTeamAmount;								// �����ģ:5vs5 teamAmount=5
	OBJID	captainA;
	OBJID	captainB;
    USHORT  usAmount;
    LPROOMDATA roomDatas[1];
} PACKED MSG_LPCREATE_INSTANCE, *PMSG_LPCREATE_INSTANCE;
#pragma pack(pop)

NAMESPACE_END(msglpcreateinstance)


//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      lxy
// Created:     2010/02/25
//
//*********************************************************************

#ifndef _INSTANCE_IMSGLP_GAME_RESULT_H_
#define _INSTANCE_IMSGLP_GAME_RESULT_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"

NAMESPACE_BEGIN(msggameresult)

#pragma pack(push, 1)

enum EResult
{
    eResult_Win,
    eResult_Lose,
    eResult_Abort,
};


struct GAMING_RESULT
{
    unsigned long	result;					// 战斗结果，EResult
    unsigned long	exp;					// 获得平台经验
    unsigned long	gold;				    // 这次战斗获得的金币(游戏中的金币，非平台金币)
    int             score;                  // 获得或者减少的匹配分
    unsigned long	heroType;				// 选择的英雄--这场战斗选择的英雄统计
    unsigned long	equip1;                 // 装备1
    unsigned long	equip2;					// 装备2
    unsigned long	equip3;					// 装备3
    unsigned long	equip4;					// 装备4
    unsigned long	equip5;					// 装备5
    unsigned long	equip6;					// 装备6
    unsigned long	killHeroAmount;			// 击杀英雄数量	[累计]
    unsigned long	secondaryAttackAmount;	// 助攻数		[累计]
    unsigned long	killEmplacementAmount;	// 摧毁炮台数	[累计]
    unsigned long	killSoldiersAmount;		// 击杀小兵数	[累计]
    unsigned long	killBarracksAmount;		// 摧毁兵营数
    unsigned long	killNeutralityAmount;	// 中立生物
    unsigned long	gainMoney;				// 这次战斗获得的金币(游戏中的金币，非平台金币)  
    unsigned long	seriesKill;				// 最高连杀
    unsigned long	moreKill;				// 最多连杀
    unsigned long	outputDamage;			// 输出的伤害
    unsigned long	outputNormalDamage;		// 输出的物理伤害
    unsigned long	outputMagicDamage;		// 输出的魔法伤害
    unsigned long	supportDamage;			// 承受的伤害
    unsigned long	supportNormalDamage;	// 承受的物理伤害
    unsigned long	supportMagicDamage;		// 承受的魔法伤害
    unsigned long   dieAmount;              // 死亡次数
    unsigned long   evaluateState;          // 评价状态
    unsigned long	mapId;					// 地图
    unsigned long	heroMode;				// 英雄模式
    unsigned long	gameTime;				// 比赛起始时间
    unsigned long	endTime;				// 比赛起始时间
	unsigned long	gameMode;				// 游戏模式
	unsigned long	lgnExp;					// 工会经验
    unsigned long	expandAttr;				// 扩展属性
	unsigned long	worldId;				// 扩展属性
};


typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
    unsigned long	gameInstanceId;
    unsigned long	accountId;
    GAMING_RESULT	result;
}MSG_GAME_RESULT, *PMSG_GAME_RESULT;

#pragma pack(pop)

NAMESPACE_END(msggameresult)


#endif

#pragma once

#include "BaseCode/BaseMacro.h"

NAMESPACE_BEGIN(msginvalidgameresult)


#pragma pack(push, 1)

enum EResult
{
    eResult_Win,
    eResult_Lose,
    eResult_Abort,
};


struct INVALID_GAMING_RESULT
{
	uint32_t	result;					// 战斗结果，EResult
	int32_t     score;                  // 获得或者减少的匹配分
	uint32_t	heroType;				// 选择的英雄--这场战斗选择的英雄统计
	uint32_t	equip1;                 // 装备1
	uint32_t	equip2;					// 装备2
	uint32_t	equip3;					// 装备3
	uint32_t	equip4;					// 装备4
	uint32_t	equip5;					// 装备5
	uint32_t	equip6;					// 装备6
	uint32_t	killHeroAmount;			// 击杀英雄数量	[累计]
	uint32_t	secondaryAttackAmount;	// 助攻数		[累计]
	uint32_t	killNeutralityAmount;	// 中立生物
	uint32_t    dieAmount;              // 死亡次数
	uint32_t	gameTime;				// 比赛起始时间
	uint32_t	endTime;				// 比赛起始时间
	uint32_t    gameMode;               // 游戏模式

	uint32_t	worldId;
	uint32_t	accountId;
};

typedef struct
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	INVALID_GAMING_RESULT results[10];
}MSG_INVALID_GAME_RESULTS, *PMSG_INVALID_GAME_RESULTS;

#pragma pack(pop)

NAMESPACE_END(msginvalidgameresult)

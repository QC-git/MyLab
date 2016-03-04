//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      majl
// Created:     2010/02/25
//
//*********************************************************************
#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglppvebeatboss)

#pragma pack(push, 1)


typedef struct 
{
	USHORT usMsgSize;
	USHORT usMsgType;

	typedef struct
	{
		U32 accountId;		// 账服发给client的account ID
		U32 worldId;		// 服务器ID
		U32 outputDmg;		// 输出伤害
		U32 nScore;			// 评分
		U32 maxEquipScore;	// 最高战斗力
		U32 legionId;		// 公会 ID
		U32 expandAttr;		// 扩展属性
		bool isValid;		// 是否正常结束
	}SPlayer;

	U32 beatId;
	USHORT star;
    USHORT finishStar;
	bool finish;
	USHORT userAmount;
	SPlayer users[1];
}MSG_LP_PVE_BEAT_BOSS, *PMSG_LP_PVE_BEAT_BOSS;
#pragma pack(pop)

NAMESPACE_END(msglppvebeatboss)

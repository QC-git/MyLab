//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      yuwj
// Created:     2011/318
// 
// 专精属性，包括战斗天赋和战斗宝石
// 
//*********************************************************************
#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglppveupdateitem)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	U32	accountId; // 账服发给client的account ID
	USHORT  amount;	
	LPPVEItem		items[1];	
}MSG_LP_PVE_UPDATE_ITEM, *PMSG_LP_PVE_UPDATE_ITEM;
#pragma pack(pop)

NAMESPACE_END(msglppveupdateitem)

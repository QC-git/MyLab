//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      yuwj
// Created:     2013/07/23
//
//*********************************************************************
#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpupdatebuyhero)

#pragma pack(push, 1)

typedef struct 
{
	enum EBuyAction
	{
		eBuyAction_Hero,
		eBuyAction_Skin,
	};

	USHORT usMsgSize;
	USHORT usMsgType;
	
    U32         	accountId;	// 账服发给client的account ID
	EBuyAction		buyAction;
    U32         	idHero;
    U32         	idSkin;
}MSG_LP_UPDATE_BUY_HERO, *PMSG_LP_UPDATE_BUY_HERO;
#pragma pack(pop)

NAMESPACE_END(msglpupdatebuyhero)


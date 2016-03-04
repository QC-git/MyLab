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

NAMESPACE_BEGIN(msglpplayerinfo)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
    OBJID   idAccount;	
    LPPLAERATA Data;
    USHORT usAmmount;
    USHORT usheroAmount;
	USHORT usHeroFeatAmount;
    U32 heros[100];
	UCHAR  heroFeats[100];
    LPPLAYERSKINATACK szSkinData[1];
} PACKED MSG_LP_PLAYERINFO, *PMSG_LP_PLAYERINFO;
#pragma pack(pop)

NAMESPACE_END(msglpplayerinfo)

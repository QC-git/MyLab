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

NAMESPACE_BEGIN(msglpupdateroleheroskin)

#pragma pack(push, 1)


typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	U32         	accountId;	// 账服发给client的account ID
    U32             worldId;	// 服务器ID
	unsigned short	amount;		// 
	LPPLAYERSKINATA skins[1];
}MSG_LP_UPDATE_ROLE_HEROSKIN, *PMSG_LP_UPDATE_ROLE_HEROSKIN;
#pragma pack(pop)

NAMESPACE_END(msglpupdateroleheroskin)


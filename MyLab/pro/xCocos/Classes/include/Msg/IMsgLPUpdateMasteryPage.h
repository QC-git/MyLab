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

NAMESPACE_BEGIN(msglpupdatemasterypage)

#pragma pack(push, 1)

typedef struct 
{
	USHORT usMsgSize;
	USHORT usMsgType;
	
    U32 accountId;	// 账服发给client的account ID
	U32 worldId;    // 服务器ID
	U32 page;
}MSG_LP_UPDATE_MASTERY_PAGE, *PMSG_LP_UPDATE_MASTERY_PAGE;
#pragma pack(pop)

NAMESPACE_END(msglpupdatemasterypage)

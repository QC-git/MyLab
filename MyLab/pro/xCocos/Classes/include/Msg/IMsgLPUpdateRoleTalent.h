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

NAMESPACE_BEGIN(msglpupdateroletalent)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
    U32	accountId;	// 账服发给client的account ID
    unsigned short	amount;		// 
    U32   talents[1];
}MSG_LP_UPDATE_ROLE_TALENT, *PMSG_LP_UPDATE_ROLE_TALENT;
#pragma pack(pop)

NAMESPACE_END(msglpupdateroletalent)


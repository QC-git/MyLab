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

NAMESPACE_BEGIN(msglpremoveplayer)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
	OBJID   idAccount;	
	U32     worldId;
	OBJID   idIns;	
}MSG_LPREMPVE_PLAYER, *PMSG_LPREMPVE_PLAYER;
#pragma pack(pop)

NAMESPACE_END(msglpremoveplayer)


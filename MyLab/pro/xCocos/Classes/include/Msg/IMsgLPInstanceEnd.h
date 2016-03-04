//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      majl
// Created:     2010/11/25
//
//*********************************************************************

#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpinstanceend)

#pragma pack(push, 1)

typedef struct 
{
    USHORT	usMsgSize;
    USHORT	usMsgType;

    OBJID   idInstance;
    USHORT  usResultCount;
    USHORT  usCamp;
	OBJID	heroesBanA[5];
	OBJID   heroesBanB[5];	
} PACKED MSG_LPINSTANCE_END, *PMSG_LPINSTANCE_END;
#pragma pack(pop)

NAMESPACE_END(msglpinstanceend)


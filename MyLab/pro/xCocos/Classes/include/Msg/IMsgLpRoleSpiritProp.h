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

NAMESPACE_BEGIN(msglprolespiritprop)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
	OBJID   idAccount;	
	U32     topRatio;
    U32     initialRatio;
    U32     growRatio;
    U32     growInterval;
    LPROLESPIRITPROP propPower;
	LPROLESPIRITPROP propAgile;
	LPROLESPIRITPROP propIntel;
}MSG_LP_ROLESPIRITPROP, *PMSG_LP_ROLESPIRITPROP;
#pragma pack(pop)

NAMESPACE_END(msglprolespiritprop)

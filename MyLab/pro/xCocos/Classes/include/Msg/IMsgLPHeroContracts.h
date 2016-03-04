//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      yuwj
// Created:     2012/12/31
//
//*********************************************************************


#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpherocontracts)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
	OBJID  idAccount;	
    USHORT usAmount;
    U32 heroContracts[1];
}MSG_LP_HEROCONTRACTS, *PMSG_LP_HEROCONTRACTS;
#pragma pack(pop)

NAMESPACE_END(msglpherocontracts)

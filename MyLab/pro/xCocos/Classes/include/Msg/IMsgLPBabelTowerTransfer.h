//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      xujb
// Created:     2015/08/07
//
//*********************************************************************

#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpbabeltowertarnsfer)

#pragma pack(push, 1)


typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	unsigned long	accountId;		// 账服发给client的account ID
	unsigned short  iCurLayer;
	unsigned short  iNextLayer;
}MSG_LP_BABELTOWER_TRANSFER, *PMSG_LP_BABELTOWER_TRANSFER;


#pragma pack(pop)

NAMESPACE_END(msglpbabeltowertarnsfer)


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

NAMESPACE_BEGIN(msglpuseitem)

#pragma pack(push, 1)


typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	enum EAction
	{
		eAction_Use,
		eAction_Del,
	};

	U32	accountId;		// 账服发给client的account ID
	U32   worldId;	// 服务器ID
	unsigned short	action;
	U32   idItem;
	U32   idItemType;
	float posX;
	float posY;
	float posZ;
	U32	idMap;
	U32	nDeath;	// 账服发给client的account ID
	unsigned short	result;
}MSG_LP_USE_ITEM, *PMSG_LP_USE_ITEM;
#pragma pack(pop)

NAMESPACE_END(msglpuseitem)


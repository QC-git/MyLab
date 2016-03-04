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

NAMESPACE_BEGIN(msglpretitem)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	struct SItemInfo
	{
		U32 idItemType;
        U32 nAmount;
	};

	struct SUserItem
	{
		U32 accountId;
		SItemInfo items[4];
	};

	unsigned short amount;
	SUserItem userItems[1];
}MSG_LP_RET_ITEM, *PMSG_LP_RET_ITEM;
#pragma pack(pop)

NAMESPACE_END(msglpretitem)

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

NAMESPACE_BEGIN(msglppvehistory)

#pragma pack(push, 1)

typedef struct 
{
	USHORT usMsgSize;
	USHORT usMsgType;

	struct SPVERoleHistory
	{
		OBJID accountId;
		OBJID switchTimes;
		OBJID deathTimes;
		OBJID outputDmg;
		OBJID endureDmg;
		OBJID itemAmount[5];

		SPVERoleHistory() : accountId( 0 ), switchTimes( 0 ), deathTimes( 0 ), outputDmg( 0 ), endureDmg( 0 ) { memset(itemAmount, 0, sizeof(itemAmount)); }
	};

	OBJID insId;
	OBJID bossId;
	OBJID useTime;
	SPVERoleHistory history[5]; 

}MSG_LP_PVE_HISTORY, *PMSG_LP_PVE_HISTORY;
#pragma pack(pop)

NAMESPACE_END(msglppvehistory)
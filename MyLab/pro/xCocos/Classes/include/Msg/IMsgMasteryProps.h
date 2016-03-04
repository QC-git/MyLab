//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      yuwj
// Created:     2011/318
// 
// ר�����ԣ�����ս���츳��ս����ʯ
// 
//*********************************************************************
#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpmasteryprops)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
	OBJID	idAccount;
	U32  curPage;
	USHORT	usAmount;
	LPMasteryProp props[1];
}MSG_LP_MASTERY_PROPS, *PMSG_LP_MASTERY_PROPS;
#pragma pack(pop)

NAMESPACE_END(msglpmasteryprops)


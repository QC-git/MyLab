//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      majl
// Created:     2010/11/25
//
//*********************************************************************

#ifndef _INSTANCE_IMSGINSTANCE_INFO_H_
#define _INSTANCE_IMSGINSTANCE_INFO_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"

NAMESPACE_BEGIN(msginstanceinfo)

enum
{
	CREATE_WORLD					            = 0,
	CREATE_INSTANCE						        = 1,
	CREATE_INSTANCE_SUC						    = 2,
};

#pragma pack(push, 1)

typedef struct
{
    OBJID idBaseMap;
	OBJID idMap;
    float fPortX;
	float fPortY;
	float fPortZ;
}INSTANCEDATA;

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
	OBJID	idInstance;
	USHORT  ustype;
	USHORT  usAmount;
	INSTANCEDATA stData[1];

}MSG_INSTANCEINFO, *PMSG_INSTANCEINFO;

#pragma pack(pop)

NAMESPACE_END(msginstanceinfo)


#endif

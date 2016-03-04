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

NAMESPACE_BEGIN(msglpcreateinstanceret)

#pragma pack(push, 1)

enum EResult
{
    eResult_Ok,
    eResult_Failed,
};

typedef struct 
{
    USHORT	usMsgSize;
    USHORT	usMsgType;

    EResult   result;
    OBJID     idInstance;
    OBJID     idlpRequest;
    char      strTelecomIp[256]; //����IP
    char      strNetcomIp[256]; //��ͨIP
    char      strEducomIp[256]; //����IP
    char      strETietongIp[256]; //��ͨIP
    unsigned short     uServicePort;  //����˿�	
} PACKED MSG_LPCREATE_INSTANCERET, *PMSG_LPCREATE_INSTANCERET;
#pragma pack(pop)

NAMESPACE_END(msgroom)

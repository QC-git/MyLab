////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2007, TQ Digital Entertainment, All Rights Reserved
// Author:      Shen Rongfei
// Created:     2010/09/15
////////////////////////////////////////////////////////////////////////

#ifndef _IMSGUSERMAGICDATA_H_
#define _IMSGUSERMAGICDATA_H_

#include "Define.h"
#include "MsgDefine.h"
const int	SKILL_NAME_TYPESIZE	= 31;				// 技能类型名长度
namespace msgusermagicdata
{
#pragma pack(push, 1)

struct USERMAGICDATA_INFO
{
	OBJID	id;
	OBJID	idType;
	USHORT	idLevel;
	USHORT	usOwnerType;
	char   szName[SKILL_NAME_TYPESIZE];	
};

typedef struct
{
	USHORT				usMsgSize;
	USHORT				usMsgType;

	OBJID				idOwner;
	USHORT				usRecordAmount;
	USERMAGICDATA_INFO	setRecords[1];

}MSG_USERMAGICDATA_INFO;

#pragma pack(pop)
}

#endif

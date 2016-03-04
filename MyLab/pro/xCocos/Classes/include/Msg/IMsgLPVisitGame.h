#pragma once

#include "Define.h"

NAMESPACE_BEGIN(msglpvisitgame)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	U32	accountId;	// 账服发给client的account ID
	U32	accountIdBak;
	U32	camp;
	LPROOMDATA		info;
}MSG_LP_VISIT_GAME, *PMSG_LP_VISIT_GAME;

#pragma pack(pop)

NAMESPACE_END(msglpvisitgame)


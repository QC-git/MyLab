#pragma once


#include "Define.h"

NAMESPACE_BEGIN(msglprandhero)

#pragma pack(push, 1)

typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	U32	    accountId;	// 账服发给client的account ID
	USHORT	result;
}PACKED MSG_LP_RAND_HERO, *PMMSG_LP_RAND_HERO;

#pragma pack(pop)

NAMESPACE_END(msglprandhero)


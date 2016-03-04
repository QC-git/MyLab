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

NAMESPACE_BEGIN(msglppvebeatboss)

#pragma pack(push, 1)


typedef struct 
{
	USHORT usMsgSize;
	USHORT usMsgType;

	typedef struct
	{
		U32 accountId;		// �˷�����client��account ID
		U32 worldId;		// ������ID
		U32 outputDmg;		// ����˺�
		U32 nScore;			// ����
		U32 maxEquipScore;	// ���ս����
		U32 legionId;		// ���� ID
		U32 expandAttr;		// ��չ����
		bool isValid;		// �Ƿ���������
	}SPlayer;

	U32 beatId;
	USHORT star;
    USHORT finishStar;
	bool finish;
	USHORT userAmount;
	SPlayer users[1];
}MSG_LP_PVE_BEAT_BOSS, *PMSG_LP_PVE_BEAT_BOSS;
#pragma pack(pop)

NAMESPACE_END(msglppvebeatboss)

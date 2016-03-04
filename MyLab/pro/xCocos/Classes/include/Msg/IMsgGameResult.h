//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      lxy
// Created:     2010/02/25
//
//*********************************************************************

#ifndef _INSTANCE_IMSGLP_GAME_RESULT_H_
#define _INSTANCE_IMSGLP_GAME_RESULT_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"

NAMESPACE_BEGIN(msggameresult)

#pragma pack(push, 1)

enum EResult
{
    eResult_Win,
    eResult_Lose,
    eResult_Abort,
};


struct GAMING_RESULT
{
    unsigned long	result;					// ս�������EResult
    unsigned long	exp;					// ���ƽ̨����
    unsigned long	gold;				    // ���ս����õĽ��(��Ϸ�еĽ�ң���ƽ̨���)
    int             score;                  // ��û��߼��ٵ�ƥ���
    unsigned long	heroType;				// ѡ���Ӣ��--�ⳡս��ѡ���Ӣ��ͳ��
    unsigned long	equip1;                 // װ��1
    unsigned long	equip2;					// װ��2
    unsigned long	equip3;					// װ��3
    unsigned long	equip4;					// װ��4
    unsigned long	equip5;					// װ��5
    unsigned long	equip6;					// װ��6
    unsigned long	killHeroAmount;			// ��ɱӢ������	[�ۼ�]
    unsigned long	secondaryAttackAmount;	// ������		[�ۼ�]
    unsigned long	killEmplacementAmount;	// �ݻ���̨��	[�ۼ�]
    unsigned long	killSoldiersAmount;		// ��ɱС����	[�ۼ�]
    unsigned long	killBarracksAmount;		// �ݻٱ�Ӫ��
    unsigned long	killNeutralityAmount;	// ��������
    unsigned long	gainMoney;				// ���ս����õĽ��(��Ϸ�еĽ�ң���ƽ̨���)  
    unsigned long	seriesKill;				// �����ɱ
    unsigned long	moreKill;				// �����ɱ
    unsigned long	outputDamage;			// ������˺�
    unsigned long	outputNormalDamage;		// ����������˺�
    unsigned long	outputMagicDamage;		// �����ħ���˺�
    unsigned long	supportDamage;			// ���ܵ��˺�
    unsigned long	supportNormalDamage;	// ���ܵ������˺�
    unsigned long	supportMagicDamage;		// ���ܵ�ħ���˺�
    unsigned long   dieAmount;              // ��������
    unsigned long   evaluateState;          // ����״̬
    unsigned long	mapId;					// ��ͼ
    unsigned long	heroMode;				// Ӣ��ģʽ
    unsigned long	gameTime;				// ������ʼʱ��
    unsigned long	endTime;				// ������ʼʱ��
	unsigned long	gameMode;				// ��Ϸģʽ
	unsigned long	lgnExp;					// ���ᾭ��
    unsigned long	expandAttr;				// ��չ����
	unsigned long	worldId;				// ��չ����
};


typedef struct 
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	
    unsigned long	gameInstanceId;
    unsigned long	accountId;
    GAMING_RESULT	result;
}MSG_GAME_RESULT, *PMSG_GAME_RESULT;

#pragma pack(pop)

NAMESPACE_END(msggameresult)


#endif

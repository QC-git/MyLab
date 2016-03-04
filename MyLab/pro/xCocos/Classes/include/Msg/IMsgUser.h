// -*- C++ -*-

//=============================================================================
/**
 *  @file    IMsgUser.h
 *
 *  $Id: IMsgUser.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _MSG_IMSGUSER_H_
#define _MSG_IMSGUSER_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#include "MsgDefine.h"
#pragma pack(4)

NAMESPACE_BEGIN(msguser)
		
enum
{
};

typedef struct
{	                 
	USHORT			usMsgSize;
	USHORT			usMsgType;
	
	OBJID			idUser;              	
	UCHAR			ucLevel;	
	U32				dwLookFace;			// ��ò
	U32				dwMaxLife;
	U32				dwMaxMana;
	U32				dwMinAttack;        //����������
	U32				dwMaxAttack;        //����������
	float           dwDef;              //��������
	U32				dwMagicDef;         //����ħ��
	U32				dwPVEEquipMagicDef;	//PVEװ��ħ��
	U32				dwPower;            //��������
	U32				dwBrain;            //��������
	U32				dwAgility;          //��������
	U32				dwRestoreLife;      //��Ѫ/��
	U32				dwRestoreMana;      //����/��
	int             nLife;              //����
    int             nMana;              //ħ��ֵ
	int             nInstance;          //����ID
	USHORT          usCamp;
	USHORT          usObsize;           //��ײ��Ĵ�С
	int             nSpeed;
	float           fChaseDist;
	float           fTurnRate;//ת���ٶ�
	float           fBat;
	int             nSkillIndex;
    int             title;
    int             rank;
    int             magicAttack;
	char			szAIName[_MAX_NAMESIZE]; //AiName
	char			szPlayerName[_MAX_NAMESIZE];
	bool			bLongRange;			//�Ƿ�Զ��Ӣ��
    int             VipLevel;
    unsigned int    control;            //robot������
	int				heroSkin;
    int             collideRaid;
	int				spiritParryChance;
	int				masteryParryChance;
	U32			hit;
	U32			phyPass;
	U32			crit;
	U32			critRes;
	U32			phySuck;
	U32			spePass;
	U32			speSuck;
	U32			speCd;
	bool			bInit;					// �Ƿ��ʼ��
	U32			dwPVEEquipMinAttack;	// PVEװ��������
	U32			dwPVEEquipMaxAttack;	// PVEװ��������
	U32			stateDamageType;		// ״̬�˺�����
	U32			stateDamageModulus;		// ״̬�˺�ϵ��
	USHORT			mainAttribute;			// Ӣ��������
	U32			dwPVEPhyAttackModulus;	// �������˺�ϵ��
	int				ditch;					// ����
	OBJID			idMainUser;				// ��Ӣ��ID
	U32			toughness;				// ����
	U32			toughnessPenetration;	// ���Դ�͸
	UINT32			defalultPassiveSkill;	// Ĭ�ϱ�������
}MSG_USER;

NAMESPACE_END(msguser)

#pragma pack()

#endif //_MSG_IMSGUSER_H_

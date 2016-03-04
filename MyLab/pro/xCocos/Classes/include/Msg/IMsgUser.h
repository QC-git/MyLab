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
	U32				dwLookFace;			// 外貌
	U32				dwMaxLife;
	U32				dwMaxMana;
	U32				dwMinAttack;        //基础攻击力
	U32				dwMaxAttack;        //基础攻击力
	float           dwDef;              //基础护甲
	U32				dwMagicDef;         //基础魔抗
	U32				dwPVEEquipMagicDef;	//PVE装备魔抗
	U32				dwPower;            //基础力量
	U32				dwBrain;            //基础智力
	U32				dwAgility;          //基础敏捷
	U32				dwRestoreLife;      //回血/秒
	U32				dwRestoreMana;      //回蓝/秒
	int             nLife;              //生命
    int             nMana;              //魔法值
	int             nInstance;          //副本ID
	USHORT          usCamp;
	USHORT          usObsize;           //碰撞体的大小
	int             nSpeed;
	float           fChaseDist;
	float           fTurnRate;//转身速度
	float           fBat;
	int             nSkillIndex;
    int             title;
    int             rank;
    int             magicAttack;
	char			szAIName[_MAX_NAMESIZE]; //AiName
	char			szPlayerName[_MAX_NAMESIZE];
	bool			bLongRange;			//是否远程英雄
    int             VipLevel;
    unsigned int    control;            //robot才有用
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
	bool			bInit;					// 是否初始化
	U32			dwPVEEquipMinAttack;	// PVE装备攻击力
	U32			dwPVEEquipMaxAttack;	// PVE装备攻击力
	U32			stateDamageType;		// 状态伤害类型
	U32			stateDamageModulus;		// 状态伤害系数
	USHORT			mainAttribute;			// 英雄主属性
	U32			dwPVEPhyAttackModulus;	// 物理攻击伤害系数
	int				ditch;					// 渠道
	OBJID			idMainUser;				// 主英雄ID
	U32			toughness;				// 韧性
	U32			toughnessPenetration;	// 韧性穿透
	UINT32			defalultPassiveSkill;	// 默认被动技能
}MSG_USER;

NAMESPACE_END(msguser)

#pragma pack()

#endif //_MSG_IMSGUSER_H_

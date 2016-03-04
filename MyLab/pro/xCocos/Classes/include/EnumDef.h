// -*- C++ -*-

//=============================================================================
/**
 *  @file    EnumDef.h
 *
 *  $Id: EnumDef.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _TQ_ENUM_DEFINE_H_
#define _TQ_ENUM_DEFINE_H_

#include "ConstDef.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/***************************************************************************
//��ע�⣺����ļ���������ϵͳ�����ĵ�ö�����ͣ��벻Ҫ�����������ά������ *
****************************************************************************/

//���enum��ģ��֮��ͨ��ʹ��ʹ��
enum ENUM_NOTIFY_CMD {
	CMD_NONE = 0, 
	SLASH_CMD = 1, 
	ADD_USER_CMD, 
	DEL_USER_CMD, 
	ADD_SPIRIT_CMD, 
	DEL_SPIRIT_CMD,
	DISPATCH_CMD,
};

enum ENUM_STONE { ENUM_STONE0, ENUM_STONE1, ENUM_STONE2, };
enum UPDATE_BOOL	      { UPDATE_FALSE=false,			UPDATE_TRUE=true };
enum DELRECORD_BOOL	      { DELRECORD_FALSE=false,		DELRECORD_TRUE=true };
enum INCLUDE_BOOL	      { EXCLUDE_SELF=false,			INCLUDE_SELF=true };
enum SYNCHRO_ENUM	      { SYNCHRO_FALSE=false,		SYNCHRO_TRUE=true,  SYNCHRO_BROADCAST, SYNCHRO_TEAM_BROADCAST = 4, SYNCHRO_TEAM_AND_SCREEN_BROADCAST = 6};
enum AWARDDEED_BOOL       { AWARDDEED_FALSE=false,		AWARDDEED_TRUE=true };
enum CHANGESHAPE_BOOL     { CHANGESHAPE_FALSE=false,	CHANGESHAPE_TRUE=true };
enum COMBINE_ENUM         { COMBINE_NONE, COMBINE_FIT,	COMBINE_OVERFLOW};
enum PAY_ENUM             { PAY_MONEY, PAY_RMB, PAY_EMONEY3};
enum BUY_ENUM             { BUY_NONE, BUY_NPCSHOP, BUY_BOOTH, BUY_TRADE, BUY_VIP_SHOP, BUY_VIP_STORE, BUY_VIP_SHOP_AND_USE, BUY_VIP_STORAGE, BUY_VIP_NIMBUS};
enum FORBID_WALLOW_STATUS {FORBID_WALLOW_STATUS_NULL = 0, FORBID_WALLOW_STATUS_FULL_EXP, FORBID_WALLOW_STATUS_HALF_EXP, FORBID_WALLOW_STATUS_ZERO_EXP};
enum					  { HIT_BY_MAGIC, HIT_BY_WEAPON, HIT_BY_ITEM };
enum DATA_IDX			  { DATAIDX_0 = 0, DATAIDX_1, DATAIDX_2, DATAIDX_3,	DATAIDX_4, DATAIDX_5, DATAIDX_6, DATAIDX_7,	DATAIDX_ALL };

// Domain��������
enum DOMAIN_TYPE
{
// 	DOMAINTYPE_NORMAL_REGION	= 100011,
// 	DOMAINTYPE_NORMAL_MAP	= 100010,
// 	DOMAINTYPE_DAYTIME	= 100000,
	DOMAINTYPE_MAP		= 1,
	DOMAINTYPE_REGION	= 2,
	DOMAINTYPE_MAP_SYN_ADD_DAMAGE					= 3,
	DOMAINTYPE_FIELD_SYN_ADD_DAMAGE					= 4,
	DOMAINTYPE_NO_ENERGY_INCREASE					= 5,

};
// GenaKoo ����
enum GENAKOO_POS
{
	// ��ó��� Spirit
	GENAKOO_OUT = 1 << 1,
	// ��������ȷ�Ӫλ�õ� Spirit
	GENAKOO_VAN = 1 << 2,
	// ������Һ�Ӫλ�õ� Spirit
	GENAKOO_REST = 1 << 3,
	// �����������λ�õ� Spirit
	GENAKOO_LIMIT = 1 << 4,

	// ���³���������������
	GENAKOO_DUN = 1 << 5,
	// �ٻ����ĵ��³������һ���������
	GENAKOO_DUNFREE = 1 << 6,

	// ����λ�õ� Spirit
	GENAKOO_ALL = GENAKOO_OUT | GENAKOO_VAN | GENAKOO_REST | GENAKOO_LIMIT | GENAKOO_DUN | GENAKOO_DUNFREE,
};

enum DBLOAD_USERDATA_EM 
{
	DBLOAD_USER_BASEINFO,
	DBLOAD_USER_EXTENDINFO,
	DBLOAD_ROBOT_FLOATCANNON_STANDBY,
	DBLOAD_JOB_SCORE,
	DBLOAD_MESSAGE_INFO,
	DBLOAD_GENA_INFO,
	DBLOAD_STATISTIC_INFO,
	DBLOAD_STATUS_INFO,
	DBLOAD_ITEMEX_ROBOT,
	DBLOAD_ITEM_ROBOT,
	DBLOAD_BONUS_INFO,
	DBLOAD_FRIEND_INFO,
	DBLOAD_FRIENDED_INFO,
	DBLOAD_ENEMY_INFO,
	DBLOAD_LEAVEWORD_INFO,
	DBLOAD_WEAPON_SKILL,
	DBLOAD_MAGIC_INFO,
	DBLOAD_MAGIC_SKILL,
	DBLOAD_AMMO_SKILL,
	DBLOAD_SYNATTR_INFO,
	DBLOAD_FAMIATTR_INFO,
	DBLOAD_CONTRACT_INFO,
	DBLOAD_RESEARCH_INFO,
	DBLOAD_TUTOR_FARTHER_LEVEL,
	DBLOAD_TUTOR_GRANDFARTHER_LEVEL,
	DBLOAD_TUTOR_MY_DATA,
	DBLOAD_TUTOR_MY_CONTRIBUTIONS,
	//��Ϊͽ��Ĺ���
	DBLOAD_TUTOR_MY_CONTRIBUTIONS_SUBSTUDENT,
	DBLOAD_TUTOR_FATHER_DATA,
	DBLOAD_TUTOR_ACCESS,
	DBLOAD_TUTOR_STUDENT_DATA,
	DBLOAD_TUTOR_STUDENT_CONTRIBUTIONS,
	//ͽ����Ϊͽ��Ĺ���
	DBLOAD_TUTOR_STUDENT_CONTRIBUTIONS_SUBSTUDENT,
	//ʦ��
	DBLOAD_TUTOR_CLASSMATE_DATA,
	DBLOAD_TUTOR_CLASSMATE_CONTRIBUTIONS,
	//ʦ����Ϊͽ��Ĺ���
	DBLOAD_TUTOR_CLASSMATE_CONTRIBUTIONS_SUBSTUDENT,
	//ͽ��
	DBLOAD_TUTOR_SUBSTUDENT_DATA_BEGIN,
	DBLOAD_TUTOR_SUBSTUDENT_DATA_END = DBLOAD_TUTOR_SUBSTUDENT_DATA_BEGIN + 20,

	DBLOAD_TUTOR_SUBSTUDENT_CONTRIBUTIONS_BEGIN,
	DBLOAD_TUTOR_SUBSTUDENT_CONTRIBUTIONS_END = DBLOAD_TUTOR_SUBSTUDENT_CONTRIBUTIONS_BEGIN + 20,
	//ͽ����Ϊͽ��Ĺ���
	DBLOAD_TUTOR_SUBSTUDENT_CONTRIBUTIONS_SUBSTUDENT,


	DBLOAD_TUTOR_MY_TUTORANNOUNCE,
	DBLOAD_QUEST_OF_MINE,
	//�ֵ�ϵͳ
	DBLOAD_BROTHER_ATTR,
	DBLOAD_BROTHER_TEAM,
	DBLOAD_BROTHER_TEAM_ATTR,
	DBLOAD_BROTHER_ENEMY,
	DBLOAD_SHIP_RECORD_BOOK,
	
	DBLOAD_BOOTH_FLAG_BY_PERSON,
	DBLOAD_BOOTH_FLAG_BY_SYN,
	DBLOAD_BOOTH_INCOME_BY_PERSON,
	DBLOAD_BOOTH_INCOME_BY_SYN,
	
	DBLOAD_LIFESKILL_INFO,
	
	DBLOAD_ITEMEX_SALEAPPLY,
	DBLOAD_ITEM_SALEAPPLY,
	DBLOAD_ITEM_BONDCLEARWAIT,

	DBLOAD_ROBOT_STATISTIC_INFO,
	DBLOAD_CANNON_STATISTIC_INFO_BEGIN	= 700,
	DBLOAD_CANNON_STATISTIC_INFO_END	= 799,
	DBLOAD_GENAKOO_STATISTIC_INFO_BEGIN = 800,
	DBLOAD_GENAKOO_STATISTIC_INFO_END   = 900,
	
	DBLOAD_BUSSINESS_INFO =	901,
	DBLOAD_DUN							=902,
	// ���ݵ��³� ID ���ؽ�������
	DBLOAD_DUN_CONSTRUCTION_MATERIAL_BY_DUN	= 906,
	DBLOAD_GENaKoo_ITEMEXBEGIN=1000,
	DBLOAD_GENaKoo_ITEMEXEND=1500,
	DBLOAD_GENaKoo_ITEMBEGIN=1501,
	DBLOAD_GENaKoo_ITEMEND=2000,

	DBLOAD_FLOATCANNON1_ITEMEXBEGIN=2001,
	DBLOAD_FLOATCANNON1_ITEMEXEND=2500,
	DBLOAD_FLOATCANNON1_ITEMBEGIN=2501,
	DBLOAD_FLOATCANNON1_ITEMEND=3000,

	DBLOAD_FLOATCANNON2_ITEMEXBEGIN=3001,
	DBLOAD_FLOATCANNON2_ITEMEXEND=3500,
	DBLOAD_FLOATCANNON2_ITEMBEGIN=3501,
	DBLOAD_FLOATCANNON2_ITEMEND=4000,
	
	DBLOAD_FLOATCANNON_MAGIC_INFO_BEGIN=4001,
	DBLOAD_FLOATCANNON_MAGIC_INFO_END=4100,
	DBLOAD_FLOATCANNON_MAGIC_SKILL_BEGIN=4101,
	DBLOAD_FLOATCANNON_MAGIC_SKILL_END=4200,

	DBLOAD_AUCTION_ITEM					=4210,
	DBLOAD_AUCTION_ITEMEX				=4211,
	
	DBLOAD_DIG_BEGIN					=4212,
	DBLOAD_DIG_END						=4250,

	DBLOAD_DUN_CONSTRUCT_BEGIN			=4251,
	DBLOAD_DUN_CONSTRUCT_END			=4289,

	DBLOAD_DUN_CONSTRUCTION_MATERIAL_BY_DUN_BEGIN = 4290,
	DBLOAD_DUN_CONSTRUCTION_MATERIAL_BY_DUN_END	  = 4318,
	DBLOAD_USER_STATE = 4400,
	DBLOAD_ID_KILLED  = 4444,
};

enum
{
	WAYLAY_ACT_USE,      // ʹ�������
	WAYLAY_ACT_CANCEL,   // ȡ�������
	WAYLAY_ACT_FLYOUT,	 // ��������
};


//�����ļ���ö������
enum CFGDATA
{
	CFGDATA_ID,
	CFGDATA_NAME,
	CFGDATA_DATA,
	CFGDATA_DESC,
};


//��ͼ��ö������
enum MAPDATA
{
    MAPDATA_ID		= 0,
    MAPDATA_NAME,
    MAPDATA_DESCRIBE,
    MAPDATA_MAPDOC,
    MAPDATA_TYPE,
    MAPDATA_OWNER_ID,
	MAPDATA_MAPGROUP,
    MAPDATA_IDSERVER,
    MAPDATA_WEATHER,
    MAPDATA_BGMUSIC,
    MAPDATA_BGMUDIC_SHOW,
    MAPDATA_PORTAL0_X,
    MAPDATA_PORTAL0_Y,
    MAPDATA_REBORN_MAP,
    MAPDATA_REBORN_PORTAL,
	MAPDATA_RES_LEV,
    MAPDATA_OWNER_TYPE,
    MAPDATA_LINK_MAP_ID,
    MAPDATA_LINK_MAP_X,
    MAPDATA_LINK_MAP_Y,
    MAPDATA_DEL_FLAG,
	MAPDATA_MAXLV_REQ,			//�����ͼ�����ȼ�����
	MAPDATA_MINLV_REQ,			//�����ͼ����С�ȼ�����
	MAPDATA_ROOM1,				//�̶������mapid
	MAPDATA_ROOM2,
	MAPDATA_ROOM3,
	MAPDATA_ROOM4,
	MAPDATA_ROOM5,
	MAPDATA_ROOM6,
	MAPDATA_PROVINCE_ID,		
	MAPDATA_GENNO,             //��������ͼ����
};

enum PORTALDATA
{
	PROTALDATA_ID		= 0,
	PROTALDATA_MAPID,
	PROTALDATA_PORTAL_IDX,
	PROTALDATA_PORTAL_X,
	PROTALDATA_PORTAL_Y
};

enum PASSWAYDATA
{
	PASSWAYDATA_ID		= 0,
	PASSWAYDATA_MAPID,
	PASSWAYDATA_IDX,
	PASSWAYDATA_PASSWAY_MAPID,
	PASSWAYDATA_MAPPORTAL
};

//��ͼ��������
enum REGIONDATA
{
	REGIONDATA_ID		= 0,
	REGIONDATA_MAPID,
	REGIONDATA_TYPE,				
	REGIONDATA_BOUND_X,
	REGIONDATA_BOUND_Y,
	REGIONDATA_BOUND_CX,
	REGIONDATA_BOUND_CY,
	REGIONDATA_DATASTR,
	REGIONDATA_DATA0,
	REGIONDATA_DATA1,
	REGIONDATA_DATA2,
	REGIONDATA_DATA3,
	REGIONDATA_GENNO,
};

//����������
const OBJID DOMAINMAGICTYPE_NOMAL_MAP	= 100010;	//ͨ�����������ڲ���
const OBJID DOMAINMAGICTYPE_NOMAL_DOMAIN	= 100011;	//ͨ�����������ڲ���
const OBJID DOMAINMAGICTYPE_NOMAL_CONTROL	= 100012;	//ͨ�����������ڲ���
const OBJID DOMAINMAGICTYPE_DAYTIME1 = 100000;	//һ����������
const OBJID DOMAINMAGICTYPE_DAYTIME2 = 100001;	//������������
const OBJID DOMAINMAGICTYPE_DAYTIME3 = 100002;	//������������
const OBJID DOMAINMAGICTYPE_DAMAGE_DEC = 900100;//ȫ��ͼ�������˺�����Ч��������,��ʱ����

const OBJID DOMAIN_FIELD_SYN_ADD_DAMAGE1 = 123400; //��ΧȫԱ�˺���������
const OBJID DOMAIN_FIELD_SYN_ADD_DAMAGE2 = 123401;
const OBJID DOMAIN_FIELD_SYN_ADD_DAMAGE3 = 123402;
const OBJID DOMAIN_FIELD_SYN_ADD_DAMAGE4 = 123403;
const OBJID DOMAIN_FIELD_SYN_ADD_DAMAGE5 = 123404;

//��ͼ������ص�ö�ٶ���
enum TRAPTYPEDATA
{
	TRAPTYPEDATA_ID = 0,
	TRAPTYPEDATA_SOTR,
	TRAPTYPEDATA_LOOK,
	TRAPTYPEDATA_ACTION_ID,
	TRAPTYPEDATA_LEVEL,
	TRAPTYPEDATA_DEXTERITY,
	TRAPTYPEDATA_ATTACK_SPEED,
	TRAPTYPEDATA_ACTIVE_TIMES,
	TRAPTYPEDATA_MAGIC_TYPE,
	TRAPTYPEDATA_MAGIC_HITRATE,
	TRAPTYPEDATA_SIZE,
	TRAPTYPEDATA_ATK_MODE,
	TRAPTYPEDATA_ATKMAX,
	TRAPTYPEDATA_ATKMIN,
	TRAPTYPEDATA_ATKHOT,
	TRAPTYPEDATA_ATKSHAKE,
	TRAPTYPEDATA_ATKSTING,
	TRAPTYPEDATA_ATKDECAY,
	TRAPTYPEDATA_IMMUNITY,
	TRAPTYPEDATA_TRIGGER_RANGE,		
	TRAPTYPEDATA_DETONATE_RANGE,
	// TODO::MILO 11/9/2015 ������GS�и�BS��һ���Ķ��塣
	TRAPTYPEDATA_ACTION,
	TRAPTYPEDATA_SPEED,
	TRAPTYPEDATA_STAY_TIME,
	TRAPTYPEDATA_MAGICTYPE,
	TRAPTYPEDATA_CX,
	TRAPTYPEDATA_CY,
};

enum TRAPDATA
{
	TRAPDATA_ID_= 0,
	TRAPDATA_TYPE,
	TRAPDATA_LOOK,					
	TRAPDATA_OWNERID,
	TRAPDATA_MAPID,
	TRAPDATA_POS_X,
	TRAPDATA_POS_Y,
	TRAPDATA_DATA,
	TRAPDATA_POS_CX,
	TRAPDATA_POS_CY,
	TRAPDATA_GENNO,
	// TODO::MILO 11/9/2015
	TRAPDATA_DYNA_TYPE,     // ��̬�����飬0��ʾ���������ʱ������������ʾ��action����ʱ����
	TRAPDATA_CREATE_TIME,   // �������ʱ��
	TRAPDATA_STAY_TIME,     // �������ʱ��
	TRAPDATA_BASE_MAP,      // ��ͼ
};

enum TRAPRULEDATA
{
	TRAPRULEDATA_ID = 0,
	TRAPRULEDATA_TRAPRULL,
	TRAPRULEDATA_TRAPTYPE,
	TRAPRULEDATA_PERCENT,
	
};
enum TRAP_SORT
{
	TRAPSORT_SYSTRAP		= 1,					//ϵͳ�����壬�����Ч
	TRAPSORT_TRAPSORT_		= 10,					// ������ 
	TRAPSORT_FIREWALL		= 10,					// ��ǽ, ����ϵͳ����
	TRAPSORT_BURNWALLAMMO	= 11,					// ȼ�յ������ͷ��Ժ�Ļ�������   trap_sort=11
	TRAPSORT_MINE			= 12,					// ���ף�����
	TRAPSORT_MONSTERDIE		= 100,                  // ����������������
};

/////////////////////////////////////////////////////////////////////////////////////
// ����ʹ�õ�DATA���
enum {
		SYNFLAGNPC_FIGHTBEGIN1=0,SYNFLAGNPC_FIGHTEND1,SYNFLAGNPC_FIGHTBEGIN2,SYNFLAGNPC_FIGHTEND2,					// ���ɱ�־(time:WWHHMMSS, sun day = 7)
		GOALNPC_LEVEL=3,
		TIMERNPC_TIME=3,
		TRUNKNPC_SIZE=3,
		STORAGENPC_SIZE=3,
		NEIGHBORNPC_X=1,NEIGHBORNPC_Y=2,NEIGHBORNPC_SERIAL=3,
};			//? Ŀǰһ�����֧��4������


//NPC��ص�ö�ٶ���
enum NPCDATA
{
  NPCDATA_ID			= 0, 	
	NPCDATA_OWNER_ID,
	NPCDATA_OWNER_TYPE,
    NPCDATA_NAME,
    NPCDATA_TYPE,
    NPCDATA_LOOKFACE,		STATUARYDATA_DIR = NPCDATA_LOOKFACE,
    NPCDATA_IDSERVER,
    NPCDATA_MAPID,
    NPCDATA_CEXX,
    NPCDATA_CEXY,
    NPCDATA_TASK0,			STATUARYDATA_HELMET=NPCDATA_TASK0,
    NPCDATA_TASK1,			STATUARYDATA_ARMOR=NPCDATA_TASK1,
    NPCDATA_TASK2,			STATUARYDATA_WEAPONR=NPCDATA_TASK2,
    NPCDATA_TASK3,			STATUARYDATA_WEAPONL=NPCDATA_TASK3,
    NPCDATA_TASK4,			STATUARYDATA_FRAME=NPCDATA_TASK4,
    NPCDATA_TASK5,			STATUARYDATA_POSE=NPCDATA_TASK5,
    NPCDATA_TASK6,			STATUARYDATA_LOOKFACE = NPCDATA_TASK6,
    NPCDATA_TASK7,			STATUARYDATA_RANKSHOW_HAIR = NPCDATA_TASK7,
	NPCDATA_DATA0,
	NPCDATA_DATA1,
	NPCDATA_DATA2,
	NPCDATA_DATA3,
	NPCDATA_DATASTR,
	NPCDATA_LINKID,		
	NPCDATA_LIFE,
	NPCDATA_MAXLIFE,
	NPCDATA_BASE,
	NPCDATA_SORT,
	NPCDATA_ITEMTYPE,
	NPCDATA_DEFADJ,		
	NPCDATA_DEFSUB,
	NPCDATA_DEFHOT,
	NPCDATA_DEFSHAKE,
	NPCDATA_DEFSTING,
	NPCDATA_DEFLIGHT,
	NPCDATA_OWNER_NAME,				//��ҵ����
	NPCDATA_DEFAULT_OWNER_NAME,
	NPCDATA_INITIAL_PRICE,
	NPCDATA_PRICE,
	NPCDATA_DEPOSIT,
	NPCDATA_BUY_RATIO,
	NPCDATA_FEE_TYPE,
	NPCDATA_INCOME_VALUE,
	NPCDATA_PREFERENTIAL,
	NPCDATA_ANNEX,
	NPCDATA_ATTRIBUTE_TYPE,
	NPCDATA_USER_ATK_ADJUST,
	NPCDATA_USER_ATK_MODE,				
	NPCDATA_LEVEL,
	NPCDATA_CALC_DMG_TYPE,
	NPCDATA_HARVEST_DATE,
	NPCDATA_NUMBER,
	NPCDATA_GENNO,                 //������ͼ���� 
};

enum NPCTYPE
{
	_NPC_NONE				= 0,			// ͨ��NPC
	_SHOPKEEPER_NPC			= 1,			// �̵�NPC
	_TASK_NPC				= 2,			// ����NPC(�����ϣ������ڼ��ݾ�����)
	_STORAGE_NPC			= 3,			// �Ĵ洦NPC
	_TRUNCK_NPC				= 4,			// ����NPC
	_FACE_NPC				= 5,			// ��ͷ��NPC
	_FORGE_NPC				= 6,			// ����NPC		(only use for client)
	_EMBED_NPC				= 7,			// ��ǶNPC
	_COMPOSE_NPC			= 8,			// Ǭ������¯NPC
	_STATUARY_NPC			= 9,			// ����NPC
	_SYNFLAG_NPC_B			= 10,			// ���ɱ��NPC
	_ROLE_PLAYER			= 11,			// �������		(only use for client)
	_ROLE_HERO				= 12,			// �Լ�			(only use for client)
	_ROLE_MONSTER			= 13,			// ����			(only use for client)
	_BOOTH_NPC				= 14,			// ��̯NPC		(CBooth class)
	_SYNTRANS_NPC			= 15,			// ���ɴ���NPC, �̶��Ǹ���Ҫ�ô�����! (����00:00�շ�)(LINKIDΪ�̶�NPC��ID��������ʹ��LINKID�Ļ���)
	_ROLE_BOOTH_FLAG_NPC	= 16,			// ̯λ��־NPC	(only use for client)
	_ROLE_MOUSE_NPC			= 17,			// ����ϵ�NPC	(only use for client)
	_ROLE_MAGICITEM			= 18,			// �����ǽ		(only use for client)
	_ROLE_DICE_NPC			= 19,			// ����NPC
	_ROLE_SHELF_NPC			= 20,			// ��Ʒ��
	_WEAPONGOAL_NPC			= 21,			// ���̱��NPC
	_AMMOGOAL_NPC			= 22,			// Զ�̱��NPC
	_BOWGOAL_NPC			= 23,			// ��������NPC
	_ROLE_TARGET_NPC		= 24,			// ���򣬲���������	(only use for client)
	_ROLE_FURNITURE_NPC		= 25,			// �Ҿ�NPC	(only use for client)
	_ROLE_CITY_GATE_NPC		= 26,			// ����NPC	(only use for client)
	_ROLE_NEIGHBOR_DOOR		= 27,			// �ھӵ���
	_ROLE_CALL_PET			= 28,			// �ٻ���	(only use for client)
	_ROLE_TELEPORT			= 29,			// ����NPC			
	_ROLE_AMMOBIND_NPC		= 30,			// ��ҩ��NPC	
	_ROLE_SKILLBIND_NPC		= 31,			// ���ܰ�NPC
	_ROLE_EVOLVE_NPC		= 32,			// ����NPC
	_ROLE_ALLOTPNT_NPC		= 33,			// ��������NPC
	_ROLE_PKSETTING_NPC		= 34,			// PK����NPC
	_ROLE_CHATROOM_NPC		= 35,			// ������NPC
	_ROLE_EQUIP_NPC			= 36,			// װ��NPC
	_SHIP_NPC				= 37,			// �ɴ�NPC		
	_BOOTH_BUSINESS_FLAG_NPC= 38,			// ��ҵ̯λ̯λ��־NPC
	_BOOTH_BUSINESS_NPC		= 39,			// ��ҵ̯λNPC
	_SYNFLAG_NPC_A			= 40,			// ���ɱ��NPC_A
	_SYNFLAG_NPC_C			= 41,			// ���ɱ��NPC_C
	_FAMILY_NPC_WARLETTER	= 42,			// ��ͥռ��NPC
	_MISSION_PRIVATE_TENT	= 43,			// ��������˽������
	_MISSION_PUBLIC_TENT	= 44,			// �������񣺹�������
	_DETAIN_EQUIP_NPC       = 45,           // ��Ѻװ��NPC

	//������NPC���� ����Ѫ��09-12-23��
	_NPC_EXERCISE_MAGIC_INITIATIVE	= 45,	//������Ĺ�������ѵ��
	_NPC_EXERCISE_MAGIC_AUXILIARY	= 46,	//������ĸ�������ѵ��
	_NPC_EXERCISE_MAGIC_PASSIVE		= 47,	//��������ѵ��
	_NPC_EXERCISE_WEAPON_CLOSE		= 48,	//��ս����ѵ��
	_NPC_EXERCISE_WEAPON_DISTANT	= 49,	//Զս����ѵ��

	_ALTAR_NPC				= 55,			//��̳NPC
	_NPC_LAMPS_SWITCH		= 56,			//�ƾ߿���NPC
	_AI_NPC					= 57,			//����NPC
	_ROLE_3DFURNITURE_NPC	= 101,			// 3D�Ҿ�NPC 

	_MOVE_NPC				= 160,			//�ƶ�NPC
};

enum NEW_STATE  // ˳���޹�!!!������ֵ �ж�  ��Ҫ������  ������Ҫ���!!!
{
	STATE_START					= 0,	// ��ʼ,��ʹ��ʹ��, ע��:һ������ID�������� 
	STATE_INTERATTACK			= 1,	//  =0x0000000000000001;
	STATE_DIE					= 2,	//  =0x0000000000000002;
	STATE_TEAMLEADER			= 3,	//  =0x0000000000000004;
	STATE_GHOST					= 4,	//  =0x0000000000000008;
	STATE_DISAPPEARING			= 5,	//	=0x0000000000000010;
	STATE_RED					= 6,	//	=0x0000000000000020;	//PK����
	STATE_WING					= 7,	//	=0x0000000000000040;
	STATE_STARWAR_LEADER		= 8,	//	=0x0000000000000080;
	STATE_STOPALL				= 9,	//	=0x0000000000000100;	
// 	STATE_ATTACKCD				= 10,	//	=0x0000000000000200;	// ��
// 	STATE_ATTACK				= 11,	//	=0x0000000000000400;	// ��
// 	STATE_DEFENCE				= 12,	//	=0x0000000000000800;	// ��
// 	STATE_MOVESLOWLY			= 13,	//	=0x0000000000001000;	// ��
// 	STATE_STOPFIGHT				= 14,	//	=0x0000000000002000;	// ��
// 	STATE_STOPMOVE				= 15,	//	=0x0000000000004000;	// ͣ
// 	STATE_UNDERWRAPS			= 16,	//	=0x0000000000008000;	// ��
// 	STATE_SHIELD				= 17,	//	=0x0000000000010000;	// ������Ч�� ״̬
// 	STATE_GUARDIANSHIP			= 18,	//	=0x0000000000020000;	// �ػ� ״̬
	STATE_SUCKBLOOD_EXPIATE_EXP_UP	=19,	//	=0x0000000000040000;	//��Ѫ����ϴ���꾭������״̬
	STATE_INVINCIBLE			= 20,	//	=0x0000000000080000;	// �޵�״̬
//	STATE_FETCH_BURST			= 21,	//	=0x0000000000100000;	// �걬״̬
	STATE_MONSTER_BE_STEAL_LIFE	= 22,	//	=0x0000000000200000;	// �����Ѿ���Ѫ�巨ʦ�ɹ�͵ȡ����״̬
	STATE_SUCKBLOOD_EXPIATE		= 23,	//	=0x0000000000400000;	 
	STATE_TEAMROLE_ATTACKER		= 24,	//	=0x0000000000800000;	// �����ɫ������TEAM_ROLEPLAYING_ATTACKER
	STATE_TEAMROLE_TANK			= 25,	//	=0x0000000001000000;	// �����ɫ������TEAM_ROLEPLAYING_TANK
	STATE_TEAMROLE_HELAER		= 26,	//	=0x0000000002000000;	// �����ɫ������TEAM_ROLEPLAYING_HEALER
	STATE_TEAMROLE_INSPIRER		= 27,	//	=0x0000000004000000;	// �����ɫ������TEAM_ROLEPLAYING_INSPIRER
//	STATE_INSPIRER_ADDMONEY		= 28,	//	=0x0000000008000000;
//	STATE_INSPIRER_ADDDAMAG		= 29,	//	=0x0000000010000000;
//	STATE_INSPIRER_DECATTACK	= 30,	//	=0x0000000020000000;
//	STATE_INSPIRER_ADDEXP		= 31,	//	=0x0000000040000000;	
	STATE_VAMPIRE_UNDER_SUNSHINE= 32,   //  =0x0000000080000000;	// ��Ѫ��̫��ɹ��״̬
	STATE_ANGEL					= 33,  	//	=0x0000000100000000;	//��ʹ״̬
	STATE_BUSY_LevupInterface	= 34,	//	=0x0000000200000000;	// �����������棨ȫ�����棩æµ״̬
	STATE_POWERCRAZYFIGHTER		= 35,	//	=0x0000000400000000;	// ���սʿ״̬
	STATE_MOUNT					= 36,	//  =0x0000000800000000;	// �����е�״̬
//	STATE_FLAMETHROWER			= 37,	//	=0x0000001000000000;	//������������������״̬
	STATE_XPFULL				= 38,	//	=0X0000002000000000;	// xp full status.
	STATE_PURPLE				= 39,	//	=0x0000004000000000;	// ������״̬
	STATE_WATCH_STARWAR			= 40,	//	=0x0000008000000000;	// ��ս״̬
	STATE_DEEPRED				= 41,	//	=0X0000010000000000;    //����  //����ͨ���졢��������ʵ�� 
	STATE_PRACTISE				= 43,	//	=0X0000040000000000;	//��������״̬
	STATE_VAMPIRE_UNDER_SAINT_LIGHT = 44,//	=0X0000080000000000;	// ��Ѫ��ʥ������״̬		//ѹ��״̬
//	STATE_DODGE					= 45,	//	=0X0000100000000000;	//������״̬
	STATE_SELFPROTECT			= 46,	//	=0x0000200000000000;    //�Զ�����״̬
//	STATE_LOCKATTACK			= 47,	//	=0x0000400000000000;    //��������״̬
	STATE_GODBLESS				= 48,	//	=0x0000800000000000;    //���͹�����״̬
//	STATE_TRANSLOOK				= 49,	//	=0x0001000000000000;    //����һ��״̬
	STATE_FLYMAP				= 50,	//	=0x0002000000000000;    //������ʱ״̬�������Ϳͻ��˶������
//	STATE_BAITMONSTER			= 51,	//	=0x0004000000000000;	// ���˶���״̬
	STATE_UPMODELLEV_USEITEM	= 52,	//	=0x0008000000000000;	//ʹ����Ʒ�����Ǽ�����
	STATE_DIVE					= 53,	//  =0x0010000000000000;	//Ǳˮ
	STATE_PK_CHAMPION1			= 54,	//	=0x0020000000000000;	//pk�� �����ھ�״̬ 
	STATE_PK_CANDICATE1			= 55,	//  =0x0040000000000000;	//pk�� ������Χ״̬ 
	STATE_PK_CHAMPION2			= 56,	//	=0x0080000000000000;	//pk�� �߼��ھ�״̬ 
	STATE_PK_CANDICATE2			= 57,	//	=0x0100000000000000;	//pk�� �߼���Χ״̬ 
	STATE_PK_CHAMPION3			= 58,	//	=0x0200000000000000;	//pk�� �м��ھ�״̬ 
	STATE_PK_CANDICATE3			= 59,	//	=0x0400000000000000;	//pk�� �м���Χ״̬ 
	STATE_WAYLAY				= 60,	//	=0x0800000000000000;	//��ҷ��� vampire 
	STATE_CONK					= 61,	//	=0x1000000000000000;	//�� majl
//	STATE_TRUMP_SELFBLAST_DECBATTLEEFFECT = 62,//=0x2000000000000000;	//����-�Ա�������ս��������
	STATE_CHAOS					= 63,	//  =0x4000000000000000;	//����
	STATE_FIRST_NIMBUS			= 64,	//	=0X8000000000000000;	// ��һ���������а�״̬

// ��չ״̬����   �ڶ���64λ
	STATE_SKILL_SHOTGUNSPEEDYCHANGEBULLET = 95, //= 0x0000000040000000;//������ɢ��ǹ״̬

// 128λ���µĲ��ܴ�������Ϣ 
	

// 128Ϊ���ϵĿ���ѡ���Դ����ݵ��ͻ���      //        ע��: ��Ҫ���ͻ���ͬ���ľ����ͽ�����ֵд��  ������Լ��ڲ�ʹ�õ�ֻ����ö�پͿ����� 
	STATE_START1				= 129,	  
	STATE_GODTRANSPORT			= 130,		// ���ɴ���״̬
	STATE_TEAM_SIGNROLE			= 131,		// ���ӳ����״̬
	STATE_TEAMSTATUS_EXP_MEDICINE=132,
	STATE_USER_IN_BOOTH			 =133, 

	STATE_SKILL_BLEEDING		= 135,	// �µļ�����Ѫ״̬
	STATE_SKILL_BURNING			= 136,  // �µļ�������״̬
    STATE_CRIME                 = 137,  // ����״̬
// 	STATE_FLOWER				= 137,	// �յ���õ������
// 	STATE_WHITEFLOWER			= 138,	// �յ���õ������
	STATE_MAGE_STEAL_LIFE		= 139,	// Ѫ�巨ʦ͵ȡ������������״̬
	STATE_SKILL_FREEZING		= 141,	// �µļ��ܱ���״̬
	STATE_SKILL_MOVESPEEDREDUCE	= 142,	// �ƶ��ٶȽ���״̬-- ��Ѫ�������
	STATE_SKILL_SAN_SHIELD		= 143,	// ����״̬ ��ʥ�ܻ�
	STATE_SKILL_DIZZY			= 144,	// �¼��ܵ�ѣ��״̬ ��ʥ�ܻ�
	STATE_SKILL_JUSTICE			= 145,	// ����״̬  ��ʥ�������
	STATE_SKILL_BLOODSHADOWSTEP = 146,	// ѪӰ��״̬
	STATE_SKILL_WITHBOMB		= 147,  // �µļ���ը������״̬
	STATE_SKILL_MOVEDISABLE		= 148,	// ���ٹ�����ֹ�ƶ�״̬
	STATE_SKILL_QUICK_SHOT		= 149,	// �������
	STATE_EQUIP_AMMO		    = 150,	// װ��״̬
	STATE_CURSE                 = 151,  // ����״̬
	STATE_SKILL_LIGHTNING_SHAKE	= 152,  //�µļ��ܵ��״̬
	STATE_WERWOLF_VARIATION1    = 153,  // ���˱��� һ��
	STATE_WERWOLF_VARIATION2    = 154,  // ���˱��� ����
	STATE_SKILL_ADD_LIFE        = 155,
	STATE_INSPIRER_ADDMONEY		= 156,	// ���������ӽ�һ�ȡ
	STATE_INSPIRER_ADDDAMAG		= 157,	// �����������˺�Ч��
	STATE_INSPIRER_DECATTACK	= 158,	// �����߽��͹���Ч��
	STATE_INSPIRER_ADDEXP		= 159,	// ���������Ӿ����ȡ
	STATE_GEM_CAN_EXCHANGE_EXP,				//���ǻ�����
	STATE_VAMPIRE_UNDER_DOMAIN_LIGHT = 161,// ��Ѫ��������������״̬
	STATE_ATTACKCD	                 = 162, //���ڿ��ƹ����ļ����״̬----��ʬ
	STATE_LIFT_ITEM					 = 163,
	STATE_ACT_EMOTION		,				// 2007.03.05 �������鱣��
	
	STATE_ATKRANGE,
	STATE_ATTACK_LOCK,
	STATE_CARRY_WOOD			, // ����״̬
//	STATE_VAMPIRE_UNDER_DOMAIN_LIGHT = 161,// ��Ѫ��������������״̬
	STATE_ATKSPEED,    
	STATE_USER_CANNOT_CONJURE_DEVIL,
	STATE_USER_HP_AUTO_RESUME,
	STATE_USER_MP_AUTO_RESUME,

	STATE_RECOVERY,
	STATE_PKBEATBACK,
	STATE_ADD_BATTLEEFFECT,
	STATE_TRUMP_WHOLEMAP_ADD_EXP,				 //����-ȫ��ͼȫԱ����ֵ���
	STATE_TRUMP_WHOLEMAP_SYNDIACTE_ADD_EXP,		 //����-ȫ��ͼ���Ӿ���ֵ���
	STATE_TRUMP_WHOLEMAP_TEAM_ADD_EXP,			 //����-ȫ��ͼ���龭��ֵ���
	STATE_TRUMP_WHOLEMAP_FAMILY_ADD_EXP,		 //����-ȫ��ͼ���徭��ֵ���
	STATE_TRUMP_REGION_FORBID_JUMP,
	STATE_TRUMP_REGION_BATTLEEFFECT,			 //����-ս����������		
	STATE_TRUMP_REGION_DAMAGE,					 //����������ΧȫԱ�˺����		
	STATE_TRUMP_REGION_BE_DAMAGE,				 //����������ΧȫԱ���˺����		
	STATE_TRUMP_REGION_TYPE_REGION_ADD_HP,		 //����������ΧȫԱHP���    
	STATE_TRUMP_REGION_FORBID_RESTORE_HP,		 //����ΧȫԱHP�ظ�
	 STATE_TRUMP_REGION_FORBID_TRANS_POS,
 
	STATE_TRUMP_REGION_ADD_DEAD_TIME,
	STATE_TRUMP_WHOLEMAP_BATTLEEFFECT,			 //����-ȫ��ͼȫԱս�������
	STATE_TRUMP_WHOLEMAP_SYNDIACTE_BATTLEEFFECT,//����-ȫ��ͼ����ս�������
	STATE_TRUMP_WHOLEMAP_FAMILY_BATTLEEFFECT,	 //����-ȫ��ͼ����ս�������
	STATE_TRUMP_WHOLEMAP_TEAM_BATTLEEFFECT,		//����-ȫ��ͼ����ս�������		
	STATE_TRUMP_WHOLEMAP_HP,					 //����-ȫ��ͼȫԱHP���
	STATE_TRUMP_WHOLEMAP_SYNDIACTE_HP,			 //����-ȫ��ͼ����HP���
	STATE_TRUMP_WHOLEMAP_FAMILY_HP,				//����-ȫ��ͼ����HP���
	STATE_TRUMP_WHOLEMAP_TEAM_HP,				 //����-ȫ��ͼ����HP���
	STATE_TRUMP_WHOLEMAP_ADD_DAMAGE,			 //������ȫ��ͼȫԱ���˺����
	STATE_TRUMP_WHOLEMAP_SYNDIACTE_ADD_DAMAGE,	 //������ȫ��ͼ���Ӽ��˺����
	STATE_TRUMP_WHOLEMAP_TEAM_ADD_DAMAGE,		 //������ȫ��ͼ������˺����
	STATE_TRUMP_WHOLEMAP_FAMILY_ADD_DAMAGE,		//������ȫ��ͼ������˺����
	STATE_TRUMP_WHOLEMAP_DEC_DAMAGE,			 //������ȫ��ͼȫԱ���˺����
	STATE_TRUMP_WHOLEMAP_SYNDIACTE_DEC_DAMAGE,	 //������ȫ��ͼ���Ӽ��˺����
	STATE_TRUMP_WHOLEMAP_TEAM_DEC_DAMAGE,		 //������ȫ��ͼ������˺����
	STATE_TRUMP_WHOLEMAP_FAMILY_DEC_DAMAGE,		//������ȫ��ͼ������˺����
	STATE_TRUMP_REGION_RESTORE_XP_SPEED, 
	STATE_TRUMP_REGION_FORBID_RESTORE_EN,
	STATE_TRUMP_REGION_FORBID_RESTORE_POWER,
	STATE_TRUMP_REGION_FORBID_RESTORE_THRUSTER,
	STATE_TRUMP_REGION_FORBID_RESTORE_DEF,
	STATE_BECALL_BY_TEAMLEADER,
	STATE_BROTHER_BE_APPLIED_TRANSFER ,//�������ֵ�˲��
	STATE_BROTHER_TRANSFER	,		// �ֵ�˲��
	STATE_BETRAY_BROTHER,
	STATE_BROTHER_SWEAR,
	STATE_COACH_UNDERSTAND,				 //��ָ��������״̬
	STATE_COACH_USER,
	STATE_COACH_SYN,

	// һ��Ϊ������Լ�ʹ�õ�״̬ ����Ҫ֪ͨ�ͻ��˵�  ��ֵ����Ҫд��!
	STATE_USER_LOGOUT_TIMER_30_MIN, 
	STATE_SKILL_BLEEDING_IMMUNE,    // ������Լ�ʹ�õ����߶�Ӧ״̬
	STATE_SKILL_JUSTICE_IMMUNE,
	STATE_SKILL_LIGHTNING_SHAKE_IMMUNE,
	STATE_SKILL_BURNING_IMMUNE,
	STATE_SKILL_DIZZY_IMMUNE,
	STATE_NORMAL,
	STATE_EXERCISE_SKILLEXP_ONLINE,	//������ѵ�����ܡ�����������״̬����Ѫ��09-12-23��
	STATE_TODAYFLOWER_NUM_RED,		//�����ջ���������õ�壩
	STATE_TODAYFLOWER_NUM_WHITE,	//�����ջ���������õ�壩

	// ��ʬ��״̬
	STATE_CAP,						//��ץס
	STATE_CAPPOWER,					//��ץסǿ��״̬	
	STATE_CAPOVER,					//��ץס2���

	STATE_SUPPRESSED,               // ��ѹ��״̬

	STATE_SUPERARMOR = 229,      //����״̬
	STATE_SUPERARMOR_RESUME = 230,      //�������ָ���ʱ״̬
	STATE_SUPERARMOR_IMMUNE = 231,
	STATE_LAMPS_ON = 239,		//�ƾ߿�״̬
	STATE_ROLE_STAND = 240,      //��ֱ״̬
	STATE_DOTFLOOR_SPRING_ENTERBATTLE = 241,	//��Ϊ��ؽ����ս��״̬
	STATE_BATTLE_SPRING_ENTERBATTLE = 242,	//ս��״̬
	STATE_REGION_SPRING_ENTERBATTLE = 243,	//����ս�������ս��״̬
	STATE_LEADER_OFFLINE = 244,	//�ӳ�����״̬
	STATE_NPCMOVE = 245,  // NPC�ƶ�״̬
	STATE_NPCFORMOVE = 246,  // NPC��ֹ�ƶ�״̬
	STATE_USEROFFLINE = 247,  // 
	STATE_BURN = 250,      //ȼ��״̬
	//	STATE_ININSTANCE		     		    = 251,      //����״̬

	NEW_STATE_END,					// ����, ͬ����ʹ��
};

const UINT STATUS_UINT32_TOTAL_COUNT = /*4; //*/ (NEW_STATE_END-2)/32 +1;  // ����ʾ״̬: m_nStatusTotalCount*32 ��
const INT   TIME_ONCE_ONTIMER = 500;				//һ��ontimer��ʱ��
const INT	TIME_CAP = TIME_ONCE_ONTIMER / 250	;	//0.25�룬500�������� 500/250 ��
 
enum NPCSORT
{
	NPCSORT_NONE		= 0,
	NPCSORT_TASK		= 1,			// ������
	NPCSORT_RECYCLE		= 2,			// �ɻ�����
	NPCSORT_SCENE		= 4,			// ������(����ͼ���)
	NPCSORT_LINKMAP		= 8,			// �ҵ�ͼ��(LINKIDΪ��ͼID��������ʹ��LINKID�Ļ���)
	NPCSORT_DIEACTION	= 16,			// ����������(LINKIDΪACTION_ID��������ʹ��LINKID�Ļ���)
	NPCSORT_DELENABLE	= 32,			// �����ֶ�ɾ��(����ָͨ������)
	NPCSORT_EVENT		= 64,			// ����ʱ����, ʱ����data3�У���ʽΪDDWWHHMMSS��(LINKIDΪACTION_ID��������ʹ��LINKID�Ļ���)
	NPCSORT_TABLE		= 128,			// �����ݱ�����
	NPCSORT_SHOP		= 256,			// �̵���
	NPCSORT_VIPSHOP		= 512,			// VIP�̵���
		
	NPCSORT_USELINKID	= NPCSORT_LINKMAP | NPCSORT_DIEACTION | NPCSORT_EVENT
};

enum NPC_PATH_DATA
{
	NPC_PATH_DATA_ID,
	NPC_PATH_DATA_NPCID,
	NPC_PATH_DATA_APPEAR_TIME,
	NPC_PATH_DATA_DISAPPEAR_TIME,
	NPC_PATH_DATA_ACTION_MOD,
	NPC_PATH_DATA_POS_NUM,
	NPC_PATH_DATA_MAPID,
	NPC_PATH_DATA_POSX,
	NPC_PATH_DATA_POSY,
	NPC_PATH_DATA_STAY_TIME,
	NPC_PATH_DATA_MOVE_SPEED,
	NPC_PATH_DATA_FUNCTION,
};

enum NPC_INCOME_DATA
{
	INCOMEDATA_ID,
	INCOMEDATA_NPCID,
	INCOMEDATA_OWNERID,
	INCOMEDATA_OWNERTYPE,
	INCOMEDATA_INCOMEEXP,
	INCOMEDATA_INCOMEMONEY,
};

enum NPC_INCOME_TYPE
{
	NPC_SYSTEM_INCOME = 0,
	NPC_PERSON_INCOME = 1, 
	NPC_SYN_INCOME    = 2, 
	NPC_FAMILY_INCOME = 3, 
};			

enum 
{ 
	NPC_OWNER_SYSTEM, 
	NPC_OWNER_PERSON, 
	NPC_OWNER_SYN, 
	NPC_OWNER_FAMILY, 
};

enum 
{ 
	PURCHASE_BY_PERSON, 
	PURCHASE_BY_SYN, 
};


enum USERDATA // ���� ��Ӧ user �� user_x ��  ˳�����,   // ���ݿ�һһ��Ӧ����VAMPIRE_USER_DB_DATA       
{
 	USERDATA_ID,
	USERDATA_NAME,
	USERDATA_MATE_NAME,//USERDATA_MATE,
	USERDATA_MATE_ID,
	USERDATA_LOOKFACE,
	USERDATA_HAIR,
	USERDATA_MONEY,
	USERDATA_MONEY_SAVED,
	USERDATA_WEAPON_SELECT,
	USERDATA_LEVEL,
	USERDATA_EXP,
	USERDATA_STORAGELEVEL,//USERDATA_STORAGE_LV,
	USERDATA_DEED,
	USERDATA_PK_MODE,//USERDATA_PK,
	USERDATA_MEDAL,
	USERDATA_STONE_LIMIT,//USERDATA_STORAGE_STONE_LIMIT,
	USERDATA_CREATETIME,
	USERDATA_RECORD_MAP,//USERDATA_RECORDMAP_ID,
	USERDATA_RECORD_X,//USERDATA_RECORDX,
	USERDATA_RECORD_Y,//USERDATA_RECORDY,
	USERDATA_ACCOUNT_ID,
	USERDATA_LAST_LOGIN,
	USERDATA_TASK_MASK,
	USERDATA_HOME_ID,
	USERDATA_TITLE,
	USERDATA_STORAGE_LIMIT,//USERDATA_STORAGE_WEIGHT_LIMIT,
	USERDATA_LOCK_KEY,
	USERDATA_REBORN_MAPID,
	USERDATA_NEWTYPE_LV,
	USERDATA_Coach,
	USERDATA_Coach_time,
	USERDATA_Coach_date,
	USERDATA_virtue,
	USERDATA_XP_BEAT,
	USERDATA_CAMP,
	USERDATA_PKENABLE,
	USERDATA_MILITARYRANK1,
	USERDATA_MILITARYRANK2,
	USERDATA_MILITARYRANK3,
	USERDATA_MILITARYRANK4,
	USERDATA_MARRYTIME,
	USERDATA_GENAKOO_INFO,	// SPIRITstorage_lev
	USERDATA_ACCUMULATE,	// accumulate
	USERDATA_EMONEY,
	USERDATA_EMONEY_CHK,
	USERDATA_SAVED2,
	USERDATA_EXPBALL,		// 2006.09.07 ����
	USERDATA_STATUS,		// 2006.09.07 ����	status
	USERDATA_STRATAGEM,		// 2006.09.07 ����	stratagem
	USERDATA_ONLINETIME,	// 2006.09.07 ����	online_time
	USERDATA_AUTOEXP,		// 2006.09.07 ����	auto_exercise
	USERDATA_FLOWER,		// 2006.09.07 ����	flower
	USERDATA_BAGNUM,
	USERDATA_FORBITDDENWORDS,	// 2007.01.12 GMץ���Ա�־
	USERDATA_CRYSTALPOINT,
	USERDATA_CRYSTALUSAGE0,
	USERDATA_CRYSTALUSAGE1,
	USERDATA_CRYSTALUSAGE2,
	USERDATA_CRYSTALUSAGE3,
	USERDATA_CRYSTALUSAGE4,
	USERDATA_PASSWORD_ID,
	USERDATA_LOCKTIME,
	USERDATA_CHK_SUM,
	USERDATA_FLOWER_W,			// 2007.03.27 ��õ�壬�����͵���ֵ��õ������
	USERDATA_TUTOR_LEVE,
	USERDATA_TUTOR_EXP,
	USERDATA_ONLINE_TIME2,
	USERDATA_OFFLINE_TIME,
	USERDATA_LAST_LOGIN2,
	USERDATA_LIST1,
	USERDATA_LIST2,
	USERDATA_PROFESSION,
	USERDATA_BROTHER_TEAM_ID,
	USERDATA_LIFE,
	USERDATA_MANA,
	USERDATA_EN,
	USERDATA_INCOME,
	USERDATA_DF,
	USERDATA_BUSINESS,
	USERDATA_DONATE,			//��λ�����ܶ�
	USERDATA_LOGIN_TIME,		//��¼ʱ��
	USERDATA_LOGIN_IP,			//��¼IP
	USERDATA_FRIEND_SHARE,
	USERDATA_EMONEY3,			//emoney3
	USERDATA_EMONEY3_CHK,
	USERDATA_QUIZ_POINT,
	USERDATA_BATTLE_LEV,
	USERDATA_FAMILY_RANK,
	USERDATA_IDFAMILY,
	USERDATA_PROFESSION_LEV,
	USERDATA_PROFESSION_EXP,
	USERDATA_ONLINE_EXP,
	USERDATA_EXT_MONSTOR_EXP,
	USERDATA_VAMPIRE_VAL,
	USERDATA_LIMIT,
	//�����ֶ�ʱ����user_x���, �����ڲ��Զ���������ֵ��ϵ
	USERDATA_EX_ID ,
	USERDATA_EX_NAME,
	USERDATA_EX_BIG_BADLUCK,
	USERDATA_EX_SMALL_BADLUCK,
	USERDATA_EX_LOTTERY_TIMES,
	USERDATA_EX_BIG_GOODLUCK,
	USERDATA_EX_SMALL_GOODLUCK,
	USERDATA_EX_LASTLOTTERY,
	USERDATA_EX_STONE0,
	USERDATA_EX_STONE1,
	USERDATA_EX_STION2,
	USERDATA_EX_CHK_SUM,
	USERDATA_EX_EXPBALLSPIRIT,
	USERDATA_EX_VIPSHOW,

	// ���ֶ�
	USERDATA_MAXLIFE,
	USERDATA_MAXXP,

	//no use
	USERDATA_BANK,
	USERDATA_TIME_OF_LIFE,		// NPC SERVER
	USERDATA_TASK_TIME,
	// ��ʱ����
	
	USERDATA_PKCOMPETE_SPIRITID,			// ����ID
	USERDATA_PKCOMPETE_BEGINEXP,		// 2007.02.07 ����pk��ʱ���徭��
	USERDATA_PKCOMPETE_BEGINLEV,		// 2007.02.07 ����PK��ʱ����ȼ�
	USERDATA_PKCOMPETE_BEGINUSERLEV,	// 2007.02.07 ����PK��ʱ��ҵȼ�

	USERDATA_PKCOMPETE_SPIRITID1,		// ������(1)ID
	USERDATA_PKCOMPETE_BEGINEXP1,		// 2007.02.07 ����pk��ʱ�����ھ���
	USERDATA_PKCOMPETE_BEGINLEV1,		// 2007.02.07 ����PK��ʱ�����ڵȼ�
	
	USERDATA_PKCOMPETE_SPIRITID2,		// ������(2)ID
	USERDATA_PKCOMPETE_BEGINEXP2,		// 2007.02.07 ����pk��ʱ�����ھ���
	USERDATA_PKCOMPETE_BEGINLEV2,		// 2007.02.07 ����PK��ʱ�����ڵȼ�		

	USERDATA_PKCOMPETE_KILL,
	USERDATA_PKCOMPETE_FIELD,			// 2007.02.07 ����PK���еĳ���
	USERDATA_ACTION_TARGET_ID,			// 2007.03.28 ����ֵ����
	USERDATA_ACTION_TARGETNAME,			// 2007.04.13 ֧��%target_name

	USERDATA_MOUNT,

// 	USERDATA_ACCURATEPOINT			= 501,//��ȷ����
// 	USERDATA_ATTF					= 502,//����
// 	USERDATA_DFVAULE				= 503,//����ֵ
// 	USERDATA_SMVALUE				= 504,//���� ����
// 	USERDATA_PWVALUE				= 505,//����
// 	USERDATA_STVALUE				= 506,//����
// 	USERATTRIB_ACCURATE				= 507,//��ȷֵ
// 	USER_FIELD_DEFENCEPOINT			= 514,//��������
// 	USER_FILED_SMARTPOINT			= 515,//���ݵ���
// 	USER_FILED_POWERPOINT			= 516,//��������
// 	USER_FILED_STRONGPOINT			= 517,//��������
// 	USER_FILED_LIFEPOINT			= 518,//��������
// 	USERDATA_FREEPOINT				= 519,//���ɵ���
// 	USERDATA__DEFENSEPOINT_TOADD	= 520,//�������������
// 	USERDATA__AGILITYPOINT_TOADD	= 521,//���������ݵ���
// 	USERDATA__STRENGTHPOINT_TOADD	= 522,//��������������
// 	USERDATA__SPPOINT_TOADD			= 523,//��������������
// 	USERDATA__HPPOINT_TOADD			= 524,//��������������
	USERDATA_DODGE = 501,        //���� ����
	USERDATA_SHORT_DEFENCE = 502,        //��ս������
	USERDATA_LONG_DEFENCE = 503,        //Զս��ǹ����������
	USERDATA_SHORT_MINATK = 507,        //��С��ս������
	USERDATA_SHORT_MAXATK = 508,        //����ս������
	USERDATA_LONG_MINATK = 509,        //��СԶս(ǹ��)������
	USERDATA_LONG_MAXATK = 510,        //���Զս(ǹ��)������

	USERDATA_DEFENCEPOINT = 514,        //���������
	USERDATA_DODGEPOINT = 515,        //���ݵ���
	USERDATA_POWERPOINT = 516,        //��������
	USERDATA_MANAPOINT = 517,        //��������
	USERDATA_LIFEPOINT = 518,        //��������
	USERDATA_FREEPOINT = 519,        //���ɵ���

	USERDATA_HEAD = 600,        // ���ͷ��ģ��ID
	USERDATA_CITY = 601,        // ������ڳ���
};

enum USERDATA_EX
{
	USERDATAEX_ID = 0,
	USERDATAEX_NAME,
	USERDATAEX_BIG_BADLUCK,
	USERDATAEX_SMALL_BADLUCK,
	USERDATAEX_LOTTERY_TIMES,
	USERDATAEX_STONE0,
	USERDATAEX_STONE1,
	USERDATAEX_STION2,
	USERDATAEX_CHK_SUM,
	USERDATAEX_EXPBALLSPIRIT,
	USERDATAEX_VIPSHOW,
};

enum VAMPIRE_USER_DB_DATA       // ��Ѫ�����ݿ��ֶ�ö��  ��������ݿ�һһ��Ӧ��
{
	VAMPIRE_DB_USER_FIELD_ID,                        // "user, id"                       �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_NAME,                      // "user, name"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MATE,                      // "user, mate"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MATE_ID,                   // "user, mate_id"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LOOKFACE,                  // "user, lookface"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_HAIR,                      // "user, hair"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MONEY,                     // "user, money"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MONEY_SAVED,               // "user, money_saved"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_WEAPON_SELECT,             // "user, weapon_select"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LEVEL,                     // "user, level"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FLATLEVEL,                 // "user, flatlevel"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_EXP,                       // "user, exp"                      �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FLAT_EXP,                  // "user, flatexp"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_STORAGE_LV,                // "user, storage_lv"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_DEED,                      // "user, deed"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_PK,                        // "user, pk"                       �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MEDAL,                     // "user, medal"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_STORAGE_STONE_LIMIT,       // "user, storage_stone_limit"      �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CREATETIME,                // "user, CreateTime"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_RECORDMAP_ID,              // "user, recordmap_id"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_RECORDX,                   // "user, recordx"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_RECORDY,                   // "user, recordy"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ACCOUNT_ID,                // "user, account_id"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LAST_LOGIN,                // "user, last_login"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_TASK_MASK,                 // "user, task_mask"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_HOME_ID,                   // "user, home_id"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_TITLE,                     // "user, title"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_STORAGE_WEIGHT_LIMIT,      // "user, storage_weight_limit"     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LOCK_KEY,                  // "user, lock_key"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_REBORN_MAPID,              // "user, reborn_mapid"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_NEWTYPE_LV,                // "user, newtype_lv"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_COACH,                     // "user, Coach"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_COACH_TIME,                // "user, Coach_time"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_COACH_DATE,                // "user, Coach_date"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_VIRTUE,                    // "user, virtue"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_XP_BEAT,                   // "user, xp_beat"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CAMP,                      // "user, camp"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_PKENABLE,                  // "user, pkenable"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MILITARYRANK1,             // "user, militaryrank1"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MILITARYRANK2,             // "user, militaryrank2"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MILITARYRANK3,             // "user, militaryrank3"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MILITARYRANK4,             // "user, militaryrank4"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MARRYTIME,                 // "user, marrytime"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ROBOTSTORAGE_LEV,          // "user, robotstorage_lev"         �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ACCUMULATE,                // "user, accumulate"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_EMONEY,                    // "user, Emoney"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_EMONEY_CHK,                // "user, Emoney_chk"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MONEY_SAVED2,              // "user, money_saved2"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_EXPBALLUSAGE,              // "user, ExpBallUsage"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_STATUS,                    // "user, status"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_STRATAGEM,                 // "user, stratagem"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ONLINE_TIME,               // "user, online_time"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_AUTO_EXERCISE,             // "user, auto_exercise"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FLOWER,                    // "user, flower"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_BAGNUM,                    // "user, BagNum"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FORBITDDEN_WORDS,          // "user, forbitdden_words"         �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CRYSTALPOINT,              // "user, CrystalPoint"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CRYSTALUSAGE0,             // "user, CrystalUsage0"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CRYSTALUSAGE1,             // "user, CrystalUsage1"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CRYSTALUSAGE2,             // "user, CrystalUsage2"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CRYSTALUSAGE3,             // "user, CrystalUsage3"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CRYSTALUSAGE4,             // "user, CrystalUsage4"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_PASSWORD_ID,               // "user, password_id"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LOCKTIME,                  // "user, locktime"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_CHK_SUM,                   // "user, chk_sum"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FLOWER_W,                  // "user, flower_w"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_TUTOR_LEVEL,               // "user, tutor_level"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_TUTOR_EXP,                 // "user, Tutor_exp"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ONLINE_TIME2,              // "user, online_time2"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_OFFINE_TIME,               // "user, offine_time"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LAST_LOGOUT2,              // "user, last_logout2"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LIST1,                     // "user, list1"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LIST2,                     // "user, list2"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_PROFESSION,                // "user, profession"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_BROTHER_TEAM_ID,           // "user, brother_team_id"          �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LIFE,                      // "user, life"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_MANA,                      // "user, mana"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ENERGY,                    // "user, energy"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_INCOME,                    // "user, Income"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_DF,                        // "user, Df"                       �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_BUSINESS,                  // "user, business"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_DONATION,                  // "user, donation"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_LOGIN_TIME,                // "user, login_time"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_IP,                        // "user, ip"                       �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FRIEND_SHARE,              // "user, friend_share"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_EMONEY3,                   // "user, Emoney3"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_EMONEY3_CHK,               // "user, Emoney3_chk"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_QUIZ_POINT,                // "user, quiz_point"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_BATTLE_LEV,                // "user, battle_lev"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_FAMILY_RANK,               // "user, family_rank"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_IDFAMILY,                  // "user, idfamily"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_PROFESSION_LEV,            // "user, profession_lev"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_PROFESSION_EXP,            // "user, profession_exp"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ONLINE_EXP,                // "user, online_exp"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_ONLINE_EXT_MONSTER_EXP,    // "user, online_ext_monster_exp"   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_VAMPIRE_VAL,               // "user, vampire_val"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_VITALCAPACITY,             // "user, VitalCapacity"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_OXYGEN,                    // "user, Oxygen"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_USER_FIELD_DEFENCEPOINT,
	// TODO::MILO 11/9/2015
	VAMPIRE_DB_USER_FILED_DODGEPOINT,
	VAMPIRE_DB_USER_FILED_POWERPOINT,
	VAMPIRE_DB_USER_FILED_STRONGPOINT,
	VAMPIRE_DB_USER_FILED_LIFEPOINT,
	VAMPIRE_DB_USER_FILED_STAMINA,
	VAMPIRE_DB_USER_FIELD_HEAD,
	VAMPIRE_DB_USER_FIELD_CITY,
	VAMPIRE_DB_USER_FIELD_ACHIVE_ADDPOINT,
	VAMPIRE_DB_USER_FIELD_IDTEAM,
}; //VAMPIRE_USER_DB

enum VAMPIRE_USER_X_DB_DATA     // ��Ѫ�����ݿ��ֶ�ö�� ��������ݿ�һһ��Ӧ��
{
	VAMPIRE_DB_USER_X_FIELD_ID,                         // "user_x, id"
	VAMPIRE_DB_USER_X_FIELD_NAME,                       // "user_x, name"
	VAMPIRE_DB_USER_X_FIELD_BIG_BADLUCK,                // "user_x, big_badluck"
	VAMPIRE_DB_USER_X_FIELD_SMALL_BADLUCK,              // "user_x, small_badluck"
	VAMPIRE_DB_USER_X_FIELD_LOTTERY_TIMES,              // "user_x, lottery_times"
	VAMPIRE_DB_USER_X_FIELD_BIG_GOODLUCK,               // "user_x, big_goodluck"
	VAMPIRE_DB_USER_X_FIELD_SMALL_GOODLUCK,             // "user_x, small_goodluck"
	VAMPIRE_DB_USER_X_FIELD_LASTLOTTERY,                // "user_x, lastlottery"
	VAMPIRE_DB_USER_X_FIELD_STONE0,                     // "user_x, Stone0"
	VAMPIRE_DB_USER_X_FIELD_STONE1,                     // "user_x, Stone1"
	VAMPIRE_DB_USER_X_FIELD_STONE2,                     // "user_x, Stone2"
	VAMPIRE_DB_USER_X_FIELD_CHK_SUM,                    // "user_x, chk_sum"
	VAMPIRE_DB_USER_X_FIELD_EXPBALLROBOT,               // "user_x, ExpBallRobot"
	VAMPIRE_DB_USER_X_FIELD_VIP_SHOW,                   // "user_x, vip_show"
};

enum VAMPIRE_USER_DB_ATTRIBUTE
{
	ZOMBIE_DB_USER_ATT_LEVEL,
	ZOMBIE_DB_USER_ATT_LEVELPOINT,
	ZOMBIE_DB_USERATTRDATA_DODGE,
	ZOMBIE_DB_USERATTRDATA_WEIGHT,
	ZOMBIE_DB_USER_ATT_END,

};

enum ZOMBIE_USER_ATTRIBUTE_TYPE
{
	ZOMBIE_DB_USERATTRDATA_ID,
	ZOMBIE_DB_USERATTRDATA_TYPE,
	ZOMBIE_DB_USERATTRDATA_NAME,
	ZOMBIE_DB_USERATTRDATA_ATTACK_TYPE,
	ZOMBIE_DB_USERATTRDATA_DEF_TYPE,
	ZOMBIE_DB_USERATTRDATA_MOVE_SPEED,
	ZOMBIE_DB_USERATTRDATA_CHASE_RANGE,
	ZOMBIE_DB_USERATTRDATA_PVE_PHYATTACK_MODULUS,				// PVEӢ�۹���ϵ��
	ZOMBIE_DB_USERATTRDATA_ATTACK_SPEED,
	ZOMBIE_DB_USERATTRDATA_MAIN_ATTRIBUTE,
	ZOMBIE_DB_USERATTRDATA_BASE_POWER,
	ZOMBIE_DB_USERATTRDATA_BASE_BRAINS,
	ZOMBIE_DB_USERATTRDATA_BASE_AGILITY,
	ZOMBIE_DB_USERATTRDATA_POWER_PULLULATE,
	ZOMBIE_DB_USERATTRDATA_BRAINS_PULLULATE,
	ZOMBIE_DB_USERATTRDATA_AGILITY_PULLULATE,
	ZOMBIE_DB_USERATTRDATA_LIFE_PULLULATE,
	ZOMBIE_DB_USERATTRDATA_ATTACK_FREQUENCY,
	ZOMBIE_DB_USERATTRDATA_STATE_DAMAGE_TYPE,					// ״̬�˺�����
	ZOMBIE_DB_USERATTRDATA_STATE_DAMAGE_MODULUS,				// ״̬�˺�ϵ��
	ZOMBIE_DB_USERATTRDATA_DAY_VIEW,
	ZOMBIE_DB_USERATTRDATA_NIGHT_VIEW,
	ZOMBIE_DB_USERATTRDATA_COLLIDE_RADIUS,
	ZOMBIE_DB_USERATTRDATA_TURN_ABOUT_SPEED,
	ZOMBIE_DB_USERATTRDATA_RESUME_LIFE,//�����ظ��ٶ�
	ZOMBIE_DB_USERATTRDATA_RESUME_MANA,
	ZOMBIE_DB_USERATTRDATA_RELIVE_MANA,
	ZOMBIE_DB_USERATTRDATA_BASE_LIFE,
	ZOMBIE_DB_USERATTRDATA_BASE_MAGIC_DEF,
	ZOMBIE_DB_USERATTRDATA_DEF_CORRECT,
	ZOMBIE_DB_USERATTRDATA_BASE_MIN_ATK,
	ZOMBIE_DB_USERATTRDATA_BASE_MAX_ATK,
	ZOMBIE_DB_USERATTRDATA_OBSIZE,
	ZOMBIE_DB_USERATTRDATA_AI_NAME,
	ZOMBIE_DB_USERATTRDATA_SKILL_INDEX,
	ZOMBIE_DB_USERATTRDATA_SKILL,
	ZOMBIE_DB_USERATTRDATA_SKILL_TYPE,
	ZOMBIE_DB_USERATTRDATA_LONGRANGE,
	ZOMBIE_DB_USERATTRDATA_OPEN,
	ZOMBIE_DB_USERATTRDATA_FREE,
	ZOMBIE_DB_USERATTRDATA_PVE_PERLEVEL_ATTACK,
	ZOMBIE_DB_USERATTRDATA_PVE_PERLEVEL_ARMOR,
	ZOMBIE_DB_USERATTRDATA_PVE_PERLEVEL_ATTACK_MAGIC,
	ZOMBIE_DB_USERATTRDATA_PVE_PERLEVEL_SKILLCD,
	ZOMBIE_DB_USERATTRDATA_PVE_PERLEVEL_LIFE,
	ZOMBIE_DB_USERATTRDATA_PVE_PERLEVEL_LIFE_RESTORE,
	ZOMBIE_DB_USERATTRDATA_DEFAULT_PASSIVE_SKILL,

	ZOMBIE_DB_USERATTRDATA_END,
};

const int NUM_SPIRIT_CORE = 39;// װ�׺���

enum USERATTR
{
    _USERATTRIB_EN = 1,        // ��ҵ�ǰEnֵ(En�ֵ�ǰ��Enֵ)
    _USERATTRIB_MANA = 2,        // Manaֵ
    _USERATTRIB_TEAMEXP = 3,        // 2005.11.11 ����ͳ����Ϣ
    _USERATTRIB_MONEY = 4,
    _USERATTRIB_PK = 6,
    _USERATTRIB_PORFESSION = 7,
    _USERATTRIB_SIZEADD = 8,
    _USERATTRIB_MONEYSAVED = 10,
    _USERATTRIB_ADDPOINT = 11,
    _USERATTRIB_LOOKFACE = 12,
    _USERATTRIB_HEALTH = 15,
    _USERATTRIB_STORAGELEVEL = 16,
    _USERATTRIB_SPEED = 17,
    _USERATTRIB_DEGREE = 18,
    _USERATTRIB_POSE = 19,
    _USERATTRIB_PROFFER = 20,   // ���ɹ��׶�
    _USERATTRIB_MERCENARYEXP = 23,
    _USERATTRIB_VIRTUE = 24,
    _USERATTRIB_MANTLE = 25,
    _USERATTRIB_KEEPEFFECT = 26,
    _USERATTRIB_HAIR = 27,
    _USERATTRIB_XP_X = 28,
    _USERATTRIB_STONE_LIMIT = 29,
    _USERATTRIB_STORAGE_LIMIT = 30,
    _USERATTRIB_CRAZYFIGHT_SKILLLIMITAMOUNT = 31,   // ��սʿ״̬�£�����ʹ�õ��Ҽ����ܴ�����
    _USERATTRIB_CRAZYFIGHT_DETATIME = 32,   // ��սʿ״̬�£��ܻ�����
    _USERATTRIB_KEEPEFFECT2 = 33,   //64 λ effect
    _USERATTRIB_BASESUPPORTENABLE = 34,   // ����Ԯ������ʹ��֪ͨ
    _USERATTRIB_EXP = 35,   // ���徭��
    _USERATTRIB_LEV = 36,   // ����ȼ�
    _USERATTRIB_USEREXP = 37,   // ��ʦ����
    _USERATTRIB_USERLEV = 38,   // ��ʦ�ȼ�
    _USERATTRIB_SPIRITSTORAGELEV = 39,   // ��Ҹ��ɿ�����SPIRITstorage_lev����
    _USERATTRIB_QUANTA = 40,   // ���������ջ���ֵ
    _USERATTRIB_TEAM_MEMBER_AMOUNT = 41,   // �ӳ�ͷ����ʾ�Ķ�������
    _USERATTRIB_STONE0 = 42,
    _USERATTRIB_STONE1 = 43,
    _USERATTRIB_STONE2 = 44,

    _USERATTRIB_EXPTYPE = 50,
    _USERATTRIB_XP = 51,
    _USERATTRIB_MAXXP = 52,

    _USERATTRIB_ARMOR = 53,
    _USERATTRIB_SPIRITLOOK = 54,
    _USERATTRIB_SPIRITCOLOR = 55,           //�����ɫ
    _USERATTRIB_FUEL = 56,           // ȼ��
    _USERATTRIB_RMB = 57,
    _USERATTRIB_MONEYSAVED2 = 58,
    _USERATTRIB_SYMBOLFEETIME = 59,           //���͹����ӻ��µ�״̬��״̬��ʱ��
    _USERATTRIB_TEAM_STATUS_EFFECT = 60,           //
    _USERATTRIB_KILLMONSTERAMOUNT = 61,           // ɱ��ֻ������action, ͬ�����ͻ���
    _USERATTRIB_ARMORLOOK = 62,
    _USERATTRIB_GENERATOR = 63,           // ����������������
    _USERATTRIB_SPIRITDATA_EN_STATE = 64,

    _USERATTRIB_LIST1 = 65,
    _USERATTRIB_LIST2 = 66,
    _USERATTRIB_SENDGOODS = 67,
    _USERATTRIB_KEEPEFFECTEX = 68,
    _USERATTRIB_INC_KILL_HERO_AMOUNT = 69,
    _USERATTRIB_INC_KILL_MONSTER_AMOUNT = 70,
    _USERATTRIB_INC_DEADAMOUNT = 71,
    _USERATTRIB_INC_SECONDARY_ATTACK_AMOUNT = 72,
    _USERATTRIB_USERFLATEXP = 73,
    _USERATTRIB_USERFLATLEV = 74,
    _USERATTRIB_USERIBS = 75,
    _USERATTRIB_RESTORELIFE = 76,
    _USERATTRIB_RESTOREMANA = 77,

    _USERATTRIB_INC_KILL_BARRACKS_AMOUNT = 78,
    _USERATTRIB_INC_KILL_EMPACEMENT_AMOUNT = 79,
    _USERATTRIB_SERIES_KILL_AMOUNT = 80,
    _USERATTRIB_SECONDARY_ATTACK_AMOUNT_TOBS = 81,

    // SPIRIT	ע���SPIRITDATA_??? ͬ��
    _USERATTRIB_SPIRITDATA_OFFSET = 100,
    _USERATTRIB_TYPE = 105,

    // --- delete ----
    _USERATTRIB_REGISTER = 106,
    _USERATTRIB_LIFE = 107,
    _USERATTRIB_ADDLIFE = 108,
    _USERATTRIB_POWAER = 109,
    _USERATTRIB_BRAINS = 110,
    _USERATTRIB_AGILITY = 111,
    _USERATTRIB_MINATTACK = 112,

    _USERATTRIB_ADDPOWAER = 113,
    _USERATTRIB_ADDBRAINS = 114,
    _USERATTRIB_ADDAGILITY = 115,
    _USERATTRIB_ADDATTACK = 116,
    _USERATTRIB_ADDARMOR = 117,
    _USERATTRIB_ADDMAXLIFE = 118,
    _USERATTRIB_ADDMAMA = 119,
    _USERATTRIB_MAXATTACK = 120,
    _USERATTRIB_UPLEVATTRIB = 121,

    _USERATTRIB_DECPOWAER = 122,
    _USERATTRIB_DECBRAINS = 123,
    _USERATTRIB_DECAGILITY = 124,

    _USERATTRIB_CAP1,
    _USERATTRIB_CAP2,
    _USERATTRIB_CAP3,
    _USERATTRIB_CAP4,
    _USERATTRIB_CAP5,
    _USERATTRIB_CAP6,
    _USERATTRIB_POINT,
    _USERATTRIB_DEED,

    // --- need update value.
    _USERATTRIB_SHIELDSKILLPOWER,           // 2005.1.10 itemtype��sort=18����type=0|1�ĶܵĶ�������ֵ����
    _USERATTRIB_COUNTERSTRIKELIGHT,         // 2005.1.25 ����֮����������

    _USERATTRIB_SPIRITVAR_BASE = 200,
    _USERATTRIB_SHIELD_ENERGY,

    _USERATTRIB_BODYTYPE = 211,

    _USERATTRIB_MAXLIFE = 300,
    _USERATTRIB_MAXMANA = 301,
    _USERATTRIB_MAXFUEL = 302,
    _USERATTRIB_VIPLEV = 303,
    _USERATTRIB_MOUNT = 304,
    _USERATTRIB_BUSINESSACCOUNT = 305,          //dwAttributeData:business�ֶ�ֵ,dwAttributeDataHigh: 0:���״ε�¼ 1:�״ε�¼

    //add by ccw-xxx
    _USERATTRIB_EMONEY3 = 306,
    _USERATTRIB_TIME = 308,

    _USERATTRIB_ATK_DECREASE = 309,
    _USERATTRIB_DEF_DECREASE = 310,
    _USERATTRIB_ATKRATE_DECREASE = 311,
    _USERATTRIB_DEF_INCREASE = 312,
    _USERATTRIB_OXYGEN = 322,

    _USERATTRIB_AUTOEXPLORE_TIME = 323,

    // ����ʬ���ˡ�����ս������������� V1.07 �У� ɾ�����˾�ȷ���Ե�/��ȷֵ
    //    _USERATTRIB_ACCURATEPOINT       = 501, //��ȷ����
    _USERATTRIB_SHORT_ATKMIN = 502, //����
    _USERATTRIB_SHORT_DEF = 503, //����ֵ
    _USERATTRIB_DODGEVALUE = 504, //���� ����
    //    _USERATTRIB_WEIGHTVALUE         = 505, //����
    //    _USERATTRIB_STVALUE             = 506, //����
    //    _USERATTRIB_ACCURATE            = 507, //��ȷֵ
    _USERATTRIB_DEFENCEPOINT = 514, //���������
    _USERATTRIB_DODGEPOINT = 515, //���ݵ���
    _USERATTRIB_POWERPOINT = 516, //��������
    _USERATTRIB_MANAPOINT = 517, //��������
    _USERATTRIB_LIFEPOINT = 518, //��������
    _USERATTRIB_FREEPOINT = 519, //���ɵ���
    _USERATTRIB_DEFENSEPOINT_TOADD = 520, //�����俹�������
    _USERATTRIB_DODGEPOINT_TOADD = 521, //���������ݵ���
    _USERATTRIB_POWERPOINT_TOADD = 522, //��������������
    _USERATTRIB_MANAPOINT_TOADD = 523, //��������������
    _USERATTRIB_LIFEPOINT_TOADD = 524, //��������������

    //    _USERATTRIB_WEIGHT              = 525, //��ҵ�ǰ����ֵ

    _USERATTRIB_PROFESSION_LEV = 526, //ְҵ�ȼ�
    _USERATTRIB_PROFESSION_EXP = 527, //ְҵ����ֵ
    _USERATTRIB_STAMINA = 528, //��Ҿ���ֵ 09-12-22
    _USERATTRIB_EMOTIONAL_EXPREESION = 529,	//��ұ���

    //Dota
    _USERATTRIB_DELMAGIC = 550,	//
    _USERATTRIB_ADDMAGIC = 551,	//
    _USERATTRIB_POWER_DELTA = 552,
    _USERATTRIB_BRAIN_DELTA = 553,
    _USERATTRIB_AGILITY_DELTA = 554,

    _USERATTRIB_MONEY_ADDITIONAL_ACCUMULATION = 555,	//���ö��⽱�����ֵ

    _USERATTRIB_ATTACK_DELTA = 556,
    _USERATTRIB_MONEY_RATE = 661,	//��ұ���
    _USERATTRIB_BRAIN_TO_MAGICATTACK_RATE = 663,
    _USERATTRIB_BASE_MAGICATTACK = 664,	//GS TO BS
    _USERATTRIB_BUFF_BRAIN = 665,	//BS TO GS
    _USERATTRIB_BUFF_AGILITY = 666,	//BS TO GS
    _USERATTRIB_BUFF_POWER = 667,	//BS TO GS

    _USERATTRIB_PARRY_CHANCE = 700,			// ��ʶ�����ܼ���
    _USERATTRIB_ADD_PARRY_CHANCE = 701,			// ��ʶ���������ܼ���
    _USERATTRIB_MAGIC_ARMOR = 702,			// ��ʶ��ħ��
    _USERATTRIB_ADD_MAGIC_ARMOR = 703,			// ��ʶ������ħ��

    _USERATTRIB_BEKILL_EXTRA_MONEY = 710,          //Ӣ�۱���ɱ�����Ǯ
    _USERATTRIB_BEKILL_SEC_EXTRA_MONEY = 711,          //Ӣ�۱����������Ǯ
    _USERATTRIB_BANNER_ADD = 713,
    _USERATTRIB_BANNER_DEL = 714,
    _USERATTRIB_BEKILL_ADDMONEY = 717,							// Ӣ�۱���ɱ��ָ��Ŀ���ָ����Ǯ
    _USERATTRIB_PVE_Energy = 718,									// ͬ������
    _USERATTRIB_GuardianBeastTime = 720,							// �ػ��޳���ʱ��
    _USERATTRIB_SECOND_MONEY_INC = 722,								// ����ÿ���ö�����
    _USERATTRIB_SECOND_MONEY_DEC = 723,								// ����ÿ���ö�����
    _USERATTRIB_BATTLECHAUNT_GETPOINT = 724,						// ս��÷�
    _USERATTRIB_BANNER_Amount = 721,							   //������Դ����
    _USERATTRIB_PVE_CHANGE_HERO = 800,							   // PVE�л�Ӣ��
    _USERATTRIB_PVE_CHANGE_HERO_ACK = 801,						  // PVE�л�Ӣ��

    _USERATTRIB_PVE_LEVEL = 899,
    _USERATTRIB_PVE_EXPERIENCE = 900,
    _USERATTRIB_PVE_ATTACK = 901,
    _USERATTRIB_PVE_ARMOR = 902,
    _USERATTRIB_PVE_ATTACK_MAGIC = 903,
    _USERATTRIB_PVE_SKILL_CD = 904,
    _USERATTRIB_PVE_LIFE_MAX = 905,
    _USERATTRIB_PVE_LIFE_RESTORE = 906,

    _USERATTRIB_NONE = 65535,               // �Ƿ�ֵ
};

enum DEVIL_ATTR
{
	DEVIL_ATTRIBUTE_NONE				= 0,
	DEVIL_ATTRIBUTE_MANA				= 1,		 
	DEVIL_ATTRIBUTE_EXP, 
	DEVIL_ATTRIBUTE_LIFE,
	DEVIL_ATTRIBUTE_LEV,
	DEVIL_ATTRIBUTE_ADDITIONAL_LIFE,
	DEVIL_ATTRIBUTE_ADDITIONAL_PHY_ATK,
	DEVIL_ATTRIBUTE_ADDITIONAL_PHY_DEF,
	DEVIL_ATTRIBUTE_ADDITIONAL_MAG_ATK,
	DEVIL_ATTRIBUTE_ADDITIONAL_MAG_DEF,
	DEVIL_ATTRIBUTE_ADDITIONAL_AGILTIY,
	DEVIL_ATTRIBUTE_ADDITIONAL_MAGIC,
	DEVIL_ATTRIBUTE_LIFE_SPAN,
	DEVIL_ATTRIBUTE_EXP_PERCENT,
	DEVIL_ATTRIBUTE_ERROR	= 65535,			// �Ƿ�ֵ
};

enum MSG_NOTIFY_CODE       //ֻ���͵��ͻ��˵�֪ͨ������Ϣ ����˲�������    
{
	TAG_ERROR,

	TAG_ERROR_END = 65535,


	TAG_ALL_END   = -1,	
};
//////////////////////////////////////////////////////////////////////////
enum XP_STATUS
{
	XPSTATUS_STOP,		// ��ͣ״̬
	XPSTATUS_ADD,		// ����״̬
	XPSTATUS_WAIT,		// ��ֵ״̬(�ȴ�����)
	XPSTATUS_FIRE,		// ����״̬(�Ѿ���XP����)
};


enum  USERSHIPJOB_SCORE
{
	USERSHIPJOBSCORE_ID				= 0,
	// -- old totalscore
	USERSHIPJOBSCORE_TOTALSCORES	,
	USERSHIPJOBSCORE_TOTALKILLS	,
	USERSHIPJOBSCORE_TOTALDEATHS	,
	USERSHIPJOBSCORE_FINISHS		,
	USERSHIPJOBSCORE_PERFECTFINISHS	,
	USERSHIPJOBSCORE_SAFEFINISHS	,
	// -- score
	USERSHIPJOBSCORE_MISSIONNAME	,
	USERSHIPJOBSCORE_MISSIONID		,
	USERSHIPJOBSCORE_BASESCORE		,
	USERSHIPJOBSCORE_KILLS			,
	USERSHIPJOBSCORE_DEATHS			,
	USERSHIPJOBSCORE_MISSIONSCORE	,
	USERSHIPJOBSCORE_MISSIONNAME_1	,
	USERSHIPJOBSCORE_MISSIONSCORE_1	,
	USERSHIPJOBSCORE_MISSIONNAME_2	,
	USERSHIPJOBSCORE_MISSIONSCORE_2	,
	USERSHIPJOBSCORE_MISSIONNAME_3	,
	USERSHIPJOBSCORE_MISSIONSCORE_3	,
	USERSHIPJOBSCORE_MISSIONNAME_4	,
	USERSHIPJOBSCORE_MISSIONSCORE_4	,
	USERSHIPJOBSCORE_MISSIONNAME_5	,
	USERSHIPJOBSCORE_MISSIONSCORE_5	,
	USERSHIPJOBSCORE_MISSIONNAME_6	,
	USERSHIPJOBSCORE_MISSIONSCORE_6	,
	USERSHIPJOBSCORE_MISSIONNAME_7	,
	USERSHIPJOBSCORE_MISSIONSCORE_7	,
	USERSHIPJOBSCORE_MISSIONNAME_8	,
	USERSHIPJOBSCORE_MISSIONSCORE_8	,
	USERSHIPJOBSCORE_PERFECTFINISH	,		// �����ݿ��ֶΣ����������־
	USERSHIPJOBSCORE_END_			,
};

enum SHIP_DATA
{
	SHIPDATA_ID,
		SHIPDATA_TYPE,
		SHIPDATA_NAME,
		SHIPDATA_IDNAME,
		SHIPDATA_CAPTAIN,
		SHIPDATA_CAPTAIN_LEV,
		SHIPDATA_OWNER_TYPE,
		SHIPDATA_OWNER_ID,
		SHIPDATA_RECORD_FLY,
		SHIPDATA_RECORD_FINISH, 
		SHIPDATA_NPC1,
		SHIPDATA_NPC2,
		SHIPDATA_NPC3,
		SHIPDATA_NPC4,
		SHIPDATA_NPC5,
		SHIPDATA_NPC6,
		SHIPDATA_NPC7,
		SHIPDATA_NPC8,		
		SHIPDATA_LOOKFACE,
};

enum SHIPJOB_TYPEDATA
{// "shipmission"
	SHIPJOB_ID				, 
		SHIPJOB_Name			,
		SHIPJOB_Sort			,
		SHIPJOB_Type			,	// ����˸���type�ֶΣ����������ʱ������Ӧ������������жϷ�ʽ��
		SHIPJOB_Monster1		,
		SHIPJOB_Num1			,
		SHIPJOB_Monster2		,
		SHIPJOB_Num2			,
		SHIPJOB_Monster3		,
		SHIPJOB_Num3			,
		SHIPJOB_Monster4		,
		SHIPJOB_Num4			,
		SHIPJOB_TargetMapGenNO	,
		SHIPJOB_Shipid			,
		SHIPJOB_Path			,
		SHIPJOB_Maxplayers		,
		SHIPJOB_Req_minlev		,
		SHIPJOB_Req_maxlev		,
		SHIPJOB_Req_robottype	,
		SHIPJOB_Req_sex			,
		SHIPJOB_Req_item		,
		SHIPJOB_Limit_time		,
		SHIPJOB_Introduce		,
		SHIPJOB_Action			,
		SHIPJOB_Task			,
		SHIPJOB_Req_maxreborn	,
		SHIPJOB_MissionNum		,	// ������+��֧������
		SHIPJOB_DeathPunish		,	// �����ͷ�
		SHIPJOB_FinishBonus		,
		SHIPJOB_SurviveBonus	,
		SHIPJOB_Speed_finish	,	// �������������ʱ��
		SHIPJOB_Speed_finish_time,	// ���������ʱ����ʱ��ϵͳʱ��
		SHIPJOB_Speed_perfect	,	// �������������������ʱ��
		SHIPJOB_Speed_perfect_time, // ���������������ʱ����ʱ��ϵͳʱ��
		SHIPJOB_Destroy_num,
		SHIPJOB_Secret_num,
		SHIPJOB_Main_score,
		SHIPJOB_Monster1_score,
		SHIPJOB_Monster2_score,
		SHIPJOB_Monster3_score,
		SHIPJOB_Monster4_score,
		SHIPJOB_Destroy_item_score,
		SHIPJOB_Secret_score,
		SHIPJOB_Total_score,
		SHIPJOB_req_battlelev,
		SHIPJOB_need_score,
		SHIPJOB_prize_item,
		SHIPJOB_prize_money,
		SHIPJOB_prize_stone,
		
		SHIPJOB_action_begin,		//���븱����ͼ֮��ִ�е�action
		SHIPJOB_action_finish,		//������ɺ�ִ�е�action
		
		SHIPJOB_action_levexp_79,
		SHIPJOB_action_levexp_80_89,
		SHIPJOB_action_levexp_90_99,	
		SHIPJOB_action_levexp_100_109,	
		SHIPJOB_action_levexp_110_119,	
		SHIPJOB_action_levexp_120,	
		SHIPJOB_action_rankexp_12,		
		SHIPJOB_action_rankexp_13,		
		SHIPJOB_action_rankexp_14,		
		SHIPJOB_action_rankexp_15,		
		SHIPJOB_action_rankexp_16,		
		SHIPJOB_action_rankexp_17,
		SHIPJOB_action_Stat_monster1,
		SHIPJOB_action_Stat_monster2,
		SHIPJOB_action_Stat_monster3,
		SHIPJOB_action_Stat_monster4,
		// �ֶζ��������־
		SHIPJOB_End
};

enum
{
	//��Ҫ���¼��㹲��ս�����Ĳ���,CalcBattleEffect��
	//���¼���������ս����
	RECAL_FAMILY_SHARE = 0x1,
	
};

//��������Ʒ��ص�ö�ٶ���
//��Ʒ����ö��
enum ITEMTYPEDATA
{
	ITEMTYPEDATA_ID	= 0,
	ITEMTYPEDATA_NAME,
	ITEMTYPEDATA_LEVEL,				
	ITEMTYPEDATA_WEIGHT_h,				
	ITEMTYPEDATA_PRICE,
	ITEMTYPEDATA_ACTION,
	ITEMTYPEDATA_LIFE,
	ITEMTYPEDATA_MANA,					// ��¼����Ʒ��������ֵ���޵�Ч��
	ITEMTYPEDATA_MANA_RE,				// ��¼����Ʒ�������ָ�����ֵЧ������ֵ��ʾ�����ظ���������ֵ��ʾ�����ظ�����
	ITEMTYPEDATA_MAX_POWER,			
	ITEMTYPEDATA_CHARGE_POWER, //10			
	ITEMTYPEDATA_AMOUNTLIMIT,
	ITEMTYPEDATA_IDENT_h,
	ITEMTYPEDATA_EQUIP_TYPE,
	ITEMTYPEDATA_EQUIP_LEVEL,
	ITEMTYPEDATA_EQUIP_SKILL,
	ITEMTYPEDATA_GEM1_h,
	ITEMTYPEDATA_GEM2_h,
	ITEMTYPEDATA_MAGIC1_h,
	ITEMTYPEDATA_MAGIC2_h,
	ITEMTYPEDATA_MAGIC3_h,//20
	ITEMTYPEDATA_MAXRANGE,
	ITEMTYPEDATA_ATKSPEED,
	ITEMTYPEDATA_PRECISION,
	ITEMTYPEDATA_PACK_SIZE,
	ITEMTYPEDATA_PACK_WIDTH,
	ITEMTYPEDATA_MAX_SHORT_ATK,
	ITEMTYPEDATA_MIN_SHORT_ATK,
	ITEMTYPEDATA_MAX_LONG_ATK,
	ITEMTYPEDATA_MIN_LONG_ATK,//30
	ITEMTYPEDATA_SHORT_DEF,		
	ITEMTYPEDATA_LONG_DEF,		
	ITEMTYPEDATA_DEFENCE_MAX,
	ITEMTYPEDATA_DEFENCE,
	ITEMTYPEDATA_DODGE,
	ITEMTYPEDATA_VALUE,
	ITEMTYPEDATA_UPLEVTIME,
	ITEMTYPEDATA_DECAYDEF,
	ITEMTYPEDATA_SHAPE_h,
	ITEMTYPEDATA_RMB,//40
	ITEMTYPEDATA_REQ_ENGINE,		
	ITEMTYPEDATA_REQ_GUARD,
	ITEMTYPEDATA_ADDITIONAL_LEVEL,
	ITEMTYPEDATA_SELL_TYPE,		//���ֶ��Զ����ƽ��б�ʾ��ÿһλ����һ��������Ʒ�飬ͬһ����Ʒ����ͬʱ���ڶ��������Ʒ���С������������ƷΪ������Ʒ���е���Ʒ����������������Ʒʱ���Ӹ����������ȡһ��

	ITEMTYPEDATA_DFP,			//��������
	ITEMTYPEDATA_PRESP,			//��ȷ���Ե���
	ITEMTYPEDATA_PWP,			//�������Ե���
	ITEMTYPEDATA_SMP,			//���� ����
	ITEMTYPEDATA_STP,			//�������Ե���
	ITEMTYPEDATA_LIFEP,			//�������Ե���
	ITEMTYPEDATA_DFVAULE,		//����ֵ
	ITEMTYPEDATA_PRESVALUE,		//��ȷֵ
	ITEMTYPEDATA_PWVALUE,		//����ֵ
	ITEMTYPEDATA_SMVALUE,		//���� ����
	ITEMTYPEDATA_STVALUE,		//����ֵ

	ITEMTYPEDATA_HEADSHOT_RATE,			//װ����ͷ��
	ITEMTYPEDATA_HOLDKEY_TIME_LIMIT,	//��������׼ʱ������
	ITEMTYPEDATA_HOLDKEY_GAIN,			//��׼������ͷ�����޻��ս����������������
	ITEMTYPEDATA_NEEDAMMO_NUM,			//ǹеһ�������Ҫ���ӵ���
	ITEMTYPEDATA_SUPPRESS_PROBALITY,	//ǹе���ʱ��ɹ���ѹ�Ƽ���
	ITEMTYPEDATA_BACK_OFF,	            //ǹе���ʱ���˼���
	ITEMTYPEDATA_BREAK_BODY,	         //ǹе���ʱ���֫��ļ���
	ITEMTYPEDATA_SHOT_WITH,	          
	ITEMTYPEDATA_ALLOW_REPAIR,	        //�Ƿ���������  1��������  0������      
	ITEMTYPEDATA_TRIGGERSKILL_ID,       //��Ʒ��������ID,��magic����ID�ֶ�ͬ	shf
	ITEMTYPEDATA_TRIGGERSKILL_COOLTIME, //��Ʒ����������ȴʱ�䣬ʹ��6λ���ֱ�ʾ��ǰ2λ��ʾ��Ʒ������ȴʱ�����ͣ���4λ���ֱ�ʾ��ȴʱ��;
	ITEMTYPEDATA_EFFECTIVE_LONG,        //ʱЧ��Ʒ��Чʱ��
	ITEMTYPEDATA_FIRE_TYPE,				//�������� TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�
	ITEMTYPEDATA_BURN,					//ȼ������ TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�
	ITEMTYPEDATA_BURN_RANGE,			//���淶Χ TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�
	ITEMTYPEDATA_BOMB,					//��ը���� TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�

	//Dota ����
	ITEMTYPEDATA_COMPONENT0,		//�ϳ����貿��
	ITEMTYPEDATA_COMPONENT1,
	ITEMTYPEDATA_COMPONENT2,
	ITEMTYPEDATA_COMPONENT3,
	ITEMTYPEDATA_COMPONENT4,
	ITEMTYPEDATA_DOTA_POWER,
	ITEMTYPEDATA_DOTA_BRAIN,
	ITEMTYPEDATA_DOTA_AGILITY,
	ITEMTYPEDATA_DOTA_DAMAGE0_USE,
	ITEMTYPEDATA_DOTA_DAMAGE1_USE,
	ITEMTYPEDATA_DOTA_DAMAGE2_USE,
	ITEMTYPEDATA_DOTA_DAMAGE0_EQUIP,
	ITEMTYPEDATA_DOTA_DAMAGE1_EQUIP,
	ITEMTYPEDATA_DOTA_DAMAGE2_EQUIP,
	ITEMTYPEDATA_DOTA_DAMAGE0_REMOVE,
	ITEMTYPEDATA_DOTA_DAMAGE1_REMOVE,
	ITEMTYPEDATA_DOTA_DAMAGE2_REMOVE,
	ITEMTYPEDATA_DOTA_SECADDMONEY,

	ITEMTYPEDATA_MAX_ITEMTYPE,

	//ת��
	ITEMTYPEDATA_AMOUNT_h = ITEMTYPEDATA_AMOUNTLIMIT,	
	ITEMTYPEDATA_AMOUNTLIMIT_h = ITEMTYPEDATA_AMOUNTLIMIT,

	////////////////////////////////////////////////
	ITEMTYPEDATA_DELETE	=	ITEMTYPEDATA_MAX_ITEMTYPE	+	1,	// ��������Ч���ֶΣ�����ֱ��ʹ�á������ڷֱ��ж� 46
// 	ITEMTYPEDATA_MINRANGE,
	ITEMTYPEDATA_EQUIP_POS,					// ��װ����λ��
	ITEMTYPEDATA_EQUIP_PROF,				// ��������Ҫ��
// 	ITEMTYPEDATA_EQUIP_TYPE1,				// װ��Ҫ��
	ITEMTYPEDATA_EQUIP_DATA1,				// װ��Ҫ��
// 	ITEMTYPEDATA_EQUIP_TYPE2,				// װ��Ҫ��
// 	ITEMTYPEDATA_EQUIP_DATA2,				// װ��Ҫ��
// 	ITEMTYPEDATA_ATTACK_CAP,				// �Լ��ܺ͵�ҩ��װ��ǰ��
	ITEMTYPEDATA_PACK_WEIGHTLIMIT,
	ITEMTYPEDATA_REPAIR_SELF,				// ÿ3���޸��ĵ���
// 	ITEMTYPEDATA_REPAIR_TYPE1,				// ����װ�ã���������
// 	ITEMTYPEDATA_REPAIR_CAP1, 				// ����װ�ã��޸�����
	ITEMTYPEDATA_REPAIR_TYPE2,
	ITEMTYPEDATA_REPAIR_CAP2,//60
	ITEMTYPEDATA_REPAIR_TYPE3,
	ITEMTYPEDATA_REPAIR_CAP3,
// 	ITEMTYPEDATA_MAXATK_h,			// 
// 	ITEMTYPEDATA_MINATK_h,
	ITEMTYPEDATA_FIGHTERATK_h,
	ITEMTYPEDATA_GUNNERATK_h,
	ITEMTYPEDATA_ENERGYATK_h,
// 	ITEMTYPEDATA_FINALDEF,
	ITEMTYPEDATA_SWITCH,			// head_switch 
	ITEMTYPEDATA_AMMO_TYPE,
// 	ITEMTYPEDATA_PK_DEF,		//�¼��ֶ�pk_def�����atk_fighter��atk_gunne��atk_energy�ķ�����ֵ
// 	ITEMTYPEDATA_POINT_h,
// 	ITEMTYPEDATA_UPLEVEL_RULE,	//��������,�ֶκ�3λ���������ȼ���ǰ���λ�����������򣬶�Ӧ����item���е�uplv_rule�ֶ�
// 	ITEMTYPEDATA_QUALITY_h,		//Ʒ��
// 	ITEMTYPEDATA_SORT_h,
// 
// 
// 	ITEMTYPEDATA_SPRITE_LEVEL = 200,		// ����ȼ� װ���������ҵĵȼ����벻�����ھ���ĵȼ���2��
// 	ITEMTYPEDATA_GROWTH_h = 201,		// ����ԭʼ�ɳ���
// 	ITEMTYPEDATA_LEVEXP = 202,				// ������������һ����Ҫ�ľ���ֵ
	//�������
	//�����item�ֶ�ʹ�ö���
	ITEMTYPEDATA_FITTINGS_COMBIME_1 = ITEMTYPEDATA_REPAIR_TYPE2,//------------�ϳɵĴ���1
	ITEMTYPEDATA_FITTINGS_COMBIME_2 = ITEMTYPEDATA_REPAIR_CAP2,//------------�ϳɵĴ���2
	ITEMTYPEDATA_FITTINGS_COMBIME_ODDS = ITEMTYPEDATA_REPAIR_CAP3, //------------�ϳɼ���
	ITEMTYPEDATA_FITTINGS_COMBIME_RESULT = ITEMTYPEDATA_REPAIR_TYPE3,//------------�ϳɽ��

	//��ǹ������	
// 	ITEMTYPEDATA_AMMO_CANISTER			= ITEMTYPEDATA_PACK_SIZE,			//-----------������0Ϊ��ͨ��1Ϊ������
	ITEMTYPEDATA_AMMO_STRAFE			= ITEMTYPEDATA_PACK_WEIGHTLIMIT,	//-----------��ǹÿ�η�����ӵ�����
	
	//��������
// 	ITEMTYPEDATA_EVOLVE_1				= ITEMTYPEDATA_DEFENCE,				//-----------��ʾ��һ�ӽ���·��
// 	ITEMTYPEDATA_EVOLVE_2				= ITEMTYPEDATA_DODGE,				//-----------��ʾ�ڶ��ӽ���·��
// 	ITEMTYPEDATA_EVOLVE_3				= ITEMTYPEDATA_VALUE,				//-----------��ʾ�����ӽ���·��
// 
// 	//EN�⡢�ƽ�������
// 	ITEMTYPEDATA_EN_REGENERATE			= ITEMTYPEDATA_SWITCH,				//-----------�Զ��ظ�EN����
// 	ITEMTYPEDATA_FU_REGENERATE			= ITEMTYPEDATA_SWITCH,				//-----------�Զ��ظ�FU����
// 		
// 	//�������
// 	//�����������
// 	ITEMTYPEDATA_FITTINGS_REGENERATE_HP	= ITEMTYPEDATA_REPAIR_SELF,
// 	ITEMTYPEDATA_FITTINGS_REGENERATE_EN	= ITEMTYPEDATA_REPAIR_TYPE1,
// 	ITEMTYPEDATA_FITTINGS_REGENERATE_FU	= ITEMTYPEDATA_REPAIR_CAP1,
// 	ITEMTYPEDATA_FITTINGS_MAX_FU	= ITEMTYPEDATA_PACK_SIZE,//-----------����ȼ������
// 	ITEMTYPEDATA_FITTINGS_IMMUNITY_TYPE = ITEMTYPEDATA_SWITCH,//--------�������Ե�����
// 	ITEMTYPEDATA_FITTINGS_IMMUNITY_LEVEL = ITEMTYPEDATA_AMMO_TYPE,//--------�������Ե����ߵĵȼ�����
// 	//ͷ���������
// 	ITEMTYPEDATA_FITTINGS_PRODUCE_EXP	= ITEMTYPEDATA_REPAIR_SELF,
// 	ITEMTYPEDATA_FITTINGS_PRODUCE_GOLD	= ITEMTYPEDATA_REPAIR_TYPE1,
// 	ITEMTYPEDATA_FITTINGS_PRODUCE_STONE	= ITEMTYPEDATA_REPAIR_CAP1,
	ITEMTYPEDATA_FITTINGS_SKILL_CAPACITY	= ITEMTYPEDATA_PACK_WEIGHTLIMIT,//----------��������������������������ֵ

	//����
	ITEMTYPEDATA_LAYMINE_INTONE			= ITEMTYPEDATA_REPAIR_SELF,		//-----------�Զ�����ʱ�ǲ��׵�ʱ���� 
// 	ITEMTYPEDATA_REMOTEMINE_RANGE		= ITEMTYPEDATA_MAXRANGE,			//-----------���׵İ�װ��Χ
};

//��Ʒ���
enum ITEMTYPECATE{
	ITEMDATA_SORT1 = 0,
	ITEMDATA_SORT2,
	ITEMDATA_SORT3,
	ITEMDATA_SORT4,
	ITEMDATA_SORT5,
	ITEMDATA_EQUIPTYPE,
	ITEMDATA_EQUIPSUBTYPE,
	ITEMDATA_EQUIPINTERNALLEVEL,
	ITEMDATA_QUALITY,
	ITEMDATA_EQUIPTYPE_1,		
	ITEMDATA_SKILLTYPE,			
	ITEMDATA_AMMO_HEAD,
	ITEMDATA_SPECIALWEAPONE,
	ITEMDATA_TYPEID_END	
};

//��Ʒ��ö�ٶ���
enum ITEMDATA
{
	ITEMDATA_ID			= 0,			
	ITEMDATA_TYPE,
	ITEMDATA_OWNERTYPE,
	ITEMDATA_OWNERID,
	ITEMDATA_PLAYERID,
	ITEMDATA_POSDIR,
	ITEMDATA_AMOUNT,
	ITEMDATA_IDENT,
	ITEMDATA_DATA,
	ITEMDATA_PLUNDER,     //������Ʒ��ʶ
	ITEMDATA_SALE_TIME,   //������������
	ITEMDATA_TIMELIMIT,   //��Ʒʹ��ʱ��
// 	//////////////////
// 	ix,	ITEMDATA_MAX_ITEM = ix - 1,	// item����ֶΣ�����ֱ��ʹ�á������ڷֱ��ж�
// 	/////////////////////////////////////////////
		
	ITEMDATA_MAXHP,	
	ITEMDATA_WEIGHT,
	//////////////////
	ix,	ITEMDATA_MAX_ITEM = ix - 1,	// item����ֶΣ�����ֱ��ʹ�á������ڷֱ��ж�
	/////////////////////////////////////////////
	ITEMDATA_DATA1,	
	ITEMDATA_DATA2,
	ITEMDATA_DATA3,
	ITEMDATA_DATA4,
	ITEMDATA_SHAPE,
	ITEMDATA_ADDLEVEL,
	
	ITEMDATA_HOTATK,
	ITEMDATA_SHAKEATK,
	ITEMDATA_COLDATK,
	ITEMDATA_LIGHTATK,
	ITEMDATA_CHK_SUM,
	ITEMDATA_FORGENAME,
	ITEMDATA_SPECIALFLAG,//װ�����Ѫ��ϵͳ tcp 2007-3-18 add
	ITEMDATA_DATA5,		//��ʾ���������������data1��data2������ͬ��
	ITEMDATA_DATA6,		//��ʾ���Ķ����������data1��data2������ͬ��
	ITEMDATA_WEIGHT3,	//
	ITEMDATA_WEIGHT4,
	ITEMDATA_ADDLEVEL_EXP,
	ITEMDATA_UP_ADDLEVEL_TODAY,
	ITEMDATA_DEAD_TIME,               //ʱЧ��ƷʧЧʱ��	srf
	iy,ITEMDATA_MAX_ITEMEX=iy-1,	// itemex����ֶΣ�����ֱ��ʹ�á������ڷֱ��ж�
	/////////////////////////////////////////////////
	// old field
	ITEMDATA_GEM1=ITEMDATA_DATA1,				//�����������ʶ
	ITEMDATA_GEM2=ITEMDATA_DATA2,

	// ���ͼ��¼�»����ID��TYPE�����ڿͻ�����ʾ�������ԡ�
	ITEMDATA_SPIRIT_ID = ITEMDATA_DATA,
	ITEMDATA_SPIRIT_COLOR=ITEMDATA_MAXHP,
	ITEMDATA_SPIRIT_LEVEL=ITEMDATA_WEIGHT,
	// data1~4�ϳ�ΪSPIRIT_TYPE
	
	
	/////////////////////////////////////////////////
	// deleted field
	ITEMDATA_DELETE=ITEMDATA_MAX_ITEMEX+1,	// ��������Ч���ֶΣ�����ֱ��ʹ�á������ڼ��ݴ���
	
	//		ITEMDATA_MAXATK,			//2005-2-28 �����޸�ֻ���������
	//	ԭ����������ͨ�������������С����ֵ����������ֵ�ڸ÷�Χ���ȡֵ
	//	�����޸�Ϊ��
	//	ֻ����һ����ͨ������ֵ��max_atk����ԭ��С������min_atk���޸�Ϊ������ͨ���������²����� 
	//		ITEMDATA_MINATK,			//
	ITEMDATA_FIGHTERATK,
	ITEMDATA_GUNNERATK,
	ITEMDATA_ENERGYATK,
	ITEMDATA_EXP,
	//		ITEMDATA_LEVEL,					// ��Ʒ�ȼ�
	ITEMDATA_POINT,
	//		ITEMDATA_QUALITY,				// Ʒ�ʣ�������
	ITEMDATA_UNIDENT_BIM_REALTYPE,	// 2007.03.16 δ��������ģ����ʵ��TYPEֵ
	ITEMDATA_UNIDENT_BIM_REALSHAPE,	// 2007.03.16 δ��������ģ����ʵ��Shapeֵ
	
	/////////////////////////////////////
	ITEMDATA_INTIMACY=80,				//? for mount, NOTE: no this field
	
	// for sprite -- add by zlong 2003-12-05
	ITEMDATA_ATTRIB	= 91,
	ITEMDATA_GROWTH	= 92,
};

//��Ʒ��������ö�ٶ���
enum ITEM_IDENT
{
	_ITEM_STATUS_NOT_IDENT		= 1,		// δ���� 0x0001
	_ITEM_STATUS_CANNOT_REPAIR	= 2,		// �����޸� 0x0002
	_ITEM_STATUS_NEVER_DAMAGE	= 4,		// ����ĥ�� 0x0004
	_ITEM_STATUS_INSTANTTMPPACK	= 8,		// ��ʱ������ͼ��Ʒ�����Ƿ�����ʱ���е�������Ʒ 0x0000
	_ITEM_STATUS_PROP			= 16,		// ����0x0010
	_ITEM_STATUS_GROW			= 32,		// �ɳɳ�,0x0020
	_ITEM_STATUS_MONOPOLY		= 64,		// ��ռ(����������)0x0040
	_ITEM_STATUS_CANNOT_STORAGE	= 128,		// ���ɴ洢0x0080
	_ITEM_STATUS_CANNOT_SALE	= 256,		// ���ɳ���	0x0100
	_ITEM_STATUS_CANNOT_DROP_IN_DIE = 512,		// ���ɵ�����Ʒ(����������)0x0200		
	_ITEM_STATUS_UNDISPEAR_IN_MAP = 1024,	// �ڵ�ͼ�ϲ�����ʧ����Ʒ tcp 2007-4-15 add ��ս������������0x0400	
	_ITEM_STATUS_CANNOT_DISCARD = 2048,		// ���ɶ���	0x0800
	_ITEM_STATUS_RARITY			= 4096,		// ������Ʒ 0x1000
	_ITEM_STATUS_CHK_SUM_ITEM	= 8192,		// �������Ʒ 0x2000
	_ITEM_STATUS_TiMetal		= 16384,	// �ѺϽ� 0x4000
	_ITEM_STATUS_UNEXCHANGE		= 32768,	// ���ɽ��� 0x8000
     //add by ccw_xxx ��Ʒ�����⽻������
	 _ITEM_SPECIAL_MONOPOLY1 =     65536,  //65536
	 _ITEM_SPECIAL_MONOPOLY2 =     131072,  //65536 * 2
	 
	 //���·���������///////////////////////////////////////////////////
	 _ITEM_STATUS_FORBID_GNDAIR	= 131072,		// �ӵ����ͽ�ֹ�ضԿ� 0x20000
	 _ITEM_STATUS_FORBID_AIRGND	= 131072,		// �ӵ����ͽ�ֹ�նԵ�
	 _ITEM_STATUS_FORBID_AIRAIR	= 131072,		// �ӵ����ͽ�ֹ�նԿ�
	 _ITEM_STATUS_FORBID_UNIVERSE= 131072,		// �ӵ����ͽ�ֹ�����泡����ʹ��
	 _ITEM_STATUS_BLACKMARKET	= 131072,		// ����������򵽵���Ʒ��Ҫ��ԭʯ����
	_ITEM_STATUS_ADJUSTTOGETHER	= 131072,		// ֻ���ڵ���״̬��ʹ��

	_ITEM_USE0_TOUCH_SKILL = 0x40000,      // ʹ����Ʒ1 ��������
	_ITEM_USE1_TOUCH_SKILL = 0x80000,      // ʹ����Ʒ0 ��������
	_ITEM_USE2_TOUCH_SKILL = 0x100000,      // ʹ����Ʒ2 ��������
	_ITEM_REPEAT_TOUCH = 0x200000,      // �Ƿ��ظ�����
	_ITEM_REMOVE0_LAST_TOUCH = 0x400000,      // �Ƿ������Ʒ���һ��ʱ����
	_ITEM_REMOVE1_LAST_TOUCH = 0x800000,      // �Ƿ������Ʒ���һ��ʱ����
	_ITEM_REMOVE2_LAST_TOUCH = 0x1000000,      // �Ƿ������Ʒ���һ��ʱ����
	_ITEM_DIRECTNESS_USE_TOUCH = 0x2000000,      // ������ֱ��ʹ�õ���Ʒ
};

enum
{
	ITEM_USAGE_NONE = 0,
	ITEM_USAGE_SELF	= 1,
	ITEM_USAGE_SINGLE,
	ITEM_USAGE_GROUP,
};

//װ�����ö�ٶ���
enum
{
	EQUIPSORT_SHIELD				= 2,	// ��
	EQUIPSORT_WEAPON1HAND			= 4,	// ��������
	EQUIPSORT_WEAPON2HAND			= 3,	// ˫������
	EQUIPSORT_WEAPONPAIR			= 5,	// ������
	EQUIPSORT_EQUIP					= 7,	// װ��

};


// 4������ʱ�����壬�����Ǳ�ʾû��Ʒ
enum ITEM_QUALITY_DATA
{
	ITEM_QUALITY_DATA_NORMAL	= 5,	// ��Ʒ
	ITEM_QUALITY_DATA_GOOD		= 6,	// ��Ʒ
	ITEM_QUALITY_DATA_TOP		= 7,	// ��Ʒ
	ITEM_QUALITY_DATA_PERFECT	= 8,	// ��Ʒ
	ITEM_QUALITY_DATA_SUPERIOR	= 9,	// ��Ʒ
};

//��Ʒ����ö�ٶ���
enum NEWTYPE
{
	NEWTYPE_None=0,
	NEWTYPE_Thruster,					// �ƽ���
	NEWTYPE_Expend,						// ����Ʒ
	NEWTYPE_Weapon,						// ������
	NEWTYPE_Shield,						// ����
	NEWTYPE_UserHat,					// ñ�ӣ���ʦװ����ͷ
	NEWTYPE_UserCloth,					// �·�����ʦװ��������
	NEWTYPE_UserJacket,					// ����
	NEWTYPE_UserLeftHand,				// ���ָ���������ף���ʦװ��������
	NEWTYPE_UserRightHand,				// �ҽ�ָ���������ף���ʦװ��������
	NEWTYPE_UserShoes,					// Ь����ʦװ��
	NEWTYPE_UserNecklace,				// ����(����)����ʦװ��
	NEWTYPE_UserTwoHands,				// ��ʦװ����˫�֣�װ���������ϣ�����ͬʱռ������λ��
	NEWTYPE_Equipment,					// װ����
	NEWTYPE_TaskItem,					// ������Ʒ
	NEWTYPE_Gem,						// ���顢����
	NEWTYPE_Status,						// ״̬��(�ⶾ����)
	NEWTYPE_Medicine,					// ҩƷ(����ҩ)
	NEWTYPE_Ammo,						// ��ҩ(��֧)
	NEWTYPE_Mine,						// ����
	NEWTYPE_SpiritHelmet,				// ͷ����������0711XXX,0721XXX��
	NEWTYPE_Spirit_Ring,					// ����������0712XXX,0722XXX��
	NEWTYPE_Spirit_Necklace,				// ������������0713XXX,0723XXX��
	NEWTYPE_Spirit_Jacket,				// ���ף�������188XXXX��
	NEWTYPE_Spirit_Mount,				// ���������36XXXXX��
	NEWTYPE_Weapon1Hand,				// ��������
	NEWTYPE_Weapon2Hand,				// ˫������
	NEWTYPE_WeaponPair,					// ������
	NEWTYPE_Spirit_Coat,			// ����װ��
	NEWTYPE_Spirit_Shoes,				// ����װ��
	NEWTYPE_Weapon1Hand1Shoulder,		// ���ֵ�������
	NEWTYPE_Weapon2Hand1Shoulder,		// ˫�ֵ�������
	NEWTYPE_Weapon2Hand2Shoulder,		// ˫��˫������
	NEWTYPE_EquipEnable,				// ��װ������Ʒ
	NEWTYPE_EatEnable,					// �ɳԵ���Ʒ
	NEWTYPE_InstantMapItem,				// ��װ������Ʒ
	NEWTYPE_ShoulderEngaged,			// ռ�ü�λ�õ�װ���������п���װ�������ϣ���Ҳռ�ü��λ��
	NEWTYPE_LeftHandEngaged,			// ռ������λ�õ�װ���������п���װ���������ϣ���Ҳռ�����ֵ�λ��
	NEWTYPE_EnPack,						// EN��
	NEWTYPE_Blueprint,					// �������ͼ
	NEWTYPE_HeadLoop,					// ͷ����·
	NEWTYPE_AmplifierChip,				// ������оƬ
	NEWTYPE_Engine,						// ������
	NEWTYPE_Amplifier,					// ������
	NEWTYPE_BackPackItem,				// ������Ʒ
	NEWTYPE_EnergyGenerator,			// ������������ 906
	NEWTYPE_OtherChip,					// ��������оƬ 907
	NEWTYPE_SpiritHpGenerator,			// ����HP����ģ�� 908
	NEWTYPE_AbsorbEnergyShield,			// �����������Ķ���
	NEWTYPE_EngineRoom,					// �ɷ�����յ���Ʒ
	NEWTYPE_Human,						// �������Ʒ
	NEWTYPE_UnequipDisable,				// ����ж�ص�װ��
	NEWTYPE_EquipOnlyOne,				// ֻ��ͬʱװ��һ��(�ڻ�����)
	NEWTYPE_SubTypeEquipOnlyOne,		// ֻ��ͬʱװ��ͬһ�������Ʒһ��(�ڻ�����)(�������ͷ����·)
	NEWTYPE_RandomShape,				// ����ʱ���������
	NEWTYPE_EquipmentChip,				// ��׼оƬ
	NEWTYPE_HasFettings,				// ����Ƕ������оƬ
	NEWTYPE_Ore,						// ��ʯ
	NEWTYPE_Reel,						// ����
	NEWTYPE_IdentReel,					// ��������
	NEWTYPE_PickMine,					// �ɿ󹤾�
	NEWTYPE_SpiritOuterEquipment,		// �����ⲿװ��
	NWETYPE_SkillBookItem,				// ��������Ʒ
	NEWTYPE_ChgLookface,				// ��ͷ������Ʒ,�Զ�����action����Ʒ
	NEWTYPE_NeedShape,					// �Ƿ���Ҫ����λ���ж�
	NEWTYPE_BuildInModule,				// ��������ģ��(����ģ��) 909
	NEWTYPE_ExpBall,					// ������
	NEWTYPE_AddLevStone,				// װ��׷��ԭʯ
	NEWTYPE_AddLevEquip,				// ��׷��װ��		
	NEWTYPE_Symbol,						// ���͹�����				
	NEWTYPE_ChipDefenceShift,			// 90700001���������ת��װ��		
	NEWTYPE_ChipAutoAttack,				// 90700011���Զ�����װ��
	NEWTYPE_Musket,						// ��ǹ��
	NEWTYPE_VirtualSpace,				// ��ռ���չ�� Ŀǰ�ݶ�Ϊ��Ϊ3�࣬ÿ�඼��5�ֵ�Ʒ�ʣ�����Ϸ�й���15����ռ���չ�ա���ƷID��51000205~51000229��
	NEWTYPE_Bow,					    // ����
	NEWTYPE_ShotGun	,					// ɢ��ǹ
	NEWTYPE_HandGun,					// ��ǹ
	NEWTYPE_FlameThrowerGun,			// ����ǹ
	NEWTYPE_Spear,						// ì
	NEWTYPE_ReapHook,					// ��
	NEWTYPE_BroadSword,					// ��
	NEWTYPE_Pala_Spear,					// ��ǹ��������0390XXX��
	NEWTYPE_Sword,						//��
	NEWTYPE_Harmer,						//��
	NEWTYPE_Axe,						//��ͷ
	NEWTYPE_Stick,						//��

	NEWTYPE_MachineSaw,					//���	
	NEWTYPE_MachineStick,				//���
	NEWTYPE_FireExtinguisher,			//�����
	NEWTYPE_FlameThrower,				//�����

	NEWTYPE_SnipeGun,					// �ѻ�ǹ	
	NEWTYPE_IceWeapon,					// ������			
	NEWTYPE_ShakeWeapon,				// ����					
	NEWTYPE_RMBEffectChatItem,			// ��ֵ����Ч����Ʒ
	NEWTYPE_SpecialShotGun_Ammo,		// ɢ��ǹ�����ӵ�
	NEWTYPE_ShotGun_Ammo,			    // ɢ��ǹ�ӵ�
	NEWTYPE_HandGun_Ammo,				// ��ǹ�ӵ�
	NEWTYPE_SpecialHandGun_Ammo,		// ��ǹ�����ӵ�
	NEWTYPE_SpecialMusketGun_Ammo,		// ��ǹ�����ӵ�		
	NEWTYPE_MusketGun_Ammo,				// ��ǹ�ӵ�	
	NEWTYPE_FreezeGun,
	NEWTYPE_NearWarWeapon,				// ��ս����
	NEWTYPE_EnergyGeneratorAccelerate,  // �������������ظ�������
	NEWTYPE_Can_UpQuality,				// �ɸ�����Ʒ
    NEWTYPE_Can_DownLevelEquiptment,	// �ɽ���װ��
	NEWTYPE_Can_UpLevelEquiptment,		// ������װ��
	NEWTYPE_Can_MakeHoleEquipByUseItem,	// ��ʹ��ĳ��Ʒ���п�����װ��
	NEWTYPE_Can_MakeHoleEquipByNpc,		// ��ͨ��NPC�����п�����װ��
	NEWTYPE_ModelLevUpGradeItem,		// �����ͼ�������Ʒ
	NEWTYPE_Crystal,					// ˮ��
	NEWTYPE_Crystal0,					// ˮ��I
	NEWTYPE_Crystal1,					// ˮ��II
	NEWTYPE_Crystal2,					// ˮ��III
	NEWTYPE_Spirit_Color_Item,			// ����Ⱦɫ��2007-1-22 tcp add ���廻ɫ��Ʒ����
	NEWTYPE_Gem_ItemEx,					// 2007.02.13 Ϊ����itemex�� 51000801-51000899
	NEWTYPE_WEAPONSKILL_BOOK,			// ���������ȼ�����
	NEWTYPE_SPIRITSKILL_BOOK,			// ���������ȼ�����
	NEWTYPE_MAGICSKILL_BOOK,			// ħ�������ȼ�����
	NEWTYPE_SPIRITSKILL_USEIDEA,			// ����ٿصȼ�ʹ���ĵ�
	NEWTYPE_ExpBall_Special,			// ���ƾ�����
	NEWTYPE_Drop_Disappear,				// 2007.03.26 ����������ʧ����Ʒ����
	NEWTYPE_Trump,						// ����
	NEWTYPE_Trump_Fixed,				// �̶��ͷ���
	NEWTYPE_Trump_Change,				// �仯�ͷ���
	NEWTYPE_ExpBall_DoubleEffect,		// ���������˫��Ч��
	NEWTYPE_SynWar_Reborn_Medicine,		// ����ս����ҩ
	NEWTYPE_Cannon_Reborn_Medicine,		// �����ڸ���ҩ
	NEWTYPE_ExpBall_SkillUp,			// ͨ�ü��ܾ���ֵ��
	NEWTYPE_Guard_Equip,				// ����װ��
	NEWTYPE_Guard_Equip_Compound,		// ����װ���ϳɲ���
	NEWTYPE_Guard_Equip_Stone,			// ����װ����������
	NEWTYPE_Guard_Equip_Common_Stone,	// ����װ������ͨ������
	NEWTYPE_Guard_Equip_Enhanced_Stone,	// ����װ����ǿЧ������
	NEWTYPE_Guard,						// ����
	NEWTYPE_Marry_Jacket,				// ��������װ
	NEWTYPE_Guard_Jacket,               //��������
	NEWTYPE_ExpBall_Package,			// ����ֵ�����
	NEWTYPE_BEFORE_MAKE_BROTHER,        // ��������Ʒ
	NEWTYPE_AFTER_MAKE_BROTHER,			// �����Ʒ
	NEWTYPE_GUARD_HAIR,					// ��������
	NEWTYPE_GIRL_AVOID_MEMSES,			//���ڵ���
	NEWTYPE_GUARD_OPENTRUMPSKILL,		//���������ؼ������Ʒ
	NEWTYPE_HAIR,           
	NEWTYPE_STEED_STYLE_EQUIP,          // ս�����װ�� 
	NEWTYPE_TRUCK,
	NEWTYPE_TEAMSKILL_BOOK,			    // ��Ӽ�����
	NEWTYPE_USER_LEG,					// ����
	NEWTYPE_USER_WAISTBAND,		        // ������������7X4XXX��
	NEWTYPE_USER_ARMGUARD,		        // ���֣�������7X5XXX��
	NEWTYPE_USER_FINGER_RING,		    // ��ָ��������7X6XXX��
	NEWTYPE_BOW,                        // ����
	NEWTYPE_Arrow_Ammo,				    // ��ʸ
	NEWTYPE_SpecialArrow_Ammo,		    // �����ʸ
	NEWTYPE_Gun,						// ǹ֧
	NEWTYPE_Skill_With_Cool,            // ʹ�ú󴥷����ܵ���Ʒ
	NEWTYPE_BulletProofVest,            // ������
};


enum STEED_STYLE_EQUIP				// ս�����װ��   horse
{	
	STEED_STYLE_EQUIP_NONE      = 0,
	STEED_STYLE_EQUIP_SMOCK		= 1,	// ս�������
	STEED_STYLE_EQUIP_SHIELD	= 2, 	// ս��Ļ���
	STEED_STYLE_EQUIP_SADDLE	= 3,	// ս����� 
	STEED_STYLE_EQUIP_PENDANT 	= 4,	// ս��ĹҼ�
};

enum ITEM_OPERATER_TYPE
{
	ITEM_OPERATER_TYPE_NONE = 0,
	ITEM_OPERATER_TYPE_SELL_TO_NPC_SHOP,			//������Ʒ����������NPC�̵���
	ITEM_OPERATER_TYPE_EXCAHNGE_TO_ADDLEV1,			//������Ʒ���������+1��Ʒ�һ�       
	ITEM_OPERATER_TYPE_DROP_TO_GROUND,				//������Ʒ��������
	ITEM_OPERATER_TYPE_MICRO_DEC_SHAPE_SIZE,		//������Ʒ���ɽ�����΢
	ITEM_OPERATER_TYPE_ADD_LEV_ITEM,				//������Ʒ������Ϊװ������װ��׷��
	ITEM_OPERATER_TYPE_COMBIND_SECOND_ITEM,			//������Ʒ�����ģ�������Ϊ�����Ľ��кϳ�
	ITEM_OPERATER_TYPE_USEABLE,						//������Ʒ��������Ҽ�ʹ�ã�����չװ�á����˾�У����µ��Ҽ����ʹ�ú�ɾ������Ʒ
	
	ITEM_OPERATER_TYPE_USE_TO_UPDATE_LEV = ITEM_OPERATER_TYPE_USEABLE,			//������ʹ��������
	ITEM_OPERATER_TYPE_USE_TO_UPDATE_QUALITY = ITEM_OPERATER_TYPE_USEABLE,		//������ʹ��������
	ITEM_OPERATER_TYPE_USE_TO_EMBED_GEM,			//������ʹ������Ƕ
	ITEM_OPERATER_TYPE_USE_TO_MICRO_DEC_SHAPE_SIZE,	//������ʹ������΢

	ITEM_OPERATER_TYPE_UNEMBED_GEM,					//������ж������Ƕ�ı�ʯ
	ITEM_OPERATER_TYPE_USE_TO_ADD_NIMBUS,			//�������������ӻ�������ֵ			
	ITEM_OPERATER_TYPE_DROP_WHEN_DIE,				//���ﱻɱ��ʱ��������Ʒ����ӱ�����װ�����е���
	ITEM_OPERATER_TYPE_MAKE_BLOODBOND,				//������Ʒ������ǩ��װ��������ӡ
	ITEM_OPERATER_TYPE_EQUIP_INTO_ENGINEE_ROOM,		//����ͻ�������ڿ���״̬�£�������װ��
	ITEM_OPERATER_TYPE_502ACTION_DEL_ITEM,			//ִ��502ɾ����Ʒ��actionʱ������ɾ������ɾ�������Ŀ�����Ʒ��ֱ��ѡ��ɾ���ǿ�����Ʒ��������Ʒ
	ITEM_OPERATER_TYPE_EXCHANGE,					//����			
	ITEM_OPERATER_TYPE_BOOTH,						//��̯				
	ITEM_OPERATER_TYPE_EQUIP,						//װ��
};

//��ǶоƬ
enum CHIP_EMB_MASK
{
	CHIP_EMB_MASK_WEAPON	= 1,	//��ʾ������Ƕ������
	CHIP_EMB_MASK_HELMET	= 2,	//��ʾ������Ƕ��ͷ��
	CHIP_EMB_MASK_NECKLACE	= 4,	//��ʾ������Ƕ������
	CHIP_EMB_MASK_RING		= 8,	//��ʾ������Ƕ������
	CHIP_EMB_MASK_COAT		= 16,	//��ʾ������Ƕ���·�
	CHIP_EMB_MASK_SHOES		= 32,	//��ʾ������Ƕ��Ь��	
	CHIP_EMB_MASK_TRUMP		= 256	//��ʾ������Ƕ����������Ʒ����Ʒid��Χ��90010000~90089999��
};

//װ�����Ѫ��
enum 
{ 
	BLOOD_BOND_STATE			   = 0x0001,				  //ǩ�����Ѫ��״̬
	BLOOD_BOND_WAITFOR_CLEAR_STATE = 0x0002, //���Ѫ�������״̬	
};


/****************����ר����Դ�ĵ������**tcp2007-1-9 add begin**************/
enum STONE_TYPE
{
	STONE_TYPE_I,
	STONE_TYPE_II,
	STONE_TYPE_III,		
};

//��Ʒ׷��ö�ٶ���
enum ITEMADDITIONDATA
{
	ITEMADDITIONDATA_ID,
	ITEMADDITIONDATA_TYPEID,
	ITEMADDITIONDATA_LEVEL,
	ITEMADDITIONDATA_LIFE,
	ITEMADDITIONDATA_SHORT_ATK_MAX,//ITEMADDITIONDATA_ATTACK_MAX,
	ITEMADDITIONDATA_SHORT_ATK_MIN,//ITEMADDITIONDATA_ATTACK_MIN,
	ITEMADDITIONDATA_SHORT_DEF,//ITEMADDITIONDATA_DEFENCE,
	ITEMADDITIONDATA_LONG_ATK_MAX,//ITEMADDITIONDATA_DEFENCE_MAX,
	ITEMADDITIONDATA_LONG_ATK_MIN,//ITEMADDITIONDATA_DEFENCE_PERCENT,
	ITEMADDITIONDATA_LONG_DEF,//ITEMADDITIONDATA_MAX_EN,
	ITEMADDITIONDATA_MANA,//ITEMADDITIONDATA_CHARGE_EN,
	ITEMADDITIONDATA_MANA_RE,//ITEMADDITIONDATA_MAX_POWER,
	ITEMADDITIONDATA_CHARGE_POWER,
	ITEMADDITIONDATA_MAX_RANGE,
	ITEMADDITIONDATA_NICETY,
	ITEMADDITIONDATA_DODGE,
	ITEMADDITIONDATA_PACK_SIZE,
};


enum SKILLDATA
{
	SKILLDATA_BEGIN_ = 0,			
	SKILLDATA_ID	 = 0,
	SKILLDATA_OWNERID,
	SKILLDATA_MAIN,	SKILLDATA_ITEMTYPE		= SKILLDATA_MAIN,		// 6λ��(MMMM LL = magic(type) * 100 + level) | 7λ��(ITEMTYPE)
	SKILLDATA_SUB1,	SKILLDATA_WEAPON_ACTION = SKILLDATA_SUB1,		// �ӵ�����		// (MMMM LL = magic(type) * 100 + level)
	SKILLDATA_SUB2, 												// (MMMM LL = magic(type) * 100 + level)
	SKILLDATA_SUB3,													// ...
	SKILLDATA_HOTKEY,												// ���津���ȼ�
	SKILLDATA_WEAPONPOS,											// ����λ��
	SKILLDATA_OWNERTYPE,											// 1:USER, 5:SPIRIT
	SKILLDATA_END_,			
};

// //��ʬ���� ������ ���Զ��Լ�ʹ�� ����Ҫ��Ŀ�� �Ե�ʹ�� ��ѡ���ѷ�����ʹ��
enum { TARGET_EMENY = 0, TARGET_SELF=1, TARGET_NONE = 2, TARGET_TERRAIN = 4, TARGET_FRIEND = 8};
//����  ֱ��range width��Ч  Բ��range��Ч  ����range width��Ч ���ӹ���
enum { MULTI_NONE = 0, MULTI_LINE, MULTI_CIRCLE, MULTI_FAN, MULTI_TEAM, MULTI_CIRQUE, MULTI_RHOMBUS, MULTI_SCREEN};//����Բ�������Σ�ȫ��
enum IMMUNITY_TYPE
{
	IMMUNITY_NONE,
	IMMUNITY_ALLY		= 0x1 << 0,
	IMMUNITY_ENEMY		= 0x1 << 1,
	IMMUNITY_SELF		= 0x1 << 2,
};

enum { WOUND_MODE_NONE, WOUND_MODE_LIFE, WOUND_MODE_XP, };
enum { KILL_MODE_NONE, KILL_MODE_LIFE, KILL_MODE_XP, };


enum { AIR_MODE_NONE, AIR_MODE_LAND_AIR, AIR_MODE_AIR_LAND, AIR_MODE_AIR_AIR, };
enum { CLASSILY_NONE, CLASSILY_MAIN, CLASSILY_ASSISTANCE, };
enum { XP_MODE_NONE, XP_MODE_MULTI, XP_MODE_STATUS };
enum { NOT_AUTO_ATTACK=0, AUTO_ATTACK=1, AUTO_ATTACK_EQUIPMENT=2,AUTO_RAND_ATTACK=4};


enum SKILLSUIT
{
	SKILLSUIT_BEGIN,		// no use

	SKILLSUIT_ID	=	SKILLSUIT_BEGIN,

	//��ʬ�ع����룬����Ҫ��SKILLSUIT����Ѫ��������Ƶ���ʬ������
	// range
	SKILLSUIT_DISTANCE,				// SKILLSUIT_ADJUST_DISTANCE,
	SKILLSUIT_RANGE,				// �뾶
	SKILLSUIT_WIDTH,				// ֱ�ߵĿ�Ȼ����εĽǶ�

	// sort
	SKILLSUIT_SORT,
	SKILLSUIT_CRIME,
	SKILLSUIT_PASSIVE,				// ��������
	SKILLSUIT_GROUND,
	SKILLSUIT_MULTIMODE,

	// condition | expend
	SKILLSUIT_EXPEND_MANA,		   //���ĵ�ħ��ֵ

	// param
	SKILLSUIT_IMMUNITY_MODE,		// enum { IMMUNITY_NONE, IMMUNITY_ALLY, IMMUNITY_ENEMY, IMMUNITY_SELF, };
	SKILLSUIT_DELAY_MS,				//��ȴʱ��
	SKILLSUIT_STEP_SECS,			//
	SKILLSUIT_ACTION_TIMES,
	SKILLSUIT_POWER,				
	SKILLSUIT_DATA,
	SKILLSUIT_PERCENT,
	SKILLSUIT_STATUS,
	SKILLSUIT_STATUS_CHANCE,
	SKILLSUIT_STATUS_TIME,
	SKILLSUIT_ATTACK,
	SKILLSUIT_ACTION,
	SKILLSUIT_TARGET,
	SKILLSUIT_NEED_WEAPON,
	SKILLSUIT_PART_PERCENT1,
	SKILLSUIT_PART_PERCENT2,
	SKILLSUIT_HEAD_PERCENT,
	SKILLSUIT_STAND_TIME,
	SKILLSUIT_TARGET_DISTINCT,
	SKILLSUIT_SELF_DISTINCT,
	SKILLSUIT_NAME,
	SKILLSUIT_FIRE_TYPE,

//	// end flag //////////////////////
	SKILLSUIT_ALL,		// no use

	//��Ѫ��ԭ���붨��
	// sort
//	SKILLSUIT_CRIME,				// ���Ի��Ƕ��Լ��ܱ�־�����Բ��˶����Ѫ����ֵΪ1�������ԣ�Ϊ0��������
//	SKILLSUIT_GROUND,				// �Ƿ��Чħ��
	//SKILLSUIT_PASSIVE,			// ��������
// 	SKILLSUIT_TARGET,				// 

	// range
//	SKILLSUIT_MULTIMODE,			// enum { MULTI_NONE = 0, MULTI_LINE, MULTI_CIRCLE, MULTI_FAN, MULTI_TEAM, MULTI_CIRQUE, MULTI_RHOMBUS, MULTI_SCREEN };
//	SKILLSUIT_DISTANCE,				// SKILLSUIT_ADJUST_DISTANCE,
//	SKILLSUIT_RANGE,				// �뾶
// 	SKILLSUIT_WIDTH,				// ֱ�ߵĿ�Ȼ����εĽǶ�
// 	SKILLSUIT_ANIMOSITY,
	// time control
	SKILLSUIT_INTONE,
	SKILLSUIT_DELAY,
	SKILLSUIT_DELAYCHANGSKILLSUIT, // ��ͬ������ID��ʽ֮���ʱ����

	// condition | expend
// 	SKILLSUIT_NEED_WEAPON,
	SKILLSUIT_NEED_AMMO,
	SKILLSUIT_EXPEND_LIFE,         //���ĵ�����ֵ
//	SKILLSUIT_EXPEND_MANA,		   //���ĵ�ħ��ֵ
	SKILLSUIT_EXPEND_FUEL,		   //���ĵ�����
	SKILLSUIT_EXPEND_AMMO,		   //���ĵĵ�ҩ����
//	SKILLSUIT_EXPEND_ENERGY,	   //���ĵľ���
	SKILLSUIT_REQ_CAMP,			   //ְҵҪ��
	SKILLSUIT_REQ_LEV,			   //�ȼ�Ҫ��
	SKILLSUIT_LHANDEQUIP,			// ����װ��Ҫ��
	SKILLSUIT_CONDITION,			// ����Ҫ�󣬶����Ʊ�ʶ��0��ʾ������1��ʾ�����״̬��10��ʾ���״̬
//	SKILLSUIT_REQ_TEAM_ROLE,		// �����ɫ����

// 	// param
// 	SKILLSUIT_IMMUNITY_MODE,		// enum { IMMUNITY_NONE, IMMUNITY_ALLY, IMMUNITY_ENEMY, IMMUNITY_SELF, };
	SKILLSUIT_FORBIDATKTYPE,		//256�������ͽ�ֹ�ضԿ�	512�������ͽ�ֹ�նԵ� 1024�������ͽ�ֹ�նԿ�  2048�������ͽ�ֹ�����泡����ʹ��

	// special effect
// 	SKILLSUIT_RECRUIT_ENABLE,
// 	SKILLSUIT_RECRUIT_POWER,      //Ѫ��

	//����һ��
	SKILLSUIT_DOUBLE_ENABLE,      
	SKILLSUIT_DOUBLE_PERCENT,    //������
	SKILLSUIT_DOUBLE_POWER,

	SKILLSUIT_MORTAL_ENABLE,		// һ����ɱ
	SKILLSUIT_MORTAL_PERCENT,
	SKILLSUIT_MORTAL_POWER,				
	SKILLSUIT_MORTAL_MODE,			//ɱ����ࣨ1Ϊ����ɱ��2Ϊ����ɱ��
	SKILLSUIT_MORTAL_DATA,          //ɱ��Ŀ������ָ����������200Ϊ200%��

	SKILLSUIT_FINAL_ENABLE,			// �սἼ
	SKILLSUIT_FINAL_PERCENT,		// �սἼ��������
	SKILLSUIT_FINAL_DATA,			// �սἼ2 ����������������
	SKILLSUIT_FINAL_POWER,			// �սἼ2 �˺���ֵ
	SKILLSUIT_FINAL_MODE,			// mode=0, �սἼ   mode=1,�սἼ2

	SKILLSUIT_EXTREMITY_ENABLE,		// ������
	SKILLSUIT_EXTREMITY_PERCENT,	// ��ǰLIFE�İٷֱ�
	SKILLSUIT_EXTREMITY_POWER,

	SKILLSUIT_STATUS_BEGIN,
	SKILLSUIT_STATUS_END	= SKILLSUIT_STATUS_BEGIN + MAX_SKILLSIZE,
	SKILLSUIT_STATUS_POWER_BEGIN = SKILLSUIT_STATUS_BEGIN + MAX_SKILLSIZE,
	// ...
	SKILLSUIT_STATUS_SECS_BEGIN = SKILLSUIT_STATUS_POWER_BEGIN+ MAX_SKILLSIZE,
	// ...
	SKILLSUIT_STATUS_TIMES_BEGIN = SKILLSUIT_STATUS_SECS_BEGIN+ MAX_SKILLSIZE,			// 0: for once status (no more status)
	// ...
	SKILLSUIT_STATUS_PERCENT_BEGIN = SKILLSUIT_STATUS_TIMES_BEGIN+ MAX_SKILLSIZE,
	// ...
	SKILLSUIT_STATUS_NPARAM_BEGIN	= SKILLSUIT_STATUS_PERCENT_BEGIN + MAX_SKILLSIZE,
	// ...
	SKILLSUIT_STATUS_WPARAM_BEGIN	= SKILLSUIT_STATUS_NPARAM_BEGIN + MAX_SKILLSIZE,
	// ...
	SKILLSUIT_STATUS_ALL_END = SKILLSUIT_STATUS_WPARAM_BEGIN+ MAX_SKILLSIZE,

	SKILLSUIT_EXPLODE_ENABLE	=	SKILLSUIT_STATUS_ALL_END,
	SKILLSUIT_EXPLODE_RANGE,				// ������ը(ը�Է�)
	SKILLSUIT_EXPLODE_POWER,

	SKILLSUIT_DESTROY_ENABLE,				// װ���ƻ�(����Ϊ��Ѫ)
	SKILLSUIT_DESTROY_PERCENT,				// �ƻ�����
	SKILLSUIT_DESTROY_POS,
	SKILLSUIT_DESTROY_POWER,
	SKILLSUIT_DESTROY_DATA,					// �𻵼��ʵ���
	SKILLSUIT_DESTROY_MODE,					// mode=0, װ���ƻ�  mode=1, װ����

	SKILLSUIT_LOOP_ENABLE,
	//SKILLSUIT_LOOP_PERCENT,
	//SKILLSUIT_LOOP_TIMES,

	SKILLSUIT_STEAL_ENABLE,
	SKILLSUIT_STEAL_PERCENT,

	SKILLSUIT_BEATBACK_ENABLE,
	SKILLSUIT_BEATBACK_PERCENT,
	SKILLSUIT_BEATBACK_DISTANCE,

	SKILLSUIT_SELFBACK_ENABLE,
	SKILLSUIT_SELFBACK_PERCENT,
	SKILLSUIT_SELFBACK_DISTANCE,

	SKILLSUIT_PK_BEATBACK_ENABLE,
	SKILLSUIT_PK_BEATBACK_DISTANCE,

	SKILLSUIT_AIR_MODE,				// enum { AIR_MODE_NONE, AIR_MODE_LAND_AIR, AIR_MODE_AIR_LAND, AIR_MODE_AIR_AIR, };
	SKILLSUIT_AIR_POWER,

	SKILLSUIT_WOUND_MODE,
	SKILLSUIT_WOUND_POWER,

	SKILLSUIT_KILL_MODE,
	SKILLSUIT_KILL_POWER,

	SKILLSUIT_XP_MODE,

	SKILLSUIT_DROP_MAPITEM_ENABLE,
	SKILLSUIT_DROP_MAPITEM_PERCENT,
	SKILLSUIT_DROP_MONEY_ENABLE,
	SKILLSUIT_DROP_MONEY_PERCENT,
	SKILLSUIT_DROP_STONE_ENABLE,
	SKILLSUIT_DROP_STONE_PERCENT,
	SKILLSUIT_DROP_EXP_ENABLE,
	SKILLSUIT_DROP_EXP_PERCENT,
	
	SKILLSUIT_ONRUSH_ENABLE,						// ͻ������ mode=0
	SKILLSUIT_ONRUSH_MODE,							// ��Խ���� mode=1

	// addition
	SKILLSUIT_DEFENCE_INVALID,
	SKILLSUIT_JUMPATTACK,			// bool

	SKILLSUIT_CANNONFIRECOVERCAST_ENABLE,			// �ڻ𸲸Ǽ���
	SKILLSUIT_CANNONFIRECOVERCAST_POWER,			// �ڻ𸲸Ǽ���,С��Χ�İ뾶�����ĵ��ɳ������ѡ����
	SKILLSUIT_CANNONFIRECOVERCAST_BLASTNUM,			// �ڻ𸲸Ǽ���,С��Χ�����ĸ���		
	SKILLSUIT_CANNONFIRECOVERCAST_RANGE,			// �ڻ𸲸Ǽ���,��Բ�η�Χ�İ뾶����Ŀ���Ϊ���ģ�		

	SKILLSUIT_CLOSETODIE_ENABLE,					// ��������
	SKILLSUIT_CLOSETODIE_ACTIVEADJUST,				// �������ܷ�������������ֵ����ֵΪ�ٷֱ�
	SKILLSUIT_CLOSETODIE_INJUREADJUST,				// ���������˺�������ֵ����ֵΪǧ�ֱ�

	SKILLSUIT_FUELERASER_ENABLE,					// ȼ��ɱ����
	SKILLSUIT_FUELERASER_FUELADJUST,				// ȼ��ɱ�����Ŀ���ƽ������ȼ�ϵİٷֱ�
	SKILLSUIT_FUELERASER_ACTIVERATE,				// ȼ��ɱ�𷢶����ʣ��ٷֱ���ֵ
	
	SKILLSUIT_ENERGYERASER_ENABLE,					// Enɱ��
	SKILLSUIT_ENERGYERASER_ACTIVEADJUST,			// Enɱ�����Ŀ�����En�İٷֱ�
	SKILLSUIT_ENERGYERASER_ACTIVERATE,				// Enɱ�𷢶����ʣ��ٷֱ���ֵ

	SKILLSUIT_BURNWALLAMMO_ENABLE,					// ȼ�յ�
	SKILLSUIT_BURNWALLAMMO_INJUREADJUST,			// ȼ�յ��˺������ٷֱ�
	SKILLSUIT_BURNWALLAMMO_TRAPTYPE,				// ȼ�յ���������

	SKILLSUIT_INJURESELF_ENABLE,					// ����
	SKILLSUIT_INJURESELF_ACTIVERATE,				// ���˷������ʣ��ٷֱ���ֵ
	SKILLSUIT_INJURESELF_ATKADJUST,					// ���˵��˺�����ǧ�ֱ�����Ϊ�˸������ֶ�ͳһ��������31000Ϊ100%��
	SKILLSUIT_INJURESELF_EXPENDLIFE,				// ���ˣ����ٵ�HPֵ�����֣�һ���Ǽ���һ������ֵ����һ���ǰ���������HP�ı��������١��ֶ�ֵ30000����Ϊһ������ֵ��30000����Ϊ�������磺30500��Ϊ50%��

	SKILLSUIT_BODYBLAST_ENABLE,						// ʬ��

	SKILLSUIT_RECOVERHP_ENABLE,						// HP�ظ�
	SKILLSUIT_RECOVERHP_DATA,						// HP�ظ���ֵ���߱��� ��30020����ظ���ǰ���HP��20%
	SKILLSUIT_RECOVERHP_MODE,						// HP�ظ�����

	SKILLSUIT_DRAWCLOSE_ENABLE,						// ����
	SKILLSUIT_DRAWCLOSE_ACTIVERATE,					// ���������ɹ���
	
	SKILLSUIT_ADDITIONINJURE_ENABLE,				// ���˺������˺�
	SKILLSUIT_ADDITIONINJURE_MODE,					// mode=0, ���˺�  mode=1, ���˺�
	SKILLSUIT_ADDITIONINJURE_PERCENT,				// �������ʣ�50Ϊ50%��
	SKILLSUIT_ADDITIONINJURE_DATA,					// ��ʽ�е�����ָ��

	SKILLSUIT_CAPTURE_ENABLE,						// ����
	SKILLSUIT_CAPTURE_PERCENT,						// ����ɹ���
	SKILLSUIT_CAPTURE_STEPSECOND,					// �������״̬ʱ��

	SKILLSUIT_REBORN_ENABLE,						// ����
	SKILLSUIT_REBORN_DATA,							// �����HP����
	
	SKILLSUIT_RETALIATEUPON_ENABLE,					// ����

	SKILLSUIT_SHIELDSKILL_ENABLE,					// �ܼ���
	SKILLSUIT_SHIELDSKILL_DATA,						// ������ֵ
	SKILLSUIT_SHIELDSKILL1_ENABLE,					// �ܼ���1
	SKILLSUIT_SHIELDSKILL1_DATA,					// ������ֵ1
	SKILLSUIT_SHIELDSKILL2_ENABLE,					// �ܼ���2
	SKILLSUIT_SHIELDSKILL2_DATA,					// ������ֵ2
	SKILLSUIT_SHIELDSKILL3_ENABLE,					// �ܼ���3
	SKILLSUIT_SHIELDSKILL3_DATA,					// ������ֵ3

	SKILLSUIT_SEARCHBODY_ENABLE,					// ����
	SKILLSUIT_SEARCHBODY_PERCENT,					// �ɹ�����
	
	SKILLSUIT_IMPACT_ENABLE,						// ײ��
	SKILLSUIT_IMPACT_POWER,							// ������ֵ
	
	SKILLSUIT_MINESWEEPING_ENABLE,					// ɨ��
	SKILLSUIT_MINESWEEPING_RANGE,					// ɨ�׷�Χ

	SKILLSUIT_SELFBLAST1_ENABLE,					// �Ա�1
	SKILLSUIT_SELFBLAST1_DATA,						// �Ա�1ָ��
	SKILLSUIT_SELFBLAST2_ENABLE,					// �Ա�2
	SKILLSUIT_SELFBLAST2_DATA,						// �Ա�2ָ��
	SKILLSUIT_SELFBLAST3_ENABLE,					// �Ա�3
	SKILLSUIT_SELFBLAST3_DATA,						// �Ա�3ָ��

	SKILLSUIT_INTERLINK_ENABLE,						// ����
	SKILLSUIT_INTERLINK_DATA,						// ������������
	SKILLSUIT_INTERLINKFORCE_ENABLE,				// ����������ǿ��һ����������
	SKILLSUIT_INTERLINKFORCE_POWER,
	SKILLSUIT_INTERLINKFAINT_ENABLE,				// �����������һ���μ���
	SKILLSUIT_INTERLINKEXTRA_DATA,					// �����������ӹ������� ���ӵĴ���ֵ
	
	SKILLSUIT_COUNTERSTRIKE_ENABLE,					// ����
	SKILLSUIT_COUNTERSTRIKE_POWER,					// ������������ֵ
	SKILLSUIT_COUNTERSTRIKE_DATA,					// ����������ָ��
	SKILLSUIT_COUNTERSTRIKE_PERCENT,
	SKILLSUIT_COUNTERSTRIKEFORCE_ENABLE,			// ��������������ʹ�ã���������
	SKILLSUIT_COUNTERSTRIKEFORCE_POWER,
	SKILLSUIT_COUNTERSTRIKELIGHT_ENABLE,			// ��������������ʹ�ã���������
	SKILLSUIT_COUNTERSTRIKELIGHT_DATA,
	
	SKILLSUIT_RETALIATEUPONCURSE_ENABLE,			// �������� ���� ������ܹ�������ʱ���˼��ܲ���Ч��
	SKILLSUIT_RETALIATEUPONCURSE_DATA,				// ����ָ��
	SKILLSUIT_RETALIATEUPONBLAST_ENABLE,			// �������� �Ա�  (����ܹ�������ʱ����Χ����)
	SKILLSUIT_RETALIATEUPONBLAST_DATA,
	
	SKILLSUIT_THROWENEMY_ENABLE,					// Ͷ��
	SKILLSUIT_THROWENEMY_DATA,
	SKILLSUIT_THROWENEMYDOUBLE_ENABLE,				// Ͷ����������һ��
	SKILLSUIT_THROWENEMYDOUBLE_PERCENT,				// Ͷ����������һ����������
	SKILLSUIT_THROWENEMYDOUBLE_POWER,				// Ͷ����������һ����ߵİٷֱȣ���200����200%

	SKILLSUIT_MULTISELECTENEMY_ENABLE,				// ��Ŀ��ָ��

	SKILLSUIT_FETCH_BURST_ENHANCE_CLASSILY,			// �ܻ걬״̬Ӱ������
	
	SKILLSUIT_CENTERINJURE_ENABLE,					// �����˺�
	SKILLSUIT_CENTERINJURE_DATA,

	SKILLSUIT_ENSKILLMASTER_ENABLE,					// ������En���ļ���
	SKILLSUIT_ENSKILLMASTER_DATA,
	SKILLSUIT_ENSKILLMASTER_POWER,

	SKILLSUIT_POISONRANGE_ENABLE,					// ����
	SKILLSUIT_POISONRANGE_POWER,
	SKILLSUIT_POISONRANGE_DATA,
	SKILLSUIT_POISONRANGE_SEC,
	SKILLSUIT_POISONRANGE_IMMUNITY,
	SKILLSUIT_POISONRANGEADD2_ENABLE,				// ������������2
	SKILLSUIT_POISONRANGEADD2_INJURERATE,
	SKILLSUIT_POISONRANGEADD3_ENABLE,				// ������������3
	SKILLSUIT_POISONRANGEADD3_INJURESELFRATE,
	SKILLSUIT_POISONRANGEADD3_INJURERATE,

	SKILLSUIT_REINFORCE_FROM_TEAM,					// �����֧Ԯ���������������ڣ�����ڣ�
	SKILLSUIT_REINFORCE_FROM_SELF,					// �Լ���֧Ԯ���������������ڣ�����ڣ�
	SKILLSUIT_REINFORCE_POWER,						// Ԯ���������ܹ�������
	SKILLSUIT_REINFORCE_DAMAGE,						// Ԯ�������������˺����ɴ����ߺͱ��������Լ��������ڣ�����ڣ��Ĳ����йأ���ͬ��һ��ļ����˺����㷽��

	SKILLSUIT_ADJUSTTOGETHER_ENABLE,				// ����

	SKILLSUIT_KILLLINEUP_ENABLE,					// ɱ��
	SKILLSUIT_KILLLINEUP_MODE,						// 1Ϊ����ɱ��2Ϊ����ɱ��
	SKILLSUIT_KILLLINEUP_SECOND,
	SKILLSUIT_KILLLINEUP_PERCENT,
	SKILLSUIT_KILLLINEUP_TARGETMAXAMOUNT,			// ɱ��ɹ���Ŀ���������
	SKILLSUIT_KILLLINEUP_TARGETAMOUNT,				// ɱ��״̬�£��Ѿ���������Ŀ����(��ʧЧʱ��ǰ����̬�仯��Ҳ�Ƿ���������)
	SKILLSUIT_KILLLINEUP_INJUREADJUST,				// ����ָ��
	SKILLSUIT_KILLLINEUP2_FAINT_ENABLE,				// ɱ����2�����һ����
	SKILLSUIT_KILLLINEUP3_POWER,
	
	SKILLSUIT_CRAZYFIGHTER_ENABLE,					// ��սʿ״̬
	SKILLSUIT_CRAZYFIGHTER_CANUSESKILL,				// ��սʿ״̬�£���������ʹ�õļ��ܱ�־
	SKILLSUIT_CRAZYFIGHTER_POWERUP,					// ���п�սʿ�¿����õļ�����������������
	SKILLSUIT_CRAZYFIGHTER_TIMEDATA,				// �����״̬����ʱ��
	SKILLSUIT_CRAZYFIGHTER_SKILLAMOUNT,				// ��սʿ״̬�£��Ҽ�������ʹ�ô���������
	SKILLSUIT_CRAZYFIGHTERADD1_ENABLE,				// ��սʿ �������� ���սʿ
	SKILLSUIT_CRAZYFIGHTERADD1_POWER,				// ���սʿ
	SKILLSUIT_CRAZYFIGHTERADD2_TIMEADD,				// �ӳ�ʱ��
	SKILLSUIT_CRAZYFIGHTERADD3_ENABLE,				
	SKILLSUIT_CRAZYFIGHTERADD3_HPRECOVER,
	SKILLSUIT_CRAZYFIGHTERADD4_ENABLE,
	SKILLSUIT_CRAZYFIGHTERADD4_TIMEADD,				// �ܻ��ӳ�ʱ��
	SKILLSUIT_CRAZYFIGHTERADD4_PERCENT,

	SKILLSUIT_DISTANCE_NOWEAPONEFFECT,				// ���ܼ�Ʒ��������Ӱ������־ 2006.10.13

	SKILLSUIT_HOTBURN_ENABLE,						// 2006.10.22 ��������
	SKILLSUIT_HOTBURN_PERCENT,						// ���ռ���percent
	SKILLSUIT_HOTBURN_POWER,						// ����ǿ��power
	SKILLSUIT_HOTBURN_ATTACK,						// �����¶ȵ�����attack
	SKILLSUIT_HOTBURN_HOTATK,						// �����˺�atk_hot
	
	SKILLSUIT_BAITMONSTER_ENABLE,					// 2007.02.02 ���չ���
	SKILLSUIT_BAITMONSTER_SECOND,					// ���ܳ���ʱ��
	SKILLSUIT_BAITMONSTER_PERCENT,					// �ɹ���
	SKILLSUIT_BAITMONSTER_RANGE,					// ���չ������Ч��Χ
	
	SKILLSUIT_SUDDEMOVENATTACK_ENABLE,				// 2007.03.19 ˲�ƹ�������
	
	SKILLSUIT_ICE_POWER,							// ����
	SKILLSUIT_SHAKE_POWER,							// ��
	SKILLSUIT_XPMAGIC_ACTION,						// xp���ܵ�ȼxpͬʱ������Action�ֶ�ֵ����Ӧ��action
	SKILLSUIT_TRANSLOOK,							// ���μ��ܵ�����look

	SKILLSUIT_FULLSCREEN_ATK_ENABLE,				// ȫ����ը����
	SKILLSUIT_FULLSCREEN_ATK_POWER,					// ȫ������ǿ��
	SKILLSUIT_FULLSCREEN_ATK_SORT,					// ��ͨȫ����ը����,����ȫ����ը����,����ȫ����ը����, ��ȫ����ը����

    SKILL_SPIRIT_TRANSFORM_SPIRIT_TYPE_ID,			// 2007.04.01 tcp add ����ϵͳ�ĵ�
	SKILLSUIT_SPIRIT_MODEL_LEV,						// 
// 	SKILLSUIT_POWER,
// 	SKILLSUIT_PERCENT,
// 	SKILLSUIT_STEP_SECS,
	SKILLSUIT_ACTIVETIMES,

	SKILLSUIT_CHAOS_ENABLE,								//ʹ����������״̬
	SKILLSUIT_CHAOS_RANGE,								//���ҹ�����Χ

	SKILLSUIT_SINGLEIMPACT_ENABLE,						//���˳������
	SKILLSUIT_SINGLEIMPACT_POWER,						//���˳�����ܹ�����
	SKILLSUIT_SINGLEIMPACT_PERCENT,						//����״̬�ļ���
	SKILLSUIT_SINGLEIMPACT_RANGE,						//���˳�������ķ�Χ
	SKILLSUIT_RECOVERY_ENABLE ,
	SKILLSUIT_RECOVERY_POWER,

	SKILLSUIT_TEAMIMPACT_ENABLE,						//��ӳ������
	SKILLSUIT_TEAMIMPACT_POWER,						//��ӳ�����ܹ�����
	SKILLSUIT_TEAMIMPACT_PERCENT,						//����״̬�ļ���
	SKILLSUIT_TEAMIMPACT_RANGE,						//��ӳ�������ķ�Χ
	
	SKILLSUIT_MAX_TARGET_NUM,		// ��¼Ⱥ�弼��ʹ��ʱ���������Զ��ٸ�Ŀ�����(0��ʾ���������ޣ����弼�ܸ��ֶβ�������)

	SKILLSUIT_DETACHTARGET_STATUS_EXIST,//���Ŀ��״̬
	SKILLSUIT_DETACHTARGET_STATUS,

	SKILLSUIT_DETACHSELF_STATUS_EXIST,//�������״̬
	SKILLSUIT_DETACHSELF_STATUS,

	SKILLSUIT_ATTACHSELF_STATUS_EXIST,//��������״̬
	SKILLSUIT_ATTACHSELF_STATUS,
	SKILLSUIT_ATTACHSELF_STATUS_CHANCE,
	SKILLSUIT_ATTACHSELF_STATUS_POWER,
	SKILLSUIT_ATTACHSELF_STATUS_SECS,
	SKILLSUIT_ATTACHSELF_STATUS_TIMES,
	SKILLSUIT_ATTACHSELF_STATUS_NPARAM,
	SKILLSUIT_ATTACHSELF_STATUS_WPARAM,

	SKILLSUIT_ATTACHTARGET_STATUS_EXIST,//����Ŀ��״̬
	SKILLSUIT_ATTACHTARGET_STATUS,
	SKILLSUIT_ATTACHTARGET_STATUS_CHANCE,
	SKILLSUIT_ATTACHTARGET_STATUS_POWER,
	SKILLSUIT_ATTACHTARGET_STATUS_SECS,
	SKILLSUIT_ATTACHTARGET_STATUS_TIMES,
	SKILLSUIT_ATTACHTARGET_STATUS_NPARAM,
	SKILLSUIT_ATTACHTARGET_STATUS_WPARAM,

	SKILLSUIT_ADJDAMG_FROM_STATUS,//״̬�����˺�
	SKILLSUIT_STATUSA,			//���ܶ���״̬����	
	SKILLSUIT_STATUSA_POWER,
	SKILLSUIT_STATUSA_DATA,
	SKILLSUIT_STATUSB,	
	SKILLSUIT_STATUSB_POWER,	
	SKILLSUIT_STATUSB_DATA,
	
	SKILLSUIT_CURSE_ENABLE,								//�����������״̬

	SKILLSUIT_CREATE_MAPDOMAIN_ENABLE,					//������ͼ������
	SKILLSUIT_CREATE_REGIONDOMAIN_ENABLE,				//��������������
	SKILLSUIT_CREATE_CONTROLDOMAIN_ENABLE,				//�ٿ�������
	SKILLSUIT_CREATE_DOMAIN_DATA,						//��ͬʱ������������

	SKILL_DOMAIN_ENABLE,							//�����ڼ����˺�
	SKILL_DOMAIN_POWER,							//�˺���������
	SKILL_DOMAIN_SECS,							//�����˺�����״̬����ʱ��
//
//	SKILL_DOMAIN_HP_ENABLE,										//ȫ��ͼȫԱHP����
//	SKILL_DOMAIN_HP_POWER,
//	SKILL_DOMAIN_HP_SECS,

	SKILLSUIT_CALL_ALTAR_ENABLE,						//�ٻ���̳
	SKILLSUIT_CALL_ALTAR_SECS,							//�ٻ���̳�ĳ���ʱ��
	SKILLSUIT_CALL_ALTAR_RANGE,							//��̳��Χ

	SKILLSUIT_DODGE_ENABLE,							//������

	SKILLSUIT_FLY_ENABLE,							//����
	SKILL_CATCH_MONSTER_ENABLE,						//ץ������
	SKILL_MONSTER_WORSHIP_ENABLE,					//ץ�������׼�
	SKILL_DOMAIN_FIELD_ADD_DAMAGE,					// ����		���ż��˺�
	SKILL_DOMAIN_MAP_TEAM_ADD_DAMAGE,					// ȫ��ͼ	������˺�  
	SKILL_DOMAIN_FIELD_NO_HP_RECOVER,					// ����		��ֹHp�ظ�

	SKILLSUIT_REGION_ADD_HP_ENABLE,						//����ΧȫԱHP���
	SKILLSUIT_REGION_ADD_HP_POWER,
	SKILLSUIT_REGION_ADD_HP_SECS,

	SKILLSUIT_WHOLEMAP_SYNDIACTE_ADD_EXP_ENABLE,						//ȫ��ͼ���Ӿ���ֵ���
	SKILLSUIT_WHOLEMAP_SYNDIACTE_ADD_EXP_POWER,
	SKILLSUIT_WHOLEMAP_SYNDIACTE_ADD_EXP_SECS,
	
// 	SKILLSUIT_WHOLEMAP_ADD_DAMAGE_ENABLE,						//ȫ��ͼȫԱ���˺����
// 	SKILLSUIT_WHOLEMAP_ADD_DAMAGE_POWER,
// 	SKILLSUIT_WHOLEMAP_ADD_DAMAGE_SECS,
	
	SKILLSUIT_WHOLEMAP_ADD_EXP_ENABLE,						//ȫ��ͼȫԱ����ֵ���
	SKILLSUIT_WHOLEMAP_ADD_EXP_POWER,
	SKILLSUIT_WHOLEMAP_ADD_EXP_SECS,
	
	SKILLSUIT_WHOLEMAP_ADD_DAMAGE_ENABLE,						//ȫ��ͼȫԱ���˺����
	SKILLSUIT_WHOLEMAP_ADD_DAMAGE_POWER,
	SKILLSUIT_WHOLEMAP_ADD_DAMAGE_SECS,
	
// 	SKILLSUIT_WHOLEMAP_ADD_EXP_ENABLE,						//ȫ��ͼȫԱ����ֵ���
// 	SKILLSUIT_WHOLEMAP_ADD_EXP_POWER,
// 	SKILLSUIT_WHOLEMAP_ADD_EXP_SECS,

	SKILL_DOMAIN_WHOLEMAP_FAMILY_INCDAMAGE_ENABLE,										//ȫ��ͼ������˺�
	SKILL_DOMAIN_WHOLEMAP_FAMILY_INCDAMAGE_POWER,
	SKILL_DOMAIN_WHOLEMAP_FAMILY_INCDAMAGE_SECS,
	
	SKILL_DOMAIN_FILDLD_NO_MOVE_ENABLE,										//�����ֹ˲��
	SKILL_DOMAIN_FILDLD_NO_MOVE_POWER,
	SKILL_DOMAIN_FILDLD_NO_MOVE_SECS,
	
	SKILL_DOMAIN_FIELD_DECDAMAGE_ENABLE,										//��������˺�
	SKILL_DOMAIN_FIELD_DECDAMAGE_POWER,
	SKILL_DOMAIN_FIELD_DECDAMAGE_SECS,
	
	SKILL_DOMAIN_FIELD_NO_JUMP_ENABLE,										//�����ֹ��Ծ
	SKILL_DOMAIN_FIELD_NO_JUMP_POWER,
	SKILL_DOMAIN_FIELD_NO_JUMP_SECS,
	
	SKILL_DOMAIN_WHOLEMAP_TEAMEXP_ENABLE,										//ȫ��ͼ���龭��ֵ
	SKILL_DOMAIN_WHOLEMAP_TEAMEXP_POWER,
	SKILL_DOMAIN_WHOLEMAP_TEAMEXP_SECS,
	
	SKILL_DOMAIN_WHOLEMAP_FAMILYEXP_ENABLE,										//ȫ��ͼ���徭��ֵ
	SKILL_DOMAIN_WHOLEMAP_FAMILYEXP_POWER,
	SKILL_DOMAIN_WHOLEMAP_FAMILYEXP_SECS,

	SKILL_DOMAIN_WHOLEMAP_TEAMINCDAMGE_ENABLE,										//ȫ��ͼ������˺�
	SKILL_DOMAIN_WHOLEMAP_TEAMINCDAMGE_POWER,
	SKILL_DOMAIN_WHOLEMAP_TEAMINCDAMGE_SECS,

	SKILL_DOMAIN_FIELD_INCDAMAGE_ENABLE,										//������˺�
	SKILL_DOMAIN_FIELD_INCDAMAGEDAMGE_POWER,
	SKILL_DOMAIN_FIELD_INCDAMAGEDAMGE_SECS,

	

	MAGICSORT_WHOLEMAP_DEC_DAMAGE_ENABLE,						
	MAGICSORT_WHOLEMAP_DEC_DAMAGE_POWER,
	MAGICSORT_WHOLEMAP_DEC_DAMAGE_SECS,

	MAGICSORT_DOMAIN_DEC_MAXHP_ENABLE,						
	MAGICSORT_DOMAIN_DEC_MAXHP_POWER,
	MAGICSORT_DOMAIN_DEC_MAXHP_SECS,

//ypn add
	SKILLSUIT_SANSTORM_ENABLE,					// ��ʥ�籩
// 	SKILLSUIT_SANSTORM_EXPEND_MANA,
// 	SKILLSUIT_SANSTORM_DELAY_MS,
	SKILLSUIT_SANSTORM_ATTACK,
//	SKILLSUIT_SANSTORM_RANGE,
//	SKILLSUIT_SANSTORM_STATUS,
//	SKILLSUIT_SANSTORM_STATUS_CHANCE,
//	SKILLSUIT_SANSTORM_POWER,

	SKILLSUIT_VELOCITY_SOUND_ENABLE,			// ���ٹ���
// 	SKILLSUIT_VELOCITY_SOUND_EXPEND_FUEL,
// 	SKILLSUIT_VELOCITY_SOUND_DELAY_MS,
// 	SKILLSUIT_VELOCITY_SOUND_DISTANCE,
	SKILLSUIT_VELOCITY_SOUND_ATTACK,

	SKILLSUIT_SOUL_LIGHTNING_ENABLE,			// �������
// 	SKILLSUIT_SOUL_LIGHTNING_EXPEND_MANA,
// 	SKILLSUIT_SOUL_LIGHTNING_DISTANCE,
// 	SKILLSUIT_SOUL_LIGHTNING_INTONE_MS,
// 	SKILLSUIT_SOUL_LIGHTNING_DELAY_MS,
//	SKILLSUIT_SOUL_LIGHTNING_STATUS,
//	SKILLSUIT_SOUL_LIGHTNING_STATUS_CHANCE,
//	SKILLSUIT_SOUL_LIGHTNING_RANGE,
	SKILLSUIT_SOUL_LIGHTNING_DATA,
	SKILLSUIT_SOUL_LIGHTNING_POWER,
//	SKILLSUIT_SOUL_LIGHTNING_STATUS_TIME,
//	SKILLSUIT_SOUL_LIGHTNING_STATUS_POWER,
	SKILLSUIT_SOUL_LIGHTNING_STATUS_DATA,

	SKILLSUIT_SAN_BEAT_ENABLE,					//��ʥ���
// 	SKILLSUIT_SAN_BEAT_EXPEND_MANA,
// 	SKILLSUIT_SAN_BEAT_DISTANCE,
// 	SKILLSUIT_SAN_BEAT_INTONE_MS,
// 	SKILLSUIT_SAN_BEAT_DELAY_MS,
//	SKILLSUIT_SAN_BEAT_STATUS,
//	SKILLSUIT_SAN_BEAT_STATUS_CHANCE,
	SKILLSUIT_SAN_BEAT_ATTACK,
	SKILLSUIT_SAN_BEAT_ATK_ENERGY,
//	SKILLSUIT_SAN_BEAT_STATUS_TIME,

	SKILLSUIT_BLOOD_SHAKE_ENABLE,				//��Ѫ���
	SKILLSUIT_BLOOD_SHAKE_ATTACK,
	SKILLSUIT_BLOOD_SHAKE_PERCENT,
//	SKILLSUIT_BLOOD_SHAKE_STATUS_CHANCE,
//	SKILLSUIT_BLOOD_SHAKE_STATUS_TIME,
	SKILLSUIT_BLOOD_SHAKE_STATUS_DATA,

	SKILLSUIT_SAN_SHIELD_BEAT_ENABLE,					//��ʥ�ܻ�
//	SKILLSUIT_SAN_SHIELD_BEAT_STATUS,
//	SKILLSUIT_SAN_SHIELD_BEAT_STATUS_CHANCE,
//	SKILLSUIT_SAN_SHIELD_BEAT_STATUS_TIME,
	SKILLSUIT_SAN_SHIELD_BEAT_SELF_STATUS,
	SKILLSUIT_SAN_SHIELD_BEAT_SELF_STATUS_CHANCE,
	SKILLSUIT_SAN_SHIELD_BEAT_SELF_STATUS_TIME,
	SKILLSUIT_SAN_SHIELD_BEAT_SELF_STATUS_POWER,
	SKILLSUIT_SAN_SHIELD_BEAT_SELF_STATUS_DATA,
	SKILLSUIT_SAN_SHIELD_BEAT_ATTACK,
	
	SKILLSUIT_REVENGE_SHIELD_ENABLE,			//����֮��
	SKILLSUIT_REVENGE_SHIELD_PERCENT,
	SKILLSUIT_REVENGE_SHIELD_MAX_TARGET_NUM,
	SKILLSUIT_REVENGE_SHIELD_STATUS_A,
	SKILLSUIT_REVENGE_SHIELD_STATUS_A_DATA1,
	SKILLSUIT_REVENGE_SHIELD_STATUS_A_DATA2,

	SKILLSUIT_GROUP_CURE_ENABLE,				//��������Ⱥ������
	SKILLSUIT_GROUP_CURE_STEP_SECS,
	SKILLSUIT_GROUP_CURE_ACTIVE_TIMES,
	SKILLSUIT_GROUP_CURE_POWER,

	SKILLSUIT_SINGLE_CURE_ENABLE,				//����������������
	SKILLSUIT_SINGLE_CURE_STEP_SECS,
	SKILLSUIT_SINGLE_CURE_ACTIVE_TIMES,
	SKILLSUIT_SINGLE_CURE_POWER,

//end ypn add
	
	// end flag //////////////////////
//	SKILLSUIT_ALL,		// no use
};

enum SPIRIT_POS_ENUM
{
	POS_MAINSPIRIT,
	POS_FLOATCANNON1,
	POS_FLOATCANNON2,
	POS_GENAKOO,
	POS_AUTO_FIND_FIT_SPIRIT,
	POS_NONE
};

enum
{
	IDENT_OK = true, 
	NO_COMBINE = false
};

enum MONSTERDATA
{
    MONSTERDATA_ID=0,					//����id
	MONSTERDATA_NAME,					//��������
	MONSTERDATA_BASE_ATTACK,			//��������
	MONSTERDATA_BASE_DEFENCE,			//��������
	MONSTERDATA_BASE_DEXTERITY,			//��������
	MONSTERDATA_BASE_LIFE,				//��������ֵ(1��ʱ�ļ�¼ֵ)
	MONSTERDATA_GROW_POINT,				//�ɳ���
	MONSTERDATA_LIFE_RISE,				//������
	MONSTERDATA_ATTACK_RATE,			//������	
    MONSTERDATA_DEFENCE_RATE,			//������
    MONSTERDATA_DEXTERITY_RATE,			//������
    MONSTERDATA_LOOK,					//����
    MONSTERDATA_CLASS,					//�������
    MONSTERDATA_INDEX_NUM,				//�������
    MONSTERDATA_HUE0,					//
    MONSTERDATA_SATURATION0,			//
    MONSTERDATA_BRIGHT0,				//
    MONSTERDATA_HUE1,					//
    MONSTERDATA_SATURATION1,			//
    MONSTERDATA_BRIGHT1,				//
    MONSTERDATA_HUE2,					//
    MONSTERDATA_SATURATION2,			//
    MONSTERDATA_BRIGHT2,				//

    MONSTERDATA_END
};

enum INTERACT
{	
    INTERACT_NONE =0, 
	INTERACT_STEAL, 
	INTERACT_ATTACK, 
	INTERACT_HEAL, 
	INTERACT_POISON, 
	INTERACT_ASSASSINATE,
	INTERACT_FREEZE,
	INTERACT_UNFREEZE,
	INTERACT_COURT,
	INTERACT_MARRY,
	INTERACT_DIVORCE,
	INTERACT_PRESENTMONEY,
	INTERACT_PRESENTITEM,
	INTERACT_SENDFLOWERS,
	INTERACT_KILL,
	INTERACT_JOINSYN,
	INTERACT_ACCEPTSYNMEMBER,
	INTERACT_KICKOUTSYNMEMBER,
	INTERACT_PRESENTPOWER,
	INTERACT_QUERYINFO,
	INTERACT_RUSHATK,
	INTERACT_MAGICATTACK = 21, 
	INTERACT_ABORTMAGIC,
	INTERACT_REFLECTWEAPON,
	INTERACT_BUMP,
	INTERACT_SHOOT = 25,
	INTERACT_REFLECTMAGIC,
	INTERACT_STATISTIC,
	INTERACT_TEAMSTATISTIC,
	INTERACT_TEAMMEMBERSTC,
	INTERACT_GETSTATISTIC,
	INTERACT_COUNTEMONEYCARD,
	INTERACT_GETEMONEYCARD,
	INTERACT_REQUESTBUSINESS,
	INTERACT_REVOKEBUSINESS,
	INTERACT_FORMALDAYS,
	INTERACT_MUSKETSHOOT = 34,
	INTERACT_ATTACK_FAIL     =    40,   // ����ʧ��
	INTERACT_MAGICATTACK_FAIL = 45, //ħ������ʧ��
	INTERACT_ATTACK_LOCK = 400,
	INTERACT_ATTACK_ENDLOCK = 401,

};

enum USER_APPLY 
{ 
    APPLY_NONE=0,
    APPLY_FRIEND,
    APPLY_MARRY,
    APPLY_TRADE,
    APPLY_TEAMAPPLY,
    APPLY_TEAMINVIT,
    APPLY_JOIN_SYN,
    APPLY_INVITE_JOIN_SYN,
    APPLY_ALLY_SYN,
    APPLY_TRADE_BUDDY,
};

enum FRIEND_OP
{
    _FRIEND_INFO        = 0,
    _ENEMY_INFO         = 1,

    _FRIEND_APPLY		= 10,
    _FRIEND_ACCEPT		= 11,
    _FRIEND_ONLINE		= 12,
    _FRIEND_OFFLINE		= 13,
    _FRIEND_BREAK		= 14,
    _FRIEND_GETINFO		= 15,
    _ENEMY_ONLINE		= 16,			// to client // ���µ�����״̬ 
    _ENEMY_OFFLINE		= 17,			// to client // ���µ�����״̬ 
    _ENEMY_DEL			= 18,			// to server // to client // ɾ��һ������ 
    _ENEMY_ADD			= 19,			// to client // ���һ������ 
};

enum { FLYMAP_ERROR=-1, FLYMAP_NORMAL, FLYMAP_MAPGROUP };

// ��ͻ��˷��͵�����������Ϣ
enum
{
	ONLINE_TRAINING_BEGIN,							// ��ʼ��������
	ONLINE_TRAINING_PAUSE,							// ��ͣ��������
	ONLINE_TRAINING_RESUME,							// �ָ���������
	ONLINE_TRAINING_GAIN_POINT,						// ����ʮ��������, ÿ����ͬ���ͻ���һ��
	ONLINE_TRAINING_AWARDEXP,						// ��ȡ������������
	ONLINE_TRAINING_END,							// ������������
};

// ���ף��Itemtype
enum
{
	GODBLESS_ITEMTYPE1 = 1200000,
	GODBLESS_ITEMTYPE2 = 1200001,
	GODBLESS_ITEMTYPE3 = 1200002,
};

// ��ͻ��˷��͵ķ�����״̬��Ϣ
enum
{
	WALLOW_NONE = 0,									// ������
	WALLOW_HALF = 50,									// ������
	WALLOW_FULL = 100,									// ȫ����
};

// �¼������� ACTION ����
enum 
{
	ACTION_EVENT_USER_DIE				= 80000000,		// �������ʱ����(pUser)
	ACTION_EVENT_USER_KILL				= 80000001,		// ���ɱ������ʱ���������У�pUser, pRoleTarget��
	ACTION_EVENT_USER_PICKUP_MAPITEM	= 80000002,		// ��Ҽ����ͼ��Ʒʱ����(pUser, pRole, pItem)
	ACTION_EVENT_USER_REBORN			= 80000003,		// �������ʱ����(pUser)
	ACTION_EVENT_USER_LEVUP				= 80000004,		// �������ʱ����(pUser)
};

// ����ת������
enum
{
	DRAGONBALLTYPE20 = 1,									// ת20������
	DRAGONBALLTYPE100 = 2,									// ת100������
};

// ����ת����־
enum
{
	DRAGONBALL_NOGET,										// δ��ȡ
	DRAGONBALL_GET,											// ����ȡ
	DRAGONBALL_WAIT,										// �ȴ�ת��
	DRAGONBALL_SUCCESS,										// �Ѿ�ת��
};

enum ITEM_EVENT	
{
	ITEM_EVENT_GEM_PICKUP		= 1,
	ITEM_EVENT_GEM_AWARD		= 2,
	ITEM_EVENT_GEM_DROP			= 3,
	ITEM_EVENT_GEM_SELL			= 4,
	
	ITEM_EVENT_SCKEQP_PICKUP	= 11,
	ITEM_EVENT_SCKEQP_AWARD		= 12,
	ITEM_EVENT_SCKEQP_DROP		= 14,
	ITEM_EVENT_SCKEQP_SELL		= 15,
	
	ITEM_EVENT_DB_PICKUP		= 21,
	ITEM_EVENT_DB_AWARD			= 22,
	ITEM_EVENT_DB_DROP			= 23,
	ITEM_EVENT_DB_SELL			= 24,
};

enum TRUMP_TYPE
{
	TRUMP_TYPE_UPLEVEXP						= 2,	//��������������ֵ�ӳ�			
	TRUMP_TYPE_DROPSTONE					= 3,	//�����ǻ�ʯ������ֵ��������	 			
	TRUMP_TYPE_DROPMONEY					= 4,	//������Ǯ������ֵ��������						
	TRUMP_TYPE_REBORN_SKILL					= 5,	//�����ĸ����
	TRUMP_TYPE_DAMAGE_BY_NEAR_FIGHTER		= 6,	//�������ܽ�ս�˺��������������� 					
	TRUMP_TYPE_DAMAGE_BY_FAR_FIGHTER		= 7,	//��������Զս�˺���������			
	TRUMP_TYPE_MAKE_DAMAG_TO_NEAR_FIGHTER	= 8,	//�����ĶԽ�ս�˺���������������							
	TRUMP_TYPE_MAKE_DAMAG_TO_FAR_FIGHTER	= 9,	//�����Ķ�Զս�˺���������		 		
	TRUMP_TYPE_INTERVAL_ADD_HP				= 10,	//�������ʱ������HP
	TRUMP_TYPE_RADIATION					= 11,	//��������ֿ�����
	TRUMP_TYPE_MAXEN						= 12,	//����֮Ӱ��EN����						
	TRUMP_TYPE_POWER						= 13,	//����Ӱ�칦�ʻָ��ٶ�			
	TRUMP_TYPE_EN_INC_POWER					= 14,	//����Ӱ��EN�ָ��ٶ�					
	TRUMP_TYPE_DEF_INC_POWER				= 15,	//����֮Ӱ�����
	TRUMP_TYPE_THRUSTER_INC_POWER			= 16,	//����֮Ӱ���ƽ����ظ��ٶ�			
	TRUMP_TYPE_ANTI_ICE						= 18,	//����֮��������				 
	TRUMP_TYPE_ANTI_HOT						= 19,	//����֮���¿���				 
	TRUMP_TYPE_ANTI_SHAKE		 			= 20,	//����֮�𵴿���				
	TRUMP_TYPE_ICE_STRONG					= 21,	//����֮����ǿ��				
	TRUMP_TYPE_HOT_STRONG					= 22,	//����֮����ǿ��				
	TRUMP_TYPE_SHAKE_STRONG					= 23,	//����֮��ǿ��				
	TRUMP_TYPE_SKILLEXPEND					= 24,	//����������������				
	TRUMP_TYPE_WEAPON_SKILL_EXP				= 25,	//���������������Ⱦ���ֵ�ӳɹ���
	TRUMP_TYPE_SKILL_EXP					= 26,	//�����ļ��������Ⱦ���ֵ�ӳɹ���
	TRUMP_TYPE_SPIRIT_SKILL_EXP				= 27,	//�����Ļ��������Ⱦ���ֵ�ӳɹ���
	TRUMP_TYPE_IDENT_EQUIP					= 29,	//������װ����������

	TRUMP_TYPE_RED_ROSE_REC_SND_DETAL_NUM   = 32,	//������Ӱ���õ����/�ջ�����		
	TRUMP_TYPE_WHITE_ROSE_REC_SND_DETAL_NUM = 33,	//������Ӱ���õ����/�ջ�����

	TRUMP_TYPE_MSGTALK_EMOTION				= 34,	//������Ӱ���������				
	TRUMP_TYPE_ICE_DAMAGE_TRANS_TO_HP		= 37,	//����֮�����˺�תHP
	TRUMP_TYPE_HOT_DAMAGE_TRANS_TO_HP		= 38,	//����֮�����˺�תHP
	TRUMP_TYPE_SHAKE_DAMAGE_TRANS_TO_HP		= 39,	//����֮���˺�תHP
	
	TRUMP_TYPE_ICE_DAMAGE_BACK_TO_ATTACKER	= 40,	//����-�����˺�����
	TRUMP_TYPE_HOT_DAMAGE_BACK_TO_ATTACKER	= 41,	//����-�����˺�����
	TRUMP_TYPE_SHAKE_DAMAGE_BACK_TO_ATTACKER= 42,	//����-���˺�����

	TRUMP_TYPE_DIE_BLAST_ENEMY_HP			= 43,	//����-����������HP

	TRUMP_TYPE_CHANGE_BEKILER_GHOSTTYPE			= 45,	//����-�ı�������״̬
	TRUMP_TYPE_DELAY_BEKILLER_REBORN_TIMES		= 46,	//����-���ָ�����ʱ
	TRUMP_TYPE_BE_REBORN_BY_OTHER_TIMES			= 47,   //����-�������Ӳ��ɱ�����ʱ��
	TRUMP_TYPE_HIDE_SYDICATE_NAME				= 48,	//���������佢������
	TRUMP_TYPE_AUTO_FIGHT_BACK					= 49,	//����-����
	TRUMP_TYPE_HP_CURSE							= 50,	//����������
	TRUMP_TYPE_DAMAGE_SUCK_HP					= 51,	//���� - ��Ѫ����
	TRUMP_TYPE_ADD_DAMAGE_INTERVAL				= 52,	//����-�Թּ�Ъ��Ѫ
	TRUMP_TYPE_SELFBLAST_DEC_HP					= 53,	//����-�Ա�������HP����
	TRUMP_TYPE_SELFBLAST_DEC_BATTLEEFFECT		= 54,	//����-�Ա�������ս����

	TRUMP_TYPE_THE_SAME_TYPE_SPIRIT_BATTLEEFFECT = 55,	//����-ͬ�����ս��������

	TRUMP_TYPE_ADD_DAMAGE_TO_TRAIN_SPIRIT		= 56,	//����-��ѧ�����˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_MIDDLE_SPIRIT		= 57,	//����-���ͻ����˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_LIFE_SPIRIT			= 59,	//����-���������˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_MACHINE_SPIRIT		= 60,	//����-��е�ջ����˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_ANTI_HOT_SPIRIT		= 61,	//����-�����»����˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_ANTI_ICE_SPIRIT		= 62,	//����-�����������˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_ANTI_SHAKE_SPIRIT	= 63,	//����-���𵴻����˺���������
	TRUMP_TYPE_ADD_DAMAGE_TO_MEDICAL_SPIRIT		= 64,	//����-ҽ��Ԯ�������˺���������
	TRUMP_TYPE_FLOATCANNON_SHARE_DAMAGE			= 65,	//�����ĸ����ڷ�̯�˺�����
	TRUMP_TYPE_FLOATCANNON_SUPPORT_HP			= 66,	//�����ĸ���������ת�ƹ���
	TRUMP_TYPE_DYING_RAGE						= 67,   //����-������
	TRUMP_TYPE_DODGE_DEC_HP						= 68,	//����-������Ѫ
	TRUMP_TYPE_FORBID_FLY						= 69,   //����-����
	TRUMP_TYPE_ANTI_FORBID_FLY					= 70,	//����-���ɵֿ�
	TRUMP_TYPE_REGION_DAMAGE					= 72,	//����������ΧȫԱ�˺����
	TRUMP_TYPE_REGION_BATTLEEFFECT				= 73,	//����-ս����������
	TRUMP_TYPE_REGION_BE_DAMAGE					= 74,	//����������ΧȫԱ���˺����
	TRUMP_TYPE_REGION_ADD_HP					= 75,	//����������ΧȫԱHP���
	TRUMP_TYPE_REGION_ANTI_HOT					= 76,	//��������������¿���
	TRUMP_TYPE_REGION_ANTI_ICE					= 77,	//�������������������
	TRUMP_TYPE_REGION_ANTI_SHAKE				= 78,	//�������������𵴿���

	TRUMP_TYPE_REGION_FORBID_RESTORE_HP			= 79,	//ȫԱ��ֹHP�ظ�������
	TRUMP_TYPE_REGION_FORBID_RESTORE_POWER		= 80,   //ȫԱ��ֹ���ʻָ�������		
	TRUMP_TYPE_REGION_FORBID_RESTORE_EN			= 81,	//ȫԱ��ֹ�ָ�EN����������
	TRUMP_TYPE_REGION_FORBID_RESTORE_THRUSTER   = 82,   //ȫԱ��ֹ�����ָ��������		
	TRUMP_TYPE_REGION_FORBID_RESTORE_DEF		= 83,	//ȫԱ��ֹ���ָܻ�������

	TRUMP_TYPE_REGION_FORBID_TRANS_POS			= 84,   //����-�����ֹ˲�ƽ��

	TRUMP_TYPE_REGION_SKILL						= 86,	//����������
	
	TRUMP_TYPE_REGION_FORBID_JUMP				= 87,	//����-����ȫԱ��ֹ��Ծ���		
	TRUMP_TYPE_HOLE_PROGRESS					= 88,	//����-�ɿ���
	TRUMP_TYPE_REGION_ADD_DEAD_TIME				= 88,	//����-������������ʱ��		

	TRUMP_TYPE_REGION_RESTORE_XP_SPEED			= 92,   //����-����ΧȫԱXP�ָ��ٶȽ��
	TRUMP_TYPE_WHOLEMAP_BATTLEEFFECT			= 96,	//����-ȫ��ͼȫԱս�������		
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_BATTLEEFFECT  = 97,	//����-ȫ��ͼ����ս�������		
	TRUMP_TYPE_WHOLEMAP_TEAM_BATTLEEFFECT       = 98,	//����-ȫ��ͼ����ս�������		
	TRUMP_TYPE_WHOLEMAP_FAMILY_BATTLEEFFECT     = 99,   //����-ȫ��ͼ����ս�������		
	
	TRUMP_TYPE_WHOLEMAP_ADD_EXP					= 100,  //����-ȫ��ͼȫԱ����ֵ���
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_ADD_EXP		= 101,  //����-ȫ��ͼ���Ӿ���ֵ���
	TRUMP_TYPE_WHOLEMAP_TEAM_ADD_EXP			= 102,  //����-ȫ��ͼ���龭��ֵ���
	TRUMP_TYPE_WHOLEMAP_FAMILY_ADD_EXP			= 103,	//����-ȫ��ͼ���徭��ֵ���

	TRUMP_TYPE_SELFBLAST_DEC_HP_ANTI			= 107,	//����-�������Ա���HP����
	TRUMP_TYPE_ANTI_BATTLE_EFFECT				= 109,		//����-��ս�������Ч��
	
	TRUMP_TYPE_ANTI_REGION_FORBID_JUMP				= 113,	//����-��������ȫԱ��ֹ��Ծ���	
	TRUMP_TYPE_ANTI_REGION_FORBID_RESTORE_HP		= 115,  //����������HP��ֹ�ظ�

	TRUMP_TYPE_ANTI_REGION_FORBID_RESTORE_EN		= 116,	//����-���ӽ�ֹ�ָ�EN������
	TRUMP_TYPE_ANTI_REGION_FORBID_RESTORE_POWER	    = 117,	//����-���ӽ�ֹ���ʻָ�������
	TRUMP_TYPE_ANTI_REGION_FORBID_RESTORE_THRUSTER  = 118,  //����-���ӽ�ֹ�����ָ�������		
	TRUMP_TYPE_ANTI_REGION_FORBID_RESTORE_DEF		= 119,	//����-���ӽ�ֹ���ָܻ�������

	TRUMP_TYPE_ANTI_FORBID_TRANS_POS			= 120,	//����-����˲�Ƶ������ֹ���
	TRUMP_TYPE_SELFBLAST_DEC_BATTLEEFFECT_ANTI	= 124,  //����-�������Ա���ս��������

	TRUMP_TYPE_DEC_DAMAGE_FROM_TRAIN_SPIRIT		= 125,//����-�ܽ�ѧ�����˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_MIDDLE_SPIRIT		= 126,//����-�����ͻ����˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_LIFE_SPIRIT		= 128,//����-�����������˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_MACHINE_SPIRIT	= 129,//����-�ܻ�е�ջ����˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_ANTI_HOT_SPIRIT	= 130,//����-�ܿ����»����˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_ANTI_ICE_SPIRIT	= 131,//����-�ܿ����������˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_ANTI_SHAKE_SPIRIT	= 132,//����-�ܿ��𵴻����˺���������
	TRUMP_TYPE_DEC_DAMAGE_FROM_MEDICAL_SPIRIT	= 133,//����-��ҽ��Ԯ�������˺���������
	TRUMP_TYPE_ANTI_HEAVY_FLY					= 138,//����-����������
			
	TRUMP_TYPE_DEC_BLACK_NAME_DAMAGE			= 139,	//����֮�����˺�����			
	TRUMP_TYPE_GREEN_NAME_MONSTER_EXP			= 140,	//������ɱ�����־������ӹ���	
	TRUMP_TYPE_BATTLELEV_BY_CONDITION			= 141,	//����-��Ҫ������ս����	
	TRUMP_TYPE_WEAPON_CONTROL_LEVEL				= 144,	//�����������ٿصȼ�����			
	TRUMP_TYPE_REQEQUIPLEV_BECOME_LOW			= 145,  //����������װ���ȼ�Ҫ���½�    
	TRUMP_TYPE_SHIPJOB_DOWN_REQMINLEV			= 146,	//��������Ҫ��ȼ����޽���
	TRUMP_TYPE_SATELLITMSG_PAY_CUTOFF			= 147,	//�������ǹ㲥�������ý���
	TRUMP_TYPE_ADD_LOTTERY_TIMES				= 148,  //����-�齱����
	
	TRUMP_TYPE_REFULSE_TRADE					= 150,	//�����ľܾ�����
	TRUMP_TYPE_REFULSE_MARRY					= 151,  //�����ľܾ����
	TRUMP_TYPE_REFUSE_MAKE_FREIND				= 152,  //�����ľܾ��ύ��Ϣ

	TRUMP_TYPE_RAND_TRANSPOS_IN_LITTE_RANGE		= 153,  //����-С˲��

	TRUMP_TYPE_HIDE_BATTLEEFFECT				= 154,  //����-ս����αװ
	TRUMP_TYPE_BE_WATCH_EQUIP_GAIN_MONEY		= 155,	//����-��켺��װ���շ�

	TRUMP_TYPE_WHOLEMAP_SKILL					= 159,  //ȫ��ͼ�����ܿ�ʼ
	TRUMP_TYPE_WHOLEMAP_HP						= 160,  //����-ȫ��ͼȫԱHP���
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_HP			= 161,  //����-ȫ��ͼ����HP���
	TRUMP_TYPE_WHOLEMAP_FAMILY_HP				= 162,	//����-ȫ��ͼ����HP���
	TRUMP_TYPE_WHOLEMAP_TEAM_HP					= 163,  //����-ȫ��ͼ����HP���		

	TRUMP_TYPE_WHOLEMAP_ADD_DAMAGE				= 164,	//������ȫ��ͼȫԱ���˺����
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_ADD_DAMAGE	= 165,	//������ȫ��ͼ���Ӽ��˺����
	TRUMP_TYPE_WHOLEMAP_TEAM_ADD_DAMAGE			= 166,	//������ȫ��ͼ������˺����
	TRUMP_TYPE_WHOLEMAP_FAMILY_ADD_DAMAGE		= 167,	//������ȫ��ͼ������˺����
	TRUMP_TYPE_WHOLEMAP_DEC_DAMAGE				= 168,	//������ȫ��ͼȫԱ���˺����
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_DEC_DAMAGE	= 169,	//������ȫ��ͼ���Ӽ��˺����
	TRUMP_TYPE_WHOLEMAP_TEAM_DEC_DAMAGE			= 170,	//������ȫ��ͼ������˺����
	TRUMP_TYPE_WHOLEMAP_FAMILY_DEC_DAMAGE		= 171,	//������ȫ��ͼ������˺����

	TRUMP_TYPE_WHOLEMAP_ANTI_HOT				= 172,	//����-ȫ��ͼȫԱ���¿��Խ��		
	
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_ANTI_HOT		= 173,	//����-ȫ��ͼ���ɸ��¿��Խ��				
	TRUMP_TYPE_WHOLEMAP_TEAM_ANTI_HOT			= 174,	//����-ȫ��ͼ������¿��Խ��		
	TRUMP_TYPE_WHOLEMAP_FAMILY_ANTI_HOT			= 175,	//����-ȫ��ͼ������¿��Խ��		

	TRUMP_TYPE_WHOLEMAP_ANTI_ICE				= 176,	//����-ȫ��ͼȫԱ�������Խ��		
	
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_ANTI_ICE		= 177,	//����-ȫ��ͼ���ɱ������Խ��				
	TRUMP_TYPE_WHOLEMAP_TEAM_ANTI_ICE			= 178,	//����-ȫ��ͼ����������Խ��		
	TRUMP_TYPE_WHOLEMAP_FAMILY_ANTI_ICE			= 179,	//����-ȫ��ͼ����������Խ��		

	TRUMP_TYPE_WHOLEMAP_ANTI_SHAKE				= 180,	//����-ȫ��ͼȫԱ�𵴿��Խ��				
	
	TRUMP_TYPE_WHOLEMAP_SYNDIACTE_ANTI_SHAKE	= 181,	//����-ȫ��ͼ�����𵴿��Խ��		
	TRUMP_TYPE_WHOLEMAP_TEAM_ANTI_SHAKE			= 182,	//����-ȫ��ͼ�����𵴿��Խ��
	TRUMP_TYPE_WHOLEMAP_FAMILY_ANTI_SHAKE		= 183,	//����-ȫ��ͼ�����𵴿��Խ��
	
	TRUMP_TYPE_SHIPJOB_UP_REQMAXLEV				= 184,	//��������Ҫ��ȼ��������
	TRUMP_TYPE_SATELLITMSG_URGENCY_CUTOFF		= 185,	//�������ǹ㲥�Ӽ����ý���
	//�����ٿصȼ��������� mj 2007-08-03 add
	TRUMP_TYPE_SWORD_CONTROL_LEV_UP             = 188,  //����-���ֽ��ٿصȼ�����			
	TRUMP_TYPE_GIANTSWORD_CONTROL_LEV_UP        = 189,  //����-�ؽ��ٿصȼ�����
	TRUMP_TYPE_HARMER_CONTROL_LEV_UP            = 190,  //����-ս���ٿصȼ�����
	TRUMP_TYPE_KNIFE_CONTROL_LEV_UP             = 191,  //����-���ֵ��ٿصȼ�����
	TRUMP_TYPE_SPEAR_CONTROL_LEV_UP         = 192,  //����-��ì�ٿصȼ�����
	TRUMP_TYPE_FREEZEGUN_CONTROL_LEV_UP          = 193,  //����-�䶳ǹ�ٿصȼ�����	
	TRUMP_TYPE_MUSKET_CONTROL_LEV_UP            = 194,  //����-��ǹ�ٿصȼ�����	
	TRUMP_TYPE_MACHINEGUN_CONTROL_LEV_UP        = 195,  //����-��ǹ�ٿصȼ�����	
	TRUMP_TYPE_SHOTGUN_CONTROL_LEV_UP           = 196,  //����-ɢ��ǹ�ٿصȼ�����		
	TRUMP_TYPE_FLAMETHROWERGUN_CONTROL_LEV_UP   = 197,  //����-����ǹ�ٿصȼ�����	
	
	//װ���ȼ�Ҫ���½����� mj 2007-08-01 add
	
	TRUMP_TYPE_SWORD_REQ_LEV_DOWN               = 198,  //����-���ֽ�װ���ȼ�Ҫ���½�
	TRUMP_TYPE_GIANTSWORD_REQ_LEV_DOWN          = 199,  //����-�ؽ�װ���ȼ�Ҫ���½�		
	TRUMP_TYPE_HARMER_REQ_LEV_DOWN              = 200,  //����-ս��װ���ȼ�Ҫ���½�	
	TRUMP_TYPE_KNIFE_REQ_LEV_DOWN               = 201,  //����-����װ���ȼ�Ҫ���½�
	TRUMP_TYPE_SPEAR_REQ_LEV_DOWN               = 202,  //����-��ìװ���ȼ�Ҫ���½�
	TRUMP_TYPE_SHIELD_REQ_LEV_DOWN              = 203,  //����-����װ���ȼ�Ҫ���½�
	TRUMP_TYPE_FREEZEGUN_REQ_LEV_DOWN           = 204,  //����-�䶳ǹװ���ȼ�Ҫ���½�		
	TRUMP_TYPE_MUSKET_REQ_LEV_DOWN              = 205,  //����-��ǹװ���ȼ�Ҫ���½�
	TRUMP_TYPE_MACHINEGUN_REQ_LEV_DOWN          = 206,  //����-��ǹװ���ȼ�Ҫ���½�
	TRUMP_TYPE_SHOTGUN_REQ_LEV_DOWN             = 207,   //����-ɢ��ǹװ���ȼ�Ҫ���½�
	TRUMP_TYPE_FLAMETHROWERGUN_REQ_LEV_DOWN     = 208,   //����-����ǹװ���ȼ�Ҫ���½�
	TRUMP_TYPE_DEFENSEIMPLEMENT_REQ_LEV_DOWN    = 209,   //����-���װ���ȼ�Ҫ���½�
	TRUMP_TYPE_THRUSTER_REQ_LEV_DOWN		    = 210, //����-�ƽ���װ���ȼ�Ҫ���½�
	TRUMP_TYPE_DODGEIMPLEMENT_REQ_LEV_DOWN	    = 211, //����-������װ���ȼ�Ҫ���½�
	TRUMP_TYPE_ENGINE_REQ_LEV_DOWN				= 212, //����-������װ���ȼ�Ҫ���½�
	TRUMP_TYPE_SPIRITHPGENERATOR_REQ_LEV_DOWN    = 213,//����-HP���װ���ȼ�Ҫ���½�����
	TRUMP_TYPE_BACKPACK_REQ_LEV_DOWN			= 214,//����-����װ���ȼ�Ҫ���½�����
	TRUMP_TYPE_ENERGYGENERATOR_REQ_LEV_DOWN     = 215,  //����-������װ���ȼ�Ҫ���½�
	//mj 2007-08-17
	TRUMP_TYPE_DEFENSEIMPLEMENT_RESTORE_SPEED	= 219,	//����-���ָܻ��ٶ�����
	TRUMP_TYPE_DEFENSEIMPLEMENT_MAX_LIMITE		= 220,  //����-������������
	TRUMP_TYPE_FLOATCANNON_DEC_REBORN_TIME      = 221,  //����-���ٸ����ڸ���ʱ��
	TRUMP_TYPE_ADD_DOUBLE_EXPERIENCE_MED        = 224,	//����-�ӳ�˫��ҩˮ����ʱ��
	TRUMP_TYPE_BOOTH_DISCOUNT                   = 225,  //����-��̯���ý���
	TRUMP_TYPE_LEVLE_ADD_BATTLEEFFECT           = 226,  //����-�ȼ�����ս����
	TRUMP_TYPE_USER_LEVEL_ADD_BATTLEEFFECT      = 227,  //����-��������ս����
	TRUMP_TYPE_SYMBOL_ADD_BATTEEFFECT           = 229,  //����-��У����ս����+1

	TRUMP_TYPE_ADD_TEAM_EXP_SHARE               = 236,  //����-��Ӿ����������
	TRUMP_TYPE_ADD_XP_RECOVER_SPEED				= 237,  //����-XP�ظ��ٶ�����
 	TRUMP_TYPE_ADD_DAMAGE_TO_EMPLACEMENT        = 240,   //����-����̨�˺�����
	TRUMP_TYPE_SUPPORT_STATION					= 241,	 //����-���Ӳ���վ
	TRUMP_TYPE_DEC_DURABILITY_BY_SWORD          = 243,   //����-���ֽ������;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_GIANTSWORD     = 244,   //����-�ؽ������;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_HARMER         = 245,   //����-ս�������;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_KNIFE          = 246,   //����-���������;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_SPEAR          = 247,   //����-��ì�����;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_FREEZEGUN      = 248,   //����-�䶳ǹ�����;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_MUSKET         = 249,   //����-��ǹ�����;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_SHOTGUN        = 250,   //����-ɢ��ǹ�����;ö�
	TRUMP_TYPE_DEC_DURABILITY_BY_FLAMETHROWERGUN= 251,   //����-����ǹ�����;ö�

	TRUMP_TYPE_EXTRA_DAMAGE_BY_SWORD            = 252,   //����-���ֽ������˺�
	TRUMP_TYPE_EXTRA_DAMAGE_BY_GIANTSWORD       = 253,   //����-�ؽ������˺�
	TRUMP_TYPE_EXTRA_DAMAGE_BY_HARMER           = 254,   //����-ս�������˺�
	TRUMP_TYPE_EXTRA_DAMAGE_BY_KNIFE            = 255,   //����-���������˺�
	TRUMP_TYPE_EXTRA_DAMAGE_BY_SPEAR            = 256,   //����-��ì�����˺�
	TRUMP_TYPE_EXTRA_DAMAGE_BY_FREEZEGUN        = 257,   //����-�䶳ǹ�����˺�
    TRUMP_TYPE_EXTRA_DAMAGE_BY_MUSKET           = 258,   //����-��ǹ�����˺�
    TRUMP_TYPE_EXTRA_DAMAGE_BY_SHOTGUN          = 259,   //����-ɢ��ǹ�����˺�
	TRUMP_TYPE_EXTRA_DAMAGE_BY_FLAMETHROWERGUN  = 260,   //����-����ǿ�����˺�


	TRUMP_TYPE_PK_REBORN_TO_50_PERCENT          = 232,  //����-PK������������50%

	TRUMP_TYPE_REGION_DOMAIN_DAYTIME			= 233,	//�����������
	
	TRUMP_TYPE_CHANG_LIMIT_SIZE					= 1000,	//�ǹ̶�����λ�����������	
	///////////////////////////////////////////////////////////////////////////////
	TRUMP_TYPE_MAINFUNC_BEGIN				= 90010000,	//�����ܵĺ�����
	TRUMP_TYPE_RADIO_SEARCH					= TRUMP_TYPE_MAINFUNC_BEGIN,//����-�״�ϵͳ
	TRUMP_TYPE_ADD_ATTACK					= 90010001,	//����-��������������
	TRUMP_TYPE_ADD_DEFENCE					= 90010002, //����-��������������
	TRUMP_TYPE_ADD_ENGINEE_MAX_POWER		= 90010003, //����-��������������
	TRUMP_TYPE_THRUSTER_SPEND_POWER			= 90010004,	//����֮Ӱ���ƽ��������ٶ�			
	TRUMP_TYPE_ADD_DAMAGE					= 90010005,	//����-�����������˺�����������		
	TRUMP_TYPE_DEC_DAMAGE					= 90010006,	//����-�����������˺�����
	TRUMP_TYPE_ATTACK_TRANSFORM_DAMAGE_ADJ	= 90010007,	//�����ĶԱ��λ����˺���������
	TRUMP_TYPE_BEATTACK_BY_TRANSFORM_DAMAGE_ADJ	= 90010008,	//�����ı����λ����˺���������
	TRUMP_TYPE_BATTLELEV                    = 90010009, //������ս��������
	TRUMP_TYPE_ZERO                         = 90010010, //����-��ź��ģ���ս������������������
	TRUMP_TYPE_MAINFUNC_END					= 90089999,	//�����ܵĺ�����					
};

enum
{
	MAKE_HOLE1_PROCESS = 1,
	MAKE_HOLE2_PROCESS,
	MAKE_HOLE1_MOONGEM,
	MAKE_HOLE2_MOONGEM,
	MAKE_HOLE1_RMB,
	MAKE_HOLE2_RMB,
	MAKE_HOLE3_PROCESS_WEAPON,
	MAKE_HOLE4_PROCESS_WEAPON,
	MAKE_HOLE3_RMB_WEAPON,
	MAKE_HOLE4_RMB_WEAPON,
};

#define TRUMP_STATUS_KEY(x, y) (x + y%100000)													
//////////////////////////////////////////////////////////////////////
// �ڲ�״̬������Ҫͨ��MsgPlayer֪ͨ������ҵ�״̬���������ڲ�ʹ��(magictypeʹ��)
enum STATUS_TYPE
{
		STATUS_NORMAL			,

		// �����Ǽ��ܴ������µ�״̬��sort=107�ļ�����status�ֶεĴ��뺬��
		STATUS_STOPALL			= 1,			// �� �ɿͻ���(��NPC������)��������Լ������ƶ�
//		STATUS_POISON			= 2,			// ��
//		STATUS_ATTACK			= 3,			// ��   //ֻ���ж� û�����ӵ�
//		STATUS_DEFENCE			= 4,			// ��
//		STATUS_MOVESLOWLY		= 5,			// ��
//		STATUS_STOPFIGHT		= 6,			// ��   //ֻ���ж� û�����ӵ�
//		STATUS_STOPMOVE			= 7,			// ͣ �ɿͻ���(��NPC������)��������Լ������ƶ�
//		STATUS_UNDERWRAPS		= 8,			// �������Σ��Ѿ��ɼ�  //ս����ȡ������
//		STATUS_WOUND_REFLECT	= 9,			// �˺����䣨������
//		STATUS_SHIELD			= 10,			// ������
//		STATUS_GUARDIANSHIP		= 11,			// �ػ�
//		STATUS_SLEEP			= 12,			// ˯
//		STATUS_DAMAGE_RED		= 12,			//�����˺�����
//		STATUS_RECOVERHP		= 13,			// HP�����ָ�
//		STATUS_RECOVEREN		= 14,			// En�����ָ�
 		STATUS_FETCH_BURST		= 15,			// �걬 ��������ָ��:power ��������ָ��param
//		STATUS_INVINCIBLE		= 16,			// �޵�
		STATUS_INTERATTACK		= 17,			// ����ս��

		STATUS_RETALIATEUPON	,				// ����״̬
//		STATUS_SHIELDSKILL		,				// װ����itemtype��sort=18����type=0|1�Ķ��ƵĶ������ۼ�״̬
//		STATUS_COUNTERSTRIKE	,				// ����״̬������������ �ϲ� ����֮�������ۼ�״̬������������
//		STATUS_THROWENEMY		,				// Ͷ�� �� ��״̬��ֻ���ߺ�Ͷ
		STATUS_MULTISELECTENEMY	,				// ��Ŀ��ָ�����ܵ�����״̬�£�����ѡ����Ŀ�꣬����¼��
		STATUS_BEMULTISELECT	,				// ����Ŀ��ָ��״̬
//		STATUS_POISONRANGE		,				// ����״̬
//		STATUS_ADJUSTTOGETHER	,				// ����
//		STATUS_KILLLINEUP		,				// ɱ��
//		STATUS_BEKILLLINEUPED	,				// ��δ����ɱ�󣬴���ɱ��״̬����ҹ������ı�־
//		STATUS_KILLLINEUPSUC	,				// ɱ���óɹ����ȴ�����ɱ�����ʱ״̬
//		STATUS_CRAZYFIGHTER		,				// ��սʿ״̬
//		STATUS_CRAZYFIGHTERHP	,				// ��սʿ״̬ HP�ظ�
//		STATUS_CRAZYPOWERFIGHTER,				// ���սʿ״̬
//		STATUS_BASESUPPORTENABLE,				// ����Ԯ������ʹ��״̬
//		STATUS_ENGINOVERRUN		,				// ���������Ƚ�ֹ�ظ�״̬
//		STATUS_WEAPONINFO		,				// ���£����̣���ʴ���𵴣���ͨ������������Ϣ
//		STATUS_HEADLOOP			,				// ͷ����·��״̬���߱����Ʊ��Լ������ĵȼ������͵Ĳ���״̬Ӱ��(nPower���ֲ���״̬֮һ, nParam�ȼ�, nWparam��״��Ʒ��)
//		STATUS_UPSPIRIT_INQUEUE	,				// �����Ŷӽ������壬�����жϴ����Ŷӹ���
//		STATUS_MACHINECENTER	,				// �ڻ�еά�����ĵ�ά��̨�ϲ���״̬�������ƶ�
//		STATUS_RECOVERPOWER		,				// �������ָ�
//		STATUS_HEADLOOPREBUILD	,				// ͷ����·����æ״̬
//		STATUS_INSPACESHIPJOB	,				// ��������ǵ�ͼ���ɴ�����״̬
//		STATUS_SHIPJOBSIGNUPOK	,				// ��ұ����ɴ�����ɹ�״̬����ֹ�����������
		STATUS_DISABLELEAVEMAP	,				// ��ֹ�س�״̬(���������н�ֹʹ�ûسǾ�)
//		STATUS_LAUNCHREADY		,				// �ɴ�����׼��״̬
//		STATUS_INSPACESHIP		,				// �����Ǵ�
//		STATUS_RETURNMARKET		,				// �ɴ�����
//		STATUS_CHANGINGSPIRIT	,				// ���ڸ�������, ��ʱ״̬
		STATUS_XPFULLSTATUS		,				// xp full
		STATUS_XPWAITSTATUS		,				// xp wait
//		STATUS_XP_REGION_SPEED	,				// XP����ظ��ٶȼӳ�
		
//		STATUS_KILL_REFLECT		,
		STATUS_CURSE			,
		STATUS_RECOVERY         ,
// 		STATUS_FLOWER			,
// 		STATUS_WHITEFLOWER		,			// 2007.03.27 �յ���õ������
		STATUS_BETRAY_BROTHER   ,
// 		STATUS_SELLOUT_TUTOR	,			// ���ѵ�ʦ
// 		STATUS_SELLOUT_TUTOR_STEP2,         // ���ѵ�ʦ״̬�ڶ��׶�
//		STATUS_MAGIC_REBORN		,			// �����

		// system status
		STATUS_DIE				,
		STATUS_CRIME			,
		STATUS_SELFDEFENCE  	,			// add huang 2004.1.11 ������״̬
		STATUS_TEAMLEADER		,
//		STATUS_PKVALUE			,
 		STATUS_DISAPPEARING		,
		STATUS_SYNCRIME			,
		STATUS_WING				,

		STATUS_ANGEL			,//��ʹ״̬

//	    STATUS_KEEPBOW			,
//		STATUS_PKSWITCH			,
 		STATUS_BUSY_LevupInterface,
		
		// old status
		STATUS_DETACH_BADLY		,			// ���ã�������в���״̬
		STATUS_DETACH_ALL		,			// ���ã��������ħ��״̬
		STATUS_VAMPIRE			,			// ���ã�ATKSTATUS����Ѫ
		STATUS_ATKRANGE			,
		STATUS_REFLECT			,
//		STATUS_WEAPONDAMAGE		,
//		STATUS_MAGICDAMAGE		,
		STATUS_ATKSPEED			,
//		STATUS_LURKER			,			// user only
//		STATUS_TORNADO			,			// self only
//		STATUS_REFLECTMAGIC		,
		STATUS_DODGE			,
//		STATUS_SUPER_DEF		,
//		STATUS_SUPER_ATK		,			// self only	
//		STATUS_SUPER_MATK		,		 	// self only
		// tcp add
//		STATUS_UPSPIRIT_BEGAN	,			// �������ڽ�����
//		STATUS_SHOT_DELAY	    ,			// �����ӵ��ù⣬�ӳ�2��������
		STATUS_PRACTISE		    ,			// ��������״̬
//		STATUS_STOP				,      
		STATUS_SUPPRESS			,			// ѹ��״̬
//		STATUS_FREEZE			,			// �䶳״̬   //ֻ���ж� û�����ӵ�
//		STATUS_SELFPROTECT      ,			// ���ұ���
//		STATUS_LOCKATTACK		,			// ��������״̬	     CMachineGun  	
//		STATUS_SNIPE_AIM		,			// ��׼״̬		
	/*	STATUS_SYMBOL			,*/			// ���͹�����״̬
//		STATUS_XPTRANSLOOK		,			// XP���μ���״̬
//		STATUS_BAITMONSTER		,			// 2007.02.02 ���չ���״̬
		/*STATUS_ACT_EMOTION		,*/			// 2007.03.05 �������鱣��
		
//		STATUS_FLYMAP			,			// ����״̬
//		STATUS_NPC_STOP_TURN    ,			//��ֹ̨ͣת��  �ѻ���ǹ�����ƻ�����ʵ�� tcp 2007-1-25	
//		STATUS_NPC_STOP_WORK    ,			//��̨����ģʽ  �ѻ���ǹ�����ƻ�����ʵ�� tcp 2007-1-25
//		STATUS_NPC_STOP_ATTACK	,			//��ս��������  2007-4-10 tcp add ��ֱ״̬
		
//		STATUS_RADAR			,			// 2007.03.07 ��ֵ��Ʒ�״�״̬
//		STATUS_DEBUGMODE		,			// 2007.03.06 ����״̬ģʽ(HP����ģ��90900000����֧��)
//		STATUS_FRESHBATTLEEFFECT,			// 2007.03.29 ս�����������װ��ˢ��
		STATUS_BECALL_BY_TEAMLEADER,		// ���ӳ��ٻ� tcp 2007-2-27 add
//		STATUS_FIGHT_BACK,					// ����״̬ tcp 2007-3-29 add
//		STATUS_UPMODELLEV_USEITEM_INQUEUE,  // ����ʹ����Ʒ�Ǽ������Ļ���
//                STATUS_HIDE_SYDICATE_NAME,			// ���������佢������
/////////////////////////////////////////////���begin////////////////////////////////////////////////
		STATUS_TRUMP_REGION_BATTLEEFFECT,			 //����-ս����������		
		STATUS_TRUMP_REGION_DAMAGE,					 //����������ΧȫԱ�˺����		
		STATUS_TRUMP_REGION_BE_DAMAGE,				 //����������ΧȫԱ���˺����		
		STATUS_TRUMP_REGION_TYPE_REGION_ADD_HP,		 //����������ΧȫԱHP���    
		STATUS_TRUMP_REGION_FORBID_RESTORE_HP,		 //����ΧȫԱHP�ظ�
// 		STATUS_TRUMP_REGION_ANTI_HOT,				 //��������������¿���
// 		STATUS_TRUMP_REGION_ANTI_ICE,				 //�������������������
// 		STATUS_TRUMP_REGION_ANTI_SHAKE,				 //�������������𵴿���
// 		
//		STATUS_TRUMP_WHOLEMAP_ANTI_HOT,				 //����-ȫ��ͼ���¿��Խ��
// 		STATUS_TRUMP_WHOLEMAP_ANTI_ICE,				 //����-ȫ��ͼ�������Խ��
//		STATUS_TRUMP_WHOLEMAP_ANTI_SHAKE,			 //����-ȫ��ͼ�𵴿��Խ��

		STATUS_TRUMP_WHOLEMAP_ADD_EXP,				 //����-ȫ��ͼȫԱ����ֵ���
		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_ADD_EXP,	 //����-ȫ��ͼ���Ӿ���ֵ���
		STATUS_TRUMP_WHOLEMAP_TEAM_ADD_EXP,			 //����-ȫ��ͼ���龭��ֵ���
		STATUS_TRUMP_WHOLEMAP_FAMILY_ADD_EXP,		 //����-ȫ��ͼ���徭��ֵ���	

// 		STATUS_TRUMP_WHOLEMAP_TEAM_ANTI_HOT,		 //����-ȫ��ͼ������¿��Խ��		
// 		STATUS_TRUMP_WHOLEMAP_TEAM_ANTI_ICE,		 //����-ȫ��ͼ����������Խ��		
// 		STATUS_TRUMP_WHOLEMAP_TEAM_ANTI_SHAKE,		 //����-ȫ��ͼ�����𵴿��Խ��			
// 		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_ANTI_HOT,	 //����-ȫ��ͼ���ɸ��¿��Խ��		
// 		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_ANTI_ICE,	 //����-ȫ��ͼ���ɱ������Խ��		
// 		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_ANTI_SHAKE,	 //����-ȫ��ͼ�����𵴿��Խ��			
// 		STATUS_TRUMP_WHOLEMAP_FAMILY_ANTI_HOT,		 //����-ȫ��ͼ������¿��Խ��		
// 		STATUS_TRUMP_WHOLEMAP_FAMILY_ANTI_ICE,		 //����-ȫ��ͼ����������Խ��		
// 		STATUS_TRUMP_WHOLEMAP_FAMILY_ANTI_SHAKE,	 //����-ȫ��ͼ�����𵴿��Խ��
		STATUS_TRUMP_WHOLEMAP_BATTLEEFFECT,			 //����-ȫ��ͼȫԱս�������
		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_BATTLEEFFECT,//����-ȫ��ͼ����ս�������
		STATUS_TRUMP_WHOLEMAP_FAMILY_BATTLEEFFECT,	 //����-ȫ��ͼ����ս�������
		STATUS_TRUMP_WHOLEMAP_TEAM_BATTLEEFFECT,	 //����-ȫ��ͼ����ս�������		
		STATUS_TRUMP_WHOLEMAP_HP,					 //����-ȫ��ͼȫԱHP���
		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_HP,			 //����-ȫ��ͼ����HP���
		STATUS_TRUMP_WHOLEMAP_FAMILY_HP,			 //����-ȫ��ͼ����HP���
		STATUS_TRUMP_WHOLEMAP_TEAM_HP,				 //����-ȫ��ͼ����HP���
		STATUS_TRUMP_WHOLEMAP_ADD_DAMAGE,			 //������ȫ��ͼȫԱ���˺����
		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_ADD_DAMAGE,	 //������ȫ��ͼ���Ӽ��˺����
		STATUS_TRUMP_WHOLEMAP_TEAM_ADD_DAMAGE,		 //������ȫ��ͼ������˺����
		STATUS_TRUMP_WHOLEMAP_FAMILY_ADD_DAMAGE,	 //������ȫ��ͼ������˺����
		STATUS_TRUMP_WHOLEMAP_DEC_DAMAGE,			 //������ȫ��ͼȫԱ���˺����
		STATUS_TRUMP_WHOLEMAP_SYNDIACTE_DEC_DAMAGE,	 //������ȫ��ͼ���Ӽ��˺����
		STATUS_TRUMP_WHOLEMAP_TEAM_DEC_DAMAGE,		 //������ȫ��ͼ������˺����
		STATUS_TRUMP_WHOLEMAP_FAMILY_DEC_DAMAGE,	 //������ȫ��ͼ������˺����
		
		STATUS_TRUMP_REGION_FORBID_RESTORE_EN,		 //ȫԱ��ֹ�ָ�EN���������磨������
		STATUS_TRUMP_REGION_FORBID_RESTORE_POWER,    //ȫԱ��ֹ���ʻָ�������						//140
		STATUS_TRUMP_REGION_FORBID_RESTORE_THRUSTER, //ȫԱ��ֹ�����ָ��������		
		STATUS_TRUMP_REGION_FORBID_RESTORE_DEF,		 //ȫԱ��ֹ���ָܻ�������	
		
//		STATUS_TRUMP_REGION_RESTORE_XP_SPEED,		 //����-����ΧȫԱXP�ָ��ٶȽ��
		STATUS_TRUMP_REGION_FORBID_JUMP,			 //����-����ȫԱ��ֹ��Ծ���	
		
		STATUS_TRUMP_REGION_ADD_DEAD_TIME,           //����-������������ʱ�� 
		////////////////////////////////////////////���end///////////////////////////////////////////		
		////////////////////////////////////////////////////////////����//////////////////////////////////		
	    STATUS_GEM_CAN_EXCHANGE_EXP,				 //���ǻ�����
		STATUS_PKBEATBACK,							 //��ұ�����,�ͻ��˱��뷴����������״̬
//		STATUS_FIRST_NIMBUS,						 //��һ�������а�
//		STATUS_STARWAR_LEADER,						 //�Ǽ�սָ�ӹ�
//		STATUS_WATCH_STARWAR,						 //�Ǽ�ս��ս״̬

//		STATUS_TRUMP_WORKING_THE_SAME_TYPE_SPIRIT_BATTLEEFFECT_BEGIN	= 500,//����-ͬ�����ս��������		
//		STATUS_TRUMP_WORKING_THE_SAME_TYPE_SPIRIT_BATTLEEFFECT_END	= 699,//����-ͬ�����ս��������
		STATUS_WAYLAY                             = 800, // �������״̬
		STATUS_USER_HP_AUTO_RESUME,  		
		STATUS_USER_MP_AUTO_RESUME,  		
		STATUS_USER_EN_AUTO_RESUME,  		
		STATUS_USER_CAN_CONJURE_DEVIL,
		STATUS_USER_CANNOT_CONJURE_DEVIL,
////////////////////////////�Զ����״̬�������ݿ�������//////////////////////////////////////////////
		STATUS_CUSTOM_BEGIN=1000,
		STATUS_TEAMSTATUS_EXP_MEDICINE=STATUS_CUSTOM_BEGIN,	// ���龭��ֵҩˮ
		STATUS_STAR_MONSTER		,			// �Թ����Ǽ�״̬
		STATUS_ADD_BATTLEEFFECT	,			// ����ս����״̬
//		STATUS_INCEXP_DECDEF	,			// ����ֵ���ӡ������½�״̬
//		STATUS_INCEXP_DECATK	,			// ����ֵ���ӡ������½�״̬
//		STATUS_CANNON_DIE,					// ����������
		STATUS_MODLE_LEV_COLD   ,			// ս���Ǽ�����ȴ״̬
//		STATUS_TRUMP_USE_TIME_LIMIT,		// ���������ʱ������״̬
		STATUS_PK_CHAMPION1			= 1008,		// pk�� �����ھ�״̬ 
		STATUS_PK_CANDICATE1		= 1009,		// pk�� ������Χ״̬    // PK��   ��һ��ö����  showstatetoʱ �·�
		STATUS_PK_CHAMPION2			= 1010,		// pk�� �߼��ھ�״̬ 
		STATUS_PK_CANDICATE2		= 1011,		// pk�� �߼���Χ״̬
		STATUS_PK_CHAMPION3			= 1012,		// pk�� �м��ھ�״̬ 
		STATUS_PK_CANDICATE3		= 1013,		// pk�� �м���Χ״̬
		STATUS_TRUMP_SELFBLAST_DECBATTLEEFFECT= 1014,//����-�Ա�������ս��������
		STATUS_ATTACK_LOCK			= 1020,		// ��ս��ͨ��������ն+���� ״̬
//		STATUS_ANTI_HEAVY_FLY		= 1021,     // ����-����������
		STATUS_COACH_USER			= 1022,		// ���ӵ�е�ָ����,param=1ΪLOGIN
		STATUS_COACH_SYN			= 1023,		// ����ӵ�е�ָ������,param=1ΪLOGIN
		STATUS_COACH_UNDERSTAND		= 1024,		// ָ�����״̬,power=Uplevtime,param=ʱ��(����),wparam=ʣ�¿ɳ�uplevtime
		STATUS_ACTION_ADD_BATTLEEFFECT=1025,			// ����ս����״̬
		STATUS_TRANS_DEC_BATTLEEFFECT=1026,			// ս�����½�״̬
//		STATUS_TRANS_RAGE			= 1027,		// �����״̬
//		STATUS_GENERATOR_WEAK		= 1028,		// ����������
		STATUS_TRUMP_DYING_RAGE     = 1035,             //������
		STATUS_BROTHER_BE_APPLIED_TRANSFER = 1039,//�������ֵ�˲��
		STATUS_BROTHER_TRANSFER		= 1040,		// �ֵ�˲��
		STATUS_CARRY_WOOD			= 1041,		// ����״̬
		STATUS_GODTRANSPORT			= 1042,		//���ɴ���״̬
		STATUS_USER_DIE				= 1043,		//�������15s����ʱ
		STATUS_GUARD_CALLOUT_DISABLE = 1050, // ������ֹ����״̬
//		STATUS_GUARD_SPIRITSKILL0_COLD = 1051,//����������ȴʱ�䣬Ŀǰֻ��һ��
//		STATUS_GUARD_BETHREATEN     = 1055,  //��̫������״̬

//		STATUS_GUARD_DECMAXHP		= 1060,	//�����������������½�һ���ٷֱ�   �����������������������������½�һ���ٷֱ�
//		STATUS_GUARD_DECHP			= 1061,	//��������HP��ǰֵ�½�һ���ٷֱ�   //��������������������HP��ǰֵ�½�һ���ٷֱ�
//		STATUS_GUARD_STOPHEAL		= 1062,	//һ��ʱ�����޷��ظ�����
//		STATUS_GUARD_STOPSKILL		= 1063,	//���������һ��ʱ���ڽ�ֹʹ�ò��ݼ���
#ifdef _ACCELERATE_MOVE
//		STATUS_PM_ACCE_MOVE			= 1064,	//�����ƶ�
//		STATUS_PM_FLY_MOVE			= 1065,	//Ʈ��״̬
#endif // _ACCELERATE_MOVE

		STATUS_BROTHER_SWEAR        = 1070, //�ֵܽ��״̬()
//		STATUS_DIGING		        = 1071, //�ھ�״̬

//		STATUS_COLLECT				= 1075, //�ռ�״̬
		STATUS_FIRST_WOLF,
		STATUS_SECOND_WOLF,

		STATUS_DOMAIN_ENTER			= 1080, //��������
		STATUS_DOMAIN_LEAVE			= 1081, //�뿪����
        
		STATUS_USER_WORSHIP			= 1090, //�׼�״̬
		STATUS_SUCKBLOOD_EXPIATE,			//��Ѫ����ϴ����	09-09-17

		STATUS_CALL_EVENT_STOPALL	= 2000, //CALLEVENT��״̬
		//////////////////////////////////////////////////////////////////////////
		// STATUS_VARIATION_WERWOLF                    =  10000, // ����״̬  �����±���״̬֮һ��Ҫ�������״̬ �������ɾ��ʱ�Ĳ���
														
		STATUS_WERWOLF_LEV1							=  10000,  // �ޱ������Ե�����״̬���Ϊ10000��һ������10001����������
		STATUS_WERWOLF_LEV2            				=  10001, 

		STATUS_RAPTOR_VARIATION_LEV1            	=  10100, //���ݱ��죬����Ϊ���ݱ�����������Σ���Ӧ����״̬���Ϊ10100��һ������10101����������
		STATUS_RAPTOR_VARIATION_LEV2            	=  10101, 		
		
		STATUS_BAT_VARIATION_LEV1					=  10110, //������죬����Ϊ���������������Σ���Ӧ����״̬���Ϊ10110��һ������10111����������
		STATUS_BAT_VARIATION_LEV2					=  10111,

		STATUS_SHARK_VARIATION_LEV1					=  10200, //������죬����Ϊ���������������Σ���Ӧ����״̬���Ϊ10200��һ������10201����������
		STATUS_SHARK_VARIATION_LEV2            		=  10201,

		STATUS_DOLPHIN_VARIATION_LEV1            	=  10210, //������죬����Ϊ���������������Σ���Ӧ����״̬���Ϊ10210��һ������10211����������
		STATUS_DOLPHIN_VARIATION_LEV2            	=  10211,

		STATUS_BEAR_VARIATION_LEV1					=  10300, //�ܻ�����죬����Ϊ�ܻ��������������Σ���Ӧ����״̬���Ϊ10300��һ������10301����������
		STATUS_BEAR_VARIATION_LEV2            		=  10301,

		STATUS_LEOPARD_VARIATION_LEV1            	=  10310, //��������죬����Ϊ�����������������Σ���Ӧ����״̬���Ϊ10310��һ������10311����������
		STATUS_LEOPARD_VARIATION_LEV2            	=  10311,

		STATUS_CATTLE_VARIATION_LEV1            	=  10320, //ţ������죬����Ϊţ���������������Σ���Ӧ����״̬���Ϊ10320��һ������10321����������
		STATUS_CATTLE_VARIATION_LEV2            	=  10321,
	
		STATUS_VAMPIRE_UNDER_SUNSHINE            	=  10333, // ��Ѫ����ɹ״̬
		STATUS_VAMPIRE_UNDER_SAINT_LIGHT            =  10334, // ��Ѫ��ʥ������״̬
		STATUS_VAMPIRE_UNDER_DOMAIN_LIGHT			=  10335, // ��Ѫ��������������״̬

		STATUS_DIVE                                 =  10336, //Ǳˮ״̬  
        STATUS_CONK                                 =  10337, //����״̬ 

		STATUS_NOMAL_DOMAIN_MAP						=  10338,
		STATUS_NOMAL_DOMAIN_REGION					=  10339,

		STATUS_SAN_SHIELD							=  10342,	//��ʥ����״̬
		STATUS_JUSTICE								=  10343,	//����״̬
		STATUS_LIGHTNING_SHAKE						=  10344,	//���״̬

		STATUS_BLEEDING								=  10345, // ��Ѫ
		STATUS_FREEZING								=  10346, // ����״̬
		STATUS_BURNING								=  10347, // ����״̬

		STATUS_WITHBOMB								=  10348, // ը������

		STATUS_HEMO_SHADOW							=  10349, // ѪӰ��
							
		STATUS_QUICK_EQUIPAMMO						=  10350, // 
		STATUS_ADD_LIFE								=  10351, //��Ѫ״̬
		STATUS_MOVE_VEL_SLOWLY						=  10352, //�����ٶ�״̬
		STATUS_DIZZY								=  10353, //ѣ��״̬

		STATUS_CAP									=  20200,										      //��ץס2��ǰ
		STATUS_CAPOVER								=  20201,										  //��ץס2���
		STATUS_CAPPOWER								=	20202,									  //��ץסǿ��״̬

// ongoing

//////////////////////////////////////////����-��ȴʱ��////�鷳����ȴ״̬��һ�ݵ�IsInColdTime(OBJID idItem, int nFunctionCode)������//////////////////////		
//  		STATUS_TRUMP_COLD_TIME_MASK = 2000,
// 		STATUS_TRUMP_COLD_TIME_FORBID_FLY					= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_FORBID_FLY),				    //����-����						
// 		STATUS_TRUMP_SELFBLAST_DECBATTLEEFFECT_PROTECTTIME	= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_SELFBLAST_DEC_BATTLEEFFECT), //����-�Ա�������ս�������ܱ���ʱ��
// 		STATUS_TRUMP_DODGEDECHP_PROTECTTIME					= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_DODGE_DEC_HP),				//����-MISS��Ѫ				
// 		STATUS_TRUMP_DAMAGE_SUCK_HP_PROTECTTIME				= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_DAMAGE_SUCK_HP),				//������Ѫ���ܱ���ʱ��			
// 		STATUS_TRUMP_COLD_TIME_HP_CURSE						= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_HP_CURSE),				    //����������					
// 		STATUS_TRUMP_FLOATCANNON_SUPPORT_HP_PROTECTTIME		= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_FLOATCANNON_SUPPORT_HP),		//�����ĸ���������ת�ƹ��ܱ���ʱ��
// 		STATUS_TRUMP_IDENT_EQUIP_PROTECTTIME				= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_IDENT_EQUIP),				//������װ����������
// 		STATUS_TRUMP_COLD_THE_SAME_TYPE_SPIRIT_BATTLEEFFECT  = TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_THE_SAME_TYPE_SPIRIT_BATTLEEFFECT),		//����-ͬ�����ս������������ʱ��						
// 		STATUS_TRUMP_COLD_RAND_TRANSPOS_IN_LITTE_RANGE		= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_RAND_TRANSPOS_IN_LITTE_RANGE),           //����-С˲������ʱ��
// 		STATUS_TRUMP_COLD_REGION_FORBID_TRANS_POS			= TRUMP_STATUS_KEY(STATUS_TRUMP_COLD_TIME_MASK, TRUMP_TYPE_REGION_FORBID_TRANS_POS),		        //����-˲�Ƶ������ֹ���				
//////////////////////////////////////////����-��Чʱ��ʱ��///////////////////////////////////////////////				
// 		STATUS_TRUMP_WORKING_TIME_MASK= 3000,
// 		STATUS_TRUMP_WORKING_TIME_RADIO_SEARCH			    = TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_RADIO_SEARCH),			 //����-�״�ϵͳ
// 		STATUS_TRUMP_WORKING_TIME_FORBID_FLY				= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_FORBID_FLY),			     //����-����								
// 		STATUS_TRUMP_WORKING_TIME_BE_WATCH_EQUIP_GAIN_MONEY	= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_BE_WATCH_EQUIP_GAIN_MONEY),//����-��켺��װ���շ�		
// 		STATUS_TRUMP_WORKING_TIME_BE_DELAY_REBORN_TIMES		= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_DELAY_BEKILLER_REBORN_TIMES),  // ����-���ָ�����ʱ
// 		STATUS_TRUMP_WORKING_TIME_BE_DELAY_REBORN_BY_OTHER_TIMES = TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_BE_REBORN_BY_OTHER_TIMES),// ����-�������Ӳ��ɱ�����				
// 		STATUS_TRUMP_WORKING_TIME_HIDE_BATTLEEFFECT			= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_HIDE_BATTLEEFFECT),		     // ����-ս����αװ		
// 		STATUS_TRUMP_CHANGE_BEKILER_GHOSTTYPE				= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_CHANGE_BEKILER_GHOSTTYPE),    //����-�ı�������״̬
// 		STATUS_TRUMP_REFULSE_MARRY							= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_REFULSE_MARRY),			    //�����ľܾ����
// 		STATUS_TRUMP_REFULSE_TRADE							= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_REFULSE_TRADE),				//�����ľܾ�����
//  		STATUS_TRUMP_REGION_FORBID_TRANS_POS				= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_REGION_FORBID_TRANS_POS),		//����-˲�Ƶ������ֹ���		
// 		STATUS_TRUMP_REFUSE_MAKE_FREIND						= TRUMP_STATUS_KEY(STATUS_TRUMP_WORKING_TIME_MASK, TRUMP_TYPE_REFUSE_MAKE_FREIND),			//����-�ܾ��ύ��Ϣ
};

enum { STATUS_OTHER, STATUS_GOOD, STATUS_BAD };			// STATUS_OTHER û�����ͬʱ3��������


enum STATUS_VARIATION_LEV
{
	STATUS_VARIATION_LEV_NONE = 0, // û������״̬;
	STATUS_VARIATION_LEV_1    = 1, // һ������״̬
	STATUS_VARIATION_LEV_2    = 2, // ��������״̬	
};
// const int VARIATION_AFFECT[4][4] = 
// { 
// 	 5, 15, 10,  5;
// 	10, 10, 10, 15;
// 		
// }

enum GENIC_VARIATION_AFFECT     //�����ʱû�����  ֻ���ȳ�����������
{	
	//�����������������״̬
	
	// ���ݱ���״̬, Ӱ������������� 
	//��Ҫ ��������5%���������15%�������½�10%���������5%
	RAPTOR_VARIATION_LIFE_REDUCE				=  5,  
	RAPTOR_VARIATION_ATTACK_ENHANCE				= 15,
	RAPTOR_VARIATION_DEFENCE_REDUCE				= 10,  
	RAPTOR_VARIATION_JOOK_ENHANCE				=  5,
	
	
	// 	�������״̬����ҪӰ������������£�	
	// 	2  ��������10%���������10%�������½�10%���������15%�������ϱ�����Ϊ�ݶ�ֵ����������ֵ�߻�ȷ����	
	BAT_VARIATION_LIFE_REDUCE					= 10,
	BAT_VARIATION_ATTACK_ENHANCE				= 10,
	BAT_VARIATION_DEFENCE_REDUCE				= 10,
	BAT_VARIATION_JOOK_ENHANCE					= 15,
	
	// 	
	//ˮ���������������״̬
	
	// 	�������״̬����ҪӰ������������£� 	
	// 	2  ��������10%���������10%���������5%��ˮ���ƶ��ٶ�����10%�����ϱ�����Ϊ�ݶ�ֵ����������ֵ�߻�ȷ����	
	SHARK_VARIATION_LIFE_REDUCE					= 10,
	SHARK_VARIATION_ATTACK_ENHANCE				= 10,
	SHARK_VARIATION_JOOK_ENHANCE				=  5,
	SHARK_VARIATION_SPEED_ENHANCE				= 10,
	
	// 	�������״̬����ҪӰ������������£�// 	
	// 	2  ħ�����10%����������5%���������10%��ˮ���ƶ��ٶ�����5%�������ϱ�����Ϊ�ݶ�ֵ����������ֵ�߻�ȷ����	
	DOLPHIN_VARIATION_MAGIC_ENHANCE				= 10,
	DOLPHIN_VARIATION_ATTACK_REDUCE				=  5,
	DOLPHIN_VARIATION_JOOK_ENHANCE				= 10,
	DOLPHIN_VARIATION_SPEED_ENHANCE				=  5,
	
	
	// 	½���������������״̬
	
	// 	�������״̬����ҪӰ������������£� 	
	// 	2  �������5%���������10%�����ܽ���10%���ƶ�����5%�����ϱ�����Ϊ�ݶ�ֵ����������ֵ�߻�ȷ����	
	BEAR_VARIATION_ATTACK_ENHANCE				=  5,
	BEAR_VARIATION_DEFENCE_REDUCE				= 10,
	BEAR_VARIATION_JOOK_ENHANCE					= 10,
	BEAR_VARIATION_SPEED_REDUCE					=  5,
	
	
	// 	�������״̬����ҪӰ������������£� 	
	// 	2  ��������5%����������3%���������5%���ƶ��ٶ�����15%�������ϱ�����Ϊ�ݶ�ֵ����������ֵ�߻�ȷ����
	LEOPARD_VARIATION_LIFE_REDUCE				=  5,
	LEOPARD_VARIATION_ATTACK_REDUCE				=  3,
	LEOPARD_VARIATION_JOOK_ENHANCE				=  5,
	LEOPARD_VARIATION_SPEED_ENHANCE				= 15,
	
	
	// 	ţ�����״̬����ҪӰ������������£� 	
	// 	2  �������10%���������10%�����ܽ���5%���ƶ��ٶȽ���5%�������ϱ�����Ϊ�ݶ�ֵ����������ֵ�߻�ȷ������
	CATTLE_VARIATION_LIFE_ENHANCE				= 10,
	CATTLE_VARIATION_ENERGY_ENHANCE				= 10,
	CATTLE_VARIATION_JOOK_REDUCEE				=  5,
	CATTLE_VARIATION_SPEED_REDUCE				=  5,	
};


enum STATUSTYPE{ 
	STATUSTYPE_LEAVETIMES	=1,	//ʣ�����
	STATUSTYPE_REMAINTIME	=2, //ʣ��ʱ��
	STATUSTYPE_ENDTIME		=4,	//����ʱ��
	STATUSTYPE_ALL          = STATUSTYPE_REMAINTIME|STATUSTYPE_LEAVETIMES|STATUSTYPE_ENDTIME,
	STATUSTYPE_MEMORY		=8, //�ڴ���
	STATUSTYPE_SYS			=16,	//���һ��ʱ��ʹ�ô���	
};
								
enum ROLE_STATUS
{
//		ROLE_STATUS_NORMAL			= 0,
//		ROLE_STATUS_POISON			= 200000000+STATUS_POISON,
		ROLE_STATUS_DIE				= 300000000+STATUS_DIE,
//		ROLE_STATUS_PKVALUE			= 300000000+STATUS_PKVALUE,
		ROLE_STATUS_TEAMLEADER		= 300000000+STATUS_TEAMLEADER,
		ROLE_STATUS_WING			= 300000000+STATUS_WING,
//		ROLE_STATUS_DISAPPEARING	= 300000000+STATUS_DISAPPEARING,
//		ROLE_STATUS_PKSWITCH		= 300000000+STATUS_PKSWITCH,
//		ROLE_STATUS_UNDERWRAPS		= 300000000+STATUS_UNDERWRAPS,
//		ROLE_STATUS_FIRST_WOLF      = 300000000+STATUS_FIRST_WOLF,
//		ROLE_STATUS_SECOND_WOLF     = 300000000+STATUS_SECOND_WOLF,
};

enum STATUSSITID
{
	STATUS_SIT_GOOD=0,	// ״̬�û�	enum { STATUS_OTHER, STATUS_GOOD, STATUS_BAD };	
	STATUS_SIT_LEVEL,	// ״̬����
	STATUS_SIT_ID,		// ״̬��ID
	STATUSSITID_END
};

//�����������ö����Ϣ
enum SPIRITDATA
{
	SPIRITDATA_ID = 0,
	SPIRITDATA_NAME,
	SPIRITDATA_OWNERTYPE,	
	SPIRITDATA_OWNERID,
	SPIRITDATA_PLAYERID,
	SPIRITDATA_TYPE,
	SPIRITDATA_EXP,
	SPIRITDATA_LEVEL,
	SPIRITDATA_LIFE,		
	SPIRITDATA_POSITION,
	SPIRITDATA_COLOR,			// ��¼��������Ϳɫ
	SPIRITDATA_REBORN_CNT,		// ת������
	SPIRITDATA_NUMBER,
	SPIRITDATA_GUARDSKILL1,		// ������������1�����ƺ��ģ�
	SPIRITDATA_GUARDSKILL2,		// ������������2�����ƺ��ģ�
	SPIRITDATA_GUARDSKILL3,		// ������������3�����ƺ��ģ�
	SPIRITDATA_GUARDSKILL4,		// ������������4�����ƺ��ģ�
	SPIRITDATA_EVENT_REC_BIN,	// �¼�����(������)
	SPIRITDATA_EN_STATE,
	SPIRITDATA_NATIVEPLACE = SPIRITDATA_EN_STATE,
	SPIRITDATA_WEAPON_SELECT,	// ��¼��������ʹ��λ��
								// Ͷ��״���½�Ů����ʱ�����1-28ȡֵ�������Ů�����¾�������
								// ʮ��λ����λ��ʾ���ڵ��ߵĵ���ʱ�䣬��ʽΪ��YYYYMMDD
	SPIRITDATA_EATHERUPLEV_DATE,	// ���ǻ�����ļ�¼ʱ��
	SPIRITDATA_MAINSKILL_DATA,	// ���������ܵ�Ч��
	SPIRITDATA_GUARDSKILL5,		// ������������5�����ƺ��ģ�
	SPIRITDATA_GUARDSKILL6,		// ������������6�����ƺ��ģ�
	SPIRITDATA_GUARDSKILL7,		// ������������7�����ƺ��ģ�
	SPIRITDATA_GUARDSKILL8,		// ������������8�����ƺ��ģ�
	SPIRITDATA_FACTION,			// ��������
	SPIRITDATA_MODEL_LEV,		// ��ǰ�����ͼ�
	SPIRITDATA_METE_LEV,			// ������¼�û���ת��ǰ�ĵȼ��;���ֵ
	SPIRITDATA_METE_SPIRITTYPE,	// ������¼�û���ת��ǰ��������
	SPIRITDATA_VALUE_WEAPON,		// ��¼�������������ϳ�ָ��
	SPIRITDATA_VALUE_ARMET,		// ��¼��������ͷ��װ���ϳ�ָ��		
	SPIRITDATA_VALUE_ARMOR,		// ��¼�������Ŀ���װ���ϳ�ָ��			
	SPIRITDATA_VALUE_BRACELET,	// ��¼������������װ���ϳ�ָ��				
	SPIRITDATA_VALUE_NECKLACE,	// ��¼������������װ���ϳ�ָ��				
	SPIRITDATA_VALUE_SHOES,		// ��¼��������Ь��װ���ϳ�ָ��
	SPIRITDATA_ACTIVITY_DATE,	//�����¼�ʱ��		
	SPIRITDATA_EVENT_REC_MET,	//�¼�����
	SPIRITDATA_SPECIAL_FLAG,     //��

	SPIRITDATA_CHK_SUM,		
	SPIRITDATA_NIMBUS,
	SPIRITDATA_NIMBUSUSAGE,	
	SPIRITDATA_HAIR,
	SPIRITDATA_DELETE_STATE,
	SPIRITDATA_ABILITY_LIMIT1,
	SPIRITDATA_ABILITY_LIMIT2,
	SPIRITDATA_UPGRADETIME,
	SPIRITDATA_UPGRADE_TIMES,
	SPIRITDATA_CONTRACT_TIME,    //���ʱ��
   	SPIRITDATA_DIALECT,          //Guard speak language
	SPIRITDATA_LOOKFACE,
	SPIRITDATA_SYNDICATE,
	SPIRITDATA_RELATIONSHIP,

	//unused
	SPIRITDATA_HOTDEF		= SPIRITDATA_GUARDSKILL1,
	SPIRITDATA_ShAKEDEF		= SPIRITDATA_GUARDSKILL2,
	SPIRITDATA_COLDDEF		= SPIRITDATA_GUARDSKILL3,
	SPIRITDATA_DECAYDEF		= SPIRITDATA_GUARDSKILL4,
	SPIRITDATA_TECHNOPOINT,		
	SPIRITDATA_TECHNOUSAGE0,		
	SPIRITDATA_TECHNOUSAGE1,		
	SPIRITDATA_TECHNOUSAGE2,		
	SPIRITDATA_TECHNOUSAGE3,		
	SPIRITDATA_TECHNOUSAGE4,		
	SPIRITDATA_RESEARCH1,		// ��¼�û����һ��Ƽ������������0��ʾ�ÿƼ���δ������1��100��ʾ�ÿƼ������ɶ�
	SPIRITDATA_RESEARCH2,		
	SPIRITDATA_RESEARCH3,		
	SPIRITDATA_RESEARCH4,		
	SPIRITDATA_RESEARCH5,		
	SPIRITDATA_RESEARCH6,
	

	// ս�� ���������ĸ�������
	SPIRITDATA_STEED_START	 = SPIRITDATA_VALUE_WEAPON,
	SPIRITDATA_STEED_SMOCK	 = SPIRITDATA_VALUE_ARMET,			// ս�������
	SPIRITDATA_STEED_SHIELD	 = SPIRITDATA_VALUE_ARMOR,			// ս��Ļ���
	SPIRITDATA_STEED_SADDLE	 = SPIRITDATA_VALUE_BRACELET,		// ս����� 
	SPIRITDATA_STEED_PENDANT = SPIRITDATA_VALUE_NECKLACE,		// ս��ĹҼ�
};

enum RBN_TYPE_DATA
{
	RBN_TYPE_DATA_Id,
	RBN_TYPE_DATA_Spirit_type,
	RBN_TYPE_DATA_Rbn_times,
	RBN_TYPE_DATA_Armet_min,
	RBN_TYPE_DATA_Armet_max,
	RBN_TYPE_DATA_armor_min,
	RBN_TYPE_DATA_armor_max,
	RBN_TYPE_DATA_bracelet_min,
	RBN_TYPE_DATA_bracelet_max,
	RBN_TYPE_DATA_necklace_min,
	RBN_TYPE_DATA_necklace_max,
	RBN_TYPE_DATA_shoes_min,
	RBN_TYPE_DATA_shoes_max
};

enum OWNERTYPE
{
	OWNER_NONE			= 0,
	OWNER_USER			= 1,
	OWNER_SYN			= 2,
	OWNER_NPC			= 3,
	OWNERTYPE_BLUEPRINT	= 4,	// �����ͼ
	OWNER_ITEM			= 4,
	OWNER_SPIRIT		= 5,
	OWNER_FAMILY		= 6,
	OWNER_TEAM			= 7,
	OWNER_DUN			= 8,
	OWNERTYPE_DEPOT		= 20,  //δ��
	
	OWNERTYPE_COMMON	= 40,  //�ֿ����
	OWNERTYPE_SPIRIT1	= 50,  //��һ��������
	OWNERTYPE_SPIRIT2	= 51,  //�ڶ���������
	
	OWNERTYPE_SPIRIT_STANDBY	= 53,  //stand by  �ѳ���������
	OWNERTYPE_SPIRIT_REST		= 63,  //rest ��Ӫ��
	OWNERTYPE_SPIRIT_CAGE		= 64,  //cage  ������������
	OWNERTYPE_SPIRIT_DUN	= 65,  //���³���������������
	OWNERTYPE_SPIRIT_DUN_FREE	= 66,  //����״̬�������������
};

enum SPIRIT_RELATIONSHIP
{
	 //add by ccw_xxx ���������⽻������
	_SPIRIT_SPECIAL_MONOPOLY1 =     0x1000000,   //16777216
	_SPIRIT_SPECIAL_MONOPOLY2 =     0x2000000,   //33554432
};

// ����ְҵ����
enum Guard_TYPE
{
	GUARD_TYPE_BEGIN = 1,
	GUARD_TYPE_Eunuch = 1,  // ̫��
	GUARD_TYPE_WU	=2,//��ְ���
	GUARD_TYPE_FORTUNETELLER	= 3,	//��������
	GUARD_TYPE_Smith  = 4,  // ����
	GUARD_TYPE_JapanVagabond=5, // �ձ�����
	GUARD_TYPE_NOBLE = 6,     //������λ
	GUARD_TYPE_Mister = 7,  // ����
	GUARD_TYPE_CAPTOR = 8,  //����
	GUARD_TYPE_DOCTOR = 9,  //ҽ��
	GUARD_TYPE_Callet = 13, // ��¥Ů��
	GUARD_TYPE_KidShow  = 17, // ��ˣ
	GUARD_TYPE_XiaKe  = 18, // ����
	GUARD_TYPE_DRILLMASTER = 19,//��ͷ
	GUARD_TYPE_THIEF	= 23,	//С͵
	GUARD_TYPE_KILLER = 24,    //ɱ��
	GUARD_TYPE_BANDIT = 25,    //ǿ��
	GUARD_TYPE_LADY   = 27, // �ټ�С��

	GUARD_TYPE_END = 32,
};
// 0.
// 1  | 5010000 | ��͢��
// 2  | 5020000 | ��ְ���
// 3  | 5030000 | ����
// 4  | 5040000 | ����
// 5  | 5050020 | �������
// 6  | 5060000 | ������λ
// 7  | 5070000 | ����
// 8  | 5080000 | ����
// 9  | 5090000 | ҽ��
// 10 | 5100000 | ��ʿ
// 11 | 5110000 | ��ؤ
// 12 | 5120000 | Ϸ��
// 16 | 5160000 | ����
// 17 | 5170000 | ��ˣ
// 18 | 5180010 | ����
// 19 | 5190000 | ��ͷ
// 20 | 5200000 | ��ʦ
// 21 | 5210010 | ����
// 22 | 5220010 | ����
// 23 | 5230000 | ��
// 24 | 5240010 | ɱ��
// 25 | 5250000 | ǿ��
// 27 | 627XXXX | �ټ�С��
// 28 | 5280000 | ʦү
// 29 | 5290000 | ����
// 30 | 5300000 | �̷�
// 31 | 5310010 | ��С��
// 32 | 5320000 | ũ��

enum
{
	SPIRIT_EN_STATE_LIMIT=0,		//����״̬
	SPIRIT_EN_STATE_NORMAL,		//����״̬
	SPIRIT_EN_STATE_OVERRUN,		//����״̬
};

enum
{
	FLOATCANNON_NOATTACK,		//������״̬
	FLOATCANNON_ATTACK,			//����״̬
};

enum IDENT_BY_WHAT
{ 
	IDENT_BYREEL, 
	IDENT_BYNPC, 
	IDENT_BYTRUMP, 
};

enum 
{//�����󶨺ͽ��״̬
	SPIRIT_BLOOD_BOND_STATE = 0x01,
	SPIRIT_BLOOD_BOND_WAITFOR_CLEAR_STATE = 0x02,
};

//װ�׺��ĵĶ���
enum{
	SPIRIT_CORE_FOOT_BEGIN	= 0,								//��
	SPIRIT_CORE_FOOT_SPECIAL	= SPIRIT_CORE_FOOT_BEGIN + 3,
	SPIRIT_CORE_HEAD_BEGIN	= 4,								//ͷ��
	SPIRIT_CORE_HEAD_SPECIAL	= SPIRIT_CORE_HEAD_BEGIN + 8,
	SPIRIT_CORE_RHAND_BEGIN	= 13,								//����
	SPIRIT_CORE_RHAND_SPECIAL	= SPIRIT_CORE_RHAND_BEGIN + 4,
	SPIRIT_CORE_LHAND_BEGIN	= 18,								//����
	SPIRIT_CORE_LHAND_SPECIAL	= SPIRIT_CORE_LHAND_BEGIN + 4,
	SPIRIT_CORE_CHEST_BEGIN	= 23,								//��
	SPIRIT_CORE_CHEST_SPECIAL	= SPIRIT_CORE_CHEST_BEGIN + 6,
	SPIRIT_CORE_HEART_BEGIN	= 30,								//��
	SPIRIT_CORE_HEART_SPECIAL	= SPIRIT_CORE_HEART_BEGIN + 7,
	SPIRIT_CORE_SPECIAL	= 38,									//��������
};


//////////////////////////////////////////////////////////////////////
enum SPIRITVAR{
	SPIRITDATA_SHIELD_ENERGY=0,
	SPIRITDATA_DATA_END,
};

//////////////////////////////////////////////////////////////////////
enum SPIRIT_SORT
{//����-�Ը��ֻ����˺���������
	SPIRIT_SORT_UNKOWN	  = 0, // δ֪
	SPIRIT_SORT_NEAR_FIGHT = 1, // ��ս
	SPIRIT_SORT_FAR_FIGHT  = 2, // Զս
	SPIRIT_SORT_TRANSFORM  = 3, // ����		
};

enum SPIRIT_SUB_TYPE
{//����-�Ը��ֻ����˺���������
	SPIRIT_SUB_TYPE_NORMAL			=  0,
	SPIRIT_SUB_TYPE_TRAIN_0			= 10,  SPIRIT_SUB_TYPE_TRAIN_1		= SPIRIT_SUB_TYPE_TRAIN_0		+ 10,
	SPIRIT_SUB_TYPE_MIDDLE_0			= 12,  SPIRIT_SUB_TYPE_MIDDLE_1		= SPIRIT_SUB_TYPE_MIDDLE_0		+ 10,
	SPIRIT_SUB_TYPE_LIFE_0			= 14,  SPIRIT_SUB_TYPE_LIFE_1		= SPIRIT_SUB_TYPE_LIFE_0			+ 10,
	SPIRIT_SUB_TYPE_MACHINE_0		= 15,  SPIRIT_SUB_TYPE_MACHINE_1		= SPIRIT_SUB_TYPE_MACHINE_0		+ 10,
	SPIRIT_SUB_TYPE_ANTI_HOT_0		= 16,  SPIRIT_SUB_TYPE_ANTI_HOT_1	= SPIRIT_SUB_TYPE_ANTI_HOT_0		+ 10,
	SPIRIT_SUB_TYPE_ANTI_ICE_0		= 17,  SPIRIT_SUB_TYPE_ANTI_ICE_1	= SPIRIT_SUB_TYPE_ANTI_ICE_0		+ 10,
	SPIRIT_SUB_TYPE_ANTI_SHAKE_0		= 18,  SPIRIT_SUB_TYPE_ANTI_SHAKE_1	= SPIRIT_SUB_TYPE_ANTI_SHAKE_0	+ 10,
	SPIRIT_SUB_TYPE_ANTI_MEDICAL_0	= 19,  SPIRIT_SUB_TYPE_ANTI_MEDICAL_1= SPIRIT_SUB_TYPE_ANTI_MEDICAL_0 + 10,
};

//���ö��Ϊ�˰������صĻ���ͳһ����
enum SPIRIT_POSITION
{
	SPIRIT_POSITION_VAN,      //��������ȷ�Ӫλ�õĻ���
	SPIRIT_POSITION_REST,     //������Һ�Ӫλ�õĻ���
	SPIRIT_POSITION_LIMIT,     //������Һ�Ӫλ�õĻ���
};

enum SPIRITUPLEVELDATA{
	SPIRITLEVELDATA_ORIGIN_TYPE=1,
	SPIRITLEVELDATA_REQ1, SPIRITLEVELDATA_REQBEGIN = SPIRITLEVELDATA_REQ1,
	SPIRITLEVELDATA_REQ2,
	SPIRITLEVELDATA_REQ3,
	SPIRITLEVELDATA_REQ4,
	SPIRITLEVELDATA_REQ5,
	SPIRITLEVELDATA_REQ6,
	SPIRITLEVELDATA_ADD1, SPIRITLEVELDATA_ADDBEGIN = SPIRITLEVELDATA_ADD1,
	SPIRITLEVELDATA_ADD2,
	SPIRITLEVELDATA_ADD3,
	SPIRITLEVELDATA_ADD4,
	SPIRITLEVELDATA_ADD5,
	SPIRITLEVELDATA_ADD6,
	SPIRITLEVELDATA_POS,
	SPIRITLEVELDATA_ITEMTYPE,
	SPIRITLEVELDATA_REGISTER,
	SPIRITLEVELDATA_REQUIRE_LEVEL,
};

enum GUARD_EQUIPVALUE_DATA
{
	GUARD_EQUIPVALUE_DATA_ID,
	GUARD_EQUIPVALUE_DATA_EQUIP_TYPE,
	GUARD_EQUIPVALUE_DATA_STAR_LEV,
	GUARD_EQUIPVALUE_DATA_EQUIP_VALUE,
	GUARD_EQUIPVALUE_DATA_UPLEVTIME,
};

enum GUARD_EQUIP_VALUE
{
	GUARD_EQUIP_VALUE_WEAPON = 0,
	GUARD_EQUIP_VALUE_ARMET,
	GUARD_EQUIP_VALUE_ARMOR,
	GUARD_EQUIP_VALUE_BRACELET,
	GUARD_EQUIP_VALUE_NECKLACE,
	GUARD_EQUIP_VALUE_SHOES,
	GUARD_EQUIP_VALUE_MAX_NUM,
};

enum TRANSTYPEDATA{
	TRANSTYPEDATA_ID,
	TRANSTYPEDATA_SORT,
	TRANSTYPEDATA_NAME,
	TRANSTYPEDATA_DATA0,
	TRANSTYPEDATA_DATA1,
	TRANSTYPEDATA_DATA2,
	TRANSTYPEDATA_DATA3,
	TRANSTYPEDATA_DATA4,
	TRANSTYPEDATA_DATA5,
	TRANSTYPEDATA_DATA6,
	TRANSTYPEDATA_DATA7,
	TRANSTYPEDATA_DATA8,
	TRANSTYPEDATA_DATA9,
	TRANSTYPEDATA_DATA10,
	TRANSTYPEDATA_DATA11,
	TRANSTYPEDATA_DATA12,
	TRANSTYPEDATA_DATA13,
	TRANSTYPEDATA_DATA14,
	TRANSTYPEDATA_DATA15,
	TRANSTYPEDATA_DATA16,
	TRANSTYPEDATA_DATA17,
	TRANSTYPEDATA_DATA18,
	TRANSTYPEDATA_DATA19,
	TRANSTYPEDATA_SIZE,
	TRANSTYPEDATA_ATK_SPEED,
	TRANSTYPEDATA_ATK_DELAY,
};	

//////////////////////////////////////////////////////////////////////
// req�Ķ��壺
enum { SPIRITNEED_SWORD=1, SPIRITNEED_GUN, SPIRITNEED_LASER, SPIRITNEED_EN, SPIRITNEED_AMMO, 
		SPIRITNEED_ARMOR, SPIRITNEED_FIST, SPIRITNEED_SHIELD, SPIRITNEED_MISSILE, SPIRITNEED_MORPH_ATTACK, 
		SPIRITNEED_MORPH_ENERGY, SPIRITNEED_CANNON, SPIRITNEED_MINE, SPIRITNEED_GEN, SPIRITNEED_EMPLACEMENT, 
		SPIRITNEED_EMPLACEMENT_HP, SPIRITNEED_ELECTRO, SPIRITNEED_PARTICLE, SPIRITNEED_FIELD, SPIRITNEED_SPIRIT_ATTACK, 
		SPIRITNEED_SPIRIT_HP, SPIRITNEED_REPAIR, SPIRITNEED_TRUNK, SPIRITNEED_GRENADE, SPIRITNEED_ASSISTANT, 
		SPIRITNEED_MAINTENANCE, SPIRITNEED_MORPH_POWER, SPIRITNEED_PHOTON_SHIELD, 
};
/*
	ʵ�彣��ǹ�������ڡ�EN����ҩ
	װ�ס�ȭ(��)���ܡ����������ι�����(����ս��)
	��������(��������)���ڡ����ס���������̨
	��̨HP����š����ӽ���������е��ս��
	��е��HP�������ֿ⡢���ס�Ԯ����
	ά������������װ��
*/


//////////////////////////////////////////////////////////////////////
/*
	װ����ְҵ����6λ������

	��  ϵ  ��  ��  ����
	��	        ��  
	 |   |   |   |   |
	 X   X   X   X   XX

  ����(ʮ��λ)		0�������ƣ�1�����࣬2������
  ϵ(��λ)			0�������ƣ�1����ս��2��Զս��3��������4������
  ��(ǧλ)			0�������ƣ�1��A�ͣ�2��B��
  �ȼ�(��λ)		0�������ƣ�1���������ã�2��һ���������¿��ã�3�����������¿��ã�4��ֻ��������������
  ����(ʮλ�͸�λ)	0�������ƣ�������ָ�����Ϳ�ʹ�ã��������塣
*/
// ���ͣ�
enum { SPIRITTYPE_FIGHT=1, SPIRITTYPE_FIGHT1, SPIRITTYPE_FIGHT2A, SPIRITTYPE_FIGHT2B, SPIRITTYPE_FIGHT3A, SPIRITTYPE_FIGHT3B, 
		SPIRITTYPE_GUN, SPIRITTYPE_GUN1, SPIRITTYPE_GUN2A, SPIRITTYPE_GUN2B, SPIRITTYPE_GUN3A, SPIRITTYPE_GUN3B, 
		SPIRITTYPE_ENERGY, SPIRITTYPE_ENERGY1, SPIRITTYPE_ENERGY2A, SPIRITTYPE_ENERGY2B, SPIRITTYPE_ENERGY3A, SPIRITTYPE_ENERGY3B, 
		SPIRITTYPE_REPAIR, SPIRITTYPE_REPAIR1, SPIRITTYPE_REPAIR2, SPIRITTYPE_REPAIR3, 
};

enum 
{	//����λ��ʮ��λ����λ��ǧλ����λ
	//DSTYPE_GUARD,1xxx00
	//����λ��ʮ��λ����λ�ֱ��ʾ��������id����λ��ʮ��λ������λ��ͬʱǧλ����λΪ0
	//DSTYPE_USER,300000,300001
	DSTYPE_USER_RED_FLOWER	= 00000,
	DSTYPE_USER_WHITE_FLOWER= 00001,
	DSTYPE_USER_OTHER		= 00000,	//such as:donate
	//ʮλ����λ
	//DSTYPE_GUARD,1xxx00XX
	DSTYPE_Guard_Star		= 00,
	DSTYPE_value_armet		= 01,
	DSTYPE_value_armor		= 02,
	DSTYPE_value_bracelet	= 03,
	DSTYPE_value_necklace	= 04,
	DSTYPE_value_shoes		= 05,

	//DSTYPE_USER,300000XX,300001XX
	DSTYPE_DAY_FLOWER		= 00,		//ÿ���ʻ��������а�
	DSTYPE_ALL_FLOWER		= 01,		//�������а�
	DSTYPE_ALL_DONATE		= 03,	//��λ�������а�

	DSTYPE_ALL_SUPERIOR     = 00,   //��������
	
	//�û�������а�3xxxxxxx
	DSTYPE_DAY_RED_FLOWER		= 00,		//ÿ�պ�õ���������а�
	DSTYPE_ALL_RED_FLOWER		= 01,		//��õ���������а�
	DSTYPE_DAY_WHITE_FLOWER		= 100,		//ÿ�հ�õ���������а�
	DSTYPE_ALL_WHITE_FLOWER		= 101,		//��õ���������а�
	DSTYPE_DONATE				= 03,		//��λ�������а�
    
	DSTYPE_SUPERIOR             = 03,       //��������

};



enum ITEM_POSITION{
		ITEMPOS_EQUIPBEGIN	= 1,

		ITEMPOS_SPIRITBEGIN = ITEMPOS_EQUIPBEGIN,
		ITEMPOS_THRUSTER	= ITEMPOS_EQUIPBEGIN,	// ����
		ITEMPOS_R_HAND		= 2,					// ����
		ITEMPOS_L_HAND		= 3,					// ����
		ITEMPOS_SHIELD		= ITEMPOS_L_HAND,		// ���ƣ�˫������û�ж��ƣ�02XXXXX��				
		ITEMPOS_SPIRIT_SHOES = 4,					// (Ь��)
		ITEMPOS_SPIRIT_COAT	= 5,					// (����)
		ITEMPOS_SPIRIT_HELMET= 6,			    	// ͷ����������0711XXX,0721XXX��
		ITEMPOS_SPIRIT_RING	= 7,					// ���ӣ�������0712XXX,0722XXX��
		ITEMPOS_SPIRIT_NECKLACE=8,					// ������������0713XXX,0723XXX��
		ITEMPOS_SPIRIT_JACKET= 9,					// ���ף�������188XXXX��
		ITEMPOS_SPIRIT_MOUNT = 10,					// ���������36XXXXX��
		ITEMPOS_ROBOT_WAISTBAND,                     // ���� (����)
		ITEMPOS_ROBOT_ARMGUARD,                      // ����
		ITEMPOS_ROBOT_R_FINGER_RING,                 // �ҽ�ָ
		ITEMPOS_ROBOT_L_FINGER_RING,	             // ���ָ��������
		ITEMPOS_PALA_SPEAR = 15,								 // ��ǹ��������
		ITEMPOS_TRUMP_EQUIP1,					    // ������9001XXXX  		
		ITEMPOS_TRUMP_EQUIP2,						// ������9001XXXX  
		ITEMPOS_TRUMP_EQUIP3,						// ������9001XXXX  
		ITEMPOS_TRUMP_EQUIP4,							// ������9001XXXX  
		ITEMPOS_TRUMP_EQUIP5,						// ������9001XXXX  

//------------------------------------
		ITEMPOS_SHOWEND		,
//------------------------------------
		ITEMPOS_EQUIPEND = ITEMPOS_SHOWEND	,

		ITEMPOS_BULLET_PROOF_VEST = 21,               // ������(ĩ��Σ������װ��λ)// TODO::MILO 11/17/2015

//------------------------------------
// �����ڳ����ڲ�ʹ�÷��㣬�������ݿ�
//------------------------------------
		ITEMPOS_ENGINEROOMBEGIN  = 20,
//------------------------------------
		ITEMPOS_ENGINE		=ITEMPOS_ENGINEROOMBEGIN,		// ������ 901
		ITEMPOS_AMPLIFIER	,						// ������ 902
		ITEMPOS_PACKITEM	,						// ������Ʒ 903
		ITEMPOS_ENPACK		,						// EN�� 904
		ITEMPOS_HEADLOOP	,						// ͷ����· 905
		ITEMPOS_ENERGYGENERATOR,					// ������������ 906
		ITEMPOS_CHIP		,						// ��������оƬ 907
		ITEMPOS_SPIRITHPGENERATOR,					// ����HP����ģ�� 908
		ITEMPOS_BUILDINMODULE,						// ��������ģ�� 909
		ITEMPOS_ENPACK_RESTORE_ACCELERATE,					  // En�ջظ������� 910		
		ITEMPOS_ENERGYGENERATOR_ACCELERATE,					  // �������������ظ������� 911			
		ITEMPOS_THRUSTER_RESTORE_ACCELERATE,				  // �ƽ����ظ�������912			
		ITEMPOS_TRUMP,										  // ����90000000~90099999
//------------------------------------
		ITEMPOS_ENGINEROOMEND,

//------------------------------------
		ITEMPOS_EXPBALL		= 40,					//����ֵ��
//------------------------------------
//------------------------------------
//------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ֿ�
		ITEMPOS_ENGINEROOM  = 51,					// ����
		ITEMPOS_BACKPACK	= 52,					// ����
		ITEMPOS_QUANTAPACK	= 53,					// ����������
		ITEMPOS_TRUCKPACK	= 54,					// ������Ʒ


		ITEMPOS_BULLETPACK	= 55,					// �ӵ���---���ڱ�ʾĿǰʹ�õ��ӵ�
		
		ITEMPOS_WEAPON_R_01	= 60,					// ������λ��һ��
		ITEMPOS_SHIELD_01	= 61,					// ������λ��һ��
		ITEMPOS_WEAPON_R_02	= 62,					// ������λ�ڶ���
		ITEMPOS_SHIELD_02	= 63,					// ������λ�ڶ���
		ITEMPOS_WEAPON_R_03	= 64,
		ITEMPOS_SHIELD_03	= 65,
		ITEMPOS_WEAPON_R_04	= 66,
		ITEMPOS_SHIELD_04	= 67,
		ITEMPOS_WEAPON_R_05	= 68,
		ITEMPOS_SHIELD_05	= 69,
		ITEMPOS_WEAPON_R_06	= 70,
		ITEMPOS_SHIELD_06	= 71,
		ITEMPOS_SPIRITEND,


		ITEMPOS_BOOTH		= 80,					// ��̯����Ʒ
		// ��ʦװ��
		ITEMPOS_USERBEGIN		= 81,
		//------------------------------------
		ITEMPOS_USERHEAD		= 81,			// 01 ͷλ�ã�  ��ʦװ����ñ��
		ITEMPOS_USERBODY		= 82,			// 02 ����λ�ã���ʦװ�����·�
		ITEMPOS_USERLEFTHAND	= 83,			// 03 ����
		ITEMPOS_USERRIGHTHAND	= 84,			// 04 ����	// 07 ˫��
		ITEMPOS_USERSHOES		= 85,			// 05 Ь��
		ITEMPOS_USERTREASURE	= 86,			// 06 ��Ʒ
		ITEMPOS_TRUCK_BEGIN		= 87,
		ITEMPOS_TRUCK_POS1 = ITEMPOS_TRUCK_BEGIN,
		ITEMPOS_TRUCK_POS2,
		ITEMPOS_TRUCK_POS3,
		ITEMPOS_TRUCK_POS4,
		ITEMPOS_TRUCK_END = ITEMPOS_TRUCK_POS4,
		//------------------------------------
		ITEMPOS_USEREND	,
		//------------------------------------
		ITEMPOS_MOUNT_SKIRT    =  ITEMPOS_EQUIPBEGIN ,       // ��ƥ����
		ITEMPOS_MOUNT_ARMOR    =  ITEMPOS_R_HAND,			 // ��ƥ����
		ITEMPOS_MOUNT_SADDLE   =  ITEMPOS_SHIELD,			 // ��
		ITEMPOS_MOUNT_ADORNING =  ITEMPOS_SPIRIT_SHOES,		 // ��ƥ����

		ITEMPOS_AUTOPACK	= ITEMPOS_BACKPACK,					// ������Զ��������е���Ʒ
		ITEMPOS_PROPPACK	= ITEMPOS_BACKPACK,					// ����ڵ��߲���Ʒ
		ITEMPOS_AMMOPACK	= ITEMPOS_BACKPACK,					// ����ڵ�ҩ���е���Ʒ
		ITEMPOS_USER_LIMIT	= 199,
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		ITEMPOS_NONE			= 255,				// �Ƿ�λ��
//////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �Ѿ����õ�
		ITEMPOS_INVALID		=ITEMPOS_CHIP,		//��ʱ������
		ITEMPOS_HAND		=ITEMPOS_R_HAND,						// ���ϵ������������ֺ�˫������
		ITEMPOS_BODY		=ITEMPOS_ENGINE,						// �������
		ITEMPOS_AMMOITEM	=ITEMPOS_ENPACK,						// ITEMPOS_ENITEM	, Զս�ǵ�ҩ����ս��En��
		ITEMPOS_HANDVAR		=ITEMPOS_INVALID,						// ���κ������
		ITEMPOS_SUBFLY		=ITEMPOS_INVALID,			// �ӻ�
		ITEMPOS_GROW		=ITEMPOS_INVALID,						// �ɳ�λ��
		ITEMPOS_TEMPPACK	=ITEMPOS_INVALID,						// ��ʱ�������Ʒ��λ�ã� �����ͻ�ɾ�������λ�����������Ʒ
		ITEMPOS_ARMORVAR	=ITEMPOS_INVALID,						// ���θ���
		ITEMPOS_ENERGY		=ITEMPOS_INVALID,						// ��Ӧ¯(���κ�ʹ��)
		ITEMPOS_TEMPITEM	=ITEMPOS_INVALID,						// ��ʱ�ֵ�λ�ã������� = 14
//------------------------------------
//		ITEMPOS_ENGINEROOMITEM,						// ������Ʒ
		ITEMPOS_SUBITEM		,						// ������Ʒ
		ITEMPOS_AUTOITEM	,						// �Զ���������Ʒ
		ITEMPOS_PROPITEM	,						// ���߲���Ʒ
		ITEMPOS_ASSISTANT	,						// ����λ��(�����������Ͳ�����)		
		
};

const int ITEMPOSITION_WEAPONHAND = ITEMPOS_R_HAND; // ���ϵ������������ֺ�˫������
const int ITEMPOSITION_SHIELD = ITEMPOS_SHOWEND; // ����
const int ITEMPOSITION_THRUSTER = ITEMPOS_THRUSTER; // �ƽ���(ԭ����λ��)
const int ITEMPOSITION_BODY = ITEMPOS_BODY; // �������
const int ITEMPOSITION_HEAD = ITEMPOS_HEADLOOP; // ͷ��
		

enum ITEM_FRAY_MODE		
{ 
	ITEM_FRAY_NORMAL = 0,		// �����ķ�ʽ��������ķ�ʽ��Ĭ��ֵ��
	ITEM_FRAY_TIME,				// װ�����̶�ʱ���������
	ITEM_FRAY_USE,				// ���߰�ʹ�ô��������
};

enum ITEM_REPAIR_MODE	
{
	ITEM_REPAIR_NORMAL	= 0,	// ��ͨ��װ�������޸���ʽ������ͨ���̵�NPC��action��ʽ�������������޸���ʽ��Ĭ��ֵ��
	ITEM_REPAIR_NO_NPC	= 1,	// ������ͨ���̵�NPC�Ĺ��ܽ�������
	ITEM_REPAIR_NO_ACTION = 2,	// ������ͨ��action��ʽ��������
};

enum 
{	
	ITEMINFOEX_NONE=0, 
	ITEMINFOEX_BOOTH,					// for booth
	ITEMINFOEX_EQUIPMENT,				// equipment update
	ITEMINFOEX_BOOTH_EMONEY,			// for booth with emoney
};

enum 
{ 
	STC_NORMAL_MONSTER_KILL = 1,
	STC_KO_MONSTER_KILL,
	STC_MAP_MONSTER_KILL,
	STC_PK_KILL,
};

// ������Ҳ���/�仯����
enum 
{	
	EMNY_OPT_ACTION_CHG		= 1,	// action �ı�
	EMNY_OPT_TRADE			= 2,	// ��ƽ����ϵͳ
	EMNY_OPT_BOOTH			= 3,	// ��̯
	EMNY_OPT_AUCTION		= 4,	// ����
	EMNY_OPT_TRADE_RCV_MONEY_FAILED		= 5,	// ��Ǯʧ��
	EMNY_OPT_CASHIN_CARD	= 6,	// ��card��ļ�¼�һ����������
	EMNY_OPT_CASHOUT_CARD	= 7,	// ��������Ҷһ���card��ļ�¼
	EMNY_OPT_CASHIN_CARD2	= 8,	// ��card2��ļ�¼�һ����������
	EMNY_OPT_CASHOUT_CARD2	= 9,	// ��������Ҷһ���card2��ļ�¼
	EMNY_OPT_BUY_ITEM		= 10,	// ��vip�̵깺����Ʒ
	EMNY_OPT_PK_BONUS		= 11,	// pk�ͷ�����
	EMNY_OPT_ARTIFACT_MAKEHOLE = 12,// ���￪��
	EMNY_OPT_REDEEM_EQUIP = 13,		// ���װ��
	EMNY_OPT_FETCH_BONUS = 14,		// ��ȡ���
};

enum 
{ 
	UNLEARN_HIDE, 
	UNLEARN_RESET, 
	UNLEARN_DROP 
};


enum
{
	 _ACTION_DANCE1		=1,
	 _ACTION_DANCE2		=2,
	 _ACTION_DANCE3		=3,
	 _ACTION_DANCE4		=4,
	 _ACTION_DANCE5		=5,
	 _ACTION_DANCE6		=6,
	 _ACTION_DANCE7		=7,
	 _ACTION_DANCE8		=8,
	
	 _ACTION_STANDBY		=100,
	 _ACTION_LAUGH			=150,
	 _ACTION_GUFFAW		=151,
	 _ACTION_FURY          =160,
	 _ACTION_SAD	        =170,
	 _ACTION_EXCITEMENT	=180,
	 _ACTION_SAYHELLO		=190,
	 _ACTION_SALUTE		=200,
	 _ACTION_GENUFLECT     =210,
	 _ACTION_KNEEL			=220,
	 _ACTION_COOL			=230,
	 _ACTION_SWIM			=240,
	 _ACTION_SITDOWN       =250,
	 _ACTION_ZAZEN			=260,
	 _ACTION_FAINT	        =270,
	 _ACTION_LIE	        =271,
};

enum RANDOMMAGICCONFIGDATA
{
	RANDOMMAGICCONFIGDATA_LEV = 0,
	RANDOMMAGICCONFIGDATA_TYPE,
	RANDOMMAGICCONFIGDATA_DATA1,
	RANDOMMAGICCONFIGDATA_DATA2,
	RANDOMMAGICCONFIGDATA_DATA3,
	RANDOMMAGICCONFIGDATA_DATA4,
	RANDOMMAGICCONFIGDATA_DATA5,
	RANDOMMAGICCONFIGDATA_DATA6,
	RANDOMMAGICCONFIGDATA_DATA7,
	RANDOMMAGICCONFIGDATA_DATA8,
	RANDOMMAGICCONFIGDATA_DATA9,
};

enum RANDOMMAGICTYPEDATA
{
	RANDOMMAGICTYPEDATA_ID = 0,
	RANDOMMAGICTYPEDATA_MAGIC,
	RANDOMMAGICTYPEDATA_NAME,
	RANDOMMAGICTYPEDATA_POOL,			//�����Ǹ���
	RANDOMMAGICTYPEDATA_FORBID_LOOK,	// ��ѡӢ��
};

enum MAGICTYPEDATA
{
	MAGICTYPEDATA_ID = 0,
	MAGICTYPEDATA_SORT,
	MAGICTYPEDATA_NAME,

	MAGICTYPEDATA_CRIME,				// ���Լ��ܻ����ǲ������ܵı�־
	MAGICTYPEDATA_GROUND,
	MAGICTYPEDATA_MULTIMODE,
	MAGICTYPEDATA_TARGET,
	MAGICTYPEDATA_IMMUNITY_MODE,
	MAGICTYPEDATA_PASSIVE,
	MAGICTYPEDATA_LOOP,

	MAGICTYPEDATA_INTONE,				// ����ʱ��
	MAGICTYPEDATA_DELAY,				// ��ͬ������ID��ʽ֮���ʱ���������뵥λ��milli-secs
	MAGICTYPEDATA_SECS,					// step_secs
	MAGICTYPEDATA_TIMES,				// active_times	, =0 : once status

	MAGICTYPEDATA_POWER,
	MAGICTYPEDATA_DATA,
	MAGICTYPEDATA_PERCENT,

	MAGICTYPEDATA_DISTANCE,
	MAGICTYPEDATA_RANGE,
	MAGICTYPEDATA_WIDTH,				// width of magic. 0-180 for degree of fan (sort 4), 0 for default.

	MAGICTYPEDATA_NEED_WEAPON,
	MAGICTYPEDATA_NEED_AMMO,
	MAGICTYPEDATA_EXPEND_LIFE,
	MAGICTYPEDATA_EXPEND_MANA,
	MAGICTYPEDATA_EXPEND_FUEL,
	MAGICTYPEDATA_XP_MODE,	//MAGICTYPEDATA_EXPAND_XP,			// 0=��XP����  1=XPħ���༼��  2=XP״̬�༼�ܣ���ʱ������

	MAGICTYPEDATA_EXPEND_AMMO,

	MAGICTYPEDATA_STATUS,
	MAGICTYPEDATA_STATUS_CHANCE,
	MAGICTYPEDATA_STATUS_TIME,
	MAGICTYPEDATA_STATUS_POWER,
	MAGICTYPEDATA_STATUS_DATA,
	MAGICTYPEDATA_ATTACK,
	MAGICTYPEDATA_ATKFIGHTER,			// �Խ�ս����		
	MAGICTYPEDATA_ATKGUNNER,			// ��Զս����
	MAGICTYPEDATA_ATKENERGY,			// ����������
	MAGICTYPEDATA_ATKHOT,				// ���¹���
	MAGICTYPEDATA_PART_PERCENT1,		
	MAGICTYPEDATA_PART_PERCENT2,		
	MAGICTYPEDATA_HEAD_PERCENT,			
	MAGICTYPEDATA_STAND_TIME,			
	MAGICTYPEDATA_REQ_CAMP,				
	MAGICTYPEDATA_REQ_LEV,				
	MAGICTYPEDATA_TRANSLOOK,			//���μ��ܵ�����look
	MAGICTYPEDATA_ANIMOSITY,
	MAGICTYPEDATA_NEED_EXP,
	MAGICTYPEDATA_UPLEVETIME,
	MAGICTYPEDATA_ACTION,				// ��actionֵ��0ʱ����ʾΪ�����actionֵ��ָ��action�еľ���ID
	MAGICTYPEDATA_STATUSA,				// ʹ�ü���ʱ���ж�Ŀ������Ƿ����ƶ�����״̬A
	MAGICTYPEDATA_STATUSA_DATA1,		
	MAGICTYPEDATA_STATUSA_DATA2,
	MAGICTYPEDATA_STATUSB,				// ʹ�ü���ʱ���ж�Ŀ������Ƿ����ƶ�����״̬B
	MAGICTYPEDATA_STATUSB_DATA1,
	MAGICTYPEDATA_STATUSB_DATA2,
	MAGICTYPEDATA_MAX_TARGET_NUM,		// ��¼Ⱥ�弼��ʹ��ʱ���������Զ��ٸ�Ŀ�����(0��ʾ���������ޣ����弼�ܸ��ֶβ�������)
	MAGICTYPEDATA_SELF_STATUS,			// ����ʹ�ú󣬶Լ���ʹ�������������ӵ�״̬
	MAGICTYPEDATA_SELF_STATUS_CHANCE,
	MAGICTYPEDATA_SELF_STATUS_TIME,
	MAGICTYPEDATA_SELF_STATUS_POWER,
	MAGICTYPEDATA_SELF_STATUS_DATA,
	MAGICTYPEDATA_LHANDEQUIP,			// ����װ��Ҫ��
	MAGICTYPEDATA_CONDITION,			// ����Ҫ�󣬶����Ʊ�ʶ��0��ʾ������1��ʾ�����״̬��10��ʾ���״̬
	MAGICTYPEDATA_TARGET_DISTINCT,
	MAGICTYPEDATA_SELF_DISTINCT,
	MAGICTYPEDATA_CONSUME_ITEM_ID,      //���Ӽ������ĵ���ƷID
	MAGICTYPEDATA_FIRE_TYPE,			//�������� TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�
//	MAGICTYPEDATA_REQ_TEAM_ROLE,		// �����ɫ����
	MAGICTYPEDATA_REQ_ROLE_TYPE
};

enum MAGICTYPEOPDATA{
	MAGICTYPEOPDATA_ID = 0,
	MAGICTYPEOPDATA_REBIRTHTIME = 1,
	MAGICTYPEOPDATA_PROFAGO,
	MAGICTYPEOPDATA_PROFNOW,
	MAGICTYPEOPDATA_OP,
	MAGICTYPEOPDATA_SKILL1,
	MAGICTYPEOPDATA_SKILL2,
	MAGICTYPEOPDATA_SKILL3,
	MAGICTYPEOPDATA_SKILL4,
	MAGICTYPEOPDATA_SKILL5,
	MAGICTYPEOPDATA_SKILL6,
	MAGICTYPEOPDATA_SKILL7,
	MAGICTYPEOPDATA_SKILL8,
	MAGICTYPEOPDATA_SKILL9,
	MAGICTYPEOPDATA_SKILL10,
	MAGICTYPEOPDATA_SKILL11,
	MAGICTYPEOPDATA_SKILL12,
	MAGICTYPEOPDATA_SKILL13,
	MAGICTYPEOPDATA_SKILL14,
	MAGICTYPEOPDATA_SKILL15,
	MAGICTYPEOPDATA_SKILL16,
	MAGICTYPEOPDATA_SKILL17,
	MAGICTYPEOPDATA_SKILL18,
	MAGICTYPEOPDATA_SKILL19,
	MAGICTYPEOPDATA_SKILL20,
	MAGICTYPEOPDATA_SKILL21,
	MAGICTYPEOPDATA_SKILL22,
	MAGICTYPEOPDATA_SKILL23,
	MAGICTYPEOPDATA_SKILL24,
	MAGICTYPEOPDATA_SKILL25,
	MAGICTYPEOPDATA_SKILL26,
	MAGICTYPEOPDATA_SKILL27,
	MAGICTYPEOPDATA_SKILL28,
	MAGICTYPEOPDATA_SKILL29,
	MAGICTYPEOPDATA_SKILL30,
	MAGICTYPEOPDATA_SKILL31,
	MAGICTYPEOPDATA_SKILL32,
	MAGICTYPEOPDATA_SKILL33,
	MAGICTYPEOPDATA_SKILL34,
	MAGICTYPEOPDATA_SKILL35,
	MAGICTYPEOPDATA_SKILL36,
	MAGICTYPEOPDATA_SKILL37,
	MAGICTYPEOPDATA_SKILL38,
	MAGICTYPEOPDATA_SKILL39,
	MAGICTYPEOPDATA_SKILL40,
	MAGICTYPEOPDATA_SKILL41,
	MAGICTYPEOPDATA_SKILL42,
	MAGICTYPEOPDATA_SKILL43,
	MAGICTYPEOPDATA_SKILL44,
	MAGICTYPEOPDATA_SKILL45,
	MAGICTYPEOPDATA_SKILL46,
	MAGICTYPEOPDATA_SKILL47,
	MAGICTYPEOPDATA_SKILL48,
	MAGICTYPEOPDATA_SKILL49,
	MAGICTYPEOPDATA_SKILL50,
	MAGICTYPEOPDATA_SKILL51,
	MAGICTYPEOPDATA_SKILL52,
	MAGICTYPEOPDATA_SKILL53,
	MAGICTYPEOPDATA_SKILL54,
	MAGICTYPEOPDATA_SKILL55,
	MAGICTYPEOPDATA_SKILL56,
	MAGICTYPEOPDATA_SKILL57,
	MAGICTYPEOPDATA_SKILL58,
	MAGICTYPEOPDATA_SKILL59,
	MAGICTYPEOPDATA_SKILL60,
};

enum MAGICDATA
{
	MAGICDATA_ID = 0,			// use for insert
	MAGICDATA_OWNERID,			//ӵ�иü��ܵ����id����Ӧ��user���id
	MAGICDATA_TYPE,				//���ܵ�����type����Ӧmagictype�����type
	MAGICDATA_LEVEL,			//���ܵĵȼ�
	MAGICDATA_EXP,				//������ʱû�о���ֵ��Ԥ��
	MAGICDATA_UNLEARN,			//
	MAGICDATA_OLD_LEVEL,		//
	MAGICDATA_OWNERTYPE,
};

//������ص�ö�ٶ���,ע�����ö�����Ͷ�����ܸ��ݲ�ͬ��ϵͳ��
//��ͬ�ĺ���,����Ҫ�ı京��,����������ע���ı�
enum MONSTERTYPEDATA
{
	MONSTERTYPEDATA_ID	= 0,
	MONSTERTYPEDATA_NAME,
	MONSTERTYPEDATA_SORT,
	MONSTERTYPEDATA_LOOKFACE,
	MONSTERTYPEDATA_LIFE,
	MONSTERTYPEDATA_MANA,
	MONSTERTYPEDATA_DEXTERITY,

	MONSTERTYPEDATA_DODGE,
	MONSTERTYPEDATA_HELMET_TYPE,  MONSTERTYPEDATA_EQUIP_BEGIN = MONSTERTYPEDATA_HELMET_TYPE,
	MONSTERTYPEDATA_ARMOR_TYPE,
	MONSTERTYPEDATA_WEAPONR_TYPE,
	MONSTERTYPEDATA_WEAPONL_TYPE,

	MONSTERTYPEDATA_ATKRANGE,
	MONSTERTYPEDATA_VIEWRANGE,
	MONSTERTYPEDATA_VIEWANGLE,
	MONSTERTYPEDATA_ESCAPELIFE,
	MONSTERTYPEDATA_ATKSPEED,			// ����
	MONSTERTYPEDATA_MOVESPEED,			// ����

	MONSTERTYPEDATA_LEVEL,
	MONSTERTYPEDATA_ATKUSER,

    MONSTERTYPEDATA_DROPMONEY_MIN,     //����Ǯ������ֵ
    MONSTERTYPEDATA_DROPMONEY_MAX,     //����Ǯ������ֵ
	MONSTERTYPEDATA_IS_SHARE_MONEY,    //���Ľ�Ǯ�Ƿ����
	MONSTERTYPEDATA_IS_MAP_AWARDMONEY, //��Ǯ�Ƿ�ȫͼ���˶��ܻ��
    MONSTERTYPEDATA_EXTRA_DROPMONEY,   //�����Ǯ

	MONSTERTYPEDATA_SIZEADD,			// 1: ����һ��CELL�Ĺ�������
	MONSTERTYPEDATA_ACTION,				// action for kill award
	MONSTERTYPEDATA_RUNSPEED,			// ����

	MONSTERTYPEDATA_HOT_POWER,		   // ����ǿ�ȣ�����cold_powerͬʱ���ڣ�
	MONSTERTYPEDATA_COLD_POWER,		   // �䶳ǿ�ȣ�����hot_powerͬʱ���ڣ�
	MONSTERTYPEDATA_SHAKE_POWER,	   // ��ǿ��
	MONSTERTYPEDATA_DROP_RING,			// 
	MONSTERTYPEDATA_DROP_WEAPON,		// 
	MONSTERTYPEDATA_DROP_SHIELD,		// 
	MONSTERTYPEDATA_DROP_SHOES,			// 

	MONSTERTYPEDATA_DROP_MONEY_PERCENT,	   //��Ǯ�ļ���
	MONSTERTYPEDATA_DROP_ITEM_CHANCE,	   //����Ʒ�ļ���

	MONSTERTYPEDATA_MAGIC_TYPE,	
	MONSTERTYPEDATA_MAGIC_DEF,
	MONSTERTYPEDATA_MAGIC_HITRATE,

	MONSTERTYPEDATA_AITYPE,					// for client
	MONSTERTYPEDATA_EXPLODE_ITEM_CHANCE1,	//С���ļ���
	MONSTERTYPEDATA_EXPLODE_ITEM_CHANCE2,	//�б��ļ���
	MONSTERTYPEDATA_EXPLODE_ITEM_CHANCE3,	//�󱬵ļ���
	MONSTERTYPEDATA_DROP_ITEM_RULE,			//����Ʒ�Ĺ�����ID

	MONSTERTYPEDATA_ATKMAX,
	MONSTERTYPEDATA_ATKMIN,
	MONSTERTYPEDATA_ATKHOT,
	MONSTERTYPEDATA_ATKSHAKE,
	MONSTERTYPEDATA_ATKCOLD,
	MONSTERTYPEDATA_ATKLIGHT,
	MONSTERTYPEDATA_DEFADJ,
	MONSTERTYPEDATA_DEFSUB,
	MONSTERTYPEDATA_DEFHOT,			
	MONSTERTYPEDATA_DEFSHAKE,
	MONSTERTYPEDATA_DEFCOLD,
	MONSTERTYPEDATA_DEFLIGHT,
	MONSTERTYPEDATA_WEAPON_AMOUNT,
	MONSTERTYPEDATA_ARMOR_AMOUNT,
	MONSTERTYPEDATA_THRUSTER_AMOUNT,
	MONSTERTYPEDATA_STEALITEM,
	MONSTERTYPEDATA_AWARD_EXP,				// ����ս������
	MONSTERTYPEDATA_IS_SHARE,               // �����Ƿ����
	MONSTERTYPEDATA_IS_MAP_AWARD_EXP,       // �Ƿ�ȫͼ��þ���
	MONSTERTYPEDATA_DROP_STONE_PERCENT,		// ���ԭʯ�ļ���
	MONSTERTYPEDATA_DROPSTONE_MIN,			// �����Сԭʯ��
	MONSTERTYPEDATA_DROPSTONE_MAX,			// ������ԭʯ��

    MONSTERTYPEDATA_MAGIC_1,
	MONSTERTYPEDATA_MAGIC_2,
	MONSTERTYPEDATA_MAGIC_3,
	MONSTERTYPEDATA_MAGIC_ASSISTANT_1,			//����ħ��1
	MONSTERTYPEDATA_MAGIC_ASSISTANT_2,			//����ħ��2
	MONSTERTYPEDATA_MAGIC_DESTROY,				//���˻������Ա��������ħ��
	MONSTERTYPEDATA_MAGIC_PASSIVE,				//��������
	MONSTERTYPEDATA_STATUS_IMMUNITY,			//״̬��������
	MONSTERTYPEDATA_STATUS_IMMUNITY_LV,			//״̬�����ȼ�
	MONSTERTYPEDATA_SOMATOTYPE,					//
	MONSTERTYPEDATA_CAMP,						//�������Ӫ
	MONSTERTYPEDATA_SPIRIT_TYPE,					//�ɲ�׽��־=0���ܲ�׽ !=0��ʾ�ɲ�׽�����Ҹ�ֵΪSPIRIT����

	MONSTERTYPEDATA_DROP_EQUIP_COE,				//װ�����伸����������
	MONSTERTYPEDATA_DROP_AMMO_COE,				//��ҩ���伸����������
	MONSTERTYPEDATA_DROP_PART_COE,				//��׼������伸����������
	MONSTERTYPEDATA_DROP_AMPLIFIER_COE,			//���������伸����������
	MONSTERTYPEDATA_DROP_GUARD_COE,				//������Ʒ���伸����������
	MONSTERTYPEDATA_DROP_EXPENDABLE_COE,		//����Ʒ���伸����������
	MONSTERTYPEDATA_DROP_INSIDEITEM_COE,		//�ڲ�װ�õ��伸����������
	MONSTERTYPEDATA_DROP_EXPLODE_COE,			//����Ʒ�ļ�����������
	MONSTERTYPEDATA_DROP_SPECIAL_COE,			//������Ʒ���伸����������
	MONSTERTYPEDATA_SPECIAL_TYPE,				//��д������Ʒ������
	MONSTERTYPEDATA_DROP_DELTALEV_COE,			//�Ƿ����������伸������Ӱ��Ĳ���
	MONSTERTYPEDATA_ATTRIBUTETYPE,				//��Ӧmonster_attribute_type��
	MONSTERTYPEDATA_EXTRA_BATTLELEV,			//�������Ķ���ս�����ȼ�
	MONSTERTYPEDATA_EXTRA_EXP,					//��������ڱ���ҹ���ʱ����ҵĶ���ս�����ȼ�ÿ�߳�������Ǽ�1�������ӵľ���ֵ��ֵ��10000��ʾ10000/10000��
	MONSTERTYPEDATA_EXTRA_DAMAGE,				//�����Ǽ������ڹ������ʱ��������ܵ����˺�ռ��������ֵ�ı�ֵ��10000��ʾ10000/10000��
	MONSTERTYPEDATA_DROP_STONE_TYPE,			//����ר����Դ�ĵ�����򣬶�Ӧdrop_stone_rule���еġ�IDĬ��Ϊ0����ʾ����������ר����Դ��tcp 2007-1-9 add
	MONSTERTYPEDATA_USER_ATK_ADJUST,			//����BOSS�ࡢ���������ڱ�ɱ����������һ������������ϵ�� = �ֶ���ֵ / 100
	//����������˺����ܡ�����ϵͳ 
	MONSTERTYPEDATA_EXEMPT_DAMAGE,				//ʹ�÷����������/���ܹ�������ʱ����������˺��ٷֱ�
	MONSTERTYPEDATA_PERTINENCE_MAGIC,			//����Լ��ܵ�id
	MONSTERTYPEDATA_PERTINENCE_MAGIC_DAMAGE,	//ʹ������Լ��ܽ��й���ʱ���������ܵ��������˺��ٷֱ�
	MONSTERTYPEDATA_PERTINENCE_WEAPON,			//���������������id
	MONSTERTYPEDATA_PERTINENCE_WEAPON_DAMAGE,	//ʹ��������������й���ʱ���������ܵ��������˺��ٷֱ�
	//����������˺����ܡ�����ϵͳ	
	MONSTERTYPEDATA_DROP_RMB_COE,				//����̫��ʯ������������
	MONSTERTYPEDATA_DROP_OTHER_COE,				//����������Ʒ������������		
	MONSTERTYPEDATA_PRICE,						//����ս���ƻ����ά�޷���
	MONSTERTYPEDATA_USER_ATK_MODE,				//=0 ��ʾ��ɱ�ֻ�������     =1 ��ʾ��ɱ�ֻ�������
	MONSTERTYPEDATA_ATTACK_TYPE,				//=0 ����     =1 ΪԶ��
	MONSTERTYPEDATA_CALC_DMG_TYPE,				//=0 ʹ�õ�ǰbaselife���˺��������̡�=1���ʾʹ���˺� = �� - ���ļ�������
	MONSTERTYPEDATA_WEAKNESS_TIPS,              //����������ʾ��Ӧ��tips���
	MONSTERTYPEDATA_COMA_LIFE_RATE,				//����������Ե�Ѫ������
	MONSTERTYPEDATA_COMA_PROBABILITY,			//������Եļ���
	MONSTERTYPEDATA_ADD_PROFESSION_EXP,			//�Թ�����Ѫ��������ְҵ����ֵ
	MONSTERDATA_LIVE_SECS,						//����ʬ�屣��ʱ�䣨��ʬ2010-01-08��0��ʾ10���ʬ����ʧ��1��ʾʬ�岻��ʧ������ֵ��ʾ���������������ʬ����ʧ����
	MONSTERDATA_CORRECLATION_MONSTER,		    //��������ֶ�
	MONSTERTYPEDATA_CHANGE_ID,					//���������Ӧ�Ĺ���id
//	MONSTERTYPEDATA_REBORN_COUNT,					//
	MONSTERTYPEDATA_BLOOD_ACTION_LOWER_LIMIT,   //����Ѫ����������ֵ
	MONSTERTYPEDATA_BLOOD_ACTION,               //����Ѫ������Action
	MONSTERTYPEDATA_RATECAP,					//���ﲶ����Ҽ���
	MONSTERTYPEDATA_FABACKDISTANCE,             //��������ս������
	MONSTERTYPEDATA_PARRY,
    MONSTERTYPEDATA_DEF_NEAR,
	MONSTERTYPEDATA_RIGHT_HAND_WEAPON,
	MONSTERTYPEDATA_LEFT_HAND_WEAPON,
	MONSTERTYPEDATA_MOVE_SPEED_ATTACK,
	MONSTERTYPEDATA_ATTACK_USER_TYPE,
	MONSTERTYPEDATA_SIZE,
	MONSTERTYPEDATA_MAGIC_HITRATE1,
	MONSTERTYPEDATA_MAGIC_HITRATE2,
	MONSTERTYPEDATA_MAGIC_HITRATE3,
	MONSTERTYPEDATA_RESISTANCE_TYPE,
	MONSTERTYPEDATA_BROKEN_BODY_SPEED,           // ���������ȱʱ���ƶ��ٶ� | monster's move speed when its body is broken
    MONSTERTYPEDATA_BROKEN_BODY_ATTACK_DURATION, // ���������ȱʱ�Ĺ����ٶ� ms | monster's attack duration(in ms) when its body is broken
    MONSTERTYPEDATA_GREENNAME_DISDAIN,
    MONSTERTYPEDATA_DROP_RULE,
    MONSTERTYPEDATA_SUPERARMOR_BREAK,           // ������巧ֵ
    MONSTERTYPEDATA_SUPERARMOR_RESUME,          // �ָ����巧ֵ
    MONSTERTYPEDATA_DEF_FAR,                    //Զ�̷���
    MONSTERTYPEDATA_STATUS_MACHINE_TYE,         // ״̬������
	MONSTERTYPEDATA_BURN,						//ȼ������ TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�
	MONSTERTYPEDATA_BURN_RANGE,					//���淶Χ TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�
	MONSTERTYPEDATA_PVE_ENERGY,					//PVE����ֵ

	//Dota���ֶ�
	MONSTERTYPEDATA_ADDITIVE_ATTR,				//��ӦCREATURE_ADDITIVE_ATTR_TYPE
	MONSTERTYPEDATA_UP_OWNER_ID,				//����ʱ�����ı�Ӫid
	MONSTERTYPEDATA_END_OWNER_ID,				//����ʱ�رյı�Ӫid
	MONSTERTYPEDATA_PVE_POINT,					//PVE����
    MONSTERTYPEDATA_DAMAGE_MONEY_RATE,          //�����˺����ϵ��
};

enum MONSTER_SORT_TYPE
{
	MONSTER_SORT_NULL,
	MONSTER_SORT_LAMPS_ON = 1,		//�ƾߣ�Ĭ�Ͽ���
	MONSTER_SORT_LAMPS_OFF = 2,		//�ƾߣ�Ĭ�Ϲأ�
};

enum MONSTERRESISTANCETYPEDATA
{
	MONSTERRESISTANCEDATA_ID,
	MONSTERRESISTANCEDATA_HEADSHOT_RATE,	//��ͷ�ֿ�����
	MONSTERRESISTANCEDATA_MUTILATION_RATE,  //��֫�ֿ�����
	MONSTERRESISTANCEDATA_BEATBACK_RATE,    //���˵ֿ�����
	MONSTERRESISTANCEDATA_KNOCKDOWN_RATE,   //�����ֿ�����
	MONSTERRESISTANCEDATA_KNOCKBACK_RATE,   //���ɵֿ�����
	MONSTERRESISTANCEDATA_SPASTICITY_TIME,  //��ֱ�ֿ�ʱ��
};

enum MONSTERSKILLDATA
{
	//MONSTER_SKILL_ID,
	MONSTER_SKILL_MONSTERTYPE,
	MONSTER_SKILL_SKILL1,
	MONSTER_SKILL_CONDITION1,
	MONSTER_SKILL_DATA1,
	MONSTER_SKILL_DELAY_MS1,
	MONSTER_SKILL_INTONE_MS1,
	MONSTER_SKILL_SKILL2,
	MONSTER_SKILL_CONDITION2,
	MONSTER_SKILL_DATA2,
	MONSTER_SKILL_DELAY_MS2,
	MONSTER_SKILL_INTONE_MS2,
	MONSTER_SKILL_SKILL3,
	MONSTER_SKILL_CONDITION3,
	MONSTER_SKILL_DATA3,
	MONSTER_SKILL_DELAY_MS3,
	MONSTER_SKILL_INTONE_MS3,
	MONSTER_SKILL_SKILL4,
	MONSTER_SKILL_CONDITION4,
	MONSTER_SKILL_DATA4,
	MONSTER_SKILL_DELAY_MS4,
	MONSTER_SKILL_INTONE_MS4,
	MONSTER_SKILL_SKILL5,
	MONSTER_SKILL_CONDITION5,
	MONSTER_SKILL_DATA5,
	MONSTER_SKILL_DELAY_MS5,
	MONSTER_SKILL_INTONE_MS5,
	MONSTER_SKILL_SKILL6,
	MONSTER_SKILL_CONDITION6,
	MONSTER_SKILL_DATA6,
	MONSTER_SKILL_DELAY_MS6,
	MONSTER_SKILL_INTONE_MS6,
	MONSTER_SKILL_SKILL7,
	MONSTER_SKILL_CONDITION7,
	MONSTER_SKILL_DATA7,
	MONSTER_SKILL_DELAY_MS7,
	MONSTER_SKILL_INTONE_MS7,
	MONSTER_SKILL_SKILL8,
	MONSTER_SKILL_CONDITION8,
	MONSTER_SKILL_DATA8,
	MONSTER_SKILL_DELAY_MS8,
	MONSTER_SKILL_INTONE_MS8,
	MONSTER_SKILL_SKILL9,
	MONSTER_SKILL_CONDITION9,
	MONSTER_SKILL_DATA9,
	MONSTER_SKILL_DELAY_MS9,
	MONSTER_SKILL_INTONE_MS9,
	MONSTER_SKILL_SKILL10,
	MONSTER_SKILL_CONDITION10,
	MONSTER_SKILL_DATA10,
	MONSTER_SKILL_DELAY_MS10,
	MONSTER_SKILL_INTONE_MS10,
};

//���ö�ٸ��ݾ���ҵ���е������������ص�ע��
enum MONSTERATTRTYPEDATA
{
	MONSTERATTRTYPE_ID,
	MONSTERATTRTYPE_DEF_STRAFE,		//��ǹ������0~10000��
	MONSTERATTRTYPE_DEF_FIREGUN,	//����ǹ������0~10000��
	MONSTERATTRTYPE_DEF_SHAKE,		//��ǹ������0~10000��
	MONSTERATTRTYPE_DEF_ICEGUN,		//����ǹ������0~10000��
	MONSTERATTRTYPE_DEF_SNIPE,		//�ѻ�ǹ������0~10000��
	MONSTERATTRTYPE_WEAKNESS,		//���� ���������������㹥��ʱ����ʧ HP����/��������HP��=0ʱ,��def_snipe=9999ʱ���Ӧ
	MONSTERATTRTYPE_DEF_COLD,		//����������0~10000�� ���ȣ�Ӱ�������ٶȺͽ����ٶȡ��ֶ���ֵXX��ʾXX%����ΧΪ0~100
	MONSTERATTRTYPE_DEF_HOT,		//���·�����0~10000�� ���յֿ���Ӱ��ʵ�ʵĸ����˺����ֶ���ֵXX��ʾXX%
	MONSTERATTRTYPE_DEF_MGUN,		//��ǹ��ѹ�Ʒ�����0~10000��
	MONSTERATTRTYPE_DEF_SHAKEGUN,	//�𵴷�����0~10000��
	MONSTERATTRTYPE_MAX_WRATH,		//��ս��������tcp 2007-3-29 add
	MONSTERATTRTYPE_DEF_BEAT,		//��ս��������tcp 2007-3-29 add
	MONSTERATTRTYPE_DEF_MUSKET,		//��ǹ������0~10000����ǹ
};

enum DROPITEMTYPE
{
	DROPITEMTYPE_NONE = 0,
	DROPITEMTYPE_EQUIP = 10,
	DROPITEMTYPE_AMMO  = 20,
	DROPITEMTYPE_PART  = 30,
	DROPITEMTYPE_AMPLIFIER =  40,
	DROPITEMTYPE_GUARDEQUIPITEM =  50,
	DROPITEMTYPE_EXPENDABLE = 60,
	DROPITEMTYPE_INSIDEITEM = 70,
	DROPITEMTYPE_OTHERITEM	= 80,
	DROPITEMTYPE_SPECIALITEM = 90,
	DROPITEMTYPE_RMB   = 100
};

typedef enum
{
	EMPLACEMENT_NONE = 0,
	EMPLACEMENT_TYPE_PROGCOMMON = 1,
	EMPLACEMENT_TYPE_PROGTRACE,
	EMPLACEMENT_TYPE_TRACE,
	EMPLACEMENT_TYPE_TRACE_MAGIC=5,

	EMPLACEMENT_TYPE_SYN_ATTACK_SIDE = 40,//��ǰ����̨��ǰ׺

	ELECTROMOTOR_TYPE=50,
}EmplacementType;

//////////////////////////////////////////////////////////////////////
enum 
{	
	ATKUSER_LEAVEONLY				= 0,				// ֻ������
	ATKUSER_PASSIVE					= 0x01,				// ��������
	ATKUSER_ACTIVE					= 0x02,				// ��������
	ATKUSER_RIGHTEOUS				= 0x04,				// �����(����������ٻ��Ϳ��ƵĹ���)
	ATKUSER_GUARD					= 0x08,				// ����(���»�ԭλ��)
	ATKUSER_PPKER					= 0x10,				// ׷ɱ����
	ATKUSER_JUMP					= 0x20,				// ����
	ATKUSER_FIXED					= 0x40,				// ���ᶯ��
	ATKUSER_FASTBACK				= 0x0080,				// �ٹ�
	ATKUSER_LOCKUSER				= 0x0100,				// ��������ָ����ң�����뿪�Զ���ʧ
	ATKUSER_LOCKONE					= 0x0200,				// �����������ȹ����Լ������
	ATKUSER_ADDLIFE					= 0x0400,				// �Զ���Ѫ
	ATKUSER_EVIL_KILLER				= 0x0800,				// ����ɱ��
	ATKUSER_WING					= 0x1000,				// ����״̬
	ATKUSER_DESTROYOBJ				= 0x2000,				// ���ƻ����
	ATKUSER_ROAR					= 0x4000,				// ����ʱȫ��ͼŭ��
	ATKUSER_NOESCAPE				= 0x8000,				// ��������
	ATKUSER_EQUALITY				= 0x00010000,			// ������
	ATKUSER_DEFSUPPRESS				= 0x00020000,			// ���ɱ�ѹ�Ƶ�
	ATKUSER_BLAST					= 0x00100000,			// ��ͼ��ը��
	ATKUSER_EMPLACEMENT				= 0x00200000,			// ��̨������	
	ATKUSER_ELECTROMOTOR			= 0x00400000,			// �����������
	ATKUSER_PROTECTNPC				= 0x00800000,			// ����NPC
	ATKUSER_NON_DORMANCY			= 0x01000000,			// �����߹�������
	ATKUSER_ATTACK_DEFENCE_SIDE		= 0x02000000,			// ֻ�������ط����Ӽ�������};
	ATKUSER_PHYSICAL_IMMUNITY		= 0x04000000,			// ���ܱ�������
	ATKUSER_CHANGE_BODY				= 0x08000000,			//�ɱ������ [����2009.8.17]
	ATKUSER_SHIFTABLE				= 0x10002040,           //�ɱ���Ҿ���������Ŀ��ƻ����
	ATKUSER_ATTACK_IMMUNITY			= 0x20000000,			//���ܱ�����
};

////////////////////////////////////////////////////////////////
enum
{
		TYPE_MAGIC		= 0, // ħ��
		TYPE_XPSKILL	= 1, // xp��
		TYPE_KONGFU		= 2, // �书��ʽ
};


enum ATK_MODE
{
	ATKMODE_USER			= 0x1,
	ATKMODE_MONSTER			= 0x2,
	ATKMODE_ACTION			= 0x4,				// ֻ����ACTION
	ATKMODE_TRIGGER			= 0x8,				//7��	��ͬ�������е�������
	ATKMODE_AIR_UNIT		= 0x10,				//8��	һ����Χ���Զ���������Ŀ��
	ATKMODE_FRIENDS_ENEMY	= 0x20,			//9��	����Ĵ�����ʽ������һ����Χ���Զ�����ͬ���Ա������Ŀ�꣩
	ATKMODE_LATENCY			= 0x40,				// ���ף���Ǳ���ڴ��������ϣ�������ң��������!!!! traptype��Ҫ��atk_mode�����ֻ��׺͵��ף����׵�atk_mode����Ҫ����0x40����ң��������������ȥ�ͻ����ϱ�ը��
	ATKMODE_NOATTACK		= 0x80,				// ����������
	ATKMODE_ONCE_EFFECT		= 0x100,			// ��������ֻ�ܴ���һ����
};

// 
// // �ⲿ״̬����Ҫͨ��MsgPlayer֪ͨ������ҵ�״̬����ͻ���ͬ��
// enum KEEPEFFECT
// {
// 	// effect0
// 		KEEPEFFECT_NORMAL			=0x0000,
// 		KEEPEFFECT_CRIME			=0x0001, 
// 		KEEPEFFECT_POISON			=0x0002, 
// 		KEEPEFFECT_INVISIBLE		=0x0004,
// 		KEEPEFFECT_FREEZE			=0x0008,
// 		KEEPEFFECT_XPFULL			=0x0010,
// 		KEEPEFFECT_DIE				=0x0020,
// 		KEEPEFFECT_TEAMLEADER		=0x0040,
// 		KEEPEFFECT_HITRATE			=0x0080,
// 		KEEPEFFECT_DEFENCE			=0x0100,
// 		KEEPEFFECT_ATTACK			=0x0200,
// 		KEEPEFFECT_GHOST			=0x0400,
// 		KEEPEFFECT_DISAPPEARING		=0x0800,
// 		KEEPEFFECT_MAGICDEFENCE		=0x1000,
// 		KEEPEFFECT_BOWDEFENCE		=0x2000,
// 		KEEPEFFECT_RED				=0x4000,
// 		KEEPEFFECT_DEEPRED			=0x8000,
// 		KEEPEFFECT_ATKRANGE			=0x00010000,
// 		KEEPEFFECT_REFLECT			=0x00020000,
// 		KEEPEFFECT_SUPERMAN			=0x00040000,
// 		KEEPEFFECT_WEAPONDAMAGE		=0x00080000,
// 		KEEPEFFECT_MAGICDAMAGE		=0x00100000,
// 		KEEPEFFECT_ATKSPEED			=0x00200000,
// 		KEEPEFFECT_LURKER			=0x00400000,
// 		KEEPEFFECT_TORNADO			=0x00800000,
// 		KEEPEFFECT_SYNCRIME			=0x01000000, 
// 		KEEPEFFECT_REFLECTMAGIC		=0x02000000,
// 		KEEPEFFECT_DODGE			=0x04000000,
// 		KEEPEFFECT_WING				=0x08000000,
// 		KEEPEFFECT_KEEPBOW			=0x10000000,
// 		KEEPEFFECT_INSTEAD			=0x20000000,
// 		KEEPEFFECT_LUCK_SPREAD		=0x40000000,		// ��
// 		KEEPEFFECT_LUCK_ABSORB		=0x80000000,		// ����
// 		
// 		// effect1
// 		KEEPEFFECT_CURSE			=0x00000001,		// ����״̬
// 		KEEPEFFECT_GODBLESS			=0x00000002,		// ף��״̬
// 		
// 		KEEPEFFECT_INVALID			=0xFFFFFFFF,
// 		
// };
// 
// //////////////////////////////////////////////////////////////////////
// // �ۺ�״̬
// enum 
// {
// 		KEEPEFFECT_NOT_ACTIVE		=KEEPEFFECT_DIE|KEEPEFFECT_FREEZE,
// 		KEEPEFFECT_NOT_CLEAR		=KEEPEFFECT_TEAMLEADER|KEEPEFFECT_RED|KEEPEFFECT_DEEPRED,		// ������������״̬
// };

enum 
{
	STATUSSORT_LEAVETIMES		= 1 << 0,
	STATUSSORT_REMAINTIME		= 1 << 1,
	STATUSSORT_ENDTIME			= 1 << 2
};

//REGION_TYPE 1000-1999�ͻ���ר�ã�û�з����
//REGION_TYPE 2000-2999�����ר�ã��ͻ���û��
//REGION_TYPE	����˫������
enum REGION_TYPE 
{
	REGION_NONE					= 0,
	REGION_CITY							= 1,			//����������Ӿ��鲻��������
	REGION_WEATHER				= 2,
	REGION_STATUARY				= 3,
	REGION_DESC					= 4,
	REGION_GOBALDESC			= 5,
	REGION_DANCE				= 6,			// data0: idLeaderRegion, data1: idMusic, 
	REGION_PK_PROTECTED					= 7,
	REGION_BOOTH						= 8,			// data0: level of booth
	REGION_SHIP							= 9,			//�ɴ������г�����
	REGION_UNIVERSE						= 11,           //���泡��
	REGION_OFFSET						= 12,			//��������(�´����ͻ���)
	REGION_BOUNCE_START					= 13,			//��������
	REGION_MARKET						= 14,			//�г�������Ӿ��鲻��������
	REGION_TRAININGFIELD				= 16,			// ����������
	REGION_FULLSCREEN_ATK_DISABLE		= 17,		    //����ʹ��ȫ����ը����
	REGION_RECORDPOS_DISABLE			= 18,           //�����¼��
	REGION_SUPPORT_STATION				= 20,           //����վ	
	REGION_JUMP_DISABLE					= 21,			//������������
	REGION_LIMITTIME_SHIP				= 22,			//�߼��޶������ɴ������ȴ�����
	REGION_SPECIAL_JUMP_EN 				= 25,           //��ͬ������Ծ���Ĳ�һ�� 2007-3-14 tcp add		
	REGION_RADIATION					= 30,           //����Ӱ�����ĵ�ͼ����	2007-2-25 tcp add
	REGION_DISABLE_TRANSPOS 			= 31,           //�����ٻ� 2007-2-27 tcp add
	REGION_FREE_JUMP 					= 34,           //������Ծ���жϾ��� 2007-2-28 tcp add	
	REGION_DISABLE_TRUMP_REBORN			= 37,           //��ֹʹ�÷��������		
	REGION_DISABLE_TRUMP_REGION			= 38,           //��ֹʹ�÷�����缼��		
	REGION_INFINITE_XP_REGION			= 39,			//����XP������������ 
	REGION_DISABLE_TRUMP_RAND_TRANS_POS = 40,			 //��ֹʹ�÷���-С˲��
	REGION_DISABLE_TRANSFORM			= 41,			//��ֹ����
	REGION_XP_REVERT_SPEED_ADJ			= 43,			//XP�ظ��ٶȿ�������, data0��ʾ���ӡ�data1��ʾ���٣���ͬʱ������
	REGION_DISABLE_MOUNT				= 44,			//�������
	REGION_SWEAR						= 45,			//�������	
	REGION_JUMP_ATKPOWER				= 46,			//��������ս��������
	REGION_JUMP_SPIRITLEV				= 47,			//��������������ȼ�����
	REGION_JUMP_MODELLEV				= 48,			//���������������Ǽ�����
	REGION_DISBLE_JOIN_PRIVATE_SHIPJOB	= 51,			//��ֹ�μ�˽�˸������������
	REGION_DISABLE_GODTRANSPORT			= 54,			//��ֹ���ɴ���
	REGION_NOT_INVITE					= 55,			//�����Ա�����
	REGION_CHECK_JUMP_OVER_HEIGHT		= 2000,			//������Ծ���߶ȵ�����

	REGION_ABATTOIR						= 56,			//�Ƕ������򣬹���ɻ�����ս
	REGION_NOT_CREATEDOMAIN				= 57,			//�޷���������

	REGION_DISABLE_CALLALTAR			= 58,			//��ֹ�ٻ���̳����
	REGION_COM_ALTAR					= 59,			//������̳����
	REGION_PRIVATE_ALTAR				= 60,			//����ٻ���̳����

	REGION_DISABLE_FLY					= 70,			//��ֹ��������
	REGION_BATTLE						= 71,			//ս������ ��ҽ������뱸ս״̬

	REGION_SAINT_LIGHT                  = 80,           // ���ڽ�����ʱ��ʹ��Ѫ����롰��Ѫ��ʥ������״̬����
	REGION_ANGEL_DRAW					= 90,			//��ʹ��ȡ��
	REGION_PEACE                        = 95,           //��ƽ���� ����2009 10 12 
	REGION_MONSTER                      = 96,           //��ƽ���� ����2009 10 12
	REGION_TRAP                         = 97,           //��ƽ���� ����2009 10 12
	REGION_SUN_SHINE                    = 65536,        //  Type = 65536�������������

};

enum AUTO_ACTIVE
{
		AUTOACTIVE_KILL		= 0x01,
		AUTOACTIVE_FOREVER	= 0x02,
		AUTOACTIVE_RANDOM	= 0x04,
};

enum USER_LOOK_FACE
{
	LOOK_MALEGHOST = 98,
	LOOK_FEMALEGHOST,
};  

enum USER_LOOK_SEX
{ 
	SEX_ALL = 0, 
	SEX_MAN, 
	SEX_WOMAN,
	SEX_ASEXUAL
};

enum 
{
	LOCK_STATUS				= 1 << 0,
	WAITINGUNLOCK_STATUS	= 1 << 1,
};

enum
{
	BUDDY_APPLY,		// ����
	BUDDY_REFUSE,		// �ܾ�
	BUDDY_ONLINE,		// ����
	BUDDY_OFFLINE,		// ����
	BUDDY_BREAK,		// �Ͻ�
	BUDDY_BASE_INFO,	// ������Ϣ
	BUDDY_DEL,			// ɾ����ɫ
	BUDDY_SYNC,			// ͬ��ʱ��
	BUDDY_APPLYPROMPT,	// ��������ҵ�����ʾ
};	

enum MOVE_MODE
{
	MOVEMODE_WALK=0,					// PathMove()��ģʽ
	MOVEMODE_RUN,
	MOVEMODE_SHIFT,						// to server only
	MOVEMODE_JUMP,
	MOVEMODE_TRANS,
	MOVEMODE_CHGMAP,
	MOVEMODE_JUMPMAGICATTCK,
	MOVEMODE_COLLIDE,
	MOVEMODE_SYNCHRO,					// to server only
	MOVEMODE_FLYNORMAL = 10,            // ����
	MOVEMODE_FLYMIDDLE,
	MOVEMODE_FLYFAST,                   // ���ٷ���
	MOVEMODE_FLOAT,                     // ����
	MOVEMODE_FLYSLOW,                   // ����
	MOVEMODE_MACHINEGUN_ATK=15,         // ��ǹ�ƶ����
	//�����е��ƶ���ʽ
	MOVEMODE_UNIVERSE_FLY	= 20,		// �����
	MOVEMODE_UNIVERSE_FLYFAST,			// ������
	MOVEMODE_WHIRLWIND,                 // ����ն
	/////////////////////////////
	MOVEMODE_NONE = 255,
};

enum ITEM_VALUE
{
	ITEM_VALUE_ID,
	ITEM_VALUE_TYPE,
	ITEM_VALUE_DATA1,
	ITEM_VALUE_VALUE,
};

enum 
{
	VALUE_RATIO = 1,
	VALUE_GEM1,
	VALUE_GEM2,
	VALUE_ADD,
	VALUE_ITEM,
	VALUE_DMG_REDUCE,
};


//////////////////////////////////////////////////////////////////////
//����ö�ٶ�������PET
enum PETDATA
{
	PETDATA_ID	   =0,
	PETDATA_OWNERID ,
	PETDATA_OWNERTYPE,
	PETDATA_GENID,
	PETDATA_TYPE,
	PETDATA_NAME,
	PETDATA_LIFE,
	PETDATA_MANA,
	PETDATA_MAPID,
	PETDATA_RECORD_X,
	PETDATA_RECORD_Y,
	PETDATA_DATA,						// ���������޼�¼NPCID
	PETDATA_DATA1,						// ����������itemtype.id
	PETDATA_DATA2,						// �����ڻ���robottype
	PETDATA_NUMBER,	
};

enum
{ 
	POSE_STAND	= 0 
};

enum STORAGE_TYPE 
{
	STORAGE_NONE			= 0,
	STORAGE_STORE			= 10,
	STORAGE_TRUNK			= 20,
	STORAGE_CHEST			= 30,
};
enum WEATHER_TYPE
{ 
	WEATHER_NONE        =   0, 
    WEATHER_FINE,           //����(������)
    WEATHER_RAINY,          //����
    WEATHER_SNOWY,          //��ѩ
	WEATHER_SANDS,          //��ɳ
	WEATHER_LEAF,           //��Ҷ
	WEATHER_BAMBOO,         //ƮҶ
    WEATHER_FLOWER,         //�仨
    WEATHER_FLYING,         //�ɻ�
    WEATHER_DANDELION,      //�ѹ�Ӣ
    WEATHER_WORM,           //ө���
    WEATHER_CLOUDY,         //Ʈ��
    WEATHER_ALL
};


enum TRAININGSTATE
{
	TRAINING_NORMAL = 10,
	TRAINING_PAUSE  = 11,
	TRAINING_STOP   = 12,
};

enum  HOTAGEDATA
{
	HOSTAGE_ID,
	HOSTAGE_TYPE,
	HOSTAGE_SEX,
	CHARACTER_TYPE,
	CHARACTER,
};

enum PEERAGE_RANK
{
	PEERAGERANK_NONE,
	PEERAGERANK_BARON = 1,		//�о�
	PEERAGERANK_VISCOUNT = 3,	//�Ӿ�
	PEERAGERANK_EARL = 5,		//����
	PEERAGERANK_MARQUIS = 7,	//���
	PEERAGERANK_DUKE = 9,		//����
	PEERAGERANK_KING = 12,		//����/Ů��
};

// װ��Ʒ��itemtype�����һλ
enum
{
	NORMAL = 5,			// ��Ʒ Normal
	REFINED,			// ��Ʒ Refined
	UNIQUE,				// ��Ʒ Unique
	ELITE,				// ��Ʒ Elite
	SUPER,				// ��Ʒ Super
};
enum
{
	PK_ITEM_ID,
	PK_ITEM_ITEM,
	PK_ITEM_TARGET,
	PK_ITEM_TARGET_NAME,
	PK_ITEM_HUNTER,
	PK_ITEM_HUNTER_NAME,
	PK_ITEM_MANHUNT_TIME,
	PK_ITEM_BONUS
};

enum 
{ 
	QUERY_DETAIN_ITEM_REDEEM, 
	QUERY_DETAIN_ITEM_BONUS 
};

enum DYNA_RANK_REC_DATA
{
	RANK_REC_ID,
	RANK_REC_TYPE,
	RANK_REC_VALUE,
	RANK_REC_OBJID,
	RANK_REC_OBJNAME,
	RANK_REC_USERID,
	RANK_REC_USERNAME,
};

enum DYNA_RANK_TYPE_DATA
{
	RANK_TYPE_ID,
	RANK_TYPE_TYPE,
	RANK_TYPE_NUM,
	RANK_TYPE_DATAMIN,
	RANK_TYPE_TIMETYPE,
	RANK_TYPE_COMMENT,
};

enum RANKTYPE_DATA
{
	RANKTYPE_ID,
	RANKTYPE_TYPE,
	RANKTYPE_NUM,
	RANKTYPE_DATA_MIN,
};

enum RANKSORT_DATA
{
	RANKSORT_ID,
	RANKSORT_TYPE,
	RANKSORT_VALUE,
	RANKSORT_OBJID,
	RANKSORT_OBJNAME,
	RANKSORT_USERID,
	RANKSORT_USERNAME,
};

enum ACT_TYPE
{
	ACT_QUERY_SORT	= 1,
	ACT_QUERY_MINE	= 2,
	ACT_QUERY_VALUE_BY_POS	= 3,
	ACT_QUERY_EFFECT,
	ACT_QUERY_END,
};

enum SYSBUYERDATA
{
	SYSBUYERDATA_ITEM = 1,
	SYSBUYERDATA_INTERVAL,
	SYSBUYERDATA_MIN_PRICE,
	SYSBUYERDATA_MAX_PRICE,
};


enum 
{
	DETECTOR_NONE = 0, 
	DETECTOR_VERIFYDATA
};

enum FLOWER_TYPE
{
	FLOWER_R,
	FLOWER_W,
	FLOWER_LILY,
	FLOWER_TULIP
};

enum INSTANTMAPITEMDATA{
		INSTANTMAPITEMDATA_ID	= 0,
		INSTANTMAPITEMDATA_MAPID,
		INSTANTMAPITEMDATA_X,
		INSTANTMAPITEMDATA_Y,
		INSTANTMAPITEMDATA_RANGE,
		INSTANTMAPITEMDATA_SEC,
		INSTANTMAPITEMDATA_ITEMTYPE,
};


//////////////////////////////////////////////////////////////////////
enum SPIRITTYPEDATA{
	SPIRITTYPEDATA_ID = 0,
	SPIRITTYPEDATA_PRICE,			// �����׶�
	SPIRITTYPEDATA_HP,
	SPIRITTYPEDATA_INCREASE,
	SPIRITTYPEDATA_TOTALINSIDESIZE,
	SPIRITTYPEDATA_SIZEX,
	SPIRITTYPEDATA_WEIGHTLIMIT,
	
	SPIRITTYPEDATA_DMG_SHARE,	
	SPIRITTYPEDATA_DATA0,	
	SPIRITTYPEDATA_DATA1,
	SPIRITTYPEDATA_DATA2,
	SPIRITTYPEDATA_DATA3,
	SPIRITTYPEDATA_DATA4,

	SPIRITTYPEDATA_DATA5,
	SPIRITTYPEDATA_DATA6,
	SPIRITTYPEDATA_DATA7,
	SPIRITTYPEDATA_REQLEV,
	SPIRITTYPEDATA_WEAPONSKILL,
	SPIRITTYPEDATA_SEX,
	SPIRITTYPEDATA_HOTDEF,SPIRITTYPEDATA_LIFE_RE = SPIRITTYPEDATA_HOTDEF,
	SPIRITTYPEDATA_ShAKEDEF,
	SPIRITTYPEDATA_COLDDEF,SPIRITTYPEDATA_WEAPON_TYPE = SPIRITTYPEDATA_COLDDEF,
	SPIRITTYPEDATA_LIGHTDEF,

	SPIRITTYPEDATA_LOOK,
	SPIRITTYPEDATA_TYPENAME,		// 2006.01.16 ��֪��˭�ӵ����ݿ��ֶΣ���������ȴû�����ӣ������ص����⡣
	SPIRITTYPEDATA_AMOUNTADD,	// 2006.01.16 �����װ����������(1-255)������Ϊ1
	SPIRITTYPEDATA_SPIRITNAME,
	SPIRITTYPEDATA_DODGE,
	SPIRITTYPEDATA_EXPTYPE,		// 2006.06.04 ��Ӧlevexp.type ���徭��(type=1��type=2��)��ע���������Ƴ��������鲻ͬ�Ķ��ֻ��壩
	SPIRITTYPEDATA_DMGTYPE,
	
	
	/////��ɾ��
//	SPIRITTYPEDATA_RACE,				// enum { RACE_EARTH=1, RACE_SPACE=2, RACE_DUAL=3 };
//	SPIRITTYPEDATA_SORT,				// enum { SPIRITSORT_NONE=0, SPIRITSORT_FIGHTER, SPIRITSORT_GUNNER, SPIRITSORT_ENERGY, SPIRIT_ASSISTANT };
};


	enum { ATTACK_TIME=false, BEATTACK_TIME=true, BY_WEAPON=false, BY_MAGIC=true };


	// requre sex define
	const unsigned char SEX_REQ_MAN			=	0x01;// �еĿ���
	const unsigned char SEX_REQ_WOMAN		=	0x02;// Ů�Ŀ���
	const unsigned char SEX_REQ_EUNUCH		=	0x04;// ̫�����

	enum ENGINESPEND
	{// 2006.11.01
		ENGINESPEND_SKILL,					// ʹ�ü��ܣ����Ķ�
		ENGINESPEND_EQUIPT_DIRECTOUTPUT,	// ���ķ��������������װ�����������ƽ���������װ�á�����װ��
		ENGINESPEND_EQUIPT_USEEN,			// ���ķ����������۵�װ����������������������
	};

	// GetRevertType��������
	enum REVERT_TYPE{
			REVERT_HP				= 0,
			REVERT_EN				= 1,
			REVERT_FUEL				= 2,
			REVERT_STATUS			= 3,
			REVERT_EQUIP			= 4,
			REVERT_ENGIN			= 5,
	};

	enum EEliteJudgeType
	{
		ELITEJUDGE_TRADE,
			ELITEJUDGE_BOOTH,
			ELITEJUDGE_SELL,
			ELITEJUDGE_DROP,
	};

	enum {	PROFSORT_ROBBER		=0, 
		PROFSORT_OFFICER 	=1, 

		// no use
		PROFSORT_ARCHER		=3, 
		PROFSORT_WIZARD		=4, 
		PROFSORT_DAOIST		=10, 
		PROFSORT_DAOISTGOLD	=11, 
		PROFSORT_DAOISTWOOD	=12, 
		PROFSORT_DAOISTWATER=13, 
		PROFSORT_DAOISTFIRE	=14, 
		PROFSORT_DAOISTEARTH=15, 
	};

	//////////////////////////////////////////////////////////////////////
	enum INFO_ID{
			INFO_NONE=0,
			INFO_ITEM,
			INFO_FRIEND,
			INFO_ENEMY,
			INFO_WEAPONSKILL,
			INFO_MAGIC,
			INFO_SYNATTR,
			INFO_STATUS,
			INFO_TEAM,
			INFO_VIPLEVEL,
	};

	////////////////////////////////////////////////////////////////
	enum REMOTE_CALL{
			REMOTE_CALL_DROP_LEADER,
			REMOTE_CALL_LEAVE_SYN,
			REMOTE_CALL_TEAM_CLOSE_MONEY,
			REMOTE_CALL_TEAM_CLOSE_ITEM,
			REMOTE_CALL_TEAM_CLOSE_GEM_ACCESS,
			REMOTE_CALL_TEAM_ADD_VIRTUE,
			REMOTE_CALL_TEAM_HUNTKILL,
			REMOTE_CALL_SYSMSG_SEND,
			REMOTE_CALL_LEAVE_FAMILY,
	};

enum	//�˶����Ѳ�ʹ�ã���ʹ�����Ķ���
{
	RANK_COMMANDER							= 1000,					// ����˾��
	RANK_LEADER								= RANK_COMMANDER,
	
	RANK_VICE_COMMANDER						= 990,					// ������˾��
	RANK_VICE_COMMANDER_DESIGNATED			= 980,					// ����������˾��
	RANK_COMMANDER_MATE						= 920,					// ����˾�����
	
	RANK_CORP_COMMANDER						= 890,					// ����������
	RANK_CORP_COMMANDER_DESIGNATED			= 880,					// ��������������		
	RANK_DIVISION_COMMANDER					= 850,					// ʦ��������
	RANK_DIVISION_COMMANDER_DESIGNATED		= 840,					// ����ʦ��������
	
	RANK_REGIMENTAL_COMMANDER				= 690,					// �ų�������
	RANK_REGIMENTAL_COMMANDER_DESIGNATED	= 680,					// �����ų�������

	RANK_VICE_COMMANDER_MATE				= 620,					// ������˾�����
	RANK_VICE_COMMANDER_ASSITANT			= 611,					// ������˾�������
	RANK_COMMANDER_MATE_ASSITANT			= 610,					// ����˾���������
	
	RANK_COMPANY_COMMANDER					= 590,					// ����������
	RANK_CORP_COMMANDER_MATE				= 520,					// �������¡����ϰ���
	RANK_DIVISION_COMMANDER_MATE			= 521,					// ʦ�����¡���������
	RANK_DIVISION_COMMANDER_ASSISTANT		= 511,					// ʦ��������������		
	RANK_CORP_COMMANDER_ASSISTANT			= 510,					// ����������������
	
	RANK_PLATOON_LEADER  					= 490,					// �ų���ͷĿ
	RANK_REGIMENTAL_COMMANDER_MATE			= 420,					// ��������
	
	RANK_SENIOR_MONITOR						= 210,					// ����೤����Ա
	RANK_MONITOR							= 200,					// �೤����Ա
	
	RANK_SOLIDER							= 100,					// սʿ��Ԥ����Ա
	RANK_NONE								= 0,
};

enum SYN_MEMBER_RANK
{
	RANK_Leader								= RANK_COMMANDER,						// �����ų�         100%
		
	RANK_SecondLeader						= RANK_VICE_COMMANDER,					// ���ų�            90%
	RANK_SecondLeader_Designated			= RANK_VICE_COMMANDER_DESIGNATED,		// �����ĸ��ų�		 90%
	RANK_LeaderMate							= RANK_COMMANDER_MATE,					// ���ų�����        90%
		
	RANK_Elder		 						= RANK_CORP_COMMANDER,					// ����              80%
	RANK_Elder_Designated					= RANK_CORP_COMMANDER_DESIGNATED,		// �����ĳ���        80%
		
	RANK_Brainman_Leader                    = 870,                                  //�����ı��         80%
	RANK_Brainman                           = 860,                                  //�����ı           70%
		
	RANK_Guard								= RANK_DIVISION_COMMANDER,				// ����				 70%
	RANK_Guard_Designated					= RANK_DIVISION_COMMANDER_DESIGNATED,	// �����Ļ���        70%
		
	RANK_GroupLeader						= RANK_REGIMENTAL_COMMANDER,			// ����              50%
	RANK_GroupLeader_Designated				= RANK_REGIMENTAL_COMMANDER_DESIGNATED,	// ����������        50%
		
	RANK_SecondGroupLeader					= 650,									//��ָ�ӹ�/�����  50%
		
	RANK_SecondLeaderMate					= RANK_VICE_COMMANDER_MATE,				// ���ų�����        50%
	RANK_SecondLeaderAssistant				= RANK_VICE_COMMANDER_ASSITANT,			// ���ų�������      50%		
	RANK_LeaderMateAssistant				= RANK_COMMANDER_MATE_ASSITANT,			// ���ų���������    50%
		
	RANK_HenchMan_Leader		= 602,			// ���ų�����		 50%
	//-----------------------------------------------------------------------------
	RANK_GroupLeader_Standard	= 600,			// ������׼(����ְλ��ֻ��һ���籮)
	//-----------------------------------------------------------------------------
	RANK_DonateRMB_TeamLeader				= 597,									// Ԫ��ִ�й�		 30%
	RANK_DonateRobot_TeamLeader				= 596,									// ����ִ�й�		 30%
	RANK_DonateMoney_TeamLeader				= 595,									// ����ִ�й�		 30%
	RANK_DonateExploit_TeamLeader			= 593,									// ��ѫִ�й�		 30%
	RANK_Rose_TeamLeader					= 591,									// õ��ִ�й�		 30%
		
	RANK_TeamLeader							= RANK_COMPANY_COMMANDER,				// ������ִ�й�      30%
	RANK_ElderMate							= RANK_CORP_COMMANDER_MATE,				// ���ϰ���          30%
	RANK_GuardMate							= RANK_DIVISION_COMMANDER_MATE,			// ��������          30%
	RANK_GuardAssistant						= RANK_DIVISION_COMMANDER_ASSISTANT,	// ��������          30%		
	RANK_ElderAssistant						= RANK_CORP_COMMANDER_ASSISTANT,		// ��������          30%
	//-----------------------------------------------------------------------------
	RANK_TeamLeader_Standard	= 500,			// ������׼(����ְλ��ֻ��һ���籮)
	//-----------------------------------------------------------------------------
	RANK_DonateRMB_SmallLeader				= 497,									// Ԫ����Ӣ��Ա		 20%
	RANK_DonateRobot_SmallLeader			= 496,									// ���徫Ӣ��Ա		 20%
	RANK_DonateMoney_SmallLeader			= 495,									// ����Ӣ��Ա		 20%
	RANK_DonateExploit_SmallLeader			= 493,									// ��ѫ��Ӣ��Ա		 20%
	RANK_Rose_SmallLeader					= 491,									// õ�徫Ӣ��Ա		 20%
	
	RANK_SmallLeader						= RANK_PLATOON_LEADER,					// ͷĿ����Ӣ��Ա    20%
	RANK_GroupLeaderMate					= RANK_REGIMENTAL_COMMANDER_MATE,		// ��������          20%
	
	RANK_HenchMan_SecondLeader				= 405,									// ���ų�����		 20%
	RANK_HenchMan_SecondLeaderD				= 404,									// �������ų�����	 20%
	RANK_HenchMan_LeaderMate				= 403,									// �ų���������		 20%
	RANK_HenchMan_Elder						= 402,									// ��������			 20%
	RANK_HenchMan_ElderD					= 401,									// ������������		 20%
	
	RANK_SeniorNewbie						= RANK_SENIOR_MONITOR,					// ������Ա			 15%
	RANK_Newbie								= RANK_MONITOR,							// ��ͨ��Ա          10%
	RANK_Solider							= RANK_SOLIDER,							// Ԥ����Ա           0%
	RANK_None								= 0,
};

//////////////////////////////////////////////////////////////////////
enum 
{
		DIE_NORMAL			= 1,
		DIE_CRITICALHIT		= 2,
		DIE_MAGIC			= 3,
		DIE_FLOAT			= 4,		// only for client
		DIE_ARROWSHOOT		= 5,
		DIE_DELAY			= 6,		// �ӳ���ͻ��˷�������Ϣ�����ڴ���
		DIE_SUICIDE         = 7,		// ������ɱ(����)
		DIE_SUCKBLOOD_EXPIATE	= 8,	// ����Ѫ����ϴ����
};

	//////////////////////////////////////////////////////////////////////
	enum CONDITION_USER_TYPE
	{
		CONDITION_USER_ALL,
		CONDITION_USER_LIVE,	
	};

	//�Ƿ��Զ��������
	enum {_NOT_AUTOALLOT = 0, _AUTOALLOT = 1};
	enum {LOCK_NOT_OPEN = 0, LOCK_OPENED = 1};

	////////////////////////////////////////////////////////////////
	enum FLOATELECTROM_STATUS
	{
		FLOATELECTROM_STATUS_NONE,
		FLOATELECTROM_STATUS_ATTACK,
		FLOATELECTROM_STATUS_REINFORCE,
		FLOATELECTROM_STATUS_COUNTERSTROKE,
	};
	////////////////////////////////////////////////////////////////
	//��Ҳ���λ�õ�����
	enum USER_WEAKNESS
	{
		USER_WEAKNESS_OUTER_THRUSTOR = 0x00000001,
		USER_WEAKNESS_OUTER_DODGING  = 0x00000002,
		USER_WEAKNESS_OUTER_DEFENDER = 0x00000004,
		USER_WEAKNESS_INNER_ENGINE   = 0x00000008,
		USER_WEAKNESS_INNER_ENPACK   = 0x00000010,
		USER_WEAKNESS_INNER_ENERGYGENERATOR = 0x00000020,	
	};
//////////////////////////////////////////////////////////////////////
// ������������� tcp 2006.11.
enum MONSTER_WEAKNESS
{
	MONSTER_WEAKNESS_MOVE  = 0x00000001,
	MONSTER_WEAKNESS_TURN  = 0x00000002,
	MONSTER_WEAKNESS_POWER = 0x00000004,
	MONSTER_WEAKNESS_ALL   = MONSTER_WEAKNESS_MOVE|MONSTER_WEAKNESS_TURN|MONSTER_WEAKNESS_POWER,
};


enum BATTLESIDE_TYPE
{
	BATTLESIDE_NONE,
	BATTLESIDE_MONSTER = 1,
	BATTLESIDE_USER,         //������Һ�������
	//BATTLESIDE_MAGIC,
};

	enum EXCHANG_TYPE{EXCHANG_TYPE_STONE2_TO_STONE1=0,EXCHANG_TYPE_STONE2_TO_STONE0,EXCHANG_TYPE_STONE1_TO_STONE0};//�ǻ�ʯ���� tcp 2007-4-17 

	enum EXP_ADJ_TYPE
	{
		TEAMXP_EXP_ADJ,
		TEAMXP_EXP_MEDICINE,
		TEAMXP_EXP_GEM,
	};


enum
{
	TEAMEXP_ORDER_BASE,				//��������
	TEAMEXP_ORDER_VIP,				//��У���˻���
	TEAMEXP_ORDER_STAR,				//ս�����Ǽ���
	TEAMEXP_ORDER_SUPPORT,			//״̬������
	TEAMEXP_ORDER_MEDICINE,			//����ҩˮ	
	TEAMEXP_ORDER_CRYSTAL,			//����ˮ��
	TEAMEXP_ORDER_NUM,
};

enum{
	TEAM_ROLEPLAYING_NONE = -1,
	TEAM_ROLEPLAYING_ATTACKER = 0,	//������
	TEAM_ROLEPLAYING_TANK,			//���
	TEAM_ROLEPLAYING_HEALER,		//������
	TEAM_ROLEPLAYING_INSPIRER,		//������
};

	enum 
	{
		TEAM_DEF_SHARE,
		TEAM_HIGHLEV_SHARE,
		TEAM_BATTLE_SHARE,
	};
	enum
	{
		TEAM_EVENT_SHARE,
		TEAM_EVENT_REBORN,
		TEAM_EVENT_DIE,
	};
	enum
	{
		FAMILY_BATTLESHARE_LIMIT,
		BROTHER_BATTLESHARE_LIMIT,	
	};
	enum
	{
		MAIN_SPIRIT,
		LEFT_SPIRIT,
		RIGHT_SPIRIT,
	};
	enum 
	{
		PACKET_BAG,
		PACKET_GENAKOO_COMMON,
		PACKET_GENAKOO_CAGE,
		PACKET_GENAKOO_REST,
	};

enum TUTOR_AWARD_TYPE
{
	TUTOR_AWARD_TYPE_GOD_TIME,
	TUTOR_AWARD_TYPE_UPLEVTIME,
	TUTOR_AWARD_TYPE_SPIRIT,
	TUTOR_AWARD_TYPE_EXP,
	TUTOR_AWARD_TYPE_MAX,
};

enum TUTOR_MEMBER_TYPE
{
	MEMBER_TUTOR_TYPE,
	MEMBER_STUDENT_TYPE,
	MEMBER_SUBSTUDENT_TYPE, 
};


enum {
	FAMILY_RANK_SHAIKH	= 100,		// �峤
	FAMILY_RANK_MATE	= 50,		// ��ż
	FAMILY_RANK_MEMBER	= 10,		// ��Ա
	FAMILY_RANK_NONE	= 0,
};

enum TEAMATTR
{
	TEAM_LEADER_ID,
	TEAM_MEMBER_COUNT,
	TEAM_SHARE_MONEY,
	TEAM_SHARE_ITEM,
	
};

enum SPIRITATTR
{
	_SPIRITATTRIB_POWER						= 1,		// ��������ǰ����ֵ
	_SPIRITATTRIB_EN							= 2,	// ��ǰEnֵ(En�ֵ�ǰ��Enֵ)
	_SPIRITATTRIB_KEEPEFFECT					= 26,
	_SPIRITATTRIB_EXP						= 35,	// ���徭��
	_SPIRITATTRIB_LEV						= 36,	// ����ȼ�
	_SPIRITATTRIB_FUEL						= 56,		// ȼ��
	_SPIRITATTRIB_GENERATOR					= 63,	// ����������������
	
	_SPIRITATTRIB_MODEL_LEV					= 69,
	_SPIRITATTRIB_NIMBUS						= 70,   // ����
	_SPIRITATTRIB_NIMBUSUSAGE				= 71,	// �������Ӵ���	
	_SPIRITATTRIB_SYNDICATEID				= 76,   // ���形��ID

	_SPIRITATTRIB_HAIR                       = 80,   //��������
	
	_SPIRITATTRIB_LIFE						= 107,
	
	_SPIRITATTRIB_MAXLIFE					= 300,
	_SPIRITATTRIB_MAXMANA					= 301,
	_SPIRITATTRIB_MAXFUEL					= 302,
	
	_SPIRITATTRIB_GUARDSKILL_BEGIN			= 351,
	_SPIRITATTRIB_GUARDSKILL1				= 351,
	_SPIRITATTRIB_GUARDSKILL2				= 352,
	_SPIRITATTRIB_GUARDSKILL3				= 353,
	_SPIRITATTRIB_GUARDSKILL4				= 354,
	_SPIRITATTRIB_GUARDSKILL5				= 355,
	_SPIRITATTRIB_GUARDSKILL6				= 356,
	_SPIRITATTRIB_GUARDSKILL7				= 357,
	_SPIRITATTRIB_GUARDSKILL8				= 358,
	_SPIRITATTRIB_GUARDSKILL_END			= 400,

	_SPIRITATTRIB_PROFESSION_LEV            = 500,   //ְҵ�ȼ�
	_SPIRITATTRIB_PROFESSION_EXP            = 501,   //ְҵ����ֵ

	_SPIRITATTRIB_MAX_SPEED                 = 601,   //�ƶ��ٶ�

	_SPIRITATTRIB_MAX_UNDERWATER_SPEED      = 602,   //ˮ���ƶ��ٶ�


	_SPIRITATTRIB_LOAD						= 401,	//�ھ���
	
	_SPIRITATTRIB_NONE	= 65535,			// �Ƿ�ֵ
};

enum MONSTEREXPDATA
{
	MONSTEREXPDATA_ID_,
	MONSTEREXPDATA_MONSTERSORT,				//����sort���ͣ���Ӧcq_monster���sort�ֶ�
	MONSTEREXPDATA_LEVEL,					//����ͼ���ȼ�
	MONSTEREXPDATA_MONSTEREXP,				//�ﵽ��ͼ���ȼ���Ҫ��ͼ������ֵ
};

//�������Ͷ��壨ĩ��Σ����Ϸ���ڷ�������ڱ�ʾһ������ļ������ͣ�
//��MAGICKIND_ICE_BALL=xxx����ʾ���������ּ��ܣ�xxx�������magictype�������ݶ�Ӧ�Ĺ�ϵ��ֵ��
enum MAGICKIND
{
	MAGICKIND_NONE						= 0,

	//���м���
	MAGICKIND_HAMMER_LIGHT1 = 30500100,
	MAGICKIND_HAMMER_LIGHT2 = 30500301,
	MAGICKIND_HAMMER_LIGHT3 = 30500302,
	MAGICKIND_HAMMER_LIGHT4 = 30500303,

	MAGICKIND_HAMMER_HEAVY1 = 30500000,
	MAGICKIND_HAMMER_HEAVY2 = 30500201,
	MAGICKIND_HAMMER_HEAVY3 = 30500202,
	MAGICKIND_HAMMER_HEAVY4 = 30500203,
	MAGICKIND_HAMMER_HEAVY5 = 30500204,

	MAGICKIND_AX_LIGHT1 = 30300100,
	MAGICKIND_AX_LIGHT2 = 30300301,
	MAGICKIND_AX_LIGHT3 = 30300302,
	MAGICKIND_AX_LIGHT4 = 30300303,

	MAGICKIND_AX_HEAVY1 = 30300000,
	MAGICKIND_AX_HEAVY2 = 30300201,
	MAGICKIND_AX_HEAVY3 = 30300202,
	MAGICKIND_AX_HEAVY4 = 30300203,
	MAGICKIND_AX_HEAVY5 = 30300204,

	MAGICKIND_BARE_HANDER_LIGHT1 = 30000100,
	MAGICKIND_BARE_HANDER_LIGHT2 = 30000301,
	MAGICKIND_BARE_HANDER_LIGHT3 = 30000302,
	MAGICKIND_BARE_HANDER_LIGHT4 = 30000303,

	MAGICKIND_BARE_HANDER_HEAVY1 = 30000000,
	MAGICKIND_BARE_HANDER_HEAVY2 = 30000201,
	MAGICKIND_BARE_HANDER_HEAVY3 = 30000202,
	MAGICKIND_BARE_HANDER_HEAVY4 = 30000203,
	MAGICKIND_BARE_HANDER_HEAVY5 = 30000204,

	MAGICKIND_FISTS_LIGHT1 = 30700100,
	MAGICKIND_FISTS_LIGHT2 = 30700301,
	MAGICKIND_FISTS_LIGHT3 = 30700302,
	MAGICKIND_FISTS_LIGHT4 = 30700303,

	MAGICKIND_FISTS_HEAVY1 = 30700000,
	MAGICKIND_FISTS_HEAVY2 = 30700201,
	MAGICKIND_FISTS_HEAVY3 = 30700202,
	MAGICKIND_FISTS_HEAVY4 = 30700203,
	MAGICKIND_FISTS_HEAVY5 = 30700204,

	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_LIGHT1 = 30100100,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_LIGHT2 = 30100301,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_LIGHT3 = 30100302,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_LIGHT4 = 30100303,

	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_HEAVY1 = 30100000,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_HEAVY2 = 30100201,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_HEAVY3 = 30100202,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_HEAVY4 = 30100203,
	MAGICKIND_DOUBLE_HANDED_BROADSWORDS_HEAVY5 = 30100204,

	MAGICKIND_TWO_HANDED_SWORD_LIGHT1 = 30200100,
	MAGICKIND_TWO_HANDED_SWORD_LIGHT2 = 30200301,
	MAGICKIND_TWO_HANDED_SWORD_LIGHT3 = 30200302,
	MAGICKIND_TWO_HANDED_SWORD_LIGHT4 = 30200303,

	MAGICKIND_TWO_HANDED_SWORD_HEAVY1 = 30200000,
	MAGICKIND_TWO_HANDED_SWORD_HEAVY2 = 30200201,
	MAGICKIND_TWO_HANDED_SWORD_HEAVY3 = 30200202,
	MAGICKIND_TWO_HANDED_SWORD_HEAVY4 = 30200203,
	MAGICKIND_TWO_HANDED_SWORD_HEAVY5 = 30200204,

	MAGICKIND_LONG_STAFF_LIGHT1 = 30400100,
	MAGICKIND_LONG_STAFF_LIGHT2 = 30400301,
	MAGICKIND_LONG_STAFF_LIGHT3 = 30400302,
	MAGICKIND_LONG_STAFF_LIGHT4 = 30400303,

	MAGICKIND_LONG_STAFF_HEAVY1 = 30400000,
	MAGICKIND_LONG_STAFF_HEAVY2 = 30400201,
	MAGICKIND_LONG_STAFF_HEAVY3 = 30400202,
	MAGICKIND_LONG_STAFF_HEAVY4 = 30400203,
	MAGICKIND_LONG_STAFF_HEAVY5 = 30400204,

	MAGICKIND_TUMBLE = 40000002,
	//�����Զ��弼�ܣ���magictype���ݣ�
	MAGICKIND_CUSTOM_RANGE = 1000,	//�����Զ��弼����С�ڴ�ֵ
	MAGICKIND_IGNITE = 10,	//ȼ�ռ��� TQD16910��ĩ��Σ��������ȼ�ձ�ը������ܰ�

	//��������ڲ��Եļ�������
	MAGICKIND_TEST = 199,
	MAGICKIND_TEST2 = 30100100,
	MAGICKIND_TEST3 = 30100201,
};

// ��������Ѫ������еļ������Ͷ���ֵ��Ӧ��ɾ�� 2010-01-30
//////////////////////////////////////////////////////////////////////
enum MAGICSORT
{
		MAGICSORT_NONE				= 0,
		MAGICSORT_KICKBACK			= 1,			// ����  	
 		MAGICSORT_KICKDOWN			= 2,			// ����
		MAGICSORT_KICKFLYAWAY		= 3,			// ����
		MAGICSORT_FAN				= 4,			// support auto active(random).
		MAGICSORT_BOMB				= 5,
		MAGICSORT_ATTACHSTATUS		= 6,
		MAGICSORT_DETACHSTATUS		= 7,
		MAGICSORT_SQUARE			= 8,
		MAGICSORT_JUMPATTACK		= 9,			// move, a-lock
		MAGICSORT_RANDOMTRANS		= 10,			// move, a-lock
		MAGICSORT_DISPATCHXP		= 11,
		MAGICSORT_COLLIDE			= 12,			// move, a-lock & b-synchro
		MAGICSORT_SERIALCUT			= 13,			// auto active only.
		MAGICSORT_LINE				= 14,			// support auto active(random).
		MAGICSORT_ATKRANGE			= 15,			// auto active only, forever active.
		MAGICSORT_ATKSTATUS			= 16,			// support auto active, random active.
		MAGICSORT_CALLTEAMMEMBER	= 17,
		MAGICSORT_RECORDTRANSSPELL	= 18,
		MAGICSORT_TRANSFORM			= 19,
		MAGICSORT_ADDMANA			= 20,			// support self target only.
		MAGICSORT_LAYTRAP			= 21,
		MAGICSORT_DANCE				= 22,			// ����(only use for client)
		MAGICSORT_CALLPET			= 23,			// �ٻ���
		MAGICSORT_VAMPIRE			= 24,			// ��Ѫ��power is percent award. use for call pet
		MAGICSORT_INSTEAD			= 25,			// ����. use for call pet
		MAGICSORT_DECLIFE			= 26,			// ��Ѫ(��ǰѪ�ı���)
		MAGICSORT_GROUNDSTING		= 27,			// �ش�
		// jz
		MAGICSORT_NORMAL			= 100,			// ��ͨ���幥����
		MAGICSORT_EXPLODE			= 101,			// ����ը
		MAGICSORT_DOUBLE			= 103,			// ����һ��
		MAGICSORT_MORTAL			= 104,			// һ����ɱ
		MAGICSORT_FINAL				= 105,			// �սἼ
		MAGICSORT_EXTREMITY			= 106,			// ������
		MAGICSORT_STATUS			= 107,			// ����״̬
		MAGICSORT_DESTROY			= 108,			// �ƻ�װ��
		MAGICSORT_LOOP	 			= 109,			// ѭ������
		MAGICSORT_STEAL				= 110,			// ͵
		MAGICSORT_BEATBACK			= 111,			// ����
		MAGICSORT_SELFBACK			= 112,			// ����
		MAGICSORT_WOUND				= 113,			// ���˺������Լ�����
		MAGICSORT_KILL				= 114,			// �����������Լ�����
		MAGICSORT_ADD				= 115,			// ��������
		MAGICSORT_DEFENCE_INVALID	= 117,			// ���ӷ���
		MAGICSORT_REBORN			= 118,			// ����
		MAGICSORT_ADD_RANGE			= 119,			// ��Χ����
		MAGICSORT_AIR				= 120,			// �յ�����
		MAGICSORT_DROP_MAPITEM		= 121,			// ���ӵ���Ʒ�ĸ���
		MAGICSORT_DROP_MONEY		= 122,			// ���ӵ�Ǯ�ĸ���
		MAGICSORT_DROP_STONE		= 123,			// ���ӵ�ԭʯ�ĸ���
		MAGICSORT_DROP_EXP			= 124,			// ���ӵ�����ĸ���
		MAGICSORT_ONRUSH			= 125,			// ͻ������
		MAGICSORT_CANNONFIREOVERCAST= 126,			// �ڻ𸲸�
		MAGICSORT_CLOSETODIE		= 127,			// ��������
		MAGICSORT_FUELERASER		= 128,			// ȼ��ɱ��
		MAGICSORT_ENERGYERASER		= 129,			// Enɱ��
		MAGICSORT_BURNWALLAMMO		= 130,			// ȼ�յ�
		MAGICSORT_INJURESELF		= 131,			// ����
		MAGICSORT_BODYBLAST			= 132,			// ʬ��
		MAGICSORT_CURE				= 134,			// ����
		MAGICSORT_RECOVERHP			= 135,			// HP�ظ�
		MAGICSORT_DRAWCLOSE			= 136,			// ����
		MAGICSORT_ADDITIONINJURE	= 137,			// ���˺������˺�
		MAGICSORT_CAPTURE			= 138,			// ����
		MAGICSORT_RETALIATEUPON		= 139,			// ����
		MAGICSORT_SHIELDSKILL		= 140,			// �ܼ���
		MAGICSORT_SHIELDSKILL1		= 141,			// �ܼ���1
		MAGICSORT_SHIELDSKILL2		= 142,			// �ܼ���2
		MAGICSORT_SHIELDSKILL3		= 143,			// �ܼ���3
		MAGICSORT_SEARCHBODY		= 144,			// ����
		MAGICSORT_IMPACT			= 145,			// ײ��
		MAGICSORT_SELFBLAST1		= 146,			// �Ա�1
		MAGICSORT_SELFBLAST2		= 147,			// �Ա�2
		MAGICSORT_SELFBLAST3		= 148,			// �Ա�3
		MAGICSORT_MINESWEEPING		= 150,			// ����			
		MAGICSORT_INTERLINK			= 151,			// ����
		MAGICSORT_INTERLINKFORCE	= 152,			// ����������ǿ��һ����������
		MAGICSORT_INTERLINKFAINT	= 153,			// �����������һ���μ���
		MAGICSORT_INTERLINKEXTRA	= 154,			// �����������ӹ�����������
		MAGICSORT_COUNTERSTRICK		= 155,			// ����
		MAGICSORT_COUNTERSTRICKFORCE= 157,			// ����������ǿ���� ����
		MAGICSORT_COUNTERSTRICKLIGHT= 158,			// ����������ǿ���� ����
		MAGICSORT_RETALIATEUPONCURSE= 159,			// �������� ����
		MAGICSORT_RETALIATEUPONBLAST= 160,			// �������� �Ա�
		MAGICSORT_THROWENEMY		= 161,			// Ͷ��
		MAGICSORT_THROWENEMYDOUBLE	= 162,			// Ͷ����������һ��
		MAGICSORT_MULTISELECTENEMY	= 163,			// ��Ŀ��ָ��
		MAGICSORT_CENTERINJURE		= 164,			// �����˺�
		MAGICSORT_ENSKILLMASTER		= 166,			// En���ļ���
		MAGICSORT_POISONRANGE		= 167,			// ����
		MAGICSORT_POISONRANGE_ADD	= 168,			// �������� ���ӷ�Χ
		MAGICSORT_POISONRANGE_POWER	= 169,			// �������� ���ӱ���
		MAGICSORT_POISONRANGE_DANGE	= 170,			// �������� ����
		MAGICSORT_ADJUSTTOGETHER	= 171,			// ����
		MAGICSORT_KILLLINEUP		= 172,			// ɱ��
		MAGICSORT_KILLLINEUP1		= 173,			// ɱ����1
		MAGICSORT_KILLLINEUP2		= 174,			// ɱ����2
		MAGICSORT_CRAZYFIGHTER		= 175,			// ��սʿ
		MAGICSORT_CRAZYFIGHTER_POWER= 176,			// ��սʿ�������� �桤��սʿ		
		MAGICSORT_CRAZYFIGHTER_TIME	= 177,			// ��սʿ�������� �ӳ�ʱ��
		MAGICSORT_CRAZYFIGHTER_HP	= 178,			// ��սʿ�������� Hp�ظ�
		MAGICSORT_CRAZYFIGHTER_TIME2= 179,			// ��սʿ�������� �ܻ��ӳ�ʱ��
		MAGICSORT_KILLLINEUP3		= 180,			// ɱ����3 ȫ�幥��
//		MAGICSORT_FLAMETHROWER		= 181,			// �������� �ƶ�����
		MAGICSORT_HOTBURN			= 182,			// ��������
		MAGICSORT_ICE				= 183,			// �䶳
		MAGICSORT_SHAKE				= 184,			// ��
		MAGICSORT_REPARE_XP			= 185,			// ά��XP����
		MAGICSORT_RETURNSTAR		= 186,			// ������ն
		MAGICSORT_SHOTGUN_XP		= 187,			// ����ǹXP tcp 2007-3-5 add
		
		MAGICSORT_CHAOS				= 188,			//���Ҽ���
		MAGICSORT_SINGLE_IMPACT		= 189,			//���˳������
		
		MAGICSORT_FULLSCREEN_ATK_BEGIN=190,			//ȫ����ը��sortֵΪ190��199
		MAGICSORT_FULLSCREEN_ATK_NORMAL	= MAGICSORT_FULLSCREEN_ATK_BEGIN,//��ͨȫ����ը����
		MAGICSORT_FULLSCREEN_ATK_HOT,				// ����ȫ����ը����
		MAGICSORT_FULLSCREEN_ATK_ICE,				// ����ȫ����ը����
		MAGICSORT_FULLSCREEN_ATK_SHAKE,				// ��ȫ����ը����
		MAGICSORT_FULLSCREEN_ATK_ICE_SHAKE,			// ����+��ȫ����ը
		MAGICSORT_FULLSCREEN_ATK_END=199,			// 
		MAGICSORT_RECOVERY          = 200,          //�����ӷ�
		
		MAGICSORT_INCEXP_DECATK		= 211,			// ����ֵ���ӡ��������½�״̬
		MAGICSORT_INCEXP_DECDEF		= 212,			// ����ֵ���ӡ������½�״̬
		MAGICSORT_BAITMONSTER		= 220,			// ���չ��＼��
		MAGICSORT_SUDDENMOVEATTACK	= 221,			// ˲�ƹ�������
		
//		MAGICSORT_CREATE_MAP_DOMAIN_START	= 222,	//������ͼ�����ܿ�ʼ
		MAGICSORT_CREATE_MAP_DOMAIN_END		= 224,	//������ͼ�����ܽ���
//		MAGICSORT_CREATE_REGION_DOMAIN_START = 225,	//�������������ܿ�ʼ
		
//		MAGICSORT_DOMAIN_DEC_DAMAGE			 = 226, //�������˺����ټ���
//		MAGICSORT_DOMAIN_HP					 = 227,//hp����

		MAGICSORT_CREATE_REGION_DOMAIN_END	 = 599,	//�������������ܽ���

		MAGICSORT_CONTROL_DOMAIN	= 229,			//�ٿ�������
		
		MAGICSORT_HOT_ATTACK		= 230,			// �������� tcp 2007-3-22 add
		MAGICSORT_COLD_ATTACK		= 231,			// �������� tcp 2007-3-22 add
		MAGICSORT_SAHKE_ATTACK		= 232,			// ������ tcp 2007-3-22 add		
		
		MAGICSORT_PK_BEATBACK		= 234,			// ����PK����-��ײ��ɼ���
		MAGICSORT_CONJURE_DEVIL     = 235,

		MAGICSORT_CURSE				= 251,			//������似��
		MAGICSORT_REINFORCE			= 252,			// Ԯ������

		MAGICSORT_HURT			    = 253,			// ��Ѫ���ܴ̻�����Ѫ��
		MAGICSORT_HEMO_LOP			= 254,			// ��Ѫ����Ѫն����Ѫ��
		MAGICSORT_Z_LOP			    = 255,			// ��Ѫ����Z��ն����Ѫ��
		MAGICSORT_HEMO_SHADOW		= 256,			// Ѫ��սʿ����-ѪӰ��
		MAGICSORT_CHARGE    		= 257,			// ��ʥ���
		MAGICSORT_CHGAMMO    		= 258,			// ����

		

		MAGICSORT_CALL_ALTAR		= 261,			//�ٻ���̳
		MAGICSORT_WORSHIP			= 262,			//�׼�
		MAGICSORT_CATCH				= 263,			//�׼�ץ��
		MAGICSORT_CATCH_WORSHIP		= 264,			//ץ���׼�

		MAGICSORT_DODGE				= 265,			//�����ܼ���

		MAGICSORT_FLY				= 270,			//���м���

		MAGICSORT_TEAM_IMPACT		= 280,			//��ӳ������
		//����ר��
		MAGICSORT_REVIVISCENCE		= 300,			// ����������ʱ����Ϊ��һ���������ר��  power��data�ֶηֱ���������ɵ����ֹ���ID����50%���ʣ�����0���ޣ���percent�ֶ���Ϊ�������������ĸ���
		MAGICSORT_TRANSFER			= 301,			// ����ʹ�øü���ʱ����ʹĿ����ұ��������ü����趨�õĵ�ͼ�������

		MAGICSORT_SANSTORM			= 310,			// ��ʥ�籩
		MAGICSORT_VELOCITY_SOUND	= 311,			// ���ٹ���
		MAGICSORT_SOUL_LIGHTNING	= 312,			// �������
		MAGICSORT_SAN_BEAT			= 313,			// ��ʥ���
		MAGICSORT_BLOOD_SHAKE		= 314,			// ��Ѫ���
		MAGICSORT_REVENAGE_SHIELD	= 315,			// ����֮��
		MAGICSORT_SAN_SHIELD_BEAT	= 316,			// ��ʥ�ܻ�
		MAGICSORT_GROUP_CURE		= 317,			//��������Ⱥ������
		MAGICSORT_SINGLE_CURE		= 318,			//����������������
		
		//ȫ��ͼȫԱ���˺�����
		MAGICSORT_DOMAIN_DEC_MAXHP    = 463,
		MAGICSORT_WHOLEMAP_DEC_DAMAGE = 468,

		MAGICSORT_DOMAIN_BEGIN		= 400,			//�����ܿ�ʼ
		MAGICSORT_DOMAIN_DEC_DAMAGE = 420,			//�������˺����ټ���
		MAGICSORT_DOMAIN_HP			= 421,			//hp����
		MAGICSORT_CREATE_MAP_DOMAIN_START = 422,	//�ܰ�
		MAGICSORT_CREATE_REGION_DOMAIN_START = 423, //
		MAGICSORT_REGION_FORBID_RESTORE_HP	 = 424, ////ȫԱ��ֹHP�ظ�������
		MAGICSORT_DOMAIN_WHOLEMAP_SYNDIACTE_HP = 425,//ȫ��ͼ����HP���
		MAGICSORT_DOMAIN_WHOLEMAP_TEAM_HP = 426, //ȫ��ͼ����HP���
        
		//
		//180
		//181
		MAGICSORT_DOMAIN_FIELD_NO_ENERGY_RECORY = 440,			//
		MAGICSORT_DOMAIN_FIELD_NO_HP_RECOVER,					// ����		��ֹHp�ظ�
		MAGICSORT_DOMAIN_FIELD_ADD_DAMAGE,						// ����		���˺�
		MAGICSORT_DOMAIN_MAP_TEAM_ADD_DAMAGE,					// ȫ��ͼ	������˺�
		MAGICSORT_DOMAIN_REGION_DAYTIME	= 480,			// ��������������

		MAGICSORT_DOMAIN_WHOLEMAP_FAMILY_INCDAMAGE = 500,    //ȫ��ͼ������˺�
        MAGICSORT_DOMAIN_FIELD_NO_MOVE ,				     //�����ֹ˲��
		MAGICSORT_DOMAIN_FIELD_DECDAMAGE ,				     //��������˺�
		MAGICSORT_DOMAIN_FIELD_NO_JUMP ,				     //�����ֹ��Ծ
		MAGICSORT_DOMAIN_WHOLEMAP_TEAMEXP ,				     //ȫ��ͼ���龭��ֵ
		MAGICSORT_DOMAIN_WHOLEMAP_FAMILYEXP ,				 //ȫ��ͼ���徭��ֵ
		MAGICSORT_DOMAIN_WHOLEMAP_TEAMINCDAMAGE ,		     //ȫ��ͼ������˺�
		MAGICSORT_DOMAIN_FIELD_INCDAMAGE ,		             //����ȫԱ���˺�
		MAGICSORT_DOMAIN_WHOLEMAP_SYNDECDAMAGE ,		    //ȫ��ͼ���ɳ�Ա���˺�
		MAGICSORT_DOMAIN_WHOLEMAP_FAMILYDECDAMAGE ,		    //ȫ��ͼ������˺�


		//�����ܣ�400 ~ 599��
		//MAGICSORT_REGION_DAMAGE					= 72,	//����������ΧȫԱ�˺����
		//MAGICSORT_REGION_BATTLEEFFECT				= 73,	//����-ս����������
		//MAGICSORT_REGION_BE_DAMAGE					= 74,	//����������ΧȫԱ���˺����
		MAGICSORT_REGION_ADD_HP					= 404,	//����������ΧȫԱHP���
		//MAGICSORT_REGION_ANTI_HOT					= 76,	//��������������¿���
		//MAGICSORT_REGION_ANTI_ICE					= 77,	//�������������������
		//MAGICSORT_REGION_ANTI_SHAKE				= 78,	//�������������𵴿���
		
		//MAGICSORT_REGION_FORBID_RESTORE_HP			= 79,	//ȫԱ��ֹHP�ظ�������
		//MAGICSORT_REGION_FORBID_RESTORE_POWER		= 80,   //ȫԱ��ֹ���ʻָ�������		
		MAGICSORT_REGION_FORBID_RESTORE_EN			= 406,	//ȫԱ��ֹ�ָ�EN����������
		//MAGICSORT_REGION_FORBID_RESTORE_THRUSTER   = 82,   //ȫԱ��ֹ�����ָ��������		
		//MAGICSORT_REGION_FORBID_RESTORE_DEF		= 83,	//ȫԱ��ֹ���ָܻ�������
		//MAGICSORT_REGION_FORBID_TRANS_POS			= 84,   //����-�����ֹ˲�ƽ��
		//MAGICSORT_REGION_FORBID_JUMP				= 87,	//����-����ȫԱ��ֹ��Ծ���		
		//MAGICSORT_REGION_RESTORE_XP_SPEED			= 92,   //����-����ΧȫԱXP�ָ��ٶȽ��	
		
		//MAGICSORT_ANTI_REGION_FORBID_JUMP				= 113,	//����-��������ȫԱ��ֹ��Ծ���	
		//MAGICSORT_ANTI_REGION_FORBID_RESTORE_HP		= 115,  //����������HP��ֹ�ظ�
		//MAGICSORT_ANTI_REGION_FORBID_RESTORE_EN		= 116,	//����-���ӽ�ֹ�ָ�EN������
		//MAGICSORT_ANTI_REGION_FORBID_RESTORE_POWER	    = 117,	//����-���ӽ�ֹ���ʻָ�������
		//MAGICSORT_ANTI_REGION_FORBID_RESTORE_THRUSTER  = 118,  //����-���ӽ�ֹ�����ָ�������		
		//MAGICSORT_ANTI_REGION_FORBID_RESTORE_DEF		= 119,	//����-���ӽ�ֹ���ָܻ�������	
		
		MAGICSORT_WHOLEMAP_ADD_EXP					= 401, //����-ȫ��ͼȫԱ����ֵ���
		MAGICSORT_WHOLEMAP_SYNDIACTE_ADD_EXP		= 402,  //����-ȫ��ͼ���Ӿ���ֵ���
		//MAGICSORT_WHOLEMAP_TEAM_ADD_EXP			= 102,  //����-ȫ��ͼ���龭��ֵ���
		//MAGICSORT_WHOLEMAP_FAMILY_ADD_EXP			= 103,	//����-ȫ��ͼ���徭��ֵ���
		
		//MAGICSORT_WHOLEMAP_HP						= 1Ui64 << 63;  //����-ȫ��ͼȫԱHP���
		//MAGICSORT_WHOLEMAP_SYNDIACTE_HP			= 161,  //����-ȫ��ͼ����HP���
		 MAGICSORT_DOMAIN_WHOLEMAP_FAMILY_HP		= 521,	//����-ȫ��ͼ����HP���
		//MAGICSORT_WHOLEMAP_TEAM_HP					= 163,  //����-ȫ��ͼ����HP���		
		MAGICSORT_DOMAIN_FIELD_ADD_DEAD_TIME		= 451,//����-������������ʱ��	
		MAGICSORT_WHOLEMAP_ADD_DAMAGE				= 403,	//������ȫ��ͼȫԱ���˺����
		MAGICSORT_WHOLEMAP_SYNDIACTE_ADD_DAMAGE		= 405,	//������ȫ��ͼ���Ӽ��˺����
		//MAGICSORT_WHOLEMAP_TEAM_ADD_DAMAGE			= 166,	//������ȫ��ͼ������˺����
		//MAGICSORT_WHOLEMAP_FAMILY_ADD_DAMAGE		= 167,	//������ȫ��ͼ������˺����
		//MAGICSORT_WHOLEMAP_DEC_DAMAGE				= 168,	//������ȫ��ͼȫԱ���˺����
		//MAGICSORT_WHOLEMAP_SYNDIACTE_DEC_DAMAGE	= 169,	//������ȫ��ͼ���Ӽ��˺����
		//MAGICSORT_WHOLEMAP_TEAM_DEC_DAMAGE			= 170,	//������ȫ��ͼ������˺����
		//MAGICSORT_WHOLEMAP_FAMILY_DEC_DAMAGE		= 171,	//������ȫ��ͼ������˺����
		
		//MAGICSORT_WHOLEMAP_ANTI_HOT				= 172,	//����-ȫ��ͼȫԱ���¿��Խ��		
		//MAGICSORT_WHOLEMAP_SYNDIACTE_ANTI_HOT		= 173,	//����-ȫ��ͼ���ɸ��¿��Խ��				
		//MAGICSORT_WHOLEMAP_TEAM_ANTI_HOT			= 174,	//����-ȫ��ͼ������¿��Խ��		
		//MAGICSORT_WHOLEMAP_FAMILY_ANTI_HOT			= 175,	//����-ȫ��ͼ������¿��Խ��		
		
		//MAGICSORT_WHOLEMAP_ANTI_ICE				= 176,	//����-ȫ��ͼȫԱ�������Խ��		
		//MAGICSORT_WHOLEMAP_SYNDIACTE_ANTI_ICE		= 177,	//����-ȫ��ͼ���ɱ������Խ��				
		//MAGICSORT_WHOLEMAP_TEAM_ANTI_ICE			= 178,	//����-ȫ��ͼ����������Խ��		
		
		//MAGICSORT_WHOLEMAP_ANTI_SHAKE				= 180,	//����-ȫ��ͼȫԱ�𵴿��Խ��				
		//MAGICSORT_WHOLEMAP_SYNDIACTE_ANTI_SHAKE	= 181,	//����-ȫ��ͼ�����𵴿��Խ��		
		//MAGICSORT_WHOLEMAP_TEAM_ANTI_SHAKE			= 182,	//����-ȫ��ͼ�����𵴿��Խ��
		//MAGICSORT_WHOLEMAP_FAMILY_ANTI_SHAKE		= 183,	//����-ȫ��ͼ�����𵴿��Խ��
		MAGICSORT_DOMAIN_END		= 600,			//

		MAGICSORT_SHADOWMBOMB						= 611,	//��Ӱը��
		MAGICSORT_WHIRLWIND							= 612,	//����ն
		MAGICSORT_CHGMAGAZINE						= 613,	//���滻��
		MAGICSORT_AIMSHOOT							= 614,	//��׼���
		MAGICSORT_SHADOWMISSILE						= 615,	//��Ӱ�ɵ�
		MAGICSORT_EXPLODE_FIREBALL					= 616,	//���ѻ���
		MAGICSORT_BLOOD_LOP							= 617,	//Ѫ��ն����Ѫ��
		MAGICSORT_THREETIMES_LOP					= 618,	//����ն����Ѫ��
		MAGICSORT_RANDSWORD_ASSAULT					= 619,  //����ͻ��
		MAGICSORT_ICE_BALL							= 620,	//������
		MAGICSORT_THROWOBJ							= 621,	//Ͷ����Ʒ
		MAGICSORT_INSPIRER_ADDMONEY					= 622,	//���������ӽ�һ�ȡ
		MAGICSORT_INSPIRER_ADDDAMAG					= 623,	//�����������˺�Ч��
		MAGICSORT_INSPIRER_DECATTACK				= 624,  //�����߽��͹���Ч��
		MAGICSORT_INSPIRER_ADDEXP					= 625,	//���������Ӿ����ȡ
		MAGICSORT_INSPIRER_REMOVE_BADSTATE			= 626,	//�����߽������״̬
		MAGICSORT_HEALER_PALA_GROUP_CURE			= 627,	//������ʿȺ������
		MAGICSORT_HEALER_PALA_SINGLE_CURE			= 628,	//������ʿ��������
		MAGICSORT_HEALER_MAGE_SINGLE_CURE			= 629,	//Ѫ�巨ʦ��������
		MAGICSORT_HEALER_MAGE_GROUP_CURE			= 630,	//Ѫ�巨ʦȺ������
		MAGICSORT_HEALER_MAGE_STEAL_LIFE			= 631,	//Ѫ�巨ʦ͵ȡ����
		MAGICSORT_TEAM_SIGNROLE						= 632,	//�ӳ���ǹ��＼��
		MAGICSORT_TRANSFORM_BEGIN = 10000,			// ���μ��ܿ�ʼ���
};

enum MAGICTYPE
{
	
	MAGICTYPE_GROUP_CURE						= 317,			//��������Ⱥ������
	MAGICTYPE_SINGLE_CURE						= 318,			//����������������	
	MAGICTYPE_INSPIRER_ADDMONEY					= 622,	//���������ӽ�һ�ȡ
	MAGICTYPE_INSPIRER_ADDDAMAG					= 623,	//�����������˺�Ч��
	MAGICTYPE_INSPIRER_DECATTACK				= 624,  //�����߽��͹���Ч��
	MAGICTYPE_INSPIRER_ADDEXP					= 625,	//���������Ӿ����ȡ
	MAGICTYPE_INSPIRER_REMOVE_BADSTATE			= 626,	//�����߽������״̬
	MAGICTYPE_HEALER_PALA_GROUP_CURE			= 627,	//������ʿȺ������
	MAGICTYPE_HEALER_PALA_SINGLE_CURE			= 628,	//������ʿ��������
	MAGICTYPE_HEALER_MAGE_SINGLE_CURE			= 629,	//Ѫ�巨ʦ��������
	MAGICTYPE_HEALER_MAGE_GROUP_CURE			= 630,	//Ѫ�巨ʦȺ������
	MAGICTYPE_HEALER_MAGE_STEAL_LIFE			= 631,	//Ѫ�巨ʦ͵ȡ����
	MAGICTYPE_CHGMAGAZINE						= 1103,	//���滻��
	MAGICTYPE_TEAM_SIGNROLE						= 6320,	//�ӳ���ǹ��＼��
};

enum { ADJUST_HOT, ADJUST_SHAKE, ADJUST_STING, ADJUST_DECAY };
enum { SPIRITSORT_NONE=0, SPIRITSORT_FIGHTER, SPIRITSORT_GUNNER, SPIRITSORT_ENERGY, SPIRIT_ASSISTANT };

enum{
		MAGICEFFECTEX_FREEZING			= 0x01,	//��������
		MAGICEFFECTEX_BURNING			= 0x02,	//���ձ���
		MAGICEFFECTEX_FIRSTATTACK		= 0x04, //��һ�ι���(����)
};

////////////////////����ר����Դ�ĵ������2007-1-9 tcp add/////////////////////////////
enum DROP_STONE_RULE_DATA
{
	DROP_STONE_RULE_DATA_ID					,
	DROP_STONE_RULE_DATA_TIME_COE			,
	DROP_STONE_RULE_DATA_STARLV_COE			,
	DROP_STONE_RULE_DATA_WEAPON_COE			,
	DROP_STONE_RULE_DATA_MAGIC_COE			,
	DROP_STONE_RULE_DATA_SPIRITTYPE_COE		,
	DROP_STONE_RULE_DATA_GREENNAME_COE		,
	DROP_STONE_RULE_DATA_REDNAME_COE		,	
	DROP_STONE_RULE_DATA_BLACKNAME_COE		,
	DROP_STONE_RULE_DATA_DROP_STONE0_CHANCE ,
	DROP_STONE_RULE_DATA_DROP_STONE0_MIN	,
	DROP_STONE_RULE_DATA_DROP_STONE0_MAX	,
	DROP_STONE_RULE_DATA_DROP_STONE1_CHANCE ,
	DROP_STONE_RULE_DATA_DROP_STONE1_MIN	,
	DROP_STONE_RULE_DATA_DROP_STONE1_MAX	,
	DROP_STONE_RULE_DATA_DROP_STONE2_CHANCE ,
	DROP_STONE_RULE_DATA_DROP_STONE2_MIN	,
	DROP_STONE_RULE_DATA_DROP_STONE2_MAX	,	
};

enum NEWDROPRULEDATA
{
	NEWDROPRULEDATA_ID = 0,
	NEWDROPRULEDATA_TYPE ,
	NEWDROPRULEDATA_CHANCE,
	NEWDROPRULEDATA_ITEMTYPE_ID,
	NEWDROPRULEDATA_QUALITY0,
	NEWDROPRULEDATA_QUALITY1,
	NEWDROPRULEDATA_QUALITY2,
	NEWDROPRULEDATA_QUALITY3,
	NEWDROPRULEDATA_QUALITY4,
	NEWDROPRULEDATA_QUALITY5,
	NEWDROPRULEDATA_QUALITY6,
	NEWDROPRULEDATA_QUALITY7,
	NEWDROPRULEDATA_QUALITY8,
	NEWDROPRULEDATA_QUALITY9,
	NEWDROPRULEDATA_GEM_NOTHING,
	NEWDROPRULEDATA_GEM,
	NEWDROPRULEDATA_ADDITION_NOTHING,
	NEWDROPRULEDATA_ADDITION,
	NEWDROPRULEDATA_IDENTYFY_NOTHING,	
	NEWDROPRULEDATA_IDENTYFY,
	NEWDROPRULEDATA_DROP_ITEM_RULE,
};

////////////////////////////////////////////////////////////////
enum {	RACE_NONE	= 0,
		RACE_EARTH	= 1,		// �����
		RACE_SPACE	= 2,		// �����
		RACE_DUAL	= 3			// ˫�ع���
};




enum ADDPOINTDATA
{
		ADDPOINTDATA_ID,
		ADDPOINTDATA_PROF,
		ADDPOINTDATA_LEVEL,
		ADDPOINTDATA_LIFE_INC,
		ADDPOINTDATA_MANA_INC,
		ADDPOINTDATA_MANA_RE_INC,
		ADDPOINTDATA_STA_INC,
		ADDPOINTDATA_ATK_SHORT_INC,
		ADDPOINTDATA_ATK_LONG_INC,
		ADDPOINTDATA_DEF_SHORT_INC,
		ADDPOINTDATA_DEF_LONG_INC,
		ADDPOINTDATA_ATTR_POINT_INC,         // ��ҵȼ����Ե��� �������2/5 �� user_attribute_type ����
		ADDPOINTDATA_DODGE_INC,              // ��ҵȼ���ʼ����ֵ
};


enum {
		PKMODE_TEAMMENBER			=	0x00000001,
		PKMODE_SYNDICATEMENBER		=	0x00000002,
		PKMODE_FRIEND				=	0x00000004,
		PKMODE_ENEMY				=	0x00000008,		
		PKMODE_CRIMINAL				=	0x00000010,
		PKMODE_REDNAME				=	0x00000020,
		PKMODE_BLACKNAME			=	0x00000040,
		PKMODE_MATE					=	0x00000080,
		PKMODE_WHITENAME			=	0x00000100,				
		PKMODE_NEWGUY				=   0x00000200,
		PKMODE_PURPLENAME			=	0x00000400,
		PKMODE_SYNWAR_SIDE			=	0x00001000,
		PKMODE_SAFE_NEW             =   0x00002000,
		PKMODE_ADVANCED				=	0x80000000,		
};

//pk�ļ���Ĭ��ģʽ
enum{

		PKMODE_SAFE	= 			PKMODE_SAFE_NEW, 
		PKMODE_PEACE =          PKMODE_ADVANCED,

		PKMODE_TEAM	=			PKMODE_TEAMMENBER
								|PKMODE_MATE
								|PKMODE_SYNDICATEMENBER
								|PKMODE_FRIEND,
							

		PKMODE_SYNDICATE =		PKMODE_SYNDICATEMENBER,

		PKMODE_ARRESTMENT =		PKMODE_ADVANCED
								|PKMODE_CRIMINAL
								|PKMODE_REDNAME
								|PKMODE_BLACKNAME
								|PKMODE_PURPLENAME
								,
		PKMODE_SYNWAR	=		PKMODE_SYNWAR_SIDE,

		PKMODE_FREE = 0,
};

enum TRANSFORM_TYPE
{
	SPIRITFORM_NONE,	
	SPIRITFORM_CHARIOT		= 1,	//ս��
	SPIRITFORM_HUMMER		= 2,	//����
	SPIRITFORM_BATTLEPLANE	= 3,	//ս����
	SPIRITFORM_WHIRLYBIRD	= 4,	//ֱ����
	SPIRITFORM_HUGECANNON	= 5,	//���� 
	SPIRITFORM_DINOSAUR		= 6,	//����
	SPIRITFORM_RAPTORIAL		= 7,	//����
	SPIRITFORM_INSECT		= 8,	//����
};

enum
{
	MAGICSORT_ROBOTFORM_CHARIOT0	= 10100,
	MAGICSORT_ROBOTFORM_CHARIOT1,
	MAGICSORT_ROBOTFORM_CHARIOT2,
	MAGICSORT_ROBOTFORM_CHARIOT3,
	MAGICSORT_ROBOTFORM_CHARIOT4,
	MAGICSORT_ROBOTFORM_CHARIOT5,
	MAGICSORT_ROBOTFORM_CHARIOT6,
	MAGICSORT_ROBOTFORM_CHARIOT7,
	MAGICSORT_ROBOTFORM_CHARIOT8,
	MAGICSORT_ROBOTFORM_CHARIOT9,

	MAGICSORT_TRANSFORM_HUMMER0		= 10200,
	MAGICSORT_TRANSFORM_HUMMER1,
	MAGICSORT_TRANSFORM_HUMMER2,
	MAGICSORT_TRANSFORM_HUMMER3,
	MAGICSORT_TRANSFORM_HUMMER4,
	MAGICSORT_TRANSFORM_HUMMER5,
	MAGICSORT_TRANSFORM_HUMMER6,
	MAGICSORT_TRANSFORM_HUMMER7,
	MAGICSORT_TRANSFORM_HUMMER8,
	MAGICSORT_TRANSFORM_HUMMER9,

	MAGICSORT_TRANSFORM_BATTLEPLANE0		= 10300,
	MAGICSORT_TRANSFORM_BATTLEPLANE1,
	MAGICSORT_TRANSFORM_BATTLEPLANE2,
	MAGICSORT_TRANSFORM_BATTLEPLANE3,
	MAGICSORT_TRANSFORM_BATTLEPLANE4,
	MAGICSORT_TRANSFORM_BATTLEPLANE5,
	MAGICSORT_TRANSFORM_BATTLEPLANE6,
	MAGICSORT_TRANSFORM_BATTLEPLANE7,
	MAGICSORT_TRANSFORM_BATTLEPLANE8,
	MAGICSORT_TRANSFORM_BATTLEPLANE9,

	MAGICSORT_TRANSFORM_WHIRLYBIRD0		= 10400,
	MAGICSORT_TRANSFORM_WHIRLYBIRD1,
	MAGICSORT_TRANSFORM_WHIRLYBIRD2,
	MAGICSORT_TRANSFORM_WHIRLYBIRD3,
	MAGICSORT_TRANSFORM_WHIRLYBIRD4,
	MAGICSORT_TRANSFORM_WHIRLYBIRD5,
	MAGICSORT_TRANSFORM_WHIRLYBIRD6,
	MAGICSORT_TRANSFORM_WHIRLYBIRD7,
	MAGICSORT_TRANSFORM_WHIRLYBIRD8,
	MAGICSORT_TRANSFORM_WHIRLYBIRD9,

	MAGICSORT_TRANSFORM_HUGECANNON0		= 10500,
	MAGICSORT_TRANSFORM_HUGECANNON1,
	MAGICSORT_TRANSFORM_HUGECANNON2,
	MAGICSORT_TRANSFORM_HUGECANNON3,
	MAGICSORT_TRANSFORM_HUGECANNON4,
	MAGICSORT_TRANSFORM_HUGECANNON5,
	MAGICSORT_TRANSFORM_HUGECANNON6,
	MAGICSORT_TRANSFORM_HUGECANNON7,
	MAGICSORT_TRANSFORM_HUGECANNON8,
	MAGICSORT_TRANSFORM_HUGECANNON9,

	MAGICSORT_TRANSFORM_DINOSAUR0	= 10600,
	MAGICSORT_TRANSFORM_DINOSAUR1,
	MAGICSORT_TRANSFORM_DINOSAUR2,
	MAGICSORT_TRANSFORM_DINOSAUR3,
	MAGICSORT_TRANSFORM_DINOSAUR4,
	MAGICSORT_TRANSFORM_DINOSAUR5,
	MAGICSORT_TRANSFORM_DINOSAUR6,
	MAGICSORT_TRANSFORM_DINOSAUR7,
	MAGICSORT_TRANSFORM_DINOSAUR8,
	MAGICSORT_TRANSFORM_DINOSAUR9,

	MAGICSORT_TRANSFORM_RAPTORIAL0	= 10700,
	MAGICSORT_TRANSFORM_RAPTORIAL1,
	MAGICSORT_TRANSFORM_RAPTORIAL2,
	MAGICSORT_TRANSFORM_RAPTORIAL3,
	MAGICSORT_TRANSFORM_RAPTORIAL4,
	MAGICSORT_TRANSFORM_RAPTORIAL5,
	MAGICSORT_TRANSFORM_RAPTORIAL6,
	MAGICSORT_TRANSFORM_RAPTORIAL7,
	MAGICSORT_TRANSFORM_RAPTORIAL8,
	MAGICSORT_TRANSFORM_RAPTORIAL9,

	MAGICSORT_TRANSFORM_INSECT0	= 10800,
	MAGICSORT_TRANSFORM_INSECT1,
	MAGICSORT_TRANSFORM_INSECT2,
	MAGICSORT_TRANSFORM_INSECT3,
	MAGICSORT_TRANSFORM_INSECT4,
	MAGICSORT_TRANSFORM_INSECT5,
	MAGICSORT_TRANSFORM_INSECT6,
	MAGICSORT_TRANSFORM_INSECT7,
	MAGICSORT_TRANSFORM_INSECT8,
	MAGICSORT_TRANSFORM_INSECT9,
};


enum TRANSFORM_STATUS
{
	TRANSFORM_STATUS_STOP,		// ��ͣ״̬
	TRANSFORM_STATUS_ADD,		// ����״̬
	TRANSFORM_STATUS_WAIT,		// ��ֵ״̬(�ȴ�����)
	TRANSFORM_STATUS_FIRE,		// ����״̬(�Ѿ��ڱ�������)
};


enum GLOBALVARIABLE_DATA
{
	GLOBALVARIABLE_DATA_ID,
	GLOBALVARIABLE_DATA_TYPE,
	GLOBALVARIABLE_DATA_DATA1,
	GLOBALVARIABLE_DATA_DATA2,
	GLOBALVARIABLE_DATA_DATA3,
	GLOBALVARIABLE_DATA_DATA4,
	GLOBALVARIABLE_DATA_DATA5,
	GLOBALVARIABLE_DATA_DESCRIPTION,
};

enum NEWBIEBORNMAPDATA
{
	NEWBIEBORNMAPDATA_ID,
	NEWBIEBORNMAPDATA_PROVINCEID,
	NEWBIEBORNMAPDATA_MAPID,
	NEWBIEBORNMAPDATA_POSX,
	NEWBIEBORNMAPDATA_POSY,
};

enum SHAPEDATA
{
		SHAPEDATA_ID,
		SHAPEDATA_CX,
		SHAPEDATA_CY,
		SHAPEDATA_Line0,
		SHAPEDATA_Line1,
		SHAPEDATA_Line2,
		SHAPEDATA_Line3,
		SHAPEDATA_Line4,
		SHAPEDATA_Line5,
		SHAPEDATA_Line6,
		SHAPEDATA_Line7,
		SHAPEDATA_Line8,
		SHAPEDATA_Line9,
		SHAPEDATA_Artifact,
};

enum FAMILYDATA
{
	FAMILYDATA_ID		= 0,			// ������INSERT
	FAMILYDATA_NAME		= 1,
	FAMILYDATA_RANK,					// ����ȼ���Ĭ��Ϊ0��rank =0��ʾ1����rank=1��ʾ2��
	FAMILYDATA_SHAIKHNAME,
	FAMILYDATA_SHAIKHID,
	FAMILYDATA_ANNOUNCE,				// ���幫����Ϣ��Ĭ��Ϊ��
	FAMILYDATA_MONEY,					// �����ʽ�
	FAMILYDATA_REPUTE,					// ��������
	FAMILYDATA_AMOUNT,					// ��ǰ����
	FAMILYDATA_ENEMY0,
	FAMILYDATA_ENEMY1,
	FAMILYDATA_ENEMY2,
	FAMILYDATA_ENEMY3,
	FAMILYDATA_ENEMY4,
	FAMILYDATA_ALLY0,
	FAMILYDATA_ALLY1,
	FAMILYDATA_ALLY2,
	FAMILYDATA_ALLY3,
	FAMILYDATA_ALLY4,
	FAMILYDATA_CREATEDATE,				// ����ʱ��
	FAMILYDATA_CREATENAME,				// ���崴ʼ����
	FAMILYDATA_STARTOWER,				// 2006.11.22 ���彨��ϵͳAdd, ����ս�������ľ���ȼ�
	FAMILYDATA_MAPID,					// 2006.11.25 ���彨��ϵͳAdd, �����ͼID
	FAMILYDATA_DELFLAG,					// ɾ����־
	FAMILYDATA_CHALLENGE,				// ��¼�ü��嵱ǰ��ս�ļ���NPC_id
	FAMILYDATA_OCCUPY,					// ��¼�ü��嵱ǰռ��ļ���NPC_id
	FAMILYDATA_TRUCE,					// ��ǰ����ս״̬ 0��δʹ����ս���� 1�����ڵ�һ����ս״̬ 2��ʹ�õ�һ����ս״̬�� 3�����ڵڶ�����ս״̬ 4��ʹ�õڶ�����ս״̬��
};

enum FAMILYATTRDATA
{
	FAMILYATTRDATA_USERID	= 0,						// ���ID
	FAMILYATTRDATA_FAMILYID	= 1,
	FAMILYATTRDATA_RANK,
	FAMILYATTRDATA_PROFFER,
	FAMILYATTRDATA_JOINDATE,							// ���ʱ��20051215
	FAMILYATTRDATA_AUTOEXE,
	FAMILYATTRDATA_EXP_DATE,
	FAMILYATTRDATA_LASTLOGOUT
};

enum FAMILYFIGHTPRIZEDATA
{
		FAMILYFIGHTPRIZEDATA_PRIZEID = 0,	//ID(�峤����)
		FAMILYFIGHTPRIZEDATA_PRIZELEVEL	= 1,	//��������				
		FAMILYFIGHTPRIZEDATA_WEEKS,				//ռ������
		FAMILYFIGHTPRIZEDATA_ATTRIB,			//���Խ���
		FAMILYFIGHTPRIZEDATA_EXPBALL,			//��������
		FAMILYFIGHTPRIZEDATA_MAN_ITEM1,			//���ཱ����Ʒ1			
		FAMILYFIGHTPRIZEDATA_MAN_ITEM2,			//���ཱ����Ʒ2
		FAMILYFIGHTPRIZEDATA_MAN_ITEM3,			//���ཱ����Ʒ3	
		FAMILYFIGHTPRIZEDATA_VMP_ITEM1,			//��Ѫ������Ʒ1
		FAMILYFIGHTPRIZEDATA_VMP_ITEM2,			//��Ѫ������Ʒ2
		FAMILYFIGHTPRIZEDATA_VMP_ITEM3			//��Ѫ������Ʒ3
};

enum BusinessAccountSetType
{
	BUSINESSACCOUNT_UNDEFINED_SETTYPE	= -1,
	BUSINESSACCOUNT_CANCEL			= 0,	//�������˺ţ����ܸ��Ĵ�ֵ
	BUSINESSACCOUNT_CANCEL_APPLY	= 1,	//�����������˺�
	BUSINESSACCOUNT_APPLY			= 2,	//�������˺�
	BUSINESSACCOUNT_APPLY_FIRST		= 3,	//�״��������˺�
	BUSINESSACCOUNT_APPLY_EFFECT	= 4,		//��¼ʱ��⵽���˺�������Ч
	
	BUSINESSACCOUNT_APPLY_EFFECT_ON_MIDNIGHT = 5,		//��ҹ������������⵽���˺�������Ч
	BUSINESSACCOUNT_APPLY_EFFECT_ON_LOGIN = 6   		//���������������⵽���˺�������Ч
		
};

enum PEERAGE_LEVEL
{
	PEERAGE_LEVEL_MIN = 0,
	PEERAGE_LEVEL0 = PEERAGE_LEVEL_MIN,	//ƽ��
	PEERAGE_LEVEL1 = 1,	//�о�
	PEERAGE_LEVEL2 = 2,	//�Ӿ�
	PEERAGE_LEVEL3 = 3,	//����
	PEERAGE_LEVEL4 = 4,	//���
	PEERAGE_LEVEL5 = 5,	//����
	PEERAGE_LEVEL6 = 6,	//��
	
	PEERAGE_LEVEL_MAX = PEERAGE_LEVEL6
};

enum STEP_TYPE
{ 
	STEP_NONE=0, 
	STEP_LOGIN, 
	STEP_ENTERMAP, 
	STEP_INIT_ITEM, 
	STEP_INIT_FRIEND, 
	STEP_INIT_SKILL, 
	STEP_INIT_MAGIC, 
	STEP_INIT_SYNATTR, 
	STEP_INIT_CONTRACT, 
	STEP_INIT_RESEARCH, 
	STEP_SIZE 
};

enum CHEAT_TYPE
{ 
	_TYPE_MAGIC=0, 
	_TYPE_WS=1, 
	_TYPE_FY=2, 
	_TYPE_USE_LIFE=3, 
	_TYPE_USE_MANA=4, 
}; // ��˫// ����	// �ú�ҩ// ����ҩ

enum LEVUPEXPDATA
{
		LEVUPEXPDATA_LEVEL = 0,
		LEVUPEXPDATA_EXP,
		//LEVUPEXPDATA_POINT,
		//LEVUPEXPDATA_TEAM_EXP_LIMIT,
		LEVUPEXPDATA_PERATK,
		LEVUPEXPDATA_OVERADJATK,
		LEVUPEXPDATA_PERXP,
		LEVUPEXPDATA_OVERADJXP,
		LEVUPEXPDATA_PERXPTEAM,
		LEVUPEXPDATA_OVERADJXPTEAM,
		LEVUPEXPDATA_KILLBONUS,
		LEVUPEXPDATA_OVERADJKILLBONUS,
		LEVUPEXPDATA_METEMPSYCHOSIS,
		LEVUPEXPDATA_UPLEVTIME,
		LEVUPEXPDATA_EXPBALLMAX,
		LEVUPEXPDATA_TYPE,		// 2006.06.04 ��ʦ����(type=0) ���徭��(type=1��type=2��)��ע���������Ƴ��������鲻ͬ�Ķ��ֻ��壩
		LEVUPEXPDATA_FINALEXP,
		LEVUPEXPDATA_OVERADJFINAL,
		LEVUPEXPDATA_BASELIFE,
		LEVUPEXPDATA_KILLMONSTER,  //�û�����ʥ����ID��8180����Ǭ������ID��8181�������������ɱ������
};

enum SYNATTRDATA
{
	SYNATTRDATA_BEGIN = 0,
	SYNATTRDATA_USERID	= 0,		     // ���ID
	SYNATTRDATA_SYNID	= 1,
	SYNATTRDATA_RANK,
	SYNATTRDATA_PROFFER,
	SYNATTRDATA_DAYS,				// ���ʱ��20051215
	SYNATTRDATA_END = SYNATTRDATA_DAYS
};

enum	TRANS_ADJUST_DATA
{
	TRANS_ADJUST_Exp,								//����
	TRANS_ADJUST_Def,								//����,ս��,����,ս����,����
	//	TRANS_ADJUST_SpendPower_Attack,					//����
	TRANS_ADJUST_Power_Jump,						//����,����,����
	TRANS_ADJUST_MaxPower,							//����
	TRANS_ADJUST_Power_Recover,						//����
	TRANS_ADJUST_ShakeDef,							//����,ս��,����,����,ս����,����
	TRANS_ADJUST_HotDef,							//ս��,����,ս����,ֱ���ɻ�,����
	TRANS_ADJUST_ColdDef,							//ս��,����,����,ս����,ֱ���ɻ�,����
	//	TRANS_ADJUST_SpendAmmo,							//����
	TRANS_ADJUST_BeAttackByNearWar_Dec_Damage,		//ս��
	TRANS_ADJUST_MaxLife,							//����
	TRANS_ADJUST_MaxLife_Percent,					//ս��,����
	TRANS_ADJUST_BattleEffect,						//ս��,ս����
	TRANS_ADJUST_AttackDestroyObj_Add_Damage,		//ս��,����,ս����
	TRANS_ADJUST_AttackFarWar_Add_Atk,				//ս��
	TRANS_ADJUST_AttackHummer_Add_Damage,			//ս��
	TRANS_ADJUST_Df,								//ս��
	TRANS_ADJUST_AttackEmplacement_Add_Atk,			//����
	TRANS_ADJUST_Additional_Damage,					//����
	TRANS_ADJUST_BeAttackByMachineGun_Dec_Damage,	//����
	TRANS_ADJUST_AttackNearWar_Add_Damage,			//����
	TRANS_ADJUST_AttackHugeCannon_Add_Damage,		//����
	TRANS_ASSIT_SKILL_ID,							//����,����,ս����
	TRANS_ATTACK_PERCENT,							//����,����,����
	TRANS_ATTACK_POWER_PERCENT,						//����,����
	TRANS_BATTALEEFFECT_DEC_TIME,					//����,ֱ���ɻ�
	TRANS_ADJUST_Dec_def_Add_Atk,					//����
	TRANS_NEED_TIME,								//����,����,����
	TRANS_ATTACK_POWER_VALUE,						//����,����
	TRANS_DISABLE_TRUMP_REGION,						//����
	TRANS_BATTLEEFFECT_CONDITION,					//����,����,ֱ���ɻ�
	TRANS_HP_Revert_Percent,						//����
	TRANS_ADJUST_Df_Revert,							//����
	TRANS_Generator_Be_Attack_Revert_Time,			//����
	TRANS_ADJUST_AttackBattleplane_Add_Atk,			//����,ս����
	TRANS_ADJUST_AttackWhirlybird_Add_Atk,			//����
	TRANS_Attack_TargetUser_Make_Lost_HP,			//����
	TRANS_ADJUST_MOVESPEED,							//ս����
	TRANS_ADJUST_Max_Flytime,						//ս����
	TRANS_ADJUST_Spend_Flytime_PerSec,				//ս����
	TRANS_ADJUST_RevertSpeed_Flytime,				//ս����
	TRANS_Attach_BattleEffect_Status,				//ս����,ֱ���ɻ�
	TRANS_ADJUST_AttackChariot_Add_Damage,			//ս����
	TRANS_ADJUST_FloatCannon_Add_Atk,				//ս����
	TRRANS_Attach_ElectronGlitch_Status,			//ս����
	TRANS_BE_ATTACK_Damage_Revert_HP,				//ս����
	TRANS_ADJUST_Add_Dodge,							//ֱ���ɻ�
	TRANS_Generator_Be_Attack_Dec_Damage,			//ֱ���ɻ�
	TRANS_ADJUST_Dec_Radiation,						//ֱ���ɻ�
			
			
	TRANS_ADJUST_TOTAL_ATK_ADJ,
	TRANS_ADJUST_TOTAL_DEF_ADJ,
	TRANS_ADJUST_TOTAL_BEATTACK_DAMAGE_ADJ,				//
	TRANS_ADJUST_TOTAL_ATTACK_DAMAGE_ADJ,				//
};

enum CHECKCASE
{
	CHECKCASE_CREATENAME,		// ���������ʱ�ķǷ��ַ������ַ���
};

enum GuardEvent
{
	GUARD_EVENT_BEGIN = 0,
	STONE_USE =  GUARD_EVENT_BEGIN,
	EXPBALL_USE,	
	COMPOSE_TIMES,	//��������
	GUARD_ENENT_END,
};

enum CHECK_ENUM 
{ 
	CHECK_FALSE = false, 
	CHECK_TRUE = true 
};


enum FRIEND_SHARED_TYPE
{
    _SHARE_AUTOEXERCIZE,
	_SHARE_EXPBALLUSE,
	_SHARE_OTHER,
};

enum 
{	
	ITEMINFO_NONE=0, 
	ITEMINFO_ADDITEM,				// �����Ʒ
	ITEMINFO_TRADE,					// ��ƽ���׶Է���ӵ���Ʒ
	ITEMINFO_UPDATE,				// update item info
	ITEMINFO_OTHERPLAYER_EQUIPMENT, // �����������װ��// id is user id
	ITEMINFO_QUERY_STORAGE,			// ����ֿ�
	ITEMINFO_UPGRADE,				// TC����ITEMINFO_UPDATE�÷�һ������������ʱ���������/TS���ͻ��˵�����������ݺ��ϴ���֤
	ITEMINFO_BOOTH,					// for booth
	ITEMINFO_EQUIPMENT,				// equipment update
	ITEMINFO_OTHERPLAYER_USER_EQUIPMENT,//to client
	ITEMINFO_OTHERPLAYER_ROBOTBLUEPRINT_EQUIPMENT, //to client OwnerIDΪ�������ͼ��id ��ѯ���˻������ͼ���������Ϣ		
	ITEMINFO_ROBOT_OUTER,			//to client OwnerIDΪ���ɿ�����װ������Ϣ 
	ITEMINFO_OTHERPLAYER_QUERY_CHAT_ITEMINFO,//to client only ������Ҳ�ѯ������Ʒ��Ϣ
	ITEMINFO_QUERY_VIRTUALSPACE,	//to client ��ѯ��չ����Ʒ��Ϣ
	ITEMINFO_QUERY_VIP_STORAGE,		//to client ��ѯVIP�ֿ���Ϣ
	
	ITEMINFO_TRUMP_PREVIEW=30,		// ������ϢԤ��
	
	ITEMINFO_CONTROL_CENTER=40,		//����������Ʒ
	ITEMINFO_BOOTH_REMOTE,          //����Զ����Ʒ��Ϣ

	ITEMINFO_WAITSTATE_BOND = 45,   //�������е�װ����Ϣ	
};
enum E_VIPREBORN_TYPE
{
	NONE_REBORN = 0 ,
	VIP_STAND_REBORN,
    VIP_RAND_REBORN,
	NORMAL_REBORN,
};

enum{
		MSGPACKAGE_QUERYLIST			= 0,
		MSGPACKAGE_CHECKIN				= 1,
		MSGPACKAGE_CHECKOUT				= 2,
		MSGPACKAGE_SPLITITEM				= 3,	// to server, data: num
		MSGPACKAGE_COMBINEITEM				= 4,	// to server, data: id
		MSGPACKAGE_MOVEPOS			= 5,			// to client / to server  // ��ͬһ��������Ų����Ʒ��λ��
		MSGPACKAGE_QUERY_VIPDEPOT_ITEM		= 6,	// to client / to server  // ��ѯVIP�ֿ����Ƿ�����Ʒ

};

enum WANTEDDATA
{
	DATA_ID	= 0, 
	DATA_TARGET_NAME,
	DATA_TARGET_LEV,
	DATA_TARGET_PRO,
	DATA_TARGET_SYN,
	DATA_PAYER,
	DATA_BOUNTY,
	DATA_ORDER_TIME,
	DATA_HUNTER,
	DATA_FINISH_TIME,
};

enum BUSINESSDATA
{
	BUSINESSDATA_ID,
	BUSINESSDATA_USER_ID,
	BUSINESSDATA_BUSINESS_ID,
	BUSINESSDATA_NAME,
	BUSINESSDATA_DATE
};

enum EXPBALL_USETYPE
{
	EXPBALL_EAT,
	EXPBALL_STORE
};



// GetInstantType��������
enum INSTANT_TYPE
{
	INSTANT_HP				= 0,
	INSTANT_EN				= 1,
	INSTANT_FUEL			= 2,
	INSTANT_EQUIP			= 3,
	INSTANT_STATUS_FIRST	= 10,
	INSTANT_STATUS_LAST		= 39,
	INSTANT_EXPLODE_FIRST	= 40,
	INSTANT_EXPLODE_LAST	= 79,
};
// MonsterBook
enum
{
		ACTION_QUERY_IDENTIFY_LIST			= 0,				// to server, to client��ѯ���������б�
		ACTION_IDENTIFY_FIRST_TIP				= 1,					// to client��һ��ɱ��ĳ������ϵͳ��Ϣ��ʾ
		ACTION_IDENTIFY_MIDDLE_TIP			= 2,				// to client����ͼ���ȼ��õ�����ʱ��ϵͳ��Ϣ��ʾ
		ACTION_IDENTIFY_TOP_LEVEL_TIP		= 3,				// to clientͼ���ȼ��ﵽ8����ϵͳ��Ϣ��ʾ
		ACTION_IDENTIFY_ADDITIONAL_TIP	= 4,				// to client�����ͼ������ֵ������ϵͳ��Ϣ��ʾ
		ACTION_QUERY_MONSTER_KILL				= 5,					// to server, to client��ѯ���������ɱ��������usPageNum��ʾ��������usShort
		ACTION_QUERY_MONSTER_KILL_LIST	= 6,				// to server, to client��ѯɱ���б�
};

// Storage
enum
{	// type
	MSGPACKAGE_TYPE_NONE			= 0,
	MSGPACKAGE_TYPE_STORAGE			= 10,	// �Ĵ洦
	MSGPACKAGE_TYPE_TRUNK			= 20,	// ����
	MSGPACKAGE_TYPE_CHEST			= 30,	// �ٱ���
	MSGPACKAGE_TYPE_VIRTUALSPACE	= 40,	// ��ռ���չ��
	MSGPACKAGE_TYPE_VIPSTORAGE      = 50    // VIPר�òֿ�
		
};

enum TASKDATA
{
	TASKDATA_ID_		=0,
	TASKDATA_IDNEXT		=1,
	TASKDATA_IDNEXTFAIL,
	TASKDATA_ITEMNAME1,
	TASKDATA_ITEMNAME2,
	TASKDATA_MONEY,
	TASKDATA_PROFESSION,
	TASKDATA_SEX,
	TASKDATA_MINPK,
	TASKDATA_MAXPK,
	TASKDATA_TEAM,
	TASKDATA_METEMPSYCHOSIS,
	TASKDATA_QUERY,
	TASKDATA_MARRIAGE,
	TASKDATA_CLIENTACT,
};

// enum ENUM_MAPTYPE 
// {
// 	MAPTYPE_NORMAL								= 0x0000,			// ��ͨ��ͼ 
// 	MAPTYPE_PKFIELD								= 0x0001,			// PK��
// 	MAPTYPE_CHGMAP_DISABLE						= 0x0002,			// ������ħ���ڵ�ͼʵ���ƶ�
// 	MAPTYPE_RECORD_DISABLE						= 0x0004,			// ���ܼ�¼
// 	MAPTYPE_PK_DISABLE							= 0x0008,			// 8������PK
// 	MAPTYPE_BOOTH_ENABLE						= 0x0010,			// 16��ר�ð�̯��ͼ(�޼�¼��)
// 	MAPTYPE_TEAM_DISABLE						= 0x0020,			// 32���������
// 	MAPTYPE_TELEPORT_DISABLE					= 0x0040,			// 64 // chgmap by action��������chgmap��ָ����سǾ�
// 	MAPTYPE_SYN_MAP								= 0x0080,			// 128�����ɵ�ͼ
// 	MAPTYPE_PRISON_MAP							= 0x0100,			// 256��������ͼ
// 	MAPTYPE_DISABLE_TRANSFER_SOURCE				= 0x00200,			// 512��������Ϊ˲�Ƶ�Դ��
// 	MAPTYPE_FAMILY								= 0x00400,			// 1024�� ��ͥ��ͼ 
// 	MAPTYPE_MINEFIELD							= 0x0800,			// 2048����
// 	MAPTYPE_PKGAME								= 0x1000,			// 4096 // PK��
// 	MAPTYPE_HUMAN								= 0x2000,			// 8192 // ���ೡ��������ר�ó���������PK�����У�
// 	MAPTYPE_WORLDWAR							= 0x4000,			// 16384 // ��ս��ͼ 
// 	MAPTYPE_UNIVERSE							= 0x8000,			// 32768 //���泡�� ����������ͨ��ͼ�����ƶ���ʽ��
// 	MAPTYPE_EXPERIMENT							= 0x10000,			// 32768 //�����ҵ�ͼ ����������ͨ��ͼ���֣�
// 	MAPTYPE_SPACESHIPJOB						= 0x20000,			// �ɴ������ͼ ����
// 	MAPTYPE_SPACESHIP							= 0x40000,			// �ɴ���ͼ ����
// 	MAPTYPE_TRAININGFIELD						= 0x80000,			// 524300 // ��������ͼ ���� (auto set no_pk|no_record, ��������ս������)
// 	MAPTYPE_NEWPIE_PK_PROTECT					= 0x100000,			// ���ֱ�����ͼ	
// 	MAPTYPE_DISABLE_TRANSFER_TARGET				= 0x200000,			// ������Ϊ˲�Ƶ�Ŀ�ĵ�
// 	MAPTYPE_NO_REBORN_INNOWPOS					= 0x400000,			// ����ԭ�ظ����
// 	MAPTYPE_DISABLE_TRANSPOS					= 0x800000,			// �����ٻ� 2007-2-27 tcp add
// 	MAPTYPE_DISABLE_TRANSFORM					= 0x1000000,		// ���ɱ��εĵ�ͼ 2007-3-29 tcp add	
// 	MAPTYPE_DISABLE_TRUMP_REBORN				= 0x2000000,		// ��ֹʹ�÷��������	
// 	MAPTYPE_DISABLE_TRUMP_REGION				= 0x4000000,		// ��ֹʹ�÷�����缼��	
// 	MAPTYPE_DISABLE_TRUMP_RAND_TRANS_POS		= 0x8000000,		// ��ֹʹ�÷���-С˲��		
// 	MAPTYPE_PK_LOST_NOTHING						= 0x10000000,		// PK����Ҳ������κ���ʧ				
// 	MAPTYPE_DISABLE_AREA_MAGIC					= 0x20000000,		// ?	��ֹʹ�÷�Χ����	
// 	MAPTYPE_DISABLE_STEAL						= 0x40000000,		// ?	��ֹ͵��
// 	MAPTYPE_DISBLE_TEAM_SEARCH					= 0x80000000,		// ��ֹ���������ĵ�ͼ����
// };

enum WEAPONATK_PROPERTYTYPE
{
	WEAPONATK_NORMAL = 0,
	WEAPONATK_HOT,					// �������Թ�������
	WEAPONATK_SHAKE,				// �����Թ�������
	WEAPONATK_STING,				// �������Թ�������
	WEAPONATK_DECAY,				// ��ʴ���Թ�������
	WEAPONATK_MATE_SHARE_DAMEGE,	// ��żƽ���˺��Թ�������	
	WEAPONATK_RECURSIVE_DAMEGE,	    // �����˺�		
	WEAPONATK_ADD_MONSTER_DAMAGE,   // �������Թ����Ъ�˺�
	WEAPONATK_SHOTGUN    = 11,              // ɢ��ǹ����
	
	WEAPONATK_END,					// ������־
};

enum STARWAR_STATUS
{
	STARWAR_STATUS_NOT_BEGIN =0,
		STARWAR_STATUS_WAITFOR_JION,
		STARWAR_STATUS_BEGIN,
		STARWAR_STATUS_WAIT_FOR_CHANGE_TO_BONUSMAP,
		STARWAR_STATUS_BONUSMAP,
		STARWAR_STATUS_END,
};

enum SYNAWARD
{
	SYNAWARD_SCORE,
	SYNAWARD_MONEY,
};

enum
{
	MSG_TRUMP_APPLY = 0,			// TSTC �����Ŀ��ʹ�÷���,dwFunctionCodeΪ���ܱ��
	MSG_TRUMP_REFUSE,				// TSTC �Է��ܾ���ʹ�÷���
	MSG_TRUMP_AGREE,				// TSTC �Է�ͬ�ⱻʹ�÷���
		
	MSG_TRUMP_USE,					// TS   ʹ�÷���,ֻҪ�ҵ�dwFunctionCode���ܱ�ŵ���Ʒ����
	MSG_TRUMP_USE_SUCCESS,			// TC   ����ʹ�óɹ�
		
	MSG_TRUMP_CREATE_REGION,		// TS   ʹ�÷���,idTrump��ʾ����ID
		
	MSG_TRUMP_USE_BY_ID,			// TS   ʹ�÷���,idTrump��ʾ����ID,dwFunctionCode���ܱ��
		
	MSG_TRUMP_USE_SUCCESS_FLUSH,	// TC   �������������ù�Ч���� dwFunctionCode���ܱ�ŵ���Ʒ
		
	MSG_TRUMP_USE_SUCCESS_DAMAGE,	// TC   ����������������Ѫ���� dwFunctionCode���ܱ�ŵ���Ʒ dwData:��Ѫֵ
		
	MSG_TRUMP_HOLE1_PROGRESS,		// TS	����-��������,��һ������
	MSG_TRUMP_HOLE2_PROGRESS,		// TS	����-��������,����������
		
	MSG_TRUMP_HOLE1_MOONGEM,		// TS	����-��������,��չװ�ÿ�����һ������
	MSG_TRUMP_HOLE2_MOONGEM,		// TS	����-��������,��չװ�ÿ�������������
		
	MSG_TRUMP_HOLE1_RMB,			// TS	����-��������,ֱ��ʹ��̫��ʯ��һ������
	MSG_TRUMP_HOLE2_RMB,			// TS	����-��������,ֱ��ʹ��̫��ʯ����������
		
	MSG_TRUMP_ASSISTANT_FUN_COMBINE,// TS	�����������ܺϳ� idTrump:�����ܷ���	idOtherTrump:�������� idGem:��̫id 	
	// btMainMask     :������ѡȡ������λ 1 2 4 8 λ��0:�ֱ������������  Hot_atk��Shake_atk��Sting_atk��Decay_atk
	// btAssistantMask:������ѡȡ������λ 1 2 4 8 λ��1:�ֱ������������Hot_atk��Shake_atk��Sting_atk��Decay_atk
	
	MSG_TRUMP_TYPE_DIE_BEAT_BACK = 43, //������۵���HP
		
	MSG_TRUMP_IMPROVE_MAIN_FUNC_VAL = 100,	  // TS   ����-������Ч����ֵ���� idGem:������Ʒid  idTrump:����id
	MSG_TRUMP_IMPROVE_MAIN_FUNC_SUCEESS = 101,// TC   ����-������Ч����ֵ���ɳɹ� dwDetalVal:��������ֵ dwData:�÷��������ֵ
	MSG_TRUMP_IMPROVE_MAIN_FUNC_FAIL = 102,   // TC   ����-������Ч����ֵ�����Ѵﵽ���ֵ
		
	MSG_TRUMP_TYPE_INTERVAL_INCREASE_HP = 1000, //�������ʱ������HP
};



enum
{
	MSG_TRUMPREGION_CREATE,				//�����ɹ�
	MSG_TRUMPREGION_INFO,				//�����Ϣ	
	MSG_TRUMPREGION_KICK,				//��类����,��������ҵĽ��������,m_StrPacker�������������
	MSG_TRUMPREGION_DIE_FOR_MONSTER,	//��类����,���ִ���,m_StrPacker��MonsterType(�ַ�����ʽ)
	MSG_TRUMPREGION_DIE_FOR_USER,		//��类����,��PK,m_StrPacker��PK�������
	
	MSG_TRUMPREGION_MOVEOUT,			//��类����,�뿪�������Χ
	MSG_TRUMPREGION_END,				//��类����,����ʱ�����
	
	MSG_TRUMPREGION_LEAVE_SYNDICATE,	//��类�����뿪����
	MSG_TRUMPREGION_LEAVE_TEAM,			//��类�����뿪����
	MSG_TRUMPREGION_LEAVE_FAMILY,		//��类�����뿪��������
	
	MSG_TRUMPREGION_ADD_SYNDICATE,		//���������
	MSG_TRUMPREGION_ADD_TEAM,			//���������
	MSG_TRUMPREGION_ADD_FAMILY,			//���������
};

enum
{
	OBJ_MACHINEGUN	= 0x900001,
	OBJ_FREEZEGUN	= 0x900002,
	OBJ_SNIPEGUN	= 0x900003,
	OBJ_FLAMETHROWERGUN	= 0x900004,
	OBJ_SHOTGUN		= 0x900005,
	OBJ_MUSKETGUN	= 0x900006,
};

//���³ǵ�������
enum DunTerrainType
{
	DUNTERRAINTYPE_NONE			=0,				//ģ���ļ�����δ���õĸ��ӣ���Ϊ�ǿ�������

	//�����ֶ�ֵ0~9999Ϊ���ھ����
	DUNTERRAIN_DIG_BEGIN		=0,				//���ھ����
	
	//Σ������Σ���������ε�Σ��ֵ�ֶ�ֵ��Ϊ0ʱ����ʾ�õ�������Σ������Σ����ھ�����п��ܷ���������
	DUNTERRAIN_DANGER			=201,
	//�������Σ���������εĵ�������Сֵ�����������ֵ��Ϊ0ʱ����ʾ�õ������ڽ������Σ����ھ����ʱ���漴��ý�ң������ҵ��书�ܼ�����Ӱ�����
	DUNTERRAIN_GOLD				=202,
	
	DUNTERRAIN_DIG_END			=9999,			//���ھ����

	//////////////////////////////////////////////////////////////////////////
	//�����ֶ�ֵ10000~65535Ϊ�����ھ����
	DUNTERRAIN_UNDIG_BEGIN		=10000,			//�����ھ����

	//10000~10006Ϊδռ��Ŀյ�����Σ�
	DUNTERRAIN_UNOCCUPY_BEGIN	=10000,
	DUNTERRAIN_UNOCCUPY_DEFAULT	=DUNTERRAIN_UNOCCUPY_BEGIN,	//Ĭ�ϵ�δռ�����
	DUNTERRAIN_UNOCCUPY_1		=DUNTERRAIN_UNOCCUPY_DEFAULT,
	DUNTERRAIN_UNOCCUPY_2 		=DUNTERRAIN_UNOCCUPY_DEFAULT + 1,
	DUNTERRAIN_UNOCCUPY_3 		=DUNTERRAIN_UNOCCUPY_DEFAULT + 2,
	DUNTERRAIN_UNOCCUPY_4 		=DUNTERRAIN_UNOCCUPY_DEFAULT + 3,
	DUNTERRAIN_UNOCCUPY_5 		=DUNTERRAIN_UNOCCUPY_DEFAULT + 4,
	DUNTERRAIN_UNOCCUPY_6 		=DUNTERRAIN_UNOCCUPY_DEFAULT + 5,
	DUNTERRAIN_UNOCCUPY_7 		=DUNTERRAIN_UNOCCUPY_DEFAULT + 6,
	DUNTERRAIN_UNOCCUPY_END		=DUNTERRAIN_UNOCCUPY_7,

	//10010~10019Ϊˮ����Σ�
	//10020~10029Ϊ�ҽ�����Σ�
	//10030~10039Ϊ��ʯ����Σ�

	//10040~10046Ϊռ���Ŀյص��Σ�
	DUNTERRAIN_OCCUPY_BEGIN		=10040,
	DUNTERRAIN_OCCUPY_DEFAULT	=DUNTERRAIN_OCCUPY_BEGIN,	//Ĭ�ϵ�δռ�����
	DUNTERRAIN_OCCUPY_1			=DUNTERRAIN_OCCUPY_DEFAULT,
	DUNTERRAIN_OCCUPY_2 		=DUNTERRAIN_OCCUPY_DEFAULT + 1,
	DUNTERRAIN_OCCUPY_3 		=DUNTERRAIN_OCCUPY_DEFAULT + 2,
	DUNTERRAIN_OCCUPY_4 		=DUNTERRAIN_OCCUPY_DEFAULT + 3,
	DUNTERRAIN_OCCUPY_5 		=DUNTERRAIN_OCCUPY_DEFAULT + 4,
	DUNTERRAIN_OCCUPY_6 		=DUNTERRAIN_OCCUPY_DEFAULT + 5,
	DUNTERRAIN_OCCUPY_7 		=DUNTERRAIN_OCCUPY_DEFAULT + 6,
	DUNTERRAIN_OCCUPY_END		=DUNTERRAIN_OCCUPY_7,

	//////////////////////////////////////////////////////////////////////////
	//10050~65535Ϊ���ֽ������Σ�
	DUNTERRAIN_BUILDING_BEGIN	=10050,
	//��Ϊ��������ʱ��ǰ��λ��ʾ�������ͣ����һλ��ʾ������ǰ�ȼ���
	//�ȼ�λ��СֵΪ0����ʾ1��������
	
	//DUNBUILDINGTYPE

	DUNTERRAIN_BUILDING_END		=65535,
	//////////////////////////////////////////////////////////////////////////

	DUNTERRAIN_UNDIG_END		=65535,			//�����ھ����
	
};

//���³ǽ���������
enum DUNBUILDINGTYPE
{
	DUNBUILDINGTYPE_BEGIN			 =1005,
		
	DUNBUILDINGTYPE_UNDIG_ROAD		 =1005,		//��·�������ھ�/�����룩
	DUNBUILDINGTYPE_HEART			 =1006,		//���³�֮�ģ��ɴ��Ҳ��֣�
	DUNBUILDINGTYPE_HEART_CENTER	 =1007,		//���³�֮�ģ����벿�֣�
	DUNBUILDINGTYPE_MATERIAL_STORAGE =1008,    //���³ǲ��ϲֿ�
	DUNBUILDINGTYPE_MONEY_STORAGE	 =1009,	//���³ǽ�Ǯ�ֿ�
	DUNBUILDINGTYPE_END				 =6553,
};
	
//�����ű�ʵ��һ��robottype��Ӧ����ȼ�����
enum DUNIMPTYPEDATA
{
	_DUNIMPTYPEDATA_ID,				//
	DUNIMPTYPEDATA_TYPE,			//��Ӧrobottype.id
	DUNIMPTYPEDATA_LEVEL,			//�ȼ�
	DUNIMPTYPEDATA_DIG_STRENGTH,	//С��:�ھ�ʱ�Ļ�������ֵ
	DUNIMPTYPEDATA_DIG_TECH,		//С��:����ʱ�Ļ�������ֵ
	DUNIMPTYPEDATA_DIG_MAXLOAD,		//С��:�ھ�ʱ��Я����Դ�Ļ����������ֵ
};

//cq_dun_dig��ÿ�����ӱ��������
enum DIGSTATUS
{
	DIGSTATUS_BEGIN			= 0,
	DIGSTATUS_UNDEFIED		= DIGSTATUS_BEGIN,

	DIGSTATUS_BLOCK			= 1,	//��û���ھ�

	//δռ��յ�
	DIGSTATUS_UNOCCPY_BEGIN	= 2 ,
	DIGSTATUS_UNOCCPY_DEFAULT= DIGSTATUS_UNOCCPY_BEGIN ,
	DIGSTATUS_UNOCCPY_1		= DIGSTATUS_UNOCCPY_BEGIN ,
	DIGSTATUS_UNOCCPY_2		= 2 ,
	DIGSTATUS_UNOCCPY_3		= 3 ,
	DIGSTATUS_UNOCCPY_4		= 4 ,
	DIGSTATUS_UNOCCPY_5		= 5 ,
	DIGSTATUS_UNOCCPY_6		= 6 ,
	DIGSTATUS_UNOCCPY_7		= 7 ,
	DIGSTATUS_UNOCCPY_END	= DIGSTATUS_UNOCCPY_7,
	
	//��ռ��յ�
	DIGSTATUS_OCCPY_BEGIN	= 8 ,
	DIGSTATUS_OCCPY_DEFAULT	= DIGSTATUS_OCCPY_BEGIN ,
	DIGSTATUS_OCCPY_1		= DIGSTATUS_OCCPY_BEGIN ,
	DIGSTATUS_OCCPY_2		= 9 ,
	DIGSTATUS_OCCPY_3		= 10,
	DIGSTATUS_OCCPY_4		= 11,
	DIGSTATUS_OCCPY_5		= 12,
	DIGSTATUS_OCCPY_6		= 13,
	DIGSTATUS_OCCPY_7		= 14,
	DIGSTATUS_OCCPY_END		= DIGSTATUS_OCCPY_7,
	
	//������
	DIGSTATUS_BUILDING		= 15,

	DIGSTATUS_COUNT,
};

//cq_dun_terrain_type
enum DunTerrainTypeData
{
	DUNTERRAINTYPEDATA_ID,
	DUNTERRAINTYPEDATA_NAME,		//��¼�õ��ε�����
	DUNTERRAINTYPEDATA_TYPE,		//��¼�õ��ε�����
	DUNTERRAINTYPEDATA_MAXLIFE,
	DUNTERRAINTYPEDATA_EVENT_CHANCE,//��¼�õ��δ��������¼��ĸ��ʣ���ʾ�ٷֱȣ��磺Σ��ֵ=10�����ʾ��10%�ĸ��ʴ��������¼�
	DUNTERRAINTYPEDATA_DAMAGE,		//��¼�õ��ζ�С����ɵ��˺�ֵ��֧�־���ֵ�Ͱٷֱ�
	DUNTERRAINTYPEDATA_MINMONEY,	//��¼�õ��α��ƻ�ʱ�������ҵ���С����
	DUNTERRAINTYPEDATA_MAXMONEY,	//��¼�õ��α��ƻ�ʱ�������ҵ��������
};

//dungeon
enum DUNDATA
{
	DUNDATA_ID			=0,
	DUNDATA_OWNERID,
	DUNDATA_OWNERTYPE,
	DUNDATA_GENNO,
	DUNDATA_TEMPLATE_FILE_ID,
};

//���³ǳ����ȼ�
enum DUNKEEPERRANK
{
	DUNKEEPERRANK_NONE		= 0,
	DUNKEEPERRANK_SMALL		= 1,
	DUNKEEPERRANK_MIDDLE	= 2,
	DUNKEEPERRANK_LARGE		= 3,
	DUNKEEPERRANK_HUGE		= 4,
};

//��������״̬�ж�
enum SPIRITSTATUS
{
	SPIRITSTATUS_WORKING	= 1< 1,	//�Ͷ���
	SPIRITSTATUS_POSSESS	= 1< 2,	//����Ҹ���
	SPIRITSTATUS_SWIMMY		= 1< 3,	//ѣ��
};

enum LOTTERY_DATA
{ 
	LOTTERYDATA_ID_,
	LOTTERYDATA_TYPE,
	LOTTERYDATA_RANK,
	LOTTERYDATA_CHANCE,
	LOTTERYDATA_PRIZE_NAME,	
	LOTTERYDATA_PRIZE_TYPE,
	LOTTERYDATA_PRIZE_ITEM,
	LOTTERYDATA_COLOR,
	LOTTERYDATA_HOLE_NUM,
	LOTTERYDATA_ADDITION_LEV,
	LOTTERYDATA_HOT_ATK,
	LOTTERYDATA_SHAKE_ATK,
	LOTTERYDATA_STING_ATK,
	LOTTERYDATA_DECAY_ATK,
	LOTTERYDATA_HOT_DEF,
	LOTTERYDATA_SHAKE_DEF,
	LOTTERYDATA_STING_DEF,
	LOTTERYDATA_DECAY_DEF
};

enum PASSIVE_MAGIC_TYPE
{
	PASSIVE_MAGIC_NONE=0,
	PASSIVE_MAGIC_HOT_ATTACK,	//�ȹ���
	PASSIVE_MAGIC_ICE_ATTACK,	//�乥��
	PASSIVE_MAGIC_SHAKE_ATTACK,	//�𵴹���
};

enum POWER_EQUIPTYPE
{
	POWER_EQUIPTYPE_ENGINER   			= ITEMPOS_ENGINE,  //������
	POWER_EQUIPTYPE_ENPACK        		= ITEMPOS_ENPACK,  //������
	POWER_EQUIPTYPE_THRUSTER  			= ITEMPOS_THRUSTER,//�ƽ���
};

enum BROTHER_RELATION_TYPE_DATA
{
	BROTHER_RELATION_TYPE_ID,
	BROTHER_RELATION_TYPE_LEV,
	BROTHER_RELATION_TYPE_NEED,
	BROTHER_RELATION_TYPE_NAME,
	BROTHER_RELATION_TYPE_PK_REDUCE,
	BROTHER_RELATION_TYPE_TALK_ADD,
};
enum
{
	GACTION_HEROINFO			= 0,
	GACTION_TOP10INFO			= 1,
	GACTION_UPDATE_FAMILY_FUND	= 2,	// ר��: �㲥���¿ͻ��˼����������, ֻ�ܸ���dwSynMoneyֵ
	GACTION_UPDATE_FAMILY_LEVEL	= 3,	// ר�ã��㲥���¿ͻ��˼���ȼ���ֻ����ucFamilyLevֵ
	GACTION_UPDATE_STARTOWER	= 4,	// ר�ã��㲥���¿ͻ��˼���ս�������ȼ���ֻ����ucStarTowerֵ
};
enum ATK_GRADE_TYPE_DATA
{
	ATK_GRADE_TYPE_DATA_ID,
		ATK_GRADE_TYPE_DATA_ROBOT_LEVEL_MIN,
		ATK_GRADE_TYPE_DATA_ROBOT_LEVEL_MAX,
		ATK_GRADE_TYPE_DATA_QUALITY,
		ATK_GRADE_TYPE_DATA_ADDITION,
		ATK_GRADE_TYPE_DATA_GRADE,
};

enum USER_ATK_MONSTER_TYPE_DATA
{
	USER_ATK_MONSTER_TYPE_DATA_ID,
	USER_ATK_MONSTER_TYPE_DATA_DELTA_LEV,
	USER_ATK_MONSTER_TYPE_DATA_ATK_GRADE,
	USER_ATK_MONSTER_TYPE_DATA_ATK_TIMES,
	USER_ATK_MONSTER_TYPE_DATA_TYPE,
};

enum GUARD_DMG_TYPE_DATA
{
	GUARD_DMG_TYPE_DATA_ID,
	GUARD_DMG_TYPE_DATA_TYPE,
	GUARD_DMG_TYPE_DATA_DELTA_LEV,
	GUARD_DMG_TYPE_DATA_SHORT_DMG_MAX,
	GUARD_DMG_TYPE_DATA_LONG_DMG_MAX,
	GUARD_DMG_TYPE_DATA_SHORT_ATK_DMG_MIN,
	GUARD_DMG_TYPE_DATA_LONG_ATK_DMG_MIN,
};


enum GUARD_PK_TYPE_DATA
{
	GUARD_PK_TYPE_DATA_ID,
	GUARD_PK_TYPE_DATA_ATK_TYPE,
	GUARD_PK_TYPE_DATA_DEF_TYPE,
	GUARD_PK_TYPE_DATA_DELTA_LEV,
	GUARD_PK_TYPE_DATA_DMG_PERCENT,
	GUARD_PK_TYPE_DATA_RESTRAIN_STARLEV,
};
enum 
{
	STATUS_NONE = 0, 
	STATUS_WAR = 1,
};

// ���ɵȼ�
enum SYN_RANK
{
	SYN_RANK_ERROR = 0,
	SYN_RANK_1,
	SYN_RANK_2,
	SYN_RANK_3,
	SYN_RANK_4,
	SYN_RANK_5,
	SYN_RANK_6,
	SYN_RANK_7,
	SYN_RANK_8,
	SYN_RANK_9,
	SYN_RANK_10,
	SYN_RANK_MAX = SYN_RANK_10
};

enum SYN_DATA
{
	SYN_DATA_BEGIN = 0,
	SYN_DATA_ID = 0,
	SYN_DATA_NAME = 1,
	SYN_DATA_ANNOUNCE,
	SYN_DATA_TENET,
	SYN_DATA_MEMBER_TITLE,
	SYN_DATA_LEADER_ID,
	SYN_DATA_LEADER_NAME,
	SYN_DATA_MONEY,
	SYN_DATA_DEL_FLAG,
	SYN_DATA_AMOUNT,
	SYN_DATA_ENEMY0,
	SYN_DATA_ENEMY1,
	SYN_DATA_ENEMY2,
	SYN_DATA_ENEMY3,
	SYN_DATA_ENEMY4,
	SYN_DATA_ALLY0,
	SYN_DATA_ALLY1,
	SYN_DATA_ALLY2,
	SYN_DATA_ALLY3,
	SYN_DATA_ALLY4,
	// ���ӵȼ�
	SYN_DATA_RANK,
	// ����ͼ��
	SYN_DATA_ICON,
	// ���Ӵ���ʱ��
	SYN_DATA_CREATEDATE,
	// ��ָ�������
	SYN_DATA_COACH_USER0,						
	SYN_DATA_COACH_USER1,
	SYN_DATA_COACH_USER2,
	SYN_DATA_COACH_USER3,
	SYN_DATA_COACH_USER4,
	SYN_DATA_COACH_USER5,
	SYN_DATA_COACH_USER6,
	SYN_DATA_COACH_USER7,
	SYN_DATA_COACH_USER8,
	SYN_DATA_COACH_USER9,
	SYN_DATA_TOTEM_POLE,
	SYN_DATA_MEMBER_TITLE_CNT,
	SYN_DATA_EMONEY,
	SYN_DATA_PUBLISH_TIME,
	SYN_DATA_END = SYN_DATA_PUBLISH_TIME
};

//teammission
enum TEAMMISSIONDATA
{
	//base�������������
	//perfect���������
	TEAMMISSIONDATA_ID,				//������id	
	TEAMMISSIONDATA_NAME,			//������������	
	TEAMMISSIONDATA_GENNO,			//��¼�ø�����������Ӧ��map.GenNo���
	TEAMMISSIONDATA_TYPE,			//�Զ����Ʒ�ʽ����������������
	//��һλΪ�Կ��������ʶ����Ϊ1����ʾ������Ϊ�Կ����������������������������ԭ�������ж�
	//�ڶ�λΪ�����������ʶ����Ϊ1����ʾ������Ϊ�Կ�������������������������񣬸���ԭ��������������	
	TEAMMISSIONDATA_MINLEV,			//��¼�ø������������ȼ������Ҫ��
	//0��ʾ������ȼ����Ҫ��	
	
	TEAMMISSIONDATA_MAXLEV,			//��¼�ø������������ȼ������Ҫ��
	//0��ʾ������ȼ����Ҫ��	
	TEAMMISSIONDATA_MIN_BE,			//��¼�ø�������������ս����Ҫ��
	//0��ʾ��ս����Ҫ��	
	TEAMMISSIONDATA_MAXMINUTE,		//��¼�ø�����������ʱ�ޣ���λ������	
	TEAMMISSIONDATA_START_ACTION,	//��¼��������ʼ��ִ�е��������񡢿�ѡ��������action_id
	TEAMMISSIONDATA_BASE_SCORE,		//��¼��������������������ɿɻ����������
	TEAMMISSIONDATA_PERFECT_SCORE,	//��¼���������д��������������������
	TEAMMISSIONDATA_MINPROFFER,		//��¼��������ĸ����������Ĺ��׶�Ҫ��
	TEAMMISSIONDATA_AWARD_ITEMTYPE,	//��¼����������ɺ󣬿ɻ�õĽ�����Ʒitemtype_id
	TEAMMISSIONDATA_AWARD_MONEY,	//��¼����������ɺ󣬿ɻ�õĽ�Ǯ����
	TEAMMISSIONDATA_AWARD_UPLEVTIME,//��¼����������ɺ󣬿ɻ�õĽ�������uplevtime
	TEAMMISSIONDATA_END_ACTION,		//��¼�����������������������ɺ�ִ�е�Action_id���ṩ������ʹ��
	TEAMMISSIONDATA_BASE_SECS,		//��¼����������ɻ�ñ��׽����ı�׼ʱ�䣬mmSS
	TEAMMISSIONDATA_PERFECT_SECS,	//��¼����������ɻ�ñ��׽����ı�׼ʱ�䣬mmSS
	TEAMMISSIONDATA_RETURN_MAPID,	//��¼��Ҵ����񸱱��з��غ����ŵ�����	
	TEAMMISSIONDATA_RETURN_X,		//���񷵻ص�����X		
	TEAMMISSIONDATA_RETURN_Y,		//���񷵻ص�����Y		
	TEAMMISSIONDATA_START_TIME,		//��¼���񿪷ŵ�ʱ�����ֹ�㣬��Ϊ0��������,֧�ֶ�ÿ�졢ÿ�ܡ�ÿ�µ�ָ��ʱ���������	
	TEAMMISSIONDATA_END_TIME,		//���񿪷�ʱ���յ�,HHmmSS	
};

enum ZERO_TRUMP_VALUE
{
	ZERO_TRUMP_BATTLEEFFECT_VALUE,
	ZERO_TRUMP_ATTACK_VALUE,
	ZERO_TRUMP_DEFENCE_VALUE,
};

enum LOGSWITCH_DATA
{
	LOGSWITCH_PKCOMPETE,
	LOGSWITCH_SHIPJOB,
	LOGTRUMP_ASSISTANT_COMBINE,	
	LOGOPEN_HOLE,
	LOGSWITCH_MONSTER_DROP,
	LOGSWITCH_ITEM_ADDITION,
	LOGSWITCH_FORBIDWALLOW,//�����Կ���
	LOGSWITCH_REPAIR,
	LOGSWITCH_SHOP_BUY_ITEM,
	LOGSWITCH_SHOP_SELL_ITEM,
	LOGSWITCH_BUY_BOOTH,	
	LOGSWITCH_PRISON_OUT,
	LOGSWITCH_BATTLE_EFFCET,//��¼���ս��������
	LOGSWITCH_NIBUS,
	LOGMERGE_SERVER_NAME_CHECK,
	LOGSWITCH_PK_COMPETE,
	LOGSWITCH_SYNWAR,
	LOGSWITCH_GAMEMONEY,		
	LOGSWITCH_STONE,
	LOGSWITCH_WALKPIXDETAIL,
	LOGSWITCH_SKILLDETAIL,	//���ܵ�����
};

enum PKCOMPETE_GROUPTYPE
{
	PKCOMPETEGROUP_NONE,
	PKCOMPETEGROUP_NORMAL,
	PKCOMPETEGROUP_NEARORFAR,
};

enum DUN_CONSTRUCTION_MATERIAL
{
	DUN_CONSTRUCTION_MATERIAL_ID,
	DUN_CONSTRUCTION_MATERIAL_OWNER_ID,
	DUN_CONSTRUCTION_MATERIAL_OWNER_TYPE,

	DUN_CONSTRUCTION_MATERIAL_MONEY,
	DUN_CONSTRUCTION_MATERIAL_WOOD,
	DUN_CONSTRUCTION_MATERIAL_STONE,
	DUN_CONSTRUCTION_MATERIAL_OIL,
	DUN_CONSTRUCTION_MATERIAL_CRYSTAL,
	DUN_CONSTRUCTION_MATERIAL_AVENTURINE,
	DUN_CONSTRUCTION_MATERIAL_GUNMETAL,
	DUN_CONSTRUCTION_MATERIAL_STEEL,
	DUN_CONSTRUCTION_MATERIAL_MARBLE,
	DUN_CONSTRUCTION_MATERIAL_PEARL,
	DUN_CONSTRUCTION_MATERIAL_CORAL,
	DUN_CONSTRUCTION_MATERIAL_SILVER,
	DUN_CONSTRUCTION_MATERIAL_GOLD,
	DUN_CONSTRUCTION_MATERIAL_GEM,
	DUN_CONSTRUCTION_MATERIAL_JADE,
	DUN_CONSTRUCTION_MATERIAL_15,
	DUN_CONSTRUCTION_MATERIAL_16,
	DUN_CONSTRUCTION_MATERIAL_17,
	DUN_CONSTRUCTION_MATERIAL_18,
	DUN_CONSTRUCTION_MATERIAL_19,

	DUN_CONSTRUCTION_MATERIAL_BEGIN = DUN_CONSTRUCTION_MATERIAL_MONEY,
	DUN_CONSTRUCTION_MATERIAL_END = DUN_CONSTRUCTION_MATERIAL_19
};

enum ROLE_ACTION_ENUM
{
	ROLE_ACTION_BEGIN = 0, 
	ROLE_ACTION_ATTACK, 
	ROLE_ACTION_DIE,
	ROLE_ACTION_MOVE,
	ROLE_ACTION_EMOTION,
	ROLE_ACTION_CALLBACK,
	ROLE_ACTION_BEATTACK,
	ROLE_ACTION_END, 
};

enum COLLECT_TYPE
{
	COLLECT_TYPE_NONE,
	COLLECT_TYPE_EARTHBAG,
};

//////////////////////////////////////////////////////////////////////////
// QuizCompete
enum QUIZ_COMPETE_TYPE
{
	NONE_COMPETE = 0,
	M_PLAYER_COMPETE,  //ȫ����������
	S_PLAYER_COMPTET,   //������������
	AD_PLAYER_COMPET,   //�������⾺��
	EXPBALL_COMPETE,    //���������;���
};


//// MsgCallEvent ���õ��Ķ���!!!!
enum LUA_EVENT_TYPE
{
	UNKNOWN_TYPE,
		TIMEOUT_EVENT,
		ROLE_EVENT,
		PLAYER_EVENT,
		SYSTEM_EVENT,
		WINDOW_EVENT,
		MONSTER_EVENT,
};


enum LUA_EVENT_SUB_TYPE
{
		ROLE_EVENT_START			= 1000,
		ROLE_HEALTHY_CHANGE			= 1001,
		ROLE_POS_CHANGE				= 1002,
		ROLE_RUNACTION_END			= 1003,
		ROLE_ACTION_HIT				= 1004,
		ROLE_EVENT_WALK				= ROLE_EVENT_START + 5,  // hero��·
		ROLE_EVENT_RUN				= ROLE_EVENT_START + 6,  // hero��
		ROLE_EVENT_JUMP				= ROLE_EVENT_START + 7,  // hero��Ծ
		ROLE_EVENT_ATTACK			= ROLE_EVENT_START + 8,  // hero����
		ROLE_EVENT_WOUND			= ROLE_EVENT_START + 9,  // hero����
		ROLE_EVENT_DIE				= ROLE_EVENT_START + 10, // hero����
		ROLE_EVENT_ATTACK_ACTION    = ROLE_EVENT_START + 11, // hero��������
		
		SYSTEM_EVENT_START			= 20000,
		SYSTEM_MONSTER_BORN			= 20001,
		SYSTEM_EFFECT_OVER			= 20002,
		SYSTEM_3DSCENE_BEGIN		= 20003,
		SYSTEM_3DSCENE_END			= 20004,
		//���
		SYSTEM_EVENT_CLICK_GROUND   = SYSTEM_EVENT_START + 5,
		SYSTEM_ENENT_CLICK_PLAYER   = SYSTEM_EVENT_START + 6,
		
		PLAYER_EVENT_START          = 2000,
		PLAYER_EVENT_INWEREWOLF     = PLAYER_EVENT_START + 1,
		PLAYER_EVENT_OUTWEREWOLF    = PLAYER_EVENT_START + 2,
		PLAYER_EVENT_PREUSESKILL    = PLAYER_EVENT_START + 3,
		PLAYER_EVENT_BEUSEDSKILL    = PLAYER_EVENT_START + 4,
		PLAYER_EVENT_INCURSE		= PLAYER_EVENT_START + 5,
		PLAYER_EVENT_OUTCURSE       = PLAYER_EVENT_START + 6,
		
		
		//�������action
		PLAYER_EVENT_ATTACK         = PLAYER_EVENT_START + 7, // player��������
		PLAYER_EVENT_WOUND          = PLAYER_EVENT_START + 8, // player���˶���
		PLAYER_EVENT_DIE            = PLAYER_EVENT_START + 9, // player��������
		PLAYER_EVENT_RUN_FORWARD    = PLAYER_EVENT_START + 10, // player��·����
		PLAYER_EVENT_JUMP			= PLAYER_EVENT_START + 11, // player��Ծ����
		PLAYER_EVENT_CHANGESHAPE	= PLAYER_EVENT_START + 12,
		PLAYER_EVENT_ATTACK_SCRIPT_PLAYER = PLAYER_EVENT_START + 13, // ����Script player�Ļص�	
		
		PLAYER_EVENT_INDIZZY		= PLAYER_EVENT_START + 14,  //��
		PLAYER_EVENT_OUTDIZZY       = PLAYER_EVENT_START + 15,  //����
		
		PLAYER_EVENT_PACTROMETER    = PLAYER_EVENT_START + 16, //  player�������
		PLAYER_EVENT_THROWGRENADE   = PLAYER_EVENT_START + 18, // player������
		PLAYER_EVENT_GRENADEBLAST   = PLAYER_EVENT_START + 19, // ���ױ�ը
		
		PLAYER_EVENT_STATUS_CHANGE_ADD = PLAYER_EVENT_START + 20, // ״̬�ı�(����)
		PLAYER_EVENT_STATUS_CHANGE_DEL = PLAYER_EVENT_START + 21, // ״̬�ı�(����)

		PLAYER_EVENT_REGION_CREATE_CENTER   = PLAYER_EVENT_START+22,    //����Ӱ�쿪ʼ
		PLAYER_EVENT_REGION_DESTROY_CENTER  = PLAYER_EVENT_START+23,	//����Ӱ�����

		PLAYER_EVENT_USE_SKILL = PLAYER_EVENT_START + 24, // ʹ�ü���(�������·�)

		PLAYER_EVENT_CREATE_HOSTAGE = PLAYER_EVENT_START  + 36, // ��������
		PLAYER_EVENT_DESTROY_HOSTAGE = PLAYER_EVENT_START  + 38, // �ջ����� 

		PLAYER_EVENT_PROP_CHANGE		= PLAYER_EVENT_START + 25,
		MONSTER_EVENT_START         = 40000,
		MONSTER_EVENT_INCHAOS       = MONSTER_EVENT_START + 1,
		MONSTER_EVENT_OUTCHAOS      = MONSTER_EVENT_START + 2,
		
		SHELL_LBUTTON_DOWN           = 99998,
		SHELL_RBUTTON_DOWN           = 99999,
		
		WINDOW_EVENT_CTRL = 100,
		WINDOW_EVENT_OPEN,
		WINDOW_EVENT_CLOSE,
		WINDOW_EVENT_HINT,
		WINDOW_EVENT_PREOPEN,
		WINDOW_EVENT_HINTSTR,
		WINDOW_EVENT_ITEM_MOUSEOVER,
		WINDOW_EVENT_ITEM_INSERT,
		WINDOW_EVENT_ITEM_DELETE,
		WINDOW_EVENT_ITEM_MOVE,
		WINDOW_EVENT_HOVER,//���ָ��
		WINDOW_EVENT_LEAVE,//����뿪
		WINDOW_EVENT_ENTERKEY,
		
};

enum PHYLE_TYPE				//��Ѫ������	09-09-17
{
	PHYLE_TYPE_ERROR = 0,	//��������
	PHYLE_TYPE_HUMAN,		//����
	PHYLE_TYPE_VAMPIRE,		//Ѫ��
};

enum CAMP_TYPE
{
	CAMP_TYPE_OTHER = 0,	//��������
	CAMP_TYPE_HUMAN,		//����
	CAMP_TYPE_VAMPIRE,		//Ѫ��
	CAMP_TYPE_WILDANIMALS,  //Ұ��
	CAMP_TYPE_DEVIL,		//��ħ
	CAMP_TYPE_UNDEAD,		//��������
	CAMP_TYPE_VARIANCE,		//��������
};

enum VAMPIRE_robotTYPE_DB_FIELD                                              // ��Ѫ�����ݿ��ֶ�ö��
{
    VAMPIRE_DB_robotTYPE_FIELD_ID,                   // "robottype, id"                       �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_PRICE,                // "robottype, price"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_HP,                   // "robottype, hp"                       �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_HP_INC,               // "robottype, hp_inc"                   �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_TOTALINSIDE_SIZE,     // "robottype, totalinside_size"         �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_SIZEX,                // "robottype, sizex"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_WEIGHT,               // "robottype, weight"                   �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DMG_SHARE,            // "robottype, dmg_share"                �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA0,                // "robottype, data0"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA1,                // "robottype, data1"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA2,                // "robottype, data2"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA3,                // "robottype, data3"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA4,                // "robottype, data4"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA5,                // "robottype, data5"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA6,                // "robottype, data6"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DATA7,                // "robottype, data7"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_REQ_LEV,              // "robottype, req_lev"                  �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_REQ_WEAPONSKILL,      // "robottype, req_weaponskill"          �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_REQ_SEX,              // "robottype, req_sex"                  �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_HOT_DEF,              // "robottype, hot_def"                  �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_SHAKE_DEF,            // "robottype, shake_def"                �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_WEAPON_TYPE,          // "robottype, weapon_type"              �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DECAY_DEF,            // "robottype, decay_def"                �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_LOOK,                 // "robottype, look"                     �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_TYPENAME,             // "robottype, typename"                 �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_AMOUNT_ADD,           // "robottype, amount_add"               �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_ROBOTNAME,            // "robottype, Robotname"                �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_DODGE,                // "robottype, dodge"                    �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_EXPTYPE,              // "robottype, exptype"                  �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_GUARD_DMG_TYPE,       // "robottype, guard_Dmg_type"           �ֶ�,   ��ʾ:
    VAMPIRE_DB_robotTYPE_FIELD_MAGIC_TYPE,           // "robottype, magic_type"               �ֶ�,   ��ʾ:
}; //VAMPIRE_robotTYPE_DB_FIELD


enum CALC_ANIMOSITY_TYPE
{
	PLAYER_ATTACK_MONSTER = 1,
	PLAYER_HEAL_PALYER,
	MONSTER_ATTACK_PLAYER,
	PLAYER_ATTACK_PALYER,
};


enum VAMPIRE_robot_DB_FIELD                                          // ��Ѫ�����ݿ��ֶ�ö��
{
    VAMPIRE_DB_robot_FIELD_ID,                       // "robot, id"                       �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_NAME,                     // "robot, name"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_OWNER_TYPE,               // "robot, owner_type"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_OWNER_ID,                 // "robot, owner_id"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_PLAYER_ID,                // "robot, player_id"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_TYPE,                     // "robot, type"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_EXP,                      // "robot, exp"                      �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_LEVEL,                    // "robot, level"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_LIFE,                     // "robot, life"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_POSITION,                 // "robot, position"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_COLOR,                    // "robot, color"                    �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_REBORN_CNT,               // "robot, reborn_cnt"               �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_NUMBER,                   // "robot, number"                   �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL1,              // "robot, guardskill1"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL2,              // "robot, guardskill2"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL3,              // "robot, guardskill3"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL4,              // "robot, guardskill4"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_EVENT_REC_BIN,            // "robot, event_rec_bin"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_NATIVE_PLACE,             // "robot, native_place"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_WEAPON_SELECT,            // "robot, weapon_select"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_EATHERUPLEV_DATE,         // "robot, eatheruplev_date"         �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_MAINSKILL_DATA,           // "robot, mainskill_data"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL5,              // "robot, guardskill5"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL6,              // "robot, guardskill6"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL7,              // "robot, guardskill7"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_GUARDSKILL8,              // "robot, guardskill8"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_FACTION,                  // "robot, faction"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_MODEL_LEV,                // "robot, Model_lev"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_METE_LEV,                 // "robot, Mete_lev"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_METE_ROBOTTYPE,           // "robot, Mete_RobotType"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_VALUE_WEAPON,             // "robot, value_weapon"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_VALUE_ARMET,              // "robot, value_armet"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_VALUE_ARMOR,              // "robot, value_armor"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_VALUE_BRACELET,           // "robot, value_bracelet"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_VALUE_NECKLACE,           // "robot, value_necklace"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_VALUE_SHOES,              // "robot, value_shoes"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_ACTIVITY_DATE,            // "robot, activity_date"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_EVENT_REC_MET,            // "robot, event_rec_met"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_SPECIALFLAG,              // "robot, specialflag"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_CHK_SUM,                  // "robot, chk_sum"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_QI,                       // "robot, qi"                       �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_QIUSAGE,                  // "robot, qiusage"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_HAIR,                     // "robot, Hair"                     �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_DELETE_STATE,             // "robot, Delete_state"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_ABILITY_LIMIT1,           // "robot, ability_limit1"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_ABILITY_LIMIT2,           // "robot, ability_limit2"           �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_UPGRADETIME,              // "robot, Upgradetime"              �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_UPGRADE_TIMES,            // "robot, Upgrade_times"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_CONTRACT_TIME,            // "robot, contract_time"            �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_DIALECT,                  // "robot, Dialect"                  �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_LOOKFACE,                 // "robot, Lookface"                 �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_SYNDICATE,                // "robot, syndicate"                �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_RELATIONSHIP,             // "robot, relationship"             �ֶ�,   ��ʾ:
	VAMPIRE_DB_robot_FIELD_IDENTIFYED,               // �Ƿ�ᶨ����!
}; //VAMPIRE_robot_DB_FIELD

enum PROFESSION_SORT		//��Ѫ��ְҵ���� 09-12-22
{
	PROFESSION_NONE,
	PROFESSION_KNIGHT,		//ʥ��ʿ
	PROFESSION_PALADIN,		//����
	PROFESSION_RABBI,		//��ʦ
	PROFESSION_FIGHTER,		//սʿ
};

enum 
{
	GunShootSpecialEffect_Block     = 1, //--��
	GunShootSpecialEffect_Bingo     = 2, //--���� 
	GunShootSpecialEffect_HeadShoot = 3, //--��ͷ
	GunShootSpecialEffect_Limb      = 4, //--��֫
	GunShootSpecialEffect_Suppress  = 5, //--ѹ��
    GunShootSpecialEffect_UnderShoot= 6, //--δ����
	GunShootSpecialEffect_BackOff   = 8, //--����
};
enum
{
	Attack_Effect_HeadShoot		= 1		,//--��ͷ
	Attack_Effect_Limb			= 2		,//--��֫
	Attack_Effect_Block			= 3		,//--��
	Attack_Effect_Bingo			= 4		,//--����
	Attack_Effect_Suppress		= 5		,//--ѹ��
	Attack_Effect_UnderShoot	= 6		,//--δ����
	Attack_Effect_ShootGround	= 7		,//--���е���
	Attack_Effect_Die			= 8		,//--��������
	Attack_Effect_Stiff			= 9		,//--��ֱ
	Attack_Effect_KickBack		= 10	,//--����
	Attack_Effect_KickDown		= 11	,//--����
	Attack_Effect_KickFlyAway	= 12	,//--����
    Attack_Effect_SkillMove		= 13	,//--����λ��
};


enum EFFECT_MODE_TYPE	//���16��
{
	EFFECT_MODE_NONE				    = 0x00,	// ��
	EFFECT_MODE_HEADSHOOT				= 0x01,	// ��ͷ
	EFFECT_MODE_LIMB				    = 0x02,	// ��֫
	EFFECT_MODE_BLOCK				    = 0x04,	// ��
	EFFECT_MODE_HIT				        = 0x08,	// ���� 
	EFFECT_MODE_SUPPRESS      		    = 0x10,	// ѹ��(��ֱ)
	EFFECT_MODE_UNDERHIT			    = 0x20,	// δ����
	EFFECT_MODE_BACK_ABSOLUTE_POSITION  = 0x40,	// ����
	EFFECT_MODE_DIE					    = 0x80,	// ��������
	EFFECT_MODE_KICKBACK				= 0x0100,	//����
	EFFECT_MODE_KICKDOWN				= 0x0200,	//����
	EFFECT_MODE_KICKFLYAWAY				= 0x0400,	//����
	EFFECT_MODE_SKILLMOVE				= 0x0800,	//����λ��
};


enum QUEST_DATA
{
	QUEST_DATA_ID,
	QUEST_DATA_IDUSER,
	QUEST_DATA_QUEST_ID,
	QUSET_DATA_COMPLETE_FLAG,
	QUEST_DATA_NOTIFY_FLAG,
	QUEST_DATA_DATA1, 
	QUEST_DATA_DATA2,
	QUEST_DATA_DATA3,
	QUEST_DATA_DATA4,
	QUEST_DATA_DATA5,
	QUEST_DATA_DATA6,
	QUEST_DATA_DATA7,
	QUEST_DATA_REQURE_TIME
};

enum MAGIC_ACTIVITY_TYPE
{
	MAGIC_ACTIVITY_NONE,
	MAGIC_ACTIVITY_INITIATIVE,
	MAGIC_ACTIVITY_PASSIVE,
	MAGIC_ACTIVITY_AUXILIARY,
};

enum MONSTER_CANBECATCH_FLAG
{
	MONSTER_CANBECATCH_NONE = 0,       // ��
	MONSTER_CANBECATCH_CATCH = 1,       // �ܱ���׽
	MONSTER_CONVOYNPC = 10,      // �������͵�NPC
};

enum
{
	MSG_VTIME_DAY = 3,   // ����
	MSG_VTIME_NIGHT,    // ҹ��
};

// enum MONSTER_PART_TYPE	//����֫�嶨��
// {
// 	MONSTER_PART_ERROR,
// 	MONSTER_PART_HAND_LEFT		= 0x1 << 0,
// 	MONSTER_PART_HAND_RIGHT		= 0x1 << 1,
// 	MONSTER_PART_FOOT_LEFT		= 0x1 << 2,
// 	MONSTER_PART_FOOT_RIGHT		= 0x1 << 3,
// 	MONSTER_PART_BODY_UPSIDE	= 0x1 << 4,
// 	MONSTER_PART_BODY_DOWNSIDE	= 0x1 << 5,
// };

// by xuxb: ��Ҫʹ��MONSTER_PART_TYPE, ʹ�����³���
enum
{
	BODYTYPE_PERFECT          = 0,             // �������
	BODYTYPE_LACK_HAND        = 0x1 << 0,      // ȱ��
	BODYTYPE_LACK_LEG         = 0x1 << 1,      // ȱ��
};

const int	ITEMPOSITION_BACKPACK	= ITEMPOS_BACKPACK;
const int	ITEMPOSITION_EQUIPBEGIN		= 1;
//const int	ITEMPOSITION_HELMET		= 1;
//const int	ITEMPOSITION_NECKLACE	= 2;
const int	ITEMPOSITION_ARMOR		= 3;
const int	ITEMPOSITION_WEAPONR	= ITEMPOS_HAND;
const int	ITEMPOSITION_WEAPONL	= ITEMPOS_SHIELD;
//const int	ITEMPOSITION_RINGR		= 6;
//const int	ITEMPOSITION_RINGL		= 7;
const int	ITEMPOSITION_TALISMAN	= 7;
//const int	ITEMPOSITION_SHOES		= 8;
const int	ITEMPOSITION_OVERCOAT	= 9;
const int	ITEMPOSITION_INCREASE_DMG_ARTIFACT	= 10;	// ���˺��ı���λ��
const int	ITEMPOSITION_DECREASE_DMG_ARTIFACT	= 11;	// ���˺��ı���λ��
const int	ITEMPOSITION_EQUIPEND	= ITEMPOS_EQUIPEND;

//Dota����
enum ERESISTANCE       
{
	RESISTANCE_ATTACK					= 0,    //�������仯
	RESISTANCE_MAGIC_ARMOR       		= 1,    //ħ�����Է����Ա仯
	RESISTANCEDISPLACE                  = 2,
	RESISTANCE_INC_MAXLIFE             	= 3,    //��������仯
	RESISTANCE_INC_LIFE             	= 4,    //��ǰ�����仯
	RESISTANCE_DAMAGE_MODULE_MULTIPLE	= 5,    //�˺�ϵ�������仯
	RESISTANCE_MOVE_SPEED		        = 6,	//�ƶ��ٶ�
	RESISTANCE_BAT_MULTIPLE		        = 7,	//�����ٶ�
	RESISTANCE_BAT_HIT_MULTIPLE         = 8,	//���б����仯
	RESISTANCE_RESTORE_MANA				= 9,	//ħ���ָ��ٶ�
	RESISTANCE_RESTORE_MANA_MULTIPLE	= 10,	//ħ���ָ��ٶȱ���
	RESISTANCE_RESTORE_HEALTH	        = 11,	//�����ָ��ٶ�
	RESISTANCE_ATTACK_MULTIPLE          = 12,   //�����������仯
	RESISTANCE_MOVE_SPEED_MULTIPLE      = 13,   // �ƶ��ٶȱ����仯
	RESISTANCE_AROM_INC                 = 14,   //�������ӻ��߼��ٵ���ֵ
	RESISTANCE_AROM_MULTIPLE            = 15,   //���ױ����仯
	//RESISTANCE_END	                    = 16,  //RESISTANCEö��ֵ������[0,15]�ڡ��� UNIT_FILED_RESISTANCETYPE1

	//��չ 
	RESISTANCE_DAMAGE_CONTAINER         = 48,   //�˺��ĵ�����
	RESISTANCE_VAMPIRE_MUL              = 49,   //��Ѫ
	RESISTANCE_ATTACK_MODULE	        = 50,    //�����˺�ϵ���仯
    RESISTANCE_MAGIC_EFFECT             = 51,   //ħ��Ч��
    RESISTANCE_INC_MAXMANA              = 52,   //���ħ��ֵ
    RESISTANCE_INC_JOUK                 = 53,   //����
    RESISTANCE_Dedicated_IBS            = 54,   //רע�����ٶȰٷֱ�
    RESISTANCE_MAXLIFT_TO_ATTACK        = 55,   //�������ת��Ϊ�������ٷֱ�
    //RESISTANCE_IBS	                    = 56,    //�����ٶ�
    RESISTANCE_MOVE_SPEED_TEMP	        = 57,    //�ƶ��ٶ���ʱֵ 

    RESISTANCE_MAGIC_PROTECT	        = 65,    //ħ������
    RESISTANCE_NORMAL_PROTECT	        = 66,    //��ͨ����
    RESISTANCE_ALL_PROTECT	            = 67,    //����
    RESISTANCE_LINEARITY_MAGIC_ARMOR    = 68,    //ħ���������Ա仯

	RESISTANCE_MAGIC_ATTACK             = 69,    //��������
	RESISTANCE_ARMOR_THROUGH_INC        = 70,    //�����״�͸ ���Ƽף�
	RESISTANCE_ARMOR_THROUGH_MULTIPLE   = 71,    //�����״�͸�ٷֱ� ���Ƽף�
	RESISTANCE_MAGICARMOR_THROUGH_INC        = 72,    //ħ�����״�͸ ���Ƽף�
	RESISTANCE_MAGICARMOR_THROUGH_MULTIPLE   = 73,    //ħ�����״�͸�ٷֱ� ���Ƽף�

	RESISTANCE_ALL_PROTECT_MODULE       = 74,    //���ܸ��ݷ��˵�����ϵ��
    RESISTANCE_MONEY_RATE_SOLDIER       = 75,    //��ұ���(ɱС��)
	RESISTANCE_REBORN_TIME_RATE         = 76,    //����ʱ�䱶��
	RESISTANCE_MONEY_RATE_NEUTRAL       = 77,    //��ұ���(ɱҰ��)

	RESISTANCE_CRIT_RATE          = 78,    //������
	RESISTANCE_CRIT_MODULUS       = 79,    //��������
	RESISTANCE_MAGIC_VAMPIRE_MUL  = 80,    //������Ѫ��
	RESISTANCE_BRAIN_TO_MAGICATTACK_RATE=81,//����ת��ǿ��
	RESISTANCE_DEL_DAMAGE         = 82,    //�ֿ��˺�
    RESISTANCE_DEC_COOLDOWN       = 83,    //��cd״̬
    RESISTANCE_BRAIN              = 84,    //����

	RESISTANCE_SPLASH             = 98,
    RESISTANCE_AGILITY            = 99,    //����
    RESISTANCE_POWER              = 100,    //����
	RESISTANCE_All_DAMAGE_JOUK    = 101,   //���������˺�

	RESISTANCE_BEKILL_EXTRA_MONEY = 102,    
	RESISTANCE_BESEC_EXTRA_MONEY  = 103,   
	RESISTANCE_FORBID_ADD_HEALTH  = 104,  //���ܻ�Ѫ
	RESISTANCE_DEL_LONGRANGE_DAMAGE = 105,    //�ֿ��˺�(Զ��)
	RESISTANCE_SECOND_ADD_MONEY		= 106,    //ÿ���ö�����
	RESISTANCE_REDUCE_ADD_HEALTH	= 107,    //���ٻָ�Ѫ��
	RESISTANCE_TARGET_HEALTH_JUDGE  = 108,  //Ԥ��Ѫ���ٷ� 

	RESISTANCE_ARMOR_IGNORE_MULTIPLE			= 122,						//��͸�����װٷֱ� �����ף�
	RESISTANCE_MAGICARMOR_IGNORE_MULTIPLE		= 123,						//��͸ħ�����װٷֱ� �����ף�
	RESISTANCE_MAIGIC_DAMAGE_MODULE_MULTIPLE	= 124,						//ħ���˺�ϵ�������仯
	RESISTANCE_PETADD_MOVE_SPEED				= 125,						//��踽���ٶ�ֵ
	RESISTANCE_PHYSICS_IMMUNE					= 126,						//��������
	RESISTANCE_BAT_COUNTED_RATE					= 127,						//���и���
	RESISTANCE_PHY_DAMAGE_MODULE_MULTIPLE		= 128,						//����ϵ�������仯
	RESISTANCE_PVE_ADD_HEALTH					= 129,							//����PVEҩˮ�ָ�Ѫ��
	RESISTANCE_TARGET_PHY_HEALTH_JUDGE			= 130,						//Ԥ��Ѫ���ٷ��������˺���
	RESISTANCE_ATTACK_DAMAGEDERATE_MODULUS		= 131,						//�����߼�������ϵ��
	RESISTANCE_DAMAGE_CONVERT					= 132,						// �˺�ת��

	RESISTANCE_DAMAGE_CONVERT_MANA				= 154,						// �˺�ת��Ϊ����
	RESISTANCE_DAMAGECONFIG_MODULUS				= 155,						// �����˺�Ӱ��ϵ��
	RESISTANCE_DAMAGE_CONVERT_MANA_POWERPECENT  = 156,						// �˺�ת��Ϊ������ת���ٷֱȣ���������ռ�����԰ٷֱȣ�
	RESISTANCE_SKILL_CPTIME_COEF				= 157,						// ����ǰҡʱ��ϵ��
	RESISTANCE_MAGIC_ATTACK_MULTIPLE			= 158,						// �������������仯
	RESISTANCE_END								= 164,						//RESISTANCEö��ֵ������[0,15] [48,58] [65,84] [98,108] [122,132][154,164]�ڡ��� UNIT_FILED_RESISTANCETYPE1

};

//��һ�õ��������ͣ����η�ͬ���Ͷ�Ӧ��
enum MONEY_RATE_TYPE
{
	MONEY_RATE_SOLDIER,	//ɱ��С������
	MONEY_RATE_NEUTRAL,	//ɱ��Ұ�ֵ���
};

enum BODYPART_TYPE  //֫���ƻ����Ͷ���
{
	BODYPART_ERROR,
	BODYPART_HEAD = 0x1 << 0,  //ͷ��
	BODYPART_HAND = 0x1 << 1,  //��
	BODYPART_FOOT = 0x1 << 2,  //��
	BODYPART_UPPERBODY = 0x1 << 3,  //�ϰ���
	BODYPART_LOWERBODY = 0x1 << 4,  //�°���
};

enum EDotaCamp
{
	eDotaCamp_Sentinel = 0,	//
	eDotaCamp_Scourge = 1,	//
	eDotaCamp_Judgement = 2,	//
	eDotaCamp_Neutrality = 3,	// ����
	eDotaCamp_Max					// ��Ч��Ӫ
};

enum
{
    ONEVIPADDFRIENDCOUNT   = 5,
    TWOVIPADDFRIENDCOUNT   = 25,
    THREEVIPADDFRIENDCOUNT = 35,
    FOURVIPADDFRIENDCOUNT  = 45,
    FIVEVIPADDFRIENDCOUNT  = 55,
    SIXVIPADDFRIENDCOUNT   = 75,
};

enum RANDDROP_KIND
{
    RANDDROP_WHITE = 0,
    RANDDROP_RED   = 1,
    RANDDROP_BLACK = 2,
};

enum USER_EMOTIONAL_EXPREESION_TYPE	//��ұ������Ͷ���.ϲ��ŭ����˼�������־�
{
	USER_EMOTIONAL_EXPREESION_NULL,
	USER_EMOTIONAL_EXPREESION_HAPPY,	//ϲ
	USER_EMOTIONAL_EXPREESION_ANGER,	//ŭ
	USER_EMOTIONAL_EXPREESION_WORRY,	//��˼
	USER_EMOTIONAL_EXPREESION_SAD,		//��
	USER_EMOTIONAL_EXPREESION_TERRIFIED,	//�־�
};

enum ATK_TYPE			 //  ��������
{
	ATK_TYPE_SHORT	= 1, //	 ���ֶ�ֵΪ1��ʾ����������		
	ATK_TYPE_FAR	= 2, //	 ���ֶ�ֵΪ2��ʾԶ�̹�������	
};


///////////////////////////////////////////////////////////////////
//Dota��Ŀ����

enum CREATURE_ADDITIVE_ATTR_TYPE
{
	CREATURE_ADDITIVE_ATTR_GEN_OWNER	= 1 << 0,		//��Ӫ�ȣ���������ж϶�Ӧ��ˢ�ֿ��ƶ���
	CREATURE_ADDITIVE_ATTR_SOLDIERS	    = 1 << 1,		//С��
	CREATURE_ADDITIVE_ATTR_EMPLACEMENT	= 1 << 2,		//��̨
	CREATURE_ADDITIVE_ATTR_NEUTRAL		= 1 << 3,		//Ұ��
	CREATURE_ADDITIVE_ATTR_ALTAR		= 1 << 4,		//��̳
};

enum EVALUATE
{
    EVALUATE_MVP            = 1 << 0,
    EVALUATE_PODI           = 1 << 1,
    EVALUATE_PIAN_JIANG     = 1 << 2,
    EVALUATE_YING_LING      = 1 << 3,
    EVALUATE_DEAD           = 1 << 4,
    EVALUATE_PO_YING        = 1 << 5,
    EVALUATE_WEALTHY        = 1 << 6,
	EVALUATE_DA_HENG		= 1 << 7,
};

enum TALENTDATA
{
	TALENTDATA_ID,
	TALENTDATA_TALENT,
	TALENTDATA_TYPE,
	TALENTDATA_PARAM,
};

enum
{
    Result_Win      = 0,			//ʤ��
    Result_Fail     = 1,			//ʧ��
    Result_About    = 2,			//����
    Result_AboutEx  = 3,			//����
	Result_WinEx    = 4,			// �Ƶ��Է�����ʤ��
	Result_FailEx   = 5,			// �Ƶ��Է�����ʧ��
	Result_Punish   = 6,			// �ͷ�
	Result_ReturnLadder  = 7,		// ��������
	Result_SingleWin = 8,			// ���˷���
	Result_Negative  = 9,			// ��������
	Result_WaiGua = 10,				// ��⵽���
	Result_Punish_DECSCORE   = 11,  //ban��ƥ������ �۷�
};

enum LP_ITEM_TYPE_DATA
{
	LP_ITEM_TYPE_ID			= 0,
	LP_ITEM_TYPE_NEED_SOUL,
	LP_ITEM_TYPE_EFFECT_MAP,
};

enum PVE_PLACE_HORNOR
{
	PVE_PLACE_HORNOR_ID = 0,
	PVE_PLACE_HORNOR_MAP_ID,
	PVE_PLACE_HORNOR_LEVEL,
	PVE_PLACE_HORNOR_LEVEL_RATE,
	PVE_PLACE_HORNOR_RESULT,
	PVE_PLACE_HORNOR_RESULT_RATE,
	PVE_PLACE_HORNOR_UP,
	PVE_PLACE_HORNOR_LOW,
	PVE_PLACE_HORNOR_HORNOR,
};

enum PVE_EVENT_POINT
{
	PVE_EVENT_POINT_ID = 0,
	PVE_EVENT_POINT_MAP_ID,
	PVE_EVENT_POINT_UP_SCORE,
	PVE_EVENT_POINT_LOW_SCORE,
	PVE_EVENT_POINT_TYPE,
	PVE_EVENT_POINT_POINT,
};

enum PVE_HORNOR_CONF
{
	PVE_HORNOR_CONF_ID = 0,
	PVE_HORNOR_CONF_MAP_ID,
	PVE_HORNOR_CONF_UP_SCORE,
	PVE_HORNOR_CONF_LOW_SCORE,
	PVE_HORNOR_CONF_POINT,
	PVE_HORNOR_CONF_SEC_POINT,
};

enum EHornorType
{
	eHornorType_None,
	eHornorType_Kill3,
	eHornorType_Kill4,
	eHornorType_Kill5,
	eHornorType_Kill6,
	eHornorType_Kill7,
	eHornorType_Kill8,
	eHornorType_Kill9,
	eHornorType_Kill10,
};

enum PVE_MAP_ATTR_DATA
{
	PVE_MAP_ATTR_MAP_ID = 0,	    
	PVE_MAP_ATTR_MIN_ATK,	  
	PVE_MAP_ATTR_MAX_ATK,	  
	PVE_MAP_ATTR_DEFENSE,	  
	PVE_MAP_ATTR_LIFE,			
	PVE_MAP_ATTR_MANA,			
	PVE_MAP_ATTR_LIFE_REGEN,
	PVE_MAP_ATTR_MANA_REGEN,
	PVE_MAP_ATTR_ATK_SPD,		
	PVE_MAP_ATTR_HIT,				
	PVE_MAP_ATTR_PHY_PASS,	
	PVE_MAP_ATTR_CRIT,			
	PVE_MAP_ATTR_CRIT_RES,	
	PVE_MAP_ATTR_PHY_SUCK,	
	PVE_MAP_ATTR_SPELL,			
	PVE_MAP_ATTR_SPE_PASS,	
	PVE_MAP_ATTR_SPE_SUCK,	
	PVE_MAP_ATTR_SPE_CD,		
	PVE_MAP_ATTR_SPE_RES,		
	PVE_MAP_ATTR_DUCK,		
	PVE_MAP_ATTR_POWER,		
	PVE_MAP_ATTR_AGILE,	
	PVE_MAP_ATTR_INTEL,	
	PVE_MAP_ATTR_MOVE_SPD,		
	PVE_MAP_ATTR_MAX_GENCOUNT,	
	PVE_MAP_ATTR_MAX_DAMAGE,
}; 

// Dota��ͼ
enum EDotaMap
{
	eDotaMap_None				= 0,
	eDotaMap_Fresh				= 2,		// ����
	eDotaMap_Strife				= 5,		// ����
    eDotaMap_Strife10v10		= 6,		// 10v10����
	eDotaMap_Battle				= 7,		// ��ս
	eDotaMap_SiFang				= 8,		// �ķ�
    eDotaMap_Alaxi				= 30,		// �ķ�
	eDotaMap_BattleChaunt		= 31,		// ս��
	eDotaMap_NationWar			= 32,		// ��ս
	eDotaMap_PVE_Map1			= 300,		// PVE
	eDotaMap_PVE_Map2			= 301,
	eDotaMap_PVE_Map3			= 302,
	eDotaMap_PVE_Map4			= 303,
	eDotaMap_PVE_Map5			= 304,
	eDotaMap_PVE_Map6			= 305,		// ��Ԩ��������

	eDotaMap_PVE_Map11			= 310,                          // ����1
	eDotaMap_PVE_Map12			= 311,                          // ����2
	eDotaMap_PVE_Map13			= 312,                          // ����3
	eDotaMap_PVE_Map14			= 313,                          // ����4
	eDotaMap_PVE_Map15			= 314,                          // ����5
	eDotaMap_NianMonster		= 315,                          // ���޸���
	eDotaMap_FinallyTussle		= 316,                          // �ػ���ʥ������ �ռ�����
	eDotaMap_PVE_WATCH_MAP1		= 317,                          // �ػ���ʥ�� ��ͼ1
	eDotaMap_PVE_WATCH_MAP2		= 318,                          // �ػ���ʥ�� ��ͼ2
	eDotaMap_PVE_WATCH_MAP3		= 319,                          // �ػ���ʥ�� ��ͼ3
	eDotaMap_PVE_WATCH_MAP4		= 320,                          // �ػ���ʥ�� ��ͼ4
	eDotaMap_PVE_WATCH_MAP5		= 321,                          // �ػ���ʥ�� ��ͼ5
	eDotaMap_PVE_WATCH_MAP6		= 322,                          // �ػ���ʥ�� ��ͼ6
	eDotaMap_PVE_WATCH_MAP7		= 323,                          // �ػ���ʥ�� ��ͼ7
	eDotaMap_PVE_WATCH_MAP8		= 324,                          // �ػ���ʥ�� ��ͼ8
	eDotaMap_PVE_WATCH_MAP9		= 325,                          // �ػ���ʥ�� ��ͼ9
	eDotaMap_PVE_WATCH_MAP10	= 326,                          // �ػ���ʥ�� ��ͼ10
	eDotaMap_PVE_WATCH_MAP11	= 327,                          // �ػ���ʥ�� ��ͼ11
	eDotaMap_PVE_WATCH_MAP12	= 328,                          // �ػ���ʥ�� ��ͼ12
	eDotaMap_PVE_WATCH_MAP13	= 329,                          // �ػ���ʥ�� ��ͼ13
	eDotaMap_PVE_WATCH_MAP14	= 330,                          // �ػ���ʥ�� ��ͼ14
	eDotaMap_PVE_WATCH_MAP15	= 331,                          // �ػ���ʥ�� ��ͼ15
	eDotaMap_PVE_WATCH_MAP16	= 332,                          // �ػ���ʥ�� ��ͼ16
	eDotaMap_PVE_BABELTOWER		= 340,							// ͨ����

	eDotaMap_PVE_10V10_War = 500,                       // PVE10V10
};

enum EPhoneMap
{
    ePhoneMap_Single1v1 = 5,                          //�����еĵ�·��ͼ1v1
    ePhoneMap_Single3v3 = 9,                          //�����еĵ�·��ͼ3v3 �Լ����䵥·
    ePhoneMap_Three5v5 = 13,                          //�����е���·��ͼ5v5 �Լ�������·
    ePhoneMap_RookieStep1 = 21,                       //��������������1����·
    ePhoneMap_RookieStep2 = 23,                       //��������������2����·
};

enum EHeroInitLevel
{
    eHeroInitLevel1 = 1,                          //��ʼ1��
    eHeroInitLevel3 = 3,                          //��ʼ3��
};

#define IS_PVE_MAP( mapId )                 ( mapId == eDotaMap_PVE_Map1 || mapId == eDotaMap_PVE_Map2 || mapId == eDotaMap_PVE_Map3 || mapId == eDotaMap_PVE_Map4 || mapId == eDotaMap_PVE_Map5 || mapId == eDotaMap_PVE_Map6 || mapId == eDotaMap_PVE_Map11 || mapId == eDotaMap_PVE_Map12 || mapId == eDotaMap_PVE_Map13 || mapId == eDotaMap_PVE_Map14 || mapId == eDotaMap_PVE_Map15 || mapId == eDotaMap_NianMonster || mapId == eDotaMap_FinallyTussle/* || mapId == eDotaMap_NationWar*/ || (mapId >= eDotaMap_PVE_WATCH_MAP1 && mapId <= eDotaMap_PVE_WATCH_MAP16) || mapId == eDotaMap_PVE_BABELTOWER)
#define USE_PVE_HERO( mapId )				( mapId == eDotaMap_PVE_10V10_War || mapId == eDotaMap_Alaxi || mapId == eDotaMap_BattleChaunt/* || mapId == eDotaMap_NationWar*/ )
#define IS_PVE_BATTLECHAUNT_MAP( mapId )    ( mapId == eDotaMap_BattleChaunt)
#define IS_PVE_FINALLYTUSSLE_MAP( mapId )   ( mapId == eDotaMap_FinallyTussle)
#define IS_PVE_NATIONWAR( mapId )			( mapId == eDotaMap_NationWar)
#define IS_PVE_WATCH_MAP( mapId )			( mapId >= eDotaMap_PVE_WATCH_MAP1 && mapId <= eDotaMap_PVE_WATCH_MAP16 )
#define IS_PVE_LEVELUP_MAP( mapId )         IS_PVE_WATCH_MAP ( mapId )
#define IS_PVE_BABELTOWER_MAP( mapId )      ( mapId == eDotaMap_PVE_BABELTOWER)

#define LOOKTYPEID_WATCHSOLDIER1		81001			// �ػ�������lookID
#define LOOKTYPEID_WATCHSOLDIER2		99001			// �ػ��޾�β��lookID
#define LOOKTYPEID_WATCHSOLDIER3		100001			// �ػ��޺���lookID
#define LOOKTYPEID_HANDBANNERSOLDIER1	91001			// �����Ϳ���С��lookID
#define LOOKTYPEID_HANDBANNERSOLDIER2	220001			// �����Ϳ���С��lookID
#define LOOKTYPEID_HANDBANNERSOLDIER3	221001			// �����Ϳ���С��lookID
#define ISHANDBANNERSOLDIER( lookId )				( lookId == LOOKTYPEID_HANDBANNERSOLDIER1 || lookId == LOOKTYPEID_HANDBANNERSOLDIER2 || lookId == LOOKTYPEID_HANDBANNERSOLDIER3)
#define ISWATCHSOLDIER( lookId )					( lookId == LOOKTYPEID_WATCHSOLDIER1 || lookId == LOOKTYPEID_WATCHSOLDIER2 || lookId == LOOKTYPEID_WATCHSOLDIER3)

const int WATCH_MAP_MAX_ENERGY = 1500;					// �����������������ֵ

/// ģʽ��1λ����ͼ��3λ��������2λ
enum EGameMode
{
	eGameMode_None        = 0,                   // 
	eGameMode_All         = 10000000,            // ����ģʽ
	eGameMode_Leisure     = 1,                   // ƥ��
	eGameMode_Match       = 2,                   // ����
	eGameMode_AI          = 3,                   // �˻�
	eGameMode_Fight       = 4,                   // ����
	eGameMode_Strife      = 101,                 // ����ʥ̳
	eGameMode_Battle      = 102,                 // ��ս֮��
	eGameMode_10v10       = 110,                 // 10v10
	eGameMode_3V3         = 11,                  // 3V3
	eGameMode_5V5         = 12,                  // 5V5
	eGameMode_Leisure_Strife = 1101,             // ƥ�����
	eGameMode_Leisure_Battle = 1102,             // ƥ���ս
	eGameMode_AILeisure_Strife = 1103,           // �˻�ƥ�����
	eGameMode_Match_Strife   = 2101,             // ���ݷ���
	eGameMode_Match_Battle   = 2102,             // ���ݾ�ս
	eGameMode_Fight_Strife   = 4101,             // ��������
	eGameMode_Fight_Battle   = 4102,             // ������ս
	eGameMode_Match_Strife_3V3 = 110111,         // ���ݷ���3V3
	eGameMode_Match_Strife_5V5 = 110112,         // ���ݷ���5V5
	eGameMode_Match_Battle_3V3 = 110211,         // ���ݾ�ս3V3
	eGameMode_Match_Battle_5V5 = 110212,         // ���ݾ�ս5V5
};

#define FOR_ALL_BEG( TDataMapIt, datas )                                                        \
{                                                                                               \
	uint32 loopCount    = 0;                                                                    \
	TDataMapIt it       = datas.begin();                                                        \
	TDataMapIt itEnd    = datas.end();                                                          \
	for( ; it != itEnd; ++it )                                                                  \
	{																							\
		DEAD_LOOP_BREAK( loopCount, 10000 );


#define FOR_ALL_END                                                                             \
	}                                                                                           \
}

enum INSTANCETYPEDATA               // �������ͱ�
{
    INSTANCETYPEDATA_INSTANCE_ID = 0,   // �������AABBCCDDEE��AA��ʾ��һ�����࣬BB��ʾ�ڶ�������
    // CC��ʾ���������࣬DD��ʾ���ĸ����࣬EE��ʾ�������ĸ������
    INSTANCETYPEDATA_NAME,          // ��������
    INSTANCETYPEDATA_PLAYER_MAX,    // ���븱����������
    INSTANCETYPEDATA_PLAYER_MIN,    // ���븱����������
    INSTANCETYPEDATA_EXPEND_STA,    // ���븱�����ľ���
    INSTANCETYPEDATA_LEV_MIN,       // ���븱����͵ȼ�
    INSTANCETYPEDATA_LEV_MAX,       // ���븱����ߵȼ�
    INSTANCETYPEDATA_REQ_TASK,      // ����ǰ������
    INSTANCETYPEDATA_REQ_INSTANCE1, // ǰ�ø���1
    INSTANCETYPEDATA_REQ_INSTANCE2, // ǰ�ø���2
    INSTANCETYPEDATA_REQ_INSTANCE3, // ǰ�ø���3
    INSTANCETYPEDATA_OPENTIME_FLAG, // ������������INSTANCEOPEN_CYC
    INSTANCETYPEDATA_START_TIME,    // ��������ʱ��
    INSTANCETYPEDATA_CLOSE_TIME,    // �����ر�ʱ��
    INSTANCETYPEDATA_LIMIT,         // �������Ʒ�ΧINSTANCEENTER_LIMIT
    INSTANCETYPEDATA_STAY_TIME,     // ��������ʱ�䣨0��ʾ��ʱ�����ƣ�
    INSTANCETYPEDATA_TOTAL_REBORN,  // ������������������������ҵ��������������0��ʾ���޴θ���
    INSTANCETYPEDATA_PERSONAL_REBORN, // �������������������е�����ҵ��������������0��ʾ���޴θ���
    INSTANCETYPEDATA_BEGIN_SCRIPT,  // ��������ʱ�����Ľű�
    INSTANCETYPEDATA_END_SCRIPT,    // ����ͨ��ʱ�����Ľű�
    INSTANCETYPEDATA_RECORD_TIME,   // ������¼ʱ�䣬0��ʾ�ø�����ʱ��Ҫ�󣬷�0��ʾ�ٴ˼�¼ʱ�����ǰ��ɵĸ����ܻ�ö��⽱��
};

enum INSTANCEPRIZEDATA              // ����������
{
    INSTANCEPRIZEDATA_INSTANCE_ID = 0, // �������ͱ��
    INSTANCEPRIZEDATA_MASTER_TASK,     // ��������������ɵĽ����ű�
    INSTANCEPRIZEDATA_LATERAL_TASK1, // ����֧������1��ɵĽ����ű�
    INSTANCEPRIZEDATA_LATERAL_TASK2, // ����֧������2��ɵĽ����ű�
    INSTANCEPRIZEDATA_LATERAL_TASK3, // ����֧������3��ɵĽ����ű�
    INSTANCEPRIZEDATA_LATERAL_TASK4, // ����֧������4��ɵĽ����ű�
    INSTANCEPRIZEDATA_LATERAL_TASK5, // ����֧������5��ɵĽ����ű�
    INSTANCEPRIZEDATA_TIME_LIMIT,   // �����ڼ�¼ʱ���ǰ��ɵõ��Ľ����ű�
    INSTANCEPRIZEDATA_ADDITIONAL_PRIZE0,
    INSTANCEPRIZEDATA_ADDITIONAL_PRIZE1,
    INSTANCEPRIZEDATA_ADDITIONAL_PRIZE2,
};

enum INSTANCEMAPTYPEDATA            // ������ͼ���ͱ�
{
    INSTANCEMAPTYPEDATA_ID = 0,      // ϵͳ���
    INSTANCEMAPTYPEDATA_INSTANCE_ID, // �������ͱ��
    INSTANCEMAPTYPEDATA_INSTANCE_MAPID, // ������ͼid
    INSTANCEMAPTYPEDATA_ENTER_X,    // ���븱������ŵ�x
    INSTANCEMAPTYPEDATA_ENTER_Y,    // ���븱������ŵ�y
    INSTANCEMAPTYPEDATA_MAPFLAG,    // ��ͼ���1Ϊ������ڵ�ͼ��0Ϊ�Ǹ�����ڵ�ͼ
};

enum STATISTIC_DATA
{
    STATISTICDATA_ID = 0,
    STATISTICDATA_PLAYERID,
    STATISTICDATA_EVENTTYPE,
    STATISTICDATA_DATA,
    STATISTICDATA_EVENTTIME,
    STATISTICDATA_OWNER_TYPE,
    STATISTICDATA_HERO_TYPE,
    STATISTICDATA_MONEY,
    STATISTICDATA_KILL_HERO_AMOUNT,
    STATISTICDATA_DEAD_AMOUNT,
    STATISTICDATA_SECONDAR_ATTACK_AMOUNT,
    STATISTICDATA_KILL_SOLDIERS_AMOUNT,//ɱ��С��
    STATISTICDATA_KILL_EMPACEMENT_AMOUNT,//ɱ����̨��
    STATISTICDATA_KILL_BARRACKS_AMOUNT,//ɱ����Ӫ��
    STATISTICDATA_KILL_NEUTRAL_AMOUNT,//ɱ����������
    STATISTICDATA_EXPORT_DAMAGE,
    STATISTICDATA_EXPORT_NORMAL_DAMAGE,
    STATISTICDATA_EXPORT_MAGIC_DAMAGE,
    STATISTICDATA_ENDURE_DAMAGE,
    STATISTICDATA_ENDURE_NORMAL_DAMAGE,
    STATISTICDATA_ENDURE_MAGIC_DAMAGE,
    STATISTICDATA_GAME_RESULT,
    STATISTICDATA_MAP,
    STATISTICDATA_HERO_MODE,
    STATISTICDATA_EQUIP_TYPE1,
    STATISTICDATA_EQUIP_TYPE2,
    STATISTICDATA_EQUIP_TYPE3,
    STATISTICDATA_EQUIP_TYPE4,
    STATISTICDATA_EQUIP_TYPE5,
    STATISTICDATA_EQUIP_TYPE6,
    STATISTICDATA_SOUL,							// ��Ϸ��ʹ�û�ʯ
    STATISTICDATA_EXPORT_BUILD_DAMAGE,			// ��������˺�
    STATISTICDATA_EXPORT_HERO_DAMAGE,			// ���Ӣ���˺�
    STATISTICDATA_PVE_HORNOR,					// ����
    STATISTICDATA_PVE_SEC_HORNOR,				// ��������
    STATISTICDATA_PVE_ALTAR_HORNOR,				// ��̳����
    STATISTICDATA_EXPORT_ALTAR_DAMGE,			// ��̳�˺�
    STATISTICDATA_PVE_ENERGY,					// ����
    STATISTICDATA_PVE_RESOURCE,					// ��Դ
    STATISTICDATA_PVE_WAR_LEV,					// ս���ȼ�
    STATISTICDATA_PVE_BANNER_HORNOR,			// ��������
    STATISTICDATA_MAX,							// ��Ч
};

// TODO::MILO 11/9/2015 BS��Ҳ��һ��HERO_TYPE������StructDef.h�� ���ڸĳ�DOTA_HERO_TYPE
enum HERO_TYPE				//Ӣ������ 
{
	HERO_NONE,
	HERO_POWER,             //����Ӣ��
	HERO_AGILITY,           //����Ӣ��
	HERO_BRAINS,            //����Ӣ��
};
//Dota��Ŀ����
///////////////////////////////////////////////////////////////////

#endif // end of define _GS_ENUM_DEFINE_H_

// -*- C++ -*-
// -*- C++ -*-

//=============================================================================
/**
 *  @file    ConstDef.h
 *
 *  $Id: ConstDef.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _TQ_CONST_DEFINE_H_
#define _TQ_CONST_DEFINE_H_

#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER > 1000

#include <limits.h>
#include "Types.h"

const int GLOBE_SESSION_ID = 0;

//�ͻ��˰汾�ţ����ڿͻ��˵����Ƿ�Ϸ��ж�
const uint32_t CLIENTVER = 170;  //��ͻ���ͬ���Ϳ���

const char szSYSTEM[] = "SYSTEM";
const char szTEAMMATES[] = "TEAMMATES";
const char szROOMMATES[] = "ROOMMATES";
const char szALLUSERES[] = "ALLUSERES";

const long _DYNAMIC_NPC_ID = 1000000;
const int SOCKET_NONE = -1;   // ��Ч��SOCKET����
const int BYTE_BITCOUNT = 8;  //һ���ֽ��ж���λ
// MoodDescribe
const int _MAX_MOODSIZE = 32;

//////////////////////////////////////////////////////////////////////
// type // from 0 --- 9999
const int _NPC_TASK = 0;
const int _NPC_WEAPON_SHOPKEEPER = 1;
const int _NPC_DEUL_PET = 2;
const int _NPC_DEUL_PET_COLOSSEUM = 3;
const int _NPC_DEUL_HERO = 4;
const int _NPC_GAMBLE = 5;
const int _NPC_DICE_TABLE = 6;
const int _NPC_CASINOMACHINE = 7;
const int _NPC_BLACKJACK = 8;
const int _NPC_FORGE_SHOPKEEPER = 100;
const int _NPC_MEDICINE_SHOPKEEPER = 101;
const int _NPC_JEWEL_SHOPKEEPER = 102;
const int _NPC_SYNOCCUPY = 200;  // ���ɿ�����
const int _NPC_PACKITEM = 201;
const int _NPC_PACKPET = 202;
const int _NPC_SYNMACKET = 203;  // �����г�����Ա
const int _NPC_FURNITURE = 300;
const int _NPC_BLOCKKEEPER = 1000;
const int _NPC_FAMILYKEEPER = 1001;

const int MAX_NPCDATA = 4;  // ����С��_MAX_NPCJOB

const int _MAX_NPCTASK = 8;
const int _MAX_NPCDATA = 4;  // ����С��_MAX_NPCTASK

//  ITEMDATA_MONOPOLY,
const uint32_t MONOPOLY_MASK = 1;  // ��ռ, ���ɽ���, �뿪������ʧ
const uint32_t STORAGE_MASK =
    1 << 1;  // �洢, ������ã����ܴ��뵽��Ʒ��, Ǭ����
const uint32_t DEAD_DROP_MASK =
    1 << 2;  // ����, ������ã�����һ�������, ��������װ��
const uint32_t BIND_MASK = 1 << 3;  // ��, ������ã�����һ���������

const uint32_t IDENT_MASK = 0x01;

const int MAGIC_NONE = 0;
const int GEM_NONE = 0;
const int GEM_HOLE = 255;

// add by zlong 2003-12-02
const int MAX_ADDITION_LEV = 12;    // ׷�ӵȼ����Ϊ12
const OBJID COMPOSE_STONE = 73000;  // ����ʯ��730001~730009

//////////////////////////////////////////////////////////////////////
const int ITEMREPAIR_PERCENT = 200;  // �����Ϊԭ�۵�200%
const int ITEMIDENT_PERCENT = 10;    // ������10%

const int NFORMALDAYS = 5;            // ����ת������
const int FORMALBUSINESSSTATE = 255;  // ��ʽ����״̬

// treasure
const OBJID TYPE_DRAGONBALL = 1088000;
const OBJID TYPE_SHOOTINGSTAR = 1088001;
const OBJID TYPE_DIVOICEITEM = 1088002;

const OBJID TYPE_SHOOTINGSTAR5 = 723268;
const OBJID TYPE_SHOOTINGSTAR10 = 720027;
const int NSHOOTINGSTAR5 = 5;
const int NSHOOTINGSTAR10 = 10;
// gems
const OBJID GEM_WPNEXP_LOW = 700051;
const OBJID GEM_WPNEXP_MID = 700052;
const OBJID GEM_WPNEXP_HGT = 700053;

const OBJID GEM_MGCEXP_LOW = 700061;
const OBJID GEM_MGCEXP_MID = 700062;
const OBJID GEM_MGCEXP_HGT = 700063;

const OBJID GEM_DECDMG_LOW = 700071;
const OBJID GEM_DECDMG_MID = 700072;
const OBJID GEM_DECDMG_HGT = 700073;
// ���˺���ʯ
const OBJID GEM_DMG_INC_LOW = 700101;
const OBJID GEM_DMG_INC_MID = 700102;
const OBJID GEM_DMG_INC_HGT = 700103;

// ���˺���ʯ
const OBJID GEM_DMG_DEC_LOW = 700121;
const OBJID GEM_DMG_DEC_MID = 700122;
const OBJID GEM_DMG_DEC_HGT = 700123;

const OBJID GEM_EXP_LOW = 700031;
const OBJID GEM_EXP_MID = 700032;
const OBJID GEM_EXP_HGT = 700033;

const OBJID GEM_DUR_LOW = 700041;
const OBJID GEM_DUR_MID = 700042;
const OBJID GEM_DUR_HGT = 700043;

const OBJID GEM_DMG_LOW = 700011;
const OBJID GEM_DMG_MID = 700012;
const OBJID GEM_DMG_HGT = 700013;

const OBJID GEM_HIT_LOW = 700021;
const OBJID GEM_HIT_MID = 700022;
const OBJID GEM_HIT_HGT = 700023;

const OBJID GEM_MATK_LOW = 700001;
const OBJID GEM_MATK_MID = 700002;
const OBJID GEM_MATK_HGT = 700003;

const OBJID NORMAL_ARROW_TYPE = 1050000;  // normal arrow itemtype
const OBJID ARROW_SUBTYPE = 50;           // normal arrow subtype
const int MAX_USERITEMSIZE = 40;

const OBJID EXP_BALL = 723700;  // ����ֵ��, ���ڴ洢һ��Сʱ�ľ���

const OBJID CARD_FEE_POINT = 780000;   // game card for fee
const OBJID CARD_FEE_POINT2 = 780001;  // game card for fee
const OBJID CARD_FEE_POINT3 = 780002;  // game card for fee
const OBJID CARD_FEE_POINT4 = 780003;  // game card for fee

const OBJID ITEM_DROPAFTERDIE = 790000;  // ������һ��������Ʒ

// package
const OBJID ITEM_TREASUREPACK3 = 1100003;
const OBJID ITEM_TREASUREPACK6 = 1100006;
const OBJID ITEM_TREASUREPACK9 = 1100009;

const int INSTANCETYPE_BEGIN_ID = 100000000;  //����������ʼid

const int ITEMSORT_INVALID = -1;
const int ITEMSORT_EXPEND = 0;                  // �׺�Ʒ
const int ITEMSORT_HELMET = 1;                  // ͷ��
const int ITEMSORT_NECKLACE = 2;                // ����
const int ITEMSORT_ARMOR = 3;                   // ����
const int ITEMSORT_WEAPON1 = 4;                 // ��������
const int ITEMSORT_WEAPON2 = 5;                 // ˫������
const int ITEMSORT_SHIELD = 6;                  // ����
const int ITEMSORT_RING = 7;                    // ��ָ
const int ITEMSORT_SHOES = 8;                   // Ь��
const int ITEMSORT_OTHER = 9;                   // ����, ����ֱ��ʹ��
const int ITEMSORT_TALISMAN = 10;               // ����
const int ITEMSORT_OVERCOAT = 11;               // ����
const int ITEMSORT_INCREASE_DMG_ARTIFACT = 12;  // ���˺�����
const int ITEMSORT_DECREASE_DMG_ARTIFACT = 13;  // ���˺�����
const int ITEMSORT_HORSE = 20;                  // ����
//////////////////////////////////////////////////////////////////////
const int ITEMTYPE_INVALID = -1;      // �Ƿ�
const int ITEMTYPE_MEDICINE = 00000;  // ��ҩ
const int ITEMTYPE_POISON = 10000;    // ��ҩ
const int ITEMTYPE_DART = 20000;      // ����
const int ITEMTYPE_BOOK = 30000;      // ����
const int ITEMTYPE_NOTUSE = 40000;    // ����
const int ITEMTYPE_ARROW = 50000;     // ��ʸ
const int ITEMTYPE_SPELL = 60000;     // ������
const int ITEMTYPE_NOT_DIRECTUSE =
    70000;  // ������˫��ʹ�õģ���������Ʒ����ʯ��ľ�ĵ���Դ�࣬ǧλ�������ࣩ
const int ITEMTYPE_EX0 = 80000;  // ��չ0
const int ITEMTYPE_EX1 = 90000;  // ��չ1

//////////////////////////////////////////////////////////////////////
// item sort is ITEMSORT_OTHER, ʮ��λ����6λ��Ϊ7
const int ITEMTYPE_GEM = 00000;         // ��ʯ��Ʒ 70xxxx
const int ITEMTYPE_TASKITEM = 10000;    // ������Ʒ 71xxxx
const int ITEMTYPE_ACTIONITEM = 20000;  // Action��Ʒ 72xxxx
const int ITEMTYPE_COMPOSEGEM =
    30000;  // ������ʯ 73xxxx������׷�����������2λ��ʾ׷�ӵȼ�
const int ITEMTYPE_GAMECARD = 80000;  // �㿨���¿� 78xxxx
const int ITEMTYPE_DROPITEM = 90000;  // ��ɱ��һ��������Ʒ 79xxxx

//////////////////////////////////////////////////////////////////////
// 2003-01-13 10:36:24  ���
// Necklace type define
const int ITEMTYPE_NECKLACE = 00000;  // ����
const int ITEMTYPE_SACHET = 10000;    // ���
const int ITEMTYPE_AMULET = 20000;    // �����

// 2003-01-13 10:46:37  ���
// Ring type define
const int ITEMTYPE_RING = 00000;        // ��ָ
const int ITEMTYPE_THUMB_RING = 10000;  // ��ָ
const int ITEMTYPE_BANGLE = 20000;      // ����

// 2003-01-13 11:05:03  ���
// Singlehand Weapon define
const int SWEAPON_NONE = 00000;     // ����
const int SWEAPON_BLADE = 10000;    // ��
const int SWEAPON_AXE = 20000;      // ��
const int SWEAPON_HAMMER = 30000;   // ��
const int SWEAPON_HOOK = 40000;     // ��
const int SWEAPON_CLUB = 50000;     // ��/��
const int SWEAPON_SWORD = 60000;    // ��
const int SWEAPON_CRUTCH = 70000;   // ��
const int SWEAPON_SCOURGE = 80000;  // ��/�
const int SWEAPON_SHORT = 90000;    // �̱���
// add by zlong 2003-12-02
const int SWEAPON_MSWORD = 21000;  // ����

// Doublehand Weapon define
const int DWEAPON_BOW = 00000;      // ��
const int DWEAPON_BLADE = 10000;    // ��
const int DWEAPON_AXE = 20000;      // ��
const int DWEAPON_HAMMER = 30000;   // ��
const int DWEAPON_HOOK = 40000;     // ��
const int DWEAPON_STAFF = 50000;    // ��
const int DWEAPON_SHOVEL = 60000;   // ��
const int DWEAPON_HALBERD = 70000;  // �
const int DWEAPON_FORK = 80000;     // ��
const int DWEAPON_SPEAR = 90000;    // ǹ

//-----------------------------------------------------------------------------
const int _MAX_USERITEMSIZE = 40;
const int _MAX_ALLUSERITEMSIZE = _MAX_USERITEMSIZE + 11;  // 9: װ������
const int _MAX_USERFRIENDSIZE = 50;
const int _MAX_TRADE_BUDDY_SIZE = 20;
const int _MAX_REBIRTH_SKILL_NUM = 60;
const int USER_PACKAGE_SIZE = 20;  // �ֿ�������ٶ���
const int VIP_STORAGE_SIZE = 5 * 8;  // VIPר�òֿ�ռ��С
const int VIP_STORAGE_NPC_ID = 1015;  // VIPר�òֿ�NPC
const int TICK_SECS = 10;
const int USERDROPITEM_RANGE = 5;       // �Զ���
const int USERDROPITEM_RANGE2 = 9;      // �ֶ���
const int THROW_WEAPON_DROP_RANGE = 1;  // �����������ɵ���Ʒ�ķ�Χ
const int PILEMONEY_CHANGE = 5000;      // �����ֽ�䶯(��Ҫ��ʱ����)
const int _ADDITIONALPOINT_NUM = 3;     // ��1���Ӷ������Ե�
const int MAX_MENUTASKSIZE = 20;        // �˵�ϵͳ��"�ش�TASK"���������
const int MAX_PKLIMIT = 10000;          // PKֵ�������С����(���ؾ�)
const int SLOWHEALLIFE_MS = 1000;       // ��ҩ��Ѫ��������ȥ�ĺ�������
const int SLOWHEALLIFE_PERCENT =
    10;  // ÿ�γ�ҩ��Ѫtick��ʱ������СѪ�� = MaxLife/SLOWHEALLIFE_PERCENT
const int AUTOHEALLIFE_TIME = 10;       // ÿ��10���Զ���Ѫ1�Ρ�
const int AUTOHEALLIFE_EACHPERIOD = 6;  // ÿ�β�Ѫ6��
const int PK_DEC_TIME = 60;             // ����һ��pkֵ60��
const int VAMPIRE_DEC_TIME = 1;         //��ҷ���״̬ÿ�뽵��һ����Ѫֵ
const int DRAW_ANGEL_TIME = 30;         //��ȡ��ʹʱ����Ҫ�ڼ�������ʱ��
const int ANGEL_BREAK_OUT = 300;        //��ʹ����ʱ��
const int ANGEL_PERSIST_TIME = 60;      //��ʹ״̬����ʱ��
const int ANGEL_EXP_PER = 10;           //��ʹÿ�α�������õľ���ֵ
const int SKILL_FLY_ID = 900100;        //��ҷ��м���ID
const int TIME_TEAMPRC = 5;             // ������Ϣ�����ʱ��
const int DURABILITY_DEC_TIME = 5;      // ��ʱ�����ĵ�װ���;ö�
const int USER_ATTACK_SPEED = 800;      // ���ͽ�ֹ���Ƶ��
const int POISONDAMAGE_INTERVAL = 2;    // �ж�ÿ2����Ѫһ��
const int CRIME_KEEP_SECS = 15;         // ����ά��ʱ��
const int SYNCRIME_KEEP_SECS = 30;      // ���ɷ���ά��ʱ��
const int ARROW_FLY_ALT = 60;           // ��֧���и߶�
const int JUMP_ALT = 200;               // ������߸߶�
const int FLY_ALT = 100;                // �ɵ���߸߶�
const int PERCENT_DECDUR = 5;           // װ������ʧ�ܺ��;õļ���

const int PKVALUE_HALFKILL = 2;
const int PKVALUE_ONEKILL = 10;
const int PKVALUE_REDNAME = 30;
const int PKVALUE_BLACKNAME = 100;
const int PKVALUE_ENEMY = 5;
const int PKVALUE_SYN_ENEMY = 3;

const int CHANCE_MAKEHOLE_UPLEVEL = 1200;   // װ�����ȼ�ʱ�ĳ�������(1 / 1200)
const int CHANCE_MAKEHOLE_UPQUALITY = 300;  // װ����Ʒ��ʱ�ĳ�������(1 / 300)

const int SUPERMAN_KILLMONSTER_INCTIME = 1;  // ��˫״̬ÿɱһ������ļ�ʱ(S)
const int SUPERMAN_KILLMONSTER_TIMELIMIT = 120;  // ��˫״̬�ӳ���ʱ������(S)
const int TORNADO_KILLMONSTER_INCTIME = 1;      // ����״̬ÿɱһ������ļ�ʱ(S)
const int TORNADO_KILLMONSTER_TIMELIMIT = 120;  // ����״̬�ӳ���ʱ������(S)

const int MASK_CHANGELOOK =
    100000000;  // ����ʱLOCKFACE�����룬face=face + new_face*10000000
const int MAX_SIZEADD =
    2;  // ����SizeAdd������ħ������ķŴ�����(ע������ݲ�Ҫ̫��)

const int CHANGE_MONSTER_TIME = 500;  // ��������ʱ��

const int CHGMAP_LOCK_SECS = 10;            // �����ͼ��ı���ʱ��
const int SYNWAR_NOMONEY_DAMAGETIMES = 10;  // ����ûǮʱ���ӵ��˺�����
const int PICK_MORE_MONEY = 1000;           // ��Ǯ��ʱ����ACTION��Ϣ
const int SYNCHRO_SECS = 5;                 // ͬ����Ϣ5����ͬ��

const int VERIFY_DATA_SECS = 60 * 10;  // 10���Ӽ��һ������

const int ONLINE_TRAINING_INTERVAL = 60;   // ��������ÿ��������ʮ��������
const int CHECKBATTLEEFFECT_INTERVAL = 5;  // 5����һ��ս�����仯
const int CONTRIBUTE_INTERVAL = 60 * 5;    // 5���ӹ���һ�ξ���

const int STATUS_MAINTAINALLWAYS =
    86400;  // ״̬ά��ʱ����Ҫ����ΪΪ���ޣ���ô��ȡ24Сʱ��ʱ��

const int TEAM_ROLEPLAYING_INSTONE_SEC = 3000;  // �����ɫ��������ʱ��

const int WALLOW_INTERVAL = 1 * 60;  // ������ϵͳÿ1���Ӽ��һ��1 * 60
const int WALLOW_INTERVAL_SEND =
    15 * 60;  // ������ϵͳ�ۼ�����ʱ��ÿ15���ӷ���һ��15 * 60
const int WALLOW_POINT = 3 * 60;    // ������ϵͳÿ3������һ����(��)�ߵ�60 * 3
const int WALLOW_FULL_POINT = 60;   // ������ϵͳȫ����״̬����60
const int WALLOW_HALF_POINT = 100;  // ������ϵͳ������״̬����100

const int DEFAULT_LOGIN_MAPGROUP = 0;  // ��¼��
const int DEFAULT_LOGIN_MAPID = 1102;  // ��¼��
const int DEFAULT_LOGIN_POSX = 600;    // ��¼��
const int DEFAULT_LOGIN_POSY = 1102;   // ��¼��

const int CELLS_PER_BLOCK = 18;  // ÿROOM�ĸ�����
const int CELLS_PER_VIEW = 18;   // ��������ĸ�����
// const int  ITEMTYPEMONEY_MIN     = 1090000;    //
// ��С��Ǯ
// const int  ITEMTYPEMONEY_MAX     = 1091020;    //
// ����Ǯ
// const int  SMALLHEAPMONEY_LIMIT    = 10;     //
// С��Ǯ
// const int  SMALLHEAPMONEY_TYPE     = 1090000;    //
// С��ǮITEMTYPE
// const int  MIDDLEHEAPMONEY_LIMIT   = 100;      //
// �ж�Ǯ
// const int  MIDDLEHEAPMONEY_TYPE    = 1090010;    //
// �ж�ǮITEMTYPE
// const int  BIGHEAPMONEY_LIMIT      = 1000;     //
// ���Ǯ
// const int  BIGHEAPMONEY_TYPE     = 1090020;    //
// ���ǮITEMTYPE

// const int  SMALLHEAPGOLD_LIMIT     = 2000;     //
// С�ѽ���
// const int  SMALLHEAPGOLD_TYPE      = 1091000;    //
// С�ѽ���ITEMTYPE
// const int  MIDDLEHEAPGOLD_LIMIT    = 5000;     //
// �жѽ���
// const int  MIDDLEHEAPGOLD_TYPE     = 1091010;    //
// �жѽ���ITEMTYPE
// const int  BIGHEAPGOLD_LIMIT     = 10000;    //
// ��ѽ���
// const int  BIGHEAPGOLD_TYPE      = 1091020;    //
// ��ѽ���ITEMTYPE

const I64 MONEY_LIMIT = 1000000000;  // 1 billion
const int EMONEY_LIMIT = 100000000;  // 100 million

const int LEAVEFROMLOTTERY_MAP_ID = 8614;
const int PRACTISESKILL_MAP_ID = 601;         // ������������ͼ
const int PRACTISESKILLONLINE_MAP_ID = 1039;  // ��������ͼ
const int STARWAR_MAP_ID_FIRST = 100000;
const int STARWAR_MAP_ID_END = 200000;
const OBJID COPYMAPGEN_FIRST = 4000000001;  // ������ͼ��������һ��ID
const OBJID DYNAMEMMAP_FIRST = 4000000001;  // DYNAMEMMAP�ĵ�һ��ID
const OBJID DYNAMEMMAP_LAST = 4294967295;   // DYNAMEMMAP�����һ��ID
// const int  WHITE_SYN_MAP_ID  = 10380;
// // �װ��ͼ
const int BLACK_SYN_MAP_ID = 10000;  // �ڰ��ͼ
const int NEWBIE_MAP_ID = 1000;      // ���ִ��ͼ

const int _MAX_BONUTY = 9999999;
const int _MIN_BONUTY = 100000;
const int _MIN_ADDBONUTY = 10000;
const int _WANTED_ORDERCOST = 1000;
const int _BONUTY_TAX = 30;
const int _MAX_ACTION_VAR = 8;
const int _MAX_UNLEARN_NUMBER = 20;

const int MAX_SYNENEMYSIZE = 5;  // һ��5���ж԰��ɿռ�
const int MAX_SYNALLYSIZE = 5;   // һ��5�����˰��ɿռ�

const uint32_t MASK_SYNID = 0x003FFFFF;
const uint32_t MASK_FAMILYID = 0x00FFFFFF;
const uint32_t MASK_RANK_SHIFT = 22;
const uint32_t MASK_FAMILY_RANK_SHIFT = 24;

const int MASTER_WEAPONSKILLLEVEL = 12;
const int ID_MAP_NEWBIE = 1100;

const int NEWBIE_LEV = 15;
const int MASTER_USERLEV = 120;
const int NEWBIE_PROTECT_LEV = 25;
const int ROOKIE_LEV = 40;
const int JUNIOR_LEV = 70;
const int VETERAN_DIFF_LEV = 20;  // ���ֵĵȼ���

const int IDOWNER0 = 12;     // Զ�ֿ̲�
const int IDOWNER1 = 44;     // �г��ֿ�
const int IDOWNER2 = 8;      // ˫���ǲֿ�
const int IDOWNER3 = 10011;  // ���Źزֿ�
const int IDOWNER4 = 10012;  // ���ﱤ�ֿ�
const int IDOWNER5 = 10027;  // ���سǲֿ�
const int IDOWNER6 = 10028;  // �ڻ��ǲֿ�
const int IDOWNER7 = 4101;   // ɳĮС�ǲֿ�

const int MAGICDAMAGE_ALT = 26;               // ����Ч���ĸ߲�����
const int AUTOLEVELUP_EXP = -1;               // �Զ������ı�־
const int DISABLELEVELUP_EXP = 0;             // �������ı�־
const int AUTOMAGICLEVEL_PER_USERLEVEL = 10;  // ÿ10���������ȼ���һ��
const int USERLEVELS_PER_MAGICLEVEL = 10;     // ��ҵȼ������Ƿ����ȼ���10��
const int KILLBONUS_PERCENT = 5;              // ɱ������Ķ���EXP����
const int AWARDEXP_PER_MAGIC = 10;         // ���ܾ����Ϊÿʹ��һ�μ��ܻ��10��
const int MAGIC_DELAY = 1000;              // ħ��DELAY
const int MAGIC_DECDELAY_PER_LEVEL = 100;  // ÿ���������ȼ������ٵ�ħ��DELAY
const int RANDOMTRANS_TRY_TIMES = 10;      // ���˲�Ƶĳ��Դ���
const int DISPATCHXP_NUMBER = 20;          // ��XP������
const int COLLIDE_POWER_PERCENT = 80;      // ��ײ���ӹ������İٷֱ�
const int COLLIDE_SHIELD_DURABILITY = 2;   // ��ײҪ���ٵĶ�������
const int LINE_WEAPON_DURABILITY = 2;      // ֱ�߹���Ҫ���ٵ���������
const int MAX_SERIALCUTSIZE = 10;          // ˳��ն������
const int AWARDEXP_BY_TIMES = 1;           // �������Ӿ���ֵ
const int AUTO_MAGIC_DELAY_PERCENT = 150;  // ����ħ������ʱ���ӵ�DELAY
const int BOW_SUBTYPE = 500;               // ����SUBTYPE
const int POISON_MAIGC_TYPE = 10010;       // use for more status

const I64 MAX_PLAYER_EXP = 9223372036854775800;   // ��������ֵ
const I64 MIN_PLAYER_EXP = -9223372036854775800;  // �����С����ֵ

const INT LOGIN_FREE_LEVEL = 16;

const int ALTAR_WIDTH = 3;   //��̳���,�ݶ�
const int ALTAR_HEIGHT = 3;  //�߶�

const int USERSTAMINA_BASE = 5000;  //������������������ֵ 09-12-22
const int USERSTAMINA_MAX = 10000;  //�����������������ֵ 09-12-22

const int MAX_DEFPACKWIDTH = 8;   //�����ſ�����10��15������ tcp 2007-1-23 add
const int MAX_DEFPACKHEIGHT = 5;  //�����ſ�����10��15������ tcp 2007-1-23 add
const int MAX_DEFPACKSIZE = MAX_DEFPACKWIDTH * MAX_DEFPACKHEIGHT;

//////////////////////////////////////////////////////////////////////
// �ⲿ״̬����Ҫͨ��MsgPlayer֪ͨ������ҵ�״̬����ͻ���ͬ��
const uint64_t KEEPEFFECT_NORMAL = 0x0000000000000000;
const uint64_t KEEPEFFECT_CRIME = 0x0000000000000001;
const uint64_t KEEPEFFECT_DIE = 0x0000000000000002;
const uint64_t KEEPEFFECT_TEAMLEADER = 0x0000000000000004;
const uint64_t KEEPEFFECT_GHOST = 0x0000000000000008;
const uint64_t KEEPEFFECT_DISAPPEARING = 0x0000000000000010;
const uint64_t KEEPEFFECT_RED = 0x0000000000000020;  // PK����
const uint64_t KEEPEFFECT_WING = 0x0000000000000040;
const uint64_t KEEPEFFECT_STARWAR_LEADER = 0x0000000000000080;
const uint64_t KEEPEFFECT_STOPALL = 0x0000000000000100;     // ��
const uint64_t KEEPEFFECT_POISON = 0x0000000000000200;      // ��
const uint64_t KEEPEFFECT_ATTACK = 0x0000000000000400;      // ��
const uint64_t KEEPEFFECT_DEFENCE = 0x0000000000000800;     // ��
const uint64_t KEEPEFFECT_MOVESLOWLY = 0x0000000000001000;  // ��
const uint64_t KEEPEFFECT_STOPFIGHT = 0x0000000000002000;   // ��
const uint64_t KEEPEFFECT_STOPMOVE = 0x0000000000004000;    // ͣ
const uint64_t KEEPEFFECT_UNDERWRAPS = 0x0000000000008000;  // ��

const uint64_t KEEPEFFECT_SHIELD = 0x0000000000010000;        // ������Ч�� ״̬
const uint64_t KEEPEFFECT_GUARDIANSHIP = 0x0000000000020000;  // �ػ� ״̬
const uint64_t KEEPEFFECT_SLEEP = 0x0000000000040000;         // ˯
const uint64_t KEEPEFFECT_DAMAGE_REDUCE =
    0x0000000000040000;  //ȫ��ͼ�������˺�����Ч��

const uint64_t KEEPEFFECT_INVINCIBLE = 0x0000000000080000;      // �޵�״̬
const uint64_t KEEPEFFECT_FETCH_BURST = 0x0000000000100000;     // �걬״̬
const uint64_t KEEPEFFECT_POISONRANGE = 0x0000000000200000;     // ����״̬
const uint64_t KEEPEFFECT_ADJUSTTOGETHER = 0x0000000000400000;  // ����
const uint64_t KEEPEFFECT_KILLLINEUP = 0x0000000000800000;      // ɱ��
const uint64_t KEEPEFFECT_CRAZYFIGHTER = 0x0000000001000000;    // ��սʿ״̬
const uint64_t KEEPEFFECT_MULTISELECT =
    0x0000000002000000;  // ����Ŀ��ѡ���ϵĶ���״̬
const uint64_t KEEPEFFECT_PKSWITCH =
    0x0000000004000000;  // ����Ŀ��ѡ���ϵĶ���״̬

const uint64_t KEEPEFFECT_FLOATCANNON_ATTACK =
    0x0000000008000000;  //������ ����״̬
const uint64_t KEEPEFFECT_FLOATCANNON_REINFORCE =
    0x0000000010000000;  //������ Ԯ��״̬
const uint64_t KEEPEFFECT_FLOATCANNON_COUNTERSTROKE =
    0x0000000020000000;  //������ ����״̬
const uint64_t KEEPEFFECT_ELECTROMCANNON_ATTACK =
    0x0000000040000000;  //����� ����״̬
const uint64_t KEEPEFFECT_VAMPIRE_UNDER_SUNSHINE =
    0x0000000080000000;  // ��Ѫ��̫��ɹ��״̬const uint64_t
                         // KEEPEFFECT_ELECTROMCANNON_REINFORCE
                         // =0x0000000080000000;  //����� Ԯ��״̬
/*const uint64_t    KEEPEFFECT_ELECTROMCANNON_COUNTERSTROKE
 * =0x0000000100000000; //����� ����״̬*/
const uint64_t KEEPEFFECT_DYING_RANGE = 0x0000000100000000;  //������
const uint64_t KEEPEFFECT_AWARD_ANGEL = 0x0000000100000000;  //��ʹ״̬

const uint64_t KEEPEFFECT_BUSY_LevupInterface =
    0x0000000200000000;  // �����������棨ȫ�����棩æµ״̬
const uint64_t KEEPEFFECT_POWERCRAZYFIGHTER =
    0x0000000400000000;                                // ���սʿ״̬
const uint64_t KEEPEFFECT_MOUNT = 0x0000000800000000;  // �����е�״̬
const uint64_t KEEPEFFECT_FLAMETHROWER =
    0x0000001000000000;                                 //������������������״̬
const uint64_t KEEPEFFECT_XPFULL = 0X0000002000000000;  // xp full status.
const uint64_t KEEPEFFECT_PURPLE = 0x0000004000000000;  // ������״̬
const uint64_t KEEPEFFECT_WATCH_STARWAR = 0x0000008000000000;  // ��ս״̬
// const uint64_t   KEEPEFFECT_SHOT_DELAY
// =0x0000008000000000; // �����ӵ��ù⣬�ӳ�2��������
const uint64_t KEEPEFFECT_DEEPRED =
    0X0000010000000000;  //����  //����ͨ���졢��������ʵ��
const uint64_t KEEPEFFECT_USERSTATUS_CURSE = 0X0000020000000000;  //����״̬
const uint64_t KEEPEFFECT_USERSTATUS_PRACTISE =
    0X0000040000000000;  //��������״̬
const uint64_t KEEPEFFECT_VAMPIRE_UNDER_SAINT_LIGHT =
    0X0000080000000000;  // ��Ѫ��ʥ������״̬  const uint64_t
                         // KEEPEFFECT_SUPPRESS
                         // =0X0000080000000000;  //ѹ��״̬
const uint64_t KEEPEFFECT_FREEZE = 0X0000100000000000;  //�䶳״̬

const uint64_t KEEPEFFECT_DODGE = 0X0000100000000000;  //������״̬

const uint64_t KEEPEFFECT_SELFPROTECT = 0x0000200000000000;  //�Զ�����״̬
const uint64_t KEEPEFFECT_LOCKATTACK = 0x0000400000000000;   //��������״̬
const uint64_t KEEPEFFECT_SYMBOL = 0x0000800000000000;       //���͹�����״̬
const uint64_t KEEPEFFECT_TRANSLOOK = 0x0001000000000000;    //����һ��״̬
const uint64_t KEEPEFFECT_FLYMAP =
    0x0002000000000000;  //������ʱ״̬�������Ϳͻ��˶������
const uint64_t KEEPEFFECT_BAITMONSTER = 0x0004000000000000;  // ���˶���״̬
const uint64_t KEEPEFFECT_UPMODELLEV_USEITEM =
    0x0008000000000000;  //ʹ����Ʒ�����Ǽ�����
const uint64_t KEEPEFFECT_USERSTATUS_DIVE = 0x0010000000000000;  //Ǳˮ
const uint64_t KEEPEFFECT_PK_CHAMPION1 =
    0x0020000000000000;  // pk�� �����ھ�״̬
const uint64_t KEEPEFFECT_PK_CANDICATE1 =
    0x0040000000000000;  // pk�� ������Χ״̬
const uint64_t KEEPEFFECT_PK_CHAMPION2 =
    0x0080000000000000;  // pk�� �߼��ھ�״̬
const uint64_t KEEPEFFECT_PK_CANDICATE2 =
    0x0100000000000000;  // pk�� �߼���Χ״̬
const uint64_t KEEPEFFECT_PK_CHAMPION3 =
    0x0200000000000000;  // pk�� �м��ھ�״̬
const uint64_t KEEPEFFECT_PK_CANDICATE3 =
    0x0400000000000000;  // pk�� �м���Χ״̬
const uint64_t KEEPEFFECT_LURK =
    0x0800000000000000;  //��ҷ��� vampire ����-����������
const uint64_t KEEPEFFECT_BE_DELAY_REBORN_BY_OTHER =
    0x1000000000000000;  //����-�ӳ����ֻ��屻�����˸���ʱ��(��)
const uint64_t KEEPEFFECT_TRUMP_SELFBLAST_DECBATTLEEFFECT =
    0x2000000000000000;  //����-�Ա�������ս��������
const uint64_t KEEPEFFECT_TRANSFORMVALUEFULL =
    0X4000000000000000;                                // ����ֵ��״̬.
const uint64_t KEEPEFFECT_CHAOS = 0x4000000000000000;  //����

const uint64_t KEEPEFFECT_FIRST_NIMBUS =
    0X8000000000000000;  // ��һ���������а�״̬
// delete---begin
const uint64_t KEEPEFFECT_ATKRANGE = 0X1000000000000000;  // ���ӹ�����Χ��״̬?
const uint64_t KEEPEFFECT_REFLECT = 0X1000000000000000;
const uint64_t KEEPEFFECT_MAGICDAMAGE = 0X1000000000000000;
const uint64_t KEEPEFFECT_ATKSPEED = 0X1000000000000000;
const uint64_t KEEPEFFECT_LURKER = 0X1000000000000000;
const uint64_t KEEPEFFECT_WEAPONDAMAGE = 0X1000000000000000;
const uint64_t KEEPEFFECT_SYNCRIME = 0X1000000000000000;
const uint64_t KEEPEFFECT_REFLECTMAGIC = 0X1000000000000000;
// const uint64_t   KEEPEFFECT_DODGE
// =0X1000000000000000;
const uint64_t KEEPEFFECT_KEEPBOW = 0X1000000000000000;
const uint64_t KEEPEFFECT_SELFDEFENCE = 0X1000000000000000;  //��������
const uint64_t KEEPEFFECT_HITRATE = 0X1000000000000000;
const uint64_t KEEPEFFECT_MAGICDEFENCE = 0X1000000000000000;
const uint64_t KEEPEFFECT_BOWDEFENCE = 0X1000000000000000;
const uint64_t KEEPEFFECT_SUPERMAN = 0X1000000000000000;
const uint64_t KEEPEFFECT_TORNADO = 0X1000000000000000;
// delte---end

// ��չ״̬����   �ڶ���64λ
const uint64_t USERSTATUSEX_RAPTOR_LEV1 = 0x0000000000000001;  // ���ݱ���һ��
const uint64_t USERSTATUSEX_RAPTOR_LEV2 = 0x0000000000000002;  // ���ݱ������

const uint64_t USERSTATUSEX_BAT_LEV1 = 0x0000000000000004;  // �������һ��
const uint64_t USERSTATUSEX_BAT_LEV2 = 0x0000000000000008;  // ����������

const uint64_t USERSTATUSEX_SHARK_LEV1 = 0x0000000000000010;  // �������һ��
const uint64_t USERSTATUSEX_SHARK_LEV2 = 0x0000000000000020;  // ����������

const uint64_t USERSTATUSEX_DOLPHIN_LEV1 = 0x0000000000000040;  // �������һ��
const uint64_t USERSTATUSEX_DOLPHIN_LEV2 = 0x0000000000000080;  // ����������

const uint64_t USERSTATUSEX_BEAR_LEV1 = 0x0000000000000100;  // �ܻ������һ��
const uint64_t USERSTATUSEX_BEAR_LEV2 = 0x0000000000000200;  // �ܻ���������

const uint64_t USERSTATUSEX_LEOPARD_LEV1 =
    0x0000000000000400;  // ���������һ��
const uint64_t USERSTATUSEX_LEOPARD_LEV2 =
    0x0000000000000800;  // ������������

const uint64_t USERSTATUSEX_CATTLE_LEV1 = 0x0000000000001000;  // ţ�������һ��
const uint64_t USERSTATUSEX_CATTLE_LEV2 = 0x0000000000002000;  // ţ����������

const uint64_t USERSTATUSEX_DOMAIN_LIGHT = 0x0000000000004000;  // ����״̬
const uint64_t USERSTATUSEX_DOMAIN_NO_ENERGY_INCREASE =
    0x0000000000008000;  //�����ܡ���ֹ�ָ������ķ�Χ����
const uint64_t USERSTATUSEX_DOMAIN_MAP_SYN_ADD_DAMAGE =
    0x0000000000010000;  //�����ܡ�ȫ��ͼ������ż��˺�
const uint64_t USERSTATUSEX_DOMAIN_FIELD_SYN_ADD_DAMAGE =
    0x0000000000020000;  //�����ܡ���ΧȫԱ�˺���������
const uint64_t USERSTATUSEX_DOMAIN_FIELD_DAYTIME =
    0x0000000000040000;  //�����ܡ���Χ��������
// ����״̬
const uint64_t USERSTATUSEX_HERO_WHIRLWIND_USEING =
    0x0000000000080000;  //������ʿ����նʹ��״̬
const uint64_t USERSTATUSEX_HERO_WHIRLWIND_AFFECT =
    0x0000000000100000;  //������ʿ����ն��Ӱ��״̬
const uint64_t USERSTATUSEX_USER_CAN_CONJURE_DEVIL =
    0x0000000000200000;  // ���������һ���ٻ���ħ

const uint64_t USERSTATUSEX_SKILL_FREEZING =
    0x0000000000400000;  //�µļ��ܱ���״̬
const uint64_t USERSTATUSEX_SKILL_BURNING =
    0x0000000000800000;  //�µļ�������״̬
const uint64_t USERSTATUSEX_SKILL_BLEEDING =
    0x0000000001000000;  //�µļ�����Ѫ״̬

const uint64_t USERSTATUSEX_SKILL_MOVESPEEDREDUCE =
    0x0000000002000000;  //�µļ����ƶ��ٶȽ���״̬
const uint64_t USERSTATUSEX__SKILL_BLOODSHADOWSTEP =
    0x0000000004000000;  //�µ�ѪӰ��״̬

const uint64_t USERSTATUSEX_SKILL_JUSTICE =
    0x0000000008000000;  //�µļ�������״̬
const uint64_t USERSTATUSEX_SKILL_SAN_SHIELD =
    0x0000000010000000;  //�µļ�����ʥ����״̬
const uint64_t USERSTATUSEX_SKILL_WITHBOMB =
    0x0000000020000000;  //�µļ���ը������״̬
const uint64_t USERSTATUSEX_SKILL_SHOTGUNSPEEDYCHANGEBULLET =
    0x0000000040000000;  //������ɢ��ǹ�ӿ�״̬
const uint64_t USERSTATUSEX_SKILL_LIGHTNING_SHAKE =
    0x0000000080000000;  //�µļ��ܵ��״̬
const uint64_t USERSTATUSEX_SKILL_ADD_LIFE =
    0x0000000100000000;  //�µļ��ܲ�Ѫ״̬
const uint64_t USERSTATUSEX_SKILL_DIZZY =
    0x0000000200000000;  //�µļ���ѣ��״̬

//�ϲ���Ѫ����룬��ͻ��ԭֵΪ��
// const uint64_t   USERSTATUSEX_STATUS_CAP          =
// 0X0000000010000000;//��ͨ״̬
// const uint64_t   USERSTATUSEX_STATUS_CAPPOWER         =
// 0X0000000020000000;//ǿ��״̬
const uint64_t USERSTATUSEX_STATUS_CAP = 0X0000000010000000;       //��ͨ״̬
const uint64_t USERSTATUSEX_STATUS_CAPPOWER = 0X0000000020000000;  //ǿ��״̬
// ongoing

//////////////////////////////////////////////////////////////////////////
// ���� ��ص� Mask
const uint64_t REGION_SUN_SHINE_MASK = 1ull
                                       << 0;  //  Type = 65536�������������
const uint64_t REGION_SAINT_LIGHT_MASK =
    1ull << 1;  // ���ڽ�����ʱ��ʹ��Ѫ����롰��Ѫ��ʥ������״̬����
const uint64_t REGION_CITY_MASK = 1ull << 2;  //����������Ӿ��鲻��������
const uint64_t REGION_WEATHER_MASK = 1ull << 3;
const uint64_t REGION_STATUARY_MASK = 1ull << 4;
const uint64_t REGION_DESC_MASK = 1ull << 5;
const uint64_t REGION_PK_PROTECTED_MASK = 1ull << 6;
const uint64_t REGION_BOOTH_MASK = 1ull << 7;   // data0: level of booth
const uint64_t REGION_OFFSET_MASK = 1ull << 8;  //��������(�´����ͻ���)
const uint64_t REGION_MARKET_MASK = 1ull << 9;  //�г�������Ӿ��鲻��������
const uint64_t REGION_RECORDPOS_DISABLE_MASK = 1ull << 10;  //�����¼��
const uint64_t REGION_DISABLE_TRUMP_REBORN_MASK = 1ull
                                                  << 11;  //��ֹʹ�÷��������
const uint64_t REGION_DISABLE_MOUNT_MASK = 1ull << 12;    //�������
const uint64_t REGION_SWEAR_MASK = 1ull << 13;            //�������
const uint64_t REGION_DISABLE_CALLALTAR_MASK = 1ull << 14;  //��ֹ�ٻ���̳����
const uint64_t REGION_COM_ALTAR_MASK = 1ull << 15;          //������̳����
const uint64_t REGION_PRIVATE_ALTAR_MASK = 1ull << 16;      //����ٻ���̳����
const uint64_t REGION_DISABLE_FLY_MASK = 1ull << 17;        //��ֹ��������
const uint64_t REGION_ANGEL_DRAW_MASK = 1ull << 18;         //��ʹ��ȡ��
const uint64_t REGION_BATTLE_MASK =
    1ull << 19;  //ս������ // TODO::MILO 11/9/2015
                 //����ԭ�����Ǹ���һ��һ����18���Ƿ���������ĳ���19
// To be Continued

//��Ʒ���е�״̬
const uint64_t KEEPEFFECT_HEADLOOP_WIEW_LEADER_POSITION =
    0x0000000000000010;  //ͷ����·��ʾ�ӳ�λ��
const uint64_t KEEPEFFECT_HEADLOOP_WIEW_TEAM_POSITION =
    0x0000000000000008;  //ͷ����·��ʾ�ӳ�λ��
//////////////////////////////////////////////////////////////////////
// �ۺ�״̬

const uint64_t KEEPEFFECT_NOT_ACTIVE = KEEPEFFECT_DIE | KEEPEFFECT_FREEZE;
const uint64_t KEEPEFFECT_NOT_CLEAR = KEEPEFFECT_TEAMLEADER | KEEPEFFECT_RED |
                                      KEEPEFFECT_DEEPRED | KEEPEFFECT_PURPLE |
                                      KEEPEFFECT_USERSTATUS_PRACTISE |
                                      KEEPEFFECT_SYMBOL;  // ������������״̬

const uint64_t KEEPEFFECT_EVIL_STATUS =
    KEEPEFFECT_CRIME | KEEPEFFECT_DEEPRED | KEEPEFFECT_SYNCRIME;

//////////////////////////////////////////////////////////////////////
// �ڲ�״̬������Ҫͨ��MsgPlayer֪ͨ������ҵ�״̬���������ڲ�ʹ��(magictypeʹ��)

// const uint64_t STATUS_NORMAL       = 0ull;
// const uint64_t STATUS_DIE          = 1ull;     //
// ����
// const uint64_t STATUS_CRIME        = 1ull << 1;
// const uint64_t STATUS_POISON       = 1ull << 2;    //
// �ж�
// const uint64_t STATUS_TEAMLEADER     = 1ull << 3;
// const uint64_t STATUS_PKVALUE        = 1ull << 4;    //
// PK״̬
// const uint64_t STATUS_HITRATE        = 1ull << 5;    //
// ������
// const uint64_t STATUS_DEFENCE        = 1ull << 6;    //
// ����
// const uint64_t STATUS_ATTACK       = 1ull << 7;    //
// ������
// const uint64_t STATUS_DISAPPEARING   = 1ull << 8;    // ��ʧ
// const uint64_t STATUS_MAGICDEFENCE   = 1ull << 9;    //
// ħ������
// const uint64_t STATUS_BOWDEFENCE     = 1ull << 10;   //
// ������
// const uint64_t STATUS_ATKRANGE     = 1ull << 11;   //
// ������Χ
// const uint64_t STATUS_REFLECT        = 1ull << 12;   //
// ������
// const uint64_t STATUS_SUPERMAN     = 1ull << 13;   //
// սʿxp
// const uint64_t STATUS_WEAPONDAMAGE   = 1ull << 14;   //
// �����˺�
// const uint64_t STATUS_MAGICDAMAGE      = 1ull << 15;   //
// ħ���˺�
// const uint64_t STATUS_ATKSPEED     = 1ull << 16;   //
// �����ٶ�
// const uint64_t STATUS_LURKER       = 1ull << 17;   //
// ����
// const uint64_t STATUS_TORNADO        = 1ull << 18;   //
// ��ʿxp
// const uint64_t STATUS_SYNCRIME     = 1ull << 19;   //
// ���ɷ���
// const uint64_t STATUS_REFLECTMAGIC   = 1ull << 20;   //
// ħ������
// const uint64_t STATUS_DODGE        = 1ull << 21;   //
// ���
// const uint64_t STATUS_WING       = 1ull << 22;   //
// ����
// const uint64_t STATUS_KEEPBOW        = 1ull << 23;   //
// ����
// const uint64_t STATUS_STOP       = 1ull << 24;   //
// �ƶ�����
// const uint64_t STATUS_LUCK_SPREAD      = 1ull << 25;   //
// ��
// const uint64_t STATUS_LUCK_ABSORB      = 1ull << 26;   //
// ����
// const uint64_t STATUS_CURSE        = 1ull << 27;   //
// ����
// const uint64_t STATUS_GODBLESS     = 1ull << 28;   //
// ף��
// const uint64_t STATUS_SYN_LEADER     = 1ull << 29;   //
// ����ս����״̬
// const uint64_t STATUS_SYN_ASSISTANT    = 1ull << 30;   //
// ����ս������״̬
// const uint64_t STATUS_PK_CHAMPION_MONTH  = 1ull << 31;   //
// ��pk���ھ�
// const uint64_t STATUS_PK_CHAMPION_WEEK = 1ull << 32;   //
// ��pk���ھ�
// const uint64_t STATUS_PK_PROF_SOLDIER    = 1ull << 33;   //
// ְҵpk�� (ս)
// const uint64_t STATUS_PK_PROF_WARRIOR    = 1ull << 34;   //
// ְҵpk�� (��)
// const uint64_t STATUS_PK_PROF_ARCHER   = 1ull << 35;   //
// ְҵpk�� (��)
// const uint64_t STATUS_PK_PROF_DAOISTWATER  = 1ull << 36;   //
// ְҵpk�� (ˮ��)
// const uint64_t STATUS_PK_PROF_DAOISTFIRE = 1ull << 37;   //
// ְҵpk�� (���)
// const uint64_t STATUS_PK_PROF_RENZHE   = 1ull << 38;   //
// ְҵpk�� (����)
//
// const uint64_t STATUS_DETACH_BADLY   = STATUS_CRIME;
// // ���ã�������в���״̬
// const uint64_t STATUS_DETACH_ALL     = STATUS_TEAMLEADER;
// // ���ã��������ħ��״̬

const int DEFAULT_MONSTER_MAGIC_LEVEL = 0;

const unsigned char RMB_LOG_VIP_SHOP = 0;  //Ϊ��VIP�̵깺����Ʒ�ļ�¼��
const unsigned char RMB_LOG_ACTION_ADD =
    1;  //Ϊaction�ı����ӣ�����ϵͳemoneyLOG���� tcp 2007-1-11
const unsigned char RMB_LOG_TRADE = 2;          //Ϊ��ƽ���׻�ã�
const unsigned char RMB_LOG_BOOTH = 3;          //Ϊ��̯��ã�
const unsigned char RMB_LOG_VENDUE = 4;         //Ϊ������ã�
const unsigned char RMB_LOG_LOST = 5;           //Ϊ��Ǯʧ�ܣ�
const unsigned char RMB_LOG_CHECKOUT_RMB = 6;   //Ϊ��card��ļ�¼�һ��ɴ��ң�
const unsigned char RMB_LOG_CHECKIN_RMB = 7;    //Ϊ�Ӵ��Ҷһ���card��ļ�¼��
const unsigned char RMB_LOG_CHECKOUT_RMB2 = 8;  //Ϊ��card2��ļ�¼�һ��ɴ��ң�
const unsigned char RMB_LOG_CHECKIN_RMB2 = 9;   //Ϊ�Ӵ��Ҷһ���card2��ļ�¼��
const unsigned char RMB_LOG_ADD_BOOTH_DEPOSIT = 10;  //׷�Ӱ�̯Ѻ��
const unsigned char RMB_LOG_ACTION_DEC =
    11;  //Ϊaction�ı���٣�����ϵͳemoneyLOG���� tcp 2007-1-11
const unsigned char RMB_LOG_PURCHASE_BOOTH = 12;   //̫��ʯ����̯λ
const unsigned char RMB_LOG_SATELLITE = 13;        //���ǹ㲥
const unsigned char RMB_LOG_AutoExercise = 14;     //��������
const unsigned char RMB_LOG_TransRandPos = 15;     //���ٴ���
const unsigned char RMB_LOG_WEAPONSKILL_ADD = 16;  //��������������
const unsigned char RMB_LOG_ROBOTSKILL_ADD = 17;   //���ӻ���������
const unsigned char RMB_LOG_MAGICSKILL_ADD = 18;   //���Ӽ���������
const unsigned char RMB_LOG_PK_PUBLISH =
    19;  // PK�ͷ� PK�ͷ����䰸 tcp 2007-3-15 add
const unsigned char RMB_LOG_MODEL_LEV_DEC_COLD_STATUS =
    20;                                            //ս���Ǽ���ȴ״̬ʱ�����
const unsigned char RMB_LOG_TRUMP_MAKE_HOLE = 21;  //���� ֱ��ʹ��̫��ʯ���п���
const unsigned char RMB_LOG_REPAIR_DESTROYOBJ = 22;   //����ս������ƻ����
const unsigned char RMB_LOG_BUY_STONE2 = 23;          //������ˮ��
const unsigned char RMB_LOG_UPDATE_NIMBUS = 24;       //ʹ��̫��ʱ�ӻ�������
const unsigned char RMB_LOG_BUY_ORDER = 25;           //�򵥻�̫��ʯ
const unsigned char RMB_LOG_MODIFY_ORDER_GAIN = 26;   //�޸��򵥷���̫��ʯ
const unsigned char RMB_LOG_MODIFY_ORDER_SPEND = 27;  //�޸��򵥿�̫��ʯ
const unsigned char RMB_LOG_DEL_BUY_ORDER = 28;       //ȡ���򵥷���̫��ʯ
const unsigned char RMB_LOG_INCOME = 29;              //����������л��̫��ʯ
const unsigned char RMB_LOG_GUARD_REBORN = 30;        //��������
const unsigned char RMB_LOG_EAT_EXPBALL = 31;         //�Ծ�����
const unsigned char RMB_LOG_DONATE = 32;              //��λ����
const unsigned char RMB_LOG_PRIZE = 33;               //�콱ϵͳ
const unsigned char RMB_LOG_AUCTION_BID = 34;         //��������
const unsigned char RMB_LOG_FAMILYWAR_TRUCE = 35;     //ռ��ս��ս����
const unsigned char RMB_LOG_AUCTION_RETURN = 36;      //����������Ʒʱ����
const unsigned char RMB_LOG_CREATE_INSTANCE = 37;     //������������
//////////////////////////////////////////////////////////////////////
const unsigned char EMONEY_LOG_REPAIR = 0;     //����װ��
const unsigned char EMONEY_LOG_BUY = 1;        //��ͨ�̵�����Ʒ
const unsigned char EMONEY_LOG_BUY_BOOTH = 2;  //����̯λ
const unsigned char EMONEY_LOG_ACTION = 3;  // action�۳�
//////////////////////////////////////////////////////////////////////
const unsigned char STONE_LOG_UPGARE_MODELLEV = 0;  //����ս�����Ǽ�
const unsigned char STONE_LOG_STONE_SHOP = 1;       //ˮ���̵�����
const unsigned char STONE_LOG_ACTION = 2;  // action�۳�
//////////////////////////////////////////////////////////////////////

const unsigned char EMONEY3_LOG_VIP_SHOP = 100;    //Ϊ��VIP�̵깺����Ʒ�ļ�¼��
const unsigned char EMONEY3_LOG_ACTION_ADD = 101;  //Ϊaction�ı����ӣ�
const unsigned char EMONEY3_LOG_ACTION_DEC = 111;  //Ϊaction�ı���٣�
const unsigned char EMONEY3_LOG_SATELLITE = 113;   //���ǹ㲥(�ɸ�)
const unsigned char EMONEY3_LOG_WEAPONSKILL_ADD = 116;  //��������������
const unsigned char EMONEY3_LOG_ROBOTSKILL_ADD = 117;   //���ӻ���������
const unsigned char EMONEY3_LOG_MAGICSKILL_ADD = 118;   //���Ӽ���������
const unsigned char EMONEY3_LOG_PK_PUBLISH = 119;  // PK�ͷ� PK�ͷ����䰸
const unsigned char EMONEY3_LOG_MODEL_LEV_DEC_COLD_STATUS =
    120;  //ս���Ǽ���ȴ״̬ʱ�����
const unsigned char EMONEY3_LOG_TRUMP_MAKE_HOLE =
    121;  //���� ֱ��ʹ��̫��ʯ���п���
const unsigned char EMONEY3_LOG_REPAIR_DESTROYOBJ = 122;  //����ս������ƻ����
const unsigned char EMONEY3_LOG_HIGH_MODE_LEV_UP = 130;   //��������
const unsigned char EMONEY3_LOG_MODULESTAR_LEV_UP = 131;  //�Ծ�����
const unsigned char EMONEY3_RMB_LOG_DONATE = 132;         //��λ���׻�̫��ʯ

const int MAX_PACKETSIZE = 1024;
const int _RANGE_EXPSHARE = 32;

const int _DELTA_X[8] = {0, -1, -1, -1, 0, 1, 1, 1};  // �������ƶ�
const int _DELTA_Y[8] = {1, 1, 0, -1, -1, -1, 0, 1};  // �������ƶ�

const int AUTO_UPRANK_SYNDICATE_USERLEV = 6;  // 2007.02.10 ��ξ�Զ���Ϊ��ʽ��Ա

const UCHAR TEAMEXP_NONE = 0x0;
const UCHAR TEAMEXP_BASE = 0x1;
const UCHAR TEAMEXP_VIP = 0x2;
const UCHAR TEAMEXP_STAR = 0x4;     //�Ǽ����ﾭ��
const UCHAR TEAMEXP_SUPPORT = 0x8;  //״̬��֧��
const UCHAR TEAMEXP_DOUBLE = 0x10;
const UCHAR TEAMEXP_TREBLE = 0x20;
const UCHAR TEAMEXP_CRYSTAL = 0x40;  //ˮ��֧��
const uint64_t MAX_EXP_CONTRIBUTIONS_LIMIT = 800000000000;

const OBJID NEW_USER_DEFAULT_MAP_ID = 1102;
const UINT NEW_USER_DEFAULT_MONEY = 100;
const UINT NEW_USER_DEFAULT_LEVEL = 1;
const UINT NEW_USER_DEFAULT_WEIGHT_LIMIT = 9999;
const UINT NEW_USER_DEFAULT_LIFT = 500;
const UINT NEW_USER_DEFAULT_MANA = 0;

const int _MAX_FLY_HEIGHT = 500;             // ���и߶�
const OBJID SPIRIT_ITEM_TYPE_ID = 53000002;  // ��Spirit������һ����Ʒ����ƷType
const int DEFAULT_SHAPE = 0;
const int ERROR_WEIGHT = 123456789;  // ���������
const int MAX_QUALITY = 9;           // ��ߵ�Ʒ��
const int CORRUPT_SALE_FEE = 1;      // ������Ʒ�۸�
const int UNIDENT_SALE_FEE = 1;      // ��δ�����ļ۸�

const int MAGIC_TYPE_OFFSET = 10;
const int MAX_SUBSKILLSIZE = 3;
const int MAX_SKILLSIZE = 1 + MAX_SUBSKILLSIZE;  // ע���CMsgSkillSuit�ṹ��ͬ
const int SKILL_TYPE_OFFSET = MAGIC_TYPE_OFFSET;
const int SKILLSUIT_HOTKEY_CRAZYFIGHT_RIGHTSHORTCUTL =
    101;  // 101����Ϊ����������ϵ�
const int SKILLSUIT_HOTKEY_CRAZYFIGHT_RIGHTSHORTCUT =
    102;  // 102����Ϊ�������Ҽ��ϵģ��ڿ�սʿ״̬�»���ʹ�ô���������
const int SKILLSUIT_HOTKEY_CRAZYFIGHT_RIGHTSHORTCUTF5 =
    103;  // 103����Ϊ������F5���ϵ�
const int SKILLSUIT_HOTKEY_TRUECRAZYFIGHT_LEFTBTN =
    201;  // 201����Ϊ����������ϣ� ɱ����ʹ�õļ���
const int SKILLSUIT_HOTKEY_BASESUPPORT = 301;  // ����Ԯ����־

const int SYN_MONEY_BASELINE = 10 * 10000;  // ���ɻ������ڸ�ֵ�������ư��ɹ���

//////////////////////////////////////////////////////////////////////////
// ITEMPOSITION
const int ITEMPOSITION_USER_LIMIT = 199;
const int ITEMPOSITION_STORAGE = 201;
const int ITEMPOSITION_TRUNK = 202;
const int ITEMPOSITION_CHEST = 203;
const int ITEMPOSITION_GROUND = 204;        // �������ݿ�
const int ITEMPOSITION_VIRTUALSPACE = 205;  // ��ռ���չ��
const int ITEMPOSITION_VIPSTORAGE = 206;  // VIPר�òֿ�
const int ITEMPOSITION_BUY_TRADE_STORAGE = 207;   //������Ʒ��Ųֿ�
const int ITEMPOSITION_SELL_TRADE_STORAGE = 208;  //������Ʒ��Ųֿ�
const int ITEMPOSITION_AUCTION_STORAGE = 209;     //�����ֿ�
const int ITEMPOSITION_NONE = 255;                // �Ƿ�λ��

const int _MAX_RMBLIMIT_TRADE = 1000000;
const int _MAX_RMBLIMIT = 10000000;
const uint32_t _MAX_MONEYLIMIT = UINT_MAX;

const int EMONEY_EXCHANGE_RATE = 73000;  // ��������Ϸ�ҵĶһ�����

//////////////////////////////////////////////////////////////////////////
// LeaveWood
const int PLAYER_WORDS_PER_TIME = 2;   // ���ÿ�ζ�ȡ5������
const int NEW_WORDS_PER_MINUTE = 5;    // ÿ�����Զ���ȡ����������
const int DELETE_LEAVEWORD_DAYS = 31;  // 31���������Ի��Զ�ɾ��
const int SECS_PER_AUTOFLUSH = 60;     // ÿ�����Զ�ˢ��һ��

const int SECS_MONSTER_DIZZ = 3;

const int MAX_HEADLOOP_ATK_NUM = 3;  //ͬʱ����״̬���������Ŀ

const int MAX_WEIGHT = 999999999;

const double EPSILONG = 0.00001;

const int PILE_ITEM_MAX_NUM = 10;

const int ADDLIFE_FIRST_PERCENT = 40;
const int ADDLIFE_NEXT_PERCENT = 20;

const int _RADAR_SECONDS = 90;  // 2007.03.12 ��ֵ��Ʒ�״����ʱ��
const int MINI_ADDLIFE_DRAG = 100;
const int PACKAGE_LIMIT = 80;  // һ��package����ܷŶ��ٸ���Ʒ
const int MARRY_MIN_LEVEL = 30;

const int PKVALUE_BADGUY = 1000;
const int MAX_EXPTYPE = 255;
const int PICK_LARGE_MONEY = 10000;  // ��Ǯ�ܶ�ʱ���㲥ACTION��Ϣ
const int MAX_USER_VAR = 32;         // ��ս����action���� 2007-2-5 add

// Task
const int LUA_IDX_START = 127;

const int MAX_DROPITEM_RATE = 100;
const int MAX_DROPITEM_AMOUNT = 0x00FFFFFF;
const int USER_SENDFLOWER_LEVEL = 50;  // �����������ͻ��ĵȼ�
const int COACH_TIME_SPEND_EVERY_INTERVAL = 20;
const int MAX_DIRSIZE = 8;
const int SIMPLEMAGIC_RECRUIT = 1005;
const int GARBAGE_DIEDELAY_SECS = 30;  // SCENE_NPC�����������ɾ��

//////////////////////////////////////////////////////////////////////////
// magictype
const OBJID ICE_MAGIC = 9800;
const OBJID SHAKE_MAGIC = 9802;
const OBJID MAGICTYPE_HOTATK = 9801;  // �������ռ���type

//////////////////////////////////////////////////////////////////////////
// mine
const int _MAX_LAY_MINE = 15;  // ������������

//////////////////////////////////////////////////////////////////////////
// spirit
const int SPIRIT_DUNTYPE_OFFSET = 1000;

//////////////////////////////////////////////////////////////////////////

const int TRANSNPC_FEE = 10000;
const int SYNFLAG_SIZEADD = 5;      // �������ӵĸ��ӳߴ�
const int DEFAULT_NPC_SIZEADD = 4;  // ÿ�����������
const int PKVALUE_YELLOWNAME = 70;
const int MAX_WEAPON_SKILL_ATK_ADJ_LEVEL = 20;
const int MAX_ATKER_NUM = 10;
//������Ʒ�Ļ�������
const int EQUIP_BASE_DROP_RATE = 1000;       //װ��
const int AMMO_BASE_DROP_RATE = 1000;        //��ҩ
const int PART_BASE_DROP_RATE = 0;           //��׼���
const int AMPLIFIER_BASE_DROP_RATE = 0;      //������
const int GUARDEQUIP_BASE_DROP_RATE = 1000;  //������Ʒ
const int EXPENDABLE_BASE_DROP_RATE = 1000;  //����Ʒ
const int INSIDEITEM_BASE_DROP_RATE = 0;     //�ڲ�װ��
const int RMB_BASE_DROP_RATE = 1000;         //̫��ʯ
const int OTHER_BASE_DROP_RATE = 2000;       //����
//��������Ʒ�Ļ�������
const int SPECIAL_BASE_DROP_RATE = 0;  //��������Ʒ
//������Ʒ�ĵ������ͻ�������
const int EXPLODE_TYPE_BASE_DROP_RATE =
    (EQUIP_BASE_DROP_RATE + AMMO_BASE_DROP_RATE + GUARDEQUIP_BASE_DROP_RATE +
     EXPENDABLE_BASE_DROP_RATE + OTHER_BASE_DROP_RATE + RMB_BASE_DROP_RATE);
//����Ʒ�Ļ�������
const int EXPLODE_BASE_DROP_RATE = 200;
//���������ж�ʹ�õ������Χ
const int RAND_RANGE = 12000;

const int MONSTERDROPITEM_RANGE = 2;  // 2*2+1��4�η�=625������

const uint64_t _MAX_SAVEMONEYLIMIT = 0x7fffffffffffffffull;

const int GUARD_DIE_DEC_BATTLEEFFECT = 2;

const int LEV_CANHOLD_CANNON2 = 20;

const OBJID SPIRITITEM_FIRSTIDD = 4000000000;  // 4012345678;
const OBJID SPIRITITEM_LASTID = 4290000000;    // 4012345678;

const int TWOCOLS_TWOROWS_SHAPE = 2010;  // 1023action����

//////////////////////////////////////////////////////////////////////////
const int EXPBALL_START = 51999996;
const int EXPBALL_END = 51999999;
const int FLOWER_START = 51000751;
const int FLOWER_END = 51000758;
const int INCREASEVALUEITEMSTART = 51000001;
const int NORMALLITEM_STAR = 0;
const int NORMALLITEM_END = 49999999;

//////////////////////////////////////////////////////////////////////////
// map gen no�η���
//��������ʱ������ĵ�ͼ�����Դ
const uint32_t MAPGENNO_DUN_START = 1000;
const uint32_t MAPGENNO_DUN_END = 9000;

const int _MAX_TEAMMEMBER = 5;

const int MIN_SUPERMAP_KILLS = 25;

const OBJID SPIRIT_NATIVEPLACE_RANDRANGE_TYPE = 20001;
const bool WITH_BLOCK = true;
const int TIME_MANA_UPDATE = 2;
const UINT DEFAULT_MANA_RESTORE_VALUE = 10;
const int TIME_MONEY_UPDATE = 5;
const int TIME_EXPERIENCE_UPDATE = 5;

//////////////////////////////////////////////////////////////////////////
// QuizCompete
const int QUIZ_START_TIME = 2000;  // 20:00
const int QUIZ_START_MSG_TIME = 1957;  // 19:57
const int CHEAT_CHECK_LEV = 100;  //������ʵ�������ȼ�Ҫ��

//////////////////////////////////////////////////////////////////////////
//�����ͼ���͹�֧��64�ֵ�ͼ����(Ŀǰ���������ͼ: ��̬��ͼ����̬��ͼ��������ͼ)
const uint64_t MAPTYPE_NORMAL = 0ull;  //��ͨ��ͼ
const uint64_t MAPTYPE_PKFIELD = 1ull << 0;  // PK��
const uint64_t MAPTYPE_CHGMAP_DISABLE = 1ull << 1;  //������ħ���ڵ�ͼʵ���ƶ�
const uint64_t MAPTYPE_RECORD_DISABLE = 1ull << 2;  //���ܼ�¼
const uint64_t MAPTYPE_PK_DISABLE = 1ull << 3;      //����PK
const uint64_t MAPTYPE_BOOTH_ENABLE = 1ull << 4;    //ר�ð�̯��ͼ(�޼�¼��)
const uint64_t MAPTYPE_TEAM_DISABLE = 1ull << 5;    //�������
const uint64_t MAPTYPE_TELEPORT_DISABLE =
    1ull << 6;  // chgmap by action��������chgmap��ָ����سǾ�
const uint64_t MAPTYPE_SYN_MAP = 1ull << 7;     //���ɵ�ͼ
const uint64_t MAPTYPE_PRISON_MAP = 1ull << 8;  //������ͼ
const uint64_t MAPTYPE_FLY_DISABLE = 1ull << 9;
const uint64_t MAPTYPE_DISABLE_TRANSFER_SOURCE = 1ull
                                                 << 9;     //������Ϊ˲�Ƶ�Դ��
const uint64_t MAPTYPE_FAMILY = 1ull << 10;                //��ͥ��ͼ
const uint64_t MAPTYPE_MINEFIELD = 1ull << 11;             //��
const uint64_t MAPTYPE_DISABLE_GODTRANSPORT = 1ull << 11;  //��ֹ���ɴ���
const uint64_t MAPTYPE_PKGAME = 1ull << 12;  // PK��
const uint64_t MAPTYPE_HUMAN = 1ull
                               << 13;  //���ೡ��������ר�ó���������PK�����У�
const uint64_t MAPTYPE_WORLDWAR = 1ull << 14;  //��ս��ͼ
const uint64_t MAPTYPE_UNIVERSE =
    1ull << 15;  //���泡�� ����������ͨ��ͼ�����ƶ���ʽ��
const uint64_t MAPTYPE_EXPERIMENT = 1ull
                                    << 16;  //�����ҵ�ͼ ����������ͨ��ͼ���֣�
const uint64_t MAPTYPE_SPACESHIPJOB = 1ull << 17;  //�ɴ������ͼ ����
const uint64_t MAPTYPE_SPACESHIP = 1ull << 18;     //�ɴ���ͼ ����
const uint64_t MAPTYPE_TRAININGFIELD =
    1ull << 19;  //��������ͼ ���� (auto set no_pk|no_record, ��������ս������)
const uint64_t MAPTYPE_NEWPIE_PK_PROTECT = 1ull << 20;  //���ֱ�����ͼ
const uint64_t MAPTYPE_FULLSCREEN_ATK_DISABLE = 1ull
                                                << 21;  //����ʹ��ȫ����ը����
const uint64_t MAPTYPE_DISABLE_TRANSFER_TARGET = 1ull
                                                 << 21;  //������Ϊ˲�Ƶ�Ŀ�ĵ�
const uint64_t MAPTYPE_NO_REBORN_INNOWPOS = 1ull << 22;  // ����ԭ�ظ����
const uint64_t MAPTYPE_DISABLE_TRANSPOS = 1ull
                                          << 23;  //�����ٻ� 2007-2-27 tcp add
const uint64_t MAPTYPE_DISABLE_TRANSFORM =
    1ull << 24;  //���ɱ��εĵ�ͼ 2007-3-29 tcp add
const uint64_t MAPTYPE_DISABLE_TRUMP_REBORN = 1ull
                                              << 25;  //��ֹʹ�÷��������
const uint64_t MAPTYPE_DISABLE_TRUMP_REGION = 1ull
                                              << 26;  //��ֹʹ�÷�����缼��
const uint64_t MAPTYPE_DISABLE_TRUMP_RAND_TRANS_POS =
    1ull << 27;  //��ֹʹ�÷���-С˲��
const uint64_t MAPTYPE_PK_LOST_NOTHING = 1ull << 29;  // PK����Ҳ������κ���ʧ

const uint64_t MAPTYPE_DISABLE_AREA_MAGIC = 1ull << 30;  //��ֹʹ�÷�Χ����

const uint64_t MAPTYPE_DISABLE_STEAL = 1ull << 30;  //��ֹ͵��
const uint64_t MAPTYPE_DISBLE_TEAM_SEARCH = 1ull
                                            << 31;  //��ֹ���������ĵ�ͼ����
const uint64_t MAPTYPE_OFFLINE_TRAINING_DISABLE = 1ull
                                                  << 33;  //���������Ƿ�����
const uint64_t MAPTYPE_NOT_INVITE = 1ull << 34;           //�Ƿ���������
const uint64_t MAPTYPE_FAMILYWAR = 1ull << 32;            //����ս��ͼ
const uint64_t MAPTYPE_DUN = 1ull << 36;                  //���³�
//����PK����ͼ����
const uint64_t MAPTYPE_PKGAME_NEAR_WAR = 1ull << 43;  // PK�ٱ���ͼ
const uint64_t MAPTYPE_PKGAME_FAR_WAR = 1ull << 44;  // pkɽ�˵�ͼ
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//ĩ��Σ������
const int MSGMAGICEFFECT_MUTUAL_EFFECT_BIT =
    6;  // 2^6���µ�ֵ�������Ч������ʹ�ã�ʮ���Ʒ�ʽ����2^6�����ϵ�ֵ���ǻ����Ч��ʹ�ã������Ʒ�ʽ��
const int TIMELINESS_ITEM_TIME_UNIT = 60;  //ʱЧ����Ʒ��ʱ��λ��60�룩

// globalvaniable��type�ֶζ���
const int GLOBALDATA_TYPE_USER_BATTLE_ATTRIBUTE = 20101;  //���Ե�Ч��

//ǿ�и������Ʒ srf
const char ENFORCE_AWARDITEM_SQL[] =
    "INSERT INTO itemex(type,owner_id,player_id,position,ownertype) "
    "VALUES(%d,%d,%d,4070,52)";

// Dota
const INT ITEM_COMPONENT_MAX = 5;  //��Ʒ�ϳ���������

#endif  // end of define _GS_CONST_DEFINE_H_

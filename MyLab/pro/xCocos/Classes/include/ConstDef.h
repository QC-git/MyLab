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

//客户端版本号，用于客户端登入是否合法判断
const uint32_t CLIENTVER = 170;  //与客户端同步就可以

const char szSYSTEM[] = "SYSTEM";
const char szTEAMMATES[] = "TEAMMATES";
const char szROOMMATES[] = "ROOMMATES";
const char szALLUSERES[] = "ALLUSERES";

const long _DYNAMIC_NPC_ID = 1000000;
const int SOCKET_NONE = -1;   // 无效的SOCKET索引
const int BYTE_BITCOUNT = 8;  //一个字节有多少位
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
const int _NPC_SYNOCCUPY = 200;  // 帮派看门人
const int _NPC_PACKITEM = 201;
const int _NPC_PACKPET = 202;
const int _NPC_SYNMACKET = 203;  // 帮派市场管理员
const int _NPC_FURNITURE = 300;
const int _NPC_BLOCKKEEPER = 1000;
const int _NPC_FAMILYKEEPER = 1001;

const int MAX_NPCDATA = 4;  // 必须小于_MAX_NPCJOB

const int _MAX_NPCTASK = 8;
const int _MAX_NPCDATA = 4;  // 必须小于_MAX_NPCTASK

//  ITEMDATA_MONOPOLY,
const uint32_t MONOPOLY_MASK = 1;  // 独占, 不可交易, 离开身体消失
const uint32_t STORAGE_MASK =
    1 << 1;  // 存储, 如果设置，则不能存入到物品箱, 乾坤袋
const uint32_t DEAD_DROP_MASK =
    1 << 2;  // 丢弃, 如果设置，死亡一定会掉落, 包括身上装备
const uint32_t BIND_MASK = 1 << 3;  // 绑定, 如果设置，死亡一定不会掉落

const uint32_t IDENT_MASK = 0x01;

const int MAGIC_NONE = 0;
const int GEM_NONE = 0;
const int GEM_HOLE = 255;

// add by zlong 2003-12-02
const int MAX_ADDITION_LEV = 12;    // 追加等级最大为12
const OBJID COMPOSE_STONE = 73000;  // 赤炼石：730001~730009

//////////////////////////////////////////////////////////////////////
const int ITEMREPAIR_PERCENT = 200;  // 修理费为原价的200%
const int ITEMIDENT_PERCENT = 10;    // 鉴定费10%

const int NFORMALDAYS = 5;            // 商人转正天数
const int FORMALBUSINESSSTATE = 255;  // 正式商人状态

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
// 加伤害宝石
const OBJID GEM_DMG_INC_LOW = 700101;
const OBJID GEM_DMG_INC_MID = 700102;
const OBJID GEM_DMG_INC_HGT = 700103;

// 减伤害宝石
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

const OBJID EXP_BALL = 723700;  // 经验值球, 用于存储一个小时的经验

const OBJID CARD_FEE_POINT = 780000;   // game card for fee
const OBJID CARD_FEE_POINT2 = 780001;  // game card for fee
const OBJID CARD_FEE_POINT3 = 780002;  // game card for fee
const OBJID CARD_FEE_POINT4 = 780003;  // game card for fee

const OBJID ITEM_DROPAFTERDIE = 790000;  // 死亡后一定掉的物品

// package
const OBJID ITEM_TREASUREPACK3 = 1100003;
const OBJID ITEM_TREASUREPACK6 = 1100006;
const OBJID ITEM_TREASUREPACK9 = 1100009;

const int INSTANCETYPE_BEGIN_ID = 100000000;  //副本类型起始id

const int ITEMSORT_INVALID = -1;
const int ITEMSORT_EXPEND = 0;                  // 易耗品
const int ITEMSORT_HELMET = 1;                  // 头盔
const int ITEMSORT_NECKLACE = 2;                // 项链
const int ITEMSORT_ARMOR = 3;                   // 盔甲
const int ITEMSORT_WEAPON1 = 4;                 // 单手武器
const int ITEMSORT_WEAPON2 = 5;                 // 双手武器
const int ITEMSORT_SHIELD = 6;                  // 盾牌
const int ITEMSORT_RING = 7;                    // 戒指
const int ITEMSORT_SHOES = 8;                   // 鞋子
const int ITEMSORT_OTHER = 9;                   // 其他, 不能直接使用
const int ITEMSORT_TALISMAN = 10;               // 法宝
const int ITEMSORT_OVERCOAT = 11;               // 外套
const int ITEMSORT_INCREASE_DMG_ARTIFACT = 12;  // 加伤害宝物
const int ITEMSORT_DECREASE_DMG_ARTIFACT = 13;  // 减伤害宝物
const int ITEMSORT_HORSE = 20;                  // 坐骑
//////////////////////////////////////////////////////////////////////
const int ITEMTYPE_INVALID = -1;      // 非法
const int ITEMTYPE_MEDICINE = 00000;  // 补药
const int ITEMTYPE_POISON = 10000;    // 毒药
const int ITEMTYPE_DART = 20000;      // 暗器
const int ITEMTYPE_BOOK = 30000;      // 秘笈
const int ITEMTYPE_NOTUSE = 40000;    // 不用
const int ITEMTYPE_ARROW = 50000;     // 箭矢
const int ITEMTYPE_SPELL = 60000;     // 符咒类
const int ITEMTYPE_NOT_DIRECTUSE =
    70000;  // 不可以双击使用的（如任务物品，宝石，木材等资源类，千位继续分类）
const int ITEMTYPE_EX0 = 80000;  // 扩展0
const int ITEMTYPE_EX1 = 90000;  // 扩展1

//////////////////////////////////////////////////////////////////////
// item sort is ITEMSORT_OTHER, 十万位（第6位）为7
const int ITEMTYPE_GEM = 00000;         // 宝石物品 70xxxx
const int ITEMTYPE_TASKITEM = 10000;    // 任务物品 71xxxx
const int ITEMTYPE_ACTIONITEM = 20000;  // Action物品 72xxxx
const int ITEMTYPE_COMPOSEGEM =
    30000;  // 炼化宝石 73xxxx，用于追加炼化，最后2位表示追加等级
const int ITEMTYPE_GAMECARD = 80000;  // 点卡，月卡 78xxxx
const int ITEMTYPE_DROPITEM = 90000;  // 被杀后一定掉的物品 79xxxx

//////////////////////////////////////////////////////////////////////
// 2003-01-13 10:36:24  黄宇航
// Necklace type define
const int ITEMTYPE_NECKLACE = 00000;  // 项链
const int ITEMTYPE_SACHET = 10000;    // 香袋
const int ITEMTYPE_AMULET = 20000;    // 护身符

// 2003-01-13 10:46:37  黄宇航
// Ring type define
const int ITEMTYPE_RING = 00000;        // 戒指
const int ITEMTYPE_THUMB_RING = 10000;  // 扳指
const int ITEMTYPE_BANGLE = 20000;      // 手镯

// 2003-01-13 11:05:03  黄宇航
// Singlehand Weapon define
const int SWEAPON_NONE = 00000;     // 空手
const int SWEAPON_BLADE = 10000;    // 刀
const int SWEAPON_AXE = 20000;      // 斧
const int SWEAPON_HAMMER = 30000;   // 锤
const int SWEAPON_HOOK = 40000;     // 钩
const int SWEAPON_CLUB = 50000;     // 棒/杵
const int SWEAPON_SWORD = 60000;    // 剑
const int SWEAPON_CRUTCH = 70000;   // 拐
const int SWEAPON_SCOURGE = 80000;  // 鞭/锏
const int SWEAPON_SHORT = 90000;    // 短兵器
// add by zlong 2003-12-02
const int SWEAPON_MSWORD = 21000;  // 法剑

// Doublehand Weapon define
const int DWEAPON_BOW = 00000;      // 弓
const int DWEAPON_BLADE = 10000;    // 刀
const int DWEAPON_AXE = 20000;      // 斧
const int DWEAPON_HAMMER = 30000;   // 锤
const int DWEAPON_HOOK = 40000;     // 钩
const int DWEAPON_STAFF = 50000;    // 棍
const int DWEAPON_SHOVEL = 60000;   // 铲
const int DWEAPON_HALBERD = 70000;  // 戟
const int DWEAPON_FORK = 80000;     // 叉
const int DWEAPON_SPEAR = 90000;    // 枪

//-----------------------------------------------------------------------------
const int _MAX_USERITEMSIZE = 40;
const int _MAX_ALLUSERITEMSIZE = _MAX_USERITEMSIZE + 11;  // 9: 装备数量
const int _MAX_USERFRIENDSIZE = 50;
const int _MAX_TRADE_BUDDY_SIZE = 20;
const int _MAX_REBIRTH_SKILL_NUM = 60;
const int USER_PACKAGE_SIZE = 20;  // 仓库最多存多少东西
const int VIP_STORAGE_SIZE = 5 * 8;  // VIP专用仓库空间大小
const int VIP_STORAGE_NPC_ID = 1015;  // VIP专用仓库NPC
const int TICK_SECS = 10;
const int USERDROPITEM_RANGE = 5;       // 自动掉
const int USERDROPITEM_RANGE2 = 9;      // 手动扔
const int THROW_WEAPON_DROP_RANGE = 1;  // 扔武器攻击可掉物品的范围
const int PILEMONEY_CHANGE = 5000;      // 大量现金变动(需要即时存盘)
const int _ADDITIONALPOINT_NUM = 3;     // 升1级加多少属性点
const int MAX_MENUTASKSIZE = 20;        // 菜单系统中"回答TASK"的最大数量
const int MAX_PKLIMIT = 10000;          // PK值的最大最小限制(防回卷)
const int SLOWHEALLIFE_MS = 1000;       // 吃药补血慢慢补上去的豪秒数。
const int SLOWHEALLIFE_PERCENT =
    10;  // 每次吃药补血tick到时，补的小血量 = MaxLife/SLOWHEALLIFE_PERCENT
const int AUTOHEALLIFE_TIME = 10;       // 每隔10秒自动补血1次。
const int AUTOHEALLIFE_EACHPERIOD = 6;  // 每次补血6。
const int PK_DEC_TIME = 60;             // 降低一点pk值60秒
const int VAMPIRE_DEC_TIME = 1;         //玩家飞行状态每秒降低一点吸血值
const int DRAW_ANGEL_TIME = 30;         //领取天使时间需要在集结点待的时间
const int ANGEL_BREAK_OUT = 300;        //天使爆发时间
const int ANGEL_PERSIST_TIME = 60;      //天使状态持续时间
const int ANGEL_EXP_PER = 10;           //天使每次爆发所获得的经验值
const int SKILL_FLY_ID = 900100;        //玩家飞行技能ID
const int TIME_TEAMPRC = 5;             // 队伍信息处理的时间
const int DURABILITY_DEC_TIME = 5;      // 按时间消耗的装备耐久度
const int USER_ATTACK_SPEED = 800;      // 玩家徒手攻击频率
const int POISONDAMAGE_INTERVAL = 2;    // 中毒每2秒伤血一次
const int CRIME_KEEP_SECS = 15;         // 犯罪维持时间
const int SYNCRIME_KEEP_SECS = 30;      // 帮派犯罪维持时间
const int ARROW_FLY_ALT = 60;           // 箭支飞行高度
const int JUMP_ALT = 200;               // 跳的最高高度
const int FLY_ALT = 100;                // 飞的最高高度
const int PERCENT_DECDUR = 5;           // 装备升级失败后渐耐久的几率

const int PKVALUE_HALFKILL = 2;
const int PKVALUE_ONEKILL = 10;
const int PKVALUE_REDNAME = 30;
const int PKVALUE_BLACKNAME = 100;
const int PKVALUE_ENEMY = 5;
const int PKVALUE_SYN_ENEMY = 3;

const int CHANCE_MAKEHOLE_UPLEVEL = 1200;   // 装备升等级时的出洞机率(1 / 1200)
const int CHANCE_MAKEHOLE_UPQUALITY = 300;  // 装备升品质时的出洞机率(1 / 300)

const int SUPERMAN_KILLMONSTER_INCTIME = 1;  // 无双状态每杀一个怪物的加时(S)
const int SUPERMAN_KILLMONSTER_TIMELIMIT = 120;  // 无双状态延长的时间限制(S)
const int TORNADO_KILLMONSTER_INCTIME = 1;      // 旋风状态每杀一个怪物的加时(S)
const int TORNADO_KILLMONSTER_TIMELIMIT = 120;  // 旋风状态延长的时间限制(S)

const int MASK_CHANGELOOK =
    100000000;  // 变身时LOCKFACE的掩码，face=face + new_face*10000000
const int MAX_SIZEADD =
    2;  // 最大的SizeAdd，用于魔法区域的放大搜索(注意该数据不要太大)

const int CHANGE_MONSTER_TIME = 500;  // 怪物变身的时间

const int CHGMAP_LOCK_SECS = 10;            // 进入地图后的保护时间
const int SYNWAR_NOMONEY_DAMAGETIMES = 10;  // 帮派没钱时增加的伤害倍数
const int PICK_MORE_MONEY = 1000;           // 捡钱多时，发ACTION消息
const int SYNCHRO_SECS = 5;                 // 同步消息5秒内同步

const int VERIFY_DATA_SECS = 60 * 10;  // 10分钟检查一次数据

const int ONLINE_TRAINING_INTERVAL = 60;   // 在线练功每分种增加十个练功点
const int CHECKBATTLEEFFECT_INTERVAL = 5;  // 5秒检测一次战斗力变化
const int CONTRIBUTE_INTERVAL = 60 * 5;    // 5分钟贡献一次经验

const int STATUS_MAINTAINALLWAYS =
    86400;  // 状态维持时间需要设置为为无限，那么就取24小时的时限

const int TEAM_ROLEPLAYING_INSTONE_SEC = 3000;  // 队伍角色扮演吟唱时间

const int WALLOW_INTERVAL = 1 * 60;  // 防沉迷系统每1分钟检测一次1 * 60
const int WALLOW_INTERVAL_SEND =
    15 * 60;  // 防沉迷系统累计在线时间每15分钟发送一次15 * 60
const int WALLOW_POINT = 3 * 60;    // 防沉迷系统每3分钟算一个在(离)线点60 * 3
const int WALLOW_FULL_POINT = 60;   // 防沉迷系统全收益状态点数60
const int WALLOW_HALF_POINT = 100;  // 防沉迷系统半收益状态点数100

const int DEFAULT_LOGIN_MAPGROUP = 0;  // 登录点
const int DEFAULT_LOGIN_MAPID = 1102;  // 登录点
const int DEFAULT_LOGIN_POSX = 600;    // 登录点
const int DEFAULT_LOGIN_POSY = 1102;   // 登录点

const int CELLS_PER_BLOCK = 18;  // 每ROOM的格子数
const int CELLS_PER_VIEW = 18;   // 可视区域的格子数
// const int  ITEMTYPEMONEY_MIN     = 1090000;    //
// 最小堆钱
// const int  ITEMTYPEMONEY_MAX     = 1091020;    //
// 最大堆钱
// const int  SMALLHEAPMONEY_LIMIT    = 10;     //
// 小堆钱
// const int  SMALLHEAPMONEY_TYPE     = 1090000;    //
// 小堆钱ITEMTYPE
// const int  MIDDLEHEAPMONEY_LIMIT   = 100;      //
// 中堆钱
// const int  MIDDLEHEAPMONEY_TYPE    = 1090010;    //
// 中堆钱ITEMTYPE
// const int  BIGHEAPMONEY_LIMIT      = 1000;     //
// 大堆钱
// const int  BIGHEAPMONEY_TYPE     = 1090020;    //
// 大堆钱ITEMTYPE

// const int  SMALLHEAPGOLD_LIMIT     = 2000;     //
// 小堆金子
// const int  SMALLHEAPGOLD_TYPE      = 1091000;    //
// 小堆金子ITEMTYPE
// const int  MIDDLEHEAPGOLD_LIMIT    = 5000;     //
// 中堆金子
// const int  MIDDLEHEAPGOLD_TYPE     = 1091010;    //
// 中堆金子ITEMTYPE
// const int  BIGHEAPGOLD_LIMIT     = 10000;    //
// 大堆金子
// const int  BIGHEAPGOLD_TYPE      = 1091020;    //
// 大堆金子ITEMTYPE

const I64 MONEY_LIMIT = 1000000000;  // 1 billion
const int EMONEY_LIMIT = 100000000;  // 100 million

const int LEAVEFROMLOTTERY_MAP_ID = 8614;
const int PRACTISESKILL_MAP_ID = 601;         // 离线练功场地图
const int PRACTISESKILLONLINE_MAP_ID = 1039;  // 练功场地图
const int STARWAR_MAP_ID_FIRST = 100000;
const int STARWAR_MAP_ID_END = 200000;
const OBJID COPYMAPGEN_FIRST = 4000000001;  // 副本地图生成器第一个ID
const OBJID DYNAMEMMAP_FIRST = 4000000001;  // DYNAMEMMAP的第一个ID
const OBJID DYNAMEMMAP_LAST = 4294967295;   // DYNAMEMMAP的最后一个ID
// const int  WHITE_SYN_MAP_ID  = 10380;
// // 白帮地图
const int BLACK_SYN_MAP_ID = 10000;  // 黑帮地图
const int NEWBIE_MAP_ID = 1000;      // 新手村地图

const int _MAX_BONUTY = 9999999;
const int _MIN_BONUTY = 100000;
const int _MIN_ADDBONUTY = 10000;
const int _WANTED_ORDERCOST = 1000;
const int _BONUTY_TAX = 30;
const int _MAX_ACTION_VAR = 8;
const int _MAX_UNLEARN_NUMBER = 20;

const int MAX_SYNENEMYSIZE = 5;  // 一共5个敌对帮派空间
const int MAX_SYNALLYSIZE = 5;   // 一共5个结盟帮派空间

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
const int VETERAN_DIFF_LEV = 20;  // 老手的等级差

const int IDOWNER0 = 12;     // 远程仓库
const int IDOWNER1 = 44;     // 市场仓库
const int IDOWNER2 = 8;      // 双龙城仓库
const int IDOWNER3 = 10011;  // 云门关仓库
const int IDOWNER4 = 10012;  // 鸣凤堡仓库
const int IDOWNER5 = 10027;  // 白鹭城仓库
const int IDOWNER6 = 10028;  // 黑虎城仓库
const int IDOWNER7 = 4101;   // 沙漠小城仓库

const int MAGICDAMAGE_ALT = 26;               // 法术效果的高差限制
const int AUTOLEVELUP_EXP = -1;               // 自动升级的标志
const int DISABLELEVELUP_EXP = 0;             // 不升级的标志
const int AUTOMAGICLEVEL_PER_USERLEVEL = 10;  // 每10级，法术等级加一级
const int USERLEVELS_PER_MAGICLEVEL = 10;     // 玩家等级必须是法术等级的10倍
const int KILLBONUS_PERCENT = 5;              // 杀死怪物的额外EXP奖励
const int AWARDEXP_PER_MAGIC = 10;         // 技能经验改为每使用一次技能获得10点
const int MAGIC_DELAY = 1000;              // 魔法DELAY
const int MAGIC_DECDELAY_PER_LEVEL = 100;  // 每个“法术等级”减少的魔法DELAY
const int RANDOMTRANS_TRY_TIMES = 10;      // 随机瞬移的尝试次数
const int DISPATCHXP_NUMBER = 20;          // 加XP的数量
const int COLLIDE_POWER_PERCENT = 80;      // 冲撞增加攻击力的百分比
const int COLLIDE_SHIELD_DURABILITY = 2;   // 冲撞要减少的盾牌寿命
const int LINE_WEAPON_DURABILITY = 2;      // 直线攻击要减少的武器寿命
const int MAX_SERIALCUTSIZE = 10;          // 顺势斩的数量
const int AWARDEXP_BY_TIMES = 1;           // 按次数加经验值
const int AUTO_MAGIC_DELAY_PERCENT = 150;  // 连续魔法攻击时增加的DELAY
const int BOW_SUBTYPE = 500;               // 弓的SUBTYPE
const int POISON_MAIGC_TYPE = 10010;       // use for more status

const I64 MAX_PLAYER_EXP = 9223372036854775800;   // 玩家最大经验值
const I64 MIN_PLAYER_EXP = -9223372036854775800;  // 玩家最小经验值

const INT LOGIN_FREE_LEVEL = 16;

const int ALTAR_WIDTH = 3;   //祭坛宽度,暂定
const int ALTAR_HEIGHT = 3;  //高度

const int USERSTAMINA_BASE = 5000;  //玩家死亡复活后精力重置值 09-12-22
const int USERSTAMINA_MAX = 10000;  //玩家死亡复活后精力最大值 09-12-22

const int MAX_DEFPACKWIDTH = 8;   //请程序放开货舱10×15的限制 tcp 2007-1-23 add
const int MAX_DEFPACKHEIGHT = 5;  //请程序放开货舱10×15的限制 tcp 2007-1-23 add
const int MAX_DEFPACKSIZE = MAX_DEFPACKWIDTH * MAX_DEFPACKHEIGHT;

//////////////////////////////////////////////////////////////////////
// 外部状态，需要通过MsgPlayer通知其它玩家的状态。与客户端同步
const uint64_t KEEPEFFECT_NORMAL = 0x0000000000000000;
const uint64_t KEEPEFFECT_CRIME = 0x0000000000000001;
const uint64_t KEEPEFFECT_DIE = 0x0000000000000002;
const uint64_t KEEPEFFECT_TEAMLEADER = 0x0000000000000004;
const uint64_t KEEPEFFECT_GHOST = 0x0000000000000008;
const uint64_t KEEPEFFECT_DISAPPEARING = 0x0000000000000010;
const uint64_t KEEPEFFECT_RED = 0x0000000000000020;  // PK开关
const uint64_t KEEPEFFECT_WING = 0x0000000000000040;
const uint64_t KEEPEFFECT_STARWAR_LEADER = 0x0000000000000080;
const uint64_t KEEPEFFECT_STOPALL = 0x0000000000000100;     // 晕
const uint64_t KEEPEFFECT_POISON = 0x0000000000000200;      // 毒
const uint64_t KEEPEFFECT_ATTACK = 0x0000000000000400;      // 弱
const uint64_t KEEPEFFECT_DEFENCE = 0x0000000000000800;     // 虚
const uint64_t KEEPEFFECT_MOVESLOWLY = 0x0000000000001000;  // 缓
const uint64_t KEEPEFFECT_STOPFIGHT = 0x0000000000002000;   // 封
const uint64_t KEEPEFFECT_STOPMOVE = 0x0000000000004000;    // 停
const uint64_t KEEPEFFECT_UNDERWRAPS = 0x0000000000008000;  // 隐

const uint64_t KEEPEFFECT_SHIELD = 0x0000000000010000;        // 防御罩效果 状态
const uint64_t KEEPEFFECT_GUARDIANSHIP = 0x0000000000020000;  // 守护 状态
const uint64_t KEEPEFFECT_SLEEP = 0x0000000000040000;         // 睡
const uint64_t KEEPEFFECT_DAMAGE_REDUCE =
    0x0000000000040000;  //全地图队伍受伤害减少效果

const uint64_t KEEPEFFECT_INVINCIBLE = 0x0000000000080000;      // 无敌状态
const uint64_t KEEPEFFECT_FETCH_BURST = 0x0000000000100000;     // 魂爆状态
const uint64_t KEEPEFFECT_POISONRANGE = 0x0000000000200000;     // 毒环状态
const uint64_t KEEPEFFECT_ADJUSTTOGETHER = 0x0000000000400000;  // 调和
const uint64_t KEEPEFFECT_KILLLINEUP = 0x0000000000800000;      // 杀阵
const uint64_t KEEPEFFECT_CRAZYFIGHTER = 0x0000000001000000;    // 狂战士状态
const uint64_t KEEPEFFECT_MULTISELECT =
    0x0000000002000000;  // 被多目标选择上的对象状态
const uint64_t KEEPEFFECT_PKSWITCH =
    0x0000000004000000;  // 被多目标选择上的对象状态

const uint64_t KEEPEFFECT_FLOATCANNON_ATTACK =
    0x0000000008000000;  //浮游炮 攻击状态
const uint64_t KEEPEFFECT_FLOATCANNON_REINFORCE =
    0x0000000010000000;  //浮游炮 援助状态
const uint64_t KEEPEFFECT_FLOATCANNON_COUNTERSTROKE =
    0x0000000020000000;  //浮游炮 反击状态
const uint64_t KEEPEFFECT_ELECTROMCANNON_ATTACK =
    0x0000000040000000;  //电磁炮 攻击状态
const uint64_t KEEPEFFECT_VAMPIRE_UNDER_SUNSHINE =
    0x0000000080000000;  // 吸血鬼被太阳晒的状态const uint64_t
                         // KEEPEFFECT_ELECTROMCANNON_REINFORCE
                         // =0x0000000080000000;  //电磁炮 援助状态
/*const uint64_t    KEEPEFFECT_ELECTROMCANNON_COUNTERSTROKE
 * =0x0000000100000000; //电磁炮 反击状态*/
const uint64_t KEEPEFFECT_DYING_RANGE = 0x0000000100000000;  //濒死狂暴
const uint64_t KEEPEFFECT_AWARD_ANGEL = 0x0000000100000000;  //天使状态

const uint64_t KEEPEFFECT_BUSY_LevupInterface =
    0x0000000200000000;  // 技能升级界面（全屏界面）忙碌状态
const uint64_t KEEPEFFECT_POWERCRAZYFIGHTER =
    0x0000000400000000;                                // 真狂战士状态
const uint64_t KEEPEFFECT_MOUNT = 0x0000000800000000;  // 交易中的状态
const uint64_t KEEPEFFECT_FLAMETHROWER =
    0x0000001000000000;                                 //火焰喷射器连续攻击状态
const uint64_t KEEPEFFECT_XPFULL = 0X0000002000000000;  // xp full status.
const uint64_t KEEPEFFECT_PURPLE = 0x0000004000000000;  // 紫名的状态
const uint64_t KEEPEFFECT_WATCH_STARWAR = 0x0000008000000000;  // 观战状态
// const uint64_t   KEEPEFFECT_SHOT_DELAY
// =0x0000008000000000; // 机体子弹用光，延迟2秒才能射击
const uint64_t KEEPEFFECT_DEEPRED =
    0X0000010000000000;  //红名  //黑名通过红、黄名复用实现
const uint64_t KEEPEFFECT_USERSTATUS_CURSE = 0X0000020000000000;  //诅咒状态
const uint64_t KEEPEFFECT_USERSTATUS_PRACTISE =
    0X0000040000000000;  //在线练功状态
const uint64_t KEEPEFFECT_VAMPIRE_UNDER_SAINT_LIGHT =
    0X0000080000000000;  // 吸血鬼被圣光照射状态  const uint64_t
                         // KEEPEFFECT_SUPPRESS
                         // =0X0000080000000000;  //压制状态
const uint64_t KEEPEFFECT_FREEZE = 0X0000100000000000;  //冷冻状态

const uint64_t KEEPEFFECT_DODGE = 0X0000100000000000;  //分身躲避状态

const uint64_t KEEPEFFECT_SELFPROTECT = 0x0000200000000000;  //自动防护状态
const uint64_t KEEPEFFECT_LOCKATTACK = 0x0000400000000000;   //锁定攻击状态
const uint64_t KEEPEFFECT_SYMBOL = 0x0000800000000000;       //共和国徽章状态
const uint64_t KEEPEFFECT_TRANSLOOK = 0x0001000000000000;    //狼人一级状态
const uint64_t KEEPEFFECT_FLYMAP =
    0x0002000000000000;  //切屏零时状态服务器和客户端独立清除
const uint64_t KEEPEFFECT_BAITMONSTER = 0x0004000000000000;  // 狼人二级状态
const uint64_t KEEPEFFECT_UPMODELLEV_USEITEM =
    0x0008000000000000;  //使用物品进行星级升级
const uint64_t KEEPEFFECT_USERSTATUS_DIVE = 0x0010000000000000;  //潜水
const uint64_t KEEPEFFECT_PK_CHAMPION1 =
    0x0020000000000000;  // pk赛 超级冠军状态
const uint64_t KEEPEFFECT_PK_CANDICATE1 =
    0x0040000000000000;  // pk赛 超级入围状态
const uint64_t KEEPEFFECT_PK_CHAMPION2 =
    0x0080000000000000;  // pk赛 高级冠军状态
const uint64_t KEEPEFFECT_PK_CANDICATE2 =
    0x0100000000000000;  // pk赛 高级入围状态
const uint64_t KEEPEFFECT_PK_CHAMPION3 =
    0x0200000000000000;  // pk赛 中级冠军状态
const uint64_t KEEPEFFECT_PK_CANDICATE3 =
    0x0400000000000000;  // pk赛 中级入围状态
const uint64_t KEEPEFFECT_LURK =
    0x0800000000000000;  //玩家伏击 vampire 法宝-反重力悬浮
const uint64_t KEEPEFFECT_BE_DELAY_REBORN_BY_OTHER =
    0x1000000000000000;  //法宝-延长对手机体被其它人复活时间(秒)
const uint64_t KEEPEFFECT_TRUMP_SELFBLAST_DECBATTLEEFFECT =
    0x2000000000000000;  //法宝-自爆降敌人战斗力功能
const uint64_t KEEPEFFECT_TRANSFORMVALUEFULL =
    0X4000000000000000;                                // 变形值满状态.
const uint64_t KEEPEFFECT_CHAOS = 0x4000000000000000;  //混乱

const uint64_t KEEPEFFECT_FIRST_NIMBUS =
    0X8000000000000000;  // 第一名灵气排行榜状态
// delete---begin
const uint64_t KEEPEFFECT_ATKRANGE = 0X1000000000000000;  // 增加攻击范围的状态?
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
const uint64_t KEEPEFFECT_SELFDEFENCE = 0X1000000000000000;  //正当防卫
const uint64_t KEEPEFFECT_HITRATE = 0X1000000000000000;
const uint64_t KEEPEFFECT_MAGICDEFENCE = 0X1000000000000000;
const uint64_t KEEPEFFECT_BOWDEFENCE = 0X1000000000000000;
const uint64_t KEEPEFFECT_SUPERMAN = 0X1000000000000000;
const uint64_t KEEPEFFECT_TORNADO = 0X1000000000000000;
// delte---end

// 扩展状态定义   第二个64位
const uint64_t USERSTATUSEX_RAPTOR_LEV1 = 0x0000000000000001;  // 猛禽变异一级
const uint64_t USERSTATUSEX_RAPTOR_LEV2 = 0x0000000000000002;  // 猛禽变异二级

const uint64_t USERSTATUSEX_BAT_LEV1 = 0x0000000000000004;  // 蝙蝠变异一级
const uint64_t USERSTATUSEX_BAT_LEV2 = 0x0000000000000008;  // 蝙蝠变异二级

const uint64_t USERSTATUSEX_SHARK_LEV1 = 0x0000000000000010;  // 鲨鱼变异一级
const uint64_t USERSTATUSEX_SHARK_LEV2 = 0x0000000000000020;  // 鲨鱼变异二级

const uint64_t USERSTATUSEX_DOLPHIN_LEV1 = 0x0000000000000040;  // 海豚变异一级
const uint64_t USERSTATUSEX_DOLPHIN_LEV2 = 0x0000000000000080;  // 海豚变异二级

const uint64_t USERSTATUSEX_BEAR_LEV1 = 0x0000000000000100;  // 熊基因变异一级
const uint64_t USERSTATUSEX_BEAR_LEV2 = 0x0000000000000200;  // 熊基因变异二级

const uint64_t USERSTATUSEX_LEOPARD_LEV1 =
    0x0000000000000400;  // 豹基因变异一级
const uint64_t USERSTATUSEX_LEOPARD_LEV2 =
    0x0000000000000800;  // 豹基因变异二级

const uint64_t USERSTATUSEX_CATTLE_LEV1 = 0x0000000000001000;  // 牛基因变异一级
const uint64_t USERSTATUSEX_CATTLE_LEV2 = 0x0000000000002000;  // 牛基因变异二级

const uint64_t USERSTATUSEX_DOMAIN_LIGHT = 0x0000000000004000;  // 领域状态
const uint64_t USERSTATUSEX_DOMAIN_NO_ENERGY_INCREASE =
    0x0000000000008000;  //领域技能—禁止恢复体力的范围领域
const uint64_t USERSTATUSEX_DOMAIN_MAP_SYN_ADD_DAMAGE =
    0x0000000000010000;  //领域技能—全地图领域军团加伤害
const uint64_t USERSTATUSEX_DOMAIN_FIELD_SYN_ADD_DAMAGE =
    0x0000000000020000;  //领域技能—范围全员伤害增加领域
const uint64_t USERSTATUSEX_DOMAIN_FIELD_DAYTIME =
    0x0000000000040000;  //领域技能—范围白天领域
// 技能状态
const uint64_t USERSTATUSEX_HERO_WHIRLWIND_USEING =
    0x0000000000080000;  //人族骑士旋风斩使用状态
const uint64_t USERSTATUSEX_HERO_WHIRLWIND_AFFECT =
    0x0000000000100000;  //人族骑士旋风斩被影响状态
const uint64_t USERSTATUSEX_USER_CAN_CONJURE_DEVIL =
    0x0000000000200000;  // 任意进行下一次召唤恶魔

const uint64_t USERSTATUSEX_SKILL_FREEZING =
    0x0000000000400000;  //新的技能冰冻状态
const uint64_t USERSTATUSEX_SKILL_BURNING =
    0x0000000000800000;  //新的技能灼烧状态
const uint64_t USERSTATUSEX_SKILL_BLEEDING =
    0x0000000001000000;  //新的技能流血状态

const uint64_t USERSTATUSEX_SKILL_MOVESPEEDREDUCE =
    0x0000000002000000;  //新的技能移动速度降低状态
const uint64_t USERSTATUSEX__SKILL_BLOODSHADOWSTEP =
    0x0000000004000000;  //新的血影步状态

const uint64_t USERSTATUSEX_SKILL_JUSTICE =
    0x0000000008000000;  //新的技能审判状态
const uint64_t USERSTATUSEX_SKILL_SAN_SHIELD =
    0x0000000010000000;  //新的技能神圣护盾状态
const uint64_t USERSTATUSEX_SKILL_WITHBOMB =
    0x0000000020000000;  //新的技能炸弹附身状态
const uint64_t USERSTATUSEX_SKILL_SHOTGUNSPEEDYCHANGEBULLET =
    0x0000000040000000;  //换弹夹散弹枪加快状态
const uint64_t USERSTATUSEX_SKILL_LIGHTNING_SHAKE =
    0x0000000080000000;  //新的技能电击状态
const uint64_t USERSTATUSEX_SKILL_ADD_LIFE =
    0x0000000100000000;  //新的技能补血状态
const uint64_t USERSTATUSEX_SKILL_DIZZY =
    0x0000000200000000;  //新的技能眩晕状态

//合并吸血鬼代码，冲突，原值为：
// const uint64_t   USERSTATUSEX_STATUS_CAP          =
// 0X0000000010000000;//普通状态
// const uint64_t   USERSTATUSEX_STATUS_CAPPOWER         =
// 0X0000000020000000;//强化状态
const uint64_t USERSTATUSEX_STATUS_CAP = 0X0000000010000000;       //普通状态
const uint64_t USERSTATUSEX_STATUS_CAPPOWER = 0X0000000020000000;  //强化状态
// ongoing

//////////////////////////////////////////////////////////////////////////
// 区域 相关的 Mask
const uint64_t REGION_SUN_SHINE_MASK = 1ull
                                       << 0;  //  Type = 65536，有阳光的区域
const uint64_t REGION_SAINT_LIGHT_MASK =
    1ull << 1;  // 处于教堂内时，使吸血鬼进入“吸血鬼被圣光照射状态”。
const uint64_t REGION_CITY_MASK = 1ull << 2;  //城市区域，组队经验不分享区域
const uint64_t REGION_WEATHER_MASK = 1ull << 3;
const uint64_t REGION_STATUARY_MASK = 1ull << 4;
const uint64_t REGION_DESC_MASK = 1ull << 5;
const uint64_t REGION_PK_PROTECTED_MASK = 1ull << 6;
const uint64_t REGION_BOOTH_MASK = 1ull << 7;   // data0: level of booth
const uint64_t REGION_OFFSET_MASK = 1ull << 8;  //移屏区域(下传给客户端)
const uint64_t REGION_MARKET_MASK = 1ull << 9;  //市场区域，组队经验不分享区域
const uint64_t REGION_RECORDPOS_DISABLE_MASK = 1ull << 10;  //不存记录点
const uint64_t REGION_DISABLE_TRUMP_REBORN_MASK = 1ull
                                                  << 11;  //禁止使用法宝复活技能
const uint64_t REGION_DISABLE_MOUNT_MASK = 1ull << 12;    //骑宠限制
const uint64_t REGION_SWEAR_MASK = 1ull << 13;            //结拜区域
const uint64_t REGION_DISABLE_CALLALTAR_MASK = 1ull << 14;  //禁止召唤祭坛区域
const uint64_t REGION_COM_ALTAR_MASK = 1ull << 15;          //公共祭坛区域
const uint64_t REGION_PRIVATE_ALTAR_MASK = 1ull << 16;      //玩家召唤祭坛区域
const uint64_t REGION_DISABLE_FLY_MASK = 1ull << 17;        //禁止飞行区域
const uint64_t REGION_ANGEL_DRAW_MASK = 1ull << 18;         //天使领取区
const uint64_t REGION_BATTLE_MASK =
    1ull << 19;  //战斗区域 // TODO::MILO 11/9/2015
                 //这里原代码是跟上一个一样的18？是否有误？这里改成了19
// To be Continued

//物品特有的状态
const uint64_t KEEPEFFECT_HEADLOOP_WIEW_LEADER_POSITION =
    0x0000000000000010;  //头部回路显示队长位置
const uint64_t KEEPEFFECT_HEADLOOP_WIEW_TEAM_POSITION =
    0x0000000000000008;  //头部回路显示队长位置
//////////////////////////////////////////////////////////////////////
// 综合状态

const uint64_t KEEPEFFECT_NOT_ACTIVE = KEEPEFFECT_DIE | KEEPEFFECT_FREEZE;
const uint64_t KEEPEFFECT_NOT_CLEAR = KEEPEFFECT_TEAMLEADER | KEEPEFFECT_RED |
                                      KEEPEFFECT_DEEPRED | KEEPEFFECT_PURPLE |
                                      KEEPEFFECT_USERSTATUS_PRACTISE |
                                      KEEPEFFECT_SYMBOL;  // 玩家死亡不清此状态

const uint64_t KEEPEFFECT_EVIL_STATUS =
    KEEPEFFECT_CRIME | KEEPEFFECT_DEEPRED | KEEPEFFECT_SYNCRIME;

//////////////////////////////////////////////////////////////////////
// 内部状态，不需要通过MsgPlayer通知其它玩家的状态。服务器内部使用(magictype使用)

// const uint64_t STATUS_NORMAL       = 0ull;
// const uint64_t STATUS_DIE          = 1ull;     //
// 死亡
// const uint64_t STATUS_CRIME        = 1ull << 1;
// const uint64_t STATUS_POISON       = 1ull << 2;    //
// 中毒
// const uint64_t STATUS_TEAMLEADER     = 1ull << 3;
// const uint64_t STATUS_PKVALUE        = 1ull << 4;    //
// PK状态
// const uint64_t STATUS_HITRATE        = 1ull << 5;    //
// 命中率
// const uint64_t STATUS_DEFENCE        = 1ull << 6;    //
// 防御
// const uint64_t STATUS_ATTACK       = 1ull << 7;    //
// 攻击力
// const uint64_t STATUS_DISAPPEARING   = 1ull << 8;    // 消失
// const uint64_t STATUS_MAGICDEFENCE   = 1ull << 9;    //
// 魔法防御
// const uint64_t STATUS_BOWDEFENCE     = 1ull << 10;   //
// 弓防御
// const uint64_t STATUS_ATKRANGE     = 1ull << 11;   //
// 攻击范围
// const uint64_t STATUS_REFLECT        = 1ull << 12;   //
// 物理反射
// const uint64_t STATUS_SUPERMAN     = 1ull << 13;   //
// 战士xp
// const uint64_t STATUS_WEAPONDAMAGE   = 1ull << 14;   //
// 武器伤害
// const uint64_t STATUS_MAGICDAMAGE      = 1ull << 15;   //
// 魔法伤害
// const uint64_t STATUS_ATKSPEED     = 1ull << 16;   //
// 攻击速度
// const uint64_t STATUS_LURKER       = 1ull << 17;   //
// 隐身
// const uint64_t STATUS_TORNADO        = 1ull << 18;   //
// 勇士xp
// const uint64_t STATUS_SYNCRIME     = 1ull << 19;   //
// 帮派犯罪
// const uint64_t STATUS_REFLECTMAGIC   = 1ull << 20;   //
// 魔法反射
// const uint64_t STATUS_DODGE        = 1ull << 21;   //
// 躲避
// const uint64_t STATUS_WING       = 1ull << 22;   //
// 飞行
// const uint64_t STATUS_KEEPBOW        = 1ull << 23;   //
// 蓄力
// const uint64_t STATUS_STOP       = 1ull << 24;   //
// 移动不能
// const uint64_t STATUS_LUCK_SPREAD      = 1ull << 25;   //
// 祈福
// const uint64_t STATUS_LUCK_ABSORB      = 1ull << 26;   //
// 吸福
// const uint64_t STATUS_CURSE        = 1ull << 27;   //
// 诅咒
// const uint64_t STATUS_GODBLESS     = 1ull << 28;   //
// 祝福
// const uint64_t STATUS_SYN_LEADER     = 1ull << 29;   //
// 帮派战帮主状态
// const uint64_t STATUS_SYN_ASSISTANT    = 1ull << 30;   //
// 帮派战副帮主状态
// const uint64_t STATUS_PK_CHAMPION_MONTH  = 1ull << 31;   //
// 月pk赛冠军
// const uint64_t STATUS_PK_CHAMPION_WEEK = 1ull << 32;   //
// 周pk赛冠军
// const uint64_t STATUS_PK_PROF_SOLDIER    = 1ull << 33;   //
// 职业pk赛 (战)
// const uint64_t STATUS_PK_PROF_WARRIOR    = 1ull << 34;   //
// 职业pk赛 (勇)
// const uint64_t STATUS_PK_PROF_ARCHER   = 1ull << 35;   //
// 职业pk赛 (弓)
// const uint64_t STATUS_PK_PROF_DAOISTWATER  = 1ull << 36;   //
// 职业pk赛 (水道)
// const uint64_t STATUS_PK_PROF_DAOISTFIRE = 1ull << 37;   //
// 职业pk赛 (火道)
// const uint64_t STATUS_PK_PROF_RENZHE   = 1ull << 38;   //
// 职业pk赛 (忍者)
//
// const uint64_t STATUS_DETACH_BADLY   = STATUS_CRIME;
// // 复用，清除所有不良状态
// const uint64_t STATUS_DETACH_ALL     = STATUS_TEAMLEADER;
// // 复用，清除所有魔法状态

const int DEFAULT_MONSTER_MAGIC_LEVEL = 0;

const unsigned char RMB_LOG_VIP_SHOP = 0;  //为从VIP商店购买物品的记录。
const unsigned char RMB_LOG_ACTION_ADD =
    1;  //为action改变增加；代币系统emoneyLOG调整 tcp 2007-1-11
const unsigned char RMB_LOG_TRADE = 2;          //为公平交易获得；
const unsigned char RMB_LOG_BOOTH = 3;          //为摆摊获得；
const unsigned char RMB_LOG_VENDUE = 4;         //为拍卖获得；
const unsigned char RMB_LOG_LOST = 5;           //为收钱失败；
const unsigned char RMB_LOG_CHECKOUT_RMB = 6;   //为从card表的记录兑换成代币；
const unsigned char RMB_LOG_CHECKIN_RMB = 7;    //为从代币兑换成card表的记录；
const unsigned char RMB_LOG_CHECKOUT_RMB2 = 8;  //为从card2表的记录兑换成代币；
const unsigned char RMB_LOG_CHECKIN_RMB2 = 9;   //为从代币兑换成card2表的记录。
const unsigned char RMB_LOG_ADD_BOOTH_DEPOSIT = 10;  //追加摆摊押金
const unsigned char RMB_LOG_ACTION_DEC =
    11;  //为action改变减少；代币系统emoneyLOG调整 tcp 2007-1-11
const unsigned char RMB_LOG_PURCHASE_BOOTH = 12;   //太阳石并购摊位
const unsigned char RMB_LOG_SATELLITE = 13;        //卫星广播
const unsigned char RMB_LOG_AutoExercise = 14;     //环保练功
const unsigned char RMB_LOG_TransRandPos = 15;     //快速传送
const unsigned char RMB_LOG_WEAPONSKILL_ADD = 16;  //增加武器熟练度
const unsigned char RMB_LOG_ROBOTSKILL_ADD = 17;   //增加机体熟练度
const unsigned char RMB_LOG_MAGICSKILL_ADD = 18;   //增加技能熟练度
const unsigned char RMB_LOG_PK_PUBLISH =
    19;  // PK惩罚 PK惩罚补充案 tcp 2007-3-15 add
const unsigned char RMB_LOG_MODEL_LEV_DEC_COLD_STATUS =
    20;                                            //战斗星级冷却状态时间减少
const unsigned char RMB_LOG_TRUMP_MAKE_HOLE = 21;  //法宝 直接使用太阳石进行开洞
const unsigned char RMB_LOG_REPAIR_DESTROYOBJ = 22;   //帮派战修理可破坏物件
const unsigned char RMB_LOG_BUY_STONE2 = 23;          //购买紫水晶
const unsigned char RMB_LOG_UPDATE_NIMBUS = 24;       //使用太阳时加机体灵气
const unsigned char RMB_LOG_BUY_ORDER = 25;           //买单花太阳石
const unsigned char RMB_LOG_MODIFY_ORDER_GAIN = 26;   //修改买单返回太阳石
const unsigned char RMB_LOG_MODIFY_ORDER_SPEND = 27;  //修改买单扣太阳石
const unsigned char RMB_LOG_DEL_BUY_ORDER = 28;       //取消买单返回太阳石
const unsigned char RMB_LOG_INCOME = 29;              //交易收入表中获得太阳石
const unsigned char RMB_LOG_GUARD_REBORN = 30;        //侍卫复活
const unsigned char RMB_LOG_EAT_EXPBALL = 31;         //吃经验球
const unsigned char RMB_LOG_DONATE = 32;              //爵位捐献
const unsigned char RMB_LOG_PRIZE = 33;               //领奖系统
const unsigned char RMB_LOG_AUCTION_BID = 34;         //拍卖出价
const unsigned char RMB_LOG_FAMILYWAR_TRUCE = 35;     //占领战免战费用
const unsigned char RMB_LOG_AUCTION_RETURN = 36;      //拍卖不到物品时返还
const unsigned char RMB_LOG_CREATE_INSTANCE = 37;     //创建副本消耗
//////////////////////////////////////////////////////////////////////
const unsigned char EMONEY_LOG_REPAIR = 0;     //修理装备
const unsigned char EMONEY_LOG_BUY = 1;        //普通商店买物品
const unsigned char EMONEY_LOG_BUY_BOOTH = 2;  //并购摊位
const unsigned char EMONEY_LOG_ACTION = 3;  // action扣除
//////////////////////////////////////////////////////////////////////
const unsigned char STONE_LOG_UPGARE_MODELLEV = 0;  //提升战斗力星级
const unsigned char STONE_LOG_STONE_SHOP = 1;       //水晶商店消费
const unsigned char STONE_LOG_ACTION = 2;  // action扣除
//////////////////////////////////////////////////////////////////////

const unsigned char EMONEY3_LOG_VIP_SHOP = 100;    //为从VIP商店购买物品的记录。
const unsigned char EMONEY3_LOG_ACTION_ADD = 101;  //为action改变增加；
const unsigned char EMONEY3_LOG_ACTION_DEC = 111;  //为action改变减少；
const unsigned char EMONEY3_LOG_SATELLITE = 113;   //卫星广播(飞鸽)
const unsigned char EMONEY3_LOG_WEAPONSKILL_ADD = 116;  //增加武器熟练度
const unsigned char EMONEY3_LOG_ROBOTSKILL_ADD = 117;   //增加机体熟练度
const unsigned char EMONEY3_LOG_MAGICSKILL_ADD = 118;   //增加技能熟练度
const unsigned char EMONEY3_LOG_PK_PUBLISH = 119;  // PK惩罚 PK惩罚补充案
const unsigned char EMONEY3_LOG_MODEL_LEV_DEC_COLD_STATUS =
    120;  //战斗星级冷却状态时间减少
const unsigned char EMONEY3_LOG_TRUMP_MAKE_HOLE =
    121;  //法宝 直接使用太阳石进行开洞
const unsigned char EMONEY3_LOG_REPAIR_DESTROYOBJ = 122;  //帮派战修理可破坏物件
const unsigned char EMONEY3_LOG_HIGH_MODE_LEV_UP = 130;   //侍卫复活
const unsigned char EMONEY3_LOG_MODULESTAR_LEV_UP = 131;  //吃经验球
const unsigned char EMONEY3_RMB_LOG_DONATE = 132;         //爵位捐献花太阳石

const int MAX_PACKETSIZE = 1024;
const int _RANGE_EXPSHARE = 32;

const int _DELTA_X[8] = {0, -1, -1, -1, 0, 1, 1, 1};  // 按方向移动
const int _DELTA_Y[8] = {1, 1, 0, -1, -1, -1, 0, 1};  // 按方向移动

const int AUTO_UPRANK_SYNDICATE_USERLEV = 6;  // 2007.02.10 少尉自动升为正式成员

const UCHAR TEAMEXP_NONE = 0x0;
const UCHAR TEAMEXP_BASE = 0x1;
const UCHAR TEAMEXP_VIP = 0x2;
const UCHAR TEAMEXP_STAR = 0x4;     //星级怪物经验
const UCHAR TEAMEXP_SUPPORT = 0x8;  //状态树支持
const UCHAR TEAMEXP_DOUBLE = 0x10;
const UCHAR TEAMEXP_TREBLE = 0x20;
const UCHAR TEAMEXP_CRYSTAL = 0x40;  //水晶支持
const uint64_t MAX_EXP_CONTRIBUTIONS_LIMIT = 800000000000;

const OBJID NEW_USER_DEFAULT_MAP_ID = 1102;
const UINT NEW_USER_DEFAULT_MONEY = 100;
const UINT NEW_USER_DEFAULT_LEVEL = 1;
const UINT NEW_USER_DEFAULT_WEIGHT_LIMIT = 9999;
const UINT NEW_USER_DEFAULT_LIFT = 500;
const UINT NEW_USER_DEFAULT_MANA = 0;

const int _MAX_FLY_HEIGHT = 500;             // 飞行高度
const OBJID SPIRIT_ITEM_TYPE_ID = 53000002;  // 把Spirit构建成一个物品的物品Type
const int DEFAULT_SHAPE = 0;
const int ERROR_WEIGHT = 123456789;  // 错误的重量
const int MAX_QUALITY = 9;           // 最高的品质
const int CORRUPT_SALE_FEE = 1;      // 卖损坏物品价格
const int UNIDENT_SALE_FEE = 1;      // 卖未鉴定的价格

const int MAGIC_TYPE_OFFSET = 10;
const int MAX_SUBSKILLSIZE = 3;
const int MAX_SKILLSIZE = 1 + MAX_SUBSKILLSIZE;  // 注意和CMsgSkillSuit结构相同
const int SKILL_TYPE_OFFSET = MAGIC_TYPE_OFFSET;
const int SKILLSUIT_HOTKEY_CRAZYFIGHT_RIGHTSHORTCUTL =
    101;  // 101定义为：绑定在左键上的
const int SKILLSUIT_HOTKEY_CRAZYFIGHT_RIGHTSHORTCUT =
    102;  // 102定义为：绑定在右键上的，在狂战士状态下会有使用次数的限制
const int SKILLSUIT_HOTKEY_CRAZYFIGHT_RIGHTSHORTCUTF5 =
    103;  // 103定义为：绑定在F5键上的
const int SKILLSUIT_HOTKEY_TRUECRAZYFIGHT_LEFTBTN =
    201;  // 201定义为：绑定在左键上， 杀阵下使用的技能
const int SKILLSUIT_HOTKEY_BASESUPPORT = 301;  // 基地援助标志

const int SYN_MONEY_BASELINE = 10 * 10000;  // 帮派基金少于该值，会限制帮派功能

//////////////////////////////////////////////////////////////////////////
// ITEMPOSITION
const int ITEMPOSITION_USER_LIMIT = 199;
const int ITEMPOSITION_STORAGE = 201;
const int ITEMPOSITION_TRUNK = 202;
const int ITEMPOSITION_CHEST = 203;
const int ITEMPOSITION_GROUND = 204;        // 不存数据库
const int ITEMPOSITION_VIRTUALSPACE = 205;  // 虚空间扩展舱
const int ITEMPOSITION_VIPSTORAGE = 206;  // VIP专用仓库
const int ITEMPOSITION_BUY_TRADE_STORAGE = 207;   //买入物品存放仓库
const int ITEMPOSITION_SELL_TRADE_STORAGE = 208;  //卖出物品存放仓库
const int ITEMPOSITION_AUCTION_STORAGE = 209;     //拍卖仓库
const int ITEMPOSITION_NONE = 255;                // 非法位置

const int _MAX_RMBLIMIT_TRADE = 1000000;
const int _MAX_RMBLIMIT = 10000000;
const uint32_t _MAX_MONEYLIMIT = UINT_MAX;

const int EMONEY_EXCHANGE_RATE = 73000;  // 代币与游戏币的兑换比例

//////////////////////////////////////////////////////////////////////////
// LeaveWood
const int PLAYER_WORDS_PER_TIME = 2;   // 玩家每次读取5条留言
const int NEW_WORDS_PER_MINUTE = 5;    // 每分钟自动读取几条新留言
const int DELETE_LEAVEWORD_DAYS = 31;  // 31天以上留言会自动删除
const int SECS_PER_AUTOFLUSH = 60;     // 每分钟自动刷新一次

const int SECS_MONSTER_DIZZ = 3;

const int MAX_HEADLOOP_ATK_NUM = 3;  //同时不良状态攻击最大数目

const int MAX_WEIGHT = 999999999;

const double EPSILONG = 0.00001;

const int PILE_ITEM_MAX_NUM = 10;

const int ADDLIFE_FIRST_PERCENT = 40;
const int ADDLIFE_NEXT_PERCENT = 20;

const int _RADAR_SECONDS = 90;  // 2007.03.12 增值物品雷达持续时间
const int MINI_ADDLIFE_DRAG = 100;
const int PACKAGE_LIMIT = 80;  // 一个package最多能放多少个物品
const int MARRY_MIN_LEVEL = 30;

const int PKVALUE_BADGUY = 1000;
const int MAX_EXPTYPE = 255;
const int PICK_LARGE_MONEY = 10000;  // 捡钱很多时，广播ACTION消息
const int MAX_USER_VAR = 32;         // 机战新增action需求 2007-2-5 add

// Task
const int LUA_IDX_START = 127;

const int MAX_DROPITEM_RATE = 100;
const int MAX_DROPITEM_AMOUNT = 0x00FFFFFF;
const int USER_SENDFLOWER_LEVEL = 50;  // 玩家最低允许送花的等级
const int COACH_TIME_SPEND_EVERY_INTERVAL = 20;
const int MAX_DIRSIZE = 8;
const int SIMPLEMAGIC_RECRUIT = 1005;
const int GARBAGE_DIEDELAY_SECS = 30;  // SCENE_NPC死亡多少秒后删除

//////////////////////////////////////////////////////////////////////////
// magictype
const OBJID ICE_MAGIC = 9800;
const OBJID SHAKE_MAGIC = 9802;
const OBJID MAGICTYPE_HOTATK = 9801;  // 高温灼烧技能type

//////////////////////////////////////////////////////////////////////////
// mine
const int _MAX_LAY_MINE = 15;  // 布雷数量上限

//////////////////////////////////////////////////////////////////////////
// spirit
const int SPIRIT_DUNTYPE_OFFSET = 1000;

//////////////////////////////////////////////////////////////////////////

const int TRANSNPC_FEE = 10000;
const int SYNFLAG_SIZEADD = 5;      // 帮派柱子的附加尺寸
const int DEFAULT_NPC_SIZEADD = 4;  // 每个方面加两格
const int PKVALUE_YELLOWNAME = 70;
const int MAX_WEAPON_SKILL_ATK_ADJ_LEVEL = 20;
const int MAX_ATKER_NUM = 10;
//正常物品的基本几率
const int EQUIP_BASE_DROP_RATE = 1000;       //装备
const int AMMO_BASE_DROP_RATE = 1000;        //弹药
const int PART_BASE_DROP_RATE = 0;           //标准配件
const int AMPLIFIER_BASE_DROP_RATE = 0;      //增幅器
const int GUARDEQUIP_BASE_DROP_RATE = 1000;  //侍卫物品
const int EXPENDABLE_BASE_DROP_RATE = 1000;  //消耗品
const int INSIDEITEM_BASE_DROP_RATE = 0;     //内部装置
const int RMB_BASE_DROP_RATE = 1000;         //太阳石
const int OTHER_BASE_DROP_RATE = 2000;       //其他
//掉特殊物品的基本几率
const int SPECIAL_BASE_DROP_RATE = 0;  //掉特殊物品
//爆出物品的掉落类型基本几率
const int EXPLODE_TYPE_BASE_DROP_RATE =
    (EQUIP_BASE_DROP_RATE + AMMO_BASE_DROP_RATE + GUARDEQUIP_BASE_DROP_RATE +
     EXPENDABLE_BASE_DROP_RATE + OTHER_BASE_DROP_RATE + RMB_BASE_DROP_RATE);
//爆物品的基本几率
const int EXPLODE_BASE_DROP_RATE = 200;
//掉落类型判断使用的随机范围
const int RAND_RANGE = 12000;

const int MONSTERDROPITEM_RANGE = 2;  // 2*2+1的4次方=625次搜索

const uint64_t _MAX_SAVEMONEYLIMIT = 0x7fffffffffffffffull;

const int GUARD_DIE_DEC_BATTLEEFFECT = 2;

const int LEV_CANHOLD_CANNON2 = 20;

const OBJID SPIRITITEM_FIRSTIDD = 4000000000;  // 4012345678;
const OBJID SPIRITITEM_LASTID = 4290000000;    // 4012345678;

const int TWOCOLS_TWOROWS_SHAPE = 2010;  // 1023action问题

//////////////////////////////////////////////////////////////////////////
const int EXPBALL_START = 51999996;
const int EXPBALL_END = 51999999;
const int FLOWER_START = 51000751;
const int FLOWER_END = 51000758;
const int INCREASEVALUEITEMSTART = 51000001;
const int NORMALLITEM_STAR = 0;
const int NORMALLITEM_END = 49999999;

//////////////////////////////////////////////////////////////////////////
// map gen no段分配
//程序启动时即载入的地图相关资源
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
const int CHEAT_CHECK_LEV = 100;  //外挂提问的主机体等级要求

//////////////////////////////////////////////////////////////////////////
//定义地图类型共支持64种地图类型(目前有三大类地图: 静态地图，动态地图，副本地图)
const uint64_t MAPTYPE_NORMAL = 0ull;  //普通地图
const uint64_t MAPTYPE_PKFIELD = 1ull << 0;  // PK场
const uint64_t MAPTYPE_CHGMAP_DISABLE = 1ull << 1;  //不能用魔法在地图实现移动
const uint64_t MAPTYPE_RECORD_DISABLE = 1ull << 2;  //不能记录
const uint64_t MAPTYPE_PK_DISABLE = 1ull << 3;      //不能PK
const uint64_t MAPTYPE_BOOTH_ENABLE = 1ull << 4;    //专用摆摊地图(无记录点)
const uint64_t MAPTYPE_TEAM_DISABLE = 1ull << 5;    //不能组队
const uint64_t MAPTYPE_TELEPORT_DISABLE =
    1ull << 6;  // chgmap by action，不能用chgmap（指令）、回城卷
const uint64_t MAPTYPE_SYN_MAP = 1ull << 7;     //帮派地图
const uint64_t MAPTYPE_PRISON_MAP = 1ull << 8;  //监狱地图
const uint64_t MAPTYPE_FLY_DISABLE = 1ull << 9;
const uint64_t MAPTYPE_DISABLE_TRANSFER_SOURCE = 1ull
                                                 << 9;     //不能作为瞬移的源地
const uint64_t MAPTYPE_FAMILY = 1ull << 10;                //家庭地图
const uint64_t MAPTYPE_MINEFIELD = 1ull << 11;             //矿场
const uint64_t MAPTYPE_DISABLE_GODTRANSPORT = 1ull << 11;  //禁止神仙传送
const uint64_t MAPTYPE_PKGAME = 1ull << 12;  // PK赛
const uint64_t MAPTYPE_HUMAN = 1ull
                               << 13;  //人类场景（人类专用场景，不能PK、飞行）
const uint64_t MAPTYPE_WORLDWAR = 1ull << 14;  //国战地图
const uint64_t MAPTYPE_UNIVERSE =
    1ull << 15;  //宇宙场景 （用来跟普通地图区分移动方式）
const uint64_t MAPTYPE_EXPERIMENT = 1ull
                                    << 16;  //感受室地图 （用来跟普通地图区分）
const uint64_t MAPTYPE_SPACESHIPJOB = 1ull << 17;  //飞船任务地图 类型
const uint64_t MAPTYPE_SPACESHIP = 1ull << 18;     //飞船地图 类型
const uint64_t MAPTYPE_TRAININGFIELD =
    1ull << 19;  //练功场地图 类型 (auto set no_pk|no_record, 此类型无战斗消耗)
const uint64_t MAPTYPE_NEWPIE_PK_PROTECT = 1ull << 20;  //新手保护地图
const uint64_t MAPTYPE_FULLSCREEN_ATK_DISABLE = 1ull
                                                << 21;  //限制使用全屏轰炸技能
const uint64_t MAPTYPE_DISABLE_TRANSFER_TARGET = 1ull
                                                 << 21;  //不能作为瞬移的目的地
const uint64_t MAPTYPE_NO_REBORN_INNOWPOS = 1ull << 22;  // 限制原地复活功能
const uint64_t MAPTYPE_DISABLE_TRANSPOS = 1ull
                                          << 23;  //不可召唤 2007-2-27 tcp add
const uint64_t MAPTYPE_DISABLE_TRANSFORM =
    1ull << 24;  //不可变形的地图 2007-3-29 tcp add
const uint64_t MAPTYPE_DISABLE_TRUMP_REBORN = 1ull
                                              << 25;  //禁止使用法宝复活技能
const uint64_t MAPTYPE_DISABLE_TRUMP_REGION = 1ull
                                              << 26;  //禁止使用法宝结界技能
const uint64_t MAPTYPE_DISABLE_TRUMP_RAND_TRANS_POS =
    1ull << 27;  //禁止使用法宝-小瞬移
const uint64_t MAPTYPE_PK_LOST_NOTHING = 1ull << 29;  // PK对玩家不产生任何损失

const uint64_t MAPTYPE_DISABLE_AREA_MAGIC = 1ull << 30;  //禁止使用范围技能

const uint64_t MAPTYPE_DISABLE_STEAL = 1ull << 30;  //禁止偷窃
const uint64_t MAPTYPE_DISBLE_TEAM_SEARCH = 1ull
                                            << 31;  //禁止队伍搜索的地图属性
const uint64_t MAPTYPE_OFFLINE_TRAINING_DISABLE = 1ull
                                                  << 33;  //离线练功是否允许
const uint64_t MAPTYPE_NOT_INVITE = 1ull << 34;           //是否允许邀请
const uint64_t MAPTYPE_FAMILYWAR = 1ull << 32;            //家族战地图
const uint64_t MAPTYPE_DUN = 1ull << 36;                  //地下城
//增加PK赛地图类型
const uint64_t MAPTYPE_PKGAME_NEAR_WAR = 1ull << 43;  // PK官兵地图
const uint64_t MAPTYPE_PKGAME_FAR_WAR = 1ull << 44;  // pk山匪地图
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//末日危机新增
const int MSGMAGICEFFECT_MUTUAL_EFFECT_BIT =
    6;  // 2^6以下的值给互斥的效果类型使用（十进制方式），2^6及以上的值给非互斥的效果使用（二进制方式）
const int TIMELINESS_ITEM_TIME_UNIT = 60;  //时效性物品计时单位（60秒）

// globalvaniable表type字段定义
const int GLOBALDATA_TYPE_USER_BATTLE_ATTRIBUTE = 20101;  //属性点效果

//强行给玩家物品 srf
const char ENFORCE_AWARDITEM_SQL[] =
    "INSERT INTO itemex(type,owner_id,player_id,position,ownertype) "
    "VALUES(%d,%d,%d,4070,52)";

// Dota
const INT ITEM_COMPONENT_MAX = 5;  //物品合成组件最大数

#endif  // end of define _GS_CONST_DEFINE_H_

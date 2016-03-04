// MsgItem.h: interface for the CMsgItem class.
/**
 *  @file   IMsgItem.h
 *
 *  $Id: IMsgItem.h 2008-12-22 16:03:40Z $
 *
 *  @author chx <xxx@gmail.com>
 *  
 */
//==========================================================================

#ifndef _MSG_IMSGITEM_H_
#define _MSG_IMSGITEM_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
// #pragma  pack(push)
// #pragma  pack(1)
namespace msgitem
{
	enum 
	{	
		ITEMACT_NONE=0, 
		ITEMACT_BUY					= 1,	// to server, id: idNpc, data: idItemType
		ITEMACT_SELL				= 2,	// to server, id: idNpc, data: idItem
		ITEMACT_DROP				= 3,	// to server, x, y, position
		ITEMACT_USE					= 4,	// to server, , position: target position, data: pack position
		ITEMACT_EQUIP				= 5,	// to client，通知装备物品, position: target position, data: pack position
		ITEMACT_UNEQUIP				= 6,	// to server, position: position
		ITEMACT_SPLITITEM			= 7,	// to server, data: num
		ITEMACT_COMBINEITEM			= 8,	// to server, data: id
		ITEMACT_QUERYMONEYSAVED		= 9,	// to server/client, id: idNpc, data: nMoney, usPosDir:[0:向npc查询 1:拍卖查询]
		ITEMACT_SAVEMONEY			= 10,	// to server, id: idNpc, data: nMoney
		ITEMACT_DRAWMONEY			= 11,	// to server, id: idNpc, data: nMoney
		ITEMACT_DROPMONEY			= 12,	// to server, x, y
		ITEMACT_SPENDMONEY			= 13,	// 无意义，暂保留
		ITEMACT_REPAIR				= 14,	// to server, return MsgItemInfo
		ITEMACT_REPAIRALL			= 15,	// to server, return ITEMACT_REPAIRAll, or not return if no money
		ITEMACT_IDENT_EQUIP			= 16,	// to server, return MsgItemInfo
		ITEMACT_DURABILITY			= 17,	// to client, update durability
		ITEMACT_DROPEQUIPMENT		= 18,	// to client, delete equipment, position: position
		ITEMACT_IMPROVE				= 19,	// to server, improve equipment
		ITEMACT_UPLEV				= 20,	// to server, upleve equipment
		ITEMACT_BOOTH_QUERY			= 21,	// to server/client, open booth, data is npc id, auto is kickout enable
		ITEMACT_BOOTH_ADD			= 22,	// to server/client(broadcast in table), id is idItem, data is money, need posdir
		ITEMACT_BOOTH_DEL			= 23,	// to server/client(broadcast), id is idItem, data is npc id
		ITEMACT_BOOTH_BUY			= 24,	// to server, id is idItem, data is npc id
		ITEMACT_SYNCHRO_AMOUNT		= 25,	// to client(data is amount)
		ITEMACT_FIREWORKS			= 26,
		ITEMACT_POSITION			= 27,	// to server/client, change position with different pack or one pack. dwData is to position
		ITEMACT_QUERYSTONESAVED	=28,			// to server/client, id: idNpc, data: nStone, usPosition: nMaxStone
		ITEMACT_SAVESTONE		=29,			// id: idNpc, data: nStone
		ITEMACT_DRAWSTONE		=30,			// to server, id: idNpc, data: nStone
		ITEMACT_CAST				= 31,	// to server, 投掷临时仓中的武器攻击敌人
		ITEMACT_EVOLVE				= 32,	// 武器进化
		ITEMACT_BOOTH_KICKOUT		= 33,	// to server/client, id: npc_id
		ITEMACT_EXCHANGE			= 34,	// to client, exchange two item with backpack. id: item from back pack, data: item from another pack, position: another pack.
		ITEMACT_IDENT_ORE			= 35,	// to server, return MsgItemInfo
		ITEMACT_POSITION_FAIL		= 36,	// To Client Only, change position fail.同步客户端显示
		ITEMACT_RMB_BUY_OK			= 37,	// To Client Only, 购买增值物品成功，通知客户端
		ITEMACT_USE_EXPBALL			= 38,	// To Server Only, 使用经验球, id=经验球ID或经验值球礼包ID,若为0表示用元宝消费
		ITEMACT_ADDITION			= 39,	// To Client Only,武器追加 usPosition=ITEMPOSITION_BACKPACK（货舱）或者ITEMPOS_ENGINEROOM（机械舱）, dwData=AdditionLevel(追加值)
		ITEMACT_CHGDATA				= 40,	// To Client Only,更新Data字段值
		ITEMACT_SET_STAR_MONSTER	= 41,	// 设置星级怪物状态
		ITEMACT_SELECTMULTIWEAPONPOS= 42,	// to Server Client, 选择使用第[dwData]套武器位装备
		ITEMACT_QUERYOTHER_WEAPONPOS= 43,	// to Client only, 查看别人使用第[dwData]套武器位装备
		ITEMACT_EQUIPWEAPON_INDEX	= 44,	// to Client only, 通知客户端，登陆时，目前使用的是第dwData套武器位的装备 
		ITEMACT_MOON_GEM			= 45,	// 月光宝盒打洞，给装备宝石,dwData存装备ID
		ITEMACT_EQUIPT_VIP_LEVEL	= 47,	// to Server, Client VIP专享装备等级改变, id=装备的ID, dwData=要改变的装备新的type
		ITEMACT_SPIRIT_COLOR_ITEM    = 48,	// to Server,  id:物品id,dwData = color颜色 2007-1-22 tcp add 机体换色物品制作
		ITEMACT_BUY_MULIT_VIP_ITEM	= 49,	// to server, id: idNpc, data: idItem dwCount:2007-1-31 tcp add 个数代币商店系统补充修改		
		ITEMACT_VIP_REPAIRITEM		= 50,	// to server, id: idNpc, data: idItem dwCount:2007-2-1 tcp VIP修理装备文档	
		ITEMACT_SKILL_USEIDEA_FILLEXP= 51,	// TO SERVER, usPosDir=0为存储经验,dwData存技能书类型ID，usPosDir=1为使用心得物品
		//货舱问题2007-3-13 begin add		
		ITEMACT_CLEAR_ALLITEM_CELL_MASK = 52,// to client id:idNewPackage		
		ITEMACT_ITEM_REPLACE         = 53,	//  to client dwData is to position			
		ITEMACT_FORGENAME_CHANGE	= 54,	// 2007.04.09 装备镭射签名变更, id装备ID, dwData重核以太的ID
		//货舱问题2007-3-13 end add		
		
		ITEMACT_USE_EXPBALL_PREVIEW	= 55,	// To Server Only, 预览使用经验球id=经验球ID或经验值球礼包ID,若为0表示用元宝消费
		ITEMACT_USE_EXPBALL_PREVIEW_RET	= 56,	// To Client Only, 预览使用经验球dwCount:次数 dwData:1 0 idSpiritFrom percent(lev*100000), id=经验球ID或经验值球礼包ID,若为0表示用元宝消费
		ITEMACT_BUY_MULIT_VIP_ITEM_AND_USE	= 57,	// TSTC, id: idNpc, data: idItem dwCount:2007-1-31 tcp add 个数代币商店系统补充修改, 与49相同,只是马上使用,TC时用于客户端表现
		ITEMACT_USE_SYNWAR_REBORN_MEDICINE	= 58,	// to server, , position: target position, data: pack position帮派战地图复活药使用
		ITEMACT_ADDITION_SUCEESS			= 59,	// To Client Only,武器追加 usPosition=ITEMPOSITION_BACKPACK（货舱）或者ITEMPOS_ENGINEROOM（机械舱）, dwData=AdditionLevel(追加值)		
		ITEMACT_USE_CANNON_REBORN_MEDICINE	= 60,	// to server, , position: target position, data: pack position浮游炮复活药使用
		ITEMACT_BUY_CANNON_REBORN_MEDICINE_OK=61,	// 购买浮游炮复活药成功, dwData为物品ID
		ITEMACT_BUY_CANNON_REBORN_MEDICINE_AND_USE_OK = 66, //购买复活药并使用成功
		ITEMACT_BUY_GEM_AND_EXCHANGE_EXP   	= 62,   // to server 买太阳石升经验 						
		ITEMACT_UN_EQUIP_TRUMP_IN_COLDE_TIME = 63,  // to c 技能冷却状态无法卸下法宝
		
		ITEMACT_USE_SKILLEXPBALL			= 64,	// To S/C Only, 使用通用技能经验球, id:物品ID dwData:0(武器),1(机体),2(技能) idSpiritTo:技能类型ID  返回idSpiritFrom:等级加百分比(lev*100000)
		ITEMACT_BUY_STONE2					= 65,   // To S       , dwData:购买紫水晶的数量
		ITEMINFO_TRUMP_SELECT				= 80,	// 法宝选择,dwData:选择的法宝ID
		ITEMACT_EQUIP_COMPOUND				= 81,	// 侍卫装备合成
		ITEMACT_EQUIP_COMPOUND_SUCESS		= 82,	// 侍卫装备合成成功提示
		ITEMACT_STONE_COMPOUND				= 83,   // 侍卫装备合成宝石 TSTC
		ITEMACT_STONE_COMPOUND_USAGE_QUERY  = 84,   // 侍卫装备合成宝石次数查询
		ITEMACT_ATTR_COMPOUND               = 85,   // 侍卫属性合成
		ITEMACT_GUARD_STARUP_LEVEL_LOW      = 86,   // 侍卫星级提升时等级不足
		ITEMACT_GUARD_STAR_REACH_MAX_BY_LEVEL = 87, // 侍卫星级达到当前等级上限
		
		ITEMACT_APPLY_TO_SALE = 90,					 //销售申请
		ITEMACT_CANCEL_APPLY_TO_SALE = 91,			 //取消销售申请
	    ITEMACT_QUERY_APPLY_STATUS = 92,			 //查询申请状态
		ITEMACT_GUARD_USE_HAIR              = 93,   //TC 侍卫使用发型
		ITEMACT_DONATION_MONEY				= 94,	//TS 捐款 dwData[银两数量] dwCount[元宝数量]
													//TC 捐款反馈 usPosition[0:捐献失败 1:捐献成功]
		ITEMACT_DONATION_QUERY				= 95,	//TS 捐款查询 usPosition[目标爵位]
													//TC 捐款查询结果 usPosition[目标爵位] idSpiritFrom[实际爵位] dwData[所需银两低32位] dwCount[所需银两高32位] usPosDir[1:最后一名侯爵捐献金额<=2亿]
		ITEMACT_DONATION_CHAT_EFFECT		= 96,	//TS 领取爵位聊天专用效果
		//ITEMACT_GUARD_USE_HAIR              = 97,   //TC 侍卫使用发型

		ITEMACT_GUARD_USE_MEMSES_ITEM		= 98,	//TS 女侍卫使用经期道具请求 id[物品ID] dwData[女侍卫id]
													//TC 女侍卫使用经期道具请求 id[物品ID] dwData[女侍卫id] usPosY[0:使用失败 1：使用成功 2:未过期]

															//add by ccw_xxx
		ITEMACT_BUY_MULIT_VIP_ITEM_BY_EMONEY3	        = 101,	// to server, id: idNpc, data: idItem dwCount:2007-1-31  个数代币商店系统补充修改
		ITEMACT_BUY_MULIT_VIP_ITEM_AND_USE_BY_EMONEY3	= 102,	// TSTC, id: idNpc, data: idItem dwCount:2007-1-31 tcp add 个数代币商店系统补充修改, 与49相同,只是马上使用,TC时用于客户端表现
		ITEMACT_EMONEY3_BUY_OK		                	= 103,	// To Client Only, 购买增值物品成功，通知客户端
		ITEMACT_EMONEY3_VIP_BUY_OK		                = 104,	// To Client Only, 购买增值物品成功，通知客户端

		ITEMACT_REDEEM                                  = 105,		// 赎回装备
		ITEMACT_FETCH_BONUS                             = 106,		// 领取奖励
		ITEMACT_UPDATE_PK_ITEM                          = 107,		// 更新扣押装备的信息

//		ITEMACT_TRUCK_COMPOUND				= 110,	// 货车装备合成 TS
//		ITEMACT_TRUCK_COMPOUND_SUCESS		= 111,	// 货车装备合成成功提示 TC
		ITEMACT_DEL_STORAGEITEM							= 120,		//删除仓库里的物品To Client
		ITEMACT_EQUIP_HORSE_REQ                          = 200,    // 给马装备个性饰件!!! //ts
		ITEMACT_EQUIP_HORSE_SUC                          = 201,    // 给马装备个性饰件!!! //tc
		ITEMACT_EQUIP_AMMO                               = 202,    // 装弹

		ITEMACT_LIFT_ITEM                                 = 300,    // 搬起
		ITEMACT_THROW_ITEM                                = 301,    // 抛掷
		ITEMACT_DROP_ITEM                                 = 302,    // 掉落
	};

	//SPIRIT_MENSES_ITEM_RESULT
	enum MENSES_ITEM_RESULT_e
	{
		MENSES_ITEM_RESULT_FAIL = 0,
		MENSES_ITEM_RESULT_SUC = 1,
		MENSES_ITEM_RESULT_INDAY = 2,
	};

#pragma pack(push, 1)
	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;

		OBJID		id;
		USHORT		usPosition;			// 买、卖、USE、drop时客户端都会发来物品所在仓
										// 对于 装备是ITEM_POSITION，否则是ITEM_OWNERTYPE
		OBJID		idSpiritFrom;

		union 
		{
			uint32		dwData;			//当使用对装备修复类的物品时， 用做对象物品的id
										//当装备物品时，用作需要装备的位置
										//星级提失败时，返回改星级的等级限制TC
			struct
			{
				USHORT	usPosY;
				USHORT	usPosX;
			};
		};
		union
		{
			uint32		dwRMB;
			uint32		dwCount;//物品的个数2007-1-31 tcp add 个数代币商店系统补充修改			
			OBJID		idSpiritTo;
			OBJID		idSpiritWeaponSelect;
			int			nAdditionExp;
			int         nRansom;
		};
		USHORT		usAction;
		USHORT		usPosDir;			// XXYYD: XY坐标，D方向	// ITEM_POSITION
		USHORT      nCurrencyType; //0 is rmb, 1 is emoney3

		float fPosX;
		float fPosY;
		float fPosZ;
		bool		bAuto;
		
	}MSG_ITEM;
#pragma pack(pop)
}
/*#pragma  pack(pop)*/
#endif //_MSG_IMSGITEM_H_


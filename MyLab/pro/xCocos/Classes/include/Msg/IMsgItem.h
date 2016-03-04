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
		ITEMACT_EQUIP				= 5,	// to client��֪ͨװ����Ʒ, position: target position, data: pack position
		ITEMACT_UNEQUIP				= 6,	// to server, position: position
		ITEMACT_SPLITITEM			= 7,	// to server, data: num
		ITEMACT_COMBINEITEM			= 8,	// to server, data: id
		ITEMACT_QUERYMONEYSAVED		= 9,	// to server/client, id: idNpc, data: nMoney, usPosDir:[0:��npc��ѯ 1:������ѯ]
		ITEMACT_SAVEMONEY			= 10,	// to server, id: idNpc, data: nMoney
		ITEMACT_DRAWMONEY			= 11,	// to server, id: idNpc, data: nMoney
		ITEMACT_DROPMONEY			= 12,	// to server, x, y
		ITEMACT_SPENDMONEY			= 13,	// �����壬�ݱ���
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
		ITEMACT_CAST				= 31,	// to server, Ͷ����ʱ���е�������������
		ITEMACT_EVOLVE				= 32,	// ��������
		ITEMACT_BOOTH_KICKOUT		= 33,	// to server/client, id: npc_id
		ITEMACT_EXCHANGE			= 34,	// to client, exchange two item with backpack. id: item from back pack, data: item from another pack, position: another pack.
		ITEMACT_IDENT_ORE			= 35,	// to server, return MsgItemInfo
		ITEMACT_POSITION_FAIL		= 36,	// To Client Only, change position fail.ͬ���ͻ�����ʾ
		ITEMACT_RMB_BUY_OK			= 37,	// To Client Only, ������ֵ��Ʒ�ɹ���֪ͨ�ͻ���
		ITEMACT_USE_EXPBALL			= 38,	// To Server Only, ʹ�þ�����, id=������ID����ֵ�����ID,��Ϊ0��ʾ��Ԫ������
		ITEMACT_ADDITION			= 39,	// To Client Only,����׷�� usPosition=ITEMPOSITION_BACKPACK�����գ�����ITEMPOS_ENGINEROOM����е�գ�, dwData=AdditionLevel(׷��ֵ)
		ITEMACT_CHGDATA				= 40,	// To Client Only,����Data�ֶ�ֵ
		ITEMACT_SET_STAR_MONSTER	= 41,	// �����Ǽ�����״̬
		ITEMACT_SELECTMULTIWEAPONPOS= 42,	// to Server Client, ѡ��ʹ�õ�[dwData]������λװ��
		ITEMACT_QUERYOTHER_WEAPONPOS= 43,	// to Client only, �鿴����ʹ�õ�[dwData]������λװ��
		ITEMACT_EQUIPWEAPON_INDEX	= 44,	// to Client only, ֪ͨ�ͻ��ˣ���½ʱ��Ŀǰʹ�õ��ǵ�dwData������λ��װ�� 
		ITEMACT_MOON_GEM			= 45,	// �¹ⱦ�д򶴣���װ����ʯ,dwData��װ��ID
		ITEMACT_EQUIPT_VIP_LEVEL	= 47,	// to Server, Client VIPר��װ���ȼ��ı�, id=װ����ID, dwData=Ҫ�ı��װ���µ�type
		ITEMACT_SPIRIT_COLOR_ITEM    = 48,	// to Server,  id:��Ʒid,dwData = color��ɫ 2007-1-22 tcp add ���廻ɫ��Ʒ����
		ITEMACT_BUY_MULIT_VIP_ITEM	= 49,	// to server, id: idNpc, data: idItem dwCount:2007-1-31 tcp add ���������̵�ϵͳ�����޸�		
		ITEMACT_VIP_REPAIRITEM		= 50,	// to server, id: idNpc, data: idItem dwCount:2007-2-1 tcp VIP����װ���ĵ�	
		ITEMACT_SKILL_USEIDEA_FILLEXP= 51,	// TO SERVER, usPosDir=0Ϊ�洢����,dwData�漼��������ID��usPosDir=1Ϊʹ���ĵ���Ʒ
		//��������2007-3-13 begin add		
		ITEMACT_CLEAR_ALLITEM_CELL_MASK = 52,// to client id:idNewPackage		
		ITEMACT_ITEM_REPLACE         = 53,	//  to client dwData is to position			
		ITEMACT_FORGENAME_CHANGE	= 54,	// 2007.04.09 װ������ǩ�����, idװ��ID, dwData�غ���̫��ID
		//��������2007-3-13 end add		
		
		ITEMACT_USE_EXPBALL_PREVIEW	= 55,	// To Server Only, Ԥ��ʹ�þ�����id=������ID����ֵ�����ID,��Ϊ0��ʾ��Ԫ������
		ITEMACT_USE_EXPBALL_PREVIEW_RET	= 56,	// To Client Only, Ԥ��ʹ�þ�����dwCount:���� dwData:1 0 idSpiritFrom percent(lev*100000), id=������ID����ֵ�����ID,��Ϊ0��ʾ��Ԫ������
		ITEMACT_BUY_MULIT_VIP_ITEM_AND_USE	= 57,	// TSTC, id: idNpc, data: idItem dwCount:2007-1-31 tcp add ���������̵�ϵͳ�����޸�, ��49��ͬ,ֻ������ʹ��,TCʱ���ڿͻ��˱���
		ITEMACT_USE_SYNWAR_REBORN_MEDICINE	= 58,	// to server, , position: target position, data: pack position����ս��ͼ����ҩʹ��
		ITEMACT_ADDITION_SUCEESS			= 59,	// To Client Only,����׷�� usPosition=ITEMPOSITION_BACKPACK�����գ�����ITEMPOS_ENGINEROOM����е�գ�, dwData=AdditionLevel(׷��ֵ)		
		ITEMACT_USE_CANNON_REBORN_MEDICINE	= 60,	// to server, , position: target position, data: pack position�����ڸ���ҩʹ��
		ITEMACT_BUY_CANNON_REBORN_MEDICINE_OK=61,	// �������ڸ���ҩ�ɹ�, dwDataΪ��ƷID
		ITEMACT_BUY_CANNON_REBORN_MEDICINE_AND_USE_OK = 66, //���򸴻�ҩ��ʹ�óɹ�
		ITEMACT_BUY_GEM_AND_EXCHANGE_EXP   	= 62,   // to server ��̫��ʯ������ 						
		ITEMACT_UN_EQUIP_TRUMP_IN_COLDE_TIME = 63,  // to c ������ȴ״̬�޷�ж�·���
		
		ITEMACT_USE_SKILLEXPBALL			= 64,	// To S/C Only, ʹ��ͨ�ü��ܾ�����, id:��ƷID dwData:0(����),1(����),2(����) idSpiritTo:��������ID  ����idSpiritFrom:�ȼ��Ӱٷֱ�(lev*100000)
		ITEMACT_BUY_STONE2					= 65,   // To S       , dwData:������ˮ��������
		ITEMINFO_TRUMP_SELECT				= 80,	// ����ѡ��,dwData:ѡ��ķ���ID
		ITEMACT_EQUIP_COMPOUND				= 81,	// ����װ���ϳ�
		ITEMACT_EQUIP_COMPOUND_SUCESS		= 82,	// ����װ���ϳɳɹ���ʾ
		ITEMACT_STONE_COMPOUND				= 83,   // ����װ���ϳɱ�ʯ TSTC
		ITEMACT_STONE_COMPOUND_USAGE_QUERY  = 84,   // ����װ���ϳɱ�ʯ������ѯ
		ITEMACT_ATTR_COMPOUND               = 85,   // �������Ժϳ�
		ITEMACT_GUARD_STARUP_LEVEL_LOW      = 86,   // �����Ǽ�����ʱ�ȼ�����
		ITEMACT_GUARD_STAR_REACH_MAX_BY_LEVEL = 87, // �����Ǽ��ﵽ��ǰ�ȼ�����
		
		ITEMACT_APPLY_TO_SALE = 90,					 //��������
		ITEMACT_CANCEL_APPLY_TO_SALE = 91,			 //ȡ����������
	    ITEMACT_QUERY_APPLY_STATUS = 92,			 //��ѯ����״̬
		ITEMACT_GUARD_USE_HAIR              = 93,   //TC ����ʹ�÷���
		ITEMACT_DONATION_MONEY				= 94,	//TS ��� dwData[��������] dwCount[Ԫ������]
													//TC ���� usPosition[0:����ʧ�� 1:���׳ɹ�]
		ITEMACT_DONATION_QUERY				= 95,	//TS ����ѯ usPosition[Ŀ���λ]
													//TC ����ѯ��� usPosition[Ŀ���λ] idSpiritFrom[ʵ�ʾ�λ] dwData[����������32λ] dwCount[����������32λ] usPosDir[1:���һ��������׽��<=2��]
		ITEMACT_DONATION_CHAT_EFFECT		= 96,	//TS ��ȡ��λ����ר��Ч��
		//ITEMACT_GUARD_USE_HAIR              = 97,   //TC ����ʹ�÷���

		ITEMACT_GUARD_USE_MEMSES_ITEM		= 98,	//TS Ů����ʹ�þ��ڵ������� id[��ƷID] dwData[Ů����id]
													//TC Ů����ʹ�þ��ڵ������� id[��ƷID] dwData[Ů����id] usPosY[0:ʹ��ʧ�� 1��ʹ�óɹ� 2:δ����]

															//add by ccw_xxx
		ITEMACT_BUY_MULIT_VIP_ITEM_BY_EMONEY3	        = 101,	// to server, id: idNpc, data: idItem dwCount:2007-1-31  ���������̵�ϵͳ�����޸�
		ITEMACT_BUY_MULIT_VIP_ITEM_AND_USE_BY_EMONEY3	= 102,	// TSTC, id: idNpc, data: idItem dwCount:2007-1-31 tcp add ���������̵�ϵͳ�����޸�, ��49��ͬ,ֻ������ʹ��,TCʱ���ڿͻ��˱���
		ITEMACT_EMONEY3_BUY_OK		                	= 103,	// To Client Only, ������ֵ��Ʒ�ɹ���֪ͨ�ͻ���
		ITEMACT_EMONEY3_VIP_BUY_OK		                = 104,	// To Client Only, ������ֵ��Ʒ�ɹ���֪ͨ�ͻ���

		ITEMACT_REDEEM                                  = 105,		// ���װ��
		ITEMACT_FETCH_BONUS                             = 106,		// ��ȡ����
		ITEMACT_UPDATE_PK_ITEM                          = 107,		// ���¿�Ѻװ������Ϣ

//		ITEMACT_TRUCK_COMPOUND				= 110,	// ����װ���ϳ� TS
//		ITEMACT_TRUCK_COMPOUND_SUCESS		= 111,	// ����װ���ϳɳɹ���ʾ TC
		ITEMACT_DEL_STORAGEITEM							= 120,		//ɾ���ֿ������ƷTo Client
		ITEMACT_EQUIP_HORSE_REQ                          = 200,    // ����װ�������μ�!!! //ts
		ITEMACT_EQUIP_HORSE_SUC                          = 201,    // ����װ�������μ�!!! //tc
		ITEMACT_EQUIP_AMMO                               = 202,    // װ��

		ITEMACT_LIFT_ITEM                                 = 300,    // ����
		ITEMACT_THROW_ITEM                                = 301,    // ����
		ITEMACT_DROP_ITEM                                 = 302,    // ����
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
		USHORT		usPosition;			// ������USE��dropʱ�ͻ��˶��ᷢ����Ʒ���ڲ�
										// ���� װ����ITEM_POSITION��������ITEM_OWNERTYPE
		OBJID		idSpiritFrom;

		union 
		{
			uint32		dwData;			//��ʹ�ö�װ���޸������Ʒʱ�� ����������Ʒ��id
										//��װ����Ʒʱ��������Ҫװ����λ��
										//�Ǽ���ʧ��ʱ�����ظ��Ǽ��ĵȼ�����TC
			struct
			{
				USHORT	usPosY;
				USHORT	usPosX;
			};
		};
		union
		{
			uint32		dwRMB;
			uint32		dwCount;//��Ʒ�ĸ���2007-1-31 tcp add ���������̵�ϵͳ�����޸�			
			OBJID		idSpiritTo;
			OBJID		idSpiritWeaponSelect;
			int			nAdditionExp;
			int         nRansom;
		};
		USHORT		usAction;
		USHORT		usPosDir;			// XXYYD: XY���꣬D����	// ITEM_POSITION
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


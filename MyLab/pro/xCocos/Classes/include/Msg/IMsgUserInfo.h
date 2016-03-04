// -*- C++ -*-

//=============================================================================
/**
 *  @file    IMsgUserInfo.h
 *
 *  $Id: IMsgUserInfo.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _MSG_IMSGUSERINFO_H_
#define _MSG_IMSGUSERINFO_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#pragma pack(1)

NAMESPACE_BEGIN(msguserinfo)
		
enum
{
	MSG_USERINFO_ACT_LOGIN		=0,					//登陆步骤开始
	MSG_USERINFO_ACT_UPDATE		=1,					//更新
	MSG_QUERY_USERINFO			=2,					//查询他人玩家信息
	MSG_USERINFO_CHANGE_ROBOT	=3,					// 仅用于更换机体的动作(TO CLIENT)
};




typedef struct
{	                 
	USHORT			usMsgSize;
	USHORT			usMsgType;
	
	OBJID			id;              // 2009-7-19 5:16:02   LSC  重新排序  同时客户端也修改了
	
	USHORT			usAction;
	U64			u64Exp;			// 机师经验	
	UCHAR			ucLevel;		// 机师等级
	UCHAR			ucVipLev;		// 玩家Vip等级
	U32			dwLookFace;		// 外貌

	U32			dwRMB;
	int             nTotalizeGame; 
	int             nWinGame;
	int             nKillHeroAmount;
	int             nAssistAmount;
	int             nKillEmplacementAmount;
	int             nKillDogfaceAmount;    
	// for str packer
	char			szBuf[1];
}MSG_USER_INFO;

/*     
      

typedef struct    //  原来的 结构体 
{
	USHORT			usMsgSize;
	USHORT			usMsgType;
	USHORT			usAction;
	OBJID			id;
	UCHAR			ucLevel;		// 机师等级
	UCHAR			ucGeNaKoolLevel;//格纳库等级
	U64			u64Exp;			// 机师经验
	USHORT			usPK;			// 机师PK值
	UCHAR			ucVipLev;		// 玩家Vip等级
	U32			dwTitle;		// 机师称号
	U32			dwMilitaryRank1;
	U32			dwMilitaryRank2;
	U32			dwMilitaryRank3;
	U32			dwMilitaryRank4;	// 机师军衔

  U32			dwLookFace;			// 外貌
  U32			dwMoney;
  OBJID			idTransfromMagic;	//现在用于从哪个技能变形过来
  U64			u64Stone0;
  U32			dwStone1;
  U32			dwStone2;
  U32			dwDeed;				// 国民贡献度
  OBJID			idSpirit;
  U32			dwRobotType;		// 机体类型
  int				nInsizeSize;		// 内置舱大小
  U32			usHair;
  UCHAR			ucCamp;
  USHORT			usColor ;           //机体颜色 
  U32			dwRMB;
  UCHAR			ucExpType;			//机师经验值类型                   // 2009-7-19 10:17:33   LSC  真垃圾
  U32			dwList1;
  U32			dwList2;
  UCHAR			ucProfession;
  
	UCHAR			ucPeerage;			//爵位
	//	UCHAR			ucDunKeeperRank;	//地下城城主阶级
	//add by ccw_xxx
	U32           dwEmoney3;
	int             nVipShow;
	int				nKillNum;//杀怪数量
	// for str packer
	char			szBuf[1];
}MSG_USER_INFO; 
/*
*/
NAMESPACE_END(msguserinfo)

#pragma pack()

#endif //_MSG_IMSGUSERINFO_H_

//==========================================================================
/**
*  @file   IMsgAction.h
*
*  $Id: IMsgAction.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGDOMAIN_H_
#define _MSG_IMSGDOMAIN_H_

#include "Define.h"

namespace msgdomain
{
	enum
	{
		_DOMAIN_CREATE		= 0,  //创建领域
		_DOMAIN_FAIL		= 1,  //创建领域失败	
		_DOMAIN_DESTROY		= 2,  //销毁领域
		_DOMAIN_ENTER		= 3,  //玩家进入领域
		_DOMAIN_LEAVE		= 4,  //玩家离开领域
// 		_DOMAIN_ON_CENTER	= 5,  // 玩家到领域中心
// 		_DOMAIN_LEAVE_CENTER= 6,  //玩家离开领域中心
		_DOMAIN_MAP_REPLY_LEV_LOW     = 5,   //地图领域已经有同类型的了
		_DOMAIN_MAP_REPLY_CONQUER     = 6,   //级数高突破了限制
		_DOMAIN_MAP_REPLY_NUM_HIGH    = 7,   //地图领域的数量已经到达上限
		_DOMAIN_REGION_REPLY_VALID_HIGH = 8, //区域有效数量已经到达上限
		_DOMAIN_REGION_REPLY_EXIST_HIGH = 9, //本地图区域的数量已经到达上限
		_DOMAIN_REGION_REPLY_CONQUER =10,   //级数高突破了限制
		_DOMAIN_LASTTIME			 = 20, //tc领域持续时间
	};
	
	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;

		USHORT		usAction;

		OBJID		idPlayer;

		OBJID		idRegion;       //领域ID
		uint32	    dwType;			//领域的类型

		int			nPosX;			//领域中心点x，当为玩家进入领域消息时为该玩家位置坐标x
		int			nPosY;			//领域中心点y，当为玩家进入领域消息时为该玩家位置坐标y

		uint32		dwCx;         //领域的长
		uint32		dwCy;			//领域的宽

		OBJID	    idOwnPlayer;	     //领域创建者的ID，当为玩家进入领域消息时为该玩家ID
		uint32		dwProfessionExp;	//创建者职业经验
		uint32		dwProfessionLev;	//创建者职业等级

		uint32		dwAccessTime;      // 该领域的持续时间
		OBJID		idSyndicate;	   // 所属帮派ID
		UCHAR		ucMagicLev;		   // 技能等级
		NAMESTR		strPlayerName;	   //创建者名字
		NAMESTR     strBelongName;     //创建者所属关系
	}MSG_DOMAIN;
	
}

#endif

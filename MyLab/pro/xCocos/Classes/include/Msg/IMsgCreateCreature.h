////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2008, TQ Digital Entertainment, All Rights Reserved
// Author:  Shen Rongfei
// Created: 2011/01/08
////////////////////////////////////////////////////////////////////////

#pragma once

#include "Define.h"
//#pragma pack(4)

namespace msgcreatecreature 
{
	#pragma pack(push,1)
	typedef struct CREATURE			//怪物信息
	{
		UINT templateid;  //怪物类型ID,匹配怪物的AI,技能和一些属性数值
		uint16_t mapid;     //地图ID
		float posX;       //坐标
		float posY;       //坐标
		float posZ;       //坐标
		float orientation;//方向
		uint32_t curhealth;   //当前的生命值
		uint32_t curmana;     //当前的能量值
		uint32_t movementType;//默认移动方式,0不动,1随机移动,2路径巡逻
		uint32_t randDist;    //随机移动的范围
		uint32_t waypath;     //路径巡逻的路径ID
		uint32_t corpsetime;  //尸体摆放时间
		uint32_t camp;        //阵营
		uint32_t level;			//等级
		uint32_t damageOnCreate;    //创建时执行damage
		uint32_t damageOnCreate2;    //创建时执行damage

		CREATURE()
		{
			templateid = 0;  
			mapid = 0;	
			 posX = 0;       
			 posY = 0;       
			 posZ = 0;       
			 orientation = 0;
			curhealth = 0;   
			curmana = 0;     
			movementType = 0;
			randDist = 0;    
			waypath = 0;     
			corpsetime = 0;  
			camp = 0;        
			level =	0;
			damageOnCreate = 0;
			damageOnCreate2 = 0;
		}
	}CREATURE_INFO;

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;

		UINT instanceid;  //副本ID
		USHORT usCount;						//怪物信息数量
		CREATURE_INFO setCreatureInfo[1];	//怪物信息集
	}MSG_CREATE_CREATURE;

	#pragma pack(pop)

}

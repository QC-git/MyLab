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
	typedef struct CREATURE			//������Ϣ
	{
		UINT templateid;  //��������ID,ƥ������AI,���ܺ�һЩ������ֵ
		uint16_t mapid;     //��ͼID
		float posX;       //����
		float posY;       //����
		float posZ;       //����
		float orientation;//����
		uint32_t curhealth;   //��ǰ������ֵ
		uint32_t curmana;     //��ǰ������ֵ
		uint32_t movementType;//Ĭ���ƶ���ʽ,0����,1����ƶ�,2·��Ѳ��
		uint32_t randDist;    //����ƶ��ķ�Χ
		uint32_t waypath;     //·��Ѳ�ߵ�·��ID
		uint32_t corpsetime;  //ʬ��ڷ�ʱ��
		uint32_t camp;        //��Ӫ
		uint32_t level;			//�ȼ�
		uint32_t damageOnCreate;    //����ʱִ��damage
		uint32_t damageOnCreate2;    //����ʱִ��damage

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

		UINT instanceid;  //����ID
		USHORT usCount;						//������Ϣ����
		CREATURE_INFO setCreatureInfo[1];	//������Ϣ��
	}MSG_CREATE_CREATURE;

	#pragma pack(pop)

}

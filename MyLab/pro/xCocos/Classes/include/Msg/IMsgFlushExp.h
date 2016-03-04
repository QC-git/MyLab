#ifndef _MSG_IMSGFLUSHEXP_H_
#define _MSG_IMSGFLUSHEXP_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#pragma pack(1)

namespace msgflushexp
{
	enum 
	{
		MSGFLUSHEXP_WEAPONSKILL,
		MSGFLUSHEXP_MAGIC,
		MSGFLUSHEXP_SKILL,
		MSG_USE_ANGEL_COUNTDOWN         =   4,

		MSG_USERCURSE_REMAINTIME	= 10,		// 2006.08.07 ֪ͨ�ͻ�������������ʱ�䵹��ʱ
		MSG_USERPRACTISE_POINTS		= 11,		//to c ��������������dwExp������,usType=1��˸��Ч��usType=0 ����˸						
		MSG_FULL_QUALITY9			= 12,		//to c ȫ����Ʒװ��,dwExp=playerid  tcp 2007-1-13 add	
		MSG_MSG_USER_RECOVERY_REMAINTIME = 13,		// ֪ͨ�ͻ�����Ҽӷ�����ʱ�䵹��ʱ
		MSG_USERFLY_REMAINTIME		= 15,       //֪ͨ�ͻ��˷���ʱ��
		MSG_USERDAMAGEDEC_REMAINTIME = 16,		//����������˺�ֵ���ٳ���ʱ��
		MSG_RECOVER_POWER_SLOWLY	= 100,		// 2005.12.23 ֪ͨ�ͻ��˷������ָ�Ŀ��ֵ�ͱ仯�ٶ�  to Client
		MSG_RECOVER_EN_SLOWLY,					// 2005.12.23 ֪ͨ�ͻ���EN�ָ�Ŀ��ֵ�ͱ仯�ٶ�  to Client
		MSG_TRANSPOS				= 106,		// 2007.3.2 ֪ͨ��Χ����Լ�������  to Client	dwExp:idPlayer			
		MSG_ATTACK_MONSTER_BY_RIGHT_WEAPON_AND_MAGIC = 107,//to C 2007.3.15 ��Χ��ҹ֡��ﱻ���ʵ������ͼ��ܻ���
		//dwExp:idMonster
		MSG_BEGIN_ONTIMER = 108,				//to C 2007.3.26 nType:��ʱ�������� ��ʱ��Ч�� tcp 2007-3-26 add
		MSG_PLAYFLASH = 109,				    //to C idIndex:��� nType:ѭ������ nDelayTimes:�ӳ�ʱ�� tcp 2007-3-27 add		
		MSG_SCREEN_EFFECT =110,					//to C 2007.4.14 tcp add ��ս������������	dwValue:��ĻЧ��
		MSG_STOP_EXCERSISE = 111,               //to C ������ֹͣ�����������δʹ��
		MSGFLUSHEXP_LIFESKILL = 200,
	};
	typedef struct
	{
		USHORT	usMsgSize;
		USHORT	usMsgType;

        union
		{
			struct 
			{// ����һ������flash��action 2007-4-5 tcp add
				OBJID idIndex;
				int   nDelayTimes;
			};
			U64			u64Exp;
		};

		union
		{
			int				nType;
			U32			dwValue;//��ս������������ 2007-4-14 tcp add
		};
		
		USHORT			    ucAction;
	}MSG_FLUSHEXP_INFO;
}

#pragma pack()

#endif //_MSG_IMSGFLUSHEXP_H_

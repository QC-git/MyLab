// MsgUserAttrib.h: interface for the CMsgItem class.
/**
 *  @file   IMsgUserAttrib.h
 *
 *  $Id: IMsgUserAttrib.h
 *
 *  @author chx <xxx@gmail.com>
 *  
 */
//==========================================================================

#ifndef _MSG_IMSGGETUSER_H_
#define _MSG_IMSGGETUSER_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
namespace msggetuser
{
	enum 
	{	
		INTERACT_NONE =0,
		actionexp,
		action_secondary_attack,
        action_killExp,
	};
//����Ϣ�����򸱱������� ��ҪidRole��Χ���� 
	#pragma pack(push, 1)
	typedef struct
	{
		USHORT	usMsgSize;
		USHORT	usMsgType;
					
		OBJID	idRole;
        USHORT  usAttackCamp;
		USHORT  usAction;
		int     nAmount;
		union
		{
			bool bIsShareExp; 
		};
		UCHAR	ucTargetAmount;	//Ŀ������
		OBJID   idAryTarget[1]; //Ŀ��id��
	}MSG_GETUSER;
	#pragma pack(pop)
}

#endif


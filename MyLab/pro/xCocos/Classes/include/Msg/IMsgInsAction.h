//==========================================================================
/**
*  @file   IMsgInsAction.h
*
*  $Id: IMsgInsAction.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGINSACTION_H_
#define _MSG_IMSGINSACTION_H_

#include "Define.h"
#include "MsgDefine.h"

namespace msginsaction
{
	enum
	{
        actionGetUserInfo,          //��������Ϣ
		//actionGetItemSet,           //�����Ʒ��Ϣ // TODO::MILO 11/12/2015 EntityExLogic
        actionGetEquipSet,          //��ȡװ����Ϣ
        actionGetSkillSet,          //��ü�����Ϣ
		actionGetInfoEnd,			//������־
		actionRoomEnd,			    //������־
	};
	
// #pragma pack(push,1)
	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;

		USHORT	    usAction;		
	    OBJID		idUser;

	} MSG_INS_ACTION;
// #pragma pack(pop,1)
}

#endif

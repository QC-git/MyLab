#ifndef _MSG_IMSGSKILLSUIT_H_
#define _MSG_IMSGSKILLSUIT_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
namespace msgskillsuit
{
	enum {	MSGSKILLSUIT_UPDATE,			// to client, update or add new
		MSGSKILLSUIT_DEL,				// to server, no respone
		MSGSKILLSUIT_ADDNEW,			// to server, no respone
		MSGSKILLSUIT_DELALL,			// to client, no respone
};
	typedef struct
	{
		USHORT			usMsgSize;
		USHORT			usMsgType;
		OBJID			idSkillSuit;
		SHORT			usAction;
		USHORT			usRobotType;			// 0:��ʦ��1������					// usHotkey;
		USHORT			usWeaponPos;
		uint32			dwSkill[1+3];			// ��� 1+3 ��, ע���� MAX_SKILLSIZE ͬ��
	}MSG_SKILLSUIT_INFO;

}
#endif //_MSG_IMSGSKILLSUIT_H_

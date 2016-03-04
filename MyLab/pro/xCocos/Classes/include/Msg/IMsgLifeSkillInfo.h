#ifndef _MSG_IMSGLIFESKILLINFO_H_
#define _MSG_IMSGLIFESKILLINFO_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"

namespace msglifeskillinfo
{
	enum
	{
		LIFESKILL_ACT_UPDATE,		//TC	update,add
		LIFESKILL_ACT_UPGRADE,		//TS、TC	升级,    取客户端传来的setSkillInfo[0]数据
		LIFESKILL_ACT_DELALL,		//TC, no respone
	};
	struct MsgLifeSkillInfoStruct 
	{
		USHORT usType;
		USHORT usLevel;
		uint32   dwExp; 
	};
	typedef struct
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		USHORT		usAction;
		USHORT		usNumData;
		MsgLifeSkillInfoStruct	setSkillInfo[1];
	}MSG_LIFESKILL_INFO;
	
}
#endif _MSG_IMSGLIFESKILLINFO_H_
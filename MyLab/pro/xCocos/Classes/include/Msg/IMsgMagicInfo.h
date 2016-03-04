#ifndef _MSG_IMSGMAGICINFO_H_
#define _MSG_IMSGMAGICINFO_H_
#if _MSC_VER > 1000
#pragma once
#endif
#include "Define.h"

namespace msgmagicinfo
{
	enum{
		MAGIC_ACT_UPDATE,		//TC	update,add
			MAGIC_ACT_UPGRADE,		//TS、TC	升级,    取客户端传来的setMagicInfo[0]数据
			MAGIC_ACT_DELALL,		//TC, no respone
			MAGIC_ACT_USE
	};
	
	#pragma pack(push)
	#pragma pack(1)
	struct MsgMagicInfoStruct {
		int nType;
		USHORT usLevel;
		uint32   dwExp; 
	};
	typedef struct
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		USHORT		usAction;
		USHORT		usNumData;
		
		MsgMagicInfoStruct	setMagicInfo[1];
	}MSG_MAGIC_INFO;
	#pragma pack(pop)
}

#endif //_MSG_IMSGMAGICINFO_H_

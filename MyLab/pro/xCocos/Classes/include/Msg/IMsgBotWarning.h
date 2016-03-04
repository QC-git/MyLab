
#ifndef _MSG_IMSGBOTWARNING_H_
#define _MSG_IMSGBOTWARNING_H_
#include "Types.h"

namespace msgbotwarning
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		char		data[1024]; 
	} MSG_BOTWARNING;
}

#endif

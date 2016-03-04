//==========================================================================
/**
*  @file   IMsgUserEnterInstance.h
*
*  $Id: IMsgUserEnterInstance.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGUSERENTERINSTANCERET_H_
#define _MSG_IMSGUSERENTERINSTANCERET_H_

#include "Define.h"

namespace msguserenterinstanceret
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SCID        userScid;      // 玩家的SOCKET ID
		SNID        insSnid;       // 副本的ID
		bool        bResult;       // 玩家退出副本是否成功

	} MSG_USERENTERINSTANCERET;
}

#endif

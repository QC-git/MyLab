//==========================================================================
/**
*  @file   IMsgUserLeaveInstance.h
*
*  $Id: IMsgUserLeaveinstance.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGUSERLEAVEINSTANCERET_H_
#define _MSG_IMSGUSERLEAVEINSTANCERET_H_

#include "Define.h"

namespace msguserleaveinstanceret
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SCID        userScid;      // 玩家的SOCKET ID
		SNID        insSnid;       // 副本的ID
		bool        bResult;       // 玩家退出副本是否成功

	} MSG_USERLEAVEINSTANCERET;
}

#endif

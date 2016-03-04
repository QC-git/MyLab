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
#ifndef _MSG_IMSGCREATEINSTANCE_H_
#define _MSG_IMSGCREATEINSTANCE_H_

#include "Define.h"

namespace msgcreateinstance
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SNID        insSnid;       // 副本的ID
		int         nMinUser;      // 最大支持的用户数 
		U32		dwAppealID;
		
	} MSG_CREATEINSTANCE;
}

#endif

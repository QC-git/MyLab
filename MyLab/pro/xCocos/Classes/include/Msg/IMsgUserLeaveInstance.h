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
#ifndef _MSG_IMSGUSERLEAVEINSTANCE_H_
#define _MSG_IMSGUSERLEAVEINSTANCE_H_

#include "Define.h"

namespace msguserleaveinstance
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SCID        userScid;      // ��ҵ�SOCKET ID
		SNID        insSnid;       // ������ID

	} MSG_USERLEAVEINSTANCE;
}

#endif

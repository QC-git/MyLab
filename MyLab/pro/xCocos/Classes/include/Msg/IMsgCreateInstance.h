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
		
		SNID        insSnid;       // ������ID
		int         nMinUser;      // ���֧�ֵ��û��� 
		U32		dwAppealID;
		
	} MSG_CREATEINSTANCE;
}

#endif

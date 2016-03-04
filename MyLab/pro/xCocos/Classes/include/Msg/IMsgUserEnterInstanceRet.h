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
		
		SCID        userScid;      // ��ҵ�SOCKET ID
		SNID        insSnid;       // ������ID
		bool        bResult;       // ����˳������Ƿ�ɹ�

	} MSG_USERENTERINSTANCERET;
}

#endif

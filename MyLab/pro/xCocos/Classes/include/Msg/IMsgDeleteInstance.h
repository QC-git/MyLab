//==========================================================================
/**
*  @file   IMsgDeleteInstance.h
*
*  $Id: IMsgDeleteinstance.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGDELETEINSTANCE_H_
#define _MSG_IMSGDELETEINSTANCE_H_

#include "Define.h"

namespace msgdeleteinstance
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SNID        insSnid;
	} MSG_DELETEINSTANCE;
}

#endif

//==========================================================================
/**
*  @file   IMsgInsAction.h
*
*  $Id: IMsgInsAction.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGRECONNECT_H_
#define _MSG_IMSGRECONNECT_H_

#include "Define.h"

namespace msgreconnect
{
    enum
    {
        actionConnect,               //重连
        actionConnectSuc,            //重连成功
        actionConnectFail,           //重连失败
        actionCancelConnect,         //取消重连
    };
	
    typedef struct 
    {
        USHORT		usMsgSize;
        USHORT		usMsgType;

        USHORT	    usAction;
        SCID	    userScid;	//玩家的SCID
        OBJID		idUser;
    } MSG_RE_CONNECT;
}

#endif

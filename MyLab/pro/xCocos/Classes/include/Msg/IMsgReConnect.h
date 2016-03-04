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
        actionConnect,               //����
        actionConnectSuc,            //�����ɹ�
        actionConnectFail,           //����ʧ��
        actionCancelConnect,         //ȡ������
    };
	
    typedef struct 
    {
        USHORT		usMsgSize;
        USHORT		usMsgType;

        USHORT	    usAction;
        SCID	    userScid;	//��ҵ�SCID
        OBJID		idUser;
    } MSG_RE_CONNECT;
}

#endif

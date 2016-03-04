#ifndef _IMsg_Connect_h_
#define _IMsg_Connect_h_


#include "Define.h"
#include "MsgDefine.h"

NAMESPACE_BEGIN(msgconnect)

typedef struct
{
    USHORT usMsgSize;
    USHORT usMsgType;

    OBJID idAccount;
    U32 dwAuthorize;
    char szUserName[_MAX_NAMESIZE];
    char szClientIp[IPSTR_SIZE + 1];
} MSG_CONNECT_INFO;

NAMESPACE_END(msgconnect)

#endif  // _IMsg_Connect_h_
/********************************************************************
	created:	2016/1/6 15:50:19
	author:		Du qisong
	
	purpose:	��Ϣ����
*********************************************************************/
#pragma once
#include "Types.h"

namespace baseframe {

enum PORT_MSG
{
    _MSG_CONNECT_EX = 168,                      //����MSG_CONNECT��Ϣ����ӿͻ���IP�ֶ�

    _MSG_BS2GS_PING = 169,                      // BS->GS Ping ��Ϣ

    // ���� 2015.11.24
    _MSG_SAVE_SNID = 170,
    _MSG_DEL_SCK = 180,
};

struct MSG_BASE
{
    U16 msgSize;
    U16 msgType;

    U16 Size()       { return msgSize; }
    U16 BodySize()   { return msgSize - sizeof(MSG_BASE); }
};

//struct MSG_CONNECT_EX : public MSG_BASE
//{
//    OBJID       idAccount;
//    U32  	    dwAuthorize;
//    char	    szUserName[_MAX_NAMESIZE];
//    char        szClientIp[IPSTR_SIZE+1];
//};

}
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
#ifndef _MSG_IMSGCREATEINSTANCERET_H_
#define _MSG_IMSGCREATEINSTANCERET_H_

#include "Types.h"

namespace msgcreateinstanceret
{

	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		SNID               insSnid;        // ������ID
		bool               bResult;        // ���������ɹ����
		int                nMaxUser;       // ���֧�ֵ��û��� 
		uint32_t           dwAppealID;
		uint32_t           ulUnionId;    //�ø�����ʹ�õ�DocId�͸���ID��ƴ��
        char               strTelecomIp[256]; //����IP
        char               strNetcomIp[256]; //��ͨIP
        char               strEducomIp[256]; //����IP
        char               strETietongIp[256]; //��ͨIP
		uint16_t           uServicePort;  //tcp����˿�
		uint16_t           uUdpServicePort; //udp����˿�
	} MSG_CREATEINSTANCERET;
}

#endif

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
		
		SNID               insSnid;        // 副本的ID
		bool               bResult;        // 副本创建成功与否
		int                nMaxUser;       // 最大支持的用户数 
		uint32_t           dwAppealID;
		uint32_t           ulUnionId;    //该副本所使用的DocId和副本ID的拼接
        char               strTelecomIp[256]; //电信IP
        char               strNetcomIp[256]; //联通IP
        char               strEducomIp[256]; //教育IP
        char               strETietongIp[256]; //铁通IP
		uint16_t           uServicePort;  //tcp服务端口
		uint16_t           uUdpServicePort; //udp服务端口
	} MSG_CREATEINSTANCERET;
}

#endif

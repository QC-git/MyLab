// -*- C++ -*-

//=============================================================================
/**
 *  @file    IMsgNotify.h
 *
 *  $Id: IMsgNotify.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _MSG_IMSGNOTIFY_H_
#define _MSG_IMSGNOTIFY_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#include "MsgDefine.h"

NAMESPACE_BEGIN(msgnotify)

enum 
{ 
	NEWBIEING = 0, 
	NEWBIE_SUCC, 
	NEWBIE_FAIL, 
	LOGINING, 
	LOGIN_SUCC, 
    LOGIN_FAIL, 
	LOGOUT, 
	HOLDING, 
	HOLD_SUCC, 
	HOLD_FAIL, 
	HOLD_OVER, 
	RECONNECTING,
	RECONNECT_SUCC,
	RECONNECT_FAIL,
	UNLOAD_DB,
};

enum 
{
	RESULT_NONE = 0,
	RESULT_FALSE,
	RESULT_TRUE,	
};

typedef struct
{
	USHORT	usMsgSize;
	USHORT	usMsgType;
	USHORT	usAction;
	OBJID	idActor;
    U32 	sck;
	char	szIP[16];
	U32	dwData;
	U32   dwData1; //client ip address
}MSG_NOTIFY_INFO;
	
NAMESPACE_END(msgnotify)

#endif
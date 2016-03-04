////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2008, TQ Digital Entertainment, All Rights Reserved
// Author:  Wu yongmin
// Created: 2008/03/11
////////////////////////////////////////////////////////////////////////

#pragma once

//获得消息枚举
#define SEPARATE_MSG ,
#define SEPARATE_TXT
#define SEPARATE_COLOR
#define MSGTYPE_DECLARE(id, val)    id = val
#define TXTATTR_DECLARE(id, val)
#define COLOR_DECLARE(id, val)
enum CONQ_MSG
{
#include "message.inl"
};
#undef MSGTYPE_DECLARE
#undef TXTATTR_DECLARE
#undef COLOR_DECLARE
#undef SEPARATE_COLOR
#undef SEPARATE_TXT
#undef SEPARATE_MSG

//获得字符属性枚举
#define SEPARATE_MSG
#define SEPARATE_TXT ,
#define SEPARATE_COLOR
#define MSGTYPE_DECLARE(id, val)
#define TXTATTR_DECLARE(id, val)    id = val
#define COLOR_DECLARE(id, val)
enum TXTATTR
{
#include "message.inl"
};
#undef MSGTYPE_DECLARE
#undef TXTATTR_DECLARE
#undef COLOR_DECLARE
#undef SEPARATE_COLOR
#undef SEPARATE_TXT
#undef SEPARATE_MSG

//获得颜色属性枚举
#define SEPARATE_MSG
#define SEPARATE_TXT
#define SEPARATE_COLOR   ,
#define MSGTYPE_DECLARE(id, val)
#define TXTATTR_DECLARE(id, val)
#define COLOR_DECLARE(id, val)    id = val
enum COLOR
{
#include "message.inl"
};
#undef MSGTYPE_DECLARE
#undef TXTATTR_DECLARE
#undef COLOR_DECLARE
#undef SEPARATE_COLOR
#undef SEPARATE_TXT
#undef SEPARATE_MSG

//获得消息名称
struct MSG_NAME
{
	const unsigned short msgId;
	const char*          msgName;

	MSG_NAME(const unsigned short id, const char *msg)
		: msgId(id), msgName(msg)
	{ }
};
#define SEPARATE_MSG ,
#define SEPARATE_TXT
#define SEPARATE_COLOR
#define MSGTYPE_DECLARE(id, val)    MSG_NAME(val, #id)
#define TXTATTR_DECLARE(id, val)
#define COLOR_DECLARE(id, val)
static MSG_NAME g_szMsgTag[] =
{
#include "message.inl"
};
#undef MSGTYPE_DECLARE
#undef TXTATTR_DECLARE
#undef COLOR_DECLARE
#undef SEPARATE_COLOR
#undef SEPARATE_TXT
#undef SEPARATE_MSG


namespace tq{
	void		ReMarshMessage();
	//获得消息的最大消息名字
	const int   GetMsgNameMaxLen();
	//获得消息对应的名字
	const char* GetMsgName(const unsigned short id);
}

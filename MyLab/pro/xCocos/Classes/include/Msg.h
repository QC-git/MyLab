// ********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Du qisong
// Created: 2015/11/3
//
// ********************************************************************
#pragma once

//#include <config.h>
#include <string.h>
#include "Types.h"
#include "MsgDefine.h"
#include "Macro.h"
//#include <BaseCode.h>

namespace tq
{
// msg head
typedef struct  MSG_HEAD
{
    USHORT usSize;
    USHORT usType;
} MSG_HEAD;

const USHORT MSG_HEAD_SIZE = sizeof(MSG_HEAD);

class CMsg
{
public:
    CMsg()
    {
        this->Init();
    }

    virtual ~CMsg()
    {}

    virtual const char* GetBuf(void) const
    {
        return m_bufMsg;
    }

    virtual USHORT GetSize(void) const
    {
        return m_head.usSize;
    }

    USHORT GetLeftSize(void) const
    {
        return _MAX_MSGSIZE - GetSize();
    }

    virtual USHORT GetType(void) const
    {
        return m_head.usType;
    }

    virtual USHORT GetHeadSize(void)
    {
        return sizeof(MSG_HEAD);
    }

    bool IsValid(void)
    {
        if(this->GetHeadSize() >= this->GetSize())
            return false;

        if(_MSG_NONE == this->GetType())
            return false;

        return true;
    }

    virtual void AppendInfo(OBJID idNpc) const
    {
        m_idNpc = idNpc;
    }

    OBJID GetNpcID(void) const
    {
        return m_idNpc;
    }

	void SetMapId(OBJID idMap) const
    {
         m_idNpc = idMap;
    }

protected:
    void Init(void)
    {
        ::memset(m_bufMsg, 0L, sizeof(m_bufMsg));
        m_head.usSize	=0;
        m_head.usType	=_MSG_NONE;
        m_idNpc=0;
    }

	mutable OBJID m_idNpc;
	union
	{
		char     m_bufMsg[(_MAX_MSGSIZE * 3)];
		MSG_HEAD m_head;
	};

public:
    virtual bool Create(const char* pszBuf, USHORT usBufLen)
    {
        if(!pszBuf)
            return false;

        MSG_HEAD* pHead = (MSG_HEAD*)pszBuf;
        if((USHORT)usBufLen != pHead->usSize)
            return false;

        if(_MSG_NONE == pHead->usType)
            return false;

        if ((_MAX_MSGSIZE*3) <= usBufLen)
             return false;

        ::memcpy(m_bufMsg, pszBuf, usBufLen);
        return true;
    }

    virtual void Process(void* pInfo)
    {
        UNUSED_ARG(pInfo);
        tq::LogSave("Module", "tq::CMsg::Process(void* pInfo) error");
    }

    virtual void Process(OBJID idActor)
    {
        UNUSED_ARG(idActor);
        tq::LogSave("Module", "tq::CMsg::Process(OBJID idActor) error");
    }

    virtual void Process(OBJID idActor, void* pInfo)
    {
        UNUSED_ARG(idActor);
        UNUSED_ARG(pInfo);
        tq::LogSave("Module", "tq::CMsg::Process(OBJID idActor, void* pInfo) error");
    }
};

//////////////////////////////////////////////////////////////////////////
// 服务器之间的消息
// 特别是GameServe与GlobeServe之间的消息
// Rossen Yu,07/23/2007
//////////////////////////////////////////////////////////////////////////
struct  MsgHeadGlobe : MSG_HEAD
{
    OBJID idActor;
};

//GlobeServe->GameServe的发送方式
enum MSG_SEND_STYLE
{
    MSS_ONLY_REQUEST,           //仅请求线程
    MSS_EXCEPT_REQUEST,         //除请求线程
    MSS_BROADCAST,              //广播
};

//    class CClusterMsg : public CMsg
//    {
//    public:
//    public:
//        explicit CClusterMsg() : CMsg() {};
//
//        virtual void Process(int nPortRequest, OBJID idActor
//                            , MSG_SEND_STYLE style = MSS_BROADCAST
//                            , gs::PORTGROUP group = gs::PORTGROUP_GAME) {};
//    };
}


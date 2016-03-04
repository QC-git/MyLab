/********************************************************************
	created:	2012/02/22   0:29
	author:		Xusf

	purpose:	封装使用protobuf定义的消息
	*********************************************************************/

#ifndef _TQ_PROTOMSG_H_
#define _TQ_PROTOMSG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Msg.h"
#include "google/protobuf/descriptor.h"

namespace tq
{
	template<typename T>
	class CProtoMsg : public tq::CMsg
	{
	protected:
		T m_info;
	public:
		T& GetBody() { return m_info; }
		bool IsValid() { return m_info.IsInitialized(); }

		virtual bool Serialize(USHORT usType)
		{
			try
			{
				m_head.usType = usType;
				m_head.usSize = m_info.ByteSize() + GetHeadSize();
			}
			catch (google::protobuf::FatalException)
			{
				tq::LogSave("Serialize", "msgtype(%d) Error", usType);
				return false;
			}
			catch (...)
			{
				tq::LogSave("Serialize", "msgtype(%d) Error", usType);
				return false;
			}

			IF_NOT(m_head.usSize < _MAX_MSGSIZE)
			{
				tq::ErrorMsg("%s oversize on Serialize", m_info.descriptor()->name().c_str());
				return false;
			}
			IF_NOT(m_head.usType != _MSG_NONE)
			{
				tq::ErrorMsg("%s typeerror on Serialize", m_info.descriptor()->name().c_str());
				return false;
			}

			try
			{
				IF_NOT(m_info.SerializeToArray(m_bufMsg + MSG_HEAD_SIZE, _MAX_MSGSIZE - MSG_HEAD_SIZE))
				{
					tq::LogSave("protoMsg", "msgtype(%d) Error", usType);
					return false;
				}
			}
			catch (google::protobuf::FatalException)
			{
				tq::LogSave("protoMsg", "msgtype(%d) Error", usType);
				return false;
			}
			catch (...)
			{
				tq::LogSave("protoMsg", "msgtype(%d) Error", usType);
				return false;
			}
			return true;
		}

	public:
		virtual bool Create(const char* pszBuf, USHORT usBufLen)
		{
			if (!pszBuf)
				return false;

			MSG_HEAD* pHead = (MSG_HEAD*)pszBuf;
			if ((USHORT)usBufLen != pHead->usSize)
				return false;

			if (_MSG_NONE == pHead->usType)
				return false;

			if (!CMsg::Create(pszBuf, usBufLen))
			{
				return false;
			}
			try
			{
				IF_NOT(m_info.ParseFromArray(pszBuf + MSG_HEAD_SIZE, usBufLen - MSG_HEAD_SIZE))
				{
					tq::LogSave("protoMsg", "msgtype(%d) Error", pHead->usType);
					return false;
				}
			}
			catch (google::protobuf::FatalException)
			{
				tq::LogSave("protoMsg", "msgtype(%d) Error", pHead->usType);
				return false;
			}
			catch (...)
			{
				tq::LogSave("protoMsg", "msgtype(%d) Error", pHead->usType);
				return false;
			}
			IF_NOT(this->IsValid())
				return false;

			return true;
		}
	};
}

#endif //_TQ_PROTOMSG_H_

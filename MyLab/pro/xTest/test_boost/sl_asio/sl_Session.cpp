#include "stdafx.h"

#include "sl_Session.h"
#include <boost/bind.hpp>

namespace sl_asio {
	Session::Session(const TcpSckPtr& sckPtr, IMessagePipe& pipe)
		: m_sckPtr(sckPtr)
		, m_pipe(pipe)
		, m_sckId(0)
	{

	}

	Session::~Session()
	{

	}


	void Session::Run()
	{
		char* buf = new char[MAX_MSG_SIZE];
		StartRead(buf, 0);
	}

	void Session::Write(const MsgPtr& msgPtr)
	{
		bool sendNow = m_sendQue.empty();
		m_sendQue.push_back(msgPtr);

		if (sendNow)
		{
			SendQueueMsg();
		}
	}

	void Session::HandleEnd(const ErrCode& ec)
	{
		if (m_sckPtr->is_open())
		{
			// todo:log
			m_sckPtr->close();
		}
	}

	void Session::StartRead(char* buff, size_t wp)
	{
		void* pos = buff + wp;
		size_t maxLen = MAX_MSG_SIZE - wp;
		m_sckPtr->async_read_some(boost::asio::buffer(pos, maxLen)
			, boost::bind(&Session::HandleRead, shared_from_this(), boost::asio::placeholders::error
			, boost::asio::placeholders::bytes_transferred, buff, wp));
	}

	void Session::HandleRead(const ErrCode& ec, size_t bytes_transferred, char* buff, size_t wp)
	{
		if (ec)
		{
			if (ec.value() == EC_Disconnect)
			{
				m_pipe.OnLostConnection(m_sckId);
			}

			HandleEnd(ec);
			delete [] buff;
			return;
		}

		wp += bytes_transferred;
		if (wp < sizeof(MsgSize) || bytes_transferred == 0)
		{
			StartRead(buff, wp);
			return;
		}

		MsgSize msgSize = *((MsgSize*)(buff));
		while(wp >= msgSize)
		{
			size_t overlen = wp - msgSize;
			char* newBuff = new char[MAX_MSG_SIZE];
			if (overlen > 0)
			{
				memcpy(newBuff, buff + msgSize, overlen);
			}

			try
			{
				m_pipe.OnProcessMsg(buff, m_sckId);
				delete [] buff;
			}
			catch(std::runtime_error& e) 
			{ 
				// todo:log
			}
			catch(...) 
			{
				// todo:log
			}

			buff = newBuff;
			wp = overlen;

			// 消息无溢出
			if (overlen == 0)
			{
				break;
			}

			msgSize = *((MsgSize*)(buff));
		}

		StartRead(buff, wp);
	}

	void Session::SendQueueMsg()
	{
		if (m_sendQue.empty())
		{
			return;
		}

		std::vector<boost::asio::const_buffer> buffers;
		buffers.reserve(m_sendQue.size());
		for (DeqMsg::iterator iter = m_sendQue.begin(); iter != m_sendQue.end(); ++iter)
		{
			MsgHead* head = iter->get();
			buffers.push_back(boost::asio::const_buffer(head, head->msgSize));
		}

		boost::asio::async_write(*m_sckPtr, buffers
			, boost::bind(&Session::HandleWrite, shared_from_this(), boost::asio::placeholders::error, buffers.size()));
	}

	void Session::HandleWrite(const ErrCode& ec, size_t msgNum)
	{
		if (ec)
		{
			HandleEnd(ec);
			return;
		}

		for (size_t i = 0; i < msgNum; ++i)
		{
			m_sendQue.pop_front();
		}

		SendQueueMsg();
	}

}




#pragma once

#include <deque>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include "sl_Interface.h"
#include "sl_Message.h"

namespace sl_asio {
	typedef boost::asio::ip::tcp::acceptor  TcpAccept;
	typedef boost::system::error_code       ErrCode;
	typedef boost::asio::ip::tcp::socket    TcpSck;
	typedef boost::shared_ptr<TcpSck>       TcpSckPtr;

	typedef std::deque<MsgPtr>              DeqMsg;

	const int EC_Disconnect = 10054;

	//////////////////////////////////////////////////////////////////////////

	class Session : public boost::enable_shared_from_this<Session>, public boost::noncopyable/*, public ISession*/
	{
	public:
		Session(const TcpSckPtr& sckPtr, IMessagePipe& pipe);
		~Session();

	public:
		void Write(const MsgPtr& msgPtr);
		void Run();
		void BindSessionId(SckId sckId) { m_sckId = sckId; }
		unsigned int GetSckId() const  { return m_sckId; }

	private:
		void HandleEnd(const ErrCode& ec);

		void StartRead(char* msg, size_t wp);
		void HandleRead(const ErrCode& ec, size_t bytes_transferred, char* msg, size_t wp);

		void SendQueueMsg();
		void HandleWrite(const ErrCode& ec, size_t msgNum);

	private:
		unsigned int m_sckId;
		TcpSckPtr m_sckPtr;
		DeqMsg m_sendQue;
		IMessagePipe& m_pipe;
	};

	typedef boost::shared_ptr<Session> SessionPtr;
}


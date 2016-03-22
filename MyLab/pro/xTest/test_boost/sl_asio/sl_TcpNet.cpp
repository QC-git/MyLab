#include "stdafx.h"

#include "sl_TcpNet.h"
#include <string>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

namespace sl_asio {
	SessionMgr::SessionMgr(AsioSvc& io)
		: AsioWork(io)
		, m_sckIdBeg(0)
	{

	}

	SessionMgr::~SessionMgr()
	{

	}

	unsigned int SessionMgr::Commit(const TcpSckPtr& sck, IMessagePipe& pipe)
	{
		SckId sckId = GenSckId();
		Session* session = new Session(sck, pipe);
		SessionPtr sessionPtr(session);
		m_scks.insert(std::make_pair(sckId, sessionPtr));

		session->BindSessionId(sckId);

		boost::asio::socket_base::receive_buffer_size option(REC_BUF_SIZE);
		sck->set_option(option);
		boost::asio::socket_base::send_buffer_size options(SEND_BUF_SIZE);
		sck->set_option(options);

		session->Run();

		return session->GetSckId();
	}

	bool SessionMgr::Send(SckId sckId, const MsgPtr& msgPtr)
	{
		SckMapIter iter = m_scks.find(sckId);
		if (iter == m_scks.end())
		{
			return false;
		}

		SessionPtr sessionPtr = iter->second;
		sessionPtr->Write(msgPtr);
		return true;
	}

	//////////////////////////////////////////////////////////////////////////

	TcpGuest::TcpGuest(IMessagePipe& pipe)
		: m_sessionMgr(m_io)
		, m_pipe(pipe)
	{
		boost::thread th(boost::bind(&AsioSvc::run, &m_io));
		m_thread.swap(th);

		m_timer.reset(new boost::asio::deadline_timer(m_io));
	}

	TcpGuest::~TcpGuest()
	{
		m_io.stop();
		m_thread.join();
	}

	unsigned int TcpGuest::Connect(const char* addr, unsigned short port)
	{
		ErrCode ec;

		TcpSckPtr sck(new TcpSck(m_io));
		sck->connect(TcpEP(boost::asio::ip::address::from_string(addr), port), ec);

		return ec ? 0 : m_sessionMgr.Commit(sck, m_pipe);
	}

	bool TcpGuest::AsyncConnect(const char* addr, unsigned short port)
	{
		resolver rler(m_io);
		resolver_query query(addr, boost::lexical_cast<std::string>(port));
		resolver_iter ep_it = rler.resolve(query);

		TcpSckPtr sck(new TcpSck(m_io));

		AsyncConnect(sck, ep_it);

		return true;
	}

	void TcpGuest::AsyncConnect(const TcpSckPtr& sck, resolver_iter ep_iter)
	{
		boost::asio::async_connect(*sck, ep_iter, boost::bind(&TcpGuest::HandleConnect, this, boost::asio::placeholders::error, sck));
	}

	void TcpGuest::HandleConnect(const ErrCode& ec, const TcpSckPtr& sck)
	{
		m_pipe.OnConnected(ec.value(), ec ? 0 : m_sessionMgr.Commit(sck, m_pipe));
	}

	void TcpGuest::RunUpdateTimer(unsigned int updateTime)
	{
		m_pipe.OnTick();
		m_timer->expires_from_now(boost::posix_time::milliseconds(updateTime));
		m_timer->async_wait(boost::bind(&TcpGuest::RunUpdateTimer, this, updateTime));
	}   

	bool TcpGuest::Send(SckId sckId, const MsgPtr& msgPtr)
	{
		return m_sessionMgr.Send(sckId, msgPtr);
	}

	void TcpGuest::Run()
	{
		m_io.run();
	}

	//////////////////////////////////////////////////////////////////////////

	TcpHost::TcpHost(IMessagePipe& pipe, const char* addr, unsigned short port)
		: TcpGuest(pipe)
		, m_acceptor(m_io)
	{
		m_acceptor.open(boost::asio::ip::tcp::v4());

		if (strcmp(addr, "0.0.0.0"))
		{
			m_acceptor.bind(TcpEP(boost::asio::ip::tcp::v4(), port));
		}
		else
		{
			m_acceptor.bind(TcpEP(boost::asio::ip::address::from_string(addr), port));
		}

		m_acceptor.listen();
		StartAccept();
	}

	void TcpHost::StartAccept()
	{
		TcpSckPtr sck(new TcpSck(m_io));
		m_acceptor.async_accept(*sck, boost::bind(&TcpHost::HandleAccept, this, boost::asio::placeholders::error, sck));
	}

	void TcpHost::HandleAccept(const ErrCode& ec, const TcpSckPtr& sck)
	{
		m_pipe.OnNewConnection(ec.value(), ec ? 0 : m_sessionMgr.Commit(sck, m_pipe));
		StartAccept();
	}

	unsigned int TcpHost::Connect(const char* addr, unsigned short port)
	{
		return TcpGuest::Connect(addr, port);
	}

	bool TcpHost::AsyncConnect(const char* addr, unsigned short port)
	{
		return TcpGuest::AsyncConnect(addr, port);
	}

	void TcpHost::RunUpdateTimer(unsigned int updateTime)
	{
		return TcpGuest::RunUpdateTimer(updateTime);
	}

	bool TcpHost::Send(SckId sckId, const MsgPtr& msgPtr)
	{
		return TcpGuest::Send(sckId, msgPtr);
	}
}




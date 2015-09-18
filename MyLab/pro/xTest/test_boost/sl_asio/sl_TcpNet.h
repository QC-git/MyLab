#pragma once

#include "sl_Session.h"
#include <map>
#include <boost/thread.hpp>

namespace sl_asio {
	typedef boost::asio::io_service                         AsioSvc;
	typedef boost::asio::io_service::work                   AsioWork;
	typedef boost::asio::ip::tcp::resolver                  resolver;
	typedef boost::asio::ip::tcp::resolver::query           resolver_query;
	typedef boost::asio::ip::tcp::resolver::iterator        resolver_iter;
	typedef boost::asio::ip::tcp::endpoint                  TcpEP;
	typedef boost::shared_ptr<boost::asio::deadline_timer>  TimerPtr;
	typedef std::map<unsigned int, const SessionPtr>        SckMap;
	typedef SckMap::iterator                                SckMapIter;

	class SessionMgr : public AsioWork
	{
	public:
		SessionMgr(AsioSvc& io);
		~SessionMgr();

	public:
		unsigned int Commit(const TcpSckPtr& sck, IMessagePipe& pipe);
		unsigned int GetSckId() const  { return m_sckIdBeg; }
		bool Send(SckId sckId, const MsgPtr& msgPtr);

	private:
		unsigned int GenSckId()    { return ++m_sckIdBeg; }

	private:
		unsigned int m_sckIdBeg;
		SckMap m_scks;
	};

	//////////////////////////////////////////////////////////////////////////

	class TcpGuest : public ITcpGuest
	{
	public:
		TcpGuest(IMessagePipe& pipe);
		~TcpGuest();

	public:
		virtual unsigned int Connect(const char* addr, unsigned short port);
		virtual bool AsyncConnect(const char* addr, unsigned short port);
		virtual void RunUpdateTimer(unsigned int updateTime);
		virtual bool Send(SckId sckId, const MsgPtr& msgPtr);

	private:
		void AsyncConnect(const TcpSckPtr& sck, resolver_iter ep_iter);
		void HandleConnect(const ErrCode& ec, const TcpSckPtr& sck);

	protected:
		AsioSvc m_io;
		SessionMgr m_sessionMgr;
		IMessagePipe& m_pipe;
		TimerPtr m_timer;

	private:
		boost::thread m_thread;
	};

	//////////////////////////////////////////////////////////////////////////

	class TcpHost : public TcpGuest, public ITcpHost
	{
	public:
		TcpHost(IMessagePipe& pipe, const char* addr, unsigned short port);

	public:
		virtual void StartAccept();
		// updateTime ∫¡√Î
		virtual void RunUpdateTimer(unsigned int updateTime);
		virtual unsigned int Connect(const char* addr, unsigned short port);
		virtual bool AsyncConnect(const char* addr, unsigned short port);
		virtual bool Send(SckId sckId, const MsgPtr& msgPtr);

	private:
		void HandleAccept(const ErrCode& ec, const TcpSckPtr& sck);

	private:
		TcpAccept m_acceptor;
	};

}





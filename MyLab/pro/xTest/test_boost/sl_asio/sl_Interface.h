#pragma once

#include <boost/shared_ptr.hpp>

namespace sl_asio {

	struct MsgHead;
	typedef boost::shared_ptr<MsgHead> MsgPtr;
	typedef unsigned int SckId;

	//////////////////////////////////////////////////////////////////////////

	class IMessagePipe
	{
	public:
		virtual void OnConnected(int error_code, SckId sckId) = 0;
		virtual void OnNewConnection(int error_code, SckId sckId) = 0;
		virtual void OnLostConnection(SckId sckId) = 0;
		virtual void OnProcessMsg(const char* msg, SckId sckId) = 0;
		virtual void OnTick() = 0;
	};

	//////////////////////////////////////////////////////////////////////////

	class ITcpGuest
	{
	public:
		virtual unsigned int Connect(const char* addr, unsigned short port) = 0;
		virtual bool AsyncConnect(const char* addr, unsigned short port) = 0;
		// updateTime ∫¡√Î
		virtual void RunUpdateTimer(unsigned int updateTime) = 0;
		virtual bool Send(SckId sckId, const MsgPtr& msgPtr) = 0;
	};

	typedef boost::shared_ptr<ITcpGuest> TcpGuestPtr;

	//////////////////////////////////////////////////////////////////////////

	class ITcpHost : public ITcpGuest
	{
	public:
		virtual void StartAccept() = 0;
	};

	typedef boost::shared_ptr<ITcpHost> TcpHostPtr;

	//////////////////////////////////////////////////////////////////////////

	class NetCreator
	{
	public:
		static TcpGuestPtr CreateTcpGuest(IMessagePipe& pipe);
		static TcpHostPtr CreateTcpHost(IMessagePipe& pipe, const char* addr, unsigned short port);
	};

}




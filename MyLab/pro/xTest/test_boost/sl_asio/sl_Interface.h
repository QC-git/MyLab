#pragma once

#include <boost/shared_ptr.hpp>

namespace sl_asio {

	const unsigned int MAX_MSG_SIZE = 1024;
	const unsigned int REC_BUF_SIZE = 128 * 1024;
	const unsigned int SEND_BUF_SIZE = 128 * 1024;

	typedef unsigned short MsgSize;
	typedef unsigned short MsgType;

	struct MsgHead
	{
		MsgSize msgSize;
		MsgType msgType;
	};

	typedef boost::shared_ptr<MsgHead> MsgPtr;
	typedef unsigned int SckId;

	//////////////////////////////////////////////////////////////////////////

	class IMessagePipe
	{
	public:
		virtual void OnConnected(int error_code, SckId sckId) {};
		virtual void OnNewConnection(int error_code, SckId sckId) {};
		virtual void OnLostConnection(SckId sckId) {};
		virtual void OnProcessMsg(const char* msg, SckId sckId) {};
		virtual void OnTick() {};
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

		virtual void Run(){};
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




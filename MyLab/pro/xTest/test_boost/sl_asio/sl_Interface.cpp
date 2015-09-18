#include "stdafx.h"

#include "sl_Interface.h"
#include "sl_TcpNet.h"

namespace sl_asio {

	TcpGuestPtr NetCreator::CreateTcpGuest(IMessagePipe& pipe)
	{
		return TcpGuestPtr(new TcpGuest(pipe));
	}

	TcpHostPtr NetCreator::CreateTcpHost(IMessagePipe& pipe, const char* addr, unsigned short port)
	{
		return TcpHostPtr(new TcpHost(pipe, addr, port));
	}

}


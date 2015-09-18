#pragma once

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
}

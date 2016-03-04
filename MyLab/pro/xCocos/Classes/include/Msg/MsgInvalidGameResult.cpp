#include "MsgInvalidGameResult.h"

namespace msginvalidgameresult
{

	CMsgInvalidGameResult::CMsgInvalidGameResult()
	{
		Init();
		m_pInfo = (MSG_Info*)m_bufMsg;
	}

	CMsgInvalidGameResult::~CMsgInvalidGameResult()
	{

	}

	//////////////////////////////////////////////////////////////////////
	bool CMsgInvalidGameResult::Create()
	{
		this->Init();

		// fill info now
		m_pInfo->usMsgSize	     = sizeof(MSG_Info);
		m_pInfo->usMsgType	     =_MSG_PLAYER_INVALID_GAMERESULT;

		return true;
	}

	//////////////////////////////////////////////////////////////////////
	bool CMsgInvalidGameResult::Create(char* pbufMsg, USHORT usMsgSize)
	{
		if (!pbufMsg)
		{
			return false;
		}

		if (!CMsg::Create(pbufMsg, usMsgSize))
		{
			return false;
		}

		if (_MSG_PLAYER_INVALID_GAMERESULT != this->GetType())
		{
			return false;
		}

		return true;
	}

} 

#pragma once

#include "log4cxx/logger.h"

namespace space_test_battle 
{

	VOID_T CalcAdd(U32_T& uData, U32_T uAdd, U32_T uLimit = UINT_MAX);

	VOID_T CalcDec(U32_T& uData, U32_T uDec, U32_T uLimit = UINT_MAX);

	struct SEnergy
	{
		U32_T uMaxValue;
		U32_T uValue;
		SEnergy()
		{
			uMaxValue = 0;
			uValue = 0;
		}

		VOID_T Reset(U32_T u)
		{
			uMaxValue = u;
			uValue = 0;
		}

		U32_T AddMax(U32_T u)
		{
			CalcAdd(uMaxValue, u);
			return uMaxValue;
		}

		U32_T DecMax(U32_T u)
		{
			CalcDec(uMaxValue, u);
			Syn();
			return uMaxValue;
		}

		U32_T Add(U32_T u)
		{
			CalcAdd(uValue, u);
			Syn();
			return uValue;
		}

		U32_T Dec(U32_T u)
		{
			CalcDec(uValue, u);
			return uValue;
		}

		VOID_T Syn()
		{
			if ( uValue > uMaxValue )
			{
				uValue = uMaxValue;
			}
		}

	};

	log4cxx::LoggerPtr GetScriptLogger();

#define UNIT_LOG_F(_message) LOG4CXX_INFO(m_pUnit->GetLogger(), _message)
#define SCRIPT_LOG_F(_message) LOG4CXX_INFO(GetScriptLogger(), _message)


}
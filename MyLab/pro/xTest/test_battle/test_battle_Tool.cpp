
#include "x_all.h"
#include "test_battle_Tool.h"

namespace space_test_battle
{

	VOID_T CalcAdd(U32_T& uData, U32_T uAdd, U32_T uLimit)
	{
		if ( uData > uLimit ) 
		{
			uData = uLimit;
		}

		U32_T uDif = uLimit - uData;  // 判断最大能增长多少
		if ( uAdd > uDif ) 
		{
			uAdd = uDif;
		}
		uData += uAdd;
	}

	VOID_T CalcDec(U32_T& uData, U32_T uDec, U32_T uLimit)
	{
		if ( uData > uLimit ) 
		{
			uData = uLimit;
		}
		if ( uDec > uData )  // 减数不得大于被减数
		{
			uDec = uData;
		}
		uData -= uDec;
	}

	log4cxx::LoggerPtr GetScriptLogger()
	{
		static log4cxx::LoggerPtr s_sp;
		if ( !s_sp )
		{
			s_sp = log4cxx::Logger::getLogger("脚本");
		}
		return s_sp;
	}

}
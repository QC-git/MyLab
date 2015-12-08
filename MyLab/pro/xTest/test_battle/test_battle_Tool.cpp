
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

		U32_T uDif = uLimit - uData;  // �ж��������������
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
		if ( uDec > uData )  // �������ô��ڱ�����
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
			s_sp = log4cxx::Logger::getLogger("�ű�");
		}
		return s_sp;
	}

}
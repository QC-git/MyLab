#pragma once


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

		VOID_T AddMax(U32_T& u)
		{
			CalcAdd(uMaxValue, u);
			u = uMaxValue;
		}

		VOID_T DecMax(U32_T& u)
		{
			CalcDec(uMaxValue, u);
			Syn();
			u = uMaxValue;
		}

		VOID_T Add(U32_T& u)
		{
			CalcAdd(uValue, u);
			Syn();
			u = uValue;
		}

		VOID_T Dec(U32_T& u)
		{
			CalcDec(uValue, u);
			u = uValue;
		}

		VOID_T Syn()
		{
			if ( uValue > uMaxValue )
			{
				uValue = uMaxValue;
			}
		}

	};




}
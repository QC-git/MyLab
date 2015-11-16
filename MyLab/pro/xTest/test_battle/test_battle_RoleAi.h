#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{

	class CRoleAi
	{
	public:
		CRoleAi(CUint* p);
		~CRoleAi();

		MARK_UNIT_ROLE(EUnitRole_AI)

		typedef U32_T Data;

	public:


	private:
		Data* m_pData;
		CUint* m_pUnit;

	};

}
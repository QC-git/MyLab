#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{
	class CRoleVoid
	{
	public:
		CRoleVoid(CUint* p);
		~CRoleVoid();

		MARK_UNIT_ROLE(EUnitRole_OTHER)

		struct Data
		{
			VOID_T* p;
		};

	public:
		VOID_T AddAny();

		VOID_T RemoveAny();

	private:
		Data* m_pData;
		CUint* m_pUnit;

	};


}
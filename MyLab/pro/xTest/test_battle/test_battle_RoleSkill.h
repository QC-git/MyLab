#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{

	class CRoleSkill
	{
	public:
		CRoleSkill(CUint* p);
		~CRoleSkill();

		MARK_UNIT_ROLE(EUnitRole_SKILL)

		struct Data
		{
			U32_T uSkillId;
			CUint* pTarget;

			Data()
			{
				uSkillId = 0;
				pTarget = NULL;
			}

		};

	public:
		BOOL_T CastSkill(U32_T uId, CUint* pTarget);
		BOOL_T IsCooling();
		CUint* GetTarget();

	private:
		Data* m_pData;
		CUint* m_pUnit;

	};

}
#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{

	class CRoleAdvance
	{
	public:
		CRoleAdvance(CUint* p);
		~CRoleAdvance();

		MARK_UNIT_ROLE(EUnitRole_ADVANCE)

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
		BOOL_T CastSkill(U32_T uSkillId, CUint* pTarget);
		BOOL_T RemoveSkill(U32_T uSkillId);
		BOOL_T IsCooling();
		CUint* GetTarget();

	public:
		BOOL_T AddStatus(U32_T uId);
		BOOL_T RemoveStatus(U32_T uId);
		BOOL_T HasStatus(U32_T uId);

	private:
		Data* m_pData;
		CUint* m_pUnit;

	};

}
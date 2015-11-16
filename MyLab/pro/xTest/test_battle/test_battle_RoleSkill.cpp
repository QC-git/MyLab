
#include "x_all.h"
#include "test_battle_RoleSkill.h"

namespace space_test_battle
{
	CRoleSkill::CRoleSkill(CUint* p)
	{
		m_pUnit = p;

		EUnitRole e = CRoleSkill::GetRoleType();
		m_pData = (Data*)p->GetRoleData(e);
	}

	CRoleSkill::~CRoleSkill()
	{
		;
	}

	BOOL_T CRoleSkill::CastSkill(U32_T uId, CUint* pTarget)
	{
		if ( this->IsCooling() )
		{
			return FALSE;
		}

		m_pData->uSkillId = uId;
		m_pData->pTarget = pTarget;

		return m_pUnit->AddTask(uId);
	}

	BOOL_T CRoleSkill::IsCooling()
	{
		U32_T uId = m_pData->uSkillId;
		return m_pUnit->HasTask(uId);
	}

	CUint* CRoleSkill::GetTarget()
	{
		return m_pData->pTarget;
	}

}
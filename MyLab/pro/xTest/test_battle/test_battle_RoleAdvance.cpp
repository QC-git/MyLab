
#include "x_all.h"
#include "test_battle_RoleAdvance.h"

namespace space_test_battle
{
	CRoleAdvance::CRoleAdvance(CUint* p)
	{
		m_pUnit = p;

		EUnitRole e = CRoleAdvance::GetRoleType();
		m_pData = (Data*)p->GetRoleData(e);
	}

	CRoleAdvance::~CRoleAdvance()
	{
		;
	}

	BOOL_T CRoleAdvance::CastSkill(U32_T uSkillId, CUint* pTarget)
	{
		if ( this->IsCooling() )
		{
			return FALSE;
		}

		LOG_F("ÊÍ·Å¼¼ÄÜ %d", uSkillId);

		m_pData->uSkillId = uSkillId;
		m_pData->pTarget = pTarget;

		return m_pUnit->AddTask(uSkillId);
	}

	BOOL_T CRoleAdvance::IsCooling()
	{
		U32_T uId = m_pData->uSkillId;
		return m_pUnit->HasTask(uId);
	}

	CUint* CRoleAdvance::GetTarget()
	{
		return m_pData->pTarget;
	}

	BOOL_T CRoleAdvance::AddStatus(U32_T uStatusId)
	{
		if ( m_pUnit->HasTask(uStatusId) ) {
			return FALSE;
		}

		return m_pUnit->AddTask(uStatusId);
	}

	BOOL_T CRoleAdvance::RemoveStatus(U32_T uStatusId)
	{
		if ( !m_pUnit->HasTask(uStatusId) ) {
			return FALSE;
		}

		return m_pUnit->RemoveTask(uStatusId);
	}

	BOOL_T CRoleAdvance::HasStatus(U32_T uStatusId)
	{
		return m_pUnit->HasTask(uStatusId);
	}

}
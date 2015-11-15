
#include "x_all.h"
#include "test_battle_RoleStatus.h"

namespace space_test_battle
{
	CRoleStatus::CRoleStatus(CUint* p)
	{
		m_pUnit = p;
		m_pData = (Data*)p->GetRoleData(EUnitRole_STATUS);
	}

	CRoleStatus::~CRoleStatus()
	{
		;
	}

	BOOL_T CRoleStatus::AddStatus(U32_T uId)
	{
		Data& cMap = (*m_pData);

		if ( this->HasStatus(uId) )
		{
			PStatus_T& sp = cMap[uId];
			sp->uLayer += 1;
		}
		else
		{
			PStatus_T sp;
			sp->uId = uId;
			sp->uLayer = 1;
			sp->uTickCnt = 0;
			cMap[uId] = sp;
		}

		if ( !m_pUnit->HasTask(uId) )
		{
			m_pUnit->AddTask(uId);
		}

		return TRUE;
	}

	BOOL_T CRoleStatus::RemoveStatus(U32_T uId)
	{
		Data::iterator iter = m_pData->find(uId);
		if ( iter == m_pData->end() )
		{
			return FALSE;
		}
		if ( m_pUnit->HasTask(uId) )
		{
			m_pUnit->RemoveTask(uId);
		}
		m_pData->erase(iter);
		return TRUE;
	}

	BOOL_T CRoleStatus::HasStatus(U32_T uId)
	{
		Data::iterator iter = m_pData->find(uId);
		return iter != m_pData->end();
	}

}
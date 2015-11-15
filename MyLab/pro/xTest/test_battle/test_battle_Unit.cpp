
#include "x_all.h"
#include "test_battle_Unit.h"

namespace space_test_battle 
{
	CUint::CUint()
	{
		this->ReleaseData();
	}

	CUint::~CUint()
	{
		;
	}

	VOID_T CUint::OnTick()
	{
		;
	}

	BOOL_T CUint::AddRole(EUnitRole e, VOID_T* pData)
	{
		VOID_T* p = m_cRolesMap[e];
		if (p)
		{
			return FALSE;
		}
		m_cRolesMap[e] = pData;
		return TRUE;
	}

	VOID_T* CUint::GetRoleData(EUnitRole e)
	{
		return m_cRolesMap[e];
	}

	BOOL_T CUint::HasRole(EUnitRole e)
	{
		return NULL != m_cRolesMap[e];
	}

	BOOL_T CUint::AddStatus(U32_T u)
	{
		StatusList_T::iterator iter = m_cStatusList.find(u);
		if ( iter == m_cStatusList.end() ) 
		{
			Status_T sp;
			sp->uId = u;
			sp->uLevel = 1;
			sp->uTickCnt = 0;
			m_cStatusList.insert(std::pair<U32_T, Status_T>(u, sp));
		}
		else
		{
			Status_T& sp = iter->second;
			sp->uLevel += 1;
		}
		return TRUE;
	}

	BOOL_T CUint::RemoveStatus(U32_T u)
	{
		StatusList_T::iterator iter = m_cStatusList.find(u);
		if ( iter == m_cStatusList.end() )
		{
			return FALSE;
		}
		m_cStatusList.erase(iter);
		return TRUE;
	}

	VOID_T CUint::ReleaseData() 
	{
		m_cRolesMap.clear();
		m_cStatusList.clear();
		m_cEventList.clear();
	}

}
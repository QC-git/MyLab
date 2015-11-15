
#include "x_all.h"
#include "test_battle_Unit.h"
#include "test_battle_Manager.h"

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
		TaskList_T::iterator iter;
		FOR_EACH(m_cTaskList, iter)
		{
			U32_T uId = *iter;
			FUNC_T* pFunc = CManager::GetStautsFunc(uId);
			if (pFunc)
			{
				pFunc(this);
			}
		}
	}

	BOOL_T CUint::AddRole(EUnitRole e, VOID_T* pData)
	{
		if ( this->HasRole(e) )
		{
			return NULL;
		}
		m_cDataMap[e] = pData;
		return TRUE;
	}

	VOID_T* CUint::GetRoleData(EUnitRole e)
	{
		if ( !this->HasRole(e) )
		{
			return NULL;
		}
		return m_cDataMap[e];
	}

	BOOL_T CUint::HasRole(EUnitRole e)
	{
		DataMap_T::iterator iter = m_cDataMap.find(e);
		return iter != m_cDataMap.end();
	}

	BOOL_T CUint::AddTask(U32_T u)
	{
		TaskList_T::iterator iter = m_cTaskList.find(u);
		if ( iter != m_cTaskList.end() ) 
		{
			return FALSE;
		}
		m_cTaskList.insert(u);
		return TRUE;
	}

	BOOL_T CUint::RemoveTask(U32_T u)
	{
		TaskList_T::iterator iter = m_cTaskList.find(u);
		if ( iter == m_cTaskList.end() )
		{
			return FALSE;
		}
		m_cTaskList.erase(iter);
		return TRUE;
	}

	BOOL_T CUint::HasTask(U32_T u)
	{
		TaskList_T::iterator iter = m_cTaskList.find(u);
		return iter != m_cTaskList.end();
	}

	VOID_T CUint::ReleaseData() 
	{
		m_cDataMap.clear();
		m_cTaskList.clear();
		m_cEventList.clear();
	}

}
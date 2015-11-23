
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
			Script_T* pFunc = CManager::GetTaskScript(uId);
			if (pFunc)
			{
				pFunc(this, 0);
			}
		}
	}

	VOID_T CUint::Syn(U32_T uFlag)
	{
		TaskList_T::iterator iter;
		TaskList_T::iterator iterEx;

		switch(uFlag)
		{
		case 11:
			{
				FOR_EACH(m_cAddTaskList, iter)
				{
					U32_T uId = *iter;
					iterEx = m_cTaskList.find(uId);
					if ( iterEx != m_cTaskList.end() ) // 有重复
					{
						m_cAddTaskList.erase(iter);
						continue;
					}
					m_cTaskList.insert(uId);  // 主列表增加
				}
				m_cSynAddTaskList = m_cAddTaskList;
				m_cAddTaskList.clear();
			}break;
		case 12:
			{
				FOR_EACH(m_cDelTaskList, iter)
				{
					U32_T uId = *iter;
					iterEx = m_cTaskList.find(uId);
					if ( iterEx == m_cTaskList.end() )  //没找到
					{
						m_cDelTaskList.erase(iter);
						continue;
					}
					m_cTaskList.erase(iterEx);   // 主列表删除
				}
				m_cSynDelTaskList = m_cDelTaskList;
				m_cDelTaskList.clear();
			}break;
		case 21:
			{
				TaskList_T& cList = m_cSynAddTaskList;
				FOR_EACH(cList, iter)
				{
					U32_T uId = *iter;
					Script_T* pScript = CManager::GetTaskScript(uId);
					if (pScript)
					{
						pScript(this, uFlag);
					}
				}
				cList.clear();
			}break;
		case 22:
			{
				TaskList_T& cList = m_cSynDelTaskList;
				FOR_EACH(cList, iter)
				{
					U32_T uId = *iter;
					Script_T* pScript = CManager::GetTaskScript(uId);
					if (pScript)
					{
						pScript(this, uFlag);
					}
				}
				cList.clear();
			}break;
		case 100:
			{
				//todo 同步事件
			}break;
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
		TaskList_T& cList = m_cAddTaskList;
		TaskList_T::iterator iter = cList.find(u);
		if ( iter != cList.end() ) 
		{
			return TRUE;
		}
		cList.insert(u);
		return TRUE;
	}

	BOOL_T CUint::RemoveTask(U32_T u)
	{
		TaskList_T& cList = m_cDelTaskList;
		TaskList_T::iterator iter = cList.find(u);
		if ( iter == cList.end() )
		{
			return TRUE;
		}
		cList.erase(iter);
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
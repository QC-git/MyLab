
#include "x_all.h"

#include "test_battle_Unit.h"
#include "test_battle_Manager.h"

namespace space_test_battle 
{
	CUint::CUint(U32_T uId)
		: m_uId(uId)
	{
		this->ReleaseData();
		ASSERT_F(m_uId);
		
		char sName[32];
		sprintf(sName, "单位%d", m_uId);
		
		m_spLog = log4cxx::Logger::getLogger(sName);  
	}

	CUint::~CUint()
	{
		;
	}

	U32_T CUint::GetId()
	{
		return m_uId;
	}

	VOID_T CUint::OnTick()
	{
		TaskList_T::iterator iter;
		
		FOR_EACH(m_cTaskList, iter)
		{
			U32_T uId = iter->first;
			STaskInfo* pInfo = iter->second;
			pInfo->uCount++;

			Script_T* pFunc = CManager::GetTaskScript(uId);
			if (pFunc)
			{
				pFunc(this, pInfo, ETaskFlag_Normal);
			}
		}
	}

	VOID_T CUint::Syn(U32_T uFlag)
	{
		PreTaskList_T::iterator cPreIter;
		TaskList_T::iterator cIter;

		switch(uFlag)
		{
		case ETaskFlag_ADD:
			{
				PreTaskList_T cTaskList;
				FOR_EACH(m_cPreAddTasks, cPreIter)
				{
					U32_T uTaskId = *cPreIter;
					cIter = m_cTaskList.find(uTaskId);
					if ( cIter == m_cTaskList.end() ) 
					{
						LOG_F("单位 %d 增加任务 %d", m_uId, uTaskId);
						cTaskList.insert(uTaskId);
					} 
				}
				m_cPreAddTasks.clear();

				FOR_EACH(cTaskList, cPreIter)
				{
					U32_T uTaskId = *cPreIter;
					STaskInfo* pInfo = new STaskInfo;
					pInfo->uId = uTaskId;

					Script_T* pFunc = CManager::GetTaskScript(uTaskId);					
					m_cTaskList[uTaskId] = pInfo;

					if (pFunc)
					{
						pFunc(this, pInfo, uFlag);
					}
				}

			}break;
		case ETaskFlag_DEC:
			{
				PreTaskList_T cTaskList;
				FOR_EACH(m_cPreDelTasks, cPreIter)
				{
					U32_T uTaskId = *cPreIter;
					cIter = m_cTaskList.find(uTaskId);
					if ( cIter != m_cTaskList.end() ) 
					{
						LOG_F("单位 %d 删除任务 %d", m_uId, uTaskId);
						cTaskList.insert(uTaskId);					
					} 
				}

				m_cPreDelTasks.clear();

				FOR_EACH(cTaskList, cPreIter)
				{
					U32_T uTaskId = *cPreIter;
					STaskInfo* pInfo = m_cTaskList[uTaskId];

					Script_T* pFunc = CManager::GetTaskScript(uTaskId);
					if (pFunc)
					{
						pFunc(this, pInfo, uFlag);
					}
					delete pInfo;
					m_cTaskList.erase(uTaskId);
				}
			}break;
		case ETaskFlag_SYN_EVENT:
			{
				m_cEventList.clear();
				m_cEventList = m_cPreEventList;
				m_cPreEventList.clear();
			}break;
		}
		
	}


	BOOL_T CUint::AddRole(EUnitRole e, VOID_T* pData)
	{
		if ( this->HasRole(e) )
		{
			return NULL;
		}
		LOG_F("单位 %d 获得新角色 %d", m_uId, e);
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
		PreTaskList_T& cList = m_cPreAddTasks;
		PreTaskList_T::iterator iter = cList.find(u);
		if ( iter != cList.end() ) 
		{
			return TRUE;
		}
		cList.insert(u);
		return TRUE;
	}

	BOOL_T CUint::RemoveTask(U32_T u)
	{
		PreTaskList_T& cList = m_cPreDelTasks;
		PreTaskList_T::iterator iter = cList.find(u);
		if ( iter != cList.end() )
		{
			return TRUE;
		}
		cList.insert(u);
		return TRUE;
	}

	BOOL_T CUint::HasTask(U32_T u)
	{
		TaskList_T::iterator iter = m_cTaskList.find(u);
		return iter != m_cTaskList.end();
	}

	VOID_T* CUint::GetTaskInfo(U32_T u)
	{
		TaskList_T::iterator iter = m_cTaskList.find(u);
		if ( iter == m_cTaskList.end() ) {
			return NULL;
		}
		return iter->second;
	}

	BOOL_T CUint::PushEvent(U32_T u)
	{	
		return m_cPreEventList.insert(u).second;;
	}

	BOOL_T CUint::WaitEvent(U32_T u)
	{
		return m_cEventList.find(u) != m_cEventList.end();
	}

	log4cxx::LoggerPtr CUint::GetLogger()
	{
		return m_spLog;
	}

	VOID_T CUint::ReleaseData() 
	{
		m_cDataMap.clear();
		m_cTaskList.clear();
		m_cEventList.clear();
	}

}
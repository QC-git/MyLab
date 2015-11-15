
#include "x_all.h"
#include "test_battle_Manager.h"

namespace space_test_battle 
{

	StatusFuncMap_T CManager::m_cStatusFuncMap;

	CManager::CManager()
	{
		;
	}

	CManager::~CManager()
	{
		;
	}

	

	BOOL_T CManager::RegisterStatusFunc(U32_T uId, FUNC_T* pFunc)
	{
		m_cStatusFuncMap[uId] = pFunc;
		return TRUE;
	}

	FUNC_T* CManager::GetStautsFunc(U32_T uId)
	{
		StatusFuncMap_T::iterator iter = m_cStatusFuncMap.find(uId);
		if ( iter == m_cStatusFuncMap.end() )
		{
			return NULL;
		}
		return m_cStatusFuncMap[uId];
	}

}
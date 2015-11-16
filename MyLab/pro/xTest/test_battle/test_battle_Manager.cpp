
#include "x_all.h"
#include "test_battle_Manager.h"

namespace space_test_battle 
{

	ScriptMap_T CManager::s_cScriptMap;

	UnitList_T CManager::s_cUnitList;

	U32_T CManager::s_nTickCnt = 0;

	CManager::CManager()
	{
		;
	}

	CManager::~CManager()
	{
		;
	}

	

	BOOL_T CManager::RegisterTaskScript(U32_T uId, Script_T* pScript)
	{
		s_cScriptMap[uId] = pScript;
		return TRUE;
	}

	Script_T* CManager::GetTaskScript(U32_T uId)
	{
		ScriptMap_T::iterator iter = s_cScriptMap.find(uId);
		if ( iter == s_cScriptMap.end() )
		{
			return NULL;
		}
		return s_cScriptMap[uId];
	}

	BOOL_T CManager::Create()
	{
		LOG_F("CManager::Create()");

		CUint* p1 = new CUint;
		CUint* p2 = new CUint;
		BOOL_T bRet;

		bRet = MakeRole(p1, (CRoleCommon*)NULL);	LOG_F("%d", bRet);
		bRet = MakeRole(p1, (CRoleSkill*)NULL);		LOG_F("%d", bRet);

		bRet = MakeRole(p2, (CRoleCommon*)NULL);	LOG_F("%d", bRet);
		bRet = MakeRole(p2, (CRoleSkill*)NULL);		LOG_F("%d", bRet);

		s_cUnitList.insert(p1);
		s_cUnitList.insert(p2);

		return TRUE;
	}

	VOID_T CManager::Tick()
	{
		s_nTickCnt++;
		if ( 0 == s_nTickCnt%10 )
		{
			LOG_F("CManager::Tick(), %d", s_nTickCnt);
		}
		

		UnitList_T::iterator iter;
		FOR_EACH(s_cUnitList, iter)
		{
			CUint* p = *iter;
			p->OnTick();
		}
	}

}
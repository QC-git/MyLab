
#include "x_all.h"
#include "test_battle_Manager.h"

namespace space_test_battle 
{

	ScriptMap_T CManager::s_cScriptMap;

	UnitList_T CManager::s_cUnitList;

	U32_T CManager::s_nTickCnt = 0;

	extern VOID_T LoadAllScript();

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

		LoadAllScript();

		CUint* p1 = new CUint;
		CUint* p2 = new CUint;
		BOOL_T bRet;

		bRet = MakeRole(p1, (CRoleCommon*)NULL);	LOG_F("%d", bRet);
		bRet = MakeRole(p1, (CRoleSkill*)NULL);		LOG_F("%d", bRet);

		bRet = MakeRole(p2, (CRoleCommon*)NULL);	LOG_F("%d", bRet);
		bRet = MakeRole(p2, (CRoleSkill*)NULL);		LOG_F("%d", bRet);

		s_cUnitList.insert(p1);
		s_cUnitList.insert(p2);

		CRoleCommon* pRole1 = CManager::GetRole(p1, (CRoleCommon*)NULL);
		CRoleCommon* pRole2 = CManager::GetRole(p2, (CRoleCommon*)NULL);

		U32_T uValue = 10000;
		pRole1->AddMaxHealth(uValue);

		uValue = 10000;
		pRole1->AddHealth(uValue);

		uValue = 30000;
		pRole2->AddMaxHealth(uValue);

		uValue = 30000;
		pRole2->AddHealth(uValue);

		CRoleSkill* pRole11 = CManager::GetRole(p1, (CRoleSkill*)NULL);
		pRole11->CastSkill(101, p2);
		

		return TRUE;
	}

	VOID_T CManager::Tick()
	{
		s_nTickCnt++;
		if ( 0 == s_nTickCnt%100 )
		{
			LOG_F("CManager::Tick(), %d", s_nTickCnt);
		}
		

		UnitList_T::iterator iter;
		FOR_EACH(s_cUnitList, iter)
		{
			CUint* p = *iter;
			p->OnTick();
		}

		CManager::Syn();
		
	}

	VOID_T CManager::Syn()
	{
		UnitList_T::iterator iter;

		FOR_EACH(s_cUnitList, iter)  // 同步任务表
		{
			CUint* p = *iter;
			p->Syn(12);
			p->Syn(11);
		}

		FOR_EACH(s_cUnitList, iter)  // 同步添加删除通知
		{
			CUint* p = *iter;
			p->Syn(22);
			p->Syn(21);
		}

		FOR_EACH(s_cUnitList, iter)  // 同步事件
		{
			CUint* p = *iter;
			p->Syn(100);
		}
	}

}

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

		s_cUnitList[123001] = p1;
		s_cUnitList[123002] = p2;

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

		return TRUE;
	}

	VOID_T CManager::OnMessage(VOID_T* pMsgList)
	{
		static BOOL_T bFirst = true;

		if (bFirst) {
			bFirst = false;

			CUint* p1 = s_cUnitList[123001];
			CUint* p2 = s_cUnitList[123002];

			CRoleSkill* pRole11 = CManager::GetRole(p1, (CRoleSkill*)NULL);
			pRole11->CastSkill(101, p2);
		}

	}

	VOID_T CManager::OnTick()
	{
		s_nTickCnt++;
		if ( 0 == s_nTickCnt%100 )
		{
			LOG_F("CManager::Tick(), %d", s_nTickCnt);
		}
		

		UnitList_T::iterator iter;
		FOR_EACH(s_cUnitList, iter)
		{
			CUint* p = iter->second;
			p->OnTick();
		}

		CManager::Syn();
		
	}

	VOID_T CManager::Syn()
	{
		UnitList_T::iterator iter;

		FOR_EACH(s_cUnitList, iter)  // ͬ�������
		{
			CUint* p = iter->second;
			p->Syn(12);
			p->Syn(11);
		}

		FOR_EACH(s_cUnitList, iter)  // ͬ�����ɾ��֪ͨ
		{
			CUint* p = iter->second;
			p->Syn(22);
			p->Syn(21);
		}

		FOR_EACH(s_cUnitList, iter)  // ͬ���¼�
		{
			CUint* p = iter->second;
			p->Syn(100);
		}
	}

}
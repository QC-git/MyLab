
#include "x_all.h"
#include "test_battle_Manager.h"

#include "log4cxx/propertyconfigurator.h"

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

	CUint* CManager::CreateUnit()
	{
		static U32_T s_uSn = 0;
		
		U32_T uId = ++s_uSn;
		ASSERT_F(uId);

		CUint* p = new CUint(uId);
		ASSERT_F(p);

		if ( p && !GetUnit(uId) )
		{
			LOG_F("创建新单位 %d", uId);
			s_cUnitList[uId] = p;
		}

		return p;
	}

	CUint* CManager::GetUnit(U32_T uGuid)
	{
		UnitList_T::iterator cIter = s_cUnitList.find(uGuid);
		if ( cIter == s_cUnitList.end() ) 
		{
			return NULL;
		}
		return cIter->second;
	}

	UnitSet_T CManager::getAllUnit(U32_T uIgnoreGuid)
	{
		UnitSet_T cList;

		UnitList_T::iterator cIter;
		FOR_EACH(s_cUnitList, cIter)
		{
			CUint* p = cIter->second;
			if ( p->GetId() == uIgnoreGuid )
			{
				continue;;
			}
			cList.insert(p);
		}

		return cList;
	}

	BOOL_T CManager::Init()
	{
		LOG_F("CManager::Init()");

		log4cxx::PropertyConfigurator::configure("log4cxx.properties");

		LoadAllScript();

		CUint* p1 = CManager::CreateUnit();
		CUint* p2 = CManager::CreateUnit();
		CUint* p3 = CManager::CreateUnit();
		BOOL_T bRet;

		bRet = MakeRole<CRoleBase>(p1);			ASSERT_F(bRet);
		bRet = MakeRole<CRoleAdvance>(p1);		ASSERT_F(bRet);

		bRet = MakeRole<CRoleBase>(p2);			ASSERT_F(bRet);
		bRet = MakeRole<CRoleAdvance>(p2);		ASSERT_F(bRet);

		bRet = MakeRole<CRoleBase>(p3);			ASSERT_F(bRet);
		bRet = MakeRole<CRoleAdvance>(p3);		ASSERT_F(bRet);

		SP_D(CRoleBase) spRole1 = CManager::GetRole<CRoleBase>(p1);
		SP_D(CRoleBase) spRole2 = CManager::GetRole<CRoleBase>(p2);
		SP_D(CRoleBase) spRole3 = CManager::GetRole<CRoleBase>(p3);

		U32_T uValue = 10000;
		spRole1->AddMaxHealth(uValue);
		spRole1->AddHealth(uValue);


		spRole2->AddMaxHealth(uValue);
		spRole2->AddHealth(uValue);

		spRole3->AddMaxHealth(uValue);
		spRole3->AddHealth(uValue);

		return TRUE;
	}

	VOID_T CManager::OnMessage(VOID_T* pMsgList)
	{
		static BOOL_T bFirst = true;

		if (bFirst) {
			bFirst = false;

			SP_D(CRoleAdvance) spRole = CManager::GetRole<CRoleAdvance>(1);
			CUint* pTarget = CManager::GetUnit(2);
			spRole->CastSkill(103, pTarget);

			
			//CRoleAdvance* pRole11 = 
			//spRole->AddStatus(1001);
			//spRole->AddStatus(1002);
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

		FOR_EACH(s_cUnitList, iter)  // 同步添加删除通知
		{
			CUint* p = iter->second;
			p->Syn(ETaskFlag_DEC);
			p->Syn(ETaskFlag_ADD);
		}

		FOR_EACH(s_cUnitList, iter)  // 同步事件
		{
			CUint* p = iter->second;
			p->Syn(ETaskFlag_SYN_EVENT);
		}
	}

}
#pragma once

#include "test_battle_RoleCommon.h"
#include "test_battle_RoleStatus.h"
#include "test_battle_RoleAi.h"
#include "test_battle_RoleSkill.h"

namespace space_test_battle 
{
	typedef VOID_T Script_T (CUint*, U32_T);

	typedef std::map<U32_T, Script_T*> ScriptMap_T; 

	typedef std::set<CUint*> UnitList_T;

	#define REGISTER_SCRIPT_F(_id) CManager::RegisterTaskScript(_id, script_##_id)

	class CManager
	{
	public:
		CManager();
		~CManager();

		template<class T> static BOOL_T MakeRole(CUint* p, T* pDummy)
		{
			EUnitRole eRole = T::GetRoleType();
			if ( p->HasRole(eRole) ) 
			{
				return FALSE;
			}
			T::Data* pData = new T::Data;
			if ( !pData )
			{
				return FALSE;
			}
			memset(pData, 0, sizeof(T::Data));
			return p->AddRole(eRole, pData);
		}

		template<class T> static T* GetRole(CUint* p, T* pDummy)
		{
			EUnitRole eRole = T::GetRoleType();
			if ( !p->HasRole(eRole) ) 
			{
				return (T*)NULL;
			}
			return new T(p);
		}

		static BOOL_T RegisterTaskScript(U32_T uId, Script_T* pScript);

		static Script_T* GetTaskScript(U32_T uId);

	public:
		static BOOL_T Create();

		static VOID_T Tick();

		static U32_T GetTickCount() { return s_nTickCnt; }

	protected:
		static ScriptMap_T s_cScriptMap;

		static UnitList_T s_cUnitList;

		static U32_T s_nTickCnt;

	};
}
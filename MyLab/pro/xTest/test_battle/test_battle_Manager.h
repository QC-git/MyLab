#pragma once

#include "test_battle_RoleBase.h"
#include "test_battle_RoleAdvance.h"
#include "test_battle_RoleAi.h"
#include "test_battle_RoleVoid.h"

namespace space_test_battle 
{

	typedef VOID_T Script_T (CUint*, STaskInfo* pInfo, U32_T);

	typedef std::map<U32_T, Script_T*> ScriptMap_T; 

	typedef std::map<U32_T, CUint*> UnitList_T;

	typedef std::set<CUint*>		UnitSet_T;

	#define REGISTER_SCRIPT_F(_id) CManager::RegisterTaskScript(_id, script_##_id)

	class CManager
	{
	public:
		CManager();
		~CManager();

		static CUint* CreateUnit();

		template<class T> 
		static BOOL_T MakeRole(CUint* p)
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
			//memset(pData, 0, sizeof(T::Data));
			return p->AddRole(eRole, pData);
		}

		template<class T> 
		static SP_D(T) GetRole(CUint* p)
		{
			EUnitRole eRole = T::GetRoleType();
			if ( !p->HasRole(eRole) ) 
			{
				return SP_D(T)(NULL);
			}
			return SP_D(T)(new T(p));
		}

		static BOOL_T RegisterTaskScript(U32_T uId, Script_T* pScript);

		static Script_T* GetTaskScript(U32_T uId);

	public:
		static CUint* GetUnit(U32_T uGuid);

		template<class T> 
		static SP_D(T) GetRole(U32_T uGuid)
		{
			CUint* p = GetUnit(uGuid);
			if ( NULL == p )
			{
				return SP_D(T)(NULL);
			}
			return GetRole<T>(p);
		}

		static UnitSet_T getAllUnit(U32_T uIgnoreGuid);


	public:
		static BOOL_T Init();

		static VOID_T OnMessage(VOID_T* pMsgList);

		static VOID_T OnTick();

		static U32_T GetTickCount() { return s_nTickCnt; }

	protected:
		static VOID_T Syn();

	protected:
		static ScriptMap_T s_cScriptMap;

		static UnitList_T s_cUnitList;

		static U32_T s_nTickCnt;

	};
}
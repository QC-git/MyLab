#pragma once

#include "test_battle_RoleCommon.h"

namespace space_test_battle 
{
	typedef VOID_T FUNC_T (CUint*, U32_T);
	typedef std::map<U32_T, FUNC_T*> StatusFuncMap_T; 

	#define REGISTER_TASK_F(_id) CManager::RegisterStatusFunc(_id, task_##_id)

	class CManager
	{
	public:
		CManager();
		~CManager();

		template<class T> BOOL_T MakeRole(CUint* p)
		{
			EUnitRole eRole = T::GetRoleType();
			if ( p->Hasole(eRole) ) 
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

		template<class T> static T* GetRole(CUint* p, T* pEx)
		{
			EUnitRole eRole = T::GetRoleType();
			if ( !p->HasRole(eRole) ) 
			{
				return (T*)NULL;
			}
			return new T(p);
		}

		static BOOL_T RegisterStatusFunc(U32_T uId, FUNC_T* pFunc);

		static FUNC_T* GetStautsFunc(U32_T uId);

	protected:
		static StatusFuncMap_T m_cStatusFuncMap;


	};
}
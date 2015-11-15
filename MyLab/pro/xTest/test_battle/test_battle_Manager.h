#pragma once

#include "test_battle_RoleCreature.h"

namespace space_test_battle 
{
	typedef VOID_T FUNC_T (CUint*, Status*);
	typedef std::map<U32_T, FUNC_T*> StatusFuncMap_T; 

	#define LOAD_STATUS_FUNC_F(_id) CManager::RegisterStatusFunc(_id, status_##_id)

	class CManager
	{
	public:
		CManager();
		~CManager();

		template<class T> BOOL_T MakeRole(CUint* p)
		{
			EUnitRole eRole = T::GetRoleEnum();
			if ( p->HadRole(eRole) ) 
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
			EUnitRole eRole = T::GetRoleEnum();
			if ( !p->HasRole(eRole) ) 
			{
				return (T*)NULL;
			}
			return new T(p);
		}

		BOOL_T static RegisterStatusFunc(U32_T uId, FUNC_T* pFunc);

	protected:
		static StatusFuncMap_T m_cStatusFuncMap;


	};
}
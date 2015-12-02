
#include "x_all.h"
#include "test_battle_script_tool.h"

namespace space_test_battle
{

	VOID_T task_state_dot(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_dot_s& params)
	{
		SP_D(CRoleBase) spRole = CManager::GetRole<CRoleBase>(p);
		SP_D(CRoleAdvance) spRoleEx = CManager::GetRole<CRoleAdvance>(p);
		
		if ( ETaskFlag_ADD == uFlag ) 
		{
			LOG_F("add dot %d", pInfo->uId);
			//SP_D(CRoleBase) spRole = CManager::GetRole<CRoleBase>(1111);
		}

		if ( ETaskFlag_DEC == uFlag )
		{
			LOG_F("del dot %d", pInfo->uId);
		}

		if ( ETaskFlag_Normal == uFlag )
		{
			U32_T uTickCnt = pInfo->uCount;

			if ( uTickCnt > params.uExpireCount ) 
			{
				spRoleEx->RemoveStatus(pInfo->uId);
				return;
			}

			if ( 0 == uTickCnt%params.uInterval )
			{
				spRole->DecHealth(params.uDamage);
			}

		}

	}



	VOID_T task_state_aura(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_area_s& params)
	{
		SP_D(CRoleBase) spRole = CManager::GetRole<CRoleBase>(p);
		SP_D(CRoleAdvance) spRoleEx = CManager::GetRole<CRoleAdvance>(p);

		if ( ETaskFlag_ADD == uFlag ) 
		{
			LOG_F("add aura %d", pInfo->uId);
		}

		if ( ETaskFlag_DEC == uFlag )
		{
			LOG_F("del aura %d", pInfo->uId);
		}

		if ( ETaskFlag_Normal == uFlag )
		{

			
		}
	}

}
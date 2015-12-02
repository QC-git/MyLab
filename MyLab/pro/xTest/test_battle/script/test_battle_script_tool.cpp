
#include "x_all.h"
#include "test_battle_script_tool.h"

namespace space_test_battle
{

	VOID_T task_state_dot(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_dot_s& params)
	{
		CRoleBase* pRole1 = CManager::GetRole(p, (CRoleBase*)NULL);
		CRoleAdvance* pRole = CManager::GetRole(p, (CRoleAdvance*)NULL);
		
		if ( ETaskFlag_ADD == uFlag ) 
		{
			LOG_F("add dot %d", pInfo->uId);
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
				pRole->RemoveStatus(pInfo->uId);
				return;
			}

			if ( 0 == uTickCnt%params.uInterval )
			{
				pRole1->DecHealth(params.uDamage);
			}

		}

	}

	struct state_area_s
	{

	};

	VOID_T task_state_aura(CUint* p, U32_T uFlag)
	{
		;
	}

}
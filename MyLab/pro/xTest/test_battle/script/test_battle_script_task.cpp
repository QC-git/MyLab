
#include "x_all.h"
#include "test_battle_script_task.h"
#include "test_battle_script_tool.h"

namespace space_test_battle
{
	// 技能
	VOID_T script_101(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		SP_D(CRoleAdvance) spRole = CManager::GetRole<CRoleAdvance>(p);

		U32_T nTick = CManager::GetTickCount();

		if ( 0 == nTick%30 )
		{
			CUint* pTarget = spRole->GetTarget();
			SP_D(CRoleBase) spTagretCommon = CManager::GetRole<CRoleBase>(pTarget);
			U32_T uValue = 100;
			spTagretCommon->DecHealth(uValue);
		}

	}

	//////////////////////////////////////////////////////////////////////////

	// 状态
	VOID_T script_1001(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{

		state_param_dot_s params;
		params.uDamage = 500;
		params.uInterval = 30;
		params.uExpireCount = 100;

		task_state_dot(p, pInfo, uFlag, params);

	}

	VOID_T script_1002(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		state_param_area_s param;
		param.uExpireCount = 100;
		param.uMark = 1002;

		task_state_aura(p, pInfo, uFlag, param);
	}

	//////////////////////////////////////////////////////////////////////////

	//2000+ AI

	//////////////////////////////////////////////////////////////////////////

	//yh技能
	VOID_T script_3331(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{


	}

	//yh状态
	VOID_T script_3332(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{


	}


	//////////////////////////////////////////////////////////////////////////

	VOID_T LoadAllScript()
	{
		REGISTER_SCRIPT_F(101);

		REGISTER_SCRIPT_F(1001);
		REGISTER_SCRIPT_F(1002);
	}

}
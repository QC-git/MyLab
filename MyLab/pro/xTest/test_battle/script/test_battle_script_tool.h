#pragma once

#include "../test_battle_Unit.h"
#include "../test_battle_Manager.h"

namespace space_test_battle 
{
	struct state_param_dot_s
	{
		U32_T uDamage;
		U32_T uInterval;
		U32_T uExpireCount;
	};

	VOID_T task_state_dot(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_dot_s& params);


	struct state_param_area_s
	{
		U32_T uExpireCount;
		U32_T uMark;
	};

	VOID_T task_state_aura(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_area_s& params);


}
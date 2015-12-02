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

	VOID_T task_state_aura(CUint* p, U32_T uFlag);


}
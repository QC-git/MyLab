
#include "x_all.h"
#include "test_battle_script_task.h"
#include "test_battle_script_tool.h"

namespace space_test_battle
{
	// 技能
	VOID_T script_101(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		CRoleAdvance* pRole = CManager::GetRole(p, (CRoleAdvance*)NULL);

		U32_T nTick = CManager::GetTickCount();

		if ( 0 == nTick%30 )
		{
			CUint* pTarget = pRole->GetTarget();
			CRoleBase* pTagretCommon = CManager::GetRole(pTarget, (CRoleBase*)NULL);
			U32_T uValue = 100;
			pTagretCommon->DecHealth(uValue);
		}

	}

	//////////////////////////////////////////////////////////////////////////

	// 状态
	VOID_T script_1001(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		CRoleBase* pRole = CManager::GetRole(p, (CRoleBase*)NULL);

		state_param_dot_s params;
		params.uDamage = 500;
		params.uInterval = 30;
		params.uExpireCount = 100;

		task_state_dot(p, pInfo, uFlag, params);

	}

	VOID_T script_1002(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		CRoleBase* pRole = CManager::GetRole(p, (CRoleBase*)NULL);

// 		switch(sTaskInfo.uTickCnt)
// 		{
// 		case 1:
// 			{
// 				U32_T uVal = 100;
// 				pRole->AddMagic(uVal);
// 			}break;
// 		case 10:
// 			{
// 				U32_T uVal = 100;
// 				pRole->DecMagic(uVal);
// 			}break;
// 		}
	}

	//////////////////////////////////////////////////////////////////////////

	//2000+ AI

	//////////////////////////////////////////////////////////////////////////

	//yh技能
	VOID_T script_3331(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		CRoleVoid* pRole = CManager::GetRole(p, (CRoleVoid*)NULL);


	}

	//yh状态
	VOID_T script_3332(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		CRoleVoid* pRole = CManager::GetRole(p, (CRoleVoid*)NULL);


	}


	//////////////////////////////////////////////////////////////////////////

	VOID_T LoadAllScript()
	{
		REGISTER_SCRIPT_F(101);

		REGISTER_SCRIPT_F(1001);
		REGISTER_SCRIPT_F(1002);
	}

}
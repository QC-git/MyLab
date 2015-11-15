
#include "x_all.h"
#include "test_battle_script_task.h"

namespace space_test_battle
{
	VOID_T task_1001(CUint* p)
	{
		CRoleCommon* pRole = CManager::GetRole(p, (CRoleCommon*)NULL);

// 		switch(sTaskInfo.uTickCnt)
// 		{
// 		case 1:
// 			{
// 				U32_T uVal = 100;
// 				pRole->AddHealth(uVal);
// 			}break;
// 		case 10:
// 			{
// 				U32_T uVal = 100;
// 				pRole->DecHealth(uVal);
// 			}break;
// 		}
	}

	VOID_T task_1002(CUint* p)
	{
		CRoleCommon* pRole = CManager::GetRole(p, (CRoleCommon*)NULL);

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


	VOID_T LoadStatusFunc()
	{
		REGISTER_TASK_F(1001);
		REGISTER_TASK_F(1002);
	}

}
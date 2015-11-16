
#include "x_all.h"
#include "test_battle_script_task.h"

namespace space_test_battle
{
	// ¼¼ÄÜ
	VOID_T script_101(CUint* p, U32_T uFlag)
	{
		CRoleSkill* pRole = CManager::GetRole(p, (CRoleSkill*)NULL);

		U32_T nTick = CManager::GetTickCount();

		if ( 0 == nTick%5 )
		{
			CUint* pTarget = pRole->GetTarget();
			CRoleCommon* pTagretCommon = CManager::GetRole(pTarget, (CRoleCommon*)NULL);
			U32_T uValue = 100;
			pTagretCommon->DecHealth(uValue);
		}

	}



	// ×´Ì¬
	VOID_T script_1001(CUint* p, U32_T uFlag)
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

	VOID_T script_1002(CUint* p, U32_T uFlag)
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


	VOID_T LoadAllScript()
	{
		REGISTER_SCRIPT_F(101);

		REGISTER_SCRIPT_F(1001);
		REGISTER_SCRIPT_F(1002);
	}

}
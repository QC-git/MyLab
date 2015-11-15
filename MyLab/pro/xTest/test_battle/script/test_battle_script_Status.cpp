
#include "x_all.h"
#include "test_battle_script_Status.h"

namespace space_test_battle
{
	VOID_T status_1001(CUint* p, Status* pSta)
	{
		CRoleCreature* pRole = CManager::GetRole(p, (CRoleCreature*)NULL);

		switch(pSta->uTickCnt)
		{
		case 1:
			{
				U32_T uVal = 100;
				pRole->AddHealth(uVal);
			}break;
		case 10:
			{
				U32_T uVal = 100;
				pRole->DecHealth(uVal);
			}break;
		}
	}


	VOID_T LoadStatusFunc()
	{
		//CManager::RegisterStatusFunc(1101);
		LOAD_STATUS_FUNC_F(1001);
	}

}
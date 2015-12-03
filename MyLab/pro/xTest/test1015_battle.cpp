
#include "x_all.h"

#include "xTest.h"
#include "test_battle/test_battle_Manager.h"

namespace space_test_battle {


	

}


void test_battle()
{
	space_test_battle::CManager::Init();
	while(true)
	{
		space_test_battle::CManager::OnMessage(NULL);
		space_test_battle::CManager::OnTick();
		X::Sleep_f(100);
	}

	getchar();
}
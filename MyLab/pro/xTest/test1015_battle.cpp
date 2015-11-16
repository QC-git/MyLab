
#include "x_all.h"

#include "xTest.h"
#include "test_battle/test_battle_Manager.h"

namespace space_test_battle {


	

}


void test_battle()
{
	space_test_battle::CManager::Create();
	while(true)
	{
		space_test_battle::CManager::Tick();
		X::Sleep_f(100);
	}

	getchar();
}
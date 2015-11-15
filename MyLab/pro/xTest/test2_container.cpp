
#include "x_all.h"

#include "xTest.h"


namespace space_test_container {

	//==============================º¯ÊıÇø==============================


	//==============================²âÊÔÇø==============================

	void test1()
	{
		VEC_D(int) cNumVec;
		VEC_D(int)::iterator cNumVecIter;

		cNumVec.push_back(1);
		cNumVec.push_back(3);
		cNumVec.push_back(5);
		cNumVec.push_back(7);
		cNumVec.push_back(9);

		FOR_EACH(cNumVec, cNumVecIter)
		{
			LOG_F("%d", *cNumVecIter);
		}

	}


	void test2()
	{
		HASH_D(int, int) cNumHash;
		HASH_D(int, int)::iterator cNumHashIter;

		cNumHash[1] = 11;
		cNumHash[3] = 33;
		cNumHash[5] = 55;
		cNumHash[7] = 77;
		cNumHash[9] = 99;

		FOR_EACH(cNumHash, cNumHashIter)
		{
			LOG_F("%d, %d", cNumHashIter->first, cNumHashIter->second);
		}

	}

	void test3()
	{
		FOR_LOOP(10)
		{
			LOG_F("%d", _n);
		}
	}

}

void test_container()
{
	{
		X::ContainerTest();
	}

	space_test_container::test1();
	space_test_container::test2();
	space_test_container::test3();

	getchar();
}

#include "xTest.h"

#include "x_all.h"

namespace space_test_tool
{

#define VEC_D(_type)		std::vector<_type>
#define SET_D(_type)		std::set<_type>
	//#define LIST_D(_type)		std::list<_type>
#define MAP_D(_key, _type)	std::map<_key, _type>
#define HASH_D(_key, _type)	std::hash_map<_key, _type>

#define FOR_EACH(_container, _iter) for (_iter=_container.begin(); _iter!=_container.end(); _iter++)
#define FOR_LOOP(_loop) for(int _n=0; _n<_loop; _n++)

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

void test_tool()
{
	space_test_tool::test1();
	space_test_tool::test2();
	space_test_tool::test3();

	getchar();
}
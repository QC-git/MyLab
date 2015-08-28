
#include "x_all.h"

#include "xTest.h"

#define VEC_D(_type)		std::vector<_type>
#define SET_D(_type)		std::set<_type>
//#define LIST_D(_type)		std::list<_type>
#define MAP_D(_key, _type)	std::map<_key, _type>
#define HASH_D(_key, _type)	std::hash_map<_key, _type>

#define FOR(_container, _iter) for (_iter=_container.begin(); _iter!=_container.end(); _iter++)

namespace space_test_container {

	void test1()
	{
		VEC_D(int) vecNum;
		VEC_D(int)::iterator vecNumIter;

		vecNum.push_back(1);
		vecNum.push_back(3);
		vecNum.push_back(5);
		vecNum.push_back(7);
		vecNum.push_back(9);
		
		FOR(vecNum, vecNumIter)
		{
			LOG_F("%d", *vecNumIter);
		}

	}


	void test2()
	{
		HASH_D(int, int) hashNum;
		HASH_D(int, int)::iterator hashNumIter;

		hashNum[1] = 11;
		hashNum[3] = 33;
		hashNum[5] = 55;
		hashNum[7] = 77;
		hashNum[9] = 99;
		
		FOR(hashNum, hashNumIter)
		{
			LOG_F("%d, %d", hashNumIter->first, hashNumIter->second);
		}

	}

}

void test_container()
{
	{
		//X::ContainerTest();
	}

	space_test_container::test1();
	space_test_container::test2();

	getchar();
}
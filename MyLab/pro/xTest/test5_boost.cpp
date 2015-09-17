
#include "x_all.h"

#include "xTest.h"

// #define BOOST_TEST_MODULE example
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
// 
#include "boost/test/unit_test.hpp"
//#include "boost/test/minimal.hpp"

extern int test_boost_asio_server_main(int argc, const char* argv[]);

namespace space_test_boost {

	// struct F {
	// 	F() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" ); }
	// 	~F()         { BOOST_TEST_MESSAGE( "teardown fixture" ); }
	// 
	// 	int i;
	// };
	// 
	// BOOST_AUTO_TEST_SUITE(test1);
	// 
	// BOOST_AUTO_TEST_CASE(case1)
	// {
	// 	int* p = new int;
	// 	BOOST_CHECK(p);
	// }
	// BOOST_AUTO_TEST_CASE(case2)
	// {
	// 
	// }
	// BOOST_AUTO_TEST_CASE(case3)
	// {
	// 
	// }
	// 
	// BOOST_AUTO_TEST_SUITE_END();
	// 
	// //--------------
	// 
	// BOOST_AUTO_TEST_SUITE(test222222222);
	// 
	// BOOST_AUTO_TEST_CASE(case1)
	// {
	// 
	// }
	// BOOST_AUTO_TEST_CASE(case2)
	// {
	// 
	// }
	// BOOST_AUTO_TEST_CASE(case3)
	// {
	// 
	// }
	// 
	// BOOST_AUTO_TEST_SUITE_END();

	void test1()
	{
		//boost { namespace unit_test { namespace ut_detail

		//::boost::unit_test::unit_test_main( &boost::unit_test::ut_detail::init_unit_test, 1, "" );

		//boost::unit_test_framework::framework::test1
		//::boost::unit_test::unit_test_main( &init_unit_test, 1, NULL );
	}

	void test2()
	{
		test_boost_asio_server_main(0, NULL);
	}

	void test3()
	{
		;
	}

}

void test_boost()
{
	{
		X::BoostTest();
	}
	
	//space_test_boost::test1();
	//space_test_boost::test2();
	space_test_boost::test3();

	getchar();
}
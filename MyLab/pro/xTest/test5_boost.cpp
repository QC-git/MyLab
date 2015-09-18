
#include "x_all.h"

#include "xTest.h"

// #define BOOST_TEST_MODULE example
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
// 
#include "boost/test/unit_test.hpp"
//#include "boost/test/minimal.hpp"

#include "test_boost/sl_asio/sl_Interface.h"
#include "test_boost/sl_asio/sl_Message.h"

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

	class TcpHost : public sl_asio::IMessagePipe
	{
	public:
		TcpHost() {}
		~TcpHost() {}

// 	public:
// 		static TcpHost& GetInstance();

	public:
		bool InIt()
		{
			printf("\n TcpHost::InIt()");

			m_pTcpHost = sl_asio::NetCreator::CreateTcpHost(*this, "127.0.0.1", 1234);
			m_pTcpHost->AsyncConnect("127.0.0.1", 1234);

			return true;
		}

		void Run()
		{
			printf("\n TcpHost::Run()");

			while(true)
			{
				Sleep(1);
			}
		}

	public:
		virtual void OnConnected(int error_code, unsigned int uSckId)
		{
			printf("\n OnConnected: error_code = %d, uSckId = %d", error_code, uSckId);
		}

		virtual void OnLostConnection(unsigned int uSckId)
		{
			printf("\n OnLostConnection: uSckId = %d", uSckId);
		}

		virtual void OnNewConnection(int error_code, unsigned int sckId)  {}

		virtual void OnProcessMsg(const char* msg, unsigned int sckId) {}

		virtual void OnTick()  {}

	private:
		sl_asio::TcpHostPtr m_pTcpHost;
		std::string m_token;
	};

	void test3()
	{
		TcpHost* p = new TcpHost;
		p->InIt();
		p->Run();
		delete p;
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

#include "x_all.h"

#pragma comment(lib, "xService.lib")
#pragma comment(lib, "xServer.lib")

#include "xTest.h"

namespace space_test_util {
	//==============================其它==============================
	
    //#pragma todo("VS2013")



	//==============================函数区==============================






	//==============================测试区==============================
	void test1()
	{
		LOG_F("test1: ---------------测试: auto---------------");

		int n = 1;
		auto a = n;
		double d1 = n;
		double d2 = a;

		auto a1 = [](int i) { return i; };
		auto a2 = a1(2);
	}

	void test2()
	{
		LOG_F("test1: ---------------测试: OUT_F---------------");

		OUT_F<<"\n";
		OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";

		OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
		OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
		OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
		OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";
		OUT_F<<1+10000<<2<<"hello"<<11.23<<"a";

		// 	100012hello11.230000a100012hello11.230000a100012
		// 		000a100012hello11.230000a100012hello11.230000a

	}

	class C3_1
	{
	public:
		C3_1() { LOG_F("C3_1()"); }
		~C3_1() { LOG_F("~C3_1()"); }
	};

	class C3_2
	{
	public:
		C3_2() { LOG_F("C3_2()"); }
		~C3_2() { LOG_F("~C3_2()"); }
	};

	class C3_3
	{
	public:
		C3_3() { LOG_F("C3_3()"); }
		~C3_3() { LOG_F("~C3_3()"); }
	};

	class C3_4 : public C3_1, public C3_2
	{
	public:
		C3_4() { LOG_F("C3_4()"); }
		~C3_4() { LOG_F("~C3_4()"); }

		C3_3 c3_3;
	};

	void test3()
	{
		LOG_F("test1: ---------------测试: 构造函数，析构函数先后顺序呢---------------");

		C3_4 c3_4;

		// 	[DB-LOG] C3_1()
		// 
		// 	[DB-LOG] C3_2()
		// 
		// 	[DB-LOG] C3_3()
		// 
		// 	[DB-LOG] C3_4()
		// 
		// 	[DB-LOG] ~C3_4()
		// 
		// 	[DB-LOG] ~C3_3()
		// 
		// 	[DB-LOG] ~C3_2()
		// 
		// 	[DB-LOG] ~C3_1()

	}

	//class A;
	//class B: public A {};

	
	class C4
	{
	public:
		C4() {}
		~C4() {}
	};

	void test4()
	{
		C4* p = new C4;

		LOG_F("%d", p);
		LOG_F("%x", p);
		LOG_F("%08x", p);

		delete p;

		U64_T u1 = 101;
		U64_T u2 = 101;
		CHAR_T* s3 = "102 ";
		U64_T u4 = 10001;
		
		//LOG_F("%d 对%d目标(%s)触发伤害%d", u1, u2, s3, u4);
		//LOG_F("%d %d %s %d", u1, u2, s3, u4);
		//LOG_F("%d %d %s", u1, u2, s3);
		LOG_F("\n %lld %lld %s ", u1, u2, s3);

		LOG_F("");
	}

	template<typename T>
	class C5
	{
	public:
		C5(T& data)
			: m_data(data)
		{

		}

		template<typename T1>
		void GetData11(T1 data)
		{
		}

		template<typename T1>
		void GetData12()
		{
		}

		template<typename T1, typename T2>
		void GetData13(T1 data)
		{
		}

		template<typename T1>
		static void GetData21(T1 data)
		{
		}


	private:
		T m_data;
	};

	void test5()
	{
		int a = 1;
		C5<int> c(a);
		c.GetData11(a);
		c.GetData12<int>();
		c.GetData13<int, int>(a);
		c.GetData21(a);
		C5<int>::GetData21(a);

	}


}




void test_util()
{
	{
		X::UtilTest();
	}

	{
		X::DummyTest();
	}


// 	space_test_util::test1();
// 	space_test_util::test2();
// 	space_test_util::test3();
	space_test_util::test4();

	getchar();
}
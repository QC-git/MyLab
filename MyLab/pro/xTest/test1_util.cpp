
#include "x_all.h"
#include "xTestService.hpp"

#pragma comment(lib, "xService.lib")
#pragma comment(lib, "xServer.lib")

#include "xTest.h"

#include "log4cxx/logger.h"
#include "log4cxx/propertyconfigurator.h"

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

	void test6()
	{
		log4cxx::PropertyConfigurator::configure("log4cxx.properties");
		log4cxx::LoggerPtr loggerA(log4cxx::Logger::getLogger("aaa"));  
		log4cxx::LoggerPtr loggerB(log4cxx::Logger::getLogger("bbb")); 
		LOG_F("\n");
		LOG4CXX_INFO(loggerA, "this is log4cxx test"); 
		LOG4CXX_INFO(loggerB, "this is log4cxx test"); 


		log4cxx::LoggerPtr logger0(log4cxx::Logger::getLogger("logger0")); 
		LOG4CXX_DEBUG(logger0, "hello");
		LOG4CXX_TRACE(logger0, "hello");
		LOG4CXX_INFO(logger0, "hello");
		LOG4CXX_WARN(logger0, "hello");
		LOG4CXX_ERROR(logger0, "hello");
		LOG4CXX_FATAL(logger0, "hello");

// 		std::set<int> cList;
// 		LOG4CXX_INFO(logger0, cList);

		//log4j.logger.logger0 = INFO, ap0  

// 		INFO 23:02:03 -- hello
// 		WARN 23:02:04 -- hello
// 		ERROR 23:02:04 -- hello
// 		FATAL 23:02:04 -- hello

		LOG_F("\n");
	}


	class C7_1;

	//template<class T>
	class CRef                                 
	{
		//friend class SmartPtr<T>;     
	public:
		CRef(C7_1 *ptr)
			: p(ptr)
			, count(1) 
		{

		}
		~CRef() 
		{ 
			delete p; 
		}

		int count;                                                     
		C7_1 *p;                                                      
	};

	//template<class T>
	class CAutoPtr                                            
	{
	public:

		CAutoPtr(C7_1 *ptr)
			:rp(new CRef(ptr)) 
		{

		}                                
		CAutoPtr(const CAutoPtr &sp)
			:rp(sp.rp) 
		{ 
			++rp->count; 
		}
		
		CAutoPtr& operator=(const CAutoPtr& rhs) 
		{                           
			++rhs.rp->count;                                                       
			if(--rp->count == 0)                                              
				delete rp;
			rp = rhs.rp;
			return *this;
		}

		~CAutoPtr()
		{                                           
			if(--rp->count == 0)                                 
				delete rp;
		}

	private:
		CRef *rp;                                                
	};

	class CAutoRecycle
	{
	public:
		virtual ~CAutoRecycle() {};

		void Auto()
		{
			s_cSet.insert(this);
		}

		void Recycle()
		{
			std::set<CAutoRecycle*>::iterator cIter;
			FOR_EACH(s_cSet, cIter)
			{
				delete *cIter;
			}
		}

	public:
		static std::set<CAutoRecycle*> s_cSet;
	};

	std::set<CAutoRecycle*> CAutoRecycle::s_cSet;

	class C7_1
	{
	public:
		C7_1() 
		{
			printf("\n C7_1");
		};

		~C7_1() 
		{
			printf("\n ~C7_1");
		};

	};

	class C7_2 : public CAutoRecycle
	{
	public:
		C7_2() 
		{
			printf("\n C7_2");
		};

		~C7_2() 
		{
			printf("\n ~C7_2");
		};



	};

	void test7()
	{
		C7_1* p1 = new C7_1;
		CAutoPtr sp(p1);
		CAutoPtr sp2 = sp;
		CAutoPtr sp3 = sp2;
		//int n = *(sp2.m_pCnt);
		//sp2 = 1;

		C7_2* p2 = new C7_2;
		p2->Auto();

		p2->Recycle();

		printf("");
	}


	class C8
	{
	public:
		C8()
		{
			printf("");
		}

		~C8()
		{
			printf("");
		}

	private:

	};


	void f8_1(int&& a)
	{
		printf("\n 1");
	}

	void f8_1(int& a)
	{
		printf("\n 2");
	}

	void f8_2(int&& a)
	{
		f8_1(a);
	}

	void test8()
	{
		int a = 1;
		f8_1(a);
		f8_1(1);
		f8_1(std::move(1));
		f8_1(std::move(a));
		f8_2(1);
		//	2
		//	1
		//	1
		//	1
		//	2

		std::shared_ptr<C8> p(new C8());
		//p = new C8();
		p = nullptr;
		//~C8()

	}


	class C9
	{
	public:
		C9(int data)
		{
			m_data = data;
		}

		~C9()
		{

		}

// 		void operator=(C9& _Right)
// 		{
// 			m_data = _Right.m_data;
// 		}

		C9& operator=(C9& _Right)  // 支持 = (c1 = c2)
		{
			m_data = _Right.m_data;
			C9* p = new C9(3);
			return *p;
		}

		int m_data;

	private:

	};

	void test9()
	{
		C9 c1(1);
		C9 c2(2);
		C9 c3(0);

		c3 = (c1 = c2);
		

	}

	void test10()
	{
		std::map<int, int> cMap;

		// case 1

// 		cMap.insert(std::pair<int, int>(2, 22));
// 		cMap.insert(std::pair<int, int>(4, 44));
// 		cMap.insert(std::pair<int, int>(6, 66));
//
// 		//cMap.insert(std::pair<int, int>(1, 11));
// 		//cMap.insert(std::pair<int, int>(3, 33));
// 		cMap.insert(std::pair<int, int>(5, 55));
// 		cMap.insert(std::pair<int, int>(7, 77));

		// case 2
		cMap.insert(std::pair<int, int>(3, 33));
		cMap.insert(std::pair<int, int>(2, 22));
		cMap.insert(std::pair<int, int>(1, 11));

		// case 3
// 		cMap.insert(std::pair<int, int>(3, 33));
// 		cMap.insert(std::pair<int, int>(1, 11));
// 		cMap.insert(std::pair<int, int>(2, 22));

		// case 4
// 		cMap.insert(std::pair<int, int>(1, 11));
// 		cMap.insert(std::pair<int, int>(3, 33));
// 		cMap.insert(std::pair<int, int>(2, 22));

		// case 5
// 		cMap.insert(std::pair<int, int>(1, 11));
// 		cMap.insert(std::pair<int, int>(2, 22));
// 		cMap.insert(std::pair<int, int>(3, 33));




		cMap[2] = 22;
		cMap[1] = 11;

	}

	class C11_1
	{
	public:
		C11_1() { c = 3; }
		virtual ~C11_1() 
		{
			printf("");
		}

		int c;

	private:

	};

	class C11_0 : public C11_1
	{
	public:
		C11_0() { b = 2; }
		~C11_0()
		{
			printf("");
		}

		int b;

	private:

	};

	class C11 : public C11_0
	{
	public:
		C11() { a = 1; }
		~C11()
		{
			printf("");
		}

		int a;

	private:

	};


	void test11()
	{
		struct Data
		{
			char a;
			//char b[100];
			char* b;
			char c;
		};

		Data d;
		Data* p = &d;
		memset(&d, 0, sizeof(d));
		d.a = 1;
		d.b = (char*)2;
		d.c = 3;

// 		std::shared_ptr<int> p = std::shared_ptr<int>();
// 		auto r = !p;
// 		int* pp = new int[10];
// 		p.reset(pp);
// 		r = !p;

// 		auto f = []()->bool
// 		{
// 			return true;
// 		};
// 		auto r = f();

// 		C11* p1 = new C11();
// 		C11_0* p2 = p1;
// 		delete p2;
// 		delete p1;
// 
// 		char* p = new char[10];
// 		delete p;
// 		try 
// 		{
// 			throw "asdasd";
// 			int b = 0;
// 			auto a = 1 / b;
// 			delete p;
// 		}
// 		catch (std::exception e)
// 		{
// 
// 		}
		
	}


	void test12()
	{
		CAsync::Test1();
		CAsync::Test2();

		CAsyncPriority::Test();

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
// 	space_test_util::test4();
// 	space_test_util::test6();
//	space_test_util::test7();
//	space_test_util::test8();
//	space_test_util::test9();
//	space_test_util::test10();
//	space_test_util::test11();
	space_test_util::test12();

	getchar();
}
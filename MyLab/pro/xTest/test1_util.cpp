
#include "x_all.h"
//#include<windows.h>

#pragma comment(lib, "xService.lib")
#pragma comment(lib, "xServer.lib")

#include "xTest.h"

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

// namespace hhhh
// {
// 
// #include <stdio.h>
// 	typedef signed char             S8ss_T;
// 	void func()
// 	{
// 		;
// 	}
// #define FUNC hhhh::func
// }

// stl 特化参考
// template <class _Iterator>
// struct iterator_traits {
// 	typedef typename _Iterator::iterator_category iterator_category;
// 	typedef typename _Iterator::value_type        value_type;
// 	typedef typename _Iterator::difference_type   difference_type;
// 	typedef typename _Iterator::pointer           pointer;
// 	typedef typename _Iterator::reference         reference;
// };
// 
// // specialize for _Tp*
// template <class _Tp>
// struct iterator_traits<_Tp*> {
// 	typedef random_access_iterator_tag iterator_category;
// 	typedef _Tp                         value_type;
// 	typedef ptrdiff_t                   difference_type;
// 	typedef _Tp*                        pointer;
// 	typedef _Tp&                        reference;
// };
// 
// // specialize for const _Tp*
// template <class _Tp>
// struct iterator_traits<const _Tp*> {
// 	typedef random_access_iterator_tag iterator_category;
// 	typedef _Tp                         value_type;
// 	typedef ptrdiff_t                   difference_type;
// 	typedef const _Tp*                  pointer;
// 	typedef const _Tp&                  reference;
// };


// template<int a>
// struct A
// {
// 	static int n;
// };



void test_util()
{
	{
		X::UtilTest();
	}

	{
		X::DummyTest();
	}


	test1();
	test2();
	test3();

	while(true)
	{
		X::Sleep_f(1);
	}
}
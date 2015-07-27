

#include "xTest.h"



void test1()
{
	LOG_F("test1: ---------------≤‚ ‘: auto---------------");

	int n = 1;
	auto a = n;
	double d1 = n;
	double d2 = a;

	auto a1 = [](int i) { return i; };
	auto a2 = a1(2);
}

void test2()
{
	LOG_F("test1: ---------------≤‚ ‘: OUT_F---------------");

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
	LOG_F("test1: ---------------≤‚ ‘: ππ‘Ï∫Ø ˝£¨Œˆππ∫Ø ˝œ»∫ÛÀ≥–Úƒÿ---------------");

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
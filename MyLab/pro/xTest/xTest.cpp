// xTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <windows.h>

// #include "x_dummy.h"
// #include "x_util.h"
// #include "x_thread.h"
// #include "x_container.h"
// #include "x_net.h"


#include "xTest.h"


namespace hhhh
{

#include <stdio.h>
	typedef signed char             S8ss_T;
	void func()
	{
		;
	}
#define FUNC hhhh::func
}

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


template <typename T> 
class Singleton
{
protected:
	static T* singleton_;

public:
	Singleton(void)
	{
		assert(!singleton_);
		singleton_ = static_cast< T* >(this);
	}


	~Singleton(void){  assert(singleton_);  singleton_ = 0; }

	static T& getSingleton(void) { assert(singleton_);  return (*singleton_); }
	static T* getSingletonPtr(void){ return singleton_; }

	//template <>	 TYPE * Singleton< TYPE >::singleton_ = 0;
};

#define KBE_SINGLETON_INIT( TYPE )							\
	template <>	 TYPE * Singleton< TYPE >::singleton_ = 0;	\

#define KBE_SINGLETON_INIT_TEST( TYPE )							\
	TYPE * Singleton< TYPE >::singleton_ = 0;	   // 特化与非特化区别 ？ 经测试带不带都可以 ~~, 区别于类或函数特化 ~~


class CHello
{
public:
	CHello() {;}
	~CHello() {;}

public:
	int Value() { return 123; }

};

class CHello2
{
public:
	CHello2() {;}
	~CHello2() {;}

public:
	int Value() { return 123; }

};

template<int a>
struct A
{
	static int n;
};

// A<1> g1;
// A<2> g2;

KBE_SINGLETON_INIT_TEST(CHello)
//KBE_SINGLETON_INIT_TEST(CHello)
//KBE_SINGLETON_INIT(CHello)

// KBE_SINGLETON_INIT(CHello)
// KBE_SINGLETON_INIT(CHello2)

//KBE_SINGLETON_INIT_TEST(CHello)
//KBE_SINGLETON_INIT_TEST(CHello2)



// #define sas  #define AAA 111
// sas
int _tmain(int argc, _TCHAR* argv[])
{
	LOG_F("xTest main()");


	int arg = 1;
	switch(arg)
	{
	case 1:
		{
			test_util();
		}break;
	case 2:
		{
			test_container();
		}break;
	case 3:
		{
			test_thread();
		}break;
	case 4:
		{
			test_net();
		}break;		
	case 5:
		{
			test_boost();
		}break;	
	case 6:
		{
			test_kbe();
		}break;	
	case 11:
		{
			test_db();
		}break;	
	case 12:
		{
			test_math();
		}break;	
	case 13:
		{
			test_design();
		}break;	
		
	}


// 	{
// 		int n = X::Init(NULL);
// 		LOGD_F(" n = %d", n);
// 
// 		X_HSER->Init();
// 		X_HSER->Start();
// 
// 		X_HSER->Stop();
// 		X_HSER->Destroy();
// 	}
	
	
// 	{	
// 
// 		//int nVal = Singleton<CHello>::getSingletonPtr()->Value();
// 
// 		//PRINT_F();
// 	}



// 	{
//	//  [4/26/2015 Administrator]
// 		HINSTANCE hnst=LoadLibrary(_T("xService.dll"));
// 		FreeLibrary(hnst);
// 
// 		HINSTANCE hnst2=LoadLibrary(_T("xService.dll"));
// 		FreeLibrary(hnst);
// 
// 	}
	
	while(true)
	{
		X::Sleep_f(1);
	}
	return 0;
}



#include "x_all.h"

#include "xTest.h"

namespace space_test_design
{



//-----------------test1: 工厂模式-----------------//

class C1_0 
{
public:
	C1_0() {;}
	virtual ~C1_0() {;}

	virtual int Value() { return 0; }
};

class C1_1 : public C1_0
{
public:
	C1_1() {;}
	virtual ~C1_1() {;}

	virtual int Value() { return 1; }
};

class C1_2 : public C1_0
{
public:
	C1_2() {;}
	virtual ~C1_2() {;}

	virtual int Value() { return 2; }

};

class C1_3
{
public:
	C1_3() {;}
	~C1_3() {;}

	static C1_0* Create(int n);

};

C1_0* C1_3::Create(int n)
{
	C1_0* p = NULL;
	switch(n)
	{
	case 1:
		{
			p = new C1_1;
		}break;
	case 2:
		{
			p = new C1_2;
		}break;
	}

	return p;
}

void test1()
{
	LOG_F("test1: 工厂模式");

	C1_0* p = NULL;

	p = C1_3::Create(0);
	if (p) 
	{
		LOG_F("%d", p->Value());
		delete p;
	}
	assert(!p);
	

	p = C1_3::Create(1);
	if (p) 
	{
		LOG_F("%d", p->Value());
		delete p;
	}
	assert(p);

	p = C1_3::Create(2);
	if (p) 
	{
		LOG_F("%d", p->Value());
		delete p;
	}
	assert(p);

// 	[DB-LOG] 1
// 
// 	[DB-LOG] 2

}

//-----------------test2: 策略模式-----------------//

class C2_0
{
public:
	C2_0(C1_0* p) { m_p = p;}
	~C2_0() 
	{ 
		delete m_p;		
	}

	int Data() { return m_p->Value(); };

private:
	C1_0* m_p;
};

void test2()
{
	LOG_F("test2: 策略模式");

	C2_0* p1 = new C2_0(new C1_1);
	C2_0* p2 = new C2_0(new C1_2);

	LOG_F("%d", p1->Data());
	LOG_F("%d", p2->Data());

	delete p1;
	delete p2;

// 	[DB-LOG] 1
// 
// 	[DB-LOG] 2

}

//-----------------test8: 工厂方法模式-----------------//

class C8_0 
{
public:
	C8_0() {;}
	virtual ~C8_0() {;}

	virtual C1_0* Create() { return NULL; }
};

class C8_1 : public C8_0
{
public:
	C8_1() {;}
	virtual ~C8_1() {;}

	virtual C1_0* Create() { return new C1_1; }
};

class C8_2 : public C8_0
{
public:
	C8_2() {;}
	virtual ~C8_2() {;}

	virtual C1_0* Create() { return new C1_2; }

};

void test8()
{
	LOG_F("test8: 工厂方法模式");

	C1_0* p = NULL;
	C8_0* p1 = NULL;

	p1 = new C8_1;
	p = p1->Create();
	if (p) 
	{
		LOG_F("%d", p->Value());
		delete p;
		delete p1;
	}
	assert(p&&p1);

	p1 = new C8_2;
	p = p1->Create();
	if (p) 
	{
		LOG_F("%d", p->Value());
		delete p;
		delete p1;
	}
	assert(p&&p1);

// 	[DB-LOG] 1
// 
// 	[DB-LOG] 2

}


//-----------------test15: 抽象工厂模式-----------------//

class C15_0 
{
public:
	C15_0() {;}
	virtual ~C15_0() {;}

	virtual C1_0* Create() { return NULL; }
	//virtual XXX* Create() {;}  // 只是在工厂模式中增加其它组件的创建方法
};

class C15_1 : public C15_0
{
public:
	C15_1() {;}
	virtual ~C15_1() {;}

	virtual C1_0* Create() { return new C1_1; }
	//virtual XXX* Create() {;}
};

class C15_2 : public C15_0
{
public:
	C15_2() {;}
	virtual ~C15_2() {;}

	virtual C1_0* Create() { return new C1_2; }
	//virtual XXX* Create() {;}

};

void test15()
{
	LOG_F("test15: 抽象工厂模式");

}


//-----------------test21: 单例模式-----------------//
#define DEF21_1(T) #T
#define DEF21_2(T) s_c##T
template <typename T> 
class C21_0
{
protected:
	static T* s_singleton;

public:
	C21_0()
	{
		//LOG_F("Singleton, %s", DEF21_1(T));
		assert(!s_singleton);
		s_singleton = static_cast< T* >(this);
	}


	~C21_0()
	{
		//LOG_F("~Singleton, %s", DEF21_1(T));
		assert(s_singleton);  
		if (s_singleton)
		{
			s_singleton = 0; 
		}
		
	}

	static T& getSingleton(void) { assert(s_singleton);  return (*s_singleton); }
	static T* getSingletonPtr(void){ return s_singleton; }

	//template <>	 TYPE * Singleton< TYPE >::singleton_ = 0;
};

// 特化与非特化区别 ？ 经测试带不带都可以 ~~, 区别于类或函数特化 ~~

#define SINGLETON_GET(C) C21_0<C>::getSingletonPtr();

#define SINGLETON_INIT1(C, name)							\
	template <>	 C* C21_0<C>::s_singleton = 0;	\
	C21_0<C> name;
	

#define SINGLETON_INIT2( type )							\
	C* C21_0<C>::s_singleton = 0;	 

#define SINGLETON_INIT3(C)							\
	template <>	 C* C21_0<C>::s_singleton = 0;	\
	C21_0<C> DEF21_2(C);

class C21_1 : public C21_0<C21_1>
{
public:
	C21_1() {;}
	~C21_1() {;}

public:
	int Value() { return 123; }

};

class C21_2 : public C21_0<C21_2>
{
public:
	C21_2() {;}
	~C21_2() {;}

public:
	int Value() { return 123; }

};

//SINGLETON_INIT1(C21_1, c21_1);  //通过
//SINGLETON_INIT1(C21_2, c21_2);  //通过

SINGLETON_INIT3(C21_1); //通过
SINGLETON_INIT3(C21_2); //通过


//SINGLETON_INIT2(C21_1);  // “s_singleton”: 重定义；多次初始化
//SINGLETON_INIT2(C21_2);  // “s_singleton”: 重定义；多次初始化

void test21()
{
	LOG_F("test21: 单例模式");

	C21_1* p = SINGLETON_GET(C21_1);
	LOG_F("p = %d, %d", p, p->Value());

	p = SINGLETON_GET(C21_1);
	LOG_F("p = %d, %d", p, p->Value());

	C21_2* p2 = SINGLETON_GET(C21_2);
	LOG_F("p2 = %d, %d", p2, p2->Value());

	p2 = SINGLETON_GET(C21_2);
	LOG_F("p2 = %d, %d", p2, p2->Value());

// 	[DB-LOG] p = 2958057, 123
// 
// 	[DB-LOG] p = 2958057, 123
// 
// 	[DB-LOG] p2 = 2958056, 123
// 
// 	[DB-LOG] p2 = 2958056, 123


}

//-----------------test28: 访问者模式-----------------//

class C28_1;
class C28_2;

class C28_Visitor
{
public:
	virtual void Visit1(C28_1* p) = 0;
	virtual void Visit2(C28_2* p) = 0;
};

class C28_Visitor1 : public C28_Visitor
{
public:
	virtual void Visit1(C28_1* p)
	{
		LOG_F("hello C28_1");
	}

	virtual void Visit2(C28_2* p)
	{
		LOG_F("hello C28_2");
	}
};

// class C28_Visitor2 : public C28_Visitor
// {
// public:
// 	void Visit1() = 0;
// 	void Visit2() = 0;
// };

class C28_0
{
public:
	virtual void Hello(C28_Visitor* p) = 0;
};

class C28_1 : public C28_0
{
public:
	virtual void Hello(C28_Visitor* p)
	{
		p->Visit1(this);
	}
};

class C28_2 : public C28_0
{
public:
	virtual void Hello(C28_Visitor* p)
	{
		p->Visit2(this);
	}
};

class C28_3
{
public:
	C28_3()
	{
		m_p1 = new C28_1;
		m_p2 = new C28_2;
	}
	~C28_3() 
	{
		delete m_p1;
		delete m_p2;
	}

	void Hello(C28_Visitor* p)
	{
		m_p1->Hello(p);
		m_p2->Hello(p);
	}
	
private:
	C28_1* m_p1;
	C28_2* m_p2;
	
};

void test28()
{
	LOG_F("test28: 访问者模式");

	C28_3* p = new C28_3;
	C28_Visitor* p_visitor = new C28_Visitor1;

	p->Hello(p_visitor);

	delete p_visitor;
	delete p;

// 	[DB-LOG] hello C28_1
// 
// 	[DB-LOG] hello C28_2

}

}

//-----------------测试-----------------//

void test_design()
{	

	space_test_design::test1();
	space_test_design::test2();
	space_test_design::test8();
	space_test_design::test15();
	space_test_design::test21();
	space_test_design::test28();


	while(true)
	{
		X::Sleep_f(1);
	}
}
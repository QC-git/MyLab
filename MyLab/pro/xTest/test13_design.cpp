
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

//-----------------test6: 装饰模式-----------------//

class C6_0
{
public:
	C6_0() {;}
	virtual ~C6_0() {;}

	virtual void Show() { LOG_F("C6_0"); }

};

class C6_1 : public C6_0
{
public:
	C6_1() {;}
	virtual ~C6_1() {;}

	void Set(C6_0* p) { m_p = p; }

	virtual void Show() { m_p->Show(); }

private:
	C6_0* m_p;

};

class C6_2 : public C6_1
{
public:
	C6_2() {;}
	virtual ~C6_2() {;}

	virtual void Show() { LOG_F("C6_2"); C6_1::Show(); }
};

class C6_3 : public C6_1
{
public:
	C6_3() {;}
	virtual ~C6_3() {;}

	virtual void Show() { LOG_F("C6_3"); C6_1::Show(); }
};


void test6()
{
	LOG_F("test6: 装饰模式");

	C6_0* p = new C6_0;

	C6_2* p1 = new C6_2;
	C6_3* p2 = new C6_3;

	p1->Set(p);
	p2->Set(p1);
	p2->Show();

	delete p;
	delete p1;
	delete p2;

// 	[DB-LOG] C6_3
// 
// 	[DB-LOG] C6_2
// 
// 	[DB-LOG] C6_0


}

//-----------------test7: 代理模式-----------------//

class C7_0
{
public:
	C7_0() {;}
	virtual ~C7_0() {;}

	virtual void Give1() = 0;
	virtual void Give2() = 0;

};

class C7_1 : public C7_0
{
public:
	C7_1(int nId) { m_nId = nId; }
	virtual ~C7_1() {;}

	virtual void Give1()
	{
		LOG_F("C7_1, Give1, %d", m_nId);
	}

	virtual void Give2()
	{
		LOG_F("C7_1, Give2, %d", m_nId);
	}

private:
	int m_nId;

};

class C7_Proxy : public C7_0
{
public:
	C7_Proxy(int nId) { m_p = new C7_1(nId); }
	virtual ~C7_Proxy() { delete m_p;}

	virtual void Give1()
	{
		m_p->Give1();
	}

	virtual void Give2()
	{
		m_p->Give2();
	}

private:
	C7_1* m_p;

};


void test7()
{
	LOG_F("test7: 代理模式");

	C7_Proxy* p = new C7_Proxy(123);
	p->Give1();
	p->Give2();

	delete p;

// 	[DB-LOG] C7_1, Give1, 123
// 
// 	[DB-LOG] C7_1, Give2, 123


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

//-----------------test9: 原型模式-----------------//

//prototype
class C9_Prototype
{
public:
	C9_Prototype(int nData1, int nData2) { m_nData1 = nData1; m_nData2 = nData2; }
	virtual ~C9_Prototype() {;}

	void Show() 
	{ 
		LOG_F("%d, %d", m_nData1, m_nData2);
	}
	void setData1(int nData) { m_nData1 = nData; }

	virtual C9_Prototype* Clone() = 0;

protected:
	int m_nData1;
	int m_nData2;

};

class C9_1 : public C9_Prototype
{
public:
	C9_1(int nData1, int nData2) : C9_Prototype(nData1, nData2) {;}
	virtual ~C9_1() {;}

	virtual C9_Prototype* Clone()
	{
		C9_Prototype* p = new C9_1(m_nData1, m_nData2);
		return p;
	}

};

void test9()
{
	LOG_F("test9: 原型模式");

	C9_1* p1 = new C9_1(1, 2);
	C9_1* p2 = (C9_1*)p1->Clone();
	p2->setData1(11);

	p1->Show();
	p2->Show();

	delete p1;
	delete p2;
	
// 	[DB-LOG] 1, 2
// 
// 	[DB-LOG] 11, 2

}

//-----------------test10: 模板方法模式-----------------//

class C10_0
{
public:
	C10_0() {;}
	virtual ~C10_0() {;}

	void Opt() 
	{
		Opt1();
		Opt2();
	}

protected:
	virtual void Opt1() = 0;
	virtual void Opt2() = 0;

};

class C10_1 : public C10_0
{
public:
	C10_1() {;}
	virtual ~C10_1() {;}

protected:
	void Opt1() 
	{
		LOG_F("C10_1, Opt1");
	}

	void Opt2() 
	{
		LOG_F("C10_1, Opt2");
	}

};

class C10_2 : public C10_0
{
public:
	C10_2() {;}
	virtual ~C10_2() {;}

protected:
	void Opt1() 
	{
		LOG_F("C10_2, Opt1");
	}

	void Opt2() 
	{
		LOG_F("C10_2, Opt2");
	}

};

void test10()
{
	LOG_F("test10: 模板方法模式");

	C10_0* p1 = new C10_1;
	C10_0* p2 = new C10_2;

	p1->Opt();
	p2->Opt();

	delete p1;
	delete p2;

// 	[DB-LOG] C10_1, Opt1
// 
// 	[DB-LOG] C10_1, Opt2
// 
// 	[DB-LOG] C10_2, Opt1
// 
// 	[DB-LOG] C10_2, Opt2

}

//-----------------test12: 外观模式-----------------//

class C12_1 // 与建造者模式相似, 但是流程不固定
{
public:
	C12_1() {;}
	~C12_1() {;}

	void Show()
	{
		LOG_F("C12_1");
	}

};

class C12_2
{
public:
	C12_2() {;}
	~C12_2() {;}

	void Show()
	{
		LOG_F("C12_2");
	}

};

class C12_3
{
public:
	C12_3() {;}
	~C12_3() {;}

	void Show()
	{
		LOG_F("C12_3");
	}

};

class C12_Facade
{
public:
	C12_Facade() 
	{
		m_p1 = new C12_1;
		m_p2 = new C12_2;
		m_p3 = new C12_3;
	}
	~C12_Facade()
	{
		delete m_p1;
		delete m_p2;
		delete m_p3;
	}

	void Show1()
	{
		m_p1->Show();
		m_p2->Show();
	}

	void Show2()
	{
		m_p1->Show();
		m_p3->Show();
	}

private:
	C12_1* m_p1;
	C12_2* m_p2;
	C12_3* m_p3;

};

void test12()
{
	LOG_F("test12: 外观模式");

	C12_Facade* p = new C12_Facade;
	p->Show1();
	p->Show2();
	delete p;

// 	[DB-LOG] C12_1
// 
// 	[DB-LOG] C12_2
// 
// 	[DB-LOG] C12_1
// 
// 	[DB-LOG] C12_3

}

//-----------------test13: 建造者模式-----------------//

class C13_Product  // 与外观模式相似, 但是流程固定
{
public:
	C13_Product() { m_nData = 0; }
	~C13_Product() {;}

	void Add(int nData) { m_nData += nData; }

	void Show() 
	{
		LOG_F("%d", m_nData);
	}

private:
	int m_nData;

};

class C13_0
{
public:
	C13_0() {;}
	virtual ~C13_0() {;}

	virtual void Add1() = 0;
	virtual void Add2() = 0;
	virtual C13_Product* get() = 0;

};

class C13_1 : public C13_0
{
public:
	C13_1() { m_p = new C13_Product; }
	virtual ~C13_1() { delete m_p; }

	virtual void Add1()
	{
		m_p->Add(1);
	};
	virtual void Add2()
	{
		m_p->Add(2);
	}

	virtual C13_Product* get()
	{
		return m_p;
	}

private:
	C13_Product* m_p;

};

class C13_2 : public C13_0
{
public:
	C13_2() { m_p = new C13_Product; }
	virtual ~C13_2() { delete m_p; }

	virtual void Add1()
	{
		m_p->Add(10);
	};
	virtual void Add2()
	{
		m_p->Add(20);
	}

	virtual C13_Product* get()
	{
		return m_p;
	}

private:
	C13_Product* m_p;

};

class C13_Director
{
public:
	C13_Director() {;}
	~C13_Director() {;}

	void Construct(C13_0* p)
	{
		p->Add1();
		p->Add2();
	}

};

void test13()
{
	LOG_F("test13: 建造者模式");

	C13_Director* p = new C13_Director;
	C13_0* p1 = new C13_1;
	C13_0* p2 = new C13_2;
	p->Construct(p1);
	p->Construct(p2);

	p1->get()->Show();
	p2->get()->Show();

	delete p;
	delete p1;
	delete p2;

// 	[DB-LOG] 3
// 
// 	[DB-LOG] 30

}

//-----------------test14: 观察者模式-----------------//

class C14_Observer  //观察者
{
public:
	C14_Observer() {;}
	virtual ~C14_Observer() {;}

	virtual void update() {;}

};

class C14_0  //被观察者或通知者
{
public:
	C14_0() {;}
	virtual ~C14_0() {;}

	void AddObservre(C14_Observer* p1, C14_Observer* p2) { m_p1 = p1; m_p2 = p2; }

	void Notify()
	{
		//应为列表轮询， 这里简化
		if(m_p1)
			m_p1->update();
		if(m_p2)
			m_p2->update();
	}

private:
	C14_Observer* m_p1;  //应为列表， 这里简化
	C14_Observer* m_p2;

};

class C14_1 : public C14_0
{
public:
	C14_1() { m_nState = 0; }
	virtual ~C14_1() {;}

	int m_nState;
};

class C14_ConcreteObserver : public C14_Observer //观察者实现
{
public:
	C14_ConcreteObserver(C14_1* p, int nName) { m_p = p; m_nName = nName; }
	virtual ~C14_ConcreteObserver() {;}

	virtual void update() 
	{
		LOG_F("observer name = %d, observered state = %d", m_nName, m_p->m_nState);
	}

private:
	int m_nName;
	C14_1* m_p;

};

void test14()
{
	LOG_F("test14: 观察者模式");

	C14_1* p = new C14_1;
	C14_ConcreteObserver* m_pObserver1 = new C14_ConcreteObserver(p, 111);
	C14_ConcreteObserver* m_pObserver2 = new C14_ConcreteObserver(p, 222);
	p->AddObservre(m_pObserver1, m_pObserver2);

	p->m_nState = 9;
	p->Notify();

	delete p;
	delete m_pObserver1;
	delete m_pObserver2;

// 	[DB-LOG] observer name = 111, observered state = 9
// 
// 	[DB-LOG] observer name = 222, observered state = 9

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
	space_test_design::test6();
	space_test_design::test7();
	space_test_design::test8();
	space_test_design::test9();
	space_test_design::test10();
	space_test_design::test12();
	space_test_design::test13();
	space_test_design::test14();
	space_test_design::test15();
	space_test_design::test21();
	space_test_design::test28();


	while(true)
	{
		X::Sleep_f(1);
	}
}
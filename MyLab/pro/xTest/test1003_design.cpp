
#include "x_all.h"

#include "xTest.h"

namespace space_test_design
{



//-----------------test1: ����ģʽ-----------------//

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
	LOG_F("test1: ����ģʽ");

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

//-----------------test2: ����ģʽ-----------------//

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
	LOG_F("test2: ����ģʽ");

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

//-----------------test6: װ��ģʽ-----------------//

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
	LOG_F("test6: װ��ģʽ");

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

//-----------------test7: ����ģʽ-----------------//

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
	LOG_F("test7: ����ģʽ");

	C7_Proxy* p = new C7_Proxy(123);
	p->Give1();
	p->Give2();

	delete p;

// 	[DB-LOG] C7_1, Give1, 123
// 
// 	[DB-LOG] C7_1, Give2, 123


}

//-----------------test8: ��������ģʽ-----------------//

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
	LOG_F("test8: ��������ģʽ");

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

//-----------------test9: ԭ��ģʽ-----------------//

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
	LOG_F("test9: ԭ��ģʽ");

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

//-----------------test10: ģ�巽��ģʽ-----------------//

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
	LOG_F("test10: ģ�巽��ģʽ");

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

//-----------------test12: ���ģʽ-----------------//

class C12_1 // �뽨����ģʽ����, �������̲��̶�
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
	LOG_F("test12: ���ģʽ");

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

//-----------------test13: ������ģʽ-----------------//

class C13_Product  // �����ģʽ����, �������̶̹�
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
	LOG_F("test13: ������ģʽ");

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

//-----------------test14: �۲���ģʽ-----------------//

class C14_Observer  //�۲���
{
public:
	C14_Observer() {;}
	virtual ~C14_Observer() {;}

	virtual void update() {;}

};

class C14_0  //���۲��߻�֪ͨ��
{
public:
	C14_0() {;}
	virtual ~C14_0() {;}

	void AddObservre(C14_Observer* p1, C14_Observer* p2) { m_p1 = p1; m_p2 = p2; }

	void Notify()
	{
		//ӦΪ�б���ѯ�� �����
		if(m_p1)
			m_p1->update();
		if(m_p2)
			m_p2->update();
	}

private:
	C14_Observer* m_p1;  //ӦΪ�б��� �����
	C14_Observer* m_p2;

};

class C14_1 : public C14_0
{
public:
	C14_1() { m_nState = 0; }
	virtual ~C14_1() {;}

	int m_nState;
};

class C14_ConcreteObserver : public C14_Observer //�۲���ʵ��
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
	LOG_F("test14: �۲���ģʽ");

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

//-----------------test15: ���󹤳�ģʽ-----------------//

class C15_0 
{
public:
	C15_0() {;}
	virtual ~C15_0() {;}

	virtual C1_0* Create() { return NULL; }
	//virtual XXX* Create() {;}  // ֻ���ڹ���ģʽ��������������Ĵ�������
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
	LOG_F("test15: ���󹤳�ģʽ");

}


//-----------------test16: ״̬ģʽ-----------------//

class C16_Context;

class C16_State
{
public:
	C16_State() {}
	virtual ~C16_State() {}

	virtual void Handle(C16_Context* p) = 0;

};

class C16_Context
{
public:
	C16_Context(C16_State* p) { m_p = p; }
	~C16_Context() { delete m_p; }

	void Request()
	{
		m_p->Handle(this);
	}

	void Set(C16_State* p)
	{
		delete m_p;
		m_p = p;
	}

private:
	C16_State* m_p;

};

class C16_State1 : public C16_State
{
public:
	C16_State1() {}
	virtual ~C16_State1() {}

	virtual void Handle(C16_Context* p);

};

class C16_State2 : public C16_State
{
public:
	C16_State2() {}
	virtual ~C16_State2() {}

	virtual void Handle(C16_Context* p);

};

void C16_State1::Handle(C16_Context* p)
{
	LOG_F("current state is 1");
	p->Set(new C16_State2);
}

void C16_State2::Handle(C16_Context* p)
{
	LOG_F("current state is 2");
	p->Set(new C16_State1);
}


void test16()
{
	LOG_F("test16: ״̬ģʽ");

	C16_Context* p = new C16_Context(new C16_State1);
	p->Request();
	p->Request();
	p->Request();

// 	[DB-LOG] current state is 1
// 
// 	[DB-LOG] current state is 2
// 
// 	[DB-LOG] current state is 1

}


//-----------------test17: ������ģʽ-----------------//

class C17_Target
{
public:
	C17_Target() {}
	virtual ~C17_Target() {}

	virtual void Request()
	{
		LOG_F("��ͨ����");
	}

};

class C17_TargerEx  // ��������
{
public:
	C17_TargerEx() {}
	~C17_TargerEx() {}

	void SpecialRequest()
	{
		LOG_F("��������");
	}

};

class C17_Adapter : public C17_Target
{
public:
	C17_Adapter() { m_p = new C17_TargerEx; }
	virtual ~C17_Adapter() { delete m_p; }

	virtual void Request()
	{
		m_p->SpecialRequest();
	}

private:
	C17_TargerEx* m_p;

};

void test17()
{
	LOG_F("test17: ������ģʽ");

	C17_Target* p = new C17_Adapter;  // ������Ŀ��������䣬 ʹ�����Ϊ��ͨĿ��
	p->Request();
	delete p;

//	[DB-LOG] ��������

}


//-----------------test18: ����¼ģʽ-----------------//

class C18_Memento
{
public:
	C18_Memento(int nState) { m_nState = nState; }
	~C18_Memento() {}

public:
	int m_nState;
};

class C18_0
{
public:
	C18_0() { m_nState = 0; }
	~C18_0() {}

	C18_Memento* CreateMemento()
	{
		return new C18_Memento(m_nState);
	}

	void Recover(C18_Memento* p)
	{
		m_nState = p->m_nState;
	}

public:
	int m_nState;

};

void test18()
{
	LOG_F("test18: ����¼ģʽ");

	C18_0* p = new C18_0;
	LOG_F("%d", p->m_nState);

	C18_Memento* p1 = p->CreateMemento();
	p->m_nState = 1;
	p->Recover(p1);
	LOG_F("%d", p->m_nState);

	delete p;
	delete p1;

// 	[DB-LOG] 0
// 
// 	[DB-LOG] 0

}


//-----------------test19: ���ģʽ-----------------//

void test19()
{
	LOG_F("test19: ���ģʽ");

	// �μ�XML������

}


//-----------------test20: ������ģʽ-----------------//

void test20()
{
	LOG_F("test20: ������ģʽ");

	// �μ�STL������

}


//-----------------test21: ����ģʽ-----------------//

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

// �ػ�����ػ����� �� �����Դ����������� ~~, ������������ػ� ~~

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

//SINGLETON_INIT1(C21_1, c21_1);  //ͨ��
//SINGLETON_INIT1(C21_2, c21_2);  //ͨ��

SINGLETON_INIT3(C21_1); //ͨ��
SINGLETON_INIT3(C21_2); //ͨ��


//SINGLETON_INIT2(C21_1);  // ��s_singleton��: �ض��壻��γ�ʼ��
//SINGLETON_INIT2(C21_2);  // ��s_singleton��: �ض��壻��γ�ʼ��

void test21()
{
	LOG_F("test21: ����ģʽ");

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


//-----------------test22: �Ž�ģʽ-----------------//
// 
// void test22()
// {
// 	LOG_F("test22: �Ž�ģʽ");
// 
// 
// }


//-----------------test23: ����ģʽ-----------------//

class C23_Receiver
{
public:
	C23_Receiver() {}
	~C23_Receiver() {}

	void Action()
	{
		LOG_F("ִ������");
	}
};

class C23_Command
{
public:
	C23_Command(C23_Receiver* p) { m_p = p; }
	virtual ~C23_Command() {}

	virtual void Execute() = 0;

protected:
	C23_Receiver* m_p;

};

class C23_ConcreteCommand : public C23_Command
{
public:
	C23_ConcreteCommand(C23_Receiver* p) : C23_Command(p) {}
	virtual ~C23_ConcreteCommand() {}

	virtual void Execute()
	{
		m_p->Action();
	}

};

class C23_0
{
public:
	C23_0(C23_Command* p) { m_p = p; }
	~C23_0() {}

	virtual void Execute()
	{
		m_p->Execute();
	}

private:
	C23_Command* m_p;
};

void test23()
{
	LOG_F("test23: ����ģʽ");

	C23_Receiver* p1 = new C23_Receiver;
	C23_Command* p2 = new C23_ConcreteCommand(p1);
	C23_0* p = new C23_0(p2);

	p->Execute();

	delete p;
	delete p2;
	delete p1;

//	[DB-LOG] ִ������

}


//-----------------test24: ְ����ģʽ-----------------//

class C24_0
{
public:
	C24_0() { m_p = NULL; }
	virtual ~C24_0() {}

	void SetNextStep(C24_0* p) { m_p = p; }

	void Handle()
	{
		OnHandle();
		if (m_p)
		{
			m_p->Handle();
		}
	}

	virtual void OnHandle() = 0;

private:
	C24_0* m_p;
};

class C24_1 : public C24_0
{
public:
	C24_1() {}
	virtual ~C24_1() {}

	virtual void OnHandle()
	{
		LOG_F("C24_1");
	}

};

class C24_2 : public C24_0
{
public:
	C24_2() {}
	virtual ~C24_2() {}

	virtual void OnHandle()
	{
		LOG_F("C24_2");
	}

};

class C24_3 : public C24_0
{
public:
	C24_3() {}
	virtual ~C24_3() {}

	virtual void OnHandle()
	{
		LOG_F("C24_3");
	}

};

void test24()
{
	LOG_F("test24: ְ����ģʽ");

	C24_1* p1 = new C24_1;
	C24_2* p2 = new C24_2;
	C24_3* p3 = new C24_3;

	p1->SetNextStep(p3);
	p3->SetNextStep(p2);

	p1->Handle();

	delete p1;
	delete p2;
	delete p3;

// 	[DB-LOG] C24_1
// 
// 	[DB-LOG] C24_3
// 
// 	[DB-LOG] C24_2

}


//-----------------test25: �н���ģʽ-----------------//

class C25_0;

class C25_Mediator
{
public:
	C25_Mediator() {}
	virtual ~C25_Mediator() {}

	virtual void Send(int nMsg, C25_0* pSender) = 0;

};

class C25_0
{
public:
	C25_0(C25_Mediator* p) { m_p = p; }
	virtual ~C25_0() {}

	virtual void onRecieve(C25_0* pSender, int nMsg) = 0;

	virtual void send(int nMsg) = 0;

protected:
	C25_Mediator* m_p;

};

class C25_ConcreteMediator : public C25_Mediator  // �����ڷ���
{
public:
	C25_ConcreteMediator() {}
	virtual ~C25_ConcreteMediator() {}

	void Set(C25_0* p1, C25_0* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}

	void Send(int nMsg, C25_0* pSender)
	{
		if ( pSender != m_p1 )
			m_p1->onRecieve(pSender, nMsg);

		if ( pSender != m_p2 )
			m_p2->onRecieve(pSender, nMsg);
	}

private:
	C25_0* m_p1;
	C25_0* m_p2;

};

class C25_1 : public C25_0
{
public:
	C25_1(C25_Mediator* p) : C25_0(p) {}
	virtual ~C25_1() {}

	virtual void onRecieve(C25_0* pSender, int nMsg)
	{
		LOG_F("(%d)�յ�(%d)����Ϣ��%d", this, pSender, nMsg);
	}

	virtual void send(int nMsg)
	{
		LOG_F("(%d)������Ϣ��%d", this, nMsg);
		m_p->Send(nMsg, this);
	}

};

void test25()
{
	LOG_F("test25: �н���ģʽ");

	C25_ConcreteMediator* p = new C25_ConcreteMediator;
	C25_0* p1 = new C25_1(p);
	C25_0* p2 = new C25_1(p);

	p->Set(p1, p2);

	p1->send(1);
	p2->send(2);

	delete p1;
	delete p2;
	delete p;

// 	[DB-LOG] (2001832)������Ϣ��1
// 
// 	[DB-LOG] (2001904)�յ�(2001832)����Ϣ��1
// 
// 	[DB-LOG] (2001904)������Ϣ��2
// 
// 	[DB-LOG] (2001832)�յ�(2001904)����Ϣ��2

}


//-----------------test26: ��Ԫģʽ-----------------//
// 
// void test26()
// {
// 	LOG_F("test26: ��Ԫģʽ");
// 
// 
// }


//-----------------test27: ������ģʽ-----------------//
// 
// void test27()  // ���ƹ���ģʽ
// {
// 	LOG_F("test27: ������ģʽ");
// 
// 
// }

//-----------------test28: ������ģʽ-----------------//

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
	LOG_F("test28: ������ģʽ");

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

//-----------------����-----------------//

void test_design()
{	

	space_test_design::test1();   // ����ģʽ
	space_test_design::test2();   // ����ģʽ
	space_test_design::test6();   // װ��ģʽ
	space_test_design::test7();   // ����ģʽ
	space_test_design::test8();   // ��������ģʽ
	space_test_design::test9();   // ԭ��ģʽ
	space_test_design::test10();  // ģ�巽��ģʽ

	space_test_design::test12();  // ���ģʽ
	space_test_design::test13();  // ������ģʽ
	space_test_design::test14();  // �۲���ģʽ
	space_test_design::test15();  // ���󹤳�ģʽ
	space_test_design::test16();  // ״̬ģʽ
	space_test_design::test17();  // ������ģʽ
	space_test_design::test18();  // ����¼ģʽ
	space_test_design::test19();  // ���ģʽ
	space_test_design::test20();  // ������ģʽ

	space_test_design::test21();  // ����ģʽ
//  space_test_design::test22();  // �Ž�ģʽ
	space_test_design::test23();  // ����ģʽ
	space_test_design::test24();  // ְ����ģʽ
	space_test_design::test25();  // �н���ģʽ
//  space_test_design::test26();  // ��Ԫģʽ
//	space_test_design::test27();  // ������ģʽ
	space_test_design::test28();  // ������ģʽ

	while(true)
	{
		X::Sleep_f(1);
	}

}
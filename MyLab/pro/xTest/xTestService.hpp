#pragma once

#include "x_all.h"

class CAsync
{
public:
	typedef std::function<VOID_T(ERR_T)> CFuncCb_T;

	typedef std::function<VOID_T(CFuncCb_T)> CFuncNode_T;

public:
	CAsync()
	{
		m_bForbid = false;
		m_fnNext = m_fnHead = m_fnTail = [this](ERR_T nErr)
		{
			m_fnNext = NULL;
			if (m_fnEnd)
			{
				m_fnEnd(nErr);
			}
		};
	}
	~CAsync() {}

	VOID_T Use(CFuncNode_T&& fnNode)
	{
		if (m_bForbid)
		{
			return;
		}
		auto fnNext = m_fnHead;
		m_fnNext = m_fnHead = [this, fnNode, fnNext](ERR_T nErr)
		{
			auto fn = fnNext;  //lamba bug, need this method fix
			m_fnNext.swap(fn);
			if (nErr)
			{
				m_fnTail(nErr);
			}
			else
			{
				fnNode(m_fnNext);
			}
		};
	}

	VOID_T End(CFuncCb_T&& fnEnd)
	{
		m_fnEnd = fnEnd;
	}

	VOID_T Next()
	{
		m_bForbid = true;
		if (m_fnNext)
		{
			m_fnNext(0);
		}
	}

public:
	static VOID_T Test1()
	{
		CAsync* p = new CAsync;

		p->Use([](CFuncCb_T fnCb)
		{
			LOG_F("CAsync step 3");
			fnCb(0);
		});

		p->Use([](CFuncCb_T fnCb)
		{
			LOG_F("CAsync step 2");
			fnCb(0);
		});

		p->Use([p](CFuncCb_T fnCb)
		{
			LOG_F("CAsync step 1");
			fnCb(0);
		});

		p->End([p](ERR_T nErr)
		{
			LOG_F("CAsync end, nErr = %d ", nErr);
			delete p;
		});

		p->Next();

	}


	static VOID_T Test2()
	{
		CAsync* p = new CAsync;

		p->Use([](CFuncCb_T fnCb)
		{
			LOG_F("CAsync step 3");
		});

		p->Use([](CFuncCb_T fnCb)
		{
			LOG_F("CAsync step 2");
		});

		p->Use([p](CFuncCb_T fnCb)
		{
			LOG_F("CAsync step 1");
		});

		p->End([p](ERR_T nErr)
		{
			LOG_F("CAsync end, nErr = %d ", nErr);
		});

		p->Next();
		p->Next();
		p->Next();
		p->Next();
		p->Next();

		delete p;

	}


private:
	CFuncCb_T m_fnHead;
	CFuncCb_T m_fnTail;
	CFuncCb_T m_fnNext;
	CFuncCb_T m_fnEnd;
	BOOL_T m_bForbid;

};



class CAsyncPriority
{
public:
	typedef std::function<VOID_T(ERR_T)> CFuncCb_T;

	typedef std::function<VOID_T(CFuncCb_T)> CFuncNode_T;

	typedef std::list<CFuncNode_T> CFuncNodeList_T;

public:
	CAsyncPriority() 
	{
		m_fnEnd = [this](ERR_T nErr)
		{
			if (m_fnUserEnd)
			{
				m_fnUserEnd(nErr);
			}
		};
	}
	~CAsyncPriority() {}

	VOID_T UsePre(CFuncNode_T&& fnNode)
	{
		m_fnList.push_front(fnNode);
	}

	VOID_T UseNext(CFuncNode_T&& fnNode)
	{
		m_fnList.push_back(fnNode);
	}

	VOID_T UseEnd(CFuncCb_T fnEnd)
	{
		m_fnEnd = fnEnd;
	}

	VOID_T operator()()
	{
		Next(m_fnList.begin());
	}

private:

	VOID_T Next(CFuncNodeList_T::iterator cIter)
	{
		if (cIter == m_fnList.end())
		{
			m_fnEnd(0);
		}
		else
		{
			auto fn = *cIter++;
			fn([this, cIter](int nErr)
			{
				if (nErr)
				{
					m_fnEnd(nErr);
				}
				else
				{
					Next(cIter);
				}
			});
		}
		
	}

public:
	static VOID_T Test()
	{
		CAsyncPriority* p = new CAsyncPriority;

		p->UsePre([](CFuncCb_T fnCb)
		{
			LOG_F("CAsyncPriority step 2");
			fnCb(0);
		});

		p->UseNext([](CFuncCb_T fnCb)
		{
			LOG_F("CAsyncPriority step 3");
			fnCb(0);
		});

		p->UsePre([](CFuncCb_T fnCb)
		{
			LOG_F("CAsyncPriority step 1");
			fnCb(0);
		});

		p->UseNext([](CFuncCb_T fnCb)
		{
			LOG_F("CAsyncPriority step 4");
			fnCb(0);
		});

		p->UseEnd([p](ERR_T nErr)
		{
			LOG_F("CAsyncPriority end, nErr = %d ", nErr);
		});

		(*p)();

		delete p;

	}

private:
	CFuncNodeList_T m_fnList;
	CFuncCb_T m_fnEnd;
	CFuncCb_T m_fnUserEnd;

};


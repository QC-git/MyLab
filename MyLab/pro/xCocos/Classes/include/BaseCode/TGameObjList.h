//////////////////////////////////////////////////////////////////////
// XSW, 2009.4.22 统一游戏对象操作和管理
// 说明:
//		1.容器用list，需GetKey()和Release()函数支持
//		2.GetKey()类型可自定义，值不能重复	
//////////////////////////////////////////////////////////////////////

#ifndef	_TGAMEOBJLIST_H_
#define _TGAMEOBJLIST_H_

#include <list>

NAMESPACE_BEGIN(tq)

	//////////////////////////////////////////////////////////////////////////
	//interface IGameObjList
template<class T, class KEY>
class IGameObjList
{
public:
	typedef	std::list<T*>							OBJLIST;	
	typedef	typename  OBJLIST::iterator				Iter;			//std容器迭代器
	typedef	typename  OBJLIST::const_iterator		ConstIter;		//std容器迭代器
public:
	virtual USHORT	Release()							=0;
	virtual Iter	Begin() 							=0;
	virtual Iter	End()								=0;
	
	virtual bool	AddObj(T* pObj)						=0;
	virtual bool	DelObj(const KEY& key)				=0;
	virtual T*		GetObj(const KEY& key)			=0;
	virtual T*		PopObj(const KEY& key)				=0;	// 从OWNER_SET中取出对象，不删除。
	
	virtual int		GetAmount()					const	=0;
	virtual bool	IsExist(const KEY& key)				=0;
};

//////////////////////////////////////////////////////////////////////////
//template TGameObjList
template	< class T, class KEY=INT64>
class TGameObjList : public IGameObjList<T, KEY>
{
public:
	typedef KEY (T::*GETKEY) () const;
	static TGameObjList<T,KEY>*	CreateNew(bool bOwner=true, GETKEY fnGetkey=&T::GetKey)	{ return new TGameObjList<T,KEY>(bOwner,fnGetkey); }

public:
	//////////////////////////////////////////////////////
	//迭代器封装
	class	Iterator
	{
	private: // create by parent class
		Iterator(OBJLIST* pSet) : m_pSet(pSet),m_it(pSet->begin()),m_pObj(0) {}
		friend class TGameObjList<T,KEY>;
	public: // application
		bool	Next()		{ if(m_it==m_pSet->end()) return m_pObj=NULL,false; m_pObj=*m_it;ASSERT(m_pObj); m_it++; return true; }
		void	Reset()									{ m_it=m_pSet->begin(); m_pObj=NULL; }
		operator T*()									{ return m_pObj; }
		T * operator->()								{ ASSERT(m_pObj); return m_pObj; }
		
	protected:
		const OBJLIST*	m_pSet;
		Iter			m_it;
		T*				m_pObj;
	};

	//////////////////////////////////////////////////////
	//迭代器相关接口
public: // traverse
	Iterator	NewEnum		() 							{ return Iterator(&m_setObj); }

	//////////////////////////////////////////////////////
protected:
	TGameObjList(bool bOwner, GETKEY fnGetkey):m_bOwner(bOwner),m_fnGetkey(fnGetkey){ASSERT(m_fnGetkey);}
	virtual ~TGameObjList();

	//////////////////////////////////////////////////////////////////////////
	//interface of IGameObjList
public:
	USHORT	Release()									{ delete this; return 0; }
	Iter	Begin() 									{ return m_setObj.begin(); }
	Iter	End()										{ return m_setObj.end(); }
	
	bool	AddObj(T* pObj);
	bool	DelObj(const KEY& key);
	bool	DelObj(Iterator& iter);
	T*		GetObj(const KEY& key);
	T*		GetObj(const KEY& key)				const;
	T*		PopObj(const KEY& key);
	
	int		GetAmount() 						const	{ return m_setObj.size(); }
	bool	IsExist(const KEY& key)						{ return GetObj(key)!=NULL;}

	//////////////////////////////////////////////////////////////////////////
public:
	void	Clear();
protected:
	T*		PopObj(Iterator& iter);
protected:
	OBJLIST	m_setObj;
	bool	m_bOwner;
	GETKEY	m_fnGetkey;
};

//////////////////////////////////////////////////////////////////////////
//接口实现 TGameObjList

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
TGameObjList<T,KEY>::~TGameObjList()
{
	Clear();
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
void TGameObjList<T,KEY>::Clear()
{
	if(m_bOwner)
	{
		for (Iter it=Begin(); it!=End(); ++it)
		{ 
			T* pObj = *it;
			if(pObj)
			{
				pObj->Release();
				*it = NULL;		// 加强安全性
			}
		}
	}
	m_setObj.clear();
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
bool TGameObjList<T,KEY>::AddObj(T* pObj)
{
	CHECKF_T(pObj);
	ASSERT_T(!DelObj((pObj->*m_fnGetkey)()));

	m_setObj.push_back(pObj);
	return true;
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
bool TGameObjList<T,KEY>::DelObj(Iterator& iter)
{
	if(iter.m_pObj)
	{
		T* pObj = PopObj(iter);
		IF_OK(pObj)
		{
			if(m_bOwner)
				SAFE_RELEASE(pObj);
		}
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
T* TGameObjList<T,KEY>::PopObj(Iterator& iter)
{
	if(iter.m_pObj)
	{
		T* pObj = iter.m_pObj;
		iter.m_pObj	= NULL;

		int	idx = iter.m_idx+1;
		IF_OK_T(idx < m_setObj.size())
		{
			m_setObj.erase(m_setObj.begin() + idx);
			return pObj;
		}
	}
	return NULL;
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
bool TGameObjList<T,KEY>::DelObj(const KEY& key)
{
	const KEY del_key = key;
	for (Iter it=Begin(); it!=End(); ++it)
	{ 
		T* pObj = *it;
		if(pObj && (pObj->*m_fnGetkey)()==del_key)
		{
			IF_OK(pObj)
			{
				if(m_bOwner)
					SAFE_RELEASE(pObj);
			}
			m_setObj.erase(it);
			return true; 
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
T* TGameObjList<T,KEY>::GetObj(const KEY& key)
{
	for (Iter it=Begin(); it!=End(); ++it)
	{ 
		T* pObj = *it;
		if(pObj && (pObj->*m_fnGetkey)()==key)
		{
			return pObj;
		}
	}
	return NULL;
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
T* TGameObjList<T,KEY>::GetObj(const KEY& key) const 
{
	for (ConstIter it=Begin(); it!=End(); ++it)
	{ 
		T* pObj = *it;
		if(pObj && (pObj->*m_fnGetkey)()==key)
		{
			return pObj;
		}
	}
	return NULL;
}

//////////////////////////////////////////////////////////////////////
template< class T, class KEY>
T* TGameObjList<T,KEY>::PopObj(const KEY& key)
{
	ASSERT_T(m_bOwner);

	for (Iter it=Begin(); it!=End(); ++it)
	{ 
		T* pObj = *it;
		if(pObj && (pObj->*m_fnGetkey)()==key)
		{
			m_setObj.erase(it);
			return pObj;
		}
	}
	return NULL;
}

NAMESPACE_END(tq)

#endif // !defined(_TGAMEOBJLIST_H_)

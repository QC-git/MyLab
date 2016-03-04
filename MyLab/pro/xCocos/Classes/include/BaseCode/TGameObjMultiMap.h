//////////////////////////////////////////////////////////////////////
// XSW, 2009.4.22 统一游戏对象操作和管理
//////////////////////////////////////////////////////////////////////
// 说明:
//		1.需GetKey()和Release()函数支持
//		2.GetKey()类型可自定义，值不能重复	

#pragma warning(disable:4786)
#ifndef	_TGAMEOBJMULTIMAP_H_
#define _TGAMEOBJMULTIMAP_H_


NAMESPACE_BEGIN(tq)


//////////////////////////////////////////////////////////////////////////
//interface IGameObjMultiMap
template<class T, class KEY>
class IGameObjMultiMap
{
public:
	enum {DEL_FALSE=0, DEL_TRUE, DEL_CATCH};

public:
	typedef	std::multimap<KEY, T*>					OBJMULTIMAP;	
	typedef	typename  OBJMULTIMAP::iterator			Iter;		//std容器迭代器
	typedef	typename  OBJMULTIMAP::const_iterator	ConstIter;	//std容器迭代器
public:
	virtual USHORT	Release()							=0;
	virtual Iter	Begin() 							=0;
	virtual Iter	End()								=0;

	virtual bool	AddObj(T* pObj)						=0;
	virtual bool	DelObj(const KEY& key)				=0;
	virtual T*		GetObjByIter(Iter i)				=0;

	virtual int		GetAmount()					const	=0;
	virtual int		GetAmount(const KEY& key)	const	=0;
	virtual bool	IsExist(const KEY& key)				=0;
protected:
	virtual ~IGameObjMultiMap() {}
};


template<class T, class KEY=I64 >
class TGameObjMultiMap : public IGameObjMultiMap<T, KEY>
{
public:
	enum {DEL_FALSE=0, DEL_TRUE, DEL_CATCH};

public:
	typedef	std::multimap<KEY, T*>					OBJMULTIMAP;
	typedef	std::pair<KEY, T*>						OBJMULTIPAIR;
	typedef	typename  OBJMULTIMAP::iterator			Iter;		//std容器迭代器
	typedef	typename  OBJMULTIMAP::const_iterator	ConstIter;	//std容器迭代器
public:
	typedef std::pair<Iter, Iter> RangePair;
	typedef KEY (T::*GETKEY)() const;
public:
	static TGameObjMultiMap<T,KEY>*	CreateNew(bool bOwner=true, GETKEY fnGetkey=&T::GetKey)	{ return new TGameObjMultiMap<T,KEY>(bOwner,fnGetkey); }

public:
	//////////////////////////////////////////////////////
	//迭代器封装
	class	Iterator
	{
	private: // create by parent class
		Iterator(OBJMULTIMAP* pSet) : m_pSet(pSet),m_range(pSet->begin(),pSet->end()),m_iter(pSet->begin()),m_pObj(0) {}
		Iterator(OBJMULTIMAP* pSet, const KEY& key) : m_pSet(pSet),m_range(pSet->equal_range(key)),m_iter(m_range.first),m_pObj(0) {}
		friend class TGameObjMultiMap<T,KEY>;

	public: // application
		bool	Next()		{ if(m_iter==m_range.second) return m_pObj=NULL,false; m_pObj=m_iter->second;ASSERT(m_pObj); m_iter++; return true; }
		void	Reset()									{ m_iter=m_range.first; m_pObj=NULL;m_range.first=m_pSet->end();m_range.second=m_pSet->end(); }
		operator T*()									{ return m_pObj; }
		T * operator->()								{ ASSERT(m_pObj); return m_pObj; }

	protected:
		OBJMULTIMAP*	m_pSet;
		RangePair		m_range;
		Iter			m_iter;
		T*				m_pObj;
	};
	//////////////////////////////////////////////////////
	//迭代器相关接口
public: // traverse
	Iterator	NewEnum		() 							{ return Iterator(&m_map); }
	Iterator	NewEnum		(const KEY& key)			{ return Iterator(&m_map, key); }

//////////////////////////////////////////////////////
protected:
	TGameObjMultiMap(bool bOwner, GETKEY fnGetKey):m_bOwner(bOwner),m_fnGetkey(fnGetKey){ASSERT(m_fnGetkey);}
	virtual ~TGameObjMultiMap();

	//////////////////////////////////////////////////////////////////////////
	//interface of IGameObjMultiMap
public:
	USHORT	Release()									{ delete this; return 0; }
	Iter	Begin() 									{ return m_map.begin(); }
	Iter	End()										{ return m_map.end(); }

	bool	AddObj(T* pObj);
	bool	DelObj(const KEY& key);
	bool	DelObj(Iterator& iter);
	T*		GetObjByIter(Iter i)						{ return i->second; }
	void	Clear();

	int		GetAmount() 						const	{ return m_map.size(); }
	int		GetAmount(const KEY& key)			const	{ return m_map.count(key);}
	bool	IsExist(const KEY& key)						{ return GetAmount(key) > 0;}

	//////////////////////////////////////////////////////////////////////////
protected:
	T*		PopObj(Iterator& iter);
protected:
	bool		m_bOwner;
	OBJMULTIMAP	m_map;
	GETKEY		m_fnGetkey;
};

template	< class T, class KEY>
TGameObjMultiMap<T,KEY>::~TGameObjMultiMap()
{
	Clear();
}

template	< class T, class KEY>
void TGameObjMultiMap<T,KEY>::Clear()
{
	if(m_bOwner && m_map.size())
	{
		for(Iter i = Begin(); i != End(); i++)
		{
			GetObjByIter(i)->Release();
			i->second = 0;		// 加强安全性
		}
	}
	m_map.clear();
}

template	< class T, class KEY>
bool TGameObjMultiMap<T,KEY>::AddObj(T* pObj)
{
	CHECKF_T(pObj);

	OBJMULTIPAIR p1((pObj->*m_fnGetkey)(), pObj);
	m_map.insert(p1);
	return true;
}

template	< class T, class KEY>
bool	TGameObjMultiMap<T,KEY>::DelObj(Iterator& iter)
{
	if(iter.m_pObj)
	{
		T* pObj = PopObj(iter);
		IF_OK(pObj)
		{
			if(m_bOwner)
				SAFE_RELEASE(pObj);
			return true;
		}
	}
	return false;
}

template	< class T, class KEY>
T*	TGameObjMultiMap<T,KEY>::PopObj(Iterator& iter)
{
	if(iter.m_pObj)
	{
		T* pObj = iter.m_pObj;
		iter.m_pObj	= NULL;

		IF_OK_T(iter.m_iter != m_map.begin())
		{
			Iter	temp = iter.m_iter;
			temp--;
			m_map.erase(temp);
			return pObj;
		}
	}
	return NULL;
}
	
template	< class T, class KEY>
bool	TGameObjMultiMap<T,KEY>::DelObj(const KEY& key)
{
	bool bRet = false;
	const KEY del_key = key;
	if(m_bOwner)
	{
		Iterator it = NewEnum(del_key);
		while(it.Next())
		{
			try
			{
				it->Release();
			}
			catch(...)
			{ 
				ASSERT_T(!"DelObj(key)"); 
			}
		}
	}
	bRet = m_map.erase(del_key)!=0;

	return bRet;
}

NAMESPACE_END(tq)

#endif // _TGAMEOBJMULTIMAP_H_


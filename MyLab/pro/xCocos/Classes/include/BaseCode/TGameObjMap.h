//////////////////////////////////////////////////////////////////////
// 索引类，用于建立数据表之间的快速查询。加入的KEY不能重复
// 仙剑修，2001.12.18
// XSW, 2009.4.22 统一游戏对象操作和管理
//////////////////////////////////////////////////////////////////////
// 说明:
//		1.需GetKey()和Release()函数支持
//		2.GetKey()类型可自定义，值不能重复	

#pragma warning(disable:4786)
#ifndef	_TGAMEOBJMAP_H_
#define _TGAMEOBJMAP_H_


#include <map>

NAMESPACE_BEGIN(tq)


//////////////////////////////////////////////////////////////////////////
//interface IGameObjMap
template<class T, class KEY >
class IGameObjMap
{
public:
	enum {DEL_FALSE=0, DEL_TRUE, DEL_CATCH};

public:
	typedef	std::map<KEY, T*>					OBJMAP;	
	typedef	typename OBJMAP::iterator			Iter;		//std容器迭代器
	typedef	typename OBJMAP::const_iterator		ConstIter;	//std容器迭代器
public:
	virtual USHORT	Release()							=0;
	virtual Iter	Begin() 							=0;
	virtual Iter	End()								=0;

	virtual bool	AddObj(T* pObj)						=0;
	virtual int		DelObj(const KEY& key)				=0;
	virtual T*		GetObjByIter(Iter i)		const	=0;
	virtual T*		GetObj(const KEY& key)				=0;
	virtual T*		GetObj(const KEY& key)		const	=0;
	virtual T*		PopObj(const KEY& key)				=0;	// 从OWNER_SET中取出对象，不删除。

	virtual int		GetAmount()					const	=0;
	virtual bool	IsExist(const KEY& key)				=0;
protected:
	virtual ~IGameObjMap() {}
};


template<class T, class KEY=int64_t >
class TGameObjMap : public IGameObjMap<T, KEY>
{
public:
    typedef typename IGameObjMap<T, KEY>::OBJMAP OBJMAP;
    typedef typename IGameObjMap<T, KEY>::Iter Iter;
    typedef typename IGameObjMap<T, KEY>::ConstIter ConstIter;
public:
	typedef KEY (T::*GETKEY)() const;
	static TGameObjMap<T,KEY>*	CreateNew(bool bOwner=true, GETKEY fnGetKey=&T::GetKey)	{ return new TGameObjMap<T,KEY>(bOwner,fnGetKey); }

public:
	//////////////////////////////////////////////////////
	//迭代器封装
	class	Iterator
	{
	private: // create by parent class
		Iterator(OBJMAP* pSet) : m_pSet(pSet),m_iter(pSet->begin()),m_pObj(0) {}
		friend class TGameObjMap<T,KEY>;

	public: // application
		bool	Next()		{ if(m_iter==m_pSet->end()) return m_pObj=NULL,false; m_pObj=m_iter->second;ASSERT(m_pObj); ++m_iter; return true; }
		void	Reset()									{ m_iter=m_pSet->begin(); m_pObj=NULL; }
		operator T*()									{ return m_pObj; }
		T * operator->()								{ ASSERT(m_pObj); return m_pObj; }

	protected:
		OBJMAP*	m_pSet;
		Iter	m_iter;
		T*		m_pObj;
	};
	//////////////////////////////////////////////////////
	//迭代器相关接口
public: // traverse
	Iterator	NewEnum		() 							{ return Iterator(&m_map); }

//////////////////////////////////////////////////////
protected:
	TGameObjMap(bool bOwner, GETKEY fnGetkey):m_bOwner(bOwner),m_fnGetkey(fnGetkey){ASSERT(m_fnGetkey);}
	virtual ~TGameObjMap();

	//////////////////////////////////////////////////////////////////////////
	//interface of IGameObjMap
public:
	USHORT	Release()									{ delete this; return 0; }
	Iter	Begin() 									{ return m_map.begin(); }
	Iter	End()										{ return m_map.end(); }

	bool	AddObj(T* pObj);
	int		DelObj(const KEY& key);
	int		DelObj(Iterator& iter);
	T*		GetObjByIter(Iter i)				const	{ return i->second; }
	T*		GetObj(const KEY& key);
	T*		GetObj(const KEY& key)				const;
	T*		PopObj(const KEY& key);
	void	Clear();

	int		GetAmount() 						const	{ return m_map.size(); }
	bool	IsExist(const KEY& key)						{ return GetObj(key)!=NULL;}

	//////////////////////////////////////////////////////////////////////////
protected:
	T*		PopObj(Iterator& iter);
protected:
	bool	m_bOwner;
	OBJMAP	m_map;
	GETKEY	m_fnGetkey;
};

template	< class T, class KEY >
TGameObjMap<T,KEY>::~TGameObjMap()
{
	Clear();
}

template	< class T, class KEY >
void TGameObjMap<T,KEY>::Clear()
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

template	< class T, class KEY >
bool TGameObjMap<T,KEY>::AddObj(T* pObj)
{
	IF_NOT(pObj)
	{
		return false;
	}

	if(m_bOwner)
	{
//		ASSERT_T(!DelObj((pObj->*m_fnGetkey)()));
	}
	m_map[(pObj->*m_fnGetkey)()] = pObj;
	return true;
}

template	< class T, class KEY >
int	TGameObjMap<T,KEY>::DelObj(Iterator& iter)
{
    int iRet=IGameObjMap<T, KEY>::DEL_FALSE;
	if(iter.m_pObj)
	{
		T* pObj = PopObj(iter);
		if(pObj)
			iRet=IGameObjMap<T, KEY>::DEL_TRUE;

		try
		{
			if(m_bOwner && pObj)
				pObj->Release();
		}
		catch(...)
		{ 
			ASSERT_T(!"DelObj(Iterator& iter)"); 
			iRet=IGameObjMap<T, KEY>::DEL_CATCH;
		}
		return iRet;//pObj != NULL;
	}
	return iRet;
}

template	< class T, class KEY >
T*	TGameObjMap<T,KEY>::PopObj(Iterator& iter)
{
	if(iter.m_pObj)
	{
		T* pObj = iter.m_pObj;
		iter.m_pObj	= NULL;

		IF_OK_T(iter.m_iter != m_map.begin())
		{
// #ifdef	USE_HASH_MAP
// 			m_map.erase(GetKey(pObj));
// #else // USE_HASH_MAP
			Iter	temp = iter.m_iter;
			temp--;
			m_map.erase(temp);
//#endif // USE_HASH_MAP
			return pObj;
		}
	}
	return NULL;
}
template	< class T, class KEY >
T*	TGameObjMap<T,KEY>::PopObj(const KEY& key)
{
	Iter i;
	if((i=m_map.find(key)) != m_map.end())
	{
		T* p = i->second;
		m_map.erase(key);
		return p;
	}
	return NULL;
}
	
template	< class T, class KEY >
int	TGameObjMap<T,KEY>::DelObj(const KEY& key)
{
	if(m_bOwner)
	{
		int iRet=IGameObjMap<T, KEY>::DEL_FALSE;
		Iter i = m_map.find(key);
		if(i != m_map.end())
		{
			iRet=IGameObjMap<T, KEY>::DEL_TRUE;
			try
			{
				GetObjByIter(i)->Release();
			}
			catch(...)
			{ 
				ASSERT_T(!"DelObj(key)"); 
				iRet=IGameObjMap<T, KEY>::DEL_CATCH;
			}
			m_map.erase(i);
			return iRet;
		}
		return iRet;
	}
	else
		return m_map.erase(key) != 0;
}

template	< class T, class KEY >
T* TGameObjMap<T,KEY>::GetObj(const KEY& key)
{
	Iter i;
	if((i=m_map.find(key)) != m_map.end())
		return i->second;
	
	return NULL;
}

template	< class T, class KEY >
T* TGameObjMap<T,KEY>::GetObj(const KEY& key) const
{
	ConstIter i;
	if((i=m_map.find(key)) != m_map.end())
		return i->second;
	
	return NULL;
}

NAMESPACE_END(tq)

#endif // _TGAMEOBJMAP_H_


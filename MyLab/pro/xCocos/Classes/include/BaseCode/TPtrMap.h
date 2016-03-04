//////////////////////////////////////////////////////////////////////
// 仙剑修，2001.12.18
// XSW, 2009.4.22 统一游戏对象操作和管理
//说明：
//		1.索引类，用于管理非游戏对象的管理
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)
#ifndef	_TQ_TPTRMAP_H_
#define _TQ_TPTRMAP_H_


#include <map>

NAMESPACE_BEGIN(tq)



template<class T, class KEY=int64_t >
class TPtrMap
{
public:
	typedef	typename std::map<KEY, T*>			OBJMAP;	
	typedef	typename OBJMAP::iterator			Iter;		//std容器迭代器
	typedef	typename OBJMAP::const_iterator		ConstIter;	//std容器迭代器

public:
	static TPtrMap<T,KEY>*	CreateNew(bool bOwner=true)	{ return new TPtrMap<T,KEY>(bOwner); }

public:
	//////////////////////////////////////////////////////
	//迭代器封装
	class	Iterator
	{
	private: // create by parent class
		Iterator(OBJMAP* pSet) : m_pSet(pSet),m_iter(pSet->begin()),m_pObj(0) {}
		friend class TPtrMap<T,KEY>;

	public: // application
		bool	Next()		{ if(m_iter==m_pSet->end()) return m_pObj=NULL,false;m_key=m_iter->first;m_pObj=m_iter->second;ASSERT(m_pObj); m_iter++; return true; }
		void	Reset()									{ m_iter=m_pSet->begin(); m_pObj=NULL; }
		operator T*()									{ return m_pObj; }
		T * operator->()								{ ASSERT(m_pObj); return m_pObj; }
		KEY		GetKey() const							{ IF_OK(m_pObj) return m_key; return (int)0; }//std::string(NULL)会崩溃

	protected:
		OBJMAP*	m_pSet;
		Iter	m_iter;
		T*		m_pObj;
		KEY		m_key;
	};
	//////////////////////////////////////////////////////
	//迭代器相关接口
public: // traverse
	Iterator	NewEnum		() 							{ return Iterator(&m_map); }

//////////////////////////////////////////////////////
protected:
	TPtrMap(bool bOwner):m_bOwner(bOwner){}
	virtual ~TPtrMap();

	//////////////////////////////////////////////////////////////////////////
	//interface of IGameObjMap
public:
	USHORT	Release()									{ delete this; return 0; }
	Iter	Begin() 									{ return m_map.begin(); }
	Iter	End()										{ return m_map.end(); }

	bool	AddObj(const KEY& key, T* pObj);
	bool	DelObj(const KEY& key);
	bool	DelObj(Iterator& iter);
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
};

template	< class T, class KEY >
TPtrMap<T,KEY>::~TPtrMap()
{
	Clear();
}

template	< class T, class KEY >
void TPtrMap<T,KEY>::Clear()
{
	if(m_bOwner && m_map.size())
	{
		for(Iter i = Begin(); i != End(); i++)
		{
			SAFE_DELETE(i->second);
		}
	}
	m_map.clear();
}

template	< class T, class KEY >
bool TPtrMap<T,KEY>::AddObj(const KEY& key, T* pObj)
{
	CHECKF_T(pObj);

	if(m_bOwner)
	{
		ASSERT_T(!DelObj(key));
	}
	m_map[key] = pObj;
	return true;
}

template	< class T, class KEY >
bool	TPtrMap<T,KEY>::DelObj(Iterator& iter)
{
	bool bRet = false;
	if(iter.m_pObj)
	{
		T* pObj = PopObj(iter);
		IF_OK(pObj)
		{
			if(m_bOwner)
				SAFE_DELETE(pObj);
			return true;
		}
	}
	return bRet;
}

template	< class T, class KEY >
T*	TPtrMap<T,KEY>::PopObj(Iterator& iter)
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
T*	TPtrMap<T,KEY>::PopObj(const KEY& key)
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
bool	TPtrMap<T,KEY>::DelObj(const KEY& key)
{
	bool bRet = false;
	if(m_bOwner)
	{
		Iter i = m_map.find(key);
		if(i != m_map.end())
		{
			bRet = true;
			SAFE_DELETE(i->second);
			m_map.erase(i);
		}
		return bRet;
	}
	else
		return m_map.erase(key) != 0;
}

template	< class T, class KEY >
T* TPtrMap<T,KEY>::GetObj(const KEY& key)
{
	Iter i;
	if((i=m_map.find(key)) != m_map.end())
		return i->second;
	
	return NULL;
}

template	< class T, class KEY >
T* TPtrMap<T,KEY>::GetObj(const KEY& key) const
{
	ConstIter i;
	if((i=m_map.find(key)) != m_map.end())
		return i->second;
	
	return NULL;
}

NAMESPACE_END(tq)

#endif // _TQ_TPTRMAP_H_


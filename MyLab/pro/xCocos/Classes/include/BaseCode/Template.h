// **********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Cheng hongzhang
// Created:	2006/04/03
//
// **********************************************************************

#ifndef _TQ_TEMPLATE_H_
#define _TQ_TEMPLATE_H_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <map>
#include "Types.h"
#include "BaseMacro.h"
#include "Macro.h"
NAMESPACE_BEGIN(tq)
	//////////////////////////////////////////////////////////////////////
	// 自动指针模板
	//////////////////////////////////////////////////////////////////////
	template <class T> struct policy_delete
	{
		void destroy(T*& p) { SAFE_DELETE (p); }
	};

	template <class T> struct policy_release
	{
		void destroy(T*& p) { SAFE_RELEASE (p); }
	};


	template < class T, class DestroyPolicy = policy_delete<T> >
	class TAutoPtr : DestroyPolicy
	{
	public:
		typedef T element_type;
		explicit TAutoPtr(T* P = 0)
			: m_bOwns(P != 0), m_ptr(P) {}

		TAutoPtr(const TAutoPtr<T, DestroyPolicy>& Y)
			: m_bOwns(Y.m_bOwns), m_ptr(Y.release()) {}

		TAutoPtr<T, DestroyPolicy>& operator=(const TAutoPtr<T, DestroyPolicy>& Y)
		{
			if (this != &Y)
			{
				if (m_ptr != Y.get())
				{
					if (m_bOwns)
						this->destroy(m_ptr);

					m_bOwns = Y.m_bOwns; 
				}
				else if (Y.m_bOwns)
					m_bOwns = true;

				m_ptr = Y.release(); 
			}

			return (*this); 
		}

		TAutoPtr<T, DestroyPolicy>& operator=(T* P)
		{
			if (P != m_ptr)
			{
				if (m_bOwns)
					this->destroy(m_ptr);

				m_bOwns = true;
				m_ptr	= P;
			}

			return (*this); 
		}

		~TAutoPtr()	{ if (m_bOwns) this->destroy(m_ptr); }

		T& operator*() const	{ return (*get()); }
		T* operator->() const	{ return (get()); }
		operator T*() const		{ return (m_ptr); }
		T* get() const			{ return (m_ptr); }
		T* release() const		{ ((TAutoPtr<T, DestroyPolicy> *)this)->m_bOwns = false; return (m_ptr); }
		
	private:
		bool	m_bOwns;
		T*		m_ptr;
	};


	//////////////////////////////////////////////////////////////////////
	// 智能指针模板 : 在TSmartPtr.h中定义
	//////////////////////////////////////////////////////////////////////
	//typedef std::map<void*, unsigned long> MAP_POINTER;

	//template <class T> 
	//class TSmartPtr 
	//{
	//public:
	//	TSmartPtr(T* p_=0) 
	//		: p(p_) { this->AddRef(p); }

	//	TSmartPtr(const TSmartPtr<T>& p_)  
	//		: p((T*)p_)	{ this->AddRef(p); }

	//	~TSmartPtr(void) 
	//		{ this->Release(p); }

	//	bool operator ==(T* p_) const { return (p == p_); }
	//	bool operator ==(TSmartPtr<T>& p_) const { return (p == (T*)p_); }

	//	bool operator !=(T* p_) const { return (p != p_); }
	//	bool operator !=(TSmartPtr<T>& p_) const { return (p != (T*)p_); }
	//	
	//	operator T*(void) const
	//		{ return p; }

	//	T& operator *(void)	const
	//		{ return *p; }
	//	T* operator ->(void) const
	//		{ return p; }

	//	TSmartPtr& operator =(TSmartPtr<T>& p_)
	//		{ return operator =((T *) p_); }
	//	TSmartPtr& operator =(T* p_) 
	//		{ if (p != p_) { if (p) Release(p); p = p_; if (p) AddRef(p); } return *this; }

	//private:
	//	T* p;

	//private:
	//	static void	AddRef(void* p_)
	//	{
	//		if (!p_) 
	//			return;
	//		
	//		MAP_POINTER::iterator iter = s_setPointer.find(p_);
	//		if (iter == s_setPointer.end())
	//			s_setPointer[p_] = 1;
	//		else
	//			s_setPointer[p_] = (*iter).second+1;
	//	}

	//	static void	Release(void* p_)
	//	{
	//		if (!p_)
	//			return;

	//		MAP_POINTER::iterator iter = s_setPointer.find(p_);
	//		IF_NOT (iter != s_setPointer.end())
	//		{
	//			unsigned long ref = (*iter).second;
	//			IF_OK (ref >= 1)
	//			{
	//				ref--;
	//				s_setPointer[p_] = ref;

	//				if (ref <= 0)
	//				{
	//					s_setPointer.erase(iter);
	//					SAFE_DELETE (p_);
	//				}				
	//			}
	//		}
	//	}

	//	static MAP_POINTER	s_setPointer;
	//};

	//template <class T>
	//MAP_POINTER	TSmartPtr<T>::s_setPointer;


	//////////////////////////////////////////////////////////////////////
	struct DESTROY_DELETE {};
	struct DESTROY_RELEASE {};
	struct OWNER_TRUE {};
	struct OWNER_FALSE {};


	//////////////////////////////////////////////////////////////////////
	// 单类型对象集, KEY 为 OBJID 类型
	//////////////////////////////////////////////////////////////////////
// 	template<class T, class X = DESTROY_DELETE, class Y = OWNER_TRUE>
// 	class TSingleMap
// 	{
// 	private:
// 		typedef std::map< OBJID, T* >		OBJ_SET;
// 		typedef	typename OBJ_SET::iterator	OBJ_ITER;
// 
// 	public:	// new traversal
// 		class	Iterator
// 		{
// 		public: // create by parent class
// 			Iterator(OBJ_SET* pSet) : m_pSet(pSet),m_iter(pSet->begin()),m_pObj(0) {}
// 			friend class TSingleMap<T>;
// 			
// 		public: // application
// 			bool	Next()					
// 			{ 
// 				if(m_iter==m_pSet->end())
// 				{
// 					m_pObj=NULL;
// 					return false;
// 				}
// 				else
// 				{
// 					m_pObj=m_iter->second;
// 					ASSERT(m_pObj);
// 					m_iter++; 
// 					return true; 
// 				}
// 			}
// 			void	Reset()					{ m_iter=m_pSet->begin(); m_pObj=NULL; }
// 			operator T*()					{ return m_pObj; }
// 			T * operator->()				{ return m_pObj; }
// 			
// 		protected:
// 			OBJ_SET*	m_pSet;
// 			OBJ_ITER	m_iter;
// 			T*			m_pObj;
// 		};
// 	public: // traverse
// 		Iterator	NewEnum		() 			{ return Iterator(&m_setObj); }
// 		int			Size		() const	{ return m_setObj.size(); }
// 
// 	public:
// 		TSingleMap() {}
// 		virtual ~TSingleMap() { this->DelAll(); }
// 
// 		DWORD	GetAmount(void) const { return m_setObj.size(); }
// 		
// 		T*		GetObj(OBJID idObj) const { 
// 			OBJ_SET::const_iterator iter = m_setObj.find(idObj);
// 			return iter == m_setObj.end() ? NULL : (*iter).second;
// 		}
// 
// 		void	AddObj(OBJID id, T* pObj)	{ if (pObj) m_setObj[id] = pObj; }
// 
// 		void	DelObj(OBJID idObj)	{ this->DelObj(idObj, Y()); }
// 		void	DelObj(Iterator& iter)	{ this->DelObj(iter, Y()); }
// 		void	DelAll(void)	{ this->DelAll(Y()); }
// 		
// 		void	RemoveObj(OBJID idObj)	{ m_setObj.erase(idObj); }
// 		void	RemoveAll(void)	{ m_setObj.clear(); }
// 
// 	private:
// 		void	Destroy(T* p, DESTROY_DELETE)		{ SAFE_DELETE (p); }
// 		void	Destroy(T* p, DESTROY_RELEASE)		{ SAFE_RELEASE (p); }
// 		void	Destroy(T* p) { this->Destroy(p, X()); }
// 
// 		void	DelObj(OBJID idObj, OWNER_TRUE)	
// 		{ 
// 			OBJ_SET::iterator iter = m_setObj.find(idObj);
// 			if (iter == m_setObj.end())
// 				return;
// 			
// 			this->Destroy((*iter).second);
// 			m_setObj.erase(iter);
// 		}
// 
// 		void	DelObj(OBJID idObj, OWNER_FALSE)	
// 		{ 
// 			m_setObj.erase(idObj);
// 		}
// 		bool	DelObj(Iterator& iter, OWNER_TRUE)
// 		{
// 			if(iter.m_pObj)
// 			{
// 				this->Destroy(iter.m_pObj);
// 				iter.m_pObj	= NULL;
// 				IF_OK(iter.m_iter != m_setObj.begin())
// 				{
// 					OBJ_ITER temp = iter.m_iter;
// 					temp--;
// 					m_setObj.erase(temp);
// 					return true;
// 				}
// 			}
// 			return false;
// 		}
// 		bool	DelObj(Iterator& iter, OWNER_FALSE)
// 		{
// 			if(iter.m_pObj)
// 			{
// 				iter.m_pObj	= NULL;
// 				IF_OK(iter.m_iter != m_setObj.begin())
// 				{
// 					OBJ_ITER temp = iter.m_iter;
// 					temp--;
// 					m_setObj.erase(temp);
// 					return true;
// 				}
// 			}
// 			return false;
// 		}
// 		void	DelAll(OWNER_TRUE)	
// 		{
// 			OBJ_SET::iterator iter = m_setObj.begin();
// 			for (; iter != m_setObj.end(); ++iter)
// 			{
// 				this->Destroy((*iter).second);
// 			}
// 			
// 			m_setObj.clear();
// 		}
// 
// 		void	DelAll(OWNER_FALSE)	
// 		{
// 			m_setObj.clear();
// 		}
// 
// 	private:
// 		OBJ_SET m_setObj;
// 	};
// 	
	//////////////////////////////////////////////////////////////////////
	// 多类型对象集, 管理对象必须实现GetID(), GetObjType()
	//////////////////////////////////////////////////////////////////////
// 	template<class T, class X = DESTROY_DELETE>
// 	class TMultiMap
// 	{
// 	public:
// 		TMultiMap(bool bOwner = true) : m_bOwner(bOwner) {}
// 		virtual ~TMultiMap() { this->DelAll(); }
// 		
// 	public:	
// 		void	BeginEnum(void)	{ m_iter = m_setObj.begin(); }
// 		T*		EnumObj(void)	{ 
// 			if (m_iter == m_setObj.end())
// 				return NULL;
// 			
// 			T* p = (*m_iter).second; 
// 			++m_iter; 
// 			return p; 
// 		}
// 		
// 		int		GetAmount(void) const	{ return m_setObj.size(); }
// 		
// 		T*		GetObj	(OBJID idObj, int nType) const
// 		{
// 			OBJ_SET::const_iterator iter = m_setObj.find(OBJ_INFO(idObj, nType));
// 			if (iter == m_setObj.end())
// 				return NULL;
// 			
// 			return (*iter).second;
// 		}
// 		
// 		void	AddObj(T* pObj)
// 		{	
// 			IF_NOT (pObj)
// 				return;
// 
// 			m_setObj[OBJ_INFO(pObj->GetID(), pObj->GetObjType())] = pObj;
// 		}
// 
// 		void	DelObj(OBJID idObj, int nType)
// 		{
// 			if (!m_bOwner)
// 			{
// 				m_setObj.erase(OBJ_INFO(idObj, nType));
// 				return;
// 			}
// 
// 			OBJ_SET::iterator iter = m_setObj.find(OBJ_INFO(idObj, nType));
// 			if (iter == m_setObj.end())
// 				return;
// 
// 			this->Destroy((*iter).second);
// 			m_setObj.erase(iter);
// 		}
// 
// 		void	DelAll(void)
// 		{
// 			if (m_bOwner)
// 			{
// 				OBJ_SET::iterator iter = m_setObj.begin();
// 				for (; iter != m_setObj.end(); ++iter)
// 				{
// 					this->Destroy((*iter).second);
// 				}
// 			}
// 
// 			m_setObj.clear();
// 		}
// 
// 		void	RemoveObj(OBJID idObj, int nType)	{ m_setObj.erase(OBJ_INFO(idObj, nType)); }
// 		void	RemoveAll(void)	{ m_setObj.clear(); }
// 		
// 	protected:
// 		void	Destroy(T* p, DESTROY_DELETE)		{ SAFE_DELETE (p); }
// 		void	Destroy(T* p, DESTROY_RELEASE)	{ SAFE_RELEASE (p); }
// 		void	Destroy(T* p) { this->Destroy(p, X()); }
// 
// 		const bool	m_bOwner;
// 		struct OBJ_INFO {
// 			OBJID	id;
// 			int		nType;
// 			
// 			OBJ_INFO(OBJID _id = ID_NONE, int _nType = -1) : id(_id), nType(_nType) {}
// 		};
// 
// 	private:
// 		typedef	std::map< OBJ_INFO, T* > OBJ_SET;
// 		OBJ_SET	m_setObj;
// 		typename OBJ_SET::iterator m_iter;
// 	};

	//////////////////////////////////////////////////////////////////////
	//
	//////////////////////////////////////////////////////////////////////
	template<class T, class X = DESTROY_DELETE, class Y = OWNER_TRUE>
	class TMultiTypeObjSet
	{
	public:
		TMultiTypeObjSet() {}
		virtual ~TMultiTypeObjSet() { this->DelAll(); }
		
	public:	
		void	BeginEnum(void)	{ m_iter = m_setObj.begin(); }
		T*		EnumObj(void)	{ 
			if (m_iter == m_setObj.end())
				return NULL;
			
			T* p = (*m_iter); 
			++m_iter; 
			return p; 
		}
		
		int		GetAmount(void) const	{ return m_setObj.size(); }
		
		T*		GetObj	(OBJID idObj, int nType) const
		{
			typename OBJ_SET::const_iterator iter = m_setObj.begin();
			for (; iter != m_setObj.end(); ++iter)
			{
				T* p = *iter;
				if (p->GetID() == idObj && p->GetObjType() == nType)
					return p;
			}	
			
			return NULL;
		}
		
		void	AddObj(T* pObj)
		{	
			IF_NOT_T (pObj)
				return;
			
			if (this->GetObj(pObj->GetID(), pObj->GetObjType()))
				return;

			m_setObj.push_back(pObj);
		}
		
		void	DelObj(OBJID idObj, int nType) { this->DelObj(idObj, nType, Y()); }	
		void	DelAll(void) { this->DelAll(Y()); }

		bool	RemoveObj(OBJID idObj, int nType)	
		{ 
			typename OBJ_SET::iterator iter = m_setObj.begin();
			for (; iter != m_setObj.end(); ++iter)
			{
				T* p = *iter;
				if (p->GetID() == idObj && p->GetObjType() == nType)
				{
					m_setObj.erase(iter);
					return true;
				}
			}
			return false;
		}

		void	RemoveAll(void)	{ m_setObj.clear(); }
			
	protected:
		void	Destroy(T* p, DESTROY_DELETE)		{ SAFE_DELETE (p); }
		void	Destroy(T* p, DESTROY_RELEASE)	{ SAFE_RELEASE (p); }
		void	Destroy(T* p) { this->Destroy(p, X()); }
		
		void	DelObj(OBJID idObj, int nType, OWNER_TRUE)
		{
			typename OBJ_SET::iterator iter = m_setObj.begin();
			for (; iter != m_setObj.end(); ++iter)
			{
				T* p = *iter;
				if (p->GetID() == idObj && p->GetObjType() == nType)
				{
					this->Destroy(*iter);				
					m_setObj.erase(iter);
					break;
				}
			}	
		}

		void	DelObj(OBJID idObj, int nType, OWNER_FALSE)
		{
			typename OBJ_SET::iterator iter = m_setObj.begin();
			for (; iter != m_setObj.end(); ++iter)
			{
				T* p = *iter;
				if (p->GetID() == idObj && p->GetObjType() == nType)
				{
					m_setObj.erase(iter);
					break;
				}
			}
		}

		void	DelAll(OWNER_TRUE)
		{
			typename OBJ_SET::iterator iter = m_setObj.begin();
			for (; iter != m_setObj.end(); ++iter)
			{
				this->Destroy(*iter);
			}
			
			m_setObj.clear();
		}

		void	DelAll(OWNER_FALSE)
		{
			m_setObj.clear();
		}

	private:
		typedef	std::vector< T* > OBJ_SET;
		OBJ_SET	m_setObj;
		typename OBJ_SET::iterator m_iter;
	};

NAMESPACE_END(tq)


#endif // _TQ_TEMPLATE_H_
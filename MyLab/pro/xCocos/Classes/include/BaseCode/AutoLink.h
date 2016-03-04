// �Զ�������
// ��ƣ��ɽ���, 2003.7.7
// �޸ģ��ɽ��ޣ�2004.11.21
////////////////////////////////////////////////////////////////
// ˵��:����AutoLink�������ڹ��캯���У��ø������ָ���ʼ���Լ�������: Init(this);
//		����AutoLink����ʹ�ø�ֵ�ķ�ʽ��������LINK��(ע�⣺��ò�Ҫ����̫�����ʱ���󣬷������һ������)������: m_lnkUser = pUser;
//		����AutoLink���ڲ���ָ�������ʱ������AutoLink����գ�����ÿ��ʹ�á���AutoLink��ʱ�����ȼ���Ƿ�Ϊ�ա�(!)
////////////////////////////////////////////////////////////////
//		����AutoLink���ĸ��������ʵ��һ����Ա����������: const AUTOLINK_NOTE* QueryLink() const	{ return m_link.QueryNote(); }


#ifndef	AUTO_LINK_H
#define	AUTO_LINK_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "public.h"
#include "Macro.h"
#include "BaseCode.h"
//#include "public.h"
namespace tq
{
#define		TYPENAME	class
static const int MAXAUTOLINK = 150;

//////////////////////////////////////////////////////////////////////////
template<typename T>
class POINT_NO_RELEASE : public T
{
	virtual USHORT	Release()			= 0;		// prevent call this function
//	virtual void	RleaseByOwner()		= 0;		// prevent call this function
};
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// ����Ա��Ҫֱ��ʹ�ô˽ṹ��������Ϸ�����QueryLink()���Զ�ʹ�á�
struct AUTOLINK_NOTE{
	void*			pOwner;
	AUTOLINK_NOTE*	pPrev;
	AUTOLINK_NOTE*	pNext;

	void Clear()	{ pOwner = pPrev = pNext = NULL; }
};

////////////////////////////////////////////////////////////////
template<TYPENAME T>
class	CAutoLink;
template<TYPENAME T>
class	CAutoLink
{
public:
	CAutoLink()										{ m_data.Clear(); }
	~CAutoLink()									{ Break(); }
	CAutoLink(const AUTOLINK_NOTE* pNote, T* ptr)	{ m_data.Clear(); Insert(ptr->QueryLink(), ptr); }
	CAutoLink(const CAutoLink<T>& link)				{ m_data.Clear(); if(link.m_data.pOwner) Insert(&link.m_data, link.m_data.pOwner); }
	CAutoLink(T* ptr)								{ m_data.Clear(); if(ptr) Insert(ptr->QueryLink(), ptr); }
	CAutoLink&	operator=(const CAutoLink<T>& link)	{ Break(); if(link.m_data.pOwner) Insert(&link.m_data, link.m_data.pOwner); return *this; }
	CAutoLink&	operator=(T* ptr)					
	{ 
		Break(); 
		if(ptr) 
			Insert(ptr->QueryLink(), ptr); 
		return *this; 
	}

public: // modify
	void	Init(T* pOwner)							{ ASSERT(!IsValid() && pOwner); m_data.pOwner=pOwner; }

public: // const for client call
	operator T*() const								{ return (T*)m_data.pOwner; }
	POINT_NO_RELEASE<T>* operator->() const			{ ASSERT(IsValid()); return static_cast<POINT_NO_RELEASE<T>* >((T*)m_data.pOwner); }

public: // const for auto call
	const AUTOLINK_NOTE* QueryNote() const			{ return &m_data; }

protected:
	void	Insert(const AUTOLINK_NOTE* pPrev, void* pOwner);		// insert to next, only for !IsMaster
	void	Erase();							// erase from list, only for !IsMaster
	void	Break();							// clear this note. Erase() for !IsMaster, erase all note for IsMaster
	bool	IsValid()		const					{ return m_data.pOwner != NULL; }
	bool	IsMaster()		const					{ return IsValid() && m_data.pPrev == NULL; }
#ifdef STRICT_CHECK
	size_t	Count(const AUTOLINK_NOTE* pNode) const;
#endif // STRICT_CHECK

public:
protected:
	AUTOLINK_NOTE m_data;
};

#ifdef STRICT_CHECK
////////////////////////////////////////////////////////////////
//Count���ܽϲ���а治����ʹ��
template<TYPENAME T>
size_t CAutoLink<T>::Count(const AUTOLINK_NOTE* pNode) const
{
	CHECKF_T(pNode);
	size_t	nCount=0;
	if(pNode->pOwner!=NULL && pNode->pPrev==NULL)		// master
	{
		AUTOLINK_NOTE* pNextNote = pNode->pNext;
		while(pNextNote)
		{
			AUTOLINK_NOTE* pCurr = pNextNote;
			pNextNote	= pNextNote->pNext;			// ++
			
			DEAD_LOOP_BREAK(nCount, MAXAUTOLINK)
		}
	}
	return nCount;
}
#endif // STRICT_CHECK

////////////////////////////////////////////////////////////////
template<TYPENAME T>
	void CAutoLink<T>::Break()
{
	if(IsMaster())		// master
	{
		AUTOLINK_NOTE* pNextNote = m_data.pNext;
		int	nCount=0;
		while(pNextNote)
		{
			AUTOLINK_NOTE* pCurr = pNextNote;
			pNextNote	= pNextNote->pNext;			// ++

			ASSERT(pCurr->pOwner != NULL);
			pCurr->Clear();

			DEAD_LOOP_BREAK(nCount, MAXAUTOLINK)
		}

		m_data.Clear();
	}
	else
	{
		Erase();
	}
}

////////////////////////////////////////////////////////////////
template<TYPENAME T>
void CAutoLink<T>::Insert(const AUTOLINK_NOTE* pPrev_, void* pOwner)		// insert to next
{
	AUTOLINK_NOTE* pPrev = const_cast<AUTOLINK_NOTE*>(pPrev_);

	IF_NOT(pPrev)
	{
		return; 
	}
	IF_NOT(pPrev != &m_data)
	{
		return;
	}
	IF_NOT(pOwner)
	{
		return;
	}
	IF_NOT(!IsMaster())
	{
		return ;
	}
	Erase();

	m_data.pOwner				= pOwner;
	if(IsValid())
	{
		m_data.pPrev			= pPrev;
		m_data.pNext			= pPrev->pNext;
		if(pPrev->pNext)
			pPrev->pNext->pPrev	= &m_data;
		pPrev->pNext			= &m_data;

	}

	//��ʱ��λ������
#ifdef STRICT_CHECK
	const int nCount = Count(pPrev_);
	if(nCount >= MAXAUTOLINK)
	{
		char szFuncDump[1024] = {0};
//		tq::DumpFuncAddress(10, szFuncDump);
		tq::LogSave("adapter","AutoLink[%s]����[%d] \r\n%s", typeid(*this).name(), nCount, szFuncDump);
	}
#endif // STRICT_CHECK
}

////////////////////////////////////////////////////////////////
template<TYPENAME T>
void CAutoLink<T>::Erase()						// erase from list
{
	if(IsValid())
	{
		IF_NOT(!IsMaster())
		{
			return ;
		}

		m_data.pPrev->pNext	= m_data.pNext;
		if(m_data.pNext)
			m_data.pNext->pPrev	= m_data.pPrev;

		m_data.Clear();
	}
}

}


#endif // AUTO_LINK_H

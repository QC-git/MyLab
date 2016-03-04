// TArray.h: interface for the TArray class.
// paled, 2003.8.5
//////////////////////////////////////////////////////////////////////
// 包含对象的容器(非包含指针)，支持COPY。
// 正向顺序叠代，可在叠代时删除对象，也可在叠代时增加对象，增加的对象不参加此次叠代。
// 程序最大允许SIZE为20亿，但通常用于小规模的SET
// 注意：多个iterator同时操作时，如果有DelObj()调用，会有BUG。
//////////////////////////////////////////////////////////////////////

#if !defined(_TQ_TARRAY_H_)
#define _TQ_TARRAY_H_


#pragma warning(disable: 4284)
#pragma warning(disable:4786)
#include "Macro.h"
#include "BaseCode/BaseMacro.h"
#include <algorithm>
#include <vector>

NAMESPACE_BEGIN(tq)

//////////////////////////////////////////////////////////////////////
template <class T, int SZ=0>
class TArray
{
//-----------------------------------------------
public:	// new traversal
	class	ConstIterator{
		enum { VALID_MASK=0x80000000, SIZE_MASK=0x7FFFFFFF };
	protected: // create by parent class
		ConstIterator(const std::vector<T>* pSet) : m_pSet(pSet),m_nValid_Size(pSet->size()),m_idx(0) {}
		friend class TArray<T>;

	public: // application
		bool	Next()								{ if(m_idx>=Size()) return false; if(!IsValid()) m_nValid_Size+=VALID_MASK; else m_idx++; return m_idx<Size(); }
		void	Reset()								{ m_idx=0; m_nValid_Size=m_pSet->size(); }
 		operator const T*()							{ ASSERT(IsValid()); return &m_pSet->at(m_idx); }
 		const T * operator->()						{ ASSERT(IsValid()); return &m_pSet->operator[](m_idx); }
	protected:
		bool	IsValid()							{ return (m_nValid_Size&VALID_MASK) && m_idx<Size(); }
		int		Size()								{ return m_nValid_Size & SIZE_MASK; }
		void	DelObj()							{ ASSERT_T(Size()); m_nValid_Size = Size()-1; }	// set invalid

	protected:
		const std::vector<T>*	m_pSet;
		unsigned long		m_nValid_Size;
		int					m_idx;
	};
	class	Iterator{
		enum { VALID_MASK=0x80000000, SIZE_MASK=0x7FFFFFFF };
	protected: // create by parent class
		Iterator(std::vector<T>* pSet) : m_pSet(pSet),m_nValid_Size(pSet->size()),m_idx(0) {}
		friend class TArray<T>;

	public: // application
		bool	Next()								{ if(m_idx>=Size()) return false; if(!IsValid()) m_nValid_Size+=VALID_MASK; else m_idx++; return m_idx<Size(); }
		void	Reset()								{ m_idx=0; m_nValid_Size=m_pSet->size(); }
 		operator T*()								{ ASSERT(IsValid()); return &m_pSet->at(m_idx); }
 		T * operator->()							{ ASSERT(IsValid()); return &m_pSet->operator[](m_idx); }
	protected:
		bool	IsValid()							{ return (m_nValid_Size&0x80000000) && m_idx<m_pSet->size(); }
		int		Size()								{ return m_nValid_Size & 0x7FFFFFFF; }
		void	DelObj()							{ ASSERT_T(Size()); m_nValid_Size = Size()-1; }	// set invalid

	protected:
		std::vector<T>*			m_pSet;
		unsigned long		m_nValid_Size;
		int					m_idx;
	};
public: // traverse
	const ConstIterator	NewEnum	() 	const			{ return ConstIterator(&m_set); }
	Iterator	NewEnum	() 							{ return Iterator(&m_set); }
	int			Size	() 	const					{ return m_set.size(); }
//-----------------------------------------------

public:
	TArray()											{ m_set.resize(SZ,T()); }
	explicit TArray(int nSize, T data)				{ m_set.resize(nSize, data); }
	TArray(const TArray& obj)							{ m_set = obj.m_set; }
	TArray<T>& operator=(const TArray<T>& obj)		{ if(this==&obj) return *this; m_set = obj.m_set; return *this; }

public:
	T&		operator[](int idx)						{ ASSERT(idx>=0 && idx<m_set.size()); return m_set[idx]; }
	T&		At(int idx)								{ ASSERT(idx>=0 && idx<m_set.size()); return m_set[idx]; }
	const T& operator[](int idx) const				{ ASSERT(idx>=0 && idx<m_set.size()); return m_set[idx]; }
	const T& At(int idx) const						{ ASSERT(idx>=0 && idx<m_set.size()); return m_set[idx]; }
	void	Clear()									{ m_set.clear(); }
	void	Resize(int nSize, T t=T())				{ m_set.resize(nSize,t); }
	void	Fill(const T& obj)						{ fill(m_set.begin(), m_set.end(), obj); }
	bool	Find(const T& obj)				const	{ return find(m_set.begin(), m_set.end(), obj) != m_set.end(); }
	void	Push(const T& obj)						{ m_set.push_back(obj); }
	T		PopBack()								{ T obj=m_set[m_set.size()-1]; m_set.pop_back(); return obj; }
	bool	DelObj(Iterator& iter)					{ if(!iter.IsValid()) return false; m_set.erase(m_set.begin()+iter.m_idx); iter.DelObj(); return true; }
	bool	DelObj(int idx)							{ ASSERT_T(idx<m_set.size()); m_set.erase(m_set.begin()+idx); return true; }
	template<class X>
		void CopyFrom(const TArray<X>& obj)				{ Clear(); for(int i=0;i<obj.Size();i++) Push(obj[i]); }
	template<class X>
		void CopyFrom(const X buf[], int nSize)			{ Clear(); for(int i=0;i<nSize;i++) Push(buf[i]); }
public: 
//	tq::CString	Dump()	const							{ tq::CString str="{ "; for(int i=0; i<m_set.size(); i++){ if(i) str+=", "; str+= DumpString(m_set[i]); } return str+=" }"; }

protected:
	std::vector<T>		m_set;
};

NAMESPACE_END(tq)

#endif // !defined(_TQ_TARRAY_H_)

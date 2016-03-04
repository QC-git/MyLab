////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2008, TQ Digital Entertainment, All Rights Reserved
// Created:	 2009/03/31
// Describe: TUnmanagedPtr 初始化后无法修改
////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdio.h>
#include <string.h>
#include <cassert>
#include <string>
#include <algorithm>
#include <typeinfo>

template <typename T>
class TUnmanagedPtr
{
public:
	typedef T element_type;
	
	TUnmanagedPtr(T* P = NULL)
		: m_ptr(P) { }
	~TUnmanagedPtr() { }
	
// 	TUnmanagedPtr<T>& operator=(const TUnmanagedPtr<T>& Y)
// 	{
// 		if (NULL == m_ptr)
// 		{
// 			m_ptr = Y.m_ptr;
// 		}
// 		
// 		return (*this); 
// 	}
	
	TUnmanagedPtr<T>& operator=(T* P)
	{
#ifdef STRICT_CHECK
		if (NULL == m_ptr && P==NULL)
		{
			//临时处理:如果是consumer，则assert
			std::string str = typeid(T).name();
			std::transform(str.begin(),str.end(),str.begin(),toupper);
			if (strstr(str.c_str(), "consumer") != NULL)
			{
				assert(false);
			}
		}
#endif // STRICT_CHECK
		m_ptr = P;
		
		return (*this);
	}
	
	const T& operator*() const
	{
		ASSERT_T(m_ptr != NULL);
		return *m_ptr;
	}

	T& operator*()
	{
		assert(m_ptr != NULL);
		return *m_ptr;
	}
	
	T* operator->() const
	{
		assert(m_ptr != NULL);
		return m_ptr;
	}

	T* operator->()
 	{
		assert(m_ptr != NULL);
		return m_ptr;
	}
	
	operator T*() const
	{
		return m_ptr;
	}
	
	operator T*()
	{
		return m_ptr;
	}
private:
	T* m_ptr;
};

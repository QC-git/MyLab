// **********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created:	2004/11/03   0:25
//
// **********************************************************************

#ifndef	_TQ_HEAP_H_
#define _TQ_HEAP_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <cstdint>
#include "../Platform/PlatformDefine.h"

namespace tq
{
	class CHeap
	{
	public:
		CHeap(const char* pszClassName = NULL){};
		~CHeap(){};
		
	public:
        void*		Alloc(size_t size){ return malloc(size); };
        void		Free(void* ptr){ Free(ptr); };
        bool		IsValidPt(void* p){ return p != nullptr; };
	protected:
		void*		m_hHeap;
		uint32_t	m_lNumAlloc;
		uint32_t	m_lMaxAlloc;
		std::string	m_strName;
	};

}	// end of namespace tq


	
// Marco define	
#define	MYHEAP_DECLARATION(VAR)											\
	public:																\
		static bool	IsValidPt(void* p)		{ return VAR.IsValidPt(p); }\
	protected:															\
		static tq::CHeap	VAR;
	
	
#define	MYHEAP_IMPLEMENTATION(T,VAR) tq::CHeap	T::VAR(#T);								
	

	
#endif  // _TQ_HEAP_H_

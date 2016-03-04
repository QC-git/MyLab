//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author:      zengcs
// Created:     2006/08/09
//
// Describe:
//
//*********************************************************************

#if !defined(_TQ_STRING_PACK_H_)
#define _TQ_STRING_PACK_H_
#include <Types.h>
namespace tq
{
	class CStringPacker  
	{
	public:
		CStringPacker();
		virtual ~CStringPacker();
		
		bool	AddString		(const char* pszString);
		
		bool	GetString		(UINT uIndex, char* pszStrBuf, UINT uBufSize);
		UINT	GetStrAmount	(void);
		UINT	GetSize			(void);
		
		void	SetBuf			(char* pBuf, UINT uBufSize);
		
		
	private:
		char*	m_pBuf;
		UINT	m_uBufSize;
	};
}

#endif // !defined(_TQ_STRING_PACK_H_)

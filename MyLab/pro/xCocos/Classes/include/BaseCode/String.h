// **********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created:	2006/01/18
//
// **********************************************************************

#ifndef _TQ_STRING_H_
#define _TQ_STRING_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <stdlib.h>
#include <string>

namespace tq
{
	// 这里要求后续使用CString格式化后的字符串长度不能超过4096-1
	class CString : public std::string  
	{
	public:
		CString();
		CString(const std::string& str)	{ this->assign(str.c_str()); }
		CString(const CString& str)		{ this->assign(str.c_str()); }
		CString(int i)					{ this->Format("%d", i); }
		CString(unsigned int u)			{ this->Format("%u", u); }
		CString(float f)				{ this->Format("%f", f); }
		CString(double d)				{ this->Format("%f", d); }

		//CString(const char* pstr)		{ if (pstr) this->assign(pstr); }
		explicit CString(const char* fmt, ...);
		virtual ~CString();
		
		CString& operator = (const std::string& str){ this->assign(str.c_str()); return *this; }
		CString& operator = (const CString& str)	{ this->assign(str.c_str()); return *this; }
		CString& operator = (const char* pstr)		{ if (pstr) this->assign(pstr); return *this; }
		CString& operator = (int i)					{ this->Format("%d", i); return *this; }
		CString& operator = (unsigned int u)		{ this->Format("%u", u); return *this; }
		CString& operator = (float f)				{ this->Format("%f", f); return *this; }
		CString& operator = (double d)				{ this->Format("%f", d); return *this; }
		
		const char operator [] (int nPos)			{ return this->at(nPos); }
		
		bool operator == (const std::string& str)	{ return (0 == this->compare(str)); }
		bool operator != (const std::string& str)	{ return (0 != this->compare(str)); }
		
		bool operator == (const char* pstr)			
		{ 
			if (pstr) 
				return (0 == this->compare(pstr)); 
			else
				return false;
		}
		bool operator != (const char* pstr)			
		{ 
			return !(operator == (pstr));
		}
		
		operator const char*() const				{ return this->c_str(); }
		
		operator char	() const					{ return (char)atoi(this->c_str()); }
		operator unsigned char	() const			{ return (unsigned char)atoi(this->c_str()); }
		
		operator int	() const					{ return atoi(this->c_str()); }
		operator unsigned int	() const			{ return atoi(this->c_str()); }
		
		operator long	() const					{ return atol(this->c_str()); }
		operator unsigned long	() const			{ return atol(this->c_str()); }
		
		operator double	() const					{ return atof(this->c_str()); }
		operator float	() const					{ return (float)atof(this->c_str()); }
		
		enum { MAX_STRING = 4096 };
		void Format(const char* fmt, ...);
	};
}

#endif // _TQ_STRING_H_

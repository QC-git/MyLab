// -*- C++ -*-

//=============================================================================
/**
 *  @file    BaseFunc.h
 *
 *  $Id: BaseFunc.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _EN_BASEFUNC_H_
#define _EN_BASEFUNC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Define.h"

inline int		MaskLook(int look)							{ return look/10; }
inline int		MaskDir(int look)							{ return look%10; }
inline U32		MakeLookFace(int nMaskLook, int nMaskDir)	{ return (nMaskLook*10) + (nMaskDir%10); }

inline int		MulDiv(int nNumber, int nNumerator, int nDenominator) { return nNumber * nNumerator / nDenominator; }
inline bool		PtInRect(const RECT& rect, const POINT& point) { return point.x >= rect.top && point.x <= rect.bottom&&point.y >= rect.left&&point.y <= rect.right; }

#endif

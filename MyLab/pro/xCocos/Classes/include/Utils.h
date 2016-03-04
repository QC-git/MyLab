////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, TQ Digital Entertainment, 
// All Rights Reserved
//
// Author:  MILO
// Created: 11/5/2015
//
// Brief:   
////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseFunc.h"

#ifndef M_PI
#define M_PI            3.14159265358979323846
#endif

static unsigned int holdrand;

inline void stdseed(unsigned int seed) { holdrand = seed; }

inline unsigned int stdrand() {
    holdrand = holdrand * 214013 + 2531011;
    return (holdrand >> 16) & 0x7fff;
}

inline int32_t irand(int32 min, int32 max)
{
	int nRange = max - min;
	if (nRange > 0) {
		return ((stdrand() << 15) + stdrand()) % nRange + min;
	}
	return min;
	//returnint32 (mtRand.get ().randInt (max - min)) + min;
}

inline void RandPosInRadius(float centerX, float centerY, int radius, float& x, float& y)
{
	if (radius)
	{
		int rs = irand(0, radius);
		float arc = irand(1, 360)*M_PI / 180;
		x = cos(arc)*rs + centerX;
		y = sin(arc)*rs + centerY;
	}
	else
	{
		x = centerX;
		y = centerY;
	}
}

// #ifndef timeGetTime
// inline time_t timeGetTime(void)
// {
// 	return time(NULL);
// }
// #endif // !timeGetTime



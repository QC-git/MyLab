//*********************************************************************
#pragma once

// #ifdef _WIN32
// #include <windows.h>
// #else
#include <chrono>

typedef int16_t		  SHORT;
typedef uint16_t      USHORT;
typedef int           INT;
typedef unsigned int  UINT;
typedef unsigned char UCHAR;
typedef unsigned char BYTE;

#define HIBYTE(w)           ((BYTE)((((uint64_t)(w)) >> 8) & 0xff))
#define LOBYTE(w)           ((BYTE)(((uint64_t)(w)) & 0xff))
#define LOWORD(l)           ((USHORT)(((uint64_t)(l)) & 0xffff))
#define HIWORD(l)           ((USHORT)((((uint64_t)(l)) >> 16) & 0xffff))

typedef struct tagRECT
{
	long    left;
	long    top;
	long    right;
	long    bottom;
} RECT, *PRECT;

typedef struct tagPOINT
{
	int32_t  x;
	int32_t  y;
} POINT, *PPOINT;

typedef struct tagSIZE
{
	uint32_t        cx;
	uint32_t        cy;
} SIZE, *PSIZE, *LPSIZE;


//GetTickCount windows的api，其它平台重实现
inline uint64_t GetTickCount()
{
//	struct timeval tv;
//	gettimeofday(&tv, NULL);
//
//	return (uint64(tv.tv_sec) * uint64(1000) + uint64(tv.tv_usec) / uint64(1000));
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

//#endif // _WIN32


#ifndef _RPCADDON_DEFINE_H_
#define _RPCADDON_DEFINE_H_

#if (defined _WIN32) || (defined _WIN64)
    //
#else
	#include <string.h>
	#define  strcpy_s strcpy

#endif

#endif
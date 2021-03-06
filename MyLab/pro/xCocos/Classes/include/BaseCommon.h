#pragma once


// config.h needs to be included 1st
#ifdef HAVE_CONFIG_H
#ifdef PACKAGE
#undef PACKAGE
#endif //PACKAGE
#ifdef PACKAGE_BUGREPORT
#undef PACKAGE_BUGREPORT
#endif //PACKAGE_BUGREPORT
#ifdef PACKAGE_NAME
#undef PACKAGE_NAME
#endif //PACKAGE_NAME
#ifdef PACKAGE_STRING
#undef PACKAGE_STRING
#endif //PACKAGE_STRING
#ifdef PACKAGE_TARNAME
#undef PACKAGE_TARNAME
#endif //PACKAGE_TARNAME
#ifdef PACKAGE_VERSION
#undef PACKAGE_VERSION
#endif //PACKAGE_VERSION
#ifdef VERSION
#undef VERSION
#endif //VERSION
# include "config.h"
#undef PACKAGE
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef VERSION
#endif //HAVE_CONFIG_H

//#include "Platform/Define.h"

#if COMPILER == COMPILER_MICROSOFT

#pragma warning(disable:4996)

#ifndef __SHOW_STUPID_WARNINGS__

#pragma warning(disable:4244)

#pragma warning(disable:4267)

#pragma warning(disable:4800)

#pragma warning(disable:4018)

#pragma warning(disable:4311)

#pragma warning(disable:4305)

#pragma warning(disable:4005)
#endif                                                      // __SHOW_STUPID_WARNINGS__
#endif                                                      // __GNUC__

// must be the first thing to include for it to work

#include "HashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <signal.h>

#if PLATFORM == PLATFORM_WINDOWS
#define STRCASECMP stricmp
#else
#define STRCASECMP strcasecmp
#endif

#include <string.h>
#include <set>
#include <list>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>


// #if PLATFORM == PLATFORM_WINDOWS
// #  define FD_SETSIZE 4096
// #  include <ace/config-all.h>
// // XP winver - needed to compile with standard leak check in MemoryLeaks.h
// // uncomment later if needed
// //#define _WIN32_WINNT 0x0501
// #  include <ws2tcpip.h>
// //#undef WIN32_WINNT
// #else
// #  include <sys/types.h>
// #  include <sys/ioctl.h>
// #  include <sys/socket.h>
// #  include <netinet/in.h>
// #  include <unistd.h>
// #  include <netdb.h>
// #endif

#if COMPILER == COMPILER_MICROSOFT

#include <float.h>

#define I64FMT "%016I64X"
#define I64FMTD "%I64u"
#define SI64FMTD "%I64d"
#define snprintf _snprintf
#define atoll __atoi64
#define vsnprintf _vsnprintf
#define strdup _strdup
#define finite(X) _finite(X)

#else

#define stricmp strcasecmp
#define strnicmp strncasecmp
#define I64FMT "%016llX"
#define I64FMTD "%llu"
#define SI64FMTD "%lld"
#endif

//inline float finiteAlways(float f) { return finite(f) ? f : 0.0f; }

#define atol(a) strtoul( a, NULL, 10)

#define STRINGIZE(a) #a

enum TimeConstants
{
	MINUTE = 60,
	HOUR   = MINUTE*60,
	DAY    = HOUR*24,
	MONTH  = DAY*30
};

enum AccountTypes
{
	SEC_PLAYER         = 0,
	SEC_MODERATOR      = 1,
	SEC_GAMEMASTER     = 2,
	SEC_ADMINISTRATOR  = 3
};

enum LocaleConstant
{
	LOCALE_enUS = 0,
	LOCALE_koKR = 1,
	LOCALE_frFR = 2,
	LOCALE_deDE = 3,
	LOCALE_zhCN = 4,
	LOCALE_zhTW = 5,
	LOCALE_esES = 6,
	LOCALE_esMX = 7,
	LOCALE_ruRU = 8
};

#define MAX_LOCALE 9

extern char const* localeNames[MAX_LOCALE];

LocaleConstant GetLocaleByName(std::string name);

// we always use stdlibc++ std::max/std::min, undefine some not C++ standard defines (Win API and some pother platforms)
#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#ifndef M_PI
#define M_PI            3.14159265358979323846
#endif

#if PLATFORM != PLATFORM_WINDOWS

inline void _split_whole_name(const char *whole_name, char *fname, char *ext)
{
	const char *p_ext;

	p_ext = strrchr(whole_name, '.');
	if (NULL != p_ext)
	{
		strcpy(ext, p_ext);
		snprintf(fname, p_ext - whole_name + 1, "%s", whole_name);
	}
	else
	{
		ext[0] = '\0';
		strcpy(fname, whole_name);
	}
}

inline void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext)
{
	drive[0] = '\0';
	if (NULL == path)
	{
		dir[0] = '\0';
		fname[0] = '\0';
		ext[0] = '\0';
		return;
	}

	if ('/' == path[strlen(path)])
	{
		strcpy(dir, path);
		fname[0] = '\0';
		ext[0] = '\0';
		return;
	}

	const char *p_whole_name;
	p_whole_name = strrchr(path, '/');
	if (NULL != p_whole_name)
	{
		p_whole_name++;
		_split_whole_name(p_whole_name, fname, ext);

		snprintf(dir, p_whole_name - path, "%s", path);
	}
	else
	{
		_split_whole_name(path, fname, ext);
		dir[0] = '\0';
	}
}

#endif

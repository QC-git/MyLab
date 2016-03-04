#ifndef _COMMON_INCLUDED_
#define _COMMON_INCLUDED_

#if _MSC_VER > 1000
#    pragma once
#endif

#if (defined _DEBUG || defined DEBUG)
#    pragma comment(lib, "Public.lib")
#else
#    pragma comment(lib, "Public.lib")
#endif

#endif	//_COMMON_INCLUDED_
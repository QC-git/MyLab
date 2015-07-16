
#include "x_kbe.h"

#ifdef _DEBUG
#pragma comment(lib, "apr-1_d.lib")
#pragma comment(lib, "aprutil-1_d.lib")
#pragma comment(lib, "common_d.lib")
// #pragma comment(lib, "db_interface_d.lib")
// #pragma comment(lib, "db_mysql_d.lib")

#pragma comment(lib, "expat_d.lib")
#pragma comment(lib, "helper_d.lib")
#pragma comment(lib, "jwsmtp_d.lib")
#pragma comment(lib, "libeay32_d.lib")
#pragma comment(lib, "log4cxx_d.lib")
#pragma comment(lib, "math_d.lib")
#pragma comment(lib, "navigation_d.lib")


#pragma comment(lib, "network_d.lib")
#pragma comment(lib, "resmgr_d.lib")
#pragma comment(lib, "ssleay32_d.lib")
#pragma comment(lib, "thread_d.lib")
#pragma comment(lib, "tmxparser_d.lib")
#pragma comment(lib, "xml_d.lib")
#pragma comment(lib, "zip_d.lib")

//#pragma comment(lib, "client_lib_d.lib")


#pragma comment(lib, "_ctypes_d.pyd")
#pragma comment(lib, "_elementtree_d.pyd")
#pragma comment(lib, "_hashlib_d.pyd")
#pragma comment(lib, "_socket_d.pyd")

#pragma comment(lib, "pyexpat_d.pyd")
#pragma comment(lib, "select_d.pyd")
#pragma comment(lib, "unicodedata_d.pyd")
#pragma comment(lib, "python34_d.lib")
#pragma comment(lib, "pyscript_d.lib")

#pragma comment(lib, "entitydef_d.lib")

//#pragma comment(lib, "server_d.lib")

// 
// 	#pragma comment(lib, "Version.lib")
// 	#pragma comment(lib, "netapi32.lib")
// #pragma comment(lib, "python27.lib")
// #pragma comment(lib, "python27.lib")
// #pragma comment(lib, "python27.lib")
// #pragma comment(lib, "python27.lib")
//lib;log4cxx_d.lib;expat_d.lib;jwsmtp_d.lib;_;;ud;Version.lib;netapi32.lib;zip_d.lib;resmgr_d.lib;python34_d.lib;server_d.lib;pyscript_d.lib;entitydef_d.lib;xml_d.lib;common_d.lib;helper_d.lib;math_d.lib;network_d.lib;thread_d.lib;ws2_32.lib;%(AdditionalDependencies)
#else

#endif

#include <winsock.h>

#include "network/address.h"
#include "network/endpoint.h"

namespace net_kbe
{
	typedef KBEngine::Network::Address  Addr_t;
	typedef KBEngine::Network::EndPoint Point_t;
}

_SERVOCE_DOOR_BEGIN

_SERVICE_IMPLEMENT ERR_T KbeTest()
{
	//LOG_F("KbeTest()");

	net_kbe::Point_t t;

	return 0;
}

_SERVOCE_DOOR_END
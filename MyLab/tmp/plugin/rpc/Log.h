
#ifndef __LOG_H__
#define __LOG_H__

#include "Interface.h"

extern unsigned g_loglevel;
extern clusterrouter::LogOutput g_logoutput;

#define LOG_TRC(format, ...) {if(g_loglevel<=0) { g_logoutput(0, format, ##__VA_ARGS__); }}
#define LOG_DBG(format, ...) {if(g_loglevel<=1) { g_logoutput(1, format, ##__VA_ARGS__); }}
#define LOG_INF(format, ...) {if(g_loglevel<=2) { g_logoutput(2, format, ##__VA_ARGS__); }}
#define LOG_WRN(format, ...) {if(g_loglevel<=3) { g_logoutput(3, format, ##__VA_ARGS__); }}
#define LOG_ERR(format, ...) {if(g_loglevel<=4) { g_logoutput(4, format, ##__VA_ARGS__); }}


#endif // __LOG_H__

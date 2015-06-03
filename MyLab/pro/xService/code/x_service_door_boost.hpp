
#ifdef X_SERVICE_USE_PRAGMAONCE
#pragma once
#endif

#ifndef _SERVOCE_DOOR_BOOST_HEADER
#define _SERVOCE_DOOR_BOSST_HEADER

//#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

//////////////////////////////////////////////////////////////////////////
_SERVOCE_DOOR_BEGIN

/*
************************************************************************************************************************
*                                                    CFunction
*
* Description: 函数容器
*
* Arguments  : 无
*
* Returns    : 随机
*
* Note(s)    :
*
************************************************************************************************************************
*/
class _SERVICE_CLASS CFunction
{
public:
	CFunction();
	virtual ~CFunction();

};

/*
************************************************************************************************************************
*                                                    BoostTest
*
* Description: 测试
*
* Arguments  : 无
*
* Returns    : 随机
*
* Note(s)    :
*
************************************************************************************************************************
*/
_SERVICE_EXPORT ERR_T BoostTest();

_SERVOCE_DOOR_END
	//////////////////////////////////////////////////////////////////////////

#ifdef _SERVICE_DOOR_LOCK
#error  "this file can not include the door"
#endif

#endif
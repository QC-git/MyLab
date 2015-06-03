
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
* Description: ��������
*
* Arguments  : ��
*
* Returns    : ���
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
* Description: ����
*
* Arguments  : ��
*
* Returns    : ���
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
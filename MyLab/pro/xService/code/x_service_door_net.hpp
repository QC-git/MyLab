
#ifdef X_SERVICE_USE_PRAGMAONCE
#pragma once
#endif

#ifndef _SERVOCE_DOOR_NET_HEADER
#define _SERVOCE_DOOR_NET_HEADER



//////////////////////////////////////////////////////////////////////////
_SERVOCE_DOOR_BEGIN


/*
************************************************************************************************************************
*                                                    CIp
*
* Description: ����IP
*
* Arguments  : ��
*
* Returns    : ��
*
* Note(s)    :
*
************************************************************************************************************************
*/

enum EM_NET_TYPE{
	EM_NET_TCP,
	EM_NET_UDP
};

class _SERVICE_CLASS CNetIp
{
public:
	CNetIp() {;}
	virtual ~CNetIp() {;}

	static CNetIp* Create(const CHAR_T* sAddr, U16_T uPort = 0);

public:
	virtual BOOL_T IsEffect() = 0;

};

/*
************************************************************************************************************************
*                                                    CNetPoint
*
* Description: ����˵�, ����sock
*
* Arguments  : ��
*
* Returns    : ��
*
* Note(s)    : 
*
************************************************************************************************************************
*/

class _SERVICE_CLASS CNetPoint
{
public:
	CNetPoint() {;}
	virtual ~CNetPoint() {;}

	static CNetPoint* Create();

public:
	virtual ERR_T Connect(CNetIp* pRemoteIp) = 0;

	virtual ERR_T Write(CHAR_T* pData, LEN_T uDataLen, LEN_T& uWriteLen, CNetIp* pRemoteIp = NULL) = 0;

	virtual ERR_T Read(CHAR_T* pBuffer, LEN_T uBufferLen, LEN_T& uReadLen, CNetIp* pRemoteIp = NULL) = 0;

};

/*
************************************************************************************************************************
*                                                    CNetListener
*
* Description: ���������
*
* Arguments  : ��
*
* Returns    : ��
*
* Note(s)    : 
*
************************************************************************************************************************
*/

class CNetHanlder
{
public:
	CNetHanlder() {;}
	virtual ~CNetHanlder() {;}

public:
	virtual VOID_T OnAccept(CNetPoint* pNewPonit) = 0;    // �����µ�����

	virtual VOID_T OnRecieve(CNetIp* pRemoteIp, CHAR_T* pData, LEN_T uDataLen) = 0;   // �����µ���Ϣ

};


/*
************************************************************************************************************************
*                                                    CreateNetListener
*
* Description: ������������ڣ�֧��TCP��UDP����
*
* Arguments  : �������ͣ���������IP���ص����
*
* Returns    : �������
*
* Note(s)    :
*
************************************************************************************************************************
*/
_SERVICE_EXPORT HANDLE_T CreateNetListener_f(EM_NET_TYPE eType, CNetIp* pHostIp, CNetHanlder* pCb);

/*
************************************************************************************************************************
*                                                    NetTest
*
* Description: �����������
*
* Arguments  : �������
*
* Returns    : ��
*
* Note(s)    :
*
************************************************************************************************************************
*/
_SERVICE_EXPORT VOID_T DestroyNetListener_f(HANDLE_T hListener);

/*
************************************************************************************************************************
*                                                    NetTest
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
_SERVICE_EXPORT ERR_T NetTest();

_SERVOCE_DOOR_END
	//////////////////////////////////////////////////////////////////////////

#ifdef _SERVICE_DOOR_LOCK
#error  "this file can not include the door"
#endif

#endif
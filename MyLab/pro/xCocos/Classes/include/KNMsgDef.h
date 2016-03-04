////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2007, TQ Digital Entertainment, All Rights Reserved
// Author: Wu yongmin
// Created: 2005/11/18
////////////////////////////////////////////////////////////////////////

#ifndef _KN_MSGDEFINE_H_
#define _KN_MSGDEFINE_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//////////////////////////////////////////////////////////////////////
enum PORT_MSG
{	
	_MSG_BASE					= 0,
	_MSG_VERSION,
	_MSG_ONTIMER,
	_MSG_BROADCAST,
	_MSG_SETUP_SERVE,
	_MSG_CLOSE_SERVE,
	//��Ϣ�鲥 added by lzx 20081031
	_MSG_MULTICAST,				
	_MSG_GM_COMMAND,

	// ShellServe Msg
	_MSG_SHELL_INIT				= _MSG_BASE+10,
	_MSG_SHELL_NETWORK,
	_MSG_SHELL_LOGIN,
	_MSG_SHELL_GAME,
	_MSG_SHELL_GLOBE,
	_MSG_SHELL_DB,
	_MSG_SHELL_AI,
	
	// NetworkServe Msg
	_MSG_NETWORK_SCK_SWITCH		= _MSG_BASE+20,
	_MSG_NETWORK_SCK_CLOSE,
	_MSG_NETWORK_CHG_PORT,
	_MSG_NETWORK_CHG_ENCRYPTOR,
	
	// LoginServe Msg
	_MSG_LOGIN_PORT				= _MSG_BASE+30,
    _MSG_LOGIN_CHECKIN,
    _MSG_LOGIN_CHECKOUT,

	// GameServe Msg
	_MSG_GAME_CONNECT_SETUP		= _MSG_BASE+40,		
	_MSG_GAME_CONNECT_CLOSE,
    _MSG_GAME_CONNECT_LOGIN,
	_MSG_GAME_CONNECT_AISETUP,
	_MSG_GAME_CONNECT_AICLOSE,
	_MSG_GAME_REQUEST,
	_MSG_GAME_RESULT,
	
	// GlobeServe Msg
	_MSG_GLOBE_REQUEST			= _MSG_BASE+50,		
	_MSG_GLOBE_RESULT,
	
	// DBServe Msg
    _MSG_DB_LOAD				= _MSG_BASE+60,
    _MSG_DB_UNLOAD,
	_MSG_DB_QUERY,
	_MSG_DB_APPEND,
	_MSG_DB_ERASE,
	_MSG_DB_REFRESH,
	_MSG_DB_MONITOR,

	// AIServe Msg
//	_MSG_AI_XXXX				= _MSG_BASE+70,	
	
	
	_MSG_NETWORK_STOP			= _MSG_BASE+80,
	_MSG_GAME_VERSION			= _MSG_BASE+81,	
	
	//chenyc 0823 added begin
	_MSG_WHOIS					= _MSG_BASE + 90,
	_MSG_CLIENT_DISCONNECT,
	_MSG_LOGIN_SERVER_START,
	_MSG_INSTANCESRV_DISCONNECT,
	_MSG_SWITCH_INSSVR,							//�л�����������/����������
	_MSG_TRANS,									//�����͸���֮�䷢������
	_MSG_QUERY_LOADINFO,						//��ѯ�������ص�״̬
	_MSG_LOADINFO_STATUS,						//���������渱���ĸ���״̬
	_MSG_MAINSRV_ACTIVE,						//��������    -|
	_MSG_MAINSRV_DEACTIVE,						//��������     |
	_MSG_INSSVR_ACTIVE,							//��������     | ���ĸ����Ͷ��õ���MSG_SVR_ACTIVE�Ľṹ��/����
	_MSG_INSSVR_DEACTIVE,						//��������    _|

	_MSG_APPEAL_INS,							//����һ���¸���
	_MSG_APPEAL_INS_RET,						//����һ�������Ĵ�����
	_MSG_DEL_INS,								//ɾ��һ������
	_MSG_DEL_INS_RET,							//ɾ��һ�������Ĵ�����

	_MSG_USER_GO_INS,							//��ҽ�����
	_MSG_USER_GO_INS_RET,						//��ҽ��������
	_MSG_USER_EXIT_INS,							//����˳�����
	_MSG_USER_EXIT_INS_RET,						//����˳��������

	_MSG_GAMESERVE_REG,							//gameserve��idע�ᵽnetworkģ��

	_MSG_INS_EXCEPT_EXIT,						//�����쳣�˳�����Ϊ�������������ߵ�ԭ��

	//׷�ӵ�Э��
	_MSG_INSSVR_CONNECT,						//������������
	_MSG_INSSVR_INITED,							//�����̳߳�ʼ�����

	_MSG_INS_INFO,								//������Ϣ

	//chenyc 0823 added end
    _MSG_LP_AVAILABLE                        = 163,		//LP�Ƿ�����
    _MSG_NEW_CONNECT                         = 168,		//���� tweyseo
};

enum INS_TYPE
{
	INS_TYPE_SMALL	= 0,
	INS_TYPE_MEDIUM = 1,
	INS_TYPE_LARGE	= 2,
	INS_TYPE_HUGE	= 3,
	INS_TYPE_INF	= 4,
};

const int MAX_USER__INS_SMALL	= 8;
const int MAX_USER__INS_MEDIUM	= 16;
const int MAX_USER__INS_LARGE	= 32;
const int MAX_USER__INS_HUGE	= 64;
const int MAX_USER__INS_INF		= 2000;	//������


//////////////////////////////////////////////////////////////////////
#endif   // end of define _KN_MSGDEFINE_H_

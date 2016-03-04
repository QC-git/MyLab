////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2007, TQ Digital Entertainment, All Rights Reserved
// Author: Wu yongmin
// Created: 2007/07/18
////////////////////////////////////////////////////////////////////////

#ifndef _KN_MSG_H_
#define _KN_MSG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include <windows.h>
#include <time.h>

#include "Define.h"
#include "KNMsgDef.h"
/*#include "MsgDefine.h"*/


//////////////////////////////////////////////////////////////////////
#define FRAMEWORK_VERSION    "Framework-Ver1.1"

//////////////////////////////////////////////////////////////////////
const int AI_CID	= 0;
const int AI_ACCOUNT= 0;

//////////////////////////////////////////////////////////////////////
struct MSG_HEADER
{
	uint16_t	wSize;
	uint16_t	wType;
};


//////////////////////////////////////////////////////////////////////
// internal msg define
//////////////////////////////////////////////////////////////////////
struct MSG_VERSION
{
	char	szVersion[16];
};

struct MSG_BROADCAST
{
	char szBroadcast[_MAX_WORDSSIZE];
};

struct MSG_MULTICAST
{
	int		nAction;	//��������:0=ָ��socketid����, 1=ȫ���㲥 ,2=ָ����ͼ�㲥 ,3=ָ��block id���� 4=team,5=syndicate
	UINT	unData;	//unData=0 unCount=���͵�socket id����Ŀ,nAction=2	unData=ָ���㲥�ĵ�ͼID , nAction=3 unData=block id
	UINT	unBufSize;	//��Ҫ���͵���Ϣ��С
	char	szBuf[1];  //���͵���Ϣ
};

struct MSG_SETUP_SERVE
{
	
};

struct MSG_CLOSE_SERVE
{
};


struct MSG_DB_INFO
{
    clock_t	tmSrvMax;
	clock_t	tmSrvAvg;
	clock_t	tmSrv;
	uint32_t	dwSrvCount;
    uint32_t	dwMsg;
	uint32_t	dwTotalSQL;
	uint32_t	dwSQLPer5Min;
	uint32_t	dwSumPer5Min;
	uint32_t	dwAvgPer5Min;
	uint32_t	dwMaxPer5Min;
};

struct MSG_NETWORK_INFO
{
	clock_t	tmSrvMax;
    clock_t	tmSrvAvg;
	clock_t	tmSrv;
	uint32_t	dwSrvCount;
	uint32_t	dwMsg;
	uint32_t	dwBytesSnd;
	uint32_t	dwTotalBytesSnd;
	uint32_t	dwBytesRcv;
	uint32_t	dwTotalBytesRcv;
	uint32_t	dwSckPerAccept;
	uint32_t	dwSckPerClose;
	uint32_t	dwSckOnline;
};

struct MSG_LOGIN_INFO
{
	clock_t	tmSrvMax;
    clock_t	tmSrvAvg;
	clock_t	tmSrv;
	uint32_t	dwSrvCount;
	uint32_t	dwMsg;
    uint32_t	dwAuthorize;
	uint32_t	dwRegister;
    uint32_t	dwLogin;
};

struct MSG_GAME_INFO
{
	clock_t	tmSrvMax;
    clock_t	tmSrvAvg;
	clock_t	tmSrv;
	uint32_t	dwSrvCount;
	uint32_t	dwMsg;
	uint32_t	dwLogin;
	uint32_t	dwLogout;
	uint32_t	dwKickout;
	uint32_t   dwOnline;
    OBJID	idCurrMsgType;
    time_t	tmCurrTime;
};

struct MSG_GLOBE_INFO
{
	clock_t	tmSrvMax;
    clock_t	tmSrvAvg;
	clock_t	tmSrv;
	uint32_t	dwSrvCount;
	uint32_t	dwMsg;
};

struct MSG_AI_INFO
{
	clock_t	tmSrvMax;
    clock_t	tmSrvAvg;
	clock_t	tmSrv;
	uint32_t	dwSrvCount;
	uint32_t	dwMsg;
	uint32_t	dwMonsterTotal;
	uint32_t	dwMonsterGen;
};

// Network
struct MSG_NETWORK_CHGPORT
{
	U32		u32Id;
	int		port;
};

struct MSG_NETWORK_CHGENCRYPTOR
{
	U32		u32Id;
	INT		nType;
	UINT	uCode;
};

struct MSG_NETWORK_SCK_SWITCH
{
	bool	bRefuseConnect;
};

struct MSG_NETWORK_SCK_CLOSE
{
	U32		u32Id;
	UINT	nResion;
};

// Login
struct MSG_LOGIN_PORT
{
    UINT	unMapGroup;
    INT	    port;
};

struct MSG_LOGIN_CHECKIN
{
    U32		u32Id;
    OBJID	idAccount;
    uint32_t	dwAuthorize;
    char    szIP[16];
    char    szMac[17];
};

struct MSG_LOGIN_CHECKOUT
{
    OBJID	idAccount;
	bool	bCheckOutKick;
};

// Game
struct MSG_GAME_CONNECT_SETUP
{
	U32		u32Id;
    OBJID	idAccount;
	OBJID	idUser;		//��ֹ�ʺŷ�������û�ȿͻ�����֤��ͷ�����Ϣ
    uint32_t	dwAuthorize;
    UINT	unVipLevel;
	bool	bAdult;
	char	szClientIP[16];
	
};

struct MSG_GAME_CONNECT_CLOSE
{
	U32		u32Id;
};

struct MSG_GAME_CONNECT_LOGIN
{
    OBJID	idActor;
    INT     nLevel;
	char	szName[256];
// 	char    szMonicker[256];
	INT		nLookFace;
// 	INT		nFace;
	INT		nMap;
};

struct MSG_GAME_CONNECT_AILOGIN
{
	uint64_t	sck;
	bool	bDelAllMonster;
};

// DB
struct MSG_DB_LOAD
{
    U32		u32Id;
	OBJID	idAccount;
    int     nPort;
};

struct MSG_DB_UNLOAD
{
    OBJID	idAccount;
};

//enum MODE { MODE_NONE = 0, MODE_READ, MODE_EDIT };
//struct MSG_DB_SQL
//{
//	OBJID	idUser;
//	MODE	eType;
//	char*	szSQL[MAX_SIZE_SQL];
//};

struct MSG_NETWORK_STOP
{
	bool    bStop;
	uint32_t	dwTime;
};

struct MSG_GAME_VERSION
{
    uint32_t	dwGameVersion;
};

enum MONITOR_TYPE
{
	CONNECT_ACCOUNT_STATE,
	CURRENT_PLAYER_AMOUNT,
	MAX_PLAYER_LIMIT,
	DB_SERVER_STATE,
	SERVER_CRASH_STATE,
	MAPGROUP_MSG_AMOUNT,
	SERVER_MSG_QOS,
	VALIDE_DAY,
	HALFEXP_PLAYER_AMOUNT,
	ZEROEXP_PLAYER_AMOUNT,
	FULLEXP_PLAYER_AMOUNT,
	ADULT_PLAYER_AMOUNT
};

struct MSG_DB_MONITOR
{
	MONITOR_TYPE	eCmdType;
	int				nData;
	OBJID			idAccount;
};

struct MSG_GM_COMMAND
{
	OBJID idAction;			//0: shutdown notify , 1: kickoutall
};

//chenyc 0823 added begin
struct MSG_WHOIS
{
	SNID	u32Id;				//����ʱЯ������Ϣ�����η�/������
	int		nType;				//0��ʾ��ѯ��1��ʾ����ע����Ϣ	
};

struct MSG_SWITCH_INSSVR
{
	SCID	userScid;	//���socket client id
	SNID	insSvrSnid; //����/������snid
};

struct MSG_SVR_ACTIVE		//��/��������������
{
	SNID	svrSnid;		//��/������������SNID
	int		nMaxUserCnt;	//��������
	char	szSvrname[100];	//ע��ʱЯ���ķ�����������һ�����ܵ�½
	bool	bIsReal;		//�Ƿ�ٵ�½��false=�ٵ�½.�ٵ�½ʱ��������ͨ����������ѡ��ø�����������������
};

struct MSG_SVR_DEACTIVE		//��/��������������
{
	SNID	svrSnid;	//��/������������SNID
};

struct MSG_INS_EXCEPT_EXIT
{
	int		nCnt;			//�쳣���ߵĸ�����
	SNID	snids[250];		//�쳣���ߵĸ�������,���250��
};

struct MSG_APPEAL_INS							//����һ���¸���
{
	SNID	insSnid;	//������SNID
	int		nMinUser;	//�������С�û���
	uint32_t	nAppealID;  //����id����
};

struct MSG_APPEAL_INS_RET						//����һ�������Ĵ�����
{
	SNID	insSnid;	//������SNID
	bool	bResult;	//������
	int		nMaxUser;	//���֧�ֵ��û���
	uint32_t	nAppealID;  //����id����
};

struct MSG_DEL_INS								//ɾ��һ������
{
	SNID	insSnid;	//������SNID
};
	
struct MSG_DEL_INS_RET							//ɾ��һ�������Ĵ�����
{
	SNID	insSnid;	//������SNID
	bool	bResult;	//���
};

struct MSG_USER_GO_INS							//��ҽ�����
{
	SCID	userScid;	//��ҵ�SCID
	SNID	insSnid;	//������SNID

	//���¼����ֶηǱ��룬�����������͵�������ʱ���ɿ����д
	UINT	uneState;	//״̬��Ϣ		
	OBJID	idAccount;
	UINT	unVipLevel;
	//���¼����ֶζ���ͬGameServe\Connect.h��USER_INFO�Ķ���
	OBJID	idUser;
	char	szName[256];
	char    szMonicker[256];
	INT     nLevel;
	INT		nLook;
	INT		nFace;
	INT		nMap;
};

struct MSG_USER_GO_INS_RET						//��ҽ��������
{
	SCID	userScid;	//��ҵ�SCID
	SNID	insSnid;	//������SNID
	bool	bResult;	//�������Ƿ�ɹ�
};

struct MSG_USER_EXIT_INS						//����˳�����
{
	SCID	userScid;	//��ҵ�SCID
	SNID	insSnid;	//������SNID
};

struct MSG_USER_EXIT_INS_RET					//����˳�����
{
	SCID	userScid;	//��ҵ�SCID
	SNID	insSnid;	//������SNID
	bool	bResult;	//�˳������Ƿ�ɹ�
};

struct MSG_INSSVR_CONNECT						//������������
{
	uint16_t	wSize;
	uint16_t	wType;
};

struct MSG_INSSVR_INITED						//�����̳߳�ʼ�����
{
	uint16_t	wSize;
	uint16_t	wType;	
	PORTID	gamePortId;	//GameServe��PortID��Ϣ
	bool	bResult;	//���
	UINT	nGameServeCnt; //��ǰ���õ�GameServe�߳���
};

//chenyc 0823 added end

//////////////////////////////////////////////////////////////////////
#endif   // end of define _KN_MSG_H_

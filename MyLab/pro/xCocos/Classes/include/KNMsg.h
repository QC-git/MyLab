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
	int		nAction;	//发送类型:0=指定socketid发送, 1=全服广播 ,2=指定地图广播 ,3=指定block id发送 4=team,5=syndicate
	UINT	unData;	//unData=0 unCount=发送的socket id的数目,nAction=2	unData=指定广播的地图ID , nAction=3 unData=block id
	UINT	unBufSize;	//需要发送的消息大小
	char	szBuf[1];  //发送的消息
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
	OBJID	idUser;		//防止帐号服务器还没等客户端验证后就发送消息
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
	SNID	u32Id;				//返回时携带的信息（主游服/副本）
	int		nType;				//0表示查询，1表示返回注册信息	
};

struct MSG_SWITCH_INSSVR
{
	SCID	userScid;	//玩家socket client id
	SNID	insSvrSnid; //副本/主服的snid
};

struct MSG_SVR_ACTIVE		//主/副本服务器上线
{
	SNID	svrSnid;		//主/副本服务器的SNID
	int		nMaxUserCnt;	//服务能力
	char	szSvrname[100];	//注册时携带的服务器名，不一致则不能登陆
	bool	bIsReal;		//是否假登陆，false=假登陆.假登陆时，仅建立通道，而不能选择该副本服务器创建副本
};

struct MSG_SVR_DEACTIVE		//主/副本服务器下线
{
	SNID	svrSnid;	//主/副本服务器的SNID
};

struct MSG_INS_EXCEPT_EXIT
{
	int		nCnt;			//异常下线的副本数
	SNID	snids[250];		//异常下线的副本集合,最多250个
};

struct MSG_APPEAL_INS							//请求一个新副本
{
	SNID	insSnid;	//副本的SNID
	int		nMinUser;	//请求的最小用户数
	uint32_t	nAppealID;  //请求id序列
};

struct MSG_APPEAL_INS_RET						//请求一个副本的处理结果
{
	SNID	insSnid;	//副本的SNID
	bool	bResult;	//申请结果
	int		nMaxUser;	//最大支持的用户数
	uint32_t	nAppealID;  //请求id序列
};

struct MSG_DEL_INS								//删除一个副本
{
	SNID	insSnid;	//副本的SNID
};
	
struct MSG_DEL_INS_RET							//删除一个副本的处理结果
{
	SNID	insSnid;	//副本的SNID
	bool	bResult;	//结果
};

struct MSG_USER_GO_INS							//玩家进副本
{
	SCID	userScid;	//玩家的SCID
	SNID	insSnid;	//副本的SNID

	//以下几个字段非必须，仅在主服发送到副本服时，由框架填写
	UINT	uneState;	//状态信息		
	OBJID	idAccount;
	UINT	unVipLevel;
	//以下几个字段定义同GameServe\Connect.h内USER_INFO的定义
	OBJID	idUser;
	char	szName[256];
	char    szMonicker[256];
	INT     nLevel;
	INT		nLook;
	INT		nFace;
	INT		nMap;
};

struct MSG_USER_GO_INS_RET						//玩家进副本结果
{
	SCID	userScid;	//玩家的SCID
	SNID	insSnid;	//副本的SNID
	bool	bResult;	//进副本是否成功
};

struct MSG_USER_EXIT_INS						//玩家退出副本
{
	SCID	userScid;	//玩家的SCID
	SNID	insSnid;	//副本的SNID
};

struct MSG_USER_EXIT_INS_RET					//玩家退出副本
{
	SCID	userScid;	//玩家的SCID
	SNID	insSnid;	//副本的SNID
	bool	bResult;	//退出副本是否成功
};

struct MSG_INSSVR_CONNECT						//副本连上主服
{
	uint16_t	wSize;
	uint16_t	wType;
};

struct MSG_INSSVR_INITED						//副本线程初始化结果
{
	uint16_t	wSize;
	uint16_t	wType;	
	PORTID	gamePortId;	//GameServe的PortID信息
	bool	bResult;	//结果
	UINT	nGameServeCnt; //当前配置的GameServe线程数
};

//chenyc 0823 added end

//////////////////////////////////////////////////////////////////////
#endif   // end of define _KN_MSG_H_

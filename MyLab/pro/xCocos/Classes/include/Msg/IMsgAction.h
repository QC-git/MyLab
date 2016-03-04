//==========================================================================
/**
*  @file   IMsgAction.h
*
*  $Id: IMsgAction.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGACTION_H_
#define _MSG_IMSGACTION_H_

#include "Define.h"
#pragma pack(push, 1)
namespace msgaction
{
	enum
	{
		actionNone				=0, 
		actionChgDir			=1, 
		actionPosition			=2,			//(作废) 彩江使用
		actionEmotion			=3,
		actionBroadcastPos		=4,
		actionDivorce			= 5,
		actionSelfUnfreeze		=6,
		actionChgMap			=7,			// 无需参数
		actionFlyMap			=8,
		actionChgWeather		=9,
		actionFireworks			= 10,
		actionDie				=11,
		actionQuitSyn			=12,
		actionWalk				=13,		//(作废)
		actionEnterMap			=14,		// 登录第1步，通知客户端登录成功，玩家已经进入地图。仅玩家! (to client: idUser is Map)
		actionGetItemSet		= 15,		// 登录第2步
		actionGetGoodFriend		=16,		// 登录第3步
		actionForward			=17,		//(作废) 彩江使用
		actionLeaveMap			=18,		// 服务器->客户端,idPlayer。与CMsgPlayer对应，表示玩家离开地图，要求删除对象。
		actionJump				=19,
		actionRun				= 20,		//(作废)
		actionEquip				=21,
		actionUnequip			=22,
		actionUplev				=23,		// 玩家机体升级(只显示动画),nPosX为机体ID
		actionXpCLear			=24,
		actionReborn			= 25,
		actionDelRole			=26,
		actionGetWeaponSkillSet	=27,		// 登录第4步
		actionGetMagicSet		=28,		// 登录第5步
		actionSetPkMode			=29,
		actionGetSynAttr		= 30,
		actionGhost				=31,		// 变鬼
		actionSynchro			=32,		// 坐标同步。send to client self, request client broadcast self coord if no synchro; broadcast to other client, set coord of this player
		actionQueryFriendInfo	=33,		// idTarget = friend id
		actionQueryLeaveWord	=34,
		actionChangeFace		= 35,
		actionMine				=36,
		actionTeamMemeberPos	=37,		// to client only, 主动下传队友坐标
		actionQueryPlayer		=38,
		actionAbordMagic		=39,
		actionMapARGB			= 40,		// to client only
		actionMapStatus			=41,		// to npc server only, idTarget = map id.
		actionQueryTeamMember	=42,		// To server & to client, 查询队友坐标
		actionCreateBooth		=43,		// 开始摆摊 to server - unPosX,unPosY: playerpos; unDir:dirofbooth; to client - idTarget:idnpc; 
		actionSuspendBooth		=44,		// 收起摆摊
		actionResumeBooth		= 45,		// 继续摆摊 to server - unPosX,unPosY: playerpos; unDir:dirofbooth; to client - idTarget:idnpc; 
		actionDestroyBooth		=46,		// 停止摆摊
		actionQueryCryOut		=47,		// 查询摆摊吆喝
		actionPostCmd			=48,		// to client only
		actionQuerySpiritEquipment	=49,		// to server //idTarget为需要query的PlayerID
		actionAbortTransform	= 50,		// to server
		actionCombineSubSyn		=51,		// to client, idUser-> idSubSyn, idTarget-> idTargetSyn
		actionLanding			=52,		// to server only, wing user take off
		actionGetMoney			=53,		// to client only // 捡到500以及500以上钱，只传给自己，dwData为捡到的钱
		actionCancelKeepBow		=54,		// to server, cancel keep_bow status
		actionQueryEnemyInfo	= 55,		// idTarget = enemy id	// to server
		actionMoveStop			=56,		//(作废) to target client, data=milli secs.
		actionKickBack			=57,		// to client	idUser is Player ID, unPosX unPosY is Player pos
		actionDropMagic			=58,		// to client only, data is magic type
		actionDropSkill			=59,		// to client only, data is weapon skill type
		actionSoundEffect		= 60,		// to client only, client play sound effect, dwData is monster type
		actionQueryMedal		=61,		// to server idUser is Player ID, dwData is medal
		actionDelMedal			=62,		// to server idUser is Player ID, dwData is medal
		actionAddMedal			=63,		// to client idUser is Player ID, dwData is medal
		actionQueryHonorTitle	= 65,		// to server idUser is Player ID, dwData is title
		actionDelHonorTitle		=66,		// to server idUser is Player ID, dwData is title
		actionAddHonorTitle		=67,		// to client idUser is Player ID, dwData is title
		actionOpenDialog		=69,		// to client only, open a dialog, dwData is id of dialog
		actionFlashStatus		= 70,		// broadcast to client only, team member only. dwData is dwStatus
		actionQuerySynInfo		=71,		// to server, return CMsgSynInfo. dwData is target syn id.
		actionTakeOff			=72,		// to server only
		actionGetContract		=73,		// 得到玩家的契约信息
		actionGetResearch		=74,		// 得到玩家的研究信息
		actionGetProduction		=75,		// 得到玩家的研究成果信息
		actionFastFly			=76,		//快飞
		actionFloatElectromCannonStatusSwitch = 77, //浮游炮与电磁炮 状态切换		
		actionRunUniverse		=78,	//宇宙快飞
		actionStartBusy			=79,		// 开始忙碌
		actionEndBusy			=80,		// 结束忙碌
		actionAttackModeSwitch = 81,		// 切换攻击方式
		actionShieldLight		=82,		//盾防御光效
		actionUserUplev			=83,		// 机师升级(只显示动画)
		actionQuerySpiritInfo	=84,		// 查询他人机体信息，idTarget为他人玩家ID，idSpirit为他人机体ID
		actionQueryUserEquipment=85,		// 查询他人人物装备
		actionQueryUserInfo		=86,		// 查询他人信息
		actionMarryConditionOK	=87,		// 结婚条件符合,通知客户端
		actionOreIdentOK		=88,		// 矿石鉴定成功,通知客户端
		actionSuperBoss			=89,		// 超大boss，自动回血一次
		actionAdvanceBoss		=90,		// 任务高级boss，打死自动降级
		actionXPIncrease		=91,		// XP值从某值(unPosX)递增到某值(unPosY)，速度是dwData
		actionXPDecrease		=92,		// XP值从某值(unPosX)递减到0，速度是dwData
		actionXPStop			=93,		// XP停在某值(unPosX)上
		actionUseXP				=94,		// 使用xp技
		actionJump4SpiritUpLev	= 95,		// 机体进化系统专用，从进化平台传送出去
		actionMonsterSoundEffect= 96,		// 怪物出身
		actionStopMine			= 97,		// 停止采矿
		actionJumpFly			=98 ,		//服务器->客户端 空中跳跃
		actionQuerySpiritBluePrintInfo	=99,// 查询他人和自己机体设计图信息
		actionQuerySpiritBluePrintEquipment	=100,// to server //idTarget为需要query的PlayerID		
		actionMapBounceParam	=101,		// to client	ZoomPrecent和angle，分别为机体显示的百分比和显示的角度
		actionMapBounce			=102,		// to server to client	弹射到目的地
		actionJumpAttack		=103 ,

		actionShowMeTheWay				=104,		//NPC带路到相应坐标
		actionXPFull					=105 ,// to client XP满状态
		actionOhterUserBattleEffect		=106 ,// to client 查看他人装备时，返回他人总战斗力
		actionMsgBoxReply				=107 ,// to server only
		actionExpballUseEffect			=108 ,// to client only,播放使用经验球光效
		actionQueryChatItemInfo			=109 ,// to server only,查看聊天物品信息
		actionHelpSprit					=118 ,		//顾问精灵客户端事件提示 
		actionSymbolEffect				=119 ,// to Client,共和国徽章光效,
		//(dwData值 0:玩家上线,
		//		  1:pk不掉进经验，
		//		  2:更换机体缩短时间，
		//		  3:红、紫、黑被杀降低惩罚)
		//          4:使用徽章播光效
		actionLottery				    =120, 
		actionFlowerLog			= 121,		//to c 登陆时下发送花系统接受鲜花 idUser:接受者ID,unPosX:今天受到的花束（女）今天可否送花(男），unPosY:所有受到的花束
		actionFlowerSend		= 122,		//to s,to c 送花系统送出鲜花 idUser:送出者id,idSpirit:接受者id,unPosX 最后一次送花距离今天多少天（不为0则需要提示送花）或最后一次收花距离今天多少天(不为0则提示要花):
		actionQueryFamilyInfo	= 123,		// to server, return CMsgFamilyInfo. dwData is target family id.
		actionFreezeTemperature = 124,		// to client,冷冻温度通知		
		actionTeamXPKONotify	= 125,		// 组队XPKO数通知
		actionUserScroll		= 126,		//使用回城卷 使用回城卷的时候，播放个光效 tcp 2007-1-29
		actionEmoneyHint        = 127,      //太阳石领取提示 tcp 2007-1-29
		actionShipJobMapLand_Ready	= 128,	//飞船地图登陆准备, dwData为1表示玩家自己切换地图，idUser为玩家ID，dwData为0表示集体登陆
		actionShipJobMapLand	= 129,		//飞船地图登陆，收集玩家完毕
		actionEmoneyHintEnd     = 130,      //太阳石一次性领取提示，dwData为领取总值
		actionSimpleTeamFaceBegin=131,		//组队界面简化版开始
		actionSimpleTeamFaceEnd	= 132,		//组队界面简化版结束
		actionMyBattleEffectNotify	=133 , // to client 广播自己总战斗力,idUser为玩家ID，dwData为战斗力
		actionFlowerSend_RMB	= 134,		// 2007.03.21 TS, TC 增值花束送花, idUser(送花者ID)，idTarget(对方ID)，idSpirit(花束ID)
		actionWhiteFlowerLog	= 135,		//to c 登陆时下发女性玩家收到的白玫瑰数量 unPosX:今天受到的花束，unPosY:所有受到的花束
		actionRebornGuard		= 136,		// ts  复活侍卫,用元宝,idTarget为侍卫ID
        actionSetHeroPos         =138,      // 英雄冲锋时更新英雄的坐标
		actionAttackMoveSynchroPos=139,		// 攻击动作产生的移动，用于客户端给服务端同步坐标
		
		actionRebornShow		= 140,		// 玩家复活表现

		actionQueryBoothBusInfo	= 180,		// tos 查询摊位商业信息 idNpc unDir: (0=BoothID 1=BoothFlagNpcID)
		actionBoothPurchase		= 181,		// tos 购买 idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX = 0(Person,Syn) unPosY=(用Money,EMoney) 
		actionDropBoothBusiness = 182,		// tos 放弃摊位资产 idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX = 0(Person,Syn) 
		actionFetchIncome		= 183,		// tos 提取收益	idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0=Person 1=Syn  dwData=提取金额
		actionAddDeposit		= 184,		// tos 增加押金 idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0(Person,Syn) unPosY=(用Money,EMoney)(帮派忽略只用money) dwData=钱数
		actionFetchDeposit		= 185,		// tos 提取押金 idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0=Person 1=Syn  dwData:提取金额
		actionKickoutBoother	= 186,		// tos 驱逐 idNpc=BoothNpcID unDir: (0=BoothID)
		actionQueryBoothInvestInfo =187,	// tos 查询摊位投资信息 idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0=Person 1=Syn | toc MsgDataArray
		actionPkCompete			= 189,		// TC PK赛开始广播idUser=无意义, dwData=1周赛，dwData=2月赛	TS 表示客户端决定加入PK赛
		actionShipAtkPowerAnnouce  =190,	// TC,TS飞船返回战斗力广播		
		actionGotoSomeWhere     = 199,      // toc unPosX,unPosY dwData:NextNpcId 2007.2.3 tcp add  action接自动导航功能
		
		// for ai server -----------------------------------------------
		actionSuperChgMap		= 200,		// to game server, data=idMap
		actionFullItem			= 201,		// to game server, data=itemtype
		actionChangeMapDoc		= 202,//no use		// to ai server, idPlayer=idMap, data=idDoc
		actionAddTerrainObj		= 203,		// to ai server, idUser=idMap, data=idOwner, npc_id=idTerrainObj
		actionDelTerrainObj		= 204,		// to ai server, idUser=idMap, data=idOwner
		
		actionCallMonster		= 205,		// to ai server, idUser=monster id, data=idOwner, x y = owner pos;
		actionCloseWithMe		= 206,		// dwData = idMap, x y dir = owner pos
		actionAttackTarget		= 207,		// idTarget, x y = for target
		actionAuto_Exercise		= 208,		// dwData = 0环保练功,
		// dwData = 1继续环保练功,
		// dwData = 2退出环保练功,
		// dwData = 3可用环保练功的时间 
		actionEnableAuto_ExerciseMinutes= 209, // dwData =可以用于环保练功的分钟
		actionMoonGemUse		= 210, // nPosX为0普通月光宝盒，1为加强版本, dwData为装备ID
#ifdef	COPY_MAP
		actionCreateDynaMap		= 211,		// 添加一张地图。怪物生成器立即启动。idUser=idMap, data=mapdoc
		actionDestoryDynaMap	= 212,		// 卸载一张地图。地图内的相关对象自动清除。idUser=idMap
#endif
		actionEnemyStatus		= 215,		// 仇人的状态变化,idTarget=仇人ID,idMap=仇人mapid,unPosX:战斗力变化数值,unPosY防御力变化数值
		actionNewbie_Translate	= 216,		// 15级机体之后一片区传送到太阳片区
		actionClsPKProtectedTime= 217,		// 清除PK保护时间 角色保护时间增加说明文档 tcp2007-1-10 add
		actionCannonShiftProtect= 218,		// 主机体死亡，浮游炮切换过来有5秒保护，dwData=5
		actionCannonDieStaus	= 219,		// 浮游炮死亡通知，idSpirit=为浮游炮ID，dwData=还有多少时间可以复活
		actionCoachTarget		= 220,		// 指导过程,idTarget为目标玩家,unDir=1舰队指导,0普通玩家指导
		
		actionTransformIncrease		= 230,		// 变形量值从某值(unPosX)递增到某值(unPosY)，速度是dwData
		actionTransformDecrease		= 231,		// 变形量值从某值(unPosX)递减到0，速度是dwData
		actionTransformStop			= 232,		// 变形量停在某值(unPosX)上
		actionTransformFull			= 233,		// to client 变形量满状态
		actionBeginTransform		= 234,		// 开始变形, dwData=magicid
		actionCancelTransform		= 235,		// 取消变形, dwData=magicid
		actionBeginTransfer			= 236,		// 传送离开光效
		actionUnburden				= 237,		// 
		actionQuerySynTotemGroup	= 240,		// c2s 查询玩家所在帮派图腾柱信息 idNpc=nPageNo
		actionQuerySynTotemMember	= 241,		// c2s 查询玩家所在帮派某类丰碑中的侍卫成员信息 idTarget=nTypeID, idNpc=nPageNo
		actionSynTotemOpen			= 243,		// 开启侍卫丰碑, idTarget 丰碑nTypeID
		actionSynTotemRobotReg		= 244,		// 登记侍卫
		actionSynTotemRobotUnReg	= 245,		// 注销侍卫
		actionAddTotemBattleLev		= 246,		// 丰碑加持

		actionNpcTransPos		= 300,		// npc服务器通知怪物使用瞬移技能
		actionNpcUseHelpMagic	= 301,		// npc服务器通知怪物使用对同类有益的援助魔法
		actionNpcLockTarget		= 302,		// 炮台锁定目标攻击，idTarget为目标，0为取消
		actionNpcTurn			= 303,		// 炮台转动，nPosX=nChgSort， nPosY=nChgData，dwData=nDelay
		actionMapLand			= 304,		//地图弹射器降落消息
		actionNpcPowerChanged	= 305,		// 炮台攻击力减退
		actionNpcExcuteAction	= 306,		// NPC服务器通知执行ACTION
		actionNpcReached		= 307,		// NPC服务器通知到达目的地
		
		actionNpcStopTurn		= 308,		//炮台停止转动  狙击步枪弱点破坏功能实现 tcp 2007-1-25	
		// dwData = 0取消
		// dwData = 1设置											
		actionNpcStopWork		= 309,		//炮台待机模式  狙击步枪弱点破坏功能实现 tcp 2007-1-25				
		// dwData = 0取消
		// dwData = 1设置	
		
		actionNpcGeneratorCtrl	= 310,		// dwData=generator_id,unDir=0:on    1:off
		//召唤物品系统文档 tcp 2007-2-27 add begin
		actionAskTeamMemeberFly      = 311,	// to C 队长召唤对队友飞到附近     idUser:队员id， idTarget:队长id
		actionTeamMemeberAgreeFly    = 312,	// to S		  队友同意飞到队长附近 idUser:队员id， idTarget:队长id
		actionTeamMemeberDisAgreeFly = 313,	// to S  to C 队友拒绝飞到队长附近 idUser:队员id， idTarget:队长id
		actionTeamMemeberDie         = 314,	// to c 	  队友已经死亡		   idUser:队长id， idTarget:队员id
		//召唤物品系统文档 tcp 2007-2-27 add end
		actionActEmotion			= 315,	// TS TC	2007.03.05 动作表情广播, dwData编号
		actionActEmotionKeep		= 316,	// TC only	2007.03.05 玩家进入某个区域看到其他玩家保持的动作姿态, dwData编号ID
		actionPKBeatbackOK			= 317,	// TS 客户端被击退OK
		actionDestroyObjDie		= 318,		// TONPCSERVER Npc 死亡
		//ACTION控制弹射 mj 2007-08-28
		actionScriptControlBounce   = 319,    //action 控制弹射    
		actionMonsterStatus			= 320,		// to npc server only, idTarget = idSyn. 
		actionBuildStatus			= 321,		// to npc server only, idTarget = idSyn. 
		
		actionChangeNpcType			= 322,		// to npc server only, idTarget = newNpctype. 
		actionSetLife				= 323,		// to npc server only, idTarget = nLife
		actionSetEmplacePower		= 324,		// to npc server only
		actionRelaxStatusChanged	= 325,		// NPC->S->C 怪物休闲状态改变 idUser:怪物ID dwData:休闲状态
		
		actionAbortMagicCast	= 330,	//打断技能引导

		actionLoadDynaMap		= 338,      // to npc idGen:Npc生成器的id idMap:地图
		actionVipLottery        = 360,      // to s, to c, VIP玩家抽奖请求
		
		actionLogout			= 400,		// to s, to c,客户端申请下线, 服务端确认下线
		actionResume			= 401,		// to s,客户端继续游戏
		actionDynaCreateMonster = 402,		// to Npc Server tcp 2007-2-7 矩形区域批量创建多只怪物
		actionNpcStopAttack		= 403,		// to Npc Server 近战连击机制 tcp 2007-4-10 add 怪物处于僵直状态
		actionShowAutoPraticse  = 404,      // to s环保练功
		actionJumpByCtr			= 405 ,		// to s 客户端 空中跳跃	ctr+
		actionQueryUserInfoPlayMoney    = 406,	   // to c to s dwData:钱的数量
		actionDelayOtherRebornTime		   = 407,  // to c dwData延长对手机体复活时间(秒)
		actionDelayOtherRebornByOtherTime  = 408,  // to c dwData:延长对手机体被其它人复活时间(秒)
		actionLockSuccess				   = 409,  // to c 仓库密码设置成功--环保练功场流星升级引导系统
		
		actionReturnAfterLottery           = 411, //to S 抽奖之后返回地图
		
		actionBusinessAccountRegNotify	= 520,		//to c 新建人物首次登录时，服务端下发是否申请为商人号的提示，无参数
		actionBusinessAccountCancel		= 521,		//to s 
		actionBusinessAccountApply		= 522,		//to s 申请开通商人号
		actionBusinessAccountApplyResult= 523,		//to c 申请开通商人号成功
		actionBusinessAccountCancelResult= 524,		//to c actionBusinessAccountCancel成功,iData=0:撤销商人号，iData=1:撤销申请商人号
		actionLoginIP					=600,	//TC 玩家登录信息 idUser[YYMMDDhhmm] idSpirit[上次登录ip] dwData[本次登录ip]
		
		actionStartSuperviseTalk		= 1001,	// ctos GM 请求开始监控聊天信息
		actionEndSuperviseTalk			= 1002,	// ctos GM 请求结束监控聊天信息
		actionDisappear			= 1003,	// 
		actionRideDown			=1004,//
		
		actionDonation			=1005,//TC 爵位捐款信息下发	usTargetPosX[爵位]  usTargetPosY[排名] nPosX[捐献银两总数目低32位] nPosY[捐献银两总数目高32位]
		actionPeerageChange		=1006,//TC 广播消息，当爵位发生改变时广播给周围玩家 idUser[爵位玩家ID] usTargetPosX[旧爵位] usTargetPosY[新爵位]

		actionGodTutorInfo				= 1010,	//TC 导师的神仙传送次数,idUser[导师ID] dwData[0:不可用 1:可用]
		actionGodBack					= 1013,	//TS 回原来地图
		actionGodStay					= 1014,	//TS 不回原来地图
		
		actionSuperiorSortList			= 1020,	//TC 高手排行榜排名 idUser[玩家ID] dwData[玩家排名] 
		actionSuperiorSortList_Top		= 1021,	//TS 查询第10名 第50名高手战斗力
		//TC dwData[第10名高手战斗力] idRobot[第50名高手战斗力]
		
		actionHighLevelMapEnter			= 1030,	//TS 要求进入高级限时练功场	idRobot[]
		//TC 结果 dwData[0:要求通过 1:开放时间已过] idRobot[map id]
		actionHighLevelMapLeftSecs		= 1031,	//TC 练功地图的关闭剩余时间	dwData[seconds]	idRobot[map id]
		actionHighLevelMapInvite		= 1032,	//TC 邀请 idRobot[map id] dwTimeStamp[map doc]
		actionFlowerRecv				= 1035,	// TC 女生收到花 idUser(送花者ID) idTarget(对方ID) idRobot(花束type ID)
		//	  nPosX(法宝影响送花) nPosY(鲜花数量) unDir(0:红玫瑰 1:白玫瑰)
		
		actionActTransform			= 1036,	// TS TC	玩家变身成怪物广播, idMonsterType：怪物id   idMagic：技能id  dwData时间
		actionActTransformKeep		= 1037,	// TC only	2007.03.05 玩家进入某个区域看到其他玩家保持的动作姿态, dwData编号ID
		actionActTransformStop		= 1038,	// TC 
		
		actionWaitInfoOk            = 1052,  //申请等待状态的信息已经发送完毕，通知客户端显示相关界面
		actionMaskTargetVipLev          = 1051,  //用于当一个玩家查询其他玩家装备时是否屏蔽VipLevel
		actionSynAwardTime              = 1054,  //距离下次获得舰队战经验值所剩余的时间

		actionNearOrWarPkCompete	    = 1055,		// TC PK赛开始广播idUser=无意义, 
		actionChangeNpcShape	        = 1057,		// NPC变形 
		actionWaylayUse                 = 1060,		// 使用埋伏技
		actionWaylayCancle              = 1061,		// 取消埋伏技
		actionWayLayFlyOut              = 1062,		// 埋伏技冲出   

		actionFly                       = 1053,  // 展开翅膀飞行
		actionStopFly                   = 1054,  // 停止展开翅膀飞行

		actionMonstrReborn				= 1055,		//怪物带有可重生的特殊属性[2009.8.11]
		actionCreateHostage             = 1055,  //T2C创建人质服务器发下在客户端自己创建；		
		actionHostageCmd				= 1056, //人质的动作		
		actionHostageTalk               = 1066, //人质说的随机话。广播只需要发ID 和 字符串序号		
		actionDestroyHostage            = 1077, // 收回人质		
		actionCreateHostageSucceed      = 1078, //人质创建成功		
		actionHosatageForceRotate       = 1079, 		
		actionBeginDive                 = 1080, //开始潜水		
		actionEndDive                   = 1081, //结束潜水		
		actionDrawAngel		            = 1100, //tc通知客户端打开领取天使的窗口
		actionGetAngel					= 1101, //ts告诉服务端要领取天使
		actionAngelInfo					= 1102, //天使的一些属性信息
		actionSelectAngel				= 1103, //玩家选择的天使
		actionKillMonsterSortQuery      = 1104, //TS 查询杀怪排行
		actionUserInviteTeam			= 1105,	//邀请玩家组队
		actionUserAgreeJoinTeam			= 1106, //玩家同意加入
		actionUserApplyJoinTeam			= 1107, //玩家申请加入队伍
		actionUserRejectJoinTeam		= 1108, //玩家拒绝加入队伍
		actionGetAngelFlush             = 1109, //TS让服务器下发拥有天使的倒计时时间


		// 度气
		actionChangeBreathApply         = 1110, //度气申请
		actionChangeBreathAgreen        = 1111, //同意度气
		actionChangeBreathRefuse        = 1112, //拒绝申请
		actionChangeBreathStop          = 1113, //度气结束
		actionChangeBreathStart         = 1114, //度气开始
		actionChangeBreathMove           = 1115, //度气开始
		
		actionUserFirstFly				= 1200, //玩家爵位从4到五级的时候通知客户端可以飞行了
		actionCallPet                   = 1202, //召唤宠物
		actionDispelPet                 = 1203, //收回宠物
		actionChangeMonsterShape	    = 1205,		// NPC变形 

		actionBeforeMonsterBornEffect	= 1210,	// 怪物出生前的光效
		actionDelBeforeMonsterBornEffect = 1211,//删除怪物出生前的光效，暂时不用，配置里定可能

		actionMonsterIsAI				= 1300, //怪物是否具有AI
		actionTimer                     = 1301,

		actionReachOneStep				= 1302, //平台开始停留（服务端通知客户端）
		actionDelayTimeout				= 1303, //平台结束停留（服务端通知客户端）
		actionEnterPlatform				= 1304, //用户上平台（客户端通知服务端）
		actionLeavePlatform				= 1305, //用户下平台（客户端通知服务端）
        actionAssignAttrPoint           = 1310, //申请分配点数
		actionConvoyNpcArrived			= 1320,	//护送npc到达目的地

		//------------------------ <<僵尸来了>>独有的action (1400 ~ 1600)---------------------
		actionUserTumble                = 1400,           // 玩家按“跑步键" + "空格键" 做翻滚动作
		actionUserClimbOver             = 1401,           // 玩家按“跑步键" + "空格键" 做翻越动作, 在正前方有掩码的条件下
		actionCancelUserTumble          = 1402,           // 翻滚动作检查失败，通知客户端
	    actionCancelUserClimbOver       = 1403,           // 翻越动作检查失败，通知客户端
		actionQueryDetainEquip          = 1404,           // 查询被扣押的装备

		actionTransPos                  = 1405,           // 转移怪物位置
		actionMonsterCreateTrap	        = 1406,			// 怪物被杀死生成陷阱	

		actionUserGo2Coordinate	        = 1407,			// 对玩家输入坐标的相关处理
		actionDelRoleCheck		        = 1409,	        // 删除玩家角色检测仓库密码 TSTC

		actionCriticalHit               = 1410,         // 暴击
		actionTouchLampsSwitch		    = 1411,			// 触发灯具开关
		actionInviteInstance            = 1413,         // 副本邀请

		actionGainBox                    = 1414,         //获得箱子
		actionOpenBox                    = 1415,         //开箱子

		actionMoneyChange                = 1416,         //通过打死怪物或者玩家获得金钱 通知客户端表现
		actionCheckNameFail              = 1417,         //
		actionCheckNameSuc               = 1418,         //
		actionEnterGameHall              = 1419,         //进入游戏大厅

		actionQueryDetailedBattleInfo    = 1421,         //查看详细战斗信息
		actionQueryBattleInfo            = 1422,         //查看简单的战斗信息
	};
	
	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;
		
		union
		{
			U32		dwTimeStamp;
			OBJID		idMonsterType;
		};

		union
		{			
			OBJID		idUser;
			OBJID		idGen;			
		};

		union
		{
			OBJID		idSpirit;
			OBJID		idNpc;
			OBJID		idMap;	
			U32		nAtkPower;
			OBJID		idMagic;
		};

		union
		{
			float nPosX;
			struct  
			{
				USHORT usTumbleStartPosX;  
				USHORT usTumbleStartPosY;      // 翻滚开始位置
			};
			struct  
			{
				USHORT usClimbStartPosX;
				USHORT usClimbStartPosY;       // 翻越开始位置
			};
		};

		union
		{
			float nPosY;
			struct  
			{
				USHORT usTumbleTargetPosX;
				USHORT usTumbleTargetPosY;    // 翻滚目标位置
			};
			struct  
			{
				USHORT usClimbTargetPosX;
				USHORT usClimbTargetPosY;    // 翻越目标位置
			};
		};
		float fPosZ;

		union
		{
			USHORT		unDir;		
			USHORT		nRadio;	
			USHORT      usVipReborn;    //用于PK赛中VIP的原地复活
			BYTE        uMoneyCate;
		};

		union 
		{
			OBJID		idTarget;
			U32		dwData;
			INT			iData;
			bool		bSucDone;
			U32       dwUserSp;             // 玩家体力值 (总值)

			struct 
			{
				BYTE   byGrid;
				BYTE   byMaxPerGen;
				USHORT usDelayTimes;
			};

			struct 
			{
				USHORT usTargetPosX;
				USHORT usTargetPosY;
			};

			struct 
			{
				USHORT usZoomPrecent;
				USHORT usAngle;
			};
		};

		USHORT	usAction;

	} MSG_ACTION;
}
#pragma pack(pop)

#endif

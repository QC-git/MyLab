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
		actionPosition			=2,			//(����) �ʽ�ʹ��
		actionEmotion			=3,
		actionBroadcastPos		=4,
		actionDivorce			= 5,
		actionSelfUnfreeze		=6,
		actionChgMap			=7,			// �������
		actionFlyMap			=8,
		actionChgWeather		=9,
		actionFireworks			= 10,
		actionDie				=11,
		actionQuitSyn			=12,
		actionWalk				=13,		//(����)
		actionEnterMap			=14,		// ��¼��1����֪ͨ�ͻ��˵�¼�ɹ�������Ѿ������ͼ�������! (to client: idUser is Map)
		actionGetItemSet		= 15,		// ��¼��2��
		actionGetGoodFriend		=16,		// ��¼��3��
		actionForward			=17,		//(����) �ʽ�ʹ��
		actionLeaveMap			=18,		// ������->�ͻ���,idPlayer����CMsgPlayer��Ӧ����ʾ����뿪��ͼ��Ҫ��ɾ������
		actionJump				=19,
		actionRun				= 20,		//(����)
		actionEquip				=21,
		actionUnequip			=22,
		actionUplev				=23,		// ��һ�������(ֻ��ʾ����),nPosXΪ����ID
		actionXpCLear			=24,
		actionReborn			= 25,
		actionDelRole			=26,
		actionGetWeaponSkillSet	=27,		// ��¼��4��
		actionGetMagicSet		=28,		// ��¼��5��
		actionSetPkMode			=29,
		actionGetSynAttr		= 30,
		actionGhost				=31,		// ���
		actionSynchro			=32,		// ����ͬ����send to client self, request client broadcast self coord if no synchro; broadcast to other client, set coord of this player
		actionQueryFriendInfo	=33,		// idTarget = friend id
		actionQueryLeaveWord	=34,
		actionChangeFace		= 35,
		actionMine				=36,
		actionTeamMemeberPos	=37,		// to client only, �����´���������
		actionQueryPlayer		=38,
		actionAbordMagic		=39,
		actionMapARGB			= 40,		// to client only
		actionMapStatus			=41,		// to npc server only, idTarget = map id.
		actionQueryTeamMember	=42,		// To server & to client, ��ѯ��������
		actionCreateBooth		=43,		// ��ʼ��̯ to server - unPosX,unPosY: playerpos; unDir:dirofbooth; to client - idTarget:idnpc; 
		actionSuspendBooth		=44,		// �����̯
		actionResumeBooth		= 45,		// ������̯ to server - unPosX,unPosY: playerpos; unDir:dirofbooth; to client - idTarget:idnpc; 
		actionDestroyBooth		=46,		// ֹͣ��̯
		actionQueryCryOut		=47,		// ��ѯ��̯ߺ��
		actionPostCmd			=48,		// to client only
		actionQuerySpiritEquipment	=49,		// to server //idTargetΪ��Ҫquery��PlayerID
		actionAbortTransform	= 50,		// to server
		actionCombineSubSyn		=51,		// to client, idUser-> idSubSyn, idTarget-> idTargetSyn
		actionLanding			=52,		// to server only, wing user take off
		actionGetMoney			=53,		// to client only // ��500�Լ�500����Ǯ��ֻ�����Լ���dwDataΪ�񵽵�Ǯ
		actionCancelKeepBow		=54,		// to server, cancel keep_bow status
		actionQueryEnemyInfo	= 55,		// idTarget = enemy id	// to server
		actionMoveStop			=56,		//(����) to target client, data=milli secs.
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
		actionGetContract		=73,		// �õ���ҵ���Լ��Ϣ
		actionGetResearch		=74,		// �õ���ҵ��о���Ϣ
		actionGetProduction		=75,		// �õ���ҵ��о��ɹ���Ϣ
		actionFastFly			=76,		//���
		actionFloatElectromCannonStatusSwitch = 77, //������������ ״̬�л�		
		actionRunUniverse		=78,	//������
		actionStartBusy			=79,		// ��ʼæµ
		actionEndBusy			=80,		// ����æµ
		actionAttackModeSwitch = 81,		// �л�������ʽ
		actionShieldLight		=82,		//�ܷ�����Ч
		actionUserUplev			=83,		// ��ʦ����(ֻ��ʾ����)
		actionQuerySpiritInfo	=84,		// ��ѯ���˻�����Ϣ��idTargetΪ�������ID��idSpiritΪ���˻���ID
		actionQueryUserEquipment=85,		// ��ѯ��������װ��
		actionQueryUserInfo		=86,		// ��ѯ������Ϣ
		actionMarryConditionOK	=87,		// �����������,֪ͨ�ͻ���
		actionOreIdentOK		=88,		// ��ʯ�����ɹ�,֪ͨ�ͻ���
		actionSuperBoss			=89,		// ����boss���Զ���Ѫһ��
		actionAdvanceBoss		=90,		// ����߼�boss�������Զ�����
		actionXPIncrease		=91,		// XPֵ��ĳֵ(unPosX)������ĳֵ(unPosY)���ٶ���dwData
		actionXPDecrease		=92,		// XPֵ��ĳֵ(unPosX)�ݼ���0���ٶ���dwData
		actionXPStop			=93,		// XPͣ��ĳֵ(unPosX)��
		actionUseXP				=94,		// ʹ��xp��
		actionJump4SpiritUpLev	= 95,		// �������ϵͳר�ã��ӽ���ƽ̨���ͳ�ȥ
		actionMonsterSoundEffect= 96,		// �������
		actionStopMine			= 97,		// ֹͣ�ɿ�
		actionJumpFly			=98 ,		//������->�ͻ��� ������Ծ
		actionQuerySpiritBluePrintInfo	=99,// ��ѯ���˺��Լ��������ͼ��Ϣ
		actionQuerySpiritBluePrintEquipment	=100,// to server //idTargetΪ��Ҫquery��PlayerID		
		actionMapBounceParam	=101,		// to client	ZoomPrecent��angle���ֱ�Ϊ������ʾ�İٷֱȺ���ʾ�ĽǶ�
		actionMapBounce			=102,		// to server to client	���䵽Ŀ�ĵ�
		actionJumpAttack		=103 ,

		actionShowMeTheWay				=104,		//NPC��·����Ӧ����
		actionXPFull					=105 ,// to client XP��״̬
		actionOhterUserBattleEffect		=106 ,// to client �鿴����װ��ʱ������������ս����
		actionMsgBoxReply				=107 ,// to server only
		actionExpballUseEffect			=108 ,// to client only,����ʹ�þ������Ч
		actionQueryChatItemInfo			=109 ,// to server only,�鿴������Ʒ��Ϣ
		actionHelpSprit					=118 ,		//���ʾ���ͻ����¼���ʾ 
		actionSymbolEffect				=119 ,// to Client,���͹����¹�Ч,
		//(dwDataֵ 0:�������,
		//		  1:pk���������飬
		//		  2:������������ʱ�䣬
		//		  3:�졢�ϡ��ڱ�ɱ���ͳͷ�)
		//          4:ʹ�û��²���Ч
		actionLottery				    =120, 
		actionFlowerLog			= 121,		//to c ��½ʱ�·��ͻ�ϵͳ�����ʻ� idUser:������ID,unPosX:�����ܵ��Ļ�����Ů������ɷ��ͻ�(�У���unPosY:�����ܵ��Ļ���
		actionFlowerSend		= 122,		//to s,to c �ͻ�ϵͳ�ͳ��ʻ� idUser:�ͳ���id,idSpirit:������id,unPosX ���һ���ͻ������������죨��Ϊ0����Ҫ��ʾ�ͻ��������һ���ջ�������������(��Ϊ0����ʾҪ��):
		actionQueryFamilyInfo	= 123,		// to server, return CMsgFamilyInfo. dwData is target family id.
		actionFreezeTemperature = 124,		// to client,�䶳�¶�֪ͨ		
		actionTeamXPKONotify	= 125,		// ���XPKO��֪ͨ
		actionUserScroll		= 126,		//ʹ�ûسǾ� ʹ�ûسǾ��ʱ�򣬲��Ÿ���Ч tcp 2007-1-29
		actionEmoneyHint        = 127,      //̫��ʯ��ȡ��ʾ tcp 2007-1-29
		actionShipJobMapLand_Ready	= 128,	//�ɴ���ͼ��½׼��, dwDataΪ1��ʾ����Լ��л���ͼ��idUserΪ���ID��dwDataΪ0��ʾ�����½
		actionShipJobMapLand	= 129,		//�ɴ���ͼ��½���ռ�������
		actionEmoneyHintEnd     = 130,      //̫��ʯһ������ȡ��ʾ��dwDataΪ��ȡ��ֵ
		actionSimpleTeamFaceBegin=131,		//��ӽ���򻯰濪ʼ
		actionSimpleTeamFaceEnd	= 132,		//��ӽ���򻯰����
		actionMyBattleEffectNotify	=133 , // to client �㲥�Լ���ս����,idUserΪ���ID��dwDataΪս����
		actionFlowerSend_RMB	= 134,		// 2007.03.21 TS, TC ��ֵ�����ͻ�, idUser(�ͻ���ID)��idTarget(�Է�ID)��idSpirit(����ID)
		actionWhiteFlowerLog	= 135,		//to c ��½ʱ�·�Ů������յ��İ�õ������ unPosX:�����ܵ��Ļ�����unPosY:�����ܵ��Ļ���
		actionRebornGuard		= 136,		// ts  ��������,��Ԫ��,idTargetΪ����ID
        actionSetHeroPos         =138,      // Ӣ�۳��ʱ����Ӣ�۵�����
		actionAttackMoveSynchroPos=139,		// ���������������ƶ������ڿͻ��˸������ͬ������
		
		actionRebornShow		= 140,		// ��Ҹ������

		actionQueryBoothBusInfo	= 180,		// tos ��ѯ̯λ��ҵ��Ϣ idNpc unDir: (0=BoothID 1=BoothFlagNpcID)
		actionBoothPurchase		= 181,		// tos ���� idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX = 0(Person,Syn) unPosY=(��Money,EMoney) 
		actionDropBoothBusiness = 182,		// tos ����̯λ�ʲ� idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX = 0(Person,Syn) 
		actionFetchIncome		= 183,		// tos ��ȡ����	idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0=Person 1=Syn  dwData=��ȡ���
		actionAddDeposit		= 184,		// tos ����Ѻ�� idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0(Person,Syn) unPosY=(��Money,EMoney)(���ɺ���ֻ��money) dwData=Ǯ��
		actionFetchDeposit		= 185,		// tos ��ȡѺ�� idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0=Person 1=Syn  dwData:��ȡ���
		actionKickoutBoother	= 186,		// tos ���� idNpc=BoothNpcID unDir: (0=BoothID)
		actionQueryBoothInvestInfo =187,	// tos ��ѯ̯λͶ����Ϣ idNpc unDir: (0=BoothID 1=BoothFlagNpcID) unPosX: 0=Person 1=Syn | toc MsgDataArray
		actionPkCompete			= 189,		// TC PK����ʼ�㲥idUser=������, dwData=1������dwData=2����	TS ��ʾ�ͻ��˾�������PK��
		actionShipAtkPowerAnnouce  =190,	// TC,TS�ɴ�����ս�����㲥		
		actionGotoSomeWhere     = 199,      // toc unPosX,unPosY dwData:NextNpcId 2007.2.3 tcp add  action���Զ���������
		
		// for ai server -----------------------------------------------
		actionSuperChgMap		= 200,		// to game server, data=idMap
		actionFullItem			= 201,		// to game server, data=itemtype
		actionChangeMapDoc		= 202,//no use		// to ai server, idPlayer=idMap, data=idDoc
		actionAddTerrainObj		= 203,		// to ai server, idUser=idMap, data=idOwner, npc_id=idTerrainObj
		actionDelTerrainObj		= 204,		// to ai server, idUser=idMap, data=idOwner
		
		actionCallMonster		= 205,		// to ai server, idUser=monster id, data=idOwner, x y = owner pos;
		actionCloseWithMe		= 206,		// dwData = idMap, x y dir = owner pos
		actionAttackTarget		= 207,		// idTarget, x y = for target
		actionAuto_Exercise		= 208,		// dwData = 0��������,
		// dwData = 1������������,
		// dwData = 2�˳���������,
		// dwData = 3���û���������ʱ�� 
		actionEnableAuto_ExerciseMinutes= 209, // dwData =�������ڻ��������ķ���
		actionMoonGemUse		= 210, // nPosXΪ0��ͨ�¹ⱦ�У�1Ϊ��ǿ�汾, dwDataΪװ��ID
#ifdef	COPY_MAP
		actionCreateDynaMap		= 211,		// ���һ�ŵ�ͼ����������������������idUser=idMap, data=mapdoc
		actionDestoryDynaMap	= 212,		// ж��һ�ŵ�ͼ����ͼ�ڵ���ض����Զ������idUser=idMap
#endif
		actionEnemyStatus		= 215,		// ���˵�״̬�仯,idTarget=����ID,idMap=����mapid,unPosX:ս�����仯��ֵ,unPosY�������仯��ֵ
		actionNewbie_Translate	= 216,		// 15������֮��һƬ�����͵�̫��Ƭ��
		actionClsPKProtectedTime= 217,		// ���PK����ʱ�� ��ɫ����ʱ������˵���ĵ� tcp2007-1-10 add
		actionCannonShiftProtect= 218,		// �������������������л�������5�뱣����dwData=5
		actionCannonDieStaus	= 219,		// ����������֪ͨ��idSpirit=Ϊ������ID��dwData=���ж���ʱ����Ը���
		actionCoachTarget		= 220,		// ָ������,idTargetΪĿ�����,unDir=1����ָ��,0��ͨ���ָ��
		
		actionTransformIncrease		= 230,		// ������ֵ��ĳֵ(unPosX)������ĳֵ(unPosY)���ٶ���dwData
		actionTransformDecrease		= 231,		// ������ֵ��ĳֵ(unPosX)�ݼ���0���ٶ���dwData
		actionTransformStop			= 232,		// ������ͣ��ĳֵ(unPosX)��
		actionTransformFull			= 233,		// to client ��������״̬
		actionBeginTransform		= 234,		// ��ʼ����, dwData=magicid
		actionCancelTransform		= 235,		// ȡ������, dwData=magicid
		actionBeginTransfer			= 236,		// �����뿪��Ч
		actionUnburden				= 237,		// 
		actionQuerySynTotemGroup	= 240,		// c2s ��ѯ������ڰ���ͼ������Ϣ idNpc=nPageNo
		actionQuerySynTotemMember	= 241,		// c2s ��ѯ������ڰ���ĳ��ᱮ�е�������Ա��Ϣ idTarget=nTypeID, idNpc=nPageNo
		actionSynTotemOpen			= 243,		// ���������ᱮ, idTarget �ᱮnTypeID
		actionSynTotemRobotReg		= 244,		// �Ǽ�����
		actionSynTotemRobotUnReg	= 245,		// ע������
		actionAddTotemBattleLev		= 246,		// �ᱮ�ӳ�

		actionNpcTransPos		= 300,		// npc������֪ͨ����ʹ��˲�Ƽ���
		actionNpcUseHelpMagic	= 301,		// npc������֪ͨ����ʹ�ö�ͬ�������Ԯ��ħ��
		actionNpcLockTarget		= 302,		// ��̨����Ŀ�깥����idTargetΪĿ�꣬0Ϊȡ��
		actionNpcTurn			= 303,		// ��̨ת����nPosX=nChgSort�� nPosY=nChgData��dwData=nDelay
		actionMapLand			= 304,		//��ͼ������������Ϣ
		actionNpcPowerChanged	= 305,		// ��̨����������
		actionNpcExcuteAction	= 306,		// NPC������ִ֪ͨ��ACTION
		actionNpcReached		= 307,		// NPC������֪ͨ����Ŀ�ĵ�
		
		actionNpcStopTurn		= 308,		//��ֹ̨ͣת��  �ѻ���ǹ�����ƻ�����ʵ�� tcp 2007-1-25	
		// dwData = 0ȡ��
		// dwData = 1����											
		actionNpcStopWork		= 309,		//��̨����ģʽ  �ѻ���ǹ�����ƻ�����ʵ�� tcp 2007-1-25				
		// dwData = 0ȡ��
		// dwData = 1����	
		
		actionNpcGeneratorCtrl	= 310,		// dwData=generator_id,unDir=0:on    1:off
		//�ٻ���Ʒϵͳ�ĵ� tcp 2007-2-27 add begin
		actionAskTeamMemeberFly      = 311,	// to C �ӳ��ٻ��Զ��ѷɵ�����     idUser:��Աid�� idTarget:�ӳ�id
		actionTeamMemeberAgreeFly    = 312,	// to S		  ����ͬ��ɵ��ӳ����� idUser:��Աid�� idTarget:�ӳ�id
		actionTeamMemeberDisAgreeFly = 313,	// to S  to C ���Ѿܾ��ɵ��ӳ����� idUser:��Աid�� idTarget:�ӳ�id
		actionTeamMemeberDie         = 314,	// to c 	  �����Ѿ�����		   idUser:�ӳ�id�� idTarget:��Աid
		//�ٻ���Ʒϵͳ�ĵ� tcp 2007-2-27 add end
		actionActEmotion			= 315,	// TS TC	2007.03.05 ��������㲥, dwData���
		actionActEmotionKeep		= 316,	// TC only	2007.03.05 ��ҽ���ĳ�����򿴵�������ұ��ֵĶ�����̬, dwData���ID
		actionPKBeatbackOK			= 317,	// TS �ͻ��˱�����OK
		actionDestroyObjDie		= 318,		// TONPCSERVER Npc ����
		//ACTION���Ƶ��� mj 2007-08-28
		actionScriptControlBounce   = 319,    //action ���Ƶ���    
		actionMonsterStatus			= 320,		// to npc server only, idTarget = idSyn. 
		actionBuildStatus			= 321,		// to npc server only, idTarget = idSyn. 
		
		actionChangeNpcType			= 322,		// to npc server only, idTarget = newNpctype. 
		actionSetLife				= 323,		// to npc server only, idTarget = nLife
		actionSetEmplacePower		= 324,		// to npc server only
		actionRelaxStatusChanged	= 325,		// NPC->S->C ��������״̬�ı� idUser:����ID dwData:����״̬
		
		actionAbortMagicCast	= 330,	//��ϼ�������

		actionLoadDynaMap		= 338,      // to npc idGen:Npc��������id idMap:��ͼ
		actionVipLottery        = 360,      // to s, to c, VIP��ҳ齱����
		
		actionLogout			= 400,		// to s, to c,�ͻ�����������, �����ȷ������
		actionResume			= 401,		// to s,�ͻ��˼�����Ϸ
		actionDynaCreateMonster = 402,		// to Npc Server tcp 2007-2-7 ������������������ֻ����
		actionNpcStopAttack		= 403,		// to Npc Server ��ս�������� tcp 2007-4-10 add ���ﴦ�ڽ�ֱ״̬
		actionShowAutoPraticse  = 404,      // to s��������
		actionJumpByCtr			= 405 ,		// to s �ͻ��� ������Ծ	ctr+
		actionQueryUserInfoPlayMoney    = 406,	   // to c to s dwData:Ǯ������
		actionDelayOtherRebornTime		   = 407,  // to c dwData�ӳ����ֻ��帴��ʱ��(��)
		actionDelayOtherRebornByOtherTime  = 408,  // to c dwData:�ӳ����ֻ��屻�����˸���ʱ��(��)
		actionLockSuccess				   = 409,  // to c �ֿ��������óɹ�--����������������������ϵͳ
		
		actionReturnAfterLottery           = 411, //to S �齱֮�󷵻ص�ͼ
		
		actionBusinessAccountRegNotify	= 520,		//to c �½������״ε�¼ʱ��������·��Ƿ�����Ϊ���˺ŵ���ʾ���޲���
		actionBusinessAccountCancel		= 521,		//to s 
		actionBusinessAccountApply		= 522,		//to s ���뿪ͨ���˺�
		actionBusinessAccountApplyResult= 523,		//to c ���뿪ͨ���˺ųɹ�
		actionBusinessAccountCancelResult= 524,		//to c actionBusinessAccountCancel�ɹ�,iData=0:�������˺ţ�iData=1:�����������˺�
		actionLoginIP					=600,	//TC ��ҵ�¼��Ϣ idUser[YYMMDDhhmm] idSpirit[�ϴε�¼ip] dwData[���ε�¼ip]
		
		actionStartSuperviseTalk		= 1001,	// ctos GM ����ʼ���������Ϣ
		actionEndSuperviseTalk			= 1002,	// ctos GM ����������������Ϣ
		actionDisappear			= 1003,	// 
		actionRideDown			=1004,//
		
		actionDonation			=1005,//TC ��λ�����Ϣ�·�	usTargetPosX[��λ]  usTargetPosY[����] nPosX[������������Ŀ��32λ] nPosY[������������Ŀ��32λ]
		actionPeerageChange		=1006,//TC �㲥��Ϣ������λ�����ı�ʱ�㲥����Χ��� idUser[��λ���ID] usTargetPosX[�ɾ�λ] usTargetPosY[�¾�λ]

		actionGodTutorInfo				= 1010,	//TC ��ʦ�����ɴ��ʹ���,idUser[��ʦID] dwData[0:������ 1:����]
		actionGodBack					= 1013,	//TS ��ԭ����ͼ
		actionGodStay					= 1014,	//TS ����ԭ����ͼ
		
		actionSuperiorSortList			= 1020,	//TC �������а����� idUser[���ID] dwData[�������] 
		actionSuperiorSortList_Top		= 1021,	//TS ��ѯ��10�� ��50������ս����
		//TC dwData[��10������ս����] idRobot[��50������ս����]
		
		actionHighLevelMapEnter			= 1030,	//TS Ҫ�����߼���ʱ������	idRobot[]
		//TC ��� dwData[0:Ҫ��ͨ�� 1:����ʱ���ѹ�] idRobot[map id]
		actionHighLevelMapLeftSecs		= 1031,	//TC ������ͼ�Ĺر�ʣ��ʱ��	dwData[seconds]	idRobot[map id]
		actionHighLevelMapInvite		= 1032,	//TC ���� idRobot[map id] dwTimeStamp[map doc]
		actionFlowerRecv				= 1035,	// TC Ů���յ��� idUser(�ͻ���ID) idTarget(�Է�ID) idRobot(����type ID)
		//	  nPosX(����Ӱ���ͻ�) nPosY(�ʻ�����) unDir(0:��õ�� 1:��õ��)
		
		actionActTransform			= 1036,	// TS TC	��ұ���ɹ���㲥, idMonsterType������id   idMagic������id  dwDataʱ��
		actionActTransformKeep		= 1037,	// TC only	2007.03.05 ��ҽ���ĳ�����򿴵�������ұ��ֵĶ�����̬, dwData���ID
		actionActTransformStop		= 1038,	// TC 
		
		actionWaitInfoOk            = 1052,  //����ȴ�״̬����Ϣ�Ѿ�������ϣ�֪ͨ�ͻ�����ʾ��ؽ���
		actionMaskTargetVipLev          = 1051,  //���ڵ�һ����Ҳ�ѯ�������װ��ʱ�Ƿ�����VipLevel
		actionSynAwardTime              = 1054,  //�����´λ�ý���ս����ֵ��ʣ���ʱ��

		actionNearOrWarPkCompete	    = 1055,		// TC PK����ʼ�㲥idUser=������, 
		actionChangeNpcShape	        = 1057,		// NPC���� 
		actionWaylayUse                 = 1060,		// ʹ�������
		actionWaylayCancle              = 1061,		// ȡ�������
		actionWayLayFlyOut              = 1062,		// ��������   

		actionFly                       = 1053,  // չ��������
		actionStopFly                   = 1054,  // ֹͣչ��������

		actionMonstrReborn				= 1055,		//������п���������������[2009.8.11]
		actionCreateHostage             = 1055,  //T2C�������ʷ����������ڿͻ����Լ�������		
		actionHostageCmd				= 1056, //���ʵĶ���		
		actionHostageTalk               = 1066, //����˵����������㲥ֻ��Ҫ��ID �� �ַ������		
		actionDestroyHostage            = 1077, // �ջ�����		
		actionCreateHostageSucceed      = 1078, //���ʴ����ɹ�		
		actionHosatageForceRotate       = 1079, 		
		actionBeginDive                 = 1080, //��ʼǱˮ		
		actionEndDive                   = 1081, //����Ǳˮ		
		actionDrawAngel		            = 1100, //tc֪ͨ�ͻ��˴���ȡ��ʹ�Ĵ���
		actionGetAngel					= 1101, //ts���߷����Ҫ��ȡ��ʹ
		actionAngelInfo					= 1102, //��ʹ��һЩ������Ϣ
		actionSelectAngel				= 1103, //���ѡ�����ʹ
		actionKillMonsterSortQuery      = 1104, //TS ��ѯɱ������
		actionUserInviteTeam			= 1105,	//����������
		actionUserAgreeJoinTeam			= 1106, //���ͬ�����
		actionUserApplyJoinTeam			= 1107, //�������������
		actionUserRejectJoinTeam		= 1108, //��Ҿܾ��������
		actionGetAngelFlush             = 1109, //TS�÷������·�ӵ����ʹ�ĵ���ʱʱ��


		// ����
		actionChangeBreathApply         = 1110, //��������
		actionChangeBreathAgreen        = 1111, //ͬ�����
		actionChangeBreathRefuse        = 1112, //�ܾ�����
		actionChangeBreathStop          = 1113, //��������
		actionChangeBreathStart         = 1114, //������ʼ
		actionChangeBreathMove           = 1115, //������ʼ
		
		actionUserFirstFly				= 1200, //��Ҿ�λ��4���弶��ʱ��֪ͨ�ͻ��˿��Է�����
		actionCallPet                   = 1202, //�ٻ�����
		actionDispelPet                 = 1203, //�ջس���
		actionChangeMonsterShape	    = 1205,		// NPC���� 

		actionBeforeMonsterBornEffect	= 1210,	// �������ǰ�Ĺ�Ч
		actionDelBeforeMonsterBornEffect = 1211,//ɾ���������ǰ�Ĺ�Ч����ʱ���ã������ﶨ����

		actionMonsterIsAI				= 1300, //�����Ƿ����AI
		actionTimer                     = 1301,

		actionReachOneStep				= 1302, //ƽ̨��ʼͣ���������֪ͨ�ͻ��ˣ�
		actionDelayTimeout				= 1303, //ƽ̨����ͣ���������֪ͨ�ͻ��ˣ�
		actionEnterPlatform				= 1304, //�û���ƽ̨���ͻ���֪ͨ����ˣ�
		actionLeavePlatform				= 1305, //�û���ƽ̨���ͻ���֪ͨ����ˣ�
        actionAssignAttrPoint           = 1310, //����������
		actionConvoyNpcArrived			= 1320,	//����npc����Ŀ�ĵ�

		//------------------------ <<��ʬ����>>���е�action (1400 ~ 1600)---------------------
		actionUserTumble                = 1400,           // ��Ұ����ܲ���" + "�ո��" ����������
		actionUserClimbOver             = 1401,           // ��Ұ����ܲ���" + "�ո��" ����Խ����, ����ǰ���������������
		actionCancelUserTumble          = 1402,           // �����������ʧ�ܣ�֪ͨ�ͻ���
	    actionCancelUserClimbOver       = 1403,           // ��Խ�������ʧ�ܣ�֪ͨ�ͻ���
		actionQueryDetainEquip          = 1404,           // ��ѯ����Ѻ��װ��

		actionTransPos                  = 1405,           // ת�ƹ���λ��
		actionMonsterCreateTrap	        = 1406,			// ���ﱻɱ����������	

		actionUserGo2Coordinate	        = 1407,			// ����������������ش���
		actionDelRoleCheck		        = 1409,	        // ɾ����ҽ�ɫ���ֿ����� TSTC

		actionCriticalHit               = 1410,         // ����
		actionTouchLampsSwitch		    = 1411,			// �����ƾ߿���
		actionInviteInstance            = 1413,         // ��������

		actionGainBox                    = 1414,         //�������
		actionOpenBox                    = 1415,         //������

		actionMoneyChange                = 1416,         //ͨ���������������һ�ý�Ǯ ֪ͨ�ͻ��˱���
		actionCheckNameFail              = 1417,         //
		actionCheckNameSuc               = 1418,         //
		actionEnterGameHall              = 1419,         //������Ϸ����

		actionQueryDetailedBattleInfo    = 1421,         //�鿴��ϸս����Ϣ
		actionQueryBattleInfo            = 1422,         //�鿴�򵥵�ս����Ϣ
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
				USHORT usTumbleStartPosY;      // ������ʼλ��
			};
			struct  
			{
				USHORT usClimbStartPosX;
				USHORT usClimbStartPosY;       // ��Խ��ʼλ��
			};
		};

		union
		{
			float nPosY;
			struct  
			{
				USHORT usTumbleTargetPosX;
				USHORT usTumbleTargetPosY;    // ����Ŀ��λ��
			};
			struct  
			{
				USHORT usClimbTargetPosX;
				USHORT usClimbTargetPosY;    // ��ԽĿ��λ��
			};
		};
		float fPosZ;

		union
		{
			USHORT		unDir;		
			USHORT		nRadio;	
			USHORT      usVipReborn;    //����PK����VIP��ԭ�ظ���
			BYTE        uMoneyCate;
		};

		union 
		{
			OBJID		idTarget;
			U32		dwData;
			INT			iData;
			bool		bSucDone;
			U32       dwUserSp;             // �������ֵ (��ֵ)

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

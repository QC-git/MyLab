////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2008, TQ Digital Entertainment, All Rights Reserved
// Author:  zhuang zhijie
// Created: 2008/03/12
////////////////////////////////////////////////////////////////////////

#ifndef _EXP_IPROVIDER_H_
#define _EXP_IPROVIDER_H_

#include "IBaseProvider.h"

NAMESPACE_BEGIN(entityex)

class IProvider : public adapter::IBaseProvider
{
	DELETE_DISABLED(IProvider)
public:
	virtual int				GetMaxLevel(int nType) const																= 0;
	virtual int				GetUserMaxLevel(OBJID idUser) const															= 0;
//	virtual int				GetSpiritMaxLevel(OBJID idSpirit) const														= 0;
	virtual bool			IsUserLevupexpExist(OBJID idUser, int nLev)													= 0;
//	virtual bool			IsSpiritLevupexpExist(OBJID idSpirit, int nLev)												= 0;
	// 获取升级经验数据
	virtual I64				GetUserLevExpData(OBJID idUser, int nLev, LEVUPEXPDATA eType)								= 0;
//	virtual I64				GetSpiritLevExpData(OBJID idSpirit, int nLev, LEVUPEXPDATA eType)							= 0;
	virtual I64				GetUserLevExpData(OBJID idUser, LEVUPEXPDATA eType)											= 0;
//	virtual I64				GetSpiritLevExpData(OBJID idSpirit, LEVUPEXPDATA eType)										= 0;
//	virtual double			GetSpiritExpEndPercent(OBJID idSpirit)														= 0;
	virtual I64				GetAddExp(I64 n64BeginExp, int nBeginLev, OBJID idUser)						                = 0;
	virtual I64				GetAddExp(I64 n64BeginExp, int nBeginLev, OBJID idUser, I64 n64CurrentExp, int nCurrentLev, int nTarget = 0) = 0;
//	virtual void			UpSpiritLevel(OBJID idSpirit, int nIncLev, bool bAdjSpiritSkillExpFlag = false)				= 0;
	virtual void			UpUserLevel(OBJID idUser, int nIncLev, bool bUserLevMaxLimit = true)						= 0;
	virtual void			UpUserFlatLevel(OBJID idUser, int nIncLev, bool bUserLevMaxLimit = true)	    			= 0;
	virtual double			Exp2Uplevtime(OBJID idUser, I64 n64Exp)				                 						= 0;
	virtual I64				UpLevtime2UserExp(I64 n64UpLevtime, OBJID idUser)											= 0;
	// 经验时间升级的计算
	virtual bool			CalcRoleUpLev(OBJID idUser, double dTimeOffer, int& nNewLevel, double& dEndPencentage, bool& bNineLimit, int& nInsightLev, int nCalcNewUserLev = 0, bool bCalRebornCnt = true, bool bUserLevMaxLimit = true, bool bForbidWallowFlag = true, bool bExpBallOrPractise = false) = 0;
	// 提升 User 或者 Spirit 等级并设置经验百分比，nTarget 为 1 表示为 Spirit，nTarget 为 0 表示为 User
	virtual void			ActionAwardExpTimeOffer(OBJID idUser, int nNewLevel, double nEndPencentage, int nInsightLev) = 0;
	// 加经验 n64Exp
//	virtual void			AwardSpiritExp(OBJID idSpirit, I64 n64Exp, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE, bool bGetByFightFlag = false) = 0;
	virtual void			AwardUserExp(OBJID idUser, I64 n64Exp, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)				= 0;
	virtual void			AwardUserExpEx(OBJID idUser, I64 n64Exp, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)				= 0;
	virtual void			AwardUserFlatExp(OBJID idUser, I64 n64Exp, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)			= 0;
	virtual I64				UpdateUserExp(OBJID idUser, OBJID idTarget, I64 n64Exp, int nTargetLifeLost, bool bXp, SYNCHRO_ENUM bSynchro) = 0;
	virtual I64				AdjustUserExp(OBJID idUser, OBJID idTarget, I64 n64RawExp, bool bKill = false, bool bXp = false) = 0;
//	virtual I64				AdjustSpiritExpAgain(OBJID idSpirit, I64 n64Exp, bool bKill, bool bXp = false, bool bTeam = false) = 0;
	virtual int				GetUserTrumpExpAdjust(OBJID idUser)															= 0;
	virtual bool			AwardUserBattleExp(OBJID idUser, I64 n64Exp, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE) = 0;
	virtual I64				AdjustUserExpFinal(OBJID idUser, I64 n64Exp)												= 0;
	virtual void			ShareUserBattleExp(OBJID idUser, I64 n64Exp, SYNCHRO_ENUM bSynchro)	= 0;
	virtual	I64				AdjustBattleExpInTrain(OBJID idUser, I64 n64Exp)											= 0;
	virtual void			BeKillDropUserExp(OBJID idUser, bool bMonsterKill, bool bSwearBrotherKill)					= 0;
	virtual bool			GetUserExpRuleInStoneMap(OBJID idUser, UINT& dwLevupKillMonster, I64& n64LevupExp)			= 0;
//	virtual I64				AdjustSpiritExpByReborn(OBJID idSpirit, I64 n64Exp, OBJID idRobotOffer)						= 0;
//	virtual I64				CalcSpiritExpDiff(OBJID idSpirit, int nOldLev, I64 n64OldExp)								= 0;
	virtual I64				AdjustUserExpTeamXP(OBJID idUser, I64 n64Exp)												= 0;
	virtual void			FlushAllUserExp2Client(OBJID idUser)														= 0;
	virtual void			SendFriendShareExp(OBJID idUser)															= 0;
	virtual void			FriendShareExpRestart(OBJID idUser, FRIEND_SHARED_TYPE eShareType = _SHARE_OTHER)			= 0;
	virtual void			AddFriendShareExp(OBJID idUser, OBJID idFriend, I64 n64Exp, int nTarget = 0, bool bUser = true) = 0;
	virtual void			FriendShareExpAddUplevtime(OBJID idUser, int nUplevtime, bool bReset = false, FRIEND_SHARED_TYPE eShareType = _SHARE_OTHER) = 0;
	virtual I64				TakeOutFriendUplevtime(OBJID idUser)														= 0;
	virtual I64				QueryFriendUplevtime(OBJID idUser)															= 0;
	virtual void			SendMsg(OBJID idUser, tq::CMsg& rMsg)														= 0;
	virtual bool			ActionAwardUplevtimeEx(OBJID idUser, int nType, double dbTimeOffer, bool bCalRebornCnt)		= 0;
//	virtual bool			AwardDevilExp(OBJID idUser, OBJID idDevil, I64 n64Value, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)= 0;
	virtual I64				GetLevExpData(int nLev, int nExpType, LEVUPEXPDATA eType)									= 0;


	virtual bool            UpdateUserExp(OBJID idUser, OBJID idTarget, bool bKill, int nTargetLifeLost, int nAdjustExp) = 0;
    virtual int             GetBeKillExp(OBJID idUser) = 0;
};

NAMESPACE_END(entityex)

#endif // end of define _EXP_IPROVIDER_H_

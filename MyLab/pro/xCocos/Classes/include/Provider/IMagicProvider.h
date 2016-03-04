// -*- C++ -*-

//=============================================================================
/**
 *  @file    IMagicProvider.h
 *
 *  $Id: IMagicProvider.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================


#ifndef _MAGIC_IPROVIDER_H_
#define _MAGIC_IPROVIDER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IBaseProvider.h"
//#include "../../Magic/src/msg/msginteract.h"

NAMESPACE_BEGIN(entityex)

class IProvider : public adapter::IBaseProvider
{	
	DELETE_DISABLED(IProvider)
public:
	//QueryID
	virtual OBJID	GetSkillAmmoTypeID(OBJID idSpirit, OBJID idSkill)		= 0;
	virtual OBJID	GetSkillMineTypeID(OBJID idSpirit, OBJID idSkill)		= 0;
	virtual OBJID	GetAutoMagicID(OBJID idSpirit)		= 0;

	virtual OBJID	QueryUserMagicID(OBJID idUser, int nMagicSort)		= 0;
//	virtual OBJID	QuerySpiritMagicID(OBJID idSpirit, int nMagicSort)		= 0;

	virtual OBJID	QueryMagicType(int nType, int nLevel)		= 0;
	virtual OBJID	GetSkillSuidByWeaponTypeID(OBJID idSpirit, int nWeaponType)		= 0;
	virtual bool	QuerySkillInfoBySort(OBJID idRole, int nSkillType, SkillSuitData& rSkillInfo)		= 0;
	virtual bool	QuerySkillInfoByMain(OBJID idRole, int nSkillMain, SkillSuitData& rSkillInfo)		= 0;

	virtual OBJID	QueryMonsterMagicID(OBJID idUser, OBJID idSkillSuit)=0;

	virtual bool	DelDomainInfo(OBJID idUser, OBJID idDomain)=0;
	//Create || Init || Uint 
	virtual bool	CreateSpiritMagic(OBJID idSpirit)		= 0;
//	virtual bool	InitSpiritMagic(OBJID idSpirit, int nDbLoadMagicIndex, int nDbLoadSkillIndex, bool bLogin = true)		= 0;
	virtual bool	InitUserMagic(OBJID idUser, int nDbLoadMagicIndex, int nDbLoadSkillIndex, bool bLogin = true)		= 0;
	virtual bool	InitLifeSkill(OBJID idUser, int nDbLoadIndex, bool bLogin = true)		= 0;
//	virtual bool	ReinitSpiritSkillsuit(OBJID idSpirit)		= 0;
	virtual bool	DelSkillSuit(OBJID idSpirit, OBJID idSkillSuit)		= 0;

	virtual bool	IsRoleSkillSuitExist(OBJID idRole, OBJID idSkillSuit)		= 0;

	virtual bool	CalcUpMagicLevSkill(OBJID idUser, float fTimeOfferd, int nSkillType, int& nNewLevel, double& nEndPencentage)		= 0;

	//get || set 
	virtual I64		GetUserMagicData(OBJID idUser, OBJID idMagic, MAGICDATA eMagicData)		= 0;
	virtual I64		GetMagicTypeData(OBJID idMagicType, MAGICTYPEDATA eMagicTypeData)		= 0;
	virtual int		GetUserSkillLev(OBJID idSpirit, OBJID idSkill, int nIndex)		= 0;
	virtual int		GetUserSkillType(OBJID idSpirit, OBJID idSkill, int nIndex)		= 0;
	virtual const char*	GetMagicTypeStr(OBJID idMagicType, MAGICTYPEDATA eMagicTypeData)		= 0;
	
	virtual int		GetUserSkillInt(OBJID idRole, OBJID idSkill, SKILLSUIT idx)		= 0;
	virtual bool	SetSkillSuitInt(OBJID idSpirit, OBJID idSkill, SKILLSUIT idx, int nData)		= 0;
	
	virtual bool	SetSkillSuitData(OBJID idSpirit, OBJID idSkill, SKILLDATA idx, I64 n64Data)		= 0;
	virtual I64		GetUserSkillData(OBJID idSpirit, OBJID idSkill, SKILLDATA eSkillData)		= 0;
	virtual int		GetMagicLevelByType(OBJID idRole, OBJID idMagicType, int& nMagicLevel)		= 0;
	virtual int		GetSkillSuitDataByType( OBJID idRole, OBJID idMagicType, SKILLSUIT eSkillSuitType)		= 0;
	
	virtual bool	IsMagicExpAddEnable(OBJID idUser, int nSkillType, bool bRMB=false)		= 0;

	virtual bool	CheckUserMagicLevel(OBJID idUser, int nType, int nLevel)		= 0;
	virtual bool	CheckSpiritMagicLevel(OBJID idSpirit, int nType, int nLevel)		= 0;
	
	virtual bool	CheckSpiritMagicSort(OBJID idSpirit, int nMagicSort)		= 0;
	virtual bool	CheckUserMagicByType(OBJID idUser, int nMagicType)	= 0;
	virtual bool	UpMagicLevel(OBJID idSpiritf, int nType, int nAddLev, SYNCHRO_ENUM bSynchro)		= 0;

	virtual bool	UnLearnUserMagic(OBJID idUser, int nType, bool bDrop)		= 0;
//	virtual bool	UnlearnSpiritMagic(OBJID idSpirit, int nType, bool bDrop)		= 0;

	virtual bool	AbortMagic(OBJID idSpirit, SYNCHRO_ENUM bSynchro)		= 0;

	virtual bool	AwardMagicExp(OBJID idSpirit, int nType, I64 n64BattleExp, bool bAwardDeed)		= 0;
	virtual bool	AwardMagicExpEx(OBJID idRole, int nType, I64 n64Exp, I64 n64BattleExp, bool bAwardDeed)		= 0;

	virtual bool	UpdateSkillSuit(OBJID idSpirit, OBJID idSkillSuit, uint32 setSkill[], int nHotKey, int nWeaponPos)		= 0;

	virtual bool	LearnUserMagic(OBJID idUser, int nType, int nLevel, SYNCHRO_ENUM bSynchro)		= 0;
	virtual bool	LearnUserMagicPM(OBJID idUser, int nType, SYNCHRO_ENUM bSynchro)		= 0;

	virtual int		GetMagicLevMax(int nMagicSort)		= 0;
	virtual bool	SendMagicInfo(OBJID idUser)		= 0;
//	virtual bool	QuerySpiritMagic(OBJID idSpirit)		= 0;
//	virtual bool	ClearSpiritMagic(OBJID idSpirit)		= 0;
//	virtual bool	SaveSpiritMagicInfo(OBJID idSpirit)		= 0;
	virtual OBJID	LearnMagicOnNoSkillSuit(OBJID idRole, OBJID idmagicType, SYNCHRO_ENUM bSynchro=SYNCHRO_TRUE)		= 0;
	
//	virtual bool	UpSpiritMagicLevelByTask(OBJID idSpirit, int nType)		= 0;
	virtual bool	UpUserMagicLevelByTask(OBJID idUser, int nType)		= 0;

//	virtual bool	UpdateUserMagic(OBJID idSpirit, SYNCHRO_ENUM bSynchro=SYNCHRO_TRUE)		= 0;
	//lifeskill	
// 	virtual bool	CalcLifeSkillUpLev(OBJID idUser
// 										, I64 n64TimeOfferd
// 										, int nSpiritType
// 										, int& nNewLevel
// 										, int& nEndPencentage)	= 0;

	virtual bool	CheckLifeSkillLev(OBJID idUser, int nType, int nLev)		= 0;
	virtual bool	CheckLifeSkillSort(OBJID idUser, int nType)		= 0;
	virtual bool	AwardLifeSkillExp(OBJID idUser, int nType, I64 n64Exp)		= 0;
	virtual int		GetLifeSkillLev(OBJID idUser, int nType)		= 0;
	virtual bool	AutoStudyLifeSkill(OBJID idUser, int nOldLev, int nNewLev)		= 0;
	virtual bool	SendLifeSkillInfo(OBJID idUser)		= 0;
	virtual OBJID	LearnLifeSkill(OBJID idUser, int nType, int nLev, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)		= 0;
	virtual bool	UpLevelLifeSkill(OBJID idUser, int nType, int nAddLev, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)		= 0;
	virtual bool	ClearUserLifeSkill(OBJID idUser)		= 0;
	virtual bool	QueryUserLifeSkill(OBJID idUser)		= 0;
	virtual bool	SaveUserLifeSkillInfo(OBJID idUser)		= 0;
	virtual bool	CreateUserLifeSkill(OBJID idUser)		= 0;
	virtual bool	QuerySkillInfoByID( OBJID idRole, OBJID idSkillSuit, SkillSuitData& stData)		= 0;
	//msgprocess
	virtual bool	ProcessMagicMsgInfo(OBJID idUser, int nType, USHORT msgAction)		= 0;
	virtual bool	ProcessSkillMsgInfo(OBJID idUser, 
										USHORT usMsgAction, 
										OBJID idSkillSuit,
										uint32 setSkill[], 
										int nHotKey, 
										int nWeaponPos, 
										SYNCHRO_ENUM bSynchro)	= 0;
//	virtual bool	ProcessMsgDomain(OBJID idUser, USHORT nAction, OBJPOS pos, OBJID idSkillSuit)	= 0;
	virtual bool	ProcessDomainMsg(OBJID idUser, USHORT nAction, OBJID idDomain)					= 0;

	virtual bool	ProcessMsgActionGetAngel(OBJID idUser, OBJID idAngel)							= 0;

	//battle
	virtual bool	GetSkillExplodeInfo(OBJID idSpirit, OBJID idSkill, OBJID idTarget, AttackInfo& rInfo, MAGICSORT objMagicSort)		= 0;
	virtual bool	IsSkillSuitActive(OBJID idRole, OBJID idSkillSuit)		= 0;
	virtual OBJID	CreateSkillSuitByInstanceItem(OBJID idRole, OBJID idType)		= 0;
	virtual bool	ReleaseSkillSuit(const OBJID idRole, const OBJID idSkillSuit)		= 0;
	virtual bool	GetSkillSuitAttackInfo(OBJID idRole, OBJID idSkillSuit, AttackInfo& stAttack, OBJID idTarget, STATUS_TYPE eStatusType)		= 0;
	virtual bool	GetMagicTypeBattleInfo(int nMagicType, MAGICTYPEBATTLE_INFO& rInfo)		= 0;
//	virtual bool	IsValidMagicAttack(OBJID idSpirit, OBJID idSkillSuit) = 0;
	virtual bool	IsUserGetAngel(OBJID idUser) = 0;
	virtual bool	IsUserCanUseAngel(OBJID idUser) = 0;
	virtual void	StartUserAngelTimer(OBJID idUser) = 0;
	virtual int		GetAngelRemnantTime(OBJID idUser) = 0;
	virtual void	ClearUserAngelTimer(OBJID idUser, bool bClear)= 0;
	virtual void	ProcessAngelKillMonster(OBJID idUser) = 0;
	virtual void	ProcessQueryKillMonster(OBJID idUser, int nPage) = 0;
	virtual void	UserInviteLongDisTeam(OBJID idActor, OBJID idTarget) = 0;
	virtual void	UserApplyJoinDisTeam(OBJID idActor, OBJID idTarget) = 0;
	virtual void	UserAgreeJoinTeam(OBJID idActor, OBJID idTarget, OBJID dwData) = 0;
	virtual void	UserRejectJoinTeam(OBJID idActor, OBJID idTarget, OBJID dwData) = 0;
	virtual void	UserGetAngelFlush(OBJID idActor) = 0;
//	virtual void	ProcessAngelDismissTeam(OBJID idUser) = 0;
	virtual void	RegisterNewbieMagic(OBJID idUser, int nProfession) = 0;

	//trumpregion
	virtual bool	GetUserDomainEffectValue(OBJID idUser, OBJID idMagic, TRUMP_ATTRIBUTE& rAttribute) = 0;

	//是否需要前序技能
	virtual bool	IsNeedPriorSkill(OBJID idSkill) = 0;
	
	//判断当前技能是否是上次技能的后续技能
	virtual bool	IsNextSkill(OBJID idLastSkill, OBJID idCurrentSkill) =0;

	//是否是连招技能
	virtual bool	IsSeriateSkill(OBJID idSkill) = 0;

/////////////////////////////////////////////////////////////////
//与副本服务器通讯功能
public:
	virtual bool	SendUserMagicDataToInsServer(OBJID idUser)	= 0;
	virtual void	SendUserMagicDataDone(OBJID idUser)	= 0;
	
/////////////////////////////////////////////////////////////////

	//Dota代码
	virtual void	ProcessMagicUpLevel(OBJID idUser, USHORT usAction, OBJID idOleMagic, OBJID idNewMagic)	= 0;
	virtual void	LearnMagicPVE(OBJID idUser, OBJID idOldMagic, OBJID idNewMagic) = 0;
	virtual void	UnLearnMagicPVE(OBJID idUser, OBJID idMagic) = 0;
	virtual void	ProcessUpAllAttrib(OBJID idUser, tq::CMsg& rMsg)	= 0;
    virtual void	SendSkillInfo(OBJID idRec, OBJID idUser)	= 0;
    virtual void    UpGradeTouchRandomMagic(OBJID idUser) = 0;
    virtual void	ProcessRandMagic(OBJID idUser)	= 0;
    virtual void	ProcessChangeRandMagic(OBJID idUser, OBJID idMagic)	= 0;
};

NAMESPACE_END(entityex)

#endif


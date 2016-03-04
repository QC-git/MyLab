//==========================================================================
/**
 *  @file   IUser.h
 *
 *  $Id: IUser.h 2008-12-18 20:46:50Z $
 *
 *  @author xxx
 *
 */
//==========================================================================

#ifndef _EN_IUSER_H_
#define _EN_IUSER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IRole.h"

namespace entity 
{

class CUser;

class IUser : public IRole
{
    DELETE_DISABLED(IUser)
    //玩家基本属性
public:
	virtual const tq::AUTOLINK_NOTE* QueryLink()									                                                              = 0;
    //-------------------------------------------- Basic ---------------------------------------------------------------------------------------------
    virtual const char*               GetName()                                                   const                                           = 0;
    virtual void                      SetName(const char* pszName)                                                                                = 0;
 
	virtual U32						  GetLife()                                                   const                                           = 0;
	virtual void                      SetLife(int nLife, UPDATE_BOOL bUpdate)                                                                     = 0;
    virtual U32						  GetMaxLife()                                                const                                           = 0;
    virtual void                      IncMaxLife(U32 dwIncLife)                                                                                 = 0;
	virtual void                      DecMaxLife(U32 dwDecLife)                                                                                 = 0;
    virtual bool                      IsAlive()                                                   const                                           = 0;
    
	virtual bool                      IsGhost()                                                   const                                           = 0;
    virtual void                      SetGhost(bool bGhost = true)                                                                                = 0;
    
	virtual int                       GetLevel()                                                  const                                           = 0;
    virtual void                      SetLevel(int nLev, bool bUpdate = false)                                                                    = 0;

	virtual int                       GetLevelEx()                                                const                                           = 0;
	virtual void                      SetLevelEx(int nLev, bool bUpdate = false)                                                                  = 0;
	virtual U64                    GetExperienceEx()                                           const		                                      = 0;
	virtual void                      SetExperienceEx(U64 nExp, bool bUpdate = false)                                                          = 0;

	virtual int                       GetFlatLevel()                                                  const                                       = 0;
	virtual void                      SetFlatLevel(int nLev, bool bUpdate = false)                                                                = 0;
    
	virtual U32                     GetSex(void)                                                const                                           = 0;
    
    virtual bool                      IsPM(void)                                                      const                                       = 0;
    virtual bool                      IsGM(void)                                                      const                                       = 0;
    virtual bool                      IsNewBie(void)                                                                                              = 0;
    virtual bool                      IsProtectNewbie(void)                                           const                                       = 0;
	virtual bool                      IsAdult()                                                   const                                           = 0;
    
	virtual bool                      SetFace(U32 dwFace)                                                                                       = 0;
    virtual U32                     GetFace()                                                                                                   = 0;
    virtual bool                      SetLook(U32 dwLook)                                                                                       = 0;
    virtual int                       GetLook()                                                                                                   = 0;
    virtual U32                     GetLookFace()                                                                                               = 0;
	virtual void                      SetLastLookFace(U32 dwLook)                                                                               = 0;
	virtual U32                     GetLastLookFace()																							  = 0;
	virtual void                      SetStateDamageType(int nType)                                                                               = 0;
	virtual int                       GetStateDamageType()		                                const                                             = 0;
	virtual void                      SetStateDamageModulus(int nModulus)																		  = 0;
	virtual int                       GetStateDamageModulus()									const											  = 0;
	virtual void                      SetPVEPhyAttackModulus(int nModulus)																		  = 0;
	virtual int                       GetPVEPhyAttackModulus()									const											  = 0;
    virtual U32                     GetHair()                                                   const                                           = 0;
    virtual void                      SetHair(U32 dwHair, UPDATE_BOOL fUpdate = UPDATE_FALSE)                                                   = 0;
    virtual void                      GetFootPrint(int& nPosX, int& nPosY)                        const                                           = 0;
    
	// get db attribute
	virtual I64                       GetAttr(USERDATA eType)                                     const                                           = 0;
    virtual const char*                   GetStr(USERDATA eType)                                      const                                           = 0;
    virtual bool                      SetAttr(USERDATA eType, I64 n64Data, bool bUpdate = false)                                                  = 0;
    virtual bool                      SetStr(USERDATA eType, const char* pszData, bool bUpdate = false)                                               = 0;
    virtual U64                    GetUserData64(USERDATA idx)                                                                                 = 0;
    virtual void                      SetUserData64(USERDATA idx, U64 u64Data, UPDATE_BOOL bUpdate)                                            = 0;   

	// user attribute point 
    virtual bool                      UpdateUserMaxAttr()                                                                                         = 0;
	virtual bool                      UpGradeUpdateUserAttr()                                                                                     = 0;
	virtual bool                      UpGradeUpdatePveUserAttr()                                                                                  = 0;
    virtual bool                      AddDefencePoint(USHORT iNum)                                                                                = 0;
    virtual bool                      AddDodgePoint(USHORT iNum)                                                                                  = 0;
    virtual bool                      AddPowerPoint(USHORT iNum)                                                                                  = 0;
    virtual bool                      AddManaPoint(USHORT iNum)                                                                                   = 0;
    virtual bool                      AddLifePoint(USHORT iNum)                                                                                   = 0;
    virtual bool                      ClearUserAddPoint()                                                                                         = 0;
//  virtual INT                       GetAttributeTypeLevelPoint(void)                          const                                             = 0;
//	virtual INT			              GetAttributeTypeLevelDodge(void)							const                                             = 0;
//	virtual INT			              GetAttributeTypeLevelWeight(void)		    				const	                                          = 0;

	// pk 
	virtual int                       GetPk()                                                                                                     = 0;
    virtual void                      SetPK(int nPk, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                          = 0;
    virtual U32                     GetPkMode(void)                                             const                                           = 0;
    virtual void                      SetPkMode(U32 nPkMode)                                                                                    = 0;
    
	virtual int                       GetEnergy()                                                 const                                           = 0;
    virtual void                      SetEnergy(int nValue)                                                                                       = 0;
    
// 	virtual int			              GetUserMaxWeight()										  const	                                          = 0;
// 	virtual int			              GetUserWeight()											  const	                                          = 0;
// 	virtual void		              SetUserWeight(int nWeitht)													                              = 0;

	virtual U64					  GetAchiveAddPoint()																	                      = 0;
	virtual void					  SetAchiveAddPoint(U64 u64Point, bool bUpdate = false)				  				                      = 0;
	
	virtual int						  ResetUserFreePoint(bool bLogin = false)				  				                                      = 0;
	virtual bool					  CheckAddPoint(USHORT iNum)				  																  = 0;
	// mana
	virtual U32                     GetMana()                                                                                                   = 0;
	virtual void                      SetMana(int nValue, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                     = 0;
    virtual U32                     GetMaxMana()                                              const                                             = 0;
    virtual void                      SetMaxMana(U32 nMaxMana)                                                                                  = 0;
	virtual void                      IncMaxMana(U32 nIncMana)                                                                                  = 0;
	virtual void                      DecMaxMana(U32 nDecMana)                                                                                  = 0;

    virtual int                       GetStamina()                                                                                                = 0;
    virtual void                      SetStamina(int nStamina, UPDATE_BOOL bUpdate = UPDATE_FALSE)					                              = 0;
    
	virtual U32                     GetHead()                                                                                                   = 0;
	virtual U32                     GetCity()                                                                                                   = 0;

    virtual int                       GetPhyle() const                                                                                            = 0; //获得玩家种族 09-09-17
  
	virtual U32                     GetProfession()                                                                                             = 0;
    virtual void                      SetProfession(U32 dwProfession, UPDATE_BOOL bUpdate)                                                      = 0;
    virtual U32                     GetProfessionSort()                                                                                         = 0;
    
// 	virtual bool                      IsFarFight()                                                                                                = 0;
//  virtual bool                      IsNearFight()                                                                                               = 0;
 
	virtual U64                    GetExp()                                                    const                                           = 0;
	virtual void                      SetExp(U64 nExp, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                     = 0;
	virtual U64                    GetFlatExp()                                                    const                                       = 0;
	virtual void                      SetFlatExp(U64 nExp, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                 = 0;

    virtual int                       GetExpType()                                                const                                           = 0;
    virtual void                      SetExpAdj(EXP_ADJ_TYPE expAdjType, int nExpAdj)                                                             = 0;
    virtual int                       GetCurExpAdj()                                              const                                           = 0;
    virtual void                      SetCurExpAdj(int nCurExpAdj)                                                                                = 0;
    virtual void                      ClearCurExpAdj()                                                                                            = 0;
    virtual bool                      FlushExp2Client()                                                                                           = 0;
    virtual U64                    GetRemainExp2Client()                                       const                                           = 0;
//    virtual void                      AddRemainExp2Client(I64 n64RemainUserExp2Client)                                                            = 0;
    virtual void                      ClearRemainExp2Client()                                                                                     = 0;
    
	virtual const char*               GetUserIp() const                                                                                           = 0;
    virtual void                      SetUserIp(const char* pszIp)                                                                                = 0;

	virtual bool                      IsWhiteName() const                                                                                         = 0;
	virtual bool                      IsRedName() const                                                                                           = 0;
	virtual bool                      IsBlackName() const                                                                                         = 0;
        
    virtual void                      SetEmotion(int nEmotion)                                                                                    = 0;
    virtual int                       GetEmotion()                                              const                                             = 0;
    virtual void                      SetDonate(const U64& u64Donate)                                                                          = 0;
    virtual U64                    GetDonate(void)                                           const                                             = 0;

 	//-------------------------------------------- profession ---------------------------------------------------------------------------------------------     
	virtual U32                     GetProfessionLevel()                                                                                        = 0;
    virtual U32                     GetProfessionExp()                                                                                          = 0;
    virtual bool                      UpProfessinLev(UINT nAmount)                                                                                = 0;
    virtual bool                      AddProfessinLevTime(UINT nAmount)                                                                           = 0;
    virtual bool                      AddProfessionExp(UINT nAmount)                                                                              = 0;
    
	//-------------------------------------------- MAP ---------------------------------------------------------------------------------------------   	
	virtual void                      EnterTrape(const OBJID idTrap)                                                                              = 0;
    virtual void                      LeaveTrape()                                                                                                = 0;
    virtual bool                      IsAreadyInThisTrape(const OBJID idTrap)                                                                     = 0;
   	virtual bool                      IsInFieldRegion(REGION_TYPE eRegionType)                                                                    = 0;
    
	virtual void                      SetRebornMap(OBJID idMap, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                               = 0;
    virtual OBJID                     GetRebornMap()                                                                                              = 0;
    
	virtual int                       GetPosX()                                                   const                                           = 0;
    virtual int                       GetPosY()                                                   const                                           = 0;
        
	virtual OBJPOS                    GetLastPos()                                                const                                           = 0;
    virtual void                      SetLastPos(const OBJPOS& pos)                                                                               = 0;
    
	virtual void                      SetRecordPos(OBJID idMap, U32 dwX, U32 dwY, UPDATE_BOOL bUpdate = UPDATE_FALSE, bool bSaveFlag = false) = 0;
    virtual OBJID                     GetRecordMap()                                                                                              = 0; 
	virtual U32                     GetRecordX()                                                                                                = 0;
    virtual U32                     GetRecordY()                                                                                                = 0;

    virtual U32                     GetOrigMapId()                                                                                              = 0;
    virtual U32                     GetOrigPosX()                                                                                               = 0;
    virtual U32                     GetOrigPosY()                                                                                               = 0;
    virtual void                      SetOrigMapID(U32 dwMapId)                                                                                 = 0;
    virtual void                      SetOrigPosX(U32 dwPosX)                                                                                   = 0;
    virtual void                      SetOrigPosY(U32 dwPosY)                                                                                   = 0;    
	
	virtual int                       GetGenerator()                                                                                              = 0;
    virtual bool                      SetGenerator(int nDf)                                                                                       = 0;
	virtual void					  SetDeadBodyMapItemID(OBJID idMapItem)																		  = 0;
	virtual OBJID					  GetDeadBodyMapItemID()																					  = 0;
    
	//-------------------------------------------- DynaSort ---------------------------------------------------------------------------------------------   
	virtual int                       GetDynaSortType_Leader()                                                                                    = 0;
    virtual void                      SetDynaSortType_Leader(int nTypeLeader)                                                                     = 0;
    virtual int                       GetDynaSortRankPos_Leader()                                                                                 = 0;
    virtual void                      SetDynaSortRankPos_Leader(int nRandPosLeader)                                                               = 0;
    virtual const DYNASORT_USER_INFO& GetUserDynaSortInfo()                                                                                       = 0;
    virtual void                      SetUserDynaSortInfo(const DYNASORT_USER_INFO& DynaSortInfo)                                                 = 0;
    virtual bool                      GetDynaSortLead(int& nType, int& nRankPos)                  const                                           = 0;
    
	//-------------------------------------------- Syndicate ---------------------------------------------------------------------------------------------
	virtual U32                     GetSynID()                                                  const                                           = 0;
    virtual void                      SetSynID(OBJID idSyn)                                                                                       = 0;
    virtual U32                     GetSynRank()                                                const                                           = 0;
    virtual void                      SetSynRank(OBJID SynRank)                                                                                   = 0;
    virtual U32                     GetSynRankShow()                                            const                                           = 0;
    virtual void                      SetSynRankShow(OBJID SynShow)                                                                               = 0;
    virtual U32                     GetSynIcon()                                                const                                           = 0;
    virtual void                      SetSynIcon(OBJID SynRank)                                                                                   = 0;
    virtual UCHAR                     GetSynMemberTitle()                                             const                                       = 0;
    virtual void                      SetSynMemberTitle(UCHAR ucMemberTitle)                                                                      = 0;
    virtual bool                      IsSyndicateMember()                                                                                         = 0;
    virtual OBJID                     GetSyndicate()                                                                                              = 0;
    
	//-------------------------------------------- Family ---------------------------------------------------------------------------------------------
	virtual U32                     GetFamilyRankShow()                                         const                                           = 0;
    virtual void                      SetFamilyRankShow(OBJID RankShow)                                                                           = 0;
    virtual U32                     GetFamilyID()                                               const                                           = 0;
    virtual void                      SetFamilyID(OBJID FimilyID)                                                                                 = 0;
    virtual bool                      IsFamilyMember()                                                                                            = 0;

 	//-------------------------------------------- State ---------------------------------------------------------------------------------------------   
	virtual U64                    GetEffect(int nIdex = 0) const                                                                              = 0;
    virtual void                      SetEffectValue(U64 un64Effect, int nIdex = 0)                                                            = 0;
    virtual U64                    SetEffect(U64 i64Effect, int nIdex = 0)                                                                  = 0;
    virtual U64                    ResetEffect(U64 i64Effect = 0xFFFFFFFFFFFFFFFF)                                                          = 0;
    virtual bool                      TestEffect(U64 i64Effect)                                                                                = 0;
    virtual bool                      TryResetEffectMask(NEW_STATE eState, U64& u64Mask)                                                       = 0;
    virtual bool                      TrySetEffectMask(NEW_STATE eState, U64& u64Mask)                                                         = 0;
        
	//-------------------------------------------- Money ---------------------------------------------------------------------------------------------
	virtual U32                     GetMoney()                                                          const                                   = 0;
    virtual void                      SetMoney(U32 n64Money)                                                                                    = 0;
    virtual bool                      SpendMoney(U32 n64Money, SYNCHRO_ENUM bSynchro)                                                           = 0;
    virtual bool                      GainMoney(U32 n64Money, SYNCHRO_ENUM bSynchro)                                                            = 0;
    virtual bool                      SaveMoney(U32 n64Money, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                            = 0;
    virtual bool                      DrawMoney(U32 n64Money, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                            = 0;
    virtual U64                    GetMoneySaved()                                                     const                                   = 0;
    virtual bool                      AddSaveMoneyEx(const U32 dwMoney, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                  = 0;
    virtual bool                      ChangeMoneySaved(U32 i64Money, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                     = 0;
    virtual bool                      SpendMoneySaved(U32 dwMoney, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                       = 0;
    virtual U32                     GetEmoney3()                                                        const                                   = 0;
    virtual void                      SetEmoney3(const U32& dwEmoney3, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                   = 0;
	virtual bool		              GainEmoney3(U32 dwMoney3, SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                          = 0;
	virtual bool		              SpendEmoney3(U32 dwMoney3,  SYNCHRO_ENUM bSynchro = SYNCHRO_FALSE)                                        = 0;
    virtual bool                      GainRMB(U32 nRMB)                                                                                         = 0;
    virtual U32                     GetRMB()                                                            const                                   = 0;
    virtual void                      SetRMB(U32 dwRMB)                                                                                         = 0;
  
	//-------------------------------------------- Stone ---------------------------------------------------------------------------------------------
	virtual void                      SetStone0(U64 u64Data, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                               = 0;
    virtual U64                    GetStone0()                                                                                                 = 0;
    virtual void                      SetStone1(U32 dwData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                 = 0;
    virtual U32                     GetStone1()                                                                                                 = 0;
    virtual void                      SetStone2(U32 dwData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                 = 0;
    virtual U32                     GetStone2()                                                                                                 = 0;
    virtual bool                      GainStone(ENUM_STONE eStone, U32 dwStone, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)                           = 0;
    virtual bool                      SpendStone(ENUM_STONE eStone, U32 dwStone, SYNCHRO_ENUM bSynchro)                                         = 0;
	
	//-------------------------------------------- Money Checksum -------------------------------------------------------------------------------------
	virtual bool                      TestUserChkSum()                                                                                            = 0;
    virtual bool                      IsRMBChkSumPass()                                                                                           = 0;
    virtual bool                      IsMoneyChkSumPass()                                                                                         = 0;
    virtual bool                      IsStoneChkSumPass()                                                                                         = 0;
    virtual bool                      IsEmoney3ChkSumPass()                                                                                       = 0;  
    
    //-------------------------------------------- Team ---------------------------------------------------------------------------------------------
    virtual OBJID                     GetTeamLeaderID()                                               const                                       = 0;
    virtual void                      SetTeamLeaderID(OBJID idLeaderID)                                                                           = 0;
    virtual U32                     GetTeamID()                                                     const                                       = 0;
    virtual void                      SetTeamID(U32 dwTeamID)                                                                                   = 0;
    virtual int                       GetTeamMemberAmount()                                           const                                       = 0;
    virtual void                      SetTeamMemberAmount(int nTeamMemberAmount)                                                                  = 0;
    virtual bool                      SetAutoInvite(bool bAuto)                                                                                   = 0;
    virtual bool                      SetRefuseTeam(bool bRefuse)                                                                                 = 0;
    virtual bool                      IsRefuseTeam()                                                                                              = 0;
	virtual bool                      IsTeamAutoInvite()                                                                                          = 0;

    //-------------------------------------------- list?? ---------------------------------------------------------------------------------------------
    virtual U32                     GetList1(BYTE btIndex)                                                                                      = 0;
    virtual void                      SetList1(BYTE btIndex, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                  = 0;
    virtual void                      ClsList1(BYTE btIndex, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)                                                = 0;
    virtual U32                     GetList2(BYTE btIndex)                                                                                      = 0;
    virtual void                      SetList2(BYTE btIndex, int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                       = 0;
    virtual void                      ClsList2(BYTE btIndex, SYNCHRO_ENUM bSynchro = SYNCHRO_TRUE)                                                = 0;
    
	//-------------------------------------------- XP ---------------------------------------------------------------------------------------------   
	virtual int                       GetXPBeat()                                                                                                 = 0;
    virtual void                      SetXPBeat(int nData, UPDATE_BOOL fUpdate = UPDATE_FALSE)                                                    = 0;
    virtual int                       GetXp(void)                                                           const                                 = 0;
    virtual void                      SetXp(XP_STATUS nXp)                                                                                        = 0;
    virtual U64                    GetExpInXpSaved()                                                                                           = 0;
    virtual bool                      SetExpInXpSaved(U64 un64Exp)                                                                             = 0;

    //-------------------------------------------- AUTOEXERCISE ---------------------------------------------------------------------------------------------
    virtual void                      SetAutoExerciseFlag(bool bFlag, UPDATE_BOOL bUpdate)                                                        = 0;
    virtual bool                      IsInAutoExercise()                                                                                          = 0;
    virtual bool                      InitUserAutoExeciseTick()                                                                                   = 0;
	virtual void                      AddUserInAutoExeciseMapTick()                                                                               = 0;

	//-------------------------------------------- LOTTERY ---------------------------------------------------------------------------------------------
	virtual int                       GetLastLottery()                                                                                            = 0;
    virtual void                      SetLastLottery(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                               = 0;
    virtual int                       GetLotteryTimes()                                                                                           = 0;
    virtual void                      SetLotteryTimes(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                              = 0;
    virtual bool                      ClrPosBeforeLottery()                                                                                       = 0;
    virtual bool                      IsValidPosBeforeLottery()                                                                                   = 0;
    virtual bool                      RecordPosBeforeLottery()                                                                                    = 0;
    virtual bool                      GetPosBeforeLottery(OBJPOS& pos)                                                                            = 0;
    virtual OBJID                     GetMapBeforeLottery()                                                                                       = 0;
    virtual int                       GetBigBadLuck()                                                                                             = 0;
    virtual void                      SetBigBadLuck(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                                = 0;
    virtual int                       GetSmallBadLuck()                                                                                           = 0;
    virtual void                      SetSmallBadLuck(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                              = 0;
    virtual void                      SetBigGoodLuck(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                               = 0;
    virtual int                       GetBigGoodLuck()                                                                                            = 0;
    virtual void                      SetSmallGoodLuck(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                             = 0;
    virtual int                       GetSmallGoodLuck()                                                                                          = 0;		

    //-------------------------------------------- MOVE ---------------------------------------------------------------------------------------------
	virtual U32                     GetVitalCapacity()                                                                                          = 0;
    virtual U32                     GetCurentOxygen()                                                                                           = 0;
    virtual U32                     GetLastVitalCapacity()                                                                                      = 0;
    virtual void                      SetLastVitalCapacity(int nVitalCapacity)                                                                    = 0;
    virtual U32                     GetIncVitalCapacity()                                                                                       = 0;
    virtual void                      SetIncVitalCapacity(int nVitalCapacity)                                                                     = 0;
    virtual void                      SetVitalCapacity(int nVitalCapacity)                                                                        = 0;
    virtual void                      SetOxygen(int nOxygen)                                                                                      = 0;
    
	//-------------------------------------------- BATTLE EFFECT ---------------------------------------------------------------------------------------------
    virtual int                       GetBaseBattleEffect()                                           const                                       = 0;
    virtual void                      SetBaseBattleEffect(int nEffect)                                                                            = 0;
    virtual int                       GetTutorShareBattleEffect(void)                                 const                                       = 0;
    virtual void                      SetTutorShareBattleEffect(int nTutorShareBattleEffect)                                                      = 0;
    virtual bool                      SetRankBattleEffect(int nRank)                                                                              = 0;
    virtual int                       GetRankBattleEffect(void)                                       const                                       = 0;
    virtual int                       GetTotalBattleEffect()                                          const                                       = 0;
    virtual int                       GetBattleEffect()                                               const                                       = 0;
    virtual void                      SetBattleEffect(int nBattleEffect)                                                                          = 0; 

	//-------------------------------------------- VIP ---------------------------------------------------------------------------------------------
    virtual int                       GetVipLev()                                                     const                                       = 0;
    virtual void                      SetVipLev(U32 dwVipLevel)                                                                                 = 0;
    virtual U32                     GetVipRebornCount()                                             const                                       = 0;
    virtual void                      SetVipRebornCount(U32 dwCount)                                                                            = 0;
    virtual E_VIPREBORN_TYPE          GetRebornType()                                                 const                                       = 0;
    virtual void                      SetRebornType(E_VIPREBORN_TYPE eRebornType)                                                                 = 0;
    
	// BLUE VIP
	virtual bool					GetIsBlueVip()													  const										  = 0;
	virtual void					SetIsBlueVip(bool bIsBlueVip)																				  = 0;						
	virtual bool					GetIsBlueYearVip()						                          const										  = 0;
	virtual void					SetIsBlueYearVip(bool bIsBlueYearVip)	                                                                      = 0;				
	virtual int						GetBlueVipLev()													  const										  = 0;
	virtual void					SetBlueVipLev(int nBlueVipLev)																				  = 0;
	virtual int						GetIsSuperBlueVip()												  const										  = 0;
	virtual void					SetIsSuperBlueVip(int bIsSuperBlueVip)																		  = 0;
	virtual int						GetDitch() const										  = 0;
	virtual void					SetDitch(int ditch)	= 0;

	virtual U32					GetHeroFeat()												      const									      = 0;		
    virtual void					SetHeroFeat(U32 heroFeat)																				  = 0;
	virtual const char*				GetLgnShortName()												  const										  = 0;
	virtual void					SetLgnShortName(const char* pszName)																	      = 0;
	virtual const char*				GetClanShortName()												  const										  = 0;
	virtual void					SetClanShortName(const char* pszName)																			= 0;
	virtual OBJID					GetLegionId()														const										= 0;
	virtual void					SetLegionId(OBJID legionId)																						= 0;

	virtual int						GetLgnExp()														  const										  = 0;
	virtual void					SetLgnExp(int exp)																							  = 0;

	//-------------------------------------------- TASK ---------------------------------------------------------------------------------------------
    virtual void                      SetUserTaskItemAction(OBJID idItemAction)                                                                   = 0;
    virtual OBJID                     GetUserTaskItemAction()                                         const                                       = 0;
	virtual void                      SetUserTaskItem(OBJID idTastItem)                                                                           = 0;
    virtual OBJID                     GetUserTaskItem()                                                                                           = 0;
    virtual void                      AddTaskMask(int idx)                                                                                        = 0;
    virtual void                      ClrTaskMask(int idx)                                                                                        = 0;
    virtual bool                      ChkTaskMask(int idx)                                            const                                       = 0;

	//-------------------------------------------- BATTLE ---------------------------------------------------------------------------------------------
    virtual void                      AddAtker(OBJID idAtker)                                                                                     = 0;
    virtual void                      RefreshAtker()                                                                                              = 0;
    virtual void                      RefreshDf()                                                                                                 = 0;
    virtual bool                      IsAtker(OBJID idAtker)                                          const                                       = 0;
    virtual bool                      IsBeAtkable()                                                                                               = 0;
    virtual void                      IncBeAttack()                                                                                               = 0;
    virtual void                      ClsBeAttack()                                                                                               = 0;
    virtual int                       GetBeAttack()                                                                                               = 0;
    
	//-------------------------------------------- FLOWER ---------------------------------------------------------------------------------------------
	virtual int                       GetAllRedFlower()                                               const                                       = 0;
    virtual int                       GetAllWhiteFlower()                                             const                                       = 0;
    virtual int                       GetDayRedFlower()                                               const                                       = 0;
    virtual int                       GetDayWhiteFlower()                                             const                                       = 0;
    virtual void                      SetRecieveFlower(int nFlower)                                                                               = 0;
    virtual int                       GetRecieveFlower()                                              const                                       = 0;
    virtual const char*               GetFollowEffectName() const                                                                                 = 0;
    virtual void                      SetFollowEffectName(const char* pszName)                                                                    = 0;

	//-------------------------------------------- LOGINOUT ---------------------------------------------------------------------------------------------
	virtual bool                      SetOnLineTime(BYTE byMinutes, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                           = 0;
    virtual bool                      SetOnlineTime2(BYTE btOnlineTime2, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                      = 0;
    virtual bool                      SetOfflineTime(BYTE btOfflineTime, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                      = 0;
    virtual bool                      SetLastLogOut2()                                                                                            = 0;
    virtual time_t					  GetLastLogOut2()                                                    const                                   = 0;    
	virtual bool                      SetLogoutDelay(bool bDelay)                                                                                 = 0;
    virtual bool                      GetLogoutDelay()                                                                                            = 0;
    virtual bool                      ActiveLogoutTime(bool bActive)                                                                              = 0;
    virtual bool                      SetOffline(bool bOffline)                                                                                   = 0;
    virtual bool                      GetOffline()                                                                                                = 0;
    virtual bool                      SetLastLogin()                                                                                              = 0;
    virtual BYTE                      GetOnLineTime()                                                                                             = 0;
    virtual U32						GetLastLoginTime()                                                  const                                   = 0;    
	virtual void                      SetLastLoginTime()                                                                                          = 0;
	virtual time_t					GetLastLogoutTime() = 0;
    virtual U32						GetOnlineUserTime()                                                                                         = 0;
    virtual U32						GetLastLogOutMin(void)                                                                                      = 0;

	//-------------------------------------------- INSTANCE ---------------------------------------------------------------------------------------------
	virtual	void					  SetInstance(OBJID idInstance)																				  = 0;
	virtual	OBJID					  GetInstance()																							      = 0;	
	
	//-------------------------------------------- EXPBALL ---------------------------------------------------------------------------------------------
    virtual OBJID                     GetCurExpBallItem() const                                                                                   = 0;
    virtual void                      SetCurExpBallItem(OBJID idItem)                                                                             = 0;
    virtual int                       GetCurExpBallTarget() const                                                                                 = 0;
    virtual void                      SetCurExpBallTarget(int nTarget)                                                                            = 0;
    virtual int                       GetCurExpBallType() const                                                                                   = 0;
    virtual void                      SetCurExpBallType(int nType)                                                                                = 0;
    virtual int                       GetCurExpBallNewLevel()                                                                                     = 0;
    virtual void                      SetCurExpBallNewLevel(int nNewLevel)                                                                        = 0;
    virtual int                       GetCurExpBallNewPercent()                                                                                   = 0;
    virtual void                      SetCurExpBallNewPercent(int nNewPercent)                                                                    = 0;
    virtual int                       GetExpBallInsight()                                                                                         = 0;
    virtual void                      SetExpBallInsight(int nInsightLev)                                                                          = 0;
    virtual int                       GetExpBallUsage(EXPBALL_USETYPE eType)                                                                      = 0;
    virtual void                      SetExpBallUsage(EXPBALL_USETYPE eType, int nExpBallUsage, UPDATE_BOOL bUpdate = UPDATE_FALSE)               = 0;

	virtual OBJID		              QueryExpBall()             		                                                                          = 0; 
	virtual void		              UnEquipExpBall()	                                                                                          = 0;
	virtual void		              EquipExpBall(OBJID idEquip)	                                                                              = 0;
    
	//-------------------------------------------- WANTED ---------------------------------------------------------------------------------------------
    virtual WantedInfoStruct&         WantedInfo(void)                                                                                            = 0;
    virtual void                      ResetWantedInfo(void)                                                                                       = 0;
    virtual OBJID&                    PoliceWantedID()                                                                                            = 0;


	//-------------------------------------------- QUIZCOMPLETE ---------------------------------------------------------------------------------------
    virtual U32                     GetQuizPoint(void) const                                                                                    = 0;
    virtual void                      SetQuizPoint(const U32& dwQuizPoint, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                  = 0;
	
    //-------------------------------------------- ITEM  ----------------------------------------------------------------------------------------------
    virtual void                      SetCurItemID(OBJID idItem)                                                                                  = 0;
    virtual OBJID                     GetCurItemID()                                                                                              = 0;
	virtual void                      SetMountItem(OBJID idItem)                                                                                  = 0;
    virtual OBJID                     GetMountItem()                                                                                              = 0;
	
    //-------------------------------------------- BUSINESS  ------------------------------------------------------------------------------------------
    virtual bool                      SetBusiness(int nBussiness, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                             = 0;
    virtual int                       GetBusiness()                                                     const                                     = 0;
    virtual int                       GetBusinessType()                                               const                                       = 0;
    virtual void                      SetBusinessType(int nBusinessType)                                                                          = 0;	

    //-------------------------------------------- STORAGE  ----------------------------------------------------------------------------------------------
    virtual U32                     GetStorageLev()                                                     const                                   = 0;
	virtual void                      SetStorageLev(U32 dwStorageLev)                                                                           = 0;
	
    //-------------------------------------------- BROTHER  ----------------------------------------------------------------------------------------------
    virtual OBJID                     GetBrotherGroupID(void)                                                                                     = 0;
    virtual void                      SetBrotherGroupID(OBJID idBrotherGroup, UPDATE_BOOL bUpdate = UPDATE_TRUE)                                  = 0;
    
	//-------------------------------------------- TUTOR  ----------------------------------------------------------------------------------------------
    virtual int                       GetTutorLevel()                                                 const                                       = 0;
    virtual void                      SetTutorLevel(int nTutorLevel)                                                                              = 0;

	//-------------------------------------------- MISC  ----------------------------------------------------------------------------------------------
	virtual void                      SetVirtualSpaceLimit(int nData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                         = 0;
    virtual U32                     GetVirtualSpaceLimit()                                                                                      = 0;    
	
	virtual U32                     GetNobilityRank()                                                                                           = 0;
    virtual void                      SetNobilityRank(U32 dwNobilityRank, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                   = 0;

    virtual bool                      SetMoodDescribe(char* pszMood)                                                                        = 0;
    virtual const char*               GetMoodDescribe()                                                   const                                   = 0;

	virtual void                      SetAiDescribe(const char* pszMood)                                                                          = 0;
	virtual const char*               GetAiDescribe()                                                   const                                     = 0;
    
	virtual int                       GetDonationPosition()                                                                                       = 0;
    virtual int                       SetDonationPosition(int nDonaPosition)                                                                      = 0;

    virtual bool                      IsInMount()                                                                                                 = 0;
    virtual bool                      SetMountType(OBJID idType)                                                                                  = 0;
    virtual void                      CheckMountRegion()                                                                                          = 0;

    virtual int                       GetWeapon_select()                                                                                          = 0;
    virtual void                      SetWeapon_select(int nData, bool bUpdate = false)                                                           = 0;
    
	virtual bool                      GetHaveLeaveWordFlag()                                          const                                       = 0;
    virtual void                      SetHaveLeaveWordFlag(bool bIsHaveLeaveWord)                                                                 = 0;
	
    virtual bool                      StandTurnoff()                                                                                              = 0;
    virtual bool                      SetExpType(int nData, UPDATE_BOOL bUpdate)                                                                  = 0;
    virtual bool                      SetDeed(U32 dwDeed, UPDATE_BOOL fUpdate = UPDATE_FALSE)                                                   = 0;
    virtual bool                      SetSymbolFeeTime(U32 dwData, UPDATE_BOOL bUpdate = UPDATE_FALSE)                                          = 0;

    virtual OBJID                     GetTransMagicID()                                               const                                       = 0;
    virtual void                      SetTransMagicID(OBJID idMagicID)                                                                            = 0;
    
    virtual bool                      IsHumanMap()                                                    const                                       = 0;
	
    virtual const U32               GetClientVersion(void)                                          const                                       = 0;
    virtual void                      SetClientVersion(U32 dwCliVer)                                                                            = 0;
    
	virtual OBJID                     GetAccountID()                                                  const                                       = 0;

	virtual OBJPOS                    GetLastTimer()                                              const                                           = 0;
    virtual void                      SetLastTimer(const OBJPOS& pos)                                                                             = 0;
    
    virtual bool                      SetEquip(int nPostion, OBJID idEquip)                                                                       = 0;
	virtual OBJID                     GetEquip(int nPostion) const                                                                                = 0;
	virtual int                       GetEquipType(int nPos)                                                                                      = 0;
    virtual bool                      GetEquipIDSet(ID_VEC& rVec)                                                                                 = 0;
	virtual bool		              IsFullQuaility9(void)									           const                                      = 0;
	virtual void		              SetFullQuaility9Flag(bool bFlag)                                                                            = 0;
	virtual void		              SetEquipAddAttrib(USER_EQUIP_ADDATTRIB& stEquipAddAttrib)					                                  = 0;
    virtual void                      GetEquipAddAttrib(USER_EQUIP_ADDATTRIB& stEquipAddAttrib) const                                             = 0;

	virtual bool                      IsMarried() const                                                                                           = 0;
    virtual const char*                   GetMate()   const                                                                                           = 0;
    virtual OBJID                     GetMateID()                                                const                                            = 0;
 //   virtual void                      SetMateID(OBJID idMate)                                                                                     = 0;
    virtual bool                      IsMate(const char* szMateName)                                                                              = 0;
    virtual bool                      UpdateMate(const char* pszName, OBJID idMate, U32 tMarryTime, UPDATE_BOOL bUpdate = UPDATE_FALSE)         = 0;

	virtual int                       GetDataExpType()                                                                                            = 0;
    virtual bool                      UpdateAcademeData(UPDATE_BOOL bUpdate = UPDATE_TRUE)                                                        = 0;
	
    virtual bool                      QA_WATCH(const char* format)                                                                                = 0;
    virtual int                       GetAdditionMagictypeCapacity()                                                                              = 0;
    virtual bool                      IsInExperiment()                                                                                            = 0;
	
    virtual bool                      SetPeerage(PEERAGE_LEVEL ePeerLevel)                                                                        = 0;
    virtual PEERAGE_LEVEL             GetPeerage()                                                                                                = 0;

    virtual U32                     GetFlamethrowerTemperature()                                                                                = 0;
    virtual void                      SetFlamethrowerTemperature(U32 dwFlamethrowerTemperature)                                                 = 0;
    
	virtual OBJID                     GetArmorTypeID()                                                                                            = 0;
    
	virtual U32                     GetFreezeTemperature()                                      const                                           = 0;
    virtual void                      SetFreezeTemperature(U32 dwFreezeTemperature)                                                             = 0;
    
	virtual int                       GetCurExpMedicinePower()                                  const                                             = 0;
    virtual void                      SetCurExpMedicinePower(int nCurExpMedicinePower)                                                            = 0;
    virtual void                      ClearCurExpMedicinePower()                                                                                  = 0;
    
	virtual int                       GetCurGemAdj()                                            const                                             = 0;
    virtual void                      SetCurGemAdj(int nCurGemAdj)                                                                                = 0;
    virtual U32                     GetSymbolFeeTime()                                        const                                             = 0;

    virtual void                      SetProtectTime(int nSecond)                                                                                 = 0;
	
//    virtual U32                     GetDeed()                                                 const                                             = 0;
	
	virtual U32                     GetStratagem()                                                      const                                   = 0;
    virtual void                      SetStratagem(U32 dwStratagem)                                                                             = 0;

	virtual U64                    GetFriendShareUplevtime()                                                                                   = 0;
    virtual void                      SetFriendShareUplevtime(U64 u64Uplevtime, bool bUpdate = false)                                          = 0;

    virtual bool                      ClearPKProtected()                                                                                          = 0;
    
	virtual void                      SetWeatherRegion(OBJID idWeatherRegion)                                                                     = 0;
    virtual OBJID                     GetWeatherRegion()                                                                                          = 0;

    virtual bool                      CheckSupportStation(OBJPOS posNew)                                                                          = 0;
    virtual bool                      CheckRadiation(OBJPOS posNew)                                                                               = 0;
    
	virtual bool                      InitAccumulate()                                                                                            = 0;
    virtual bool                      InitSysTime()                                                                                               = 0;
    virtual void                      InitDfTimer()                                                                                               = 0;
	virtual	void						SetLiftMonsterType(OBJID idType)											= 0;
	virtual	OBJID						GetLiftMonsterType()														= 0;
    virtual bool                      IsAddAwardExpbySupportPoints()                                                                              = 0;
    virtual bool                      IsLockOpened()                                                                                              = 0;

	virtual bool                      IsMagicAtkCheat(OBJID idTarget, OBJPOS posTarget, U32 dwTimeStamp)                                        = 0;

    virtual void                      SynchroSupermanOrder(int nOrder)                                                                            = 0;
    virtual void                      CalcSupermanKills()                                                                                         = 0;
    virtual int                       GetTopSuppermanKills()                                                                                      = 0;

    virtual OBJID                     QueryCallPetID()                                                                                            = 0;
    virtual void                      SetCallPetID(OBJID idPet)                                                                                   = 0;
	virtual int			              GetOnlineMin()                                                                                              = 0;
	virtual void		              SetOnlineMin(int nMin)                                                                                      = 0;
	virtual int 		              GetInsID()                                                                                                  = 0;
	virtual void		              SetInsID(int nID)                                                                                           = 0;

	virtual void		              SetInMapFlag(bool bFlag)                                                                                    = 0;
	virtual bool		              GetInMapFlag()                                                                                              = 0;
	virtual void		              SetChangeRoleFlag(bool bFlag)                                                                               = 0;
	virtual bool		              GetChangeRoleMapFlag()                                                                                      = 0;
	virtual void		              SetLoadMapFlag(bool bFlag)                                                                                  = 0;
	virtual bool		              GetLoadMapFlag()                                                                                            = 0;
	virtual void		              SetGiveGameFlag(bool bFlag)                                                                                 = 0;
	virtual bool		              GetGiveMapFlag()                                                                                            = 0;
	virtual void                      SetCamp(USHORT usCamp)                                                                                      = 0;
	virtual void                      SetPower(U32 dwPower)                                                                                     = 0;
	virtual void                      SetBrains(U32 dwBrains)                                                                                   = 0;
	virtual void                      SetAgility(U32 dwAgility)                                                                                 = 0;
	virtual void                      SetMinAttack(U32 dwMinAttack)                                                                             = 0;
	virtual void                      SetMaxAttack(U32 dwMaxAttack)                                                                             = 0;
	virtual void                      SetArmor(float dwArmor)                                                                                     = 0;

	virtual void                      SetBaseMana(U32 dwBaseMana)                                                                               = 0;
	virtual void                      SetBaseMinAttack(U32 dwBaseMinAttack)                                                                     = 0;
	virtual void                      SetBaseMaxAttack(U32 dwBaseMaxAttack)                                                                     = 0;
	virtual void                      SetBaseLife(U32 dwBaseLife)                                                                               = 0;
	virtual void                      SetBaseArmor(U32 dwBaseArmor)                                                                             = 0;

	virtual U32                     GetBaseMana()                                                                                               = 0;
	virtual U32                     GetBaseMinAttack()   																					      = 0;
	virtual U32                     GetBaseMaxAttack()																						  = 0;
	virtual U32                     GetBaseLife()																							      = 0;
	virtual U32                     GetBaseArmor()                                                                                              = 0;

	virtual U32                     GetPower()                                                                                                  = 0;
	virtual U32                     GetBrains()                                                                                                 = 0;
	virtual U32                     GetAgility()                                                                                                = 0;
	virtual U32                     GetMinAttack()                                                                                              = 0;
	virtual U32                     GetMaxAttack()                                                                                              = 0;
	virtual float                     GetArmor()                                                                                                  = 0;
	virtual U32                     GetMagicArmor()                                                                                             = 0;
	virtual INT			              GetUsedMagicPoint() const	                                                                                  = 0;
	virtual void		              SetUsedMagicPoint(INT nPoint)	                                                                              = 0;
	virtual void                      InitUserInfo()                                                                                              = 0;

	virtual void		               SetHeroType(HERO_TYPE nType)	                                                                              = 0;
	virtual HERO_TYPE                  GetHeroType()                                                                                              = 0;

	virtual void                      AddPower(float fNum)                                                                                       = 0;
	virtual void                      AddBrains(float fNum)                                                                                      = 0;
	virtual void                      AddAgility(float fNum)                                                                                     = 0;

    virtual void                      SetBuffPower(int nPower)                                                                                   = 0;
    virtual void                      SetBuffBrains(int nBrain)                                                                                  = 0;
    virtual void                      SetBuffAgility(int nAgility)                                                                               = 0;


    virtual int                       GetBuffPower()                                                                                             = 0;
    virtual int                       GetBuffBrains()                                                                                            = 0;
    virtual int                       GetBuffAgility()                                                                                           = 0;

    virtual void                       AddBaseMinAttack(float fNum)                                                                              = 0;
    virtual void                       AddBaseMaxAttack(float fNum)                                                                              = 0;


	virtual void                      DecPower(float fNum)                                                                                       = 0;
	virtual void                      DecBrains(float fNum)                                                                                      = 0;
	virtual void                      DecAgility(float fNum)                                                                                     = 0;

	virtual U32					  GetBaseRestoreMana()                                                                                        = 0;
	virtual U32					  GetBaseRestoreLife()                                                                                        = 0;
	virtual U32					  GetRestoreMana()                                                                                            = 0;
	virtual U32					  GetRestoreLife()                                                                                            = 0;

	virtual void					  SetBaseRestoreMana(U32 dwMana)                                                                            = 0;
	virtual void					  SetBaseRestoreLife(U32 dwLife)                                                                            = 0;
	virtual void                      SetRestoreMana(U32 dwMana)                                                                                = 0;
	virtual void                      SetRestoreLife(U32 dwLife)                                                                                = 0;   

	virtual void					  SetAddMaxLife(U32 dwLife)                                                                                 = 0;
	virtual void					  SetAddMaxMana(U32 dwMana)                                                                                 = 0;
	virtual U32                     GetAddMaxLife()                                                                                             = 0;
	virtual U32                     GetAddMaxMana()                                                                                             = 0;   

	virtual void                      SetSpeed(U32 dwSpeed)                                                                                     = 0;  
	virtual int                       GetSpeed()                                                                                                  = 0; 
	virtual void                      AddBeDamageList(OBJID idUser)                                                                               = 0;
	virtual void                      GetBeDamageList(ID_VEC& setUserID)                                                                          = 0;
	virtual void                      GetBeDamageListSort(ID_VEC& setUserID)                                                                          = 0;
	virtual bool					  IsUserInBeDamageList(OBJID idUser)                                                                          = 0;
	virtual void					  ClearBeDamageList()                                                                                         = 0;
	virtual bool					  IsCanClearDamageList()                                                                                      = 0;

    virtual void                      AddKillHeroAmount(int num)                                                                                  = 0;
    virtual void					  SetKillHeroAmount(int num)																				  = 0;
	virtual int                       GetKillHeroAmount()                                                                                         = 0;
	virtual void					  ClearKillHeroAmount()                                                                                       = 0;
	virtual void					  IncDeathAmount()                                                                                       = 0;
	virtual float					  GetDeathRate()																							  = 0;

	virtual void					  SetChaseDist(U32 dwDistance)                                                                              = 0;
	virtual U32					  GetChaseDist()                                                                                              = 0;

	virtual void					  SetTurnRate(float fRate)                                                                                    = 0;
	virtual float					  GetTurnRate()                                                                                               = 0;

	virtual void					  SetBat(U32 dwBat)                                                                                         = 0;
	virtual U32					  GetBat()                                                                                                    = 0;

	virtual const char*                   GetNormSillName()                                                                                           = 0;
	virtual U32                     GetNormSill()                                                                                               = 0;

	virtual U32                     GetSkillIndex()                                                                                             = 0;

	virtual void                      SetObSize(USHORT usSize)                                                                                    = 0;
	virtual USHORT                    GetObSize()                                                                                                 = 0;
	virtual bool					  GetLongRange()                                                                                              = 0;

	virtual bool					  GetReConnectFlag()                                                                                          = 0;
	virtual void 					  SetReConnectFlag(bool bflag)                                                                                = 0;
    virtual bool					  GetEscapeFlag()                                                                                             = 0;

    virtual bool		              GetHangFlag()                                                                                               = 0;
    virtual void 		              SetHangFlag(bool bflag)                                                                                     = 0;

    virtual bool		              GetHangBackFlag()                                                                                           = 0;
    virtual void		              SetHangBackFlag(bool bflag)                                                                                 = 0;

    virtual int                       GetMatchScore()                                                                                             = 0;
    virtual void                      SetMatchScore(int score)                                                                                    = 0;


    virtual int                       GetMatchOtherScore()                                                                                        = 0;
    virtual void                      SetMatchOtherScore(int score)                                                                               = 0;


    virtual void                      ReConnect(uint32 sock)                                                                                      = 0;

    virtual USHORT                    GetGameResult()                                                                                             = 0;
    virtual void                      SetGameResult(USHORT result)                                                                                = 0;

    virtual USHORT                    GetFreeRandomAmount()                                                                                       = 0;
    virtual void                      SetFreeRandomAmount(USHORT usAmount)                                                                        = 0;

    virtual USHORT                    GetRMBRandomAmount()                                                                                        = 0;
    virtual void                      SetRMBRandomAmount(USHORT usAmount)                                                                         = 0;

    virtual int                       GetTitle()                                                                                                  = 0;
    virtual void                      SetTitle(int usAmount)                                                                                      = 0;

    virtual int                       GetRank()                                                                                                  = 0;
    virtual void                      SetRank(int usAmount)                                                                                      = 0;

    virtual int                       GetBaseMagicAttack()                                                                                       = 0;
    virtual void                      SetBaseMagicAttack(int magicAttack)                                                                        = 0;

	virtual int                       GetMagicAttack()																							 = 0;
	virtual void                      SetMagicAttack(int magicAttack)																			 = 0;

    virtual int                       GetEvaluateState()                                                                                         = 0;
    virtual void                      AddEvaluateState(int state)                                                                                = 0;

    virtual void                      SetNameplateBadge(int nameplate)                                                                           = 0;
    virtual int                       GetNameplateBadge()                                                                                        = 0;

    virtual void                      SetNameplateTitle(int nameplate)                                                                           = 0;
    virtual int                       GetNameplateTitle()                                                                                        = 0;

    virtual void                      SetNameplateBaseboard(int nameplate)                                                                       = 0;
    virtual int                       GetNameplateBaseboard()                                                                                    = 0;

    virtual void                      SetPlatformLevel(int level)                                                                                = 0;
    virtual int                       GetPlatformLevel()                                                                                         = 0;

    virtual void                      SetRobotControl(OBJID IdControl)																			 = 0;
    virtual OBJID                     GetRobotControl()                                                                                          = 0;		

    virtual void                      AddMoreKillHeroAmount(int amount)                                                                          = 0;
    virtual void                      SetMoreKillHeroAmount(int amount)																			 = 0;
	virtual int                       GetMoreKillHeroAmount()                                                                                    = 0;	

    virtual int                       GetMoreKillHeroMost()                                                                                      = 0;
    virtual int                       GetSerisKillHeroMost()                                                                                     = 0;	

    virtual int                       GetCollideRaid()																			                 = 0;
	
	virtual void					  SetSpiritProp(U32 topRatio, U32 initRatio, U32 growRatio, U32 growInterval,LPROLESPIRITPROP &prop) = 0;	
	virtual void					  GetSpiritProp(U32 &curRatio, LPROLESPIRITPROP &spirit)													 = 0;
	virtual void					  SetMastery(LPMasteryProp& prop)																			 = 0;
	virtual void					  GetMastery(LPMasteryProp& prop)																		     = 0;
	virtual void					  SetPVEGameHeroes(LPPVEGameHeroVec& heroes, LPPVEGameHeroVec& pets)																 = 0;
	virtual void					  GetPVEGameHeroes(LPPVEGameHeroVec& heroes)																 = 0;
	virtual void					  GetPVEGamePets(LPPVEGameHeroVec& pets)																	 = 0;
	virtual void					  SetPVERebornStone(uint32 nAmount)																			 = 0;
	virtual uint32					  GetPVERebornStone()																						 = 0;
	virtual void					  SetPVEHeroScore(uint32 nScore)																			 = 0;
	virtual uint32					  GetPVEHeroScore()																							 = 0;
	virtual void					  SetPVEFeat(uint32 nFeat) = 0;
	virtual uint32					  GetPVEFeat() = 0;
	virtual uint32					  GetPVEHeroMaxScore()																							 = 0;
	virtual void					  SetPVEItems(LPPVEItemVec& items)																			 = 0;
	virtual void					  DecPVEItemAmount(uint32 idItemType)																		 = 0;
	virtual int						  GetPVEItemAmount(uint32 idItemType)																		 = 0;
	virtual int						  GetSpiritParryChance()																	                 = 0;
	virtual int						  GetMasteryParryChance()																				     = 0;
	virtual int						  GetPVEGameHeroDuck()																						 = 0;
	virtual U32					  GetHit() = 0;
	virtual U32					  GetPhyPass() = 0;
	virtual U32					  GetCrit() = 0;
	virtual U32					  GetCritRes() = 0;
	virtual U32					  GetPhySuck() = 0;
	virtual U32					  GetSpePass() = 0;
	virtual U32					  GetSpeSuck() = 0;
	virtual U32					  GetSpeCd() = 0;
	virtual U32					  GetToughness() = 0;
	virtual U32					  GetToughnessPenetration() = 0;	

    virtual void                      SetServerKey(U32 dwServerKey)                                                                            = 0;
    virtual U32                     GetServerKey()                                                                                             = 0;
    virtual bool                      GetWaiGuaFlag()                                                                                            = 0;
    virtual void                      SetWaiGuaFlag(bool bFlag)                                                                                  = 0;

	virtual void                      AddResourceList(OBJID idSource)																		     = 0;
	virtual bool                      IsResourceTimeOut(OBJID idSource)                                                                          = 0;

	virtual void                      SetWorldId(uint32 worldId)																				 = 0;
	virtual uint32                    GetWorldId()																								 = 0;

	virtual void                      SetPlatformId(uint32 platformId)																		     = 0;
	virtual uint32                    GetPlatformId()																							 = 0;

	virtual void                      SetMainHeroUserId(OBJID idUser)																			 = 0;
	virtual OBJID                     GetMainHeroUserId() const                                                                                  = 0;
	virtual void					  RebindHeroPetSocket(uint32 sock)																			 = 0;
	virtual void					  SplicePetAttribute()																						 = 0;
	virtual void					  SetDefaultPassiveSkillId(uint32 skillid) = 0;
	virtual uint32					  GetDefaultPassiveSkillId() = 0;


    //-------------------------------------------- MoneyLog  ----------------------------------------------------------------------------------------------
    virtual void   GameMoneyLog(UCHAR ucType,
                                OBJID idUser,
                                int   nNumber,
                                int   idTarget,
                                U32 dwData0,
                                U32 dwData1,
                                U32 dwData2,
                                OBJID idCostItem,
                                I64   nCost,
                                I64   nCostBonus) = 0;
    virtual bool SpendRMBAndLog(U32         nRMB,
                                unsigned char type,
                                int           id_source,
                                int           id_target,
                                U32         dwItemType,
                                int           sourceBalance,
                                int           targetBalance) = 0;
    virtual bool InsertEmoney3Log(unsigned char type,
                                  int           id_source,
                                  int           id_target,
                                  int           number,
                                  U32         dwItemType,
                                  int           sourceBalance,
                                  int           targetBalance) = 0;

    virtual bool SpendEmoney3AndLog(U32 dwMoney3, 
		                            UCHAR type, 
									int id_source, 
									int id_target, 
									U32 dwItemType, 
									int sourceBalance,
                                    int targetBalance) = 0;

	//Dota 代码
	virtual void MoneyAccumulation() = 0;
	virtual int GetMoneyAccumulation() = 0;
	virtual void	SetMoneyAdditionalAccumulation(int money) = 0;
    virtual void    SetMoneyRate(int rate, int type)=0;
    virtual int GetMoneyRate(int type) = 0;
    virtual void    SetExtraMoney(int rate, int type)=0;
    virtual int GetExtraMoney(int type) = 0;
	virtual int     GetBeKillExtraMoney() = 0;
	virtual void    SetBeKillExtraMoney(int nBeKillExtraMoney)= 0;
	virtual int     GetBeKillSecondaryExtraMoney()= 0;
	virtual void    SetBeKillSecondaryExtraMoney(int nBeKillSecondaryExtraMoney)= 0;
    virtual void    SetTalent(ID_VEC&)=0;
    virtual ID_VEC* GetTalent() = 0;
	virtual void    SetHeroSkin(U32 skin)=0;
	virtual U32  GetHeroSkin()=0;
	virtual int GetExtraSecondaryAttackMoney() =0;
	virtual void SetExtraSecondaryAttackMoney(int money) = 0;
	virtual void	SetAutoMoneyRate(int rate) = 0;
	virtual int		GetAutoMoneyRate()= 0;
	virtual void	SetDeadMoneyPercent(int p)=0;
	virtual void	DropDeadMoney()=0;
	virtual void    SetBrainToMagicAttackPercent(int p)=0;
    virtual void	AddSecAddMoney(int money) = 0;
    virtual int		GetSecAddMoney()= 0;
};

typedef std::vector<IUser*> USER_VEC;

class IUserType
{
    DELETE_DISABLED(IUserType)
public:
    virtual const tq::AUTOLINK_NOTE* QueryLink()								= 0;
    virtual	OBJID		GetID(void)										const	= 0;
    virtual I64		    GetAttr(ZOMBIE_USER_ATTRIBUTE_TYPE eType)		const   = 0;
	virtual float		GetFAttr(ZOMBIE_USER_ATTRIBUTE_TYPE eType)		const   = 0;
    virtual const char*              GetStr(ZOMBIE_USER_ATTRIBUTE_TYPE eType)                        const = 0;

//  virtual bool        GetInfo(ITEM_INFO& rInfo, bool bWeapon) const   = 0;
};

} // end namespace entity

#endif

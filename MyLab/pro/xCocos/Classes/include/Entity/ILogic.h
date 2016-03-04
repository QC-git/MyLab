// -*- C++ -*-

//=============================================================================
/**
 *  @file    ILogic.h
 *
 *  $Id: ILogic.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _ILOGIC_H_
#define _ILOGIC_H_

#include "Define.h"
//#include "Msg/IMsgUserAttrib.h"
#include "StrID.h"

namespace entity
{
class IUser;
class ISpiritEx;
class ILogic
{
public:
    virtual const tq::AUTOLINK_NOTE* QueryLink() = 0;

    //下面函数不管理地图物品,地图物品优地图物品管理器自动管理
    virtual void SendMsg(OBJID idRole, const tq::CMsg& msg) = 0;
    virtual void BroadcastWorldMsg(const tq::CMsg& msg, OBJID idExclude = ID_NONE)        = 0;
	virtual void BroadcastHallMsg(const tq::CMsg& msg, OBJID idExclude = ID_NONE)         = 0;
    virtual void SendSysMsg(OBJID idRole, const char* pszMsg, uint32_t dwColor = 0xff0000, int nAttribute = _TXTATR_SYSTEM, int nTxtStyle =  _TXT_NORMAL)           = 0;

    virtual bool CreateUser(uint32 sck, OBJID idUser, INT nVipLevel, bool bPMEnable = false, bool bAdult = true) = 0;
    virtual bool LoginUser(uint32 sck, OBJID idUser, int nVipLevel) = 0;
    virtual bool KickOutUser(OBJID idActor, const char* pszReason) = 0;
    virtual void UnloadUser(OBJID idUser, uint32 sck = 0)          = 0;
    virtual void KickOutAllUser(OBJID idActor)                     = 0;

    virtual bool ReconnectUser(uint32 sck, OBJID idActor)          = 0;

    virtual OBJID GetRoleMapID(OBJID idRole)                                                              const = 0;
    virtual bool GetRolePos(OBJID idRole, OBJPOS& posRole)                                               const  = 0;
    virtual void SetRolePos(OBJID idRole, const OBJPOS& posRole)                                                = 0;

    virtual I64 GetRoleEffect(OBJID idRole, int nIdex = 0)                                                          = 0;
    virtual void SetRoleEffect(OBJID idRole, I64 n64Effect, int nIdex = 0)                                            = 0;
    virtual U64 ResetRoleEffect(OBJID idRole, U64 un64Effect)                                                   = 0;
    virtual void SetRoleEffectValue(OBJID idRole, U64 un64Effect, int nIdex = 0)                                   = 0;
    virtual void RoleEnterTrape(OBJID idRole, OBJID idTrap)                                                           = 0;
    virtual bool IsRoleAreadyInThisTrape(OBJID idRole, OBJID idTrap)                                                  = 0;
    virtual int GetRoleLev(OBJID idRole) const                                                                        = 0;
    virtual const char* GetRoleName(OBJID idRole) const                                                               = 0;
    virtual uint32_t GetRoleLookFace(OBJID idRole) const                                                                 = 0;
    virtual int GetRolePkMode(OBJID idRole) const                                                                     = 0;
    virtual uint32_t GetRoleHair(OBJID idRole) const                                                                     = 0;
    virtual int GetRoleSizeAdd(OBJID idRole) const                                                                    = 0;
    virtual USHORT GetRoleCamp(OBJID idRole) const                                                                    = 0;
    virtual I64 GetRoleExp(OBJID idRole) const                                                                        = 0;
    virtual int GetRoleHair(USHORT usSex, USHORT usProfession)                                                        = 0;
    virtual int GetRoleDir(OBJID idRole) const                                                                        = 0;
    virtual void SetRoleDir(OBJID idRole, int nDir)                                                                   = 0;
    virtual int GetRolePose(OBJID idRole) const                                                                       = 0;
    virtual void SetRolePose(OBJID idRole, int nPose)                                                                 = 0;
    virtual void SetRoleMapID(OBJID idRole, OBJID idMap)                                                              = 0;
    virtual int GetRoleLife(OBJID idRole) const                                                                       = 0;
    virtual int GetRoleMaxLife(OBJID idRole) const                                                                    = 0;

//	virtual int			GetRoleCampSort(OBJID idRole) const = 0;
    virtual bool GetRoleFootPrint(OBJID idRole, OUT OBJPOS& posRole) const        = 0;
    virtual void SetRoleFootPrint(OBJID idRole, uint32_t tFootPrint, OBJPOS posRole) = 0;
    virtual bool IsRoleAlive(OBJID idRole) const                                  = 0;

    virtual bool GetDistortionRole(ID_VEC& vecDistortionRole, OBJID idMap)               = 0;

	virtual OBJID GetTempMonsterByUser(OBJID idUser)                                                          = 0;
    virtual bool ClearUserChooseMonster(OBJID idUser)                                                         = 0;
    virtual bool RecordUserEmoney(int nRcdType, OBJID idSource, OBJID idTarget, int nNumber)                  = 0;
    virtual uint32_t CalcEmoneyCardChksum(int nCardType, int nAccountID, int idRef)                              = 0;
	virtual int  SendInsMsg(OBJID userId, OBJID insId, const tq::CMsg msg) =0;

	//World
//	virtual bool CreateWorld()
};
} // end namespace entity

#endif

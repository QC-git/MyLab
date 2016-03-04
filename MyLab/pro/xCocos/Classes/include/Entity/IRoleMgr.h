// ********************************************************************
//
// Copyright (c) 2007
// All Rights Reserved
//
// Author: lzx
// Created: 2007/11/18
//
// ********************************************************************

#ifndef _EN_IROLEMGR_H_
#define _EN_IROLEMGR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IUser.h"

namespace entity
{
	class IRoleMgr
	{
	public:
		virtual const tq::AUTOLINK_NOTE* QueryLink() = 0;
		virtual bool DeleteUserFromDB(OBJID idUser) = 0;

		// 创建用户插入容器
		virtual IUser* CreateUser(uint32 sck, OBJID idUser, int nVipLevel = 0, bool bPMEnable = false, bool bAdult = true) = 0;
		virtual void   DestroyUser(OBJID idUser) = 0;
		virtual bool   HoldingUser(OBJID idUser) = 0;

		virtual IRole* QueryRole(OBJID idRole) = 0;
		virtual IUser* QueryUser(OBJID idRole)                                     const = 0;
		virtual IUser* QueryUser(const char* szName)                               const = 0;

		virtual void  EnumUser(OUT USER_VEC& setUser) = 0;
		virtual void  EnumHallUser(OUT USER_VEC& setUser) = 0;
		virtual void  EnumUserID(OUT ID_VEC& setUserID, bool bIncludeGM) = 0;
		virtual OBJID EnumBegin() = 0;
		virtual OBJID EnumNext() = 0;
		virtual void  EnumPKUser(ID_VEC& setUserID) = 0;

		virtual uint32_t GetUserAmount(void) = 0;
		virtual void  GetMapUserSet(OBJID idMap, ID_VEC& userSet) = 0;
		virtual int   GetMapUserCount(OBJID idMap) = 0;
		virtual int   GetMapUserAliveCount(OBJID idMap) = 0;
		virtual bool  OnLoginGS(OBJID idUser) = 0;
		virtual bool  OnHoldGS(bool bResult, OBJID idUser) = 0;
		virtual bool  OnLogoutGS(OBJID idUser) = 0;
		virtual bool  OnLoginAIS(OBJID idUser) = 0;

		virtual void  UserEnterGameHall(OBJID idUser) = 0;
		virtual void  UserLevGameHall(OBJID idUser) = 0;

		virtual OBJID GetGM() = 0;
		virtual void  BroadcastGMMsg(const tq::CMsg& Msg, OBJID idExcludeSender = ID_NONE) = 0;
		virtual void  DelGm(OBJID idUser) = 0;

		virtual OBJID GetAndDelDeadBodyMapItem(OBJID idUser) = 0;

		virtual bool EmoneyLog(const char* szCostLogFileName,
			int         nOperType,
			OBJID       idUser,
			int         nCostEmoney,
			OBJID       idTarget,
			uint32_t       dwData0,
			uint32_t       dwData1,
			uint32_t       dwData2,
			OBJID       idCostItem,
			int         nCost,
			int         nCostBonus,
			int         sourceBalance,
			int         targetBalance) = 0;

		//用户存日志到数据库
		virtual bool InsertEmoneyLog(const char*   szCostLogFileName,
			const char*   szCardLogFileName,
			unsigned char type,
			int           id_source,
			int           id_target,
			int           number,
			uint32_t         dwItemType,
			int           sourceBalance,
			int           targetBalance,
			const OBJID   idUser,
			const OBJID   idAccount,
			const char*   pName) = 0;

		virtual bool InsertRMBLog(unsigned char type,
			int           id_source,
			int           id_target,
			int           number,
			uint32_t         dwItemType,
			int           sourceBalance,
			int           targetBalance,
			const OBJID   idUser,
			const OBJID   idAccount,
			const char*   pName) = 0;

		//离线玩家的数据更新
		virtual bool OfflineGainMoney(const OBJID idUser, const uint32_t dwMoney) = 0;
		virtual bool OfflineMoneySaved(const OBJID idUser, const uint32_t dwMoney) = 0;
		virtual bool OfflineGainRMB(const OBJID idUser, const uint32_t dwRMB, uint32_t* pRMBBalance = NULL) = 0;

		virtual int       	 FindUnallowName(const char* pszName)  const = 0;
		virtual bool      	 SetTempMonster(OBJID idUser, OBJID idMonster) = 0;
		virtual OBJID     	 GetTempMonsterByUser(OBJID idUser) = 0;
		virtual bool      	 ClearUserChooseMonster(OBJID idUser) = 0;
		virtual IUserType*	 GetUserAttType(int iLevel) = 0;
		virtual int       	 GetUserAttType(int iLevel, ZOMBIE_USER_ATTRIBUTE_TYPE eType) = 0;
		virtual void      	 ResumeLifeAndMana(OBJID idUser) = 0;
		virtual int       	 GetRoleNotChange(ID_SET& setRole, ID_SET& heroContracts) = 0;
		virtual bool      	 IsFreeHero(OBJID lookface) = 0;
		virtual bool      	 IsOpenHero(OBJID lookface) = 0;
		virtual OBJID	  	 RandHeroNotChoosed(ID_SET& heroChoosed) = 0;
		virtual bool	  	 ExistHero(OBJID idHero, bool& bFresh) = 0;
		virtual bool	  	 ReLoadUserDataAttr() = 0;
		virtual bool		 CreateHeroPet(OBJID idPlayer, OBJID idHeroPet) = 0;
		virtual OBJID		 GetPetPlayerID(OBJID idUser) = 0;
	};

} // end namespace entity

#endif

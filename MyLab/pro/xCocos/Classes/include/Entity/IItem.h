// ********************************************************************
//
// Copyright (c) 2007
// All Rights Reserved
//
// Author: lzx
// Created: 2007/11/18
//
// ********************************************************************

#ifndef _EN_IITEM_H_
#define _EN_IITEM_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Map/IGameObj.h"

namespace entity
{
    class IItem : public IGameObj
	{
		DELETE_DISABLED(IItem)
	public:
		virtual const tq::AUTOLINK_NOTE* QueryLink()													= 0;
        virtual I64			GetAttr(ITEMDATA eType)												const   = 0;
        virtual bool	    SetAttr(ITEMDATA eType, I64 n64Data, bool bUpdate=true)						= 0;
        virtual const char*	GetStr(ITEMDATA enType)												const   = 0;
        virtual bool	    SetStr(ITEMDATA eType, const char* pszData, bool bUpdate=true)				= 0;
		virtual bool		GetInfo(ITEM_INFO& info, bool bItemEx)										    const	= 0;
		virtual OBJID		GetItemType()														const	= 0;
		virtual	I64         GetItemTypeAttr(ITEMTYPEDATA eType)									const	= 0;	
		virtual const char* GetItemTypeStr(ITEMTYPEDATA eType)									const	= 0;
		virtual int			CalcItemChkSum()															= 0;
		virtual void		ReSetItemChkSum()															= 0;
		virtual bool		IsChkSumPass()																= 0;
		virtual int			GetLife()															const		= 0;	
		virtual void		SetAddLevelUsage(int nUsage)													= 0;
		virtual bool		IsChkSumItem(int nType)															= 0;
		virtual bool		IsInvalueItem(int nType)														= 0;
		virtual int			GetLevel()																		= 0;
		virtual bool		SaveInfo()																		= 0;
		virtual bool		IsWPGBadge()	= 0;
		virtual void		SetForgename(const char* szName, UPDATE_BOOL bUpdate=UPDATE_FALSE) = 0;
        
		//AMMO
		virtual OBJID       GetAmmoID() = 0;
		virtual void        AddAmmo(OBJID idAmmo, int nNum)=0;
		virtual void        DelAmmo(OBJID idAmmo)=0;
		virtual void        EquipAmmo(OBJID idAmmo, int nNum)=0;
		virtual int         GetCurrAmmoAmount()=0;
		virtual void        SetCurrAmmoAmount(int nNum)=0;
		virtual void        AddCurrAmmoAmount(int nNum)=0;
		virtual bool        IsCanFlow()=0;
		virtual void        ResetUnFlow(int nMsel)=0;

		virtual uint32_t		GetDeadTime() const = 0;
		virtual void		SetDeadTime(uint32_t dwDeadTime) = 0;
	};
	
	class IItemType
	{
		DELETE_DISABLED(IItemType)
	public:
		virtual const tq::AUTOLINK_NOTE* QueryLink()								= 0;
        virtual	OBJID		GetID(void)										const	= 0;
        virtual I64		    GetAttr(ITEMTYPEDATA eType)						const   = 0;
        virtual const char*	GetStr(ITEMTYPEDATA enType)						const   = 0;
		virtual bool		GetInfo(ITEM_INFO& rInfo, bool bWeapon)	const	= 0;
	};
	
	class IItemAddtion
	{
	public:
        virtual I64		    GetAttr(ITEMADDITIONDATA eType)				const   = 0;
        virtual const char*	GetStr(ITEMADDITIONDATA enType)				const   = 0;
		virtual bool	    SetAttr(ITEMADDITIONDATA eType, I64 n64Data, bool bUpdate = true) = 0;
	};
}

#endif

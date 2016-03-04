// ********************************************************************
//
// Copyright (c) 2007
// All Rights Reserved
//
// Author: lzx
// Created: 2007/11/18
//
// ********************************************************************

#ifndef _EN_IITEMMGR_H_
#define _EN_IITEMMGR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IItem.h"

namespace entity
{
	typedef std::vector<IItem*>		ITEMS_VEC;

	class IItemMgr
	{
	public:
		virtual const tq::AUTOLINK_NOTE* QueryLink() = 0;
		virtual IItem*			CreateItem(const ITEM_INFO& info, bool bItemEx, bool bInsert = true) = 0;
		virtual IItem*			CreateItem(OBJID idItemType, OBJID idOwner, bool bItemEx, int nPostion = ITEMPOSITION_BACKPACK) = 0;
		//virtual bool			CreateItem(const db::REC_VEC& rRec, ID_VEC& rVecItem) = 0;
		virtual bool			DestroyItem(OBJID idItem) = 0;
		virtual bool            DestoryUserItem(OBJID idUser) = 0;

		virtual bool            LoadDetainItem(OBJID idItem, bool bLoadToDetain) = 0;
		virtual bool			LoadItemsByPlayerID(OBJID idPlayer, ITEMS_VEC& setItems) = 0;
		virtual bool			LoadUserStorageItem(OBJID idOwner, int nPosition, OBJID idPlayer, ID_VEC& vecItems) = 0;
		virtual bool			LoadUserStorageItemEx(OBJID idOwner, int nPosition, OBJID idPlayer, ID_VEC& vecItems) = 0;
		virtual bool			LoadUserPackage(OBJID idOwner, int ownertype, OBJID idPlayer, ID_VEC& setItems) = 0;
		virtual bool			LoadUserTradePackage(OBJID idPlayer, int ownertype, ITEMS_VEC& setItems) = 0;

		virtual bool            LoadUserItem(OBJID idUser, ID_VEC& rVecItem) = 0;
		virtual bool			UnLoadItem(OBJID idItem) = 0;
		virtual IItem*			QueryItem(OBJID idItem) = 0;
		virtual bool			DestroyDetainItem(OBJID idItem) = 0;
		virtual IItem*			QueryDetainItem(OBJID idItem) = 0;
		virtual IItemType*		QueryItemType(OBJID idItemType) = 0;
		virtual IItemAddtion*	QueryItemAddition(OBJID idType, int nLevel) = 0;
		virtual IItemAddtion*	QueryItemAdditionMax(OBJID idType) = 0;
		virtual IItemAddtion*	QueryMaxItemAddition(OBJID idType) = 0;	//获得level字段值最大的记录。末日危机新增
		virtual OBJID			GetRandBySellType(const int nSellType) = 0;

		// ItemValue根据需要扩展
		virtual U32				GetItemValue(OBJID idItem) = 0;
		virtual	bool			IsItemValuable(OBJID idItem) = 0;
		virtual	bool			IsItemWorth(OBJID idItem) = 0;
		virtual int				GetItemRatio(void) const = 0;
		virtual void			SetItemRatio(int nRatio) = 0;

		//detainequip
		virtual bool            QueryDetainItemInfo(OBJID idDetainItem, ITEM_INFO& itemInfo, bool bItemEx) = 0;
		virtual int				GetDetainItemRansom(OBJID idDetainItem) = 0;
		virtual bool			DetainItem(OBJID idItem) = 0;
		virtual bool			UnDetainItem(OBJID idItem) = 0;

		virtual bool			GetItemTypeInfo(OBJID idType, ITEM_INFO* pInfo, bool bWeapon) = 0;
		virtual bool			ChangeType(OBJID idItem, OBJID idNewType) = 0;
		virtual bool            ChangeColor(OBJID idItem, int nColor) = 0;

		virtual OBJID			CloneItem(OBJID idItem) = 0;
		virtual int				GetItemShapeByType(OBJID idType, int nMicroLev) = 0;
		virtual bool		    SaveItemInfo(OBJID idItem, bool bDel) = 0;
		virtual bool		    GunEquipAmmo(OBJID idGun, OBJID idAmmo) = 0;
		virtual void            ResetUnFlow(OBJID idItem, int nMsel) = 0;
		virtual void			GetItemComponent(OBJID idItem, OUT MAP_ITEM_COMPONENTTYPE** p) = 0;
		virtual void			GetItemProduct(OBJID idItem, OUT ID_SET** p) = 0;
	};
}

#endif
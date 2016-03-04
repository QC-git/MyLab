// -*- C++ -*-

//=============================================================================
/**
 *  @file    ICommonPackProvider.h
 *
 *  $Id: ICommonPackProvider.h 2009-01-13 14:33:41 $
 *
 *  @author xxx
 *  note:  this class need refactor, use high level memory allocator!
 */ 
//=============================================================================
#ifndef _COMMONPACK_IBACKPACKPROVIDER_H_
#define _COMMONPACK_IBACKPACKPROVIDER_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "../IBaseProvider.h"

namespace entityex
{

class IProvider : public adapter::IBaseProvider
{
	DELETE_DISABLED(IProvider);
public:		
	//spirit backpack
//	virtual bool	InitUserBackPack(OBJID idUser)	 = 0;
//	virtual bool	DelSpiritBackPack(OBJID idUser)	 = 0;
	
//	virtual bool	FindNewUserBackPackPos(OBJID idUser, int nShape, int& nPosDir)	= 0;
//	virtual	bool	IsUserBackPackChangeSizeEnable(OBJID idUser, int nSize, int nWidth, int nOldPackShape, OBJID idNewPack, vector<TPOSDIR_INFO>& AdjustItemTPosDirSet, bool& bFullChangPositionFlag)	= 0;
//	virtual	bool	ChangeUserBackPackItemPosition(OBJID idUser, OBJID idItem, int nNewPos)	= 0;
//	virtual	bool	ResetUserBackPackShapeMng(OBJID idUser, int nSize, int nWidth)	= 0;
//	virtual	bool	PlaceUserBackPackItem(OBJID idUser, OBJID idItem, int nShape, int nPosDir)	= 0;
//	virtual	bool	ResetUserPackSize(OBJID idUser, int nPos)	= 0;
//	virtual	OBJID	GetItemByTypeFromUserBackPack(OBJID idUser, int nType)	= 0;
	virtual	bool	IsUserBackPackShapePosEnable(OBJID idUser, int nShape, int nPosition, OBJID idExcludeItem=ID_NONE) = 0;
	virtual	bool	AddObjNoShapeToUserBackPack(OBJID idUser, OBJID idItem, bool bUseImmediately) = 0;
	virtual bool	AddUserBackItemAutoArrange(OBJID idUser, OBJID idItem)	= 0;
	virtual bool	IsUserBackPackEmpty(OBJID idUser) = 0;
	virtual bool	IsUserBackpackEnableWidthHeight(OBJID idUser, int nMaxWidth, int nMaxHeight, int& nPosDir, int nWeight)	= 0;
//	virtual	int		GetUserBackPackSize(OBJID idUser) = 0;
	virtual	int		GetUserBackPackItemCount(OBJID idUser) = 0;
	virtual void	OnTimer() = 0;
	
	//user backpack 
//	virtual bool	DelUserBackPack(OBJID idUser)	= 0;
	virtual	bool	FindNewUserBackPackPos(OBJID idUser, int nShape, int& pPosDir)	= 0;
//	virtual	bool	IsUserBackPackCorrupt(OBJID idUser)	= 0;
	virtual bool	IsUserBackPackHasItem(OBJID idUser, OBJID idItem)	= 0;
	virtual OBJID	IsUserBackPackHasItem(OBJID idUser, NEWTYPE nType)	= 0;
	virtual	bool	IsUserBackPackSpaceEnable(OBJID idUser, const std::vector<int>& setShape, int nWeight=0, OBJID idExcludeItem=ID_NONE)	= 0;
	virtual	bool	IsUserBackPackSpaceEnable(OBJID idUser, int nShape, int nWeight=0, OBJID idExcludeItem=ID_NONE)	= 0;
	virtual	bool	PopItemFromUserBackPack(OBJID idUser, OBJID idItem)	= 0;
	virtual bool	DelItemFromUserBackPack(OBJID idUser, OBJID idItem)	= 0;
	virtual bool	AddItemToUserBackPack(OBJID idUser, OBJID idItem, bool bAutoArrange=true)	= 0;
	virtual	bool	ChangeUserBackPackSize(OBJID idUser, int nSize, int nWidth, int nWeightLimit)	= 0;
	virtual	bool	IsUserBackPackChangeSizeEnable(OBJID idUser, int nSize, int nWidth, int nOldPackShape, OBJID idNewPack, vector<TPOSDIR_INFO>& AdjustItemTPosDirSet, bool& bFullChangPositionFlag)	= 0;
	virtual	bool	ChangeUserBackPackItemPosition(OBJID idUser, OBJID idItem, int nNewPos) 	= 0;
	virtual bool    SetUserBackPackItemPosition(OBJID idUser, OBJID idItem, int nNewPos)    = 0;
	virtual	bool	ResetUserBackPackShapeMng(OBJID idUser, int nSize, int nWidth)	= 0;
	virtual	bool	PlaceUserBackPackItem(OBJID idUser, OBJID idItem, int nShape, int nPosDir)	= 0;
	virtual	bool	ResetUserPackSize(OBJID idUser, int nPos)	= 0;
	virtual	OBJID	GetItemByTypeFromUserBackPack(OBJID idUser, int nType, ID_VEC* pvec = NULL)	= 0;
	virtual bool	IsUserBackPackSpare(OBJID idUser, const SHAPE_SET& setShape, int nWeight) = 0;
	virtual bool	RandDropItem(OBJID idDropUser, OBJID idOwnerUser,  RANDDROP_KIND eKind)	= 0;
//	virtual bool    RandDropBodyItem(OBJID idDropUser, OBJID idOwner, const int nDropCount) = 0;
	virtual	bool	IsUserBackPackSpare(OBJID idUser, int nShape, int nPosDir, int nWeight) = 0;	
	virtual bool	IsUserBackPackSpare(OBJID idUser, int nShape, int nWeight) = 0;
	virtual	int		GetUserBackPackSize(OBJID idUser) = 0;
	virtual	int		GetUserBackPackFreeSize(OBJID idUser) = 0;

	virtual bool	AllPackGunEquipAmmo(OBJID idUser) = 0;
	virtual void	GunEquipAmmo(OBJID idUser, OBJID idGun, bool IsNeedTime = true) = 0;

	//spirit enginroom
//	virtual	bool	IsSpiritEngineRoomSpaceEnable(OBJID idUser, int nShape, int nWeight=0, OBJID idExcludeItem=ID_NONE)	= 0;
//	virtual bool	IsUserEngineRoomEmpty(OBJID idUser) = 0;
//	virtual	OBJID	GetTrumpByItemTypeFromSpiritEngineRoom(OBJID idUser, OBJID idItemType) = 0;
//	virtual OBJID	GetEnginRoomChipType(OBJID idUser, int nType)	= 0;

	//user enginroom 
//	virtual	bool	PopItemFromUserEngineRoom(OBJID idUser, OBJID idItem)	= 0;
//	virtual bool	DelItemFromUserEngineRoom(OBJID idUser, OBJID idItem)	= 0;
//	virtual	bool	FindNewPosInUserEngineRoom(OBJID idUser, int& pPosDir, int nShape)	= 0;
//	virtual bool    AddItemToUserEngineRoom(OBJID idUser, OBJID idItem, bool bAutoArrange=true)	= 0;
//	virtual OBJID	GetEquipFromUserEngineRoom(OBJID idUser, int nPos, int nUnikeyIndex=0)	= 0;
	// Quanta
//	virtual bool	ResetQuantaPackAccumulate(OBJID idUser)	= 0;

	virtual bool	GetUserBackPackItemCount(OBJID idUser, int nShape, int nWeight) = 0;
	virtual bool	GetUserBackPackItemCount(OBJID idUser, int nShape, int nPosDir, int nWeight) = 0;
	virtual bool	GetUserBackPackItemCount(OBJID idUser, const SHAPE_SET& setShape, int nWeight) = 0;
	virtual	bool	IsUserAddWeightEnable(OBJID idUser, int nWeight) = 0;
	virtual int		GetUserAllWeight(OBJID idUser) = 0;


	virtual bool	GetUserPackBackItem(OBJID idUser, ID_VEC& vecItemID) = 0;
	
//	virtual bool	ChangeUserPackSize(OBJID idUser, int nSize, int nWidth, int nWeightLimit, int nPosition = ITEMPOS_ENGINEROOM)	= 0;
	virtual bool    DecreaseAllEquipDurability(OBJID idUser, int nDurability, const int nLimitCount, bool bIncludePackFlag)	= 0;						


//	virtual bool	PopItemFromUserPack(OBJID idUser, OBJID idItem, int nPos = ITEMPOS_BACKPACK)	= 0;
//	virtual bool	AddItemToUserPack(OBJID idUser, OBJID idItem, bool bAutoArrange=true, int nPos = ITEMPOS_BACKPACK)	= 0;
//	virtual bool	DelItemFromUserPack(OBJID idUser, OBJID idItem, int nPos = ITEMPOS_BACKPACK)	= 0;
//	virtual bool	IsUserPackHasItem(OBJID idUser, OBJID idItem, int nPos = ITEMPOS_BACKPACK)		= 0;
	virtual bool	SendPackItemInfo(OBJID idUser, int nPos = ITEMPOS_BACKPACK)	= 0;
    virtual void    SendUserPackBackItemInfo(OBJID idRec , OBJID idRole,int nPos = ITEMPOS_BACKPACK) = 0;
	virtual void	GetUserPackBackItemInfo(OBJID idRole, SUserGameAbortInfo &info, int nPos = ITEMPOS_BACKPACK) = 0;
//	virtual bool	SaveUserPackItemInfo(OBJID idUser, int nPos = ITEMPOS_BACKPACK)	= 0;
	virtual bool	GetUserPackItem(OBJID idUser, ID_VEC& vecItemID, int nPos = ITEMPOS_BACKPACK) = 0;
//	virtual bool	ClearUserPack(OBJID idUser, int nPos = ITEMPOS_BACKPACK)	= 0;
	virtual bool	IsUserPackSpaceEnable(OBJID idUser, const std::vector<int>& setShape, int nWeight=0, OBJID idExcludeItem=ID_NONE, int nPos = ITEMPOS_BACKPACK) = 0;
	virtual void    SortUserBackPackItem(OBJID idUser, int nPos) = 0;

	//Dota´úÂë
	virtual bool	ClearUserBackPack(OBJID idUser) = 0;
    virtual	bool	ChangeUserBackPackItemPosition_Dota(OBJID idUser, OBJID idItem, int nNewPos) 	= 0;
};

} // end namespace entityex
#endif //_BACKPACK_IBACKPACKPROVIDER_H_


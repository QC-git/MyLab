// ********************************************************************
//
// Copyright (c) 2007
// All Rights Reserved
//
// Author: ywj
// Created: 2007/11/18
//
// ********************************************************************

#ifndef _EN_I_MAP_ATTR_MGR_H_
#define _EN_I_MAP_ATTR_MGR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace entity
{

class IMapAttrMgr
{
public:
    virtual const tq::AUTOLINK_NOTE* QueryLink() = 0;
	virtual bool QueryMapAttr( EDotaMap mapId, LPPVEGameHero& hero ) = 0;
	virtual U32 GetMaxMapGenCount( EDotaMap mapId ) = 0;
	virtual U32 GetMaxMapDamage( EDotaMap mapId ) = 0;
};

}

#endif

// ********************************************************************
//
// Copyright (c) 2007
// All Rights Reserved
//
// Author: ywj
// Created: 2014/07/10
//
// ********************************************************************

#ifndef _EN_I_PVE_HORNOR_MGR_H_
#define _EN_I_PVE_HORNOR_MGR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace entity
{

class IPVEHornorMgr
{
public:
	virtual U32			GetEventPoint(EDotaMap mapId, U32 nScore, EHornorType horType) = 0;
	virtual U32			GetBeKillPoint(EDotaMap mapId, U32 nScore) = 0;
	virtual U32			GetBeSecKillPoint(EDotaMap mapId, U32 nScore) = 0;
	virtual U32			GetFinalHornor(EDotaMap mapId, U32 nLev, U32 result, uint32 nHornor) = 0;
};

}

#endif

// -*- C++ -*-

//=============================================================================
/**
 *  @file    IGameObj.h
 *
 *  $Id: IGameObj.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _MAP3DDOC_IGAMEOBJ_H_
#define _MAP3DDOC_IGAMEOBJ_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Types.h>
#include <BaseCode/BaseMacro.h>

NAMESPACE_BEGIN(entity)

class IGameObj
{
public:
    virtual	void*	QueryObj	(OBJTYPE eType)     = 0;
    virtual OBJTYPE	GetObjType	() const			= 0;
    virtual	OBJID	GetID		() const			= 0;
    virtual void	OnTimer		()					= 0;

public:
    virtual OBJID	GetMapID()					const = 0;
    virtual void	SetMapID(OBJID idMap) = 0;

    virtual OBJPOS	GetPos()					const = 0;
    virtual void	SetPos(OBJPOS pos) = 0;

    virtual int		GetDir()					const = 0;
    virtual void	SetDir(int nDir) = 0;
};

NAMESPACE_END(entity)

#endif // end of define _MAP3DDOC_IGAMEOBJ_H_

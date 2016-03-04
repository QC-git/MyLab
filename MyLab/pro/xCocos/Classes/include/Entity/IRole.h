// -*- C++ -*-

//=============================================================================
/**
 *  @file    IRole.h
 *
 *  $Id: IRole.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _EN_IROLE_H_
#define _EN_IROLE_H_

#include "Map/IGameObj.h"

namespace entity
{

class IRole : public IGameObj
{
    DELETE_DISABLED(IRole)
public:
    virtual uint32 GetSocket(void) const = 0;

    virtual void   SendMsg(const tq::CMsg& rMsg)                                                                                          = 0;
    virtual void   SendSysMsg(const char* pszMsg, uint32_t dwColor = 0xFF0000, int nAttribute = _TXTATR_SYSTEM, int nTxtStyle = _TXT_NORMAL) = 0;
    virtual USHORT GetPose(void) const                                                                                                    = 0;
    virtual void   SetPose(USHORT usPose)                                                                                                 = 0;
    virtual int    GetEquipTypeVal(int nPos)                                                                                              = 0;
    virtual USHORT GetCamp()                                                                                                        const = 0;
    virtual void   SaveInfo()                                                                                                             = 0;
    virtual void   SetFootPrint(uint32_t tFootPrint, OBJPOS posRole)                                                                        = 0;
};

} // end namespace entity

#endif // _EN_IMAP_H_

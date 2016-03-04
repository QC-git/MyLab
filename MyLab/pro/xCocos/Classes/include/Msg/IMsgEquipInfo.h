// MsgItem.h: interface for the CMsgItem class.
/**
 *  @file   IMsgEquipInfo.h
 *
 *  $Id: IMsgEquipInfo.h 
 *
 *  @author chx <xxx@gmail.com>
 *  
 */
//==========================================================================

#ifndef _MSG_IMSGEQUIPINFO_H_
#define _MSG_IMSGEQUIPINFO_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#include "MsgDefine.h"
namespace msgequipinfo
{
	struct USEREQUIP_INFO
	{
		OBJID	idItem;
		OBJID	idType;
		USHORT	usPosition;
	};
	
	typedef struct 
	{
		USHORT		        usMsgSize;
		USHORT		        usMsgType;

		OBJID		        idUser;
		USHORT				usRecordAmount;
		USEREQUIP_INFO      setRecords[1]; 
		
	}MSG_EQUIPINFO;
}
#endif 


// -*- C++ -*-

//=============================================================================
/**
 *  @file    IBaseProvider.h
 *
 *  $Id: IBaseProvider.h  2009-03-28 17:00:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _ADAPTER_IBASEPROVIDER_H_
#define _ADAPTER_IBASEPROVIDER_H_

#include "Define.h"

namespace adapter
{
	class IBaseProvider
	{
	public:
		// idUser ��¼�ǳ�
		virtual bool OnLoginUser(OBJID idUser) = 0;
		virtual bool OnLogoutUser(OBJID idUser) = 0;

		//����ģ��֮�佻��ʹ��
		virtual bool OnCmdNotify(const ST_NOTIFY_CMD& stNotifyCmd)	= 0;
	};
}

#endif	// end of define _ADAPTER_IBASEPROVIDER_H_

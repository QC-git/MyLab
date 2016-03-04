//==========================================================================
/**
 *  @file   IMsgStatistic.h
 *
 *  $Id: IMsgStatistic.h 2009-01-20 16:03:40Z $
 *
 *  @author xxx <xxx@gmail.com>
 *  
 */
//==========================================================================
#ifndef _IMSG_STATISTIC_H_
#define _IMSG_STATISTIC_H_

#include "Define.h"

namespace msgstatistic
{
	enum
	{
		STATISTIC_QUERY_KILLAMOUNT	= 0 ,		// TC TS ɱ���¼�ɱ������
		STATISTIC_QUERY_KILLTYPE		,		// TC TS ɱ���¼�ɱĳ�ֹ�ͳ�� {{TS idMonsterType(����type)}}
		STATISTIC_QUERY_PK_KILL			,		// TC TS ��ͨPK�¼�ɱ���������ͳ��
		STATISTIC_QUERY_PK_DEAD			,		// TC TS ��ͨPK�¼����������ɱ��ͳ��
		STATISTIC_QUERY_WEEKPK_KILL		,		// TC TS ��PK���¼�ɱ���������ͳ��
		STATISTIC_QUERY_WEEKPK_DEAD		,		// TC TS ��PK���¼����������ɱ��ͳ��
		STATISTIC_QUERY_MONTHPK_KILL	,		// TC TS ��PK���¼�ɱ���������ͳ��
		STATISTIC_QUERY_MONTHPK_DEAD	,		// TC TS ��PK���¼����������ɱ��ͳ��
		STATISTIC_QUERY_SEASONPK_KILL	,		// TC TS ��PK���¼�ɱ���������ͳ��
		STATISTIC_QUERY_SEASONPK_DEAD	,		// TC TS ��PK���¼����������ɱ��ͳ��
	};
	
	typedef struct  {
		USHORT	usMsgSize;
		USHORT	usMsgType;
		
		USHORT	usAction;
		OBJID	idMonsterType;			// STATISTIC_QUERY_KILLTYPE ר��
		U32	dwData;
	}MSG_STATISTIC;
}

#endif	// _IMSG_STATISTIC_H_
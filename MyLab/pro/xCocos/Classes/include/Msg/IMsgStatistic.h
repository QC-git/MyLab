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
		STATISTIC_QUERY_KILLAMOUNT	= 0 ,		// TC TS 杀怪事件杀怪总数
		STATISTIC_QUERY_KILLTYPE		,		// TC TS 杀怪事件杀某种怪统计 {{TS idMonsterType(怪物type)}}
		STATISTIC_QUERY_PK_KILL			,		// TC TS 普通PK事件杀死其他玩家统计
		STATISTIC_QUERY_PK_DEAD			,		// TC TS 普通PK事件被其他玩家杀死统计
		STATISTIC_QUERY_WEEKPK_KILL		,		// TC TS 周PK赛事件杀死其他玩家统计
		STATISTIC_QUERY_WEEKPK_DEAD		,		// TC TS 周PK赛事件被其他玩家杀死统计
		STATISTIC_QUERY_MONTHPK_KILL	,		// TC TS 月PK赛事件杀死其他玩家统计
		STATISTIC_QUERY_MONTHPK_DEAD	,		// TC TS 月PK赛事件被其他玩家杀死统计
		STATISTIC_QUERY_SEASONPK_KILL	,		// TC TS 季PK赛事件杀死其他玩家统计
		STATISTIC_QUERY_SEASONPK_DEAD	,		// TC TS 季PK赛事件被其他玩家杀死统计
	};
	
	typedef struct  {
		USHORT	usMsgSize;
		USHORT	usMsgType;
		
		USHORT	usAction;
		OBJID	idMonsterType;			// STATISTIC_QUERY_KILLTYPE 专用
		U32	dwData;
	}MSG_STATISTIC;
}

#endif	// _IMSG_STATISTIC_H_
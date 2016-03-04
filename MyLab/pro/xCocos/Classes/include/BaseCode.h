// **********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created:	2004/11/03   0:19
//
// **********************************************************************

#ifndef	_TQ_BASECODE_H_
#define _TQ_BASECODE_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma  warning(disable: 4018)

#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "Macro.h"
#include "Utils.h"

// functions...
namespace tq
{
	//系统时间函数
	enum TIME_TYPE {TIME_MILLISECOND=0, TIME_SECOND, TIME_MINUTE, TIME_DAY, TIME_DAYTIME, TIME_STAMP, TIME_WEEKDAY, };
	enum DIFF_TIME_TYPE{DIFF_TIME_SECOND, DIFF_TIME_MINUTE, DIFF_TIME_HOUR, DIFF_TIME_DAY};

//	uint8_t*		DumpFuncAddress	(int nLevel=0, char* pBuf=NULL, PEXCEPTION_POINTERS pException=NULL);

	uint32_t		TimeGet			(TIME_TYPE type = TIME_MILLISECOND);
	void		DateTime		(char * buf20, time_t tInput = 0);		// 0 : curr time
	bool		FormatDateTime	(char* buf, const char* szFormat, time_t tInput = 0);		// szFormat: "%04d-%02d-%02d %02d:%02d:%02d"
	void		DateTimeStamp	(char * buf15, time_t tInput = 0);		// 0 : curr time
	int			DateStamp		(time_t tTime=0);
	int			DateStampPass	(int nDate, int nDays);			// return -1: error
    uint32_t			DateStampDiff(int nDateFrom, int nDateTo);	// 计算nDateFrom到nDateTo经过的天数
	uint32_t		GetDiffDay(DIFF_TIME_TYPE diffTimeType, UINT uStartTime, UINT uEndDayTime);//返回时间差,uStartTime、uEndDayTime均为YYMMDDHHMM的日期格式
	//bool		IsInValidDateTime(const SYSTEMTIME& st);
	//bool	IsActiveTime	(time_t tCurr, unsigned long nFormat);
	bool		IsTimeRange(unsigned long nBegin, unsigned long nEnd, time_t tCurr=0);
	uint32_t		SysTimeGet(void);
	uint32_t		SysTimeGetEx(void);  //月日时分秒 Year%100 *100000000 + (month+1)*1000000 + day*10000 + hour*100 + min
	uint32_t		SysTimeGetMin(void); //年月日时分

	//int			SystemTime2Days(const SYSTEMTIME& st);
	//uint32_t		SystemTime2Hours(const SYSTEMTIME& st);
	//time_t		SystemtimeToSeconds(SYSTEMTIME st);
	//SYSTEMTIME  SecondsToSystemtime(uint32_t dwGameDateTimeSeconds);
	int			ShortDateStamp(time_t tTime = 0);
	uint32_t	    GetCurrTime();
	uint32_t		GetYYMMDDHHMM(time_t tCur=0);

	int		AddHour(int dwCurYYMMDDhh, int nHour);
	int		AddMin(int dwCurYYMMDDhhmm, int nMin);
	int     AddDay(int dwCurYYMMDD, int nDays);
	int		Time_DaysDiff( int nYYMMDD1, int nYYMMDD2);
	uint32_t		Time_HourDiff( int YYMMDDhh1, int YYMMDDhh2);
	int		Time_MinuteDiff( int YYMMDDhhmm1, int YYMMDDhhmm2);
	
	int		RandGet			(INT nMax, bool bRest=false);
	double	RandomRateGet	(double dRange);
    uint32_t	BuildDaysGet    (void);
    int		Double2Int		(double dValue);

	bool	StrCopy			(char* pszTarget, const char* pszSource, UINT unBufSize);
	bool	StrCheck		(const char* pszString, bool bNewLineEnable=false);
	bool	NameStrCheck	(const char* pszString);
	bool	LegalStrCheck	(const char* pszString, bool bNewLineEnable=false);
	
	void	ConsoleWriteStr (uint32_t nCoordX, uint32_t nCoordY, const char* fmt, ... );
	void	ConsoleSetup	(uint32_t dwWindowSizeX = 80, uint32_t dwWindowSizeY = 80 );

	uint32_t	MaxAxisOffsetGet(OBJPOS posThis, OBJPOS posThat);
	bool	IsValidDistance	(OBJPOS lhs, OBJPOS rhs, UINT unDistance);
	
	void	DDALine			(int x0, int y0, int x1, int y1, int nRange, std::vector<OBJPOS>& vctPoint);
	void	DDALineEx		(int x0, int y0, int x1, int y1, std::vector<OBJPOS>& vctPoint);
	void    DDALineExtend   (int x0, int y0, int x1, int y1, int nRange, std::vector<OBJPOS>& vctPoint);

	bool	GetGameConfig	(uint32_t& dwMaxPlayer, uint32_t& dwServerID, char* pszDBServer, char* pszDBUser, char* pszDBPsw, char* pszDBName, UINT& unDBPort);

	int		Distance(int x1, int y1, int x2, int y2);
	inline int	Distance(const OBJPOS& pos1, const OBJPOS& pos2)	{ return tq::Distance(pos1.x, pos1.y, pos2.x, pos2.y);}

	double RandomRateGetSinSqrtTwo(double dRange);

	template <class T>
	bool	RandomElementGet(std::vector<T>& vecElement, OUT T& element)
	{
		if (vecElement.empty())
		{
			return false;
		}
		UINT unIndex = tq::RandGet(vecElement.size());
		IF_NOT (unIndex >= 0 && unIndex < vecElement.size())
		{
			return false;
		}
		element = vecElement[unIndex];
		return true;
	}

	//////////////////////////////////////////////////////////////////////
	inline void	CombineAdjAdd(int& nAdj, int& nAdd, int nData)
	{
		if(nData > ADJUST_PERCENT)
		{
			if(nAdj == 0)
				nAdj	= PERCENT_BASE;
			nAdj	+= (nData - ADJUST_PERCENT) - PERCENT_BASE;
		}
		else
			nAdd	+= nData;
	}
	
	//////////////////////////////////////////////////////////////////////
	inline int	CombinePercent(int nAdj1, int nAdj2, int nBase/*=100*/)
	{
		if(nAdj1 == 0)
			nAdj1	= nBase;
		if(nAdj2 == 0)
			nAdj2	= nBase;
		return (nAdj1 + nAdj2) - nBase;
	}

	//////////////////////////////////////////////////////////////////////
	
	inline void	CombineDefAdj(int& nDef, int& nAdj, int nData)
	{
		/*
		if(nData > ADJUST_PERCENT)
		{
			if(nAdj == 0)
				nAdj	= PERCENT_BASE;
			nAdj	= ::MulDiv(nAdj, (nData - ADJUST_PERCENT), PERCENT_BASE);
		}
		else
			nDef	+= nData;
		*/
	}

	inline bool	 Probability(int nProb, int nBase=100)	{ return (RandGet(nBase) < nProb); }
	inline int	 AddToTop(int nData, int nAdd, int nTop) { int res=nData+nAdd; if(nAdd>0 && res<nData || res>nTop) return nTop; else return res; }
	inline int	 MulDivUp(int nVal, int nMul, int nDiv)  { IF_NOT(nDiv!=0)return 0; return ((nVal-1) * nMul / nDiv) + 1; }
	inline int   pos2index(int x, int y, int cx, int cy) { return (x + y*cx); }
	inline int   index2x(int idx, int cx, int cy) { return (idx % cy); }
	inline int   index2y(int idx, int cx, int cy) { return (idx / cy); }
	inline void  pos2lt(POINT* pTarget, const POINT& pos, int nRange) { pTarget->x = pos.x - nRange; pTarget->y = pos.y - nRange; }
	inline void  posadd(POINT* pTarget, int nOffsetX, int nOffsetY) { pTarget->x += nOffsetX; pTarget->y += nOffsetY; }
	inline void  possub(POINT* pTarget, int nOffsetX, int nOffsetY) { pTarget->x -= nOffsetX; pTarget->y -= nOffsetY; }

	/////////////////////////////////////////////////////////////////////////////
	inline unsigned int	ExchangeShortBits(unsigned long nData, int nBits)
	{
		ASSERT(nBits >= 0 && nBits < 16);
		nData	&= 0xFFFF;
		return ((nData>>nBits) | (nData<<(16-nBits))) & 0xFFFF;
	}
	
	inline unsigned int	ExchangeLongBits(unsigned long nData, int nBits)
	{
		ASSERT(nBits >= 0 && nBits < 32);
		return (nData>>nBits) | (nData<<(32-nBits));
	}

	inline int	RangeRandGet(int nMin, int nMax, bool bReset=false)
	{
		int nRange = nMax - nMin;
		if (nRange > 0) {
			// RAND_MAX is defined as the value 0x7fff.
			return ((stdrand() << 15) + stdrand()) % nRange + nMin;
		}
		
		return nMin;
	}
	//随机算法2
	//[nBegin,nEnd]区间取出nNum个数
	inline bool RandGetIndex(std::vector<int>& vecResult, const int nBegin, const int nEnd, const int nNum)
	{
		vecResult.clear();
		const int nTotal = nEnd - nBegin + 1;
		if (nTotal < 0)
		{
			ASSERT(false);
			return false;
		}
		
		vecResult.reserve(nTotal);
		for (int i = nBegin; i <= nEnd; ++i)
			vecResult.push_back(i);
		
		if (nTotal <= nNum)
		{
			return true;
		}
		
		/* 打乱顺序 */
		for (int i = 0; i < nTotal; i++)
		{
			std::swap(vecResult[i], vecResult[stdrand()%nTotal]);
		}
		
		std::vector<int>::iterator itEraseBegin = vecResult.begin();
		std::advance(itEraseBegin, nNum);
		vecResult.erase(itEraseBegin, vecResult.end());
		
		ASSERT(vecResult.size()==nNum);
		
		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <class T> inline void RandGetIndexByLimitCount(std::vector<T>& set1, const int nLimitCount)
	{//指定数量，随机挑选的玩家2007-2-28 tcp add 经测试在开发机器上本算法耗时3000集合最大耗时1毫秒左右
		if(nLimitCount<1)
			return;
		
		const int nConstCount = set1.size();	
		if(nLimitCount>=nConstCount)
			return;

		int nIndex =0;
		int nIndexSecond =0;

		T t;
		int nCount = nConstCount;
		if(1==nLimitCount)
		{
			nIndex= RandGet(nCount); 
			nCount--;		
			if(!(nIndex>=0 && nIndex < nConstCount))
			{
				return;
			}
			if(!(nCount>=0 && nCount < nConstCount))
			{
				return;
			}
			if(nCount==nIndex)
				return;
			t=set1[nCount];
			set1[nCount]= set1[nIndex];
			set1[nIndex] = t;
			return;
		}
		if(nLimitCount <= (nConstCount/2))
		{
			for(int i=0; i < nLimitCount; i++)
			{
				nIndex= RandGet(nCount); 
				nIndexSecond = RandGet(nCount); 			
				nCount--;		  		   		  
				if(!(nIndex>=0 && nIndex < nConstCount))
				{
					continue;
				}
				
				if(!(nCount>=0 && nCount < nConstCount))
				{
					continue;
				}
				
				if(nCount == nIndex)
					continue;
				
				if(!(nIndexSecond>=0 && nIndexSecond < nConstCount))
				{
					continue;
				}
				
				t=set1[nCount];
				set1[nCount]= set1[nIndex];
				set1[nIndex]= set1[nIndexSecond];
				set1[nIndexSecond] = t;
			}
		}
		else
		{
			int nNoBeSelectCount = nConstCount - nLimitCount;
			nCount = 0; 
			
			for(int i=0; i<nNoBeSelectCount; i++)
			{
				nIndex= RandGet(nConstCount-nCount); 
				if(!(nIndex>=0 && nIndex<nConstCount))
				{
					continue;
				}
				if(!(nCount>=0 && nCount<nConstCount))
				{
					continue;
				}
				if(nCount == nIndex)
				{
					nCount++;
					continue;
				}
				nIndexSecond = RandGet(nConstCount-nCount); 
				if(!(nIndexSecond>=0 && nIndexSecond < nConstCount))
				{
					continue;
				}
				nCount++;
				t=set1[nCount];
				set1[nCount]= set1[nIndex];
				set1[nIndex]= set1[nIndexSecond];
				set1[nIndexSecond] = t;
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	
	inline int	CombineAdjust(int nAdj1, int nAdj2)	{ return CombinePercent(nAdj1, nAdj2, PERCENT_BASE); }
    inline bool	IsRobot(OBJID idRole)		{ return idRole >= SPIRIT_ID_FIRST && idRole <= SPIRIT_ID_LAST; }
	inline bool	IsSynPetHero(OBJID idRole)	{ return idRole >= PETHEROID_FIRST && idRole <= PETHEROID_LAST; }
	inline bool IsPlayerID(OBJID idRole)	{ return (idRole >= PLAYER_ID_FIRST && idRole <= PLAYER_ID_LAST) || IsRobot(idRole) || IsSynPetHero(idRole); }
	inline bool IsMonsterID(OBJID idRole)	{ return (idRole >= MONSTERID_FIRST && idRole <= MONSTERID_LAST); }
	inline bool IsSceneID(OBJID idRole)		{ return (idRole >= SCENEID_FIRST && idRole <= SCENEID_LAST); }
	inline bool IsTrapID(OBJID idRole)		{ return (idRole >= TRAPID_FIRST && idRole <= TRAPID_LAST); }
	inline bool IsSysNpc(OBJID idRole)      { return (idRole >= SYSNPCID_FIRST && idRole <= SYSNPCID_LAST); }
	inline bool IsDynaNpcID(OBJID idRole)	{ return (idRole >= DYNANPCID_FIRST && idRole <= DYNANPCID_LAST); }
	inline bool	IsCallPet(OBJID idRole)		{ return idRole >= CALLPETID_FIRST && idRole <= CALLPETID_LAST; }
	inline bool	IsSynPet(OBJID idRole)		{ return idRole >= PETID_FIRST && idRole <= PETID_LAST; }
	inline bool	IsSpirit(OBJID idRole)		{ return idRole >= SPIRIT_ID_FIRST && idRole <= SPIRIT_ID_LAST; }
	inline bool IsDynaMap(OBJID idMap)		{ return idMap >= DYNAMIC_MAP_ID; }
	inline bool	IsBooth(OBJID idRole)		{ return (idRole >= BOOTH_ID_FIRST && idRole<= BOOTH_ID_LAST);}
	inline bool	IsInstanceMap(OBJID idMap)  { return (idMap >= COPY_MAPID_FIRST && idMap <= COPY_MAPID_LAST); }
	
	inline bool IsAIMonsterID(OBJID idRole)		{ return idRole >= MONSTERID_FIRST && idRole <= PETID_LAST; }
	//inline bool	IsTradeCaravanPet(OBJID idRole)		{ return (idRole >= TRADECARAVANIDPET_FIRST && idRole<= TRADECARAVANIDPET_LAST);}
	inline bool IsAINpcID(OBJID idRole)		{ return idRole >= AISERVERID_FIRST && idRole <= AISERVERID_LAST; }
	inline bool IsAINpcAndPet(OBJID idRole) { return IsAINpcID(idRole) || IsCallPet(idRole); }
	inline bool IsHero(OBJID idRole)        { return IsRobot(idRole) || IsPlayerID(idRole) || IsSynPetHero(idRole); }

	inline bool IsDevilID(OBJID idDevil)    { return idDevil >= DEVIL_ID_FIRST && idDevil <= DEVIL_ID_LAST;}
	inline int Pos2Index(int x, int y, int cx, int cy) { return (x + y*cx); }
	inline int Index2X(int idx, int cx, int cy) { return (idx % cy); }
	inline int Index2Y(int idx, int cx, int cy) { return (idx / cy); }
    inline bool IsComputer(OBJID idRole) { return IsSynPet(idRole) || IsRobot(idRole) || IsSynPetHero(idRole);}
	
	template<typename T>
	inline T	CutOverflow(T x, T y)
	{
		return (x <= y) ? x : y; 
	}

	template<typename T>
	inline T	CutTrail(T x, T y) 
	{
		return (x >= y) ? x : y; 
	}

	template<typename T>
	inline T	CutRange(T n, T min, T max)
	{
		return (n<min) ? min : ((n>max) ? max : n); 
	}

	//必须通过NUMERIC_CAST使用
//	template<typename Target, typename Source>
//		inline
//		Target _numeric_cast_log ( Source arg)
//	{
//		try
//		{
//			return boost::numeric_cast<Target,Source>(arg);
//		}
//		catch(boost::numeric::bad_numeric_cast& ex)//拦截异常
//		{
//// 			std::stringstream strm;
//// 			strm << "bad_numeric_cast, arg=" << arg;
//			tq::log_InlineLogError("bad_numeric_cast [%s]->[%s], %s", typeid(Source).name(), typeid(Target).name(), ex.what());
//		//	assert(false);
//		}
//		//再次转换，保证外面业务正常进行
//		return static_cast<Target>(arg);
//	}
//#define NUMERIC_CAST(TargetT, SourceV)	tq::SetLogConditional(__FILE__,__LINE__)?(tq::_numeric_cast_log<TargetT>(SourceV)):(tq::_numeric_cast_log<TargetT>(SourceV))


	inline int GetDirByPos(int nFromX, int nFromY, int nToX, int nToY)		// return MAX_DIRSIZE: error
	{
		if(nFromX < nToX) // 6, 5, 4
		{
			if(nFromY < nToY)
				return 7;
			else if(nFromY > nToY)
				return 5;
			else
				return 6;
		}
		else if(nFromX > nToX)
		{
			if(nFromY < nToY)
				return 1;
			else if(nFromY > nToY)
				return 3;
			else
				return 2;
		}
		else // if(nFromX == nToX)
		{
			if(nFromY < nToY)
				return 0;
			else if(nFromY > nToY)
				return 4;
		}

		return 8;
	}

	const int  MAXMONTHCOUNT =12;
	const uint16_t MONTHDAYSARRAY[MAXMONTHCOUNT][2]={
		{31,31},//JAN
		{28,29},//FEB
		{31,31},//MAR
		{30,30},//APR
		{31,31},//MAY
		{30,30},//JUN
		{31,31},//JUL
		{31,31},//AUG
		{30,30},//SEP
		{31,31},//AUG
		{30,30},//NOV
		{31,31},//DEC
	};
//	const uint16_t MONTHTATOLDAYSARRAY[MAXMONTHCOUNT+1][2]={
//		{						  0						 ,                         0					  },//		
//		{MONTHTATOLDAYSARRAY[ 0][0]+MONTHDAYSARRAY[ 0][0],MONTHTATOLDAYSARRAY[ 0][1]+MONTHDAYSARRAY[ 0][1]},//JAN
//		{MONTHTATOLDAYSARRAY[ 1][0]+MONTHDAYSARRAY[ 1][0],MONTHTATOLDAYSARRAY[ 1][1]+MONTHDAYSARRAY[ 1][1]},//FEB
//		{MONTHTATOLDAYSARRAY[ 2][0]+MONTHDAYSARRAY[ 2][0],MONTHTATOLDAYSARRAY[ 2][1]+MONTHDAYSARRAY[ 2][1]},//MAR
//		{MONTHTATOLDAYSARRAY[ 3][0]+MONTHDAYSARRAY[ 3][0],MONTHTATOLDAYSARRAY[ 3][1]+MONTHDAYSARRAY[ 3][1]},//APR
//		{MONTHTATOLDAYSARRAY[ 4][0]+MONTHDAYSARRAY[ 4][0],MONTHTATOLDAYSARRAY[ 4][1]+MONTHDAYSARRAY[ 4][1]},//MAY
//		{MONTHTATOLDAYSARRAY[ 5][0]+MONTHDAYSARRAY[ 5][0],MONTHTATOLDAYSARRAY[ 5][1]+MONTHDAYSARRAY[ 5][1]},//JUN
//		{MONTHTATOLDAYSARRAY[ 6][0]+MONTHDAYSARRAY[ 6][0],MONTHTATOLDAYSARRAY[ 6][1]+MONTHDAYSARRAY[ 6][1]},//JUL
//		{MONTHTATOLDAYSARRAY[ 7][0]+MONTHDAYSARRAY[ 7][0],MONTHTATOLDAYSARRAY[ 7][1]+MONTHDAYSARRAY[ 7][1]},//AUG
//		{MONTHTATOLDAYSARRAY[ 8][0]+MONTHDAYSARRAY[ 8][0],MONTHTATOLDAYSARRAY[ 8][1]+MONTHDAYSARRAY[ 8][1]},//SEP
//		{MONTHTATOLDAYSARRAY[ 9][0]+MONTHDAYSARRAY[ 9][0],MONTHTATOLDAYSARRAY[ 9][1]+MONTHDAYSARRAY[ 9][1]},//AUG
//		{MONTHTATOLDAYSARRAY[10][0]+MONTHDAYSARRAY[10][0],MONTHTATOLDAYSARRAY[10][1]+MONTHDAYSARRAY[10][1]},//NOV
//		{MONTHTATOLDAYSARRAY[11][0]+MONTHDAYSARRAY[11][0],MONTHTATOLDAYSARRAY[11][1]+MONTHDAYSARRAY[11][1]},//DEC	
//	};

	/*
	inline SYSTEMTIME Days2MonthDay(uint16_t wYear,uint16_t wDays)
	{//从公元元年开始
		SYSTEMTIME st={1980,1,1,1,0,0,0,0};	
		bool bFlag	=	false;	
		if((wYear%4==0 && wYear%100!=0) || wYear%400==0)
		{
			bFlag	=	true;	   
		}
		
		int i=0;
		if(bFlag)
		{
			IF_NOT(wDays>=0 && wDays<=366)
			{
				return st;
			}
			i=1;
		}
		else
		{
			IF_NOT(wDays>=0 && wDays<=365)
			{
				return st;
			}	
			i=0;
		}
		
		int nCount    = 0;
		int nMaxIndex = MAXMONTHCOUNT+1;
		int nMinIndex = 0;	
		int nIndex    = 0;
		while(1)
		{
			IF_NOT(nIndex>=0 && nIndex<MAXMONTHCOUNT)
			{
				return st;
			}
			nIndex = (nMinIndex+nMaxIndex)/2;
			if(MONTHTATOLDAYSARRAY[nIndex][i]>wDays)
			{
				nMaxIndex = nIndex;
			}
			else
			{
				nMinIndex = nIndex;
			}
			if((nMaxIndex-nMinIndex)==1)
				break;
			DEAD_LOOP_BREAK(nCount, MAXMONTHCOUNT);
		}
		st.wYear  = wYear;	
		st.wMonth = nMinIndex+1;
		wDays -= MONTHTATOLDAYSARRAY[nMinIndex][i];
		st.wDay   = wDays+1;
		return st;
	}

	const int MAXYEARSCOUNT =4;
	const SYSTEMTIME SYSTEMTIMEARRAY[MAXYEARSCOUNT]={
		{0	 ,1,1,1,0,0,0,0},		
		{1000,1,1,1,0,0,0,0},
		{2000,1,1,1,0,0,0,0},
		{3000,1,1,1,0,0,0,0}};
	const uint32_t DAYSARRAY[MAXYEARSCOUNT]={	
		SystemTime2Days(SYSTEMTIMEARRAY[0]),
		SystemTime2Days(SYSTEMTIMEARRAY[1]),
		SystemTime2Days(SYSTEMTIMEARRAY[2]),
		SystemTime2Days(SYSTEMTIMEARRAY[3])};
	const uint32_t ADDDAYSARRAY[MAXYEARSCOUNT]={
		DAYSARRAY[0]-SYSTEMTIMEARRAY[0].wYear*365,
		DAYSARRAY[1]-SYSTEMTIMEARRAY[1].wYear*365,
		DAYSARRAY[2]-SYSTEMTIMEARRAY[2].wYear*365,
		DAYSARRAY[3]-SYSTEMTIMEARRAY[3].wYear*365
	};

	inline SYSTEMTIME Days2SystemTime(uint32_t dwDays, uint16_t wHours)
	{
		SYSTEMTIME st={1980,1,2,1,wHours,0,0,0};	
		if(dwDays>=DAYSARRAY[MAXYEARSCOUNT-1] )
		{
			return st;
		}
		uint16_t wDayOfWeek = uint16_t((dwDays+6)%7);
		int nIndex=0;
		for(int i=MAXYEARSCOUNT-1;i>=0;i--)
		{
			if(dwDays>=DAYSARRAY[i])
			{
				nIndex=i;
				break;
			}		
		}			
		
		dwDays -= DAYSARRAY[nIndex];
		
		int nMaxYear	=	dwDays / 365;
		int nRestDays = dwDays % 365;			
		nMaxYear+=SYSTEMTIMEARRAY[nIndex].wYear;	
		
		int nTime4		=	nMaxYear/4;
		int nTime100	=	nMaxYear/100;
		int nTime400	=	nMaxYear/400;
		int nTimes	    =	nTime4-(nTime100-nTime400);
		int nDay		=	nTimes+1;
		
		bool bFlag	=	false;
		if((nMaxYear%4==0 && nMaxYear%100!=0) || nMaxYear%400==0)
		{
			bFlag	=	true;	   
		}	
		if(bFlag)
			nDay--;	
		
		nDay -= ADDDAYSARRAY[nIndex];
		
		if(nRestDays<nDay)
		{
			nMaxYear--;
			nRestDays += 365;
			nRestDays -= nDay;
			if(!bFlag)
			{
				if((nMaxYear%4==0 && nMaxYear%100!=0) || nMaxYear%400==0)
				{
					nRestDays++;
				}
			}
		}
		else
		{
			nRestDays -= nDay;		
		}
		st=Days2MonthDay(nMaxYear,nRestDays);
		st.wDayOfWeek = wDayOfWeek;
		st.wHour = wHours;
		return st;
	}
	*/
}


#endif // _TQ_BASECODE_H_


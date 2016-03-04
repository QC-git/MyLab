// **********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created:	2004/11/03   0:28
//
// **********************************************************************

#ifndef	_TQ_TIMER_H_
#define _TQ_TIMER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <algorithm>
#include <time.h>


namespace tq
{
	//////////////////////////////////////////////////////////////////////
	// 超时类，以“秒”为单位
	//////////////////////////////////////////////////////////////////////
	class CTimer  
	{
	public:
		CTimer(int nIntervalSecs = 0) { m_nInterval = nIntervalSecs; m_tUpdateTime = 0; }		// =0 : 用于数组初始化
		// virtual ~CTimer() {}
		CTimer& operator = (const CTimer& rhs)
		{
			m_nInterval		= rhs.m_nInterval;
			m_tUpdateTime	= rhs.m_tUpdateTime;
			return *this;
		}
		
	public:
		// 设置时间标签
		void	Update		(void)					{ m_tUpdateTime = ::time(NULL); }
		
		// 用于定时触发的连续时钟。每次触发时为true。
		bool	ToNextTime	(void)					{ if(this->IsTimeOut()) return this->Update(),true; else return false; }
		
		// 初始化时间片。(但不启动
		void	SetInterval	(int nSecs)				{ m_nInterval = nSecs; }
		
		// 开始启动时钟(同SetInterval)
		void	Startup		(int nSecs)				{ m_nInterval = nSecs; this->Update(); }
		
		// 时钟是否触发(只触发一次)，与Startup配合使用，可实现只触发一次的时钟。
		bool	TimeOver	(void)					{ if(this->IsActive() && this->IsTimeOut()) return this->Clear(),true; return false; }
		void	Clear		(void)					{ m_tUpdateTime = m_nInterval = 0; }
		bool	IsActive	(void)					{ return m_tUpdateTime != 0; }
		void	IncInterval	(int nSecs, int nLimit)	{ m_nInterval = (std::min)(m_nInterval+nSecs, nLimit); }
		void	DecInterval	(int nSecs)				{ m_nInterval = (std::max)(m_nInterval-nSecs, 0); }
		
		// 检查是否超时
		bool	IsTimeOut	(void)					{ return ::time(NULL) >= m_tUpdateTime+m_nInterval; }
		
		// 检查是否超时了指定时间片。用于同一时间标签检查多个不同超时事件。(可实现一个对象控制多个时钟)
		bool	IsTimeOut	(int nSecs)				{ return ::time(NULL) >= m_tUpdateTime+nSecs; }
		
		// 用于变长的超时事件。
		bool	ToNextTime	(int nSecs)				{ if(this->IsTimeOut(nSecs)) return this->Update(),true; else return false; }
		
		// 时钟会积累，但积累值不超过间隔值。其它同ToNextTime(...)
		bool	ToNextTick	(int nSecs);
		//	void	AppendInterval	(int nSecs)			{ if(ToNextTime()) m_nInterval=nSecs; else m_nInterval+=nSecs; }	// ToNextTime(): 保证至少有nSecs秒
		
	public: // get
		int		GetRemain()							{ return m_tUpdateTime ? (std::min)((std::max)(m_nInterval - ((int)::time(NULL)-(int)m_tUpdateTime), 0), m_nInterval) : 0; }
		int		GetInterval()						{ return m_nInterval;}
		
	protected:
		int		m_nInterval;
		time_t	m_tUpdateTime;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	// 超时类，以“毫秒”为单位
	//////////////////////////////////////////////////////////////////////
	class CTimerMS
	{
	public:
		CTimerMS(int nIntervalSecs = 0) { m_nInterval = nIntervalSecs; m_tUpdateTime = 0; }		// =0 : 用于数组初始化
		// virtual ~CTimerMS() {}
		CTimerMS& operator = (const CTimerMS& rhs)
		{
			m_nInterval		= rhs.m_nInterval;
			m_tUpdateTime	= rhs.m_tUpdateTime;
			return *this;
		}
		
	public:
		void	Update		(void)					{ m_tUpdateTime = clock(); }
		bool	IsTimeOut	(void)					{ return clock() >= m_tUpdateTime+m_nInterval; }
		bool	ToNextTime	(void)					{ if(IsTimeOut()) return Update(),true; else return false; }
		void	SetInterval	(int nMilliSecs)		{ m_nInterval = nMilliSecs; }
		
		void	Startup		(int nMilliSecs)		{ m_nInterval = nMilliSecs; Update(); }
		bool	TimeOver	(void)					{ if(IsActive() && IsTimeOut()) return Clear(),true; return false; }
		void	Clear		(void)					{ m_nInterval = m_tUpdateTime = 0; }
		bool	IsActive	(void)					{ return m_tUpdateTime != 0; }
		void	IncInterval	(int nMilliSecs, int nLimit)		{ m_nInterval = (std::min)(m_nInterval+nMilliSecs, nLimit); }
		void	DecInterval	(int nMilliSecs)		{ m_nInterval = (std::max)(m_nInterval-nMilliSecs, 0); }
		
		bool	IsTimeOut	(int nMilliSecs)		{ return clock() >= m_tUpdateTime+nMilliSecs; }
		bool	ToNextTime	(int nMilliSecs)		{ if(IsTimeOut(nMilliSecs)) return Update(),true; else return false; }
		bool	ToNextTick	(int nMilliSecs);
		//	void	AppendInterval	(int nMilliSecs)	{ if(ToNextTime()) m_nInterval=nMilliSecs; else m_nInterval+=nMilliSecs; }	// ToNextTime(): 保证至少有nSecs秒
		
	public: // get
		int		GetInterval	(void)					{ return m_nInterval; }
		clock_t	GetUpdateTime(void)					{ return m_tUpdateTime; }
		
	protected:
		int		m_nInterval;
		clock_t	m_tUpdateTime;
	};
}



#endif // _TQ_TIMER_H_

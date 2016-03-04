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
	// ��ʱ�࣬�ԡ��롱Ϊ��λ
	//////////////////////////////////////////////////////////////////////
	class CTimer  
	{
	public:
		CTimer(int nIntervalSecs = 0) { m_nInterval = nIntervalSecs; m_tUpdateTime = 0; }		// =0 : ���������ʼ��
		// virtual ~CTimer() {}
		CTimer& operator = (const CTimer& rhs)
		{
			m_nInterval		= rhs.m_nInterval;
			m_tUpdateTime	= rhs.m_tUpdateTime;
			return *this;
		}
		
	public:
		// ����ʱ���ǩ
		void	Update		(void)					{ m_tUpdateTime = ::time(NULL); }
		
		// ���ڶ�ʱ����������ʱ�ӡ�ÿ�δ���ʱΪtrue��
		bool	ToNextTime	(void)					{ if(this->IsTimeOut()) return this->Update(),true; else return false; }
		
		// ��ʼ��ʱ��Ƭ��(��������
		void	SetInterval	(int nSecs)				{ m_nInterval = nSecs; }
		
		// ��ʼ����ʱ��(ͬSetInterval)
		void	Startup		(int nSecs)				{ m_nInterval = nSecs; this->Update(); }
		
		// ʱ���Ƿ񴥷�(ֻ����һ��)����Startup���ʹ�ã���ʵ��ֻ����һ�ε�ʱ�ӡ�
		bool	TimeOver	(void)					{ if(this->IsActive() && this->IsTimeOut()) return this->Clear(),true; return false; }
		void	Clear		(void)					{ m_tUpdateTime = m_nInterval = 0; }
		bool	IsActive	(void)					{ return m_tUpdateTime != 0; }
		void	IncInterval	(int nSecs, int nLimit)	{ m_nInterval = (std::min)(m_nInterval+nSecs, nLimit); }
		void	DecInterval	(int nSecs)				{ m_nInterval = (std::max)(m_nInterval-nSecs, 0); }
		
		// ����Ƿ�ʱ
		bool	IsTimeOut	(void)					{ return ::time(NULL) >= m_tUpdateTime+m_nInterval; }
		
		// ����Ƿ�ʱ��ָ��ʱ��Ƭ������ͬһʱ���ǩ�������ͬ��ʱ�¼���(��ʵ��һ��������ƶ��ʱ��)
		bool	IsTimeOut	(int nSecs)				{ return ::time(NULL) >= m_tUpdateTime+nSecs; }
		
		// ���ڱ䳤�ĳ�ʱ�¼���
		bool	ToNextTime	(int nSecs)				{ if(this->IsTimeOut(nSecs)) return this->Update(),true; else return false; }
		
		// ʱ�ӻ���ۣ�������ֵ���������ֵ������ͬToNextTime(...)
		bool	ToNextTick	(int nSecs);
		//	void	AppendInterval	(int nSecs)			{ if(ToNextTime()) m_nInterval=nSecs; else m_nInterval+=nSecs; }	// ToNextTime(): ��֤������nSecs��
		
	public: // get
		int		GetRemain()							{ return m_tUpdateTime ? (std::min)((std::max)(m_nInterval - ((int)::time(NULL)-(int)m_tUpdateTime), 0), m_nInterval) : 0; }
		int		GetInterval()						{ return m_nInterval;}
		
	protected:
		int		m_nInterval;
		time_t	m_tUpdateTime;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	// ��ʱ�࣬�ԡ����롱Ϊ��λ
	//////////////////////////////////////////////////////////////////////
	class CTimerMS
	{
	public:
		CTimerMS(int nIntervalSecs = 0) { m_nInterval = nIntervalSecs; m_tUpdateTime = 0; }		// =0 : ���������ʼ��
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
		//	void	AppendInterval	(int nMilliSecs)	{ if(ToNextTime()) m_nInterval=nMilliSecs; else m_nInterval+=nMilliSecs; }	// ToNextTime(): ��֤������nSecs��
		
	public: // get
		int		GetInterval	(void)					{ return m_nInterval; }
		clock_t	GetUpdateTime(void)					{ return m_tUpdateTime; }
		
	protected:
		int		m_nInterval;
		clock_t	m_tUpdateTime;
	};
}



#endif // _TQ_TIMER_H_

////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2008, TQ Digital Entertainment, All Rights Reserved
// Author:  Shen Rongfei
// Created: 2012/08/11
////////////////////////////////////////////////////////////////////////

#ifndef _CONST_DATA_DECORATOR_H_
#define _CONST_DATA_DECORATOR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
#include <stdint.h>

enum DOTA_ENTITY_DATA_TYPE
{
	DED_NULL,
	//damag(1~10000)
	///////////////////////////////
	//general(1~100)
	DED_DamageGeneral_powermin	= 1,
	DED_DamageGeneral_powermax  = 2,

	//damageDotHot(101~200)
	DED_DamageDotHot_powermin	= 101,
	DED_DamageDotHot_powermax	= 102,

	//damageEffect(201~300)
	DED_DamageEffect_adddamage	= 201,

	//state(10001~20000)
	////////////////////////////////
	//general(10001~10100)
	DED_EXPIRYTIME	= 10001,	//到期时间

	//buff(10101~10200)
	DED_StateBuff_resistancevalue	= 10101,

	//skill(20001~30000)
	///////////////////////////////
	//general(20001~20100)
	DED_cooldown = 20001,
	DED_skilltargetsort = 20002,

	//SkillDirection(20101~20200)
};

enum CONST_DECORATOR_OP
{
	CONST_DECORATOR_NULL = 0,
	CONST_DECORATOR_ADD	= 1,
	CONST_DECORATOR_ASSIGN	= 2,
	CONST_DECORATOR_PERCENT =3,
};

class CResultData
{
public:
	CResultData(double v):m_v(v) {}
	CResultData& operator =(double v) {m_v=v; return *this;}

	operator char() const {return m_v;}
	operator short() const {return m_v;}
	operator long() const {return m_v;}
	operator int() const {return m_v;}
	operator int64_t() const {return m_v;}
	operator float() const {return m_v;}

	operator unsigned char() const {if(m_v<0) return 0; return m_v;}
	operator unsigned short() const {if(m_v<0) return 0; return m_v;}
	operator unsigned long() const {if(m_v<0) return 0; return m_v;}
	operator unsigned int() const {if(m_v<0) return 0; return m_v;}
	operator uint64_t() const { if (m_v<0) return 0; return m_v; }

private:
	double m_v;
};

class CConstEntityDataDecorator
{
public:
	CConstEntityDataDecorator(double param, double paramPer, bool assign=false)
		:m_param(param),m_paramPer(paramPer),m_bAssign(assign)
	{}

	CResultData Do(double v)
	{
		if (m_bAssign)
			return m_param;

		if (m_paramPer > 0)
		{
			if (m_paramPer != 100)
				v = v * m_paramPer / 100;
		}
		else
		{
			v = 0;
		}
		return v + m_param;
	}

	friend class CConstEntityDataDecoratorMgr;
private:
	bool	m_bAssign;
	double m_param;
	double m_paramPer;
};

class CConstEntityDataDecoratorMgr
{
private:
	typedef std::map<DOTA_ENTITY_DATA_TYPE, CConstEntityDataDecorator*> MAP_CEDD;
	MAP_CEDD m_map;

public:
	CConstEntityDataDecoratorMgr() {}
	virtual ~CConstEntityDataDecoratorMgr()
	{
		Clear();
	}

	bool Add(DOTA_ENTITY_DATA_TYPE t, CONST_DECORATOR_OP op,double param)
	{
		if ((DED_NULL == t) || (CONST_DECORATOR_NULL == op))
			return false;

		MAP_CEDD::iterator it = m_map.find(t);
		if (it != m_map.end() && it->second)
		{
			if (CONST_DECORATOR_ADD == op)
				(it->second)->m_param += param;
			else if (CONST_DECORATOR_PERCENT == op)
				(it->second)->m_paramPer += param;
			else if (CONST_DECORATOR_ASSIGN == op)
			{
				(it->second)->m_bAssign = true;
				(it->second)->m_param = param;
			}

			return true;
		}

		CConstEntityDataDecorator* p = NULL;
		if (CONST_DECORATOR_ADD == op)
			p = new CConstEntityDataDecorator(param, 100);
		else if (CONST_DECORATOR_PERCENT == op)
			p = new CConstEntityDataDecorator(0, param + 100);
		else if (CONST_DECORATOR_ASSIGN == op)
			p = new CConstEntityDataDecorator(param, 100, true);

		if (0 == p)
			return false;

		std::pair<MAP_CEDD::iterator, bool> res;
		res = m_map.insert(MAP_CEDD::value_type(t, p));
		if (!res.second)
		{
			delete p;
			return false;
		}

		return true;
	}

	CConstEntityDataDecorator* Query(DOTA_ENTITY_DATA_TYPE t)
	{
		MAP_CEDD::iterator it = m_map.find(t);
		if (it != m_map.end())
			return it->second;
		return NULL;
	}

	void Clear()
	{
		if (m_map.empty())
			return;
		MAP_CEDD::iterator it = m_map.begin();
		for (; it != m_map.end(); ++it)
		{
			CConstEntityDataDecorator* p = it->second;
			if (p) delete p;
		}
		m_map.clear();
	}
};

template<typename T, DOTA_ENTITY_DATA_TYPE t>
class CConstEntityData
{
public:
	CConstEntityData& operator =(T v)
	{
		m_v = v;
		return *this;
	}

	T Value(CConstEntityDataDecoratorMgr* m) const
	{
		if (NULL == m)
			return m_v;

		CConstEntityDataDecorator* p = m->Query(t);
		if (NULL == p)
			return m_v;

		return p->Do(m_v);
	}
private:
	T m_v;
};

#endif
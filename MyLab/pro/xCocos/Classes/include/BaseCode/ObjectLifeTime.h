////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, TQ Digital Entertainment, 
// All Rights Reserved
//
// Author:  MILO
// Created: 11/10/2015
//
// Brief:   
////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdexcept>
#include "Platform/PlatformDefine.h"

namespace tq
{
	typedef void(*Destroyer)(void);

	inline void at_exit(void(*func)()){};

	template <class T>
	class ObjectLifeTime
	{
	public:
		inline static void ScheduleCall(void(*destroyer)())
		{
			// at_exit(destroyer);
		}

		DECLSPEC_NORETURN static void OnDeadReference(void) ATTR_NORETURN;
	};

	template <class T>
	inline void ObjectLifeTime<T>::OnDeadReference(void)// We don't handle Dead Reference for now
	{
		throw std::runtime_error("Dead Reference");
	}
}
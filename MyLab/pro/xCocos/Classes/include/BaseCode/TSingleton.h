////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, TQ Digital Entertainment, 
// All Rights Reserved
//
// Author:  MILO
// Created: 11/10/2015
//
// Brief:   
////////////////////////////////////////////////////////////////////////
#ifndef _TQ_TSINGLETON_H_
#define _TQ_TSINGLETON_H_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <map>
#include <memory>
#include <mutex>

#include "Types.h"
#include "CreationPolicy.h"
#include "ObjectLifeTime.h"

namespace tq
{
	template 
		<
		typename T,
		typename CreatePolicy = OperatorNew < T >,
		typename LifeTimePolicy = ObjectLifeTime < T >
		>	
	class TSingleton	
	{	
	public:
		static inline T& InstanceGet();
		static inline T* InstancePtrGet();

	protected:
		TSingleton(void){}

	private:
		TSingleton(const TSingleton&);
		TSingleton & operator= (const TSingleton &);

		// Singleton Helpers
		static void DestroySingleton();

	protected:
		static std::shared_ptr<T>	s_spInstance;
		static std::mutex			s_mutex;
		static bool					s_destroyed;
	};

	template < typename T, typename CreatePolicy, typename LifeTimePolicy > 
	std::shared_ptr<T> TSingleton<T, CreatePolicy, LifeTimePolicy>::s_spInstance;
	
	template < typename T, typename CreatePolicy, typename LifeTimePolicy >
	std::mutex TSingleton<T, CreatePolicy, LifeTimePolicy>::s_mutex;

	template < typename T, typename CreatePolicy, typename LifeTimePolicy >
	bool TSingleton<T, CreatePolicy, LifeTimePolicy>::s_destroyed = false;

	template < typename T, typename CreatePolicy, typename LifeTimePolicy >
	inline T& TSingleton<T, CreatePolicy, LifeTimePolicy>::InstanceGet()
	{
		if (!s_spInstance)
		{
			std::lock_guard<std::mutex> cs(s_mutex);
			if (!s_spInstance)
			{
				if (s_destroyed)
				{
					s_destroyed = false;
					LifeTimePolicy::OnDeadReference();
				}
				s_spInstance.reset(CreatePolicy::Create(), CreatePolicy::Destroy);
				LifeTimePolicy::ScheduleCall(&DestroySingleton);
			}
		}
		
		return *s_spInstance.get();
	}

	template < typename T, typename CreatePolicy, typename LifeTimePolicy >
	inline T* TSingleton<T, CreatePolicy, LifeTimePolicy>::InstancePtrGet()
	{
		if (!s_spInstance)
		{
			std::lock_guard<std::mutex> cs(s_mutex);
			if (!s_spInstance)
			{
				if (s_destroyed)
				{
					s_destroyed = false;
					LifeTimePolicy::OnDeadReference();
				}
				s_spInstance.reset(CreatePolicy::Create(), CreatePolicy::Destroy);
				LifeTimePolicy::ScheduleCall(&DestroySingleton);
			}
		}
		
		return s_spInstance.get();
	}

	template < typename T, typename CreatePolicy, typename LifeTimePolicy >
	inline void TSingleton<T, CreatePolicy, LifeTimePolicy>::DestroySingleton()
	{
		//CreatePolicy::Destroy(s_spInstance.get()); //MILO 这里使用shared_ptr管理，不需要显示的删除
		s_spInstance = NULL;
		s_destroyed = true;
	}
}


#endif // _TQ_TSINGLETON_H_
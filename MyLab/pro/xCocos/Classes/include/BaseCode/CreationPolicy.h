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

namespace tq
{
	/**
	* OperatorNew policy creates an object on the heap using new.
	*/
	template <class T>
	class OperatorNew
	{
	public:
		static T* Create(void) 
		{
			return (new T); 
		}
		
		static void Destroy(T *obj) 
		{
			delete obj; 
		}
	};

	/**
	* CreateWithCreateNew creates the object base on the call back.
	*/
	template<class T>
	class CreateWithCreateNew
	{
	public:
		static T* Create()
		{
			return T::CreateNew();
		}

		static void Destroy(T *p)
		{
			delete p;
		}
	};
}
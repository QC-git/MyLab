////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, TQ Digital Entertainment, 
// All Rights Reserved
//
// Author:  MILO
// Created: 11/6/2015
//
// Brief:   
////////////////////////////////////////////////////////////////////////
#pragma once

#include <type_traits>
#include <typeindex>

namespace tq {

	using namespace std;

	struct Any
	{
		template<typename U> Any(U && value) : m_ptr(new Derived < typename decay<U>::type>(forward<U>(value))),
			m_tpIndex(type_index(typeid(typename decay<U>::type))){}

		Any(void) : m_tpIndex(type_index(typeid(void))){}
		Any(Any& that) : m_ptr(that.Clone()), m_tpIndex(that.m_tpIndex) {}
		Any(Any && that) : m_ptr(std::move(that.m_ptr)), m_tpIndex(that.m_tpIndex) {}

		bool IsNull() const { return !bool(m_ptr); }

		const char *Name() const
		{
			return m_tpIndex.name();
		}

		template<class U> bool Is() const
		{
			return m_tpIndex == type_index(typeid(U));
		}

		template<class U>
		typename decay<U>::type& AnyCast() const
		{
			if (!Is<U>())
			{
				//std::cout << "can not cast " << typeid(U).name() << " to " << m_tpIndex.name() << endl;
				throw bad_cast();
			}

			typedef typename decay<U>::type T;
			auto derived = static_cast<Derived<T>*> (m_ptr.get());

			return derived->m_value;
		}

		template<class U>
		operator U() /*const*/
		{
			return AnyCast<typename decay<U>::type>();
		}

		Any& operator=(const Any& a)
		{
			if (m_ptr == a.m_ptr)
				return *this;

			m_ptr = a.Clone();
			m_tpIndex = a.m_tpIndex;
			return *this;
		}

	private:
		struct Base;
		typedef std::unique_ptr<Base> BasePtr;

		struct Base
		{
			virtual ~Base() {}
			virtual BasePtr Clone() const = 0;
		};

		template<typename T>
		struct Derived : Base
		{
			template<typename U>
			Derived(U && value) : m_value(forward<U>(value)) { }

			BasePtr Clone() const
			{
				return BasePtr(new Derived<T>(m_value));
			}

			T m_value;
		};

		BasePtr Clone() const
		{
			if (m_ptr != nullptr)
				return m_ptr->Clone();

			return nullptr;
		}

		BasePtr m_ptr;
		std::type_index m_tpIndex;
	};
}

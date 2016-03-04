// ********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: An jianpeng
// Created: 2006/07/06
// Describe:
// ********************************************************************

#ifndef _TQ_SAFE_VECTOR_H_
#define _TQ_SAFE_VECTOR_H_

#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER > 1000

#include <BaseCode.h>

namespace tq {
template <class T>
class CSafeVector : public std::vector<T> {
  //-----------------------------------------------
 public:  // new traversal
  class ConstIterator {
    enum { VALID_MASK = 0x80000000, SIZE_MASK = 0x7FFFFFFF };

   private:  // create by parent class
    ConstIterator(const std::vector<T>* pSet)
        : m_pSet(pSet), m_nValid_Size(pSet->size()), m_idx(0) {}
    friend class CSafeVector<T>;

   public:  // application
    bool Next() {
      if (m_idx >= Size()) return false;
      if (!IsValid())
        m_nValid_Size += VALID_MASK;
      else
        m_idx++;
      return m_idx < Size();
    }
    void Reset() {
      m_idx = 0;
      m_nValid_Size = m_pSet->size();
    }
    operator const T*() {
      IF_OK(IsValid());
      return &m_pSet->at(m_idx);
    }
    const T* operator->() {
      IF_OK(IsValid());
      return &m_pSet->operator[](m_idx);
    }

   protected:
    bool IsValid() { return (m_nValid_Size & VALID_MASK) && m_idx < Size(); }
    int Size() { return m_nValid_Size & SIZE_MASK; }
    void DelObj() {
      IF_OK(Size());
      m_nValid_Size = Size() - 1;
    }  // set invalid

   protected:
    const std::vector<T>* m_pSet;
    unsigned long m_nValid_Size;
    int m_idx;
  };
  class Iterator {
    enum { VALID_MASK = 0x80000000, SIZE_MASK = 0x7FFFFFFF };

   private:  // create by parent class
    Iterator(std::vector<T>* pSet)
        : m_pSet(pSet), m_nValid_Size(pSet->size()), m_idx(0) {}
    friend class CSafeVector<T>;

   public:  // application
    bool Next() {
      if (m_idx >= Size()) return false;
      if (!IsValid())
        m_nValid_Size += VALID_MASK;
      else
        m_idx++;
      return m_idx < Size();
    }
    void Reset() {
      m_idx = 0;
      m_nValid_Size = m_pSet->size();
    }
    operator T*() {
      IF_OK(IsValid());
      return &m_pSet->at(m_idx);
    }
    T* operator->() {
      IF_OK(IsValid());
      return &m_pSet->operator[](m_idx);
    }

   protected:
    bool IsValid() {
      return (m_nValid_Size & 0x80000000) && m_idx < m_pSet->size();
    }
    int Size() { return m_nValid_Size & 0x7FFFFFFF; }
    void DelObj() {
      IF_OK(Size());
      m_nValid_Size = Size() - 1;
    }  // set invalid

   protected:
    std::vector<T>* m_pSet;
    unsigned long m_nValid_Size;
    int m_idx;
  };

 public:  // traverse
  const ConstIterator NewEnum() const { return ConstIterator(this); }
  Iterator NewEnum() { return Iterator(this); }
  int Size() const { return this->size(); }
  //-----------------------------------------------

 public:
  // explicit CSafeVector(int nSize=0)				{ this->resize(nSize);
  // }
  // CSafeVector(const CSafeVector& obj)			{ m_set = obj; }
  // CSafeVector& operator=(const CSafeVector& obj){ if(this==&obj) return
  // *this; m_set = obj.m_set; return *this; }

 public:
#pragma warning(push)
#pragma warning( \
    default : 4715)  // 'function' : not all control paths return a value
  // 重载vector操作符 防止越界访问
  template <class E>
  T& operator[](E position) {
    if (position >= 0 && position < this->size()) {
      return this->at(position);
    }
    DEBUG_TRY
    throw;
    DEBUG_CATCH("★CSafeVector()★ position error");
  }
  template <class E>
  const T& operator[](E position) const {
    if (position >= 0 && position < this->size()) {
      return this->at(position);
    }
    DEBUG_TRY
    throw;
    DEBUG_CATCH("★CSafeVector()★ position error");
    return this->at(position);
  }
#pragma warning(pop)
 public:
  // T&	operator[](int idx)						{ IF_OK(idx<this->size()); return
  // this->at(idx); }
  // T&	At(int idx)								{ IF_OK(idx<this->size()); return
  // this->at(idx); }
  // const T& operator[](int idx) const			{ IF_OK(idx<this->size());
  // return this->at(idx); }
  // const T& At(int idx) const					{ IF_OK(idx<this->size()); return
  // this->at(idx); }
  void Clear() { this->clear(); }
  void Push(const T& obj) { this->push_back(obj); }
  bool DelObj(Iterator& iter) {
    if (!iter.IsValid()) return false;
    this->erase(this->begin() + iter.m_idx);
    iter.DelObj();
    return true;
  }
  bool DelObj(int idx) {
    if (idx < this->size())
      ;
    this->erase(this->begin() + idx);
    return true;
  }

 public:  // dump
  tq::CString Dump() const {
    tq::CString str("{ ");
    for (int i = 0; i < this->size(); i++) {
      if (i) str += ", ";
      str += /*::DumpString*/ (this->at(i));
    }
    return str += " }";
  }
};
}

#endif  // _TQ_SAFE_VECTOR_H_

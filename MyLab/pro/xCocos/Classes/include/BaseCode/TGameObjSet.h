//////////////////////////////////////////////////////////////////////
// XSW, 2009.4.22 统一游戏对象操作和管理
// 说明:
//		1.容器用vector，需GetKey()和Release()函数支持
//		2.GetKey()类型可自定义，值不能重复
//////////////////////////////////////////////////////////////////////

#ifndef _TGAMEOBJSET_H_
#define _TGAMEOBJSET_H_

#include <vector>

NAMESPACE_BEGIN(tq)

//////////////////////////////////////////////////////////////////////////
// interface IGameObjSet
template <class T, class KEY>
class IGameObjSet {
 public:
  typedef std::vector<T*> OBJSET;
  typedef typename OBJSET::iterator Iter;  // std容器迭代器
  typedef typename OBJSET::const_iterator ConstIter;  // std容器迭代器
 public:
  virtual USHORT Release() = 0;
  virtual Iter Begin() = 0;
  virtual Iter End() = 0;

  virtual bool AddObj(T* pObj) = 0;
  virtual bool DelObj(const KEY& key) = 0;
  virtual T* GetObj(const KEY& key) = 0;
  virtual T* PopObj(const KEY& key) = 0;  // 从OWNER_SET中取出对象，不删除。

  virtual int GetAmount() const = 0;
  virtual bool IsExist(const KEY& key) const = 0;
};

//////////////////////////////////////////////////////////////////////////
// template TGameObjSet
template <class T, class KEY = int64_t>
class TGameObjSet : public IGameObjSet<T, KEY> {
    typedef typename IGameObjSet<T, KEY>::OBJSET OBJSET;
    typedef typename IGameObjSet<T, KEY>::Iter Iter;
    typedef typename IGameObjSet<T, KEY>::ConstIter ConstIter;
 public:
  typedef KEY (T::*GETKEY)() const;
  static TGameObjSet<T, KEY>* CreateNew(bool bOwner = true,
                                        GETKEY fnGetKey = &T::GetKey) {
    return new TGameObjSet<T, KEY>(bOwner, fnGetKey);
  }

  //////////////////////////////////////////////////////
 public:
  //////////////////////////////////////////////////////
  //迭代器封装
  class Iterator {
   private:  // create by parent class
    Iterator(OBJSET* pSet) : m_pSet(pSet), m_idx(pSet->size() - 1), m_pObj(0) {}
    friend class TGameObjSet<T, KEY>;

   public:  // application
    bool Next() {
      if (m_idx < 0) return m_pObj = NULL, false;
      m_pObj = m_pSet->at(m_idx);
      ASSERT(m_pObj);
      m_idx--;
      return true;
    }
    void Reset() {
      m_idx = m_pSet->size() - 1;
      m_pObj = NULL;
    }
    operator T*() { return m_pObj; }
    T* operator->() {
      ASSERT(m_pObj);
      return m_pObj;
    }

   protected:
    const OBJSET* m_pSet;
    int m_idx;
    T* m_pObj;
  };

  //////////////////////////////////////////////////////
  //迭代器相关接口
 public:  // traverse
  Iterator NewEnum() { return Iterator(&m_setObj); }

  //////////////////////////////////////////////////////////////////////////
 protected:
  TGameObjSet(bool bOwner, GETKEY fnGetkey)
      : m_bOwner(bOwner), m_fnGetkey(fnGetkey) {
    ASSERT(m_fnGetkey);
  }
  virtual ~TGameObjSet();

  //////////////////////////////////////////////////////////////////////////
  // interface of IGameObjSet
 public:
  USHORT Release() {
    delete this;
    return 0;
  }
  Iter Begin() { return m_setObj.begin(); }
  Iter End() { return m_setObj.end(); }

  bool AddObj(T* pObj);
  bool DelObj(const KEY& key);
  T* GetObj(const KEY& key);
  T* GetObj(const KEY& key) const;
  T* PopObj(const KEY& key);
  T* GetObjByIndex(int idx) {
    IF_NOT(idx >= 0 && idx < m_setObj.size()) return 0;
    return m_setObj[idx];
  }

  int GetAmount() const { return m_setObj.size(); }
  bool IsExist(const KEY& key) const { return GetObj(key) != NULL; }

  //////////////////////////////////////////////////////////////////////////
 public:
  void Clear();
  bool DelObj(Iterator& iter);

 protected:
  T* PopObj(Iterator& iter);

 protected:
  OBJSET m_setObj;
  bool m_bOwner;
  GETKEY m_fnGetkey;
};

//////////////////////////////////////////////////////////////////////////
//接口实现 TGameObjSet

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
TGameObjSet<T, KEY>::~TGameObjSet() {
  Clear();
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
void TGameObjSet<T, KEY>::Clear() {
  if (m_bOwner) {
    for (int i = 0; i < m_setObj.size(); i++) {
      T* pObj = m_setObj[i];
      if (pObj) {
        pObj->Release();
        m_setObj[i] = NULL;  // 加强安全性
      }
    }
  }
  m_setObj.clear();
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
bool TGameObjSet<T, KEY>::AddObj(T* pObj) {
  CHECKF_T(pObj);
  ASSERT_T(!DelObj((pObj->*m_fnGetkey)()));

  m_setObj.push_back(pObj);
  return true;
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
bool TGameObjSet<T, KEY>::DelObj(Iterator& iter) {
  if (iter.m_pObj) {
    T* pObj = PopObj(iter);
    IF_OK(pObj) {
      if (m_bOwner) SAFE_RELEASE(pObj);
      return true;
    }
  }
  return false;
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
T* TGameObjSet<T, KEY>::PopObj(Iterator& iter) {
  if (iter.m_pObj) {
    T* pObj = iter.m_pObj;
    iter.m_pObj = NULL;

    int idx = iter.m_idx + 1;
    IF_OK_T(idx < m_setObj.size()) {
      m_setObj.erase(m_setObj.begin() + idx);
      return pObj;
    }
  }
  return NULL;
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
bool TGameObjSet<T, KEY>::DelObj(const KEY& key) {
  for (int i = 0; i < m_setObj.size(); i++) {
    T* pObj = m_setObj[i];
    if (pObj && (pObj->*m_fnGetkey)() == key) {
      IF_OK(pObj) {
        if (m_bOwner) SAFE_RELEASE(pObj);
      }
      m_setObj.erase(m_setObj.begin() + i);
      return true;
    }
  }
  return false;
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
T* TGameObjSet<T, KEY>::GetObj(const KEY& key) {
  for (int i = 0; i < m_setObj.size(); i++) {
    T* pObj = m_setObj[i];
    if (pObj && (pObj->*m_fnGetkey)() == key) {
      return pObj;
    }
  }
  return NULL;
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
T* TGameObjSet<T, KEY>::GetObj(const KEY& key) const {
  for (int i = 0; i < m_setObj.size(); i++) {
    T* pObj = m_setObj[i];
    if (pObj && (pObj->*m_fnGetkey)() == key) {
      return pObj;
    }
  }
  return NULL;
}

//////////////////////////////////////////////////////////////////////
template <class T, class KEY>
T* TGameObjSet<T, KEY>::PopObj(const KEY& key) {
  ASSERT_T(m_bOwner);

  for (int i = 0; i < m_setObj.size(); i++) {
    T* pObj = m_setObj[i];
    if (pObj && (pObj->*m_fnGetkey)() == key) {
      m_setObj.erase(m_setObj.begin() + i);
      return pObj;
    }
  }
  return NULL;
}

NAMESPACE_END(tq)

#endif  // !defined(_TGAMEOBJSET_H_)

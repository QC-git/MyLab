//////////////////////////////////////////////////////////////////////
// �����࣬���ڽ������ݱ�֮��Ŀ��ٲ�ѯ�������KEY�����ظ�
// XSW, 2009.4.22 ͳһ��Ϸ��������͹���
//////////////////////////////////////////////////////////////////////
// ˵��:

#ifndef _TQ_TMAP_H_
#define _TQ_TMAP_H_

#pragma warning(disable : 4284)

NAMESPACE_BEGIN(tq)

template <class T, class KEY>
class TMap {
 public:
  typedef typename std::map<KEY, T> OBJMAP;
  typedef typename OBJMAP::iterator Iter;  // std����������
  typedef typename OBJMAP::const_iterator ConstIter;  // std����������
 public:
  //////////////////////////////////////////////////////
  //��������װ
  class Iterator {
   private:  // create by parent class
    Iterator(OBJMAP* pSet) : m_pSet(pSet), m_iter(pSet->begin()), m_pObj(0) {}
    friend class TMap<T, KEY>;

   public:  // application
    bool Next() {
      if (m_iter == m_pSet->end()) return m_pObj = NULL, false;
      m_key = m_iter->first;
      m_pObj = &m_iter->second;
      ASSERT(m_pObj);
      m_iter++;
      return true;
    }

    void Reset() {
      m_iter = m_pSet->begin();
      m_pObj = NULL;
//      m_pKey = NULL;
    }
    operator T*() { return m_pObj; }
    T* operator->() {
      ASSERT(m_pObj);
      return m_pObj;
    }
    KEY GetKey() const {
      IF_OK(m_pObj) return m_key;
      return (int)0;
    }  // std::string(NULL)�����

   protected:
    OBJMAP* m_pSet;
    Iter m_iter;
    T* m_pObj;
    KEY m_key;
  };
  //////////////////////////////////////////////////////
  //��������ؽӿ�
 public:  // traverse
  Iterator NewEnum() { return Iterator(&m_map); }

  //////////////////////////////////////////////////////
 protected:
  TMap() {}
  virtual ~TMap();

 public:
  static TMap<T, KEY>* CreateNew() { return new TMap<T, KEY>(); }

  //////////////////////////////////////////////////////////////////////////
  // interface of IGameMap
 public:
  USHORT Release() {
    delete this;
    return 0;
  }
  Iter Begin() { return m_map.begin(); }
  Iter End() { return m_map.end(); }

  bool AddObj(const KEY& key, const T& obj);
  bool DelObj(const KEY& key);
  bool DelObj(Iterator& iter);
  T* GetObjByIter(Iter i) const { return &i->second; }
  T* GetObj(const KEY& key);
  T* GetObj(const KEY& key) const;

  int GetAmount() const { return m_map.size(); }
  bool IsExist(const KEY& key) { return GetObj(key) != NULL; }

  //////////////////////////////////////////////////////////////////////////
 protected:
  void Clear();

 protected:
  OBJMAP m_map;
};

template <class T, class KEY>
TMap<T, KEY>::~TMap() {
  Clear();
}

template <class T, class KEY>
void TMap<T, KEY>::Clear() {
  m_map.clear();
}

template <class T, class KEY>
bool TMap<T, KEY>::AddObj(const KEY& key, const T& obj) {
  ASSERT_T(!DelObj(key));
  m_map[key] = obj;
  return true;
}

template <class T, class KEY>
bool TMap<T, KEY>::DelObj(Iterator& iter) {
  return m_map.erase(iter) != 0;
}

template <class T, class KEY>
bool TMap<T, KEY>::DelObj(const KEY& key) {
  return m_map.erase(key) != 0;
}

template <class T, class KEY>
T* TMap<T, KEY>::GetObj(const KEY& key) {
  typename OBJMAP::iterator i = m_map.find(key);
  if (i != m_map.end()) return &i->second;

  return NULL;
}

template <class T, class KEY>
T* TMap<T, KEY>::GetObj(const KEY& key) const {
  ConstIter i;
  if ((i = m_map.find(key)) != m_map.end()) return &i->second;

  return NULL;
}

NAMESPACE_END(tq)

#endif  // _TQ_TMAP_H_

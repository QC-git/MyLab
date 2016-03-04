#pragma once

#include <map>
#include <tuple>
#include <functional>
#include <vector>

template <class _BASE, typename... Args>
class Factory {
  std::map<std::tuple<Args...>, _BASE*> m_collection;
  std::vector<std::pair<std::function<bool(const Args&...)>,
                        std::function<_BASE*(const Args&...)> > > m_creator;

 public:
  _BASE* Create(const Args&... args) {
    for (auto mit : m_creator) {
      if ((mit.first)(args...)) {
        _BASE* t = mit.second(args...);
        return t;
      }
    }
    return nullptr;
  }

  _BASE* CreateOnce(const Args&... args) {
    auto it = m_collection.find(std::make_tuple(args...));
    if (it != m_collection.end()) {
      return it->second;
    } else {
      for (auto mit : m_creator) {
        if ((mit.first)(args...)) {
          _BASE* t = mit.second(args...);
          m_collection.insert(std::make_pair(std::make_tuple(args...), t));
          return t;
        }
      }
    }
    return nullptr;
  }

  template <class _IMPL>
  void Register(std::function<bool(const Args&...)> checker) {
    m_creator.push_back(std::make_pair(
        checker, [this](const Args&... args) { return new _IMPL(args...); }));
  }

  void Register(std::function<_BASE*(const Args&...)> creator) {
    m_creator.push_back(
        std::make_pair([](const Args&...) { return true; }, creator));
  }

  void Register(std::function<bool(const Args&...)> checker,
                std::function<_BASE*(const Args&...)> creator) {
    m_creator.push_back(std::make_pair(checker, creator));
  }

  ~Factory() {
    for (auto it : m_collection) {
      delete it.second;
    }
  }
};

template <class Init, class Uninit>
class Initializer {
 private:
  Uninit m_uninit;

 public:
  Initializer(Init init = nullptr, Uninit uninit = nullptr) : m_uninit(uninit) {
    if (init != nullptr) {
      init();
    }
  }
  ~Initializer() {
    if (m_uninit != nullptr) {
      m_uninit();
    }
  }
};
//////////////////////////////////////////////////////////////////////
// 为游戏对象实现一些统一接口，以规范对象容器管理、减少代码量
// XSW, 2009.4.22
//////////////////////////////////////////////////////////////////////

#ifndef _TGAMEOBJ_H_
#define _TGAMEOBJ_H_


NAMESPACE_BEGIN(tq)

///////////////////////////////////////////////////////////////
//为游戏对象实现一些统一接口，以规范对象容器管理、减少代码量

//////////////////////////////////////////////////////////////////////////
//delete by duqisong 不用boost
//template <class T>
//class TSHARED_PTR : public boost::shared_ptr<T>
//{
//	public:
//		//TSHARED_PTR(){};
//		explicit TSHARED_PTR( T * p=NULL ):boost::shared_ptr<T>(p, T::policy_release())
//		{
//		}
//};

//////////////////////////////////////////////////////////////////////////
#ifndef NO_COPY
#define	NO_COPY(T)	\
	protected:	\
	T(const T&){};	\
	T& operator=(const T&){};
#endif

//////////////////////////////////////////////////////////////////////////
//默认删除器
#define	SHAREPTR_POLICY_RELEASE(T)	\
	public:	\
	class policy_release{ public: void operator()(T* p)	{ SAFE_RELEASE(p);};};\

//////////////////////////////////////////////////////////////////////////
//生成CreateNew()、Release()、构造（带实现）、析构（带实现）
#define GAMEOBJ_TEMPLATE(T)	\
	public:	\
	static T* CreateNew() 		{ T* p = new T; ASSERT(p); return p; }	\
	USHORT	Release() 			{ delete this; return 0; }	\
	SHAREPTR_POLICY_RELEASE(T)\
	protected:	\
	T(){};\
	virtual ~T(){};\

//////////////////////////////////////////////////////////////////////////
//生成CreateNew()、Release()、构造（未带实现）、析构（未带实现）
#define GAMEOBJ_NO_CONSTRUCT_IMPLEMENT(T)	\
	public:	\
	static T* CreateNew() 		{ T* p = new T; ASSERT(p); return p; }	\
	USHORT	Release() 			{ delete this; return 0; }	\
	SHAREPTR_POLICY_RELEASE(T)\
	protected:	\
	T();\
	virtual ~T();\


NAMESPACE_END(tq)

#endif	//_TGAMEOBJ_H_
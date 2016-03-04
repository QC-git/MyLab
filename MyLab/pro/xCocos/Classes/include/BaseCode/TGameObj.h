//////////////////////////////////////////////////////////////////////
// Ϊ��Ϸ����ʵ��һЩͳһ�ӿڣ��Թ淶���������������ٴ�����
// XSW, 2009.4.22
//////////////////////////////////////////////////////////////////////

#ifndef _TGAMEOBJ_H_
#define _TGAMEOBJ_H_


NAMESPACE_BEGIN(tq)

///////////////////////////////////////////////////////////////
//Ϊ��Ϸ����ʵ��һЩͳһ�ӿڣ��Թ淶���������������ٴ�����

//////////////////////////////////////////////////////////////////////////
//delete by duqisong ����boost
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
//Ĭ��ɾ����
#define	SHAREPTR_POLICY_RELEASE(T)	\
	public:	\
	class policy_release{ public: void operator()(T* p)	{ SAFE_RELEASE(p);};};\

//////////////////////////////////////////////////////////////////////////
//����CreateNew()��Release()�����죨��ʵ�֣�����������ʵ�֣�
#define GAMEOBJ_TEMPLATE(T)	\
	public:	\
	static T* CreateNew() 		{ T* p = new T; ASSERT(p); return p; }	\
	USHORT	Release() 			{ delete this; return 0; }	\
	SHAREPTR_POLICY_RELEASE(T)\
	protected:	\
	T(){};\
	virtual ~T(){};\

//////////////////////////////////////////////////////////////////////////
//����CreateNew()��Release()�����죨δ��ʵ�֣���������δ��ʵ�֣�
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
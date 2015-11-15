#pragma once

namespace space_test_battle 
{
	enum EUnitRole
	{
		EUnitRole_NONE,
		EUnitRole_CREATURE,
		EUnitRole_OTHER
	};

#define MARK_UNIT_ROLE(_role)        \
	static EUnitRole GetRoleEnum()   \
	{                                \
		return EUnitRole_CREATURE;   \
	}

	struct Status
	{
		U32_T uId;
		U32_T uLevel;
		U32_T uTickCnt;
	};
	typedef std::shared_ptr<Status> Status_T;
	class CUint
	{
	public:
		CUint();
		~CUint();

	public:
		VOID_T OnTick();

	public:
		BOOL_T AddRole(EUnitRole e, VOID_T* pData);

		VOID_T* GetRoleData(EUnitRole e);

		BOOL_T HasRole(EUnitRole e);

		BOOL_T AddStatus(U32_T u);

		BOOL_T RemoveStatus(U32_T u);

	private:
		VOID_T ReleaseData();

	public:
		typedef std::map<U32_T, VOID_T*> RoleMap_T;
		typedef std::map<U32_T, Status_T> StatusList_T;

		RoleMap_T m_cRolesMap;
		StatusList_T m_cStatusList;
		SET_D(U32_T) m_cEventList;
	};
}
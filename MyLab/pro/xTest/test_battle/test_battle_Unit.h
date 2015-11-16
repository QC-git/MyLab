#pragma once

namespace space_test_battle 
{
	enum EUnitRole
	{
		EUnitRole_NONE,
		EUnitRole_COMMON,
		EUnitRole_STATUS,
		EUnitRole_AI,
		EUnitRole_SKILL,
		EUnitRole_OTHER
	};

#define MARK_UNIT_ROLE(_role)        \
	static EUnitRole GetRoleType()   \
	{                                \
		return _role;				 \
	}
	
	class CUint
	{
	public:
		CUint();
		~CUint();

	public:
		VOID_T OnTick();

	public:
		BOOL_T  AddRole(EUnitRole e, VOID_T* pData);

		BOOL_T  HasRole(EUnitRole e);

		VOID_T* GetRoleData(EUnitRole e);

		BOOL_T  AddTask(U32_T u);

		BOOL_T  RemoveTask(U32_T u);

		BOOL_T HasTask(U32_T u);

	private:
		VOID_T ReleaseData();

	public:
		typedef MAP_D(EUnitRole, VOID_T*)	DataMap_T;

		typedef SET_D(U32_T)				TaskList_T;

		typedef SET_D(U32_T)				EventList_T;

		DataMap_T   m_cDataMap;

		TaskList_T  m_cTaskList;
		TaskList_T  m_cAddTaskList;
		TaskList_T  m_cDelTaskList;

		EventList_T m_cEventList;
	};

}
#pragma once

namespace space_test_battle 
{
	enum EUnitRole
	{
		EUnitRole_NONE,
		EUnitRole_COMMON,
		EUnitRole_STATUS,
		EUnitRole_AI,
		EUnitRole_ADVANCE,
		EUnitRole_OTHER
	};

	enum ETaskFlag
	{
		ETaskFlag_Normal    = 0,
		ETaskFlag_ADD       = 11,
		ETaskFlag_DEC       = 12,
		ETaskFlag_SYN_EVENT = 100
	};

#define MARK_UNIT_ROLE(_role)        \
	static EUnitRole GetRoleType()   \
	{                                \
		return _role;				 \
	}

	struct STaskInfo
	{
		U32_T uId;
		U32_T uCount;
		VOID_T* uData;
		STaskInfo()
		{
			uId = 0;
			uCount = 0;
			uData = NULL;
		}
	};

	class CUint
	{
	public:
		CUint(U32_T uId);
		~CUint();

	public:
		U32_T GetId();

	public:
		VOID_T OnTick();

		VOID_T Syn(U32_T uFlag);

	public:
		BOOL_T  AddRole(EUnitRole e, VOID_T* pData);

		BOOL_T  HasRole(EUnitRole e);

		VOID_T* GetRoleData(EUnitRole e);

		BOOL_T  AddTask(U32_T u);

		BOOL_T  RemoveTask(U32_T u);

		BOOL_T HasTask(U32_T u);

		VOID_T* GetTaskInfo(U32_T u);

	private:
		VOID_T ReleaseData();

	public:
		typedef MAP_D(EUnitRole, VOID_T*)	DataMap_T;

		typedef MAP_D(U32_T, STaskInfo*)	TaskList_T;
		typedef SET_D(U32_T)				PreTaskList_T;

		typedef SET_D(U32_T)				EventList_T;

		DataMap_T   m_cDataMap;

		TaskList_T		m_cTaskList;
		PreTaskList_T  m_cPreAddTasks;
		PreTaskList_T  m_cPreDelTasks;

		EventList_T m_cEventList;

	private:
		U32_T m_uId;

	};

}
#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{
	struct Status
	{
		U32_T uId;
		U32_T uLayer;
		U32_T uTickCnt;

		Status()
		{
			uId = 0;
			uLayer = 0;
			uTickCnt = 0;
		}

	};
	typedef PTR_D(Status)           PStatus_T;
	typedef MAP_D(U32_T, PStatus_T) StatusMap_T;

	class CRoleStatus
	{
	public:
		CRoleStatus(CUint* p);
		~CRoleStatus();

		MARK_UNIT_ROLE(EUnitRole_STATUS)

		typedef StatusMap_T Data;

	public:
		BOOL_T AddStatus(U32_T uId);

		BOOL_T RemoveStatus(U32_T uId);
		
		BOOL_T HasStatus(U32_T uId);

	private:
		Data* m_pData;
		CUint* m_pUnit;

	};

}
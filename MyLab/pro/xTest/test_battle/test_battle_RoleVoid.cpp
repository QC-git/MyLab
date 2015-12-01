
#include "x_all.h"
#include "test_battle_RoleVoid.h"

namespace space_test_battle
{
	CRoleVoid::CRoleVoid(CUint* p)
	{
		m_pUnit = p;

		EUnitRole e = CRoleVoid::GetRoleType();
		m_pData = (Data*)p->GetRoleData(e);
	}

	CRoleVoid::~CRoleVoid()
	{
		;
	}

	VOID_T AddAny()
	{
		;
	}

	VOID_T RemoveAny()
	{
		;
	}



}
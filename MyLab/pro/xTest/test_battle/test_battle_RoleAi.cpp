
#include "x_all.h"
#include "test_battle_RoleAi.h"

namespace space_test_battle
{
	CRoleAi::CRoleAi(CUint* p)
	{
		m_pUnit = p;

		EUnitRole e = CRoleAi::GetRoleType();
		m_pData = (Data*)p->GetRoleData(e);
	}

	CRoleAi::~CRoleAi()
	{
		;
	}


}

#include "x_all.h"
#include "test_battle_RoleCommon.h"

namespace space_test_battle 
{

	CRoleCommon::CRoleCommon(CUint* p)
	{
		m_pUnit = p;

		EUnitRole e = CRoleCommon::GetRoleType();
		m_pData = (Data*)p->GetRoleData(e);
	}

	CRoleCommon::~CRoleCommon()
	{
		;
	}


}
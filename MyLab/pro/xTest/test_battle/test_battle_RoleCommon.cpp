
#include "x_all.h"
#include "test_battle_RoleCommon.h"

namespace space_test_battle 
{

	CRoleCommon::CRoleCommon(CUint* p)
	{
		m_pUnit = p;
		m_pData = (Data*)p->GetRoleData(EUnitRole_COMMON);
	}

	CRoleCommon::~CRoleCommon()
	{
		;
	}


}
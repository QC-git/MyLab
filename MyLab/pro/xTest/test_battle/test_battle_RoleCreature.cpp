
#include "x_all.h"
#include "test_battle_RoleCreature.h"

namespace space_test_battle 
{

	CRoleCreature::CRoleCreature(CUint* p)
	{
		m_pData = (Data*)p->GetRoleData(EUnitRole_CREATURE);
	}

	CRoleCreature::~CRoleCreature()
	{
		;
	}


}
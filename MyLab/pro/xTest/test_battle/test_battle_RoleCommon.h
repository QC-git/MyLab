#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{
	class CRoleCommon
	{
	public:
		CRoleCommon(CUint* p);
		~CRoleCommon();

		MARK_UNIT_ROLE(EUnitRole_COMMON)

		struct Data
		{
			SEnergy sHealth;
			SEnergy sMagic;
		};

	public:
		VOID_T AddMaxHealth(U32_T& uValue) { m_pData->sHealth.AddMax(uValue);		}
		VOID_T DecMaxHealth(U32_T& uValue) { m_pData->sHealth.DecMax(uValue);		}
		U32_T  GetMaxHealth()              { m_pData->sHealth.uMaxValue;			}
		VOID_T AddHealth(U32_T& uValue)    { LOG_F("增加血量 %d", uValue); m_pData->sHealth.Add(uValue);	LOG_F("剩余血量 %d", uValue);		}
		VOID_T DecHealth(U32_T& uValue)    { LOG_F("受到伤害 %d", uValue); m_pData->sHealth.Dec(uValue);	LOG_F("剩余血量 %d", uValue);		}
		U32_T  GetHealth()                 { m_pData->sHealth.uValue;				} 
		BOOL_T IsAlive()                   { return 0 != m_pData->sHealth.uValue;   }

		VOID_T AddMaxMagic(U32_T& uValue)  { m_pData->sMagic.AddMax(uValue);		}
		VOID_T DecMaxMagic(U32_T& uValue)  { m_pData->sMagic.DecMax(uValue);		}
		U32_T  GetMaxMagic()               { return m_pData->sMagic.uMaxValue;		}
		VOID_T AddMagic(U32_T& uValue)     { m_pData->sMagic.Add(uValue);			}
		VOID_T DecMagic(U32_T& uValue)     { m_pData->sMagic.Dec(uValue);			}
		U32_T  GetMagic()                  { return m_pData->sMagic.uValue;			}
		BOOL_T IsMagicEnough(U32_T uValue) { return uValue <= m_pData->sMagic.uValue; }

	private:
		Data* m_pData;
		CUint* m_pUnit;

	};
}
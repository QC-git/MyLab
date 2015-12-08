
#include "x_all.h"
#include "test_battle_script_task.h"
#include "test_battle_script_tool.h"

namespace space_test_battle
{

#define ON_ADD_D	if ( ETaskFlag_ADD == uFlag )
#define ON_DEL_D	if ( ETaskFlag_DEC == uFlag )
#define EFFECT_D(_start, _end) if ( ETaskFlag_Normal == uFlag && pInfo->uCount >= _start && pInfo->uCount < _end  )
#define EFFECT2_D(_time) if ( ETaskFlag_Normal == uFlag && pInfo->uCount == _time )
#define EVENT_D(_unit, _event) if( _unit && _unit->WaitEvent(_event) )
#define COOLDOWN_D(_cd) if ( ETaskFlag_Normal == uFlag && pInfo->uCount >= _cd ) { SP_D(CRoleAdvance) spRole = CManager::GetRole<CRoleAdvance>(p); spRole->RemoveSkill(pInfo->uId); }


	// 技能
	VOID_T script_101(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		SP_D(CRoleAdvance) spRole = CManager::GetRole<CRoleAdvance>(p);

		U32_T nTick = CManager::GetTickCount();

		if ( 0 == nTick%30 )
		{
			CUint* pTarget = spRole->GetTarget();
			SP_D(CRoleBase) spTagretCommon = CManager::GetRole<CRoleBase>(pTarget);
			U32_T uValue = 100;
			spTagretCommon->DecHealth(uValue);
		}

	}

	VOID_T script_103(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		SP_D(CRoleAdvance) spRole = CManager::GetRole<CRoleAdvance>(p);

		EFFECT_D(1, 2)
		{
			SCRIPT_LOG_F("效果1");
		}

		EFFECT2_D(3)
		{
			p->PushEvent(1);
			SCRIPT_LOG_F("效果2");
		}

		EFFECT_D(2, 5)
		{
			SCRIPT_LOG_F("效果3");
		}

		EFFECT_D(5, 12)
		{
			SCRIPT_LOG_F("效果4");
		}

		EVENT_D(p, 1)
		{
			SCRIPT_LOG_F("效果5");
		}

		COOLDOWN_D(10);
	}

	//////////////////////////////////////////////////////////////////////////

	// 状态
	VOID_T script_1001(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{

		state_param_dot_s params;
		params.uDamage = 500;
		params.uInterval = 30;
		params.uExpireCount = 100;

		state_dot(p, pInfo, uFlag, params);

	}

	VOID_T script_1002(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{
		state_param_area_s param;
		param.uExpireCount = 100;
		param.uMark = 1002;
		param.uMarkEx = 1012;

		state_aura(p, pInfo, uFlag, param);
	}

	//////////////////////////////////////////////////////////////////////////

	//2000+ AI

	//////////////////////////////////////////////////////////////////////////

	//yh技能
	VOID_T script_3331(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{


	}

	//yh状态
	VOID_T script_3332(CUint* p, STaskInfo* pInfo, U32_T uFlag)
	{


	}


	//////////////////////////////////////////////////////////////////////////

	VOID_T LoadAllScript()
	{
		REGISTER_SCRIPT_F(101);
		REGISTER_SCRIPT_F(103);
		REGISTER_SCRIPT_F(1001);
		REGISTER_SCRIPT_F(1002);
	}

}
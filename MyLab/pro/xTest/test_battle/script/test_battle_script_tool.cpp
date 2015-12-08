
#include "x_all.h"
#include "test_battle_script_tool.h"

namespace space_test_battle
{

	VOID_T state_dot(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_dot_s& params)
	{
		SP_D(CRoleBase) spRole = CManager::GetRole<CRoleBase>(p);
		SP_D(CRoleAdvance) spRoleEx = CManager::GetRole<CRoleAdvance>(p);
		
		if ( ETaskFlag_ADD == uFlag ) 
		{
			LOG_F("add dot %d", pInfo->uId);
			//SP_D(CRoleBase) spRole = CManager::GetRole<CRoleBase>(1111);
		}

		if ( ETaskFlag_DEC == uFlag )
		{
			LOG_F("del dot %d", pInfo->uId);
		}

		if ( ETaskFlag_Normal == uFlag )
		{
			U32_T uTickCnt = pInfo->uCount;

			if ( uTickCnt > params.uExpireCount ) 
			{
				spRoleEx->RemoveStatus(pInfo->uId);
				return;
			}

			if ( 0 == uTickCnt%params.uInterval )
			{
				spRole->DecHealth(params.uDamage);
			}

		}

	}

	typedef std::set<U32_T> state_info_area_s;

	VOID_T state_aura(CUint* p, STaskInfo* pInfo, U32_T uFlag, state_param_area_s& params)
	{
		SP_D(CRoleBase) spRole = CManager::GetRole<CRoleBase>(p);
		SP_D(CRoleAdvance) spRoleEx = CManager::GetRole<CRoleAdvance>(p);

		if ( ETaskFlag_ADD == uFlag ) 
		{
			LOG_F("add aura %d", pInfo->uId);

			state_info_area_s* pAreaInfo = new state_info_area_s;
			pInfo->uData = pAreaInfo;

			pAreaInfo->clear();

			UnitSet_T cList = CManager::getAllUnit(p->GetId());
			UnitSet_T::iterator cIter;
			FOR_EACH(cList, cIter)
			{
				CUint* pUnit = *cIter;

				SP_D(CRoleBase) spRoleTmp = CManager::GetRole<CRoleBase>(pUnit);
				spRoleTmp->AddMark(params.uMark);
				spRoleTmp->AddMark(params.uMarkEx);

				pAreaInfo->insert(pUnit->GetId());
			}


		}

		if ( ETaskFlag_DEC == uFlag )
		{
			LOG_F("del aura %d", pInfo->uId);

			state_info_area_s* pAreaInfo = (state_info_area_s*)pInfo->uData;

			state_info_area_s cList = *pAreaInfo;
			state_info_area_s::iterator cIter;
			FOR_EACH(cList, cIter)
			{
				U32_T uGuid = *cIter;
				CUint* pUnit = CManager::GetUnit(uGuid);

				SP_D(CRoleBase) spRoleTmp = CManager::GetRole<CRoleBase>(pUnit);
				spRoleTmp->RemoveMark(params.uMark);
				spRoleTmp->RemoveMark(params.uMarkEx);
				
			}

			delete pAreaInfo;
		}

		if ( ETaskFlag_Normal == uFlag )
		{
			state_info_area_s* pAreaInfo = (state_info_area_s*)pInfo->uData;
			
			U32_T uTickCnt = pInfo->uCount;

			if ( uTickCnt > params.uExpireCount ) 
			{
				spRoleEx->RemoveStatus(pInfo->uId);
				return;
			}

		}
	}

}
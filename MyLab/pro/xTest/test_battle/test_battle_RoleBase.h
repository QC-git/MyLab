#pragma once

#include "test_battle_Unit.h"
#include "test_battle_Tool.h"

namespace space_test_battle 
{
	class CRoleBase
	{
	public:
		CRoleBase(CUint* p);
		~CRoleBase();

		MARK_UNIT_ROLE(EUnitRole_BASE)

			typedef std::set<U32_T> MarkList_T;

		struct Data
		{
			SEnergy sHealth;
			SEnergy sMagic;
			MarkList_T cMarkList;
		};

	public:
		VOID_T AddMaxHealth(U32_T& uValue);
		VOID_T DecMaxHealth(U32_T& uValue);
		U32_T  GetMaxHealth();
		VOID_T AddHealth(U32_T& uValue);
		VOID_T DecHealth(U32_T& uValue);
		U32_T  GetHealth();
		BOOL_T IsAlive();

	public:
		VOID_T AddMaxMagic(U32_T& uValue);
		VOID_T DecMaxMagic(U32_T& uValue);
		U32_T  GetMaxMagic();
		VOID_T AddMagic(U32_T& uValue);
		VOID_T DecMagic(U32_T& uValue);
		U32_T  GetMagic();
		BOOL_T IsMagicEnough(U32_T uValue);

	public:
		BOOL_T AddMark(U32_T uMark);
		BOOL_T RemoveMark(U32_T uMark);
		VOID_T RemoveAllMark();
		BOOL_T HaveMark(U32_T uMark);

	private:
		std::string GetMarkListStr();

	private:
		Data* m_pData;
		CUint* m_pUnit;

	};
}
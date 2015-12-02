
#include "x_all.h"
#include "test_battle_RoleBase.h"

namespace space_test_battle 
{

	CRoleBase::CRoleBase(CUint* p)
	{
		m_pUnit = p;

		EUnitRole e = CRoleBase::GetRoleType();
		m_pData = (Data*)p->GetRoleData(e);
	}

	CRoleBase::~CRoleBase()
	{
		;
	}


	BOOL_T CRoleBase::AddMark(U32_T uMark)
	{
		MarkList_T& cList = m_pData->cMarkList;
		MarkList_T::iterator cIter;

		if ( 0 == uMark ) 
		{
			return FALSE;
		}

		cIter = cList.find(uMark);
		if ( cIter != cList.end() )
		{
			return false;
		}
		cList.insert(uMark);

		return true;
	}

	BOOL_T CRoleBase::RemoveMark(U32_T uMark)
	{
		MarkList_T& cList = m_pData->cMarkList;
		MarkList_T::iterator cIter;

		cIter = cList.find(uMark);
		if ( cIter == cList.end() )
		{
			return false;
		}
		cList.erase(cIter);

		return true;
	}

	VOID_T CRoleBase::RemoveAllMark()
	{
		m_pData->cMarkList.clear();
	}

	BOOL_T CRoleBase::HaveMark(U32_T uMark)
	{
		MarkList_T::iterator cIter = m_pData->cMarkList.find(uMark);
		return cIter != m_pData->cMarkList.end();
	}

}
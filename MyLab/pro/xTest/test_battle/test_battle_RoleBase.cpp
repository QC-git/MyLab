
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

	VOID_T CRoleBase::AddMaxHealth(U32_T& uValue) 
	{ 
		U32_T uResult = m_pData->sHealth.AddMax(uValue);	
		{
			std::ostringstream cLogStream;
			cLogStream << "增加最大血量 " << uValue << ", 当前最大血量" << uResult;
			UNIT_LOG_F(cLogStream.str());	
		}
		uValue = uResult;
	}

	VOID_T CRoleBase::DecMaxHealth(U32_T& uValue) 
	{ 
		U32_T uResult = m_pData->sHealth.DecMax(uValue);	
		{
			std::ostringstream cLogStream;
			cLogStream << "扣除最大血量 " << uValue << ", 当前最大血量" << uResult;
			UNIT_LOG_F(cLogStream.str());	
		}
		uValue = uResult;
	}

	U32_T  CRoleBase::GetMaxHealth()              
	{ 
		return m_pData->sHealth.uMaxValue;			
	}

	VOID_T CRoleBase::AddHealth(U32_T& uValue)    
	{ 
		U32_T uResult = m_pData->sHealth.Add(uValue);	
		{
			std::ostringstream cLogStream;
			cLogStream << "增加血量 " << uValue << ", 剩余血量 " << uResult;
			UNIT_LOG_F(cLogStream.str());	
		}	
		uValue = uResult;
	}

	VOID_T CRoleBase::DecHealth(U32_T& uValue)    
	{ 
		U32_T uResult = m_pData->sHealth.Dec(uValue);
		{
			std::ostringstream cLogStream;
			cLogStream << "扣除血量 " << uValue << ", 剩余血量 " << uResult;
			UNIT_LOG_F(cLogStream.str());	
		}
		uValue = uResult;
	}

	U32_T  CRoleBase::GetHealth()                 
	{ 
		return m_pData->sHealth.uValue;				
	} 

	BOOL_T CRoleBase::IsAlive()                   
	{ 
		return 0 != m_pData->sHealth.uValue;   
	}


	VOID_T CRoleBase::AddMaxMagic(U32_T& uValue)  
	{ 
		U32_T uResult = m_pData->sMagic.AddMax(uValue);	
		uValue = uResult;
	}

	VOID_T CRoleBase::DecMaxMagic(U32_T& uValue)  
	{ 
		U32_T uResult = m_pData->sMagic.DecMax(uValue);		
		uValue = uResult;
	}

	U32_T  CRoleBase::GetMaxMagic()               
	{ 
		return m_pData->sMagic.uMaxValue;		
	}

	VOID_T CRoleBase::AddMagic(U32_T& uValue)     
	{ 
		U32_T uResult = m_pData->sMagic.Add(uValue);	
		uValue = uResult;
	}

	VOID_T CRoleBase::DecMagic(U32_T& uValue)     
	{ 
		U32_T uResult = m_pData->sMagic.Dec(uValue);
		uValue = uResult;
	}

	U32_T  CRoleBase::GetMagic()                  
	{ 
		return m_pData->sMagic.uValue;			
	}

	BOOL_T CRoleBase::IsMagicEnough(U32_T uValue) 
	{ 
		return uValue <= m_pData->sMagic.uValue; 
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

		{
			std::string cListStr = GetMarkListStr();
			std::ostringstream cLogStream;
			cLogStream << "增加标记 " << uMark << ", 当前标记 " << cListStr;
			UNIT_LOG_F(cLogStream.str());	
		}
		

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

		{
			std::string cListStr = GetMarkListStr();
			std::ostringstream cLogStream;
			cLogStream << "移除标记 " << uMark << ", 当前标记 " << cListStr;
			UNIT_LOG_F(cLogStream.str());	
		}

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

	std::string CRoleBase::GetMarkListStr()
	{
		std::stringstream cListStr;
		MarkList_T::iterator cIter;
		FOR_EACH(m_pData->cMarkList, cIter)
		{
			cListStr << *cIter << " ";
		}
		return cListStr.str();
	}

}
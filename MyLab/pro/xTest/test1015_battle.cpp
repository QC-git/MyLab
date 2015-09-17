
#include "x_all.h"
#include<stdio.h>

#include "xTest.h"

namespace space_test_battle {


	//1，行为对象： 战斗交互的介质， 在内部可以嵌套多个属性
	//2, 属性对象： 在一段范围内变化的对象，战斗的过程记录


// 	class CUnit
// 	{
// 	public:
// 		CUnit() {}
// 		
// 	private:
// 		U32_T uAttrMap;  // 单位的基因
// 
// 	};
// 
// 	class CAttr
// 	{
// 	public:
// 		CAttr(U32_T uAttrId, U32_T ulimit) :
// 			m_uAttrId(uAttrId)
// 		{
// 			;
// 		}
// 
// 	public:
// 		virtual void Change(U32_T uValue, U32_T uFlag = 0)
// 		{
// 			
// 		}
// 
// 
// 	protected:
// 		U32_T getAttrId()
// 		{
// 			return m_uAttrId;
// 		}
// 
// 	private:
// 		U32_T m_uAttrId;
// 
// 	};
// 
// 	class CAttribute_Life : public CAttribute
// 	{
// 	public:
// 		CAttribute_Life() 
// 			: CAttribute(1)
// 		{
// 			m_uCurLife = m_uMaxLife = 100;
// 			m_uDeathLife = 1;
// 		}
// 
// 	public:
// 		void Dec(U32_T uValue, U32_T uFlag = 0)
// 		{
// 			if ( IsDeath() )
// 			{
// 				return;
// 			}
// 
// 			if ( uValue > m_uCurLife )
// 			{
// 				m_uCurLife = 0;
// 			}
// 			else
// 			{
// 				m_uCurLife -= uValue;
// 			}
// 
// // 			if()
// // 			{
// // 
// // 			}
// 
// 
// 		}
// 
// 		BOOL_T IsDeath()
// 		{
// 			return m_uCurLife < m_uDeathLife;
// 		}
// 
// 	public:
// 		U32_T m_uMaxLife;
// 		U32_T m_uDeathLife;
// 
// 		U32_T m_uCurLife;
// 		
// 
// 	};
// 
// 	class WorldJudge
// 	{
// 	public:
// 		WorldJudge();
// 
// 		BOOL_T isDeath(CWorldObject* pObj)
// 		{
// 
// 		}
// 
// 	};
// 
// 	void test1()
// 	{
// 
// 	}

}


void test_battle()
{
	getchar();
}
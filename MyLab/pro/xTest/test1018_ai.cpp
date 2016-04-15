
#include "x_all.h"

#include "xTest.h"

#include "test_ai/bt/test_BehaviorTree.hpp"

namespace space_test_behavior
{

	struct CMyBehavior : public bt::Behavior
	{
		int m_iInitializeCalled;
		int m_iTerminateCalled;
		int m_iUpdateCalled;
		bt::Status m_eReturnStatus;
		bt::Status m_eTerminateStatus;

		int m_nTag;
		int m_nMode;

		CMyBehavior(int tag, int mode)
			: m_iInitializeCalled(0)
			, m_iTerminateCalled(0)
			, m_iUpdateCalled(0)
			, m_eTerminateStatus(bt::BH_INVALID)
		{
			m_nTag = tag;
			m_nMode = mode;
		}

		virtual ~CMyBehavior()
		{
		}

		virtual void onInitialize()
		{
			++m_iInitializeCalled;
		}

		virtual void onTerminate(bt::Status s)
		{
			++m_iTerminateCalled;
			m_eTerminateStatus = s;
		}

		virtual bt::Status update()
		{
			++m_iUpdateCalled;

			bt::Status ret;

			if (0 == m_nMode ) 
			{
				ret = bt::BH_RUNNING;
			}

			if (1 == m_nMode)
			{
				ret = bt::BH_SUCCESS;
			}

			if (2 == m_nMode)
			{
				ret = bt::BH_FAILURE;
			}

			if (3 == m_nMode)
			{
				if ( 0 == m_iUpdateCalled%3 )
				{
					m_iUpdateCalled = 0;
					ret = bt::BH_SUCCESS;
				}
				else
				{
					ret = bt::BH_RUNNING;
				}
				
			}

			LOG_F("tag %d tick %d", m_nTag, ret);
			
			return ret;
		}
	};


	void test1()
	{
		auto node1 = new bt::Parallel(bt::Parallel::RequireAll, bt::Parallel::RequireOne);
		auto node11 = new bt::Sequence();
		//auto leaf12 = new CMyBehavior(12, 0);
		auto leaf13 = new CMyBehavior(13, 1);
		//auto leaf14 = new CMyBehavior(14, 2);
		node1->addChild(node11);
		//node1->addChild(leaf12);
		node1->addChild(leaf13);
		//node1->addChild(leaf14);

		auto leaf121 = new CMyBehavior(121, 3);
		auto leaf122 = new CMyBehavior(122, 2);
		node11->addChild(leaf121);
		node11->addChild(leaf122);

	
		auto sta = node1->tick();
		sta = node1->tick();
		sta = node1->tick();
		sta = node1->tick();
		sta = node1->tick();

		printf("");
	}

}


void test_behavior()
{
	space_test_behavior::test1();

	getchar();
}
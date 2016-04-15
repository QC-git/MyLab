
#include "x_all.h"

#include "xTest.h"

#include "test_bt/test_BehaviorTree.hpp"

namespace space_test_behavior
{

	struct CMyBehavior : public bt::Behavior
	{
		int m_iInitializeCalled;
		int m_iTerminateCalled;
		int m_iUpdateCalled;
		bt::Status m_eReturnStatus;
		bt::Status m_eTerminateStatus;

		CMyBehavior()
			: m_iInitializeCalled(0)
			, m_iTerminateCalled(0)
			, m_iUpdateCalled(0)
			, m_eReturnStatus(bt::BH_RUNNING)
			, m_eTerminateStatus(bt::BH_INVALID)
		{
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
			return m_eReturnStatus;
		}
	};


	void test1()
	{

	}

}


void test_behavior()
{
	space_test_behavior::test1();

	getchar();
}
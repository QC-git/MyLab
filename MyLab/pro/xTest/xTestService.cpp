
#include "xTestService.hpp"

void AsyncRun(CFuncList_T& list, CFuncList_T::iterator& iter)
{
	if (iter == list.end())
	{
		return;
	}
	auto f = *iter;
	f([&list, &iter](int err)
	{
		if (err)
		{
			return;
		}
		AsyncRun(list, ++iter);
	});
}

void AsyncRun(CFuncList_T& list)
{
	AsyncRun(list, list.begin());
};
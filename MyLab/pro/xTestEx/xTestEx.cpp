
#include "xPrecompile.h"

#ifndef _MY_LAB

void MainEx(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	MainEx(argc, argv);
	getchar();
	return 0;
}

//////////////////////////////////////////////////////////////////////////

template<typename T, bool C = true>
struct if_ {
	static const int value = 1;
};

template<typename T>
struct if_<T, true> {
	static const int value = 2;
};

void Main11()
{
	printf("\n value: %d\n", if_<int>::value);
	printf("\n value: %d\n", if_<int, false>::value);

	struct MyStruct
	{

	};

	struct MyStruct2 : public MyStruct
	{

	};


	printf("\n __is_base_of %d ", __is_base_of(MyStruct, MyStruct2));

	getchar();
}


#endif

void MainEx(int argc, char* argv[])
{
	printf("\n MainEx(), argc = %d", argc);

	printf("");


#ifndef _MY_LAB
	Main11();
#endif

}





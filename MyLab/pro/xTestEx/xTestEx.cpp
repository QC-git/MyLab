
#include "xPrecompile.h"


void MainEx(int argc, char* argv[])
{
	printf("\n MainEx(), argc = %d", argc);

	struct MyStruct
	{
		int a;
		int b;
		MyStruct()
		{
			a = 0;
			b = 0;
		}
	};

	std::map<int, MyStruct> cMap;

	MyStruct s = cMap[0];
	MyStruct s1 = cMap[1];


	std::map<int, void*> cMap2;

	void* s21 = cMap2[0];
	void* s22 = cMap2[10];

	printf("");
}


#ifndef _MY_LAB
int main(int argc, char* argv[])
{
	MainEx(argc, argv);
	getchar();
	return 0;
}

#endif


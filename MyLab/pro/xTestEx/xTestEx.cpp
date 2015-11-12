
#include "xPrecompile.h"


void MainEx(int argc, char* argv[])
{
	printf("\n MainEx(), argc = %d", argc);


}


#ifndef _MY_LAB
int main(int argc, char* argv[])
{
	MainEx(argc, argv);
	getchar();
	return 0;
}

#endif


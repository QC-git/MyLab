
#include "xTest.h"

#pragma comment(lib, "libuv_d.lib")

#include "uv.h"

void test_async()
{
	uv_loop_t *loop = uv_loop_new();

	//printf("Now quitting.\n");
	uv_run(loop, UV_RUN_DEFAULT);

	do 
	{
		Sleep(1);
	} while (true);

}
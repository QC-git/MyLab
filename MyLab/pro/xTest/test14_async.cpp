
#include "xTest.h"

#pragma comment(lib, "libuv_d.lib")
#pragma comment(lib, "libpomelo2_d.lib")

#include "uv.h"
#include "pomelo_trans.h"

void test_async()
{
	uv_loop_t *loop = uv_loop_new();

	//printf("Now quitting.\n");
	uv_run(loop, UV_RUN_DEFAULT);

	pc_client_size();

	do 
	{
		Sleep(1);
	} while (true);

}
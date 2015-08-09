
#include "xTest.h"

extern "C" 
{ 
#include "src/lua.h" 
#include "src/lualib.h" 
#include "src/lauxlib.h"
}

#pragma comment(lib, "liblua_d.lib")

namespace space_test_lua
{

void test1()
{
	lua_State* L = NULL;

	/* ��ʼ��Lua */ 
	//L = lua_open();

	/* ����Lua������ */ 
	luaL_openlibs(L);

	/* ���нű� */ 
	luaL_dofile(L, "test.lua");

	/* ���Lua */ 
	lua_close(L);

	/* ��ͣ */ 
	printf( "Press enter to exit��" );
}

void test2()
{
	;
}

}


void test_lua()
{
	space_test_lua::test1();

	getchar(); 
		
}
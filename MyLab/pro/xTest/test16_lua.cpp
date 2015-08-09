
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

	/* 初始化Lua */ 
	//L = lua_open();

	/* 载入Lua基本库 */ 
	luaL_openlibs(L);

	/* 运行脚本 */ 
	luaL_dofile(L, "test.lua");

	/* 清除Lua */ 
	lua_close(L);

	/* 暂停 */ 
	printf( "Press enter to exit…" );
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
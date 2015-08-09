
#include "xTest.h"

extern "C" 
{ 
#include "lua/src/lua.h" 
#include "lua/src/lualib.h" 
#include "lua/src/lauxlib.h"
}

#pragma comment(lib, "liblua_d.lib")

namespace space_test_lua
{

void ReadVariable (lua_State *L,int *width,int *height){    
	lua_getglobal(L,"width");   //���Lua�б�����ֵ���������ջ��    
	lua_getglobal(L,"height");    

	if(!lua_isnumber(L,-2))     //ջ��Ϊ-1��Ȼ�����μ���    
		luaL_error(L,"`width' should be a number\n");    

	if(!lua_isnumber(L,-1))    
		luaL_error(L,"`height' should be a number\n");    
	*width = (int)lua_tonumber(L,-2);    //��ջ��Ԫ��ת��Ϊ����    
	*height = (int)lua_tonumber(L,-1);    
	printf("width is %d ,height is %d\n\n",*width,*height);    
}    

static void ReadTableFromItem(lua_State *L, const char* lpszTableName, const char* lpszTableItem)    
{    
	lua_getglobal(L, lpszTableName);    

	lua_pushstring(L, lpszTableItem);//���Ȱ�Ԫ�ص�����ѹ��ջ��    
	lua_gettable(L, -2);//ֵ�����ջ����ͬʱ�ղ�ѹ���Ԫ�����ֱ�����    
	printf("%s.%s=%d\n", lpszTableName, lpszTableItem, (int)lua_tonumber(L, -1));    
	lua_pop(L, 2);    
}    

static void ReadTableFromIndex(lua_State *L, const char* lpszTableName, int index)    
{    
	lua_getglobal(L, lpszTableName);    
	lua_rawgeti(L, -1, index);//��õ�һ��Ԫ��    
	printf("%s[%d]=%d\n", lpszTableName, index, (int)lua_tonumber(L, -1));    
	lua_pop(L, 2);    
}    

static void EnumTableItem(lua_State *L, const char* lpszTableName)    
{    
	lua_getglobal(L, lpszTableName);    
	int it = lua_gettop(L);    
	lua_pushnil(L);    
	printf("Enum %s:", lpszTableName);    
	while(lua_next(L, it))//��lua_next���Ա����������    
	{    
		printf("  %d", (int)lua_tonumber(L, -1));    
		lua_pop(L, 1);    
	}    
	printf("\n\n");    
	lua_pop(L, 1);    
}   


void test1()
{
	lua_State* L = NULL;

	/* ��ʼ��Lua */ 
	L = luaL_newstate();

	char *filename = "E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_lua\\test_config.lua";    
   
    luaL_openlibs(L);

    if(luaL_loadfile(L,filename) || lua_pcall(L,0,0,0)){    
        luaL_error(L,"loadfile error! %s \n",lua_tostring(L,-1));    
    }    
    
    int w=1,h=2;    
    ReadVariable(L,&w,&h);

	ReadTableFromItem(L, "luat_Test1", "a");  // �ȼ���lua���룺print(luat_Test1.a)    
	ReadTableFromItem(L, "luat_Test1", "b");    
	ReadTableFromItem(L, "luat_Test1", "c");    
	EnumTableItem(L, "luat_Test1");    // ö��Table    

	ReadTableFromIndex(L, "luat_Test2", 1);  // �ȼ���lua���룺print(luat_Test1[1])    
	ReadTableFromIndex(L, "luat_Test2", 2);    
	ReadTableFromIndex(L, "luat_Test2", 3);    
	EnumTableItem(L, "luat_Test2");    

}

void test2()
{
	;
}

}


void test_lua()
{
	space_test_lua::test1();
	space_test_lua::test2();

	getchar(); 
		
}
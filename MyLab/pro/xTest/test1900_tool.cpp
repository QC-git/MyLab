
#include "x_all.h"

#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#include "xTest.h"

namespace space_test_tool
{
#define RES_PATH "..//..//res//"

	TCHAR s_pBuff[MAX_PATH];

	void test1()
	{
		char* sFile = RES_PATH"a.img";
		//char* sFile = "a.img";
		int nFd = open(sFile, O_CREAT | O_RDWR | O_BINARY);
		long lLen = 1474560; //filelength(nFd);
		char* pBuff = (char*)malloc(lLen);
		TEST_ASSERT( nFd > 0 && pBuff );

		memset(pBuff, 0, lLen);

		char* sFile2 = RES_PATH"boot.bin";
		int nFd2 = open(sFile2, O_RDONLY | O_BINARY);
		TEST_ASSERT(nFd2 > 0);

		long lLen2 = filelength(nFd2);
		TEST_ASSERT( 512 == lLen2 );

		char* pBuff2 = (char*)malloc(lLen2);
		TEST_ASSERT ( read(nFd2, pBuff2, lLen2) == lLen2);

		memcpy(pBuff, pBuff2, lLen2);

		TEST_ASSERT ( write(nFd, pBuff, lLen) == lLen);

		printf("");
	}
}

void test_tool()
{	
	space_test_tool::test1();

	getchar();
}
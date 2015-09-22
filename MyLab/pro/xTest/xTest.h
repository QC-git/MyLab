#pragma once

#define TEST_ASSERT(expr)                        \
	do {                                         \
	if (!(expr)) {                               \
	fprintf(stderr,                              \
	"Assertion failed in %s on line %d: %s\n",   \
	__FILE__,                                    \
	__LINE__,                                    \
#expr);											 \
	abort();									 \
	}                                            \
	} while (0)

void test_util();

void test_container();

void test_thread();

void test_net(int nFlag);

void test_boost();

void test_kbe();

void test_db();

void test_tool();

void test_math();

void test_design();

void test_async(int nFlag);

void test_lua();

void test_js();

void test_proto();

void test_graph();

void test_graph_d3d();

void test_cv();

void test_battle();

void test_hacker();


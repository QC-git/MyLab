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




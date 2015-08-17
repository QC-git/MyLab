

#include "xTest.h"

#include "test_proto/test_person.pb.h"

#pragma comment(lib, "libprotobuf_d.lib")

void test_proto()
{	
	test_proto_msg::Person cMsg;
	cMsg.set_id(123);
	cMsg.set_name("123456789", strlen("123456789"));
	std::string& str = cMsg.SerializeAsString();
	
	printf("\n %s", str.c_str());
}
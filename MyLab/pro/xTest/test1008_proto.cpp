

#include "xTest.h"

#include "test_proto/test_person.pb.h"

#pragma comment(lib, "libprotobuf_d.lib")   // 编译成动态库出现无法链接问题

namespace space_test_proto {

void test1()
{
	printf("\n\n test1 \n");

	test_proto_msg::Person cMsg;
	cMsg.set_id(123);
	cMsg.set_name("123456789", strlen("123456789"));
	cMsg.set_data1(1);
	cMsg.set_data2(9);
	std::string& str = cMsg.SerializeAsString();

	printf("\n %s", str.c_str());
	//{      123456789 (

	test_proto_msg::Person cMsg2;
	bool bSuc = cMsg2.ParseFromString(str);

	printf("\n %d", bSuc);
	printf("\n %d", cMsg2.id());
	printf("\n %s", cMsg2.name().c_str());
	printf("\n %d", cMsg2.data1());
	printf("\n %d", cMsg2.data2());
	// 	1
	// 	123
	// 	123456789
	// 	1
	// 	9

	printf("");
}

void test2()
{
	printf("\n\n test2 \n");

	test_proto_msg::Person cMsg;
	cMsg.set_id(123);
	cMsg.set_name("123456789", strlen("123456789"));
	cMsg.set_data1(1);
	cMsg.set_data2(9);

	char buff[1024];
	bool bSuc1 = cMsg.SerializeToArray(buff, 1024);
	int  nLen1  = cMsg.ByteSize();
	printf("\n %d", bSuc1);
	printf("\n %d", nLen1);
	//	1
	//	17

	test_proto_msg::Person cMsg2;
	bool bSuc2 = cMsg2.ParseFromArray(buff, 1024);
	int  nLen2 = cMsg.ByteSize();
	bool bSuc2_1 = cMsg2.ParseFromArray(buff, nLen1);
	int  nLen2_1 = cMsg.ByteSize();

	printf("\n %d", bSuc2);
	printf("\n %d", bSuc2_1);
	printf("\n %d", cMsg2.id());
	printf("\n %s", cMsg2.name().c_str());
	printf("\n %d", cMsg2.data1());
	printf("\n %d", cMsg2.data2());
	// 	0
	// 	1
	// 	123
	// 	123456789
	// 	1
	// 	9


	test_proto_msg::Person cMsg3;
	char buff3[1024];
	memcpy(buff3+128, buff, 128);

	int nLen3 = cMsg3.ByteSize();
	bool bSuc3_1 = cMsg3.ParseFromArray(buff3+128, 1);		int  nLen3_1 = cMsg3.ByteSize();	bool bInit3_1 = cMsg3.IsInitialized();
	bool bSuc3_2 = cMsg3.ParseFromArray(buff3+128, 5);		int  nLen3_2 = cMsg3.ByteSize();	bool bInit3_2 = cMsg3.IsInitialized();
	bool bSuc3_3 = cMsg3.ParseFromArray(buff3+128, 16);		int  nLen3_3 = cMsg3.ByteSize();	bool bInit3_3 = cMsg3.IsInitialized();
	bool bSuc3_4 = cMsg3.ParseFromArray(buff3+128, 17);		int  nLen3_4 = cMsg3.ByteSize();	bool bInit3_4 = cMsg3.IsInitialized();
	bool bSuc3_5 = cMsg3.ParseFromArray(buff3+128, 18);		int  nLen3_5 = cMsg3.ByteSize();	bool bInit3_5 = cMsg3.IsInitialized();

	printf("\n %d: %d: %d", bSuc3_1, nLen3_1, bInit3_1);
	printf("\n %d: %d: %d", bSuc3_2, nLen3_2, bInit3_2);
	printf("\n %d: %d: %d", bSuc3_3, nLen3_3, bInit3_3);
	printf("\n %d: %d: %d", bSuc3_4, nLen3_4, bInit3_4);
	printf("\n %d: %d: %d", bSuc3_5, nLen3_5, bInit3_5);
	// 	0: 0: 0
	// 	0: 5: 0
	// 	0: 15: 0
	// 	1: 17: 1
	// 	0: 17: 1


	printf("");
}

void test3()
{
	//todo
	//如何判断一个包为完整包 或者 一个消息的长度

	printf("");
}

}

void test_proto()
{	
	space_test_proto::test1();
	space_test_proto::test2();

	getchar(); 
}
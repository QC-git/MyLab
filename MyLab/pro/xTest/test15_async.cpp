
#include "xTest.h"

#include "stdafx.h"

#pragma comment(lib, "libuv_d.lib")
#pragma comment(lib, "libpomelo2_d.lib")
#pragma comment(lib, "libiconv_d.lib")

#include "uv.h"
#include "pomelo_trans.h"
#include "libiconv-1.14\include\iconv.h"

namespace space_test_async
{

//--------------------test1: libuv客户端-------------------//

static int shutdown_cb_called = 0;
static int connect_cb_called = 0;
static int write_cb_called = 0;
static int close_cb_called = 0;

static uv_connect_t connect_req;
static uv_shutdown_t shutdown_req;
static uv_write_t write_req;
static uv_tcp_t tcp_peer; /* client socket as accept()-ed by server */

void startup(void) 
{
#ifdef _WIN32
	struct WSAData wsa_data;
	int r = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	TEST_ASSERT(r == 0);
#endif
}

uv_os_sock_t create_tcp_socket(void) 
{
	uv_os_sock_t sock;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
#ifdef _WIN32
	TEST_ASSERT(sock != INVALID_SOCKET);
#else
	TEST_ASSERT(sock >= 0);
#endif

#ifndef _WIN32
	{
		/* Allow reuse of the port. */
		int yes = 1;
		int r = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes);
		ASSERT(r == 0);
	}
#endif

	return sock;
}

void alloc_cb(uv_handle_t* handle,
	size_t suggested_size,
	uv_buf_t* buf) 
{
		static char slab[65536];
		//ASSERT(suggested_size <= sizeof(slab));
		buf->base = slab;
		buf->len = sizeof(slab);
}


void close_cb(uv_handle_t* handle) {
	TEST_ASSERT(handle != NULL);
	close_cb_called++;
}

void read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) 
{
	TEST_ASSERT(tcp != NULL);
	
	if (nread >= 0) {
		char tmp[1024];
		memcpy(tmp, buf->base, nread);
		tmp[nread] = '\0';
		printf("收到一条新消息： %s", &tmp[2]);	

		TEST_ASSERT( nread > 2);
		//TEST_ASSERT(memcmp("PING", buf->base, nread) == 0);
	}
	else {
		//TEST_ASSERT(nread == UV_EOF);
		printf("GOT EOF\n");
		uv_close((uv_handle_t*)tcp, close_cb);
	}
}

void write_cb(uv_write_t *req, int status) {
	TEST_ASSERT( 0 == status );
	//uv_close((uv_handle_t*) req->handle, NULL);
}

void connect_cb(uv_connect_t* req, int status) 
{
	uv_buf_t buf = uv_buf_init("PING", 4);
	uv_stream_t* stream;
	int r;

	//TEST_ASSERT(req == &connect_req);
	//TEST_ASSERT(status == 0);

	stream = req->handle;
	connect_cb_called++;

	r = uv_write(&write_req, stream, &buf, 1, write_cb);
	TEST_ASSERT(r == 0);

	/* Shutdown on drain. */
	//r = uv_shutdown(&shutdown_req, stream, shutdown_cb);
	//TEST_ASSERT(r == 0);

	/* Start reading */
	r = uv_read_start(stream, alloc_cb, read_cb);
	TEST_ASSERT(r == 0);
}


void test1()
{
	Sleep(5000);

	struct sockaddr_in addr;
	uv_tcp_t client;
	uv_os_sock_t sock;
	int r;

	//int nRet = uv_ip4_addr("127.0.0.1", 1234, &addr);
	TEST_ASSERT(0 == uv_ip4_addr("127.0.0.1", 1234, &addr));

	startup();
	sock = create_tcp_socket();

	r = uv_tcp_init(uv_default_loop(), &client);
	TEST_ASSERT(r == 0);

	r = uv_tcp_open(&client, sock);
	TEST_ASSERT(r == 0);

	r = uv_tcp_connect(&connect_req,
		&client,
		(const struct sockaddr*) &addr,
		connect_cb);
	TEST_ASSERT(r == 0);

	uv_run(uv_default_loop(), UV_RUN_DEFAULT);

// 	ASSERT(shutdown_cb_called == 1);
// 	ASSERT(connect_cb_called == 1);
// 	ASSERT(write_cb_called == 1);
// 	ASSERT(close_cb_called == 1);

}


//--------------------test1: libuv服务端-------------------//

static uv_tcp_t server;
//static uv_tcp_t tcp_server;

int ChangeCode( 
	const char* pFromCode,
	const char* pToCode,
	const char* pInBuf, size_t uInLen,
	char* pOutBuf, size_t uOutLen )
{
	iconv_t hIconv = iconv_open(pToCode, pFromCode);
	if ( -1 == (int)hIconv )
	{
		return -1;
	}

	char* pIn  = (char*)pInBuf;  // pIn 会被改变, 但是内部内容不会改变
	size_t uLeft = uOutLen;
	int nRet = iconv(hIconv, &pIn, &uInLen, &pOutBuf, &uLeft);

	iconv_close(hIconv);

	int nUseLen = uOutLen - uLeft;
	if ( 0 != nRet || nUseLen<0 )
	{
		return -2;
	}

	return nUseLen;
}

int GbkToUtf8(const char* pSrc, size_t uSrcLen, char* pBuff, size_t uBuffLen) 
{
	return ChangeCode("GB2312", "UTF-8", pSrc, uSrcLen, pBuff, uBuffLen);
}

static void connection_cb(uv_stream_t* tcp, int status) {
	int r;
	uv_buf_t buf;

	//connection_cb_called++;
	//TEST_ASSERT(tcp == (uv_stream_t*)&tcp_server);
	TEST_ASSERT(status == 0);

	r = uv_tcp_init(tcp->loop, &tcp_peer);
	TEST_ASSERT(r == 0);

	r = uv_accept(tcp, (uv_stream_t*)&tcp_peer);
	TEST_ASSERT(r == 0);

	r = uv_read_start((uv_stream_t*)&tcp_peer, alloc_cb, read_cb);
	TEST_ASSERT(r == 0);

	char* str1 = "welcome to X net, -欢迎光临- \n";
	char* str2 = "你好";
	char* str3 = "nihao";

	char* str = str1;
	size_t uStrLen = strlen(str);

	size_t uBuffLen = 1024;
	char* pBuff = new char[uBuffLen];
	memset(pBuff, 0, uBuffLen);

	int nLen = GbkToUtf8(str, uStrLen, pBuff, uBuffLen);
	TEST_ASSERT(nLen > 0);

	buf.base = pBuff;
	buf.len = nLen;

	r = uv_write(&write_req, (uv_stream_t*)&tcp_peer, &buf, 1, write_cb);
	TEST_ASSERT(r == 0);

	delete pBuff;

}


static void start_server(void) {
	struct sockaddr_in addr;
	int r;

	TEST_ASSERT(0 == uv_ip4_addr("127.0.0.1", 1234, &addr));

	r = uv_tcp_init(uv_default_loop(), &server);
	TEST_ASSERT(r == 0);

	r = uv_tcp_bind(&server, (const struct sockaddr*) &addr, 0);
	TEST_ASSERT(r == 0);

	r = uv_listen((uv_stream_t*)&server, 128, connection_cb);
	TEST_ASSERT(r == 0);

}

void test2()
{
	start_server();

	uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}

//--------------------test2: libpomelo-------------------//




static pc_client_t* client;

#define REQ_ROUTE "connector.connectorHandler.entry"
#define REQ_MSG "{\"name\": \"test\"}"
#define REQ_EX ((void*)0x22)
#define REQ_TIMEOUT 10

#define NOTI_ROUTE "test.testHandler.notify"
#define NOTI_MSG "{\"content\": \"test content\"}"
#define NOTI_EX ((void*)0x33)
#define NOTI_TIMEOUT 30

#define EV_HANDLER_EX ((void*)0x44)
#define SERVER_PUSH "onPush"

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep(x * 1000);
#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#endif

static int local_storage_cb(pc_local_storage_op_t op, char* data, size_t* len, void* ex_data)
{
	// 0 - success, -1 - fail
	char buf[1024];
	size_t length;
	size_t offset;
	FILE* f;

	if (op == PC_LOCAL_STORAGE_OP_WRITE) {
		f = fopen("pomelo.dat", "w");
		if (!f) {
			return -1;
		}
		fwrite(data, 1, *len, f);
		fclose(f);
		return 0;

	} else {
		f = fopen("pomelo.dat", "r");
		if (!f) {
			*len = 0;
			return -1;
		}
		*len = 0;
		offset = 0;

		while((length = fread(buf, 1, 1024, f))) {
			*len += length;
			if (data) {
				memcpy(data + offset, buf, length);
			}
			offset += length;
		}

		fclose(f);

		return 0;
	}
}


static void event_cb(pc_client_t* client, int ev_type, void* ex_data, const char* arg1, const char* arg2)
{

	TEST_ASSERT(ex_data == EV_HANDLER_EX);
	printf("test: get event %s, arg1: %s, arg2: %s\n", pc_client_ev_str(ev_type),
		arg1 ? arg1 : "", arg2 ? arg2 : "");
}

static void request_cb(const pc_request_t* req, int rc, const char* resp)
{
	TEST_ASSERT(rc == PC_RC_OK);
	TEST_ASSERT(resp);

	printf("test get resp %s\n", resp);
	fflush(stdout);

	TEST_ASSERT(pc_request_client(req) == client);
	TEST_ASSERT(!strcmp(pc_request_route(req), REQ_ROUTE));
	TEST_ASSERT(!strcmp(pc_request_msg(req), REQ_MSG));
	TEST_ASSERT(pc_request_ex_data(req) == REQ_EX);
	TEST_ASSERT(pc_request_timeout(req) == REQ_TIMEOUT);
}

static void notify_cb(const pc_notify_t* noti, int rc)
{
	TEST_ASSERT(rc == PC_RC_OK);

	TEST_ASSERT(pc_notify_client(noti) == client);
	TEST_ASSERT(!strcmp(pc_notify_route(noti), NOTI_ROUTE));
	TEST_ASSERT(!strcmp(pc_notify_msg(noti), NOTI_MSG));
	TEST_ASSERT(pc_notify_ex_data(noti) == NOTI_EX);
	TEST_ASSERT(pc_notify_timeout(noti) == NOTI_TIMEOUT);
}

void test3()
{
	pc_client_config_t config = PC_CLIENT_CONFIG_DEFAULT;
	int handler_id;
	pc_lib_init(NULL, NULL, NULL, NULL);

	client = (pc_client_t*)malloc(pc_client_size());

	TEST_ASSERT(client);

	config.local_storage_cb = local_storage_cb;
	pc_client_init(client, (void*)0x11, &config);

	TEST_ASSERT(pc_client_ex_data(client) == (void*)0x11);
	TEST_ASSERT(pc_client_state(client) == PC_ST_INITED);

	handler_id = pc_client_add_ev_handler(client, event_cb, EV_HANDLER_EX, NULL);

	pc_client_connect(client, "127.0.0.1", 3010, NULL);

	SLEEP(1);
	pc_request_with_timeout(client, REQ_ROUTE, REQ_MSG, REQ_EX, REQ_TIMEOUT, request_cb);

	pc_notify_with_timeout(client, NOTI_ROUTE, NOTI_MSG, NOTI_EX, NOTI_TIMEOUT, notify_cb);
	SLEEP(50);

	pc_client_disconnect(client);

	pc_client_rm_ev_handler(client, handler_id);

	pc_client_cleanup(client);

	TEST_ASSERT(pc_client_state(client) == PC_ST_NOT_INITED);

	free(client);

	pc_lib_cleanup();
}

}

void test_async(int nFlag)
{
	//space_test_async::test1();
	space_test_async::test2();
	//space_test_async::test3();

	while (nFlag)
	{
		Sleep(1);
	}

}
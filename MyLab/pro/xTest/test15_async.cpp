
#include "xTest.h"

#include "stdafx.h"

#pragma comment(lib, "libuv_d.lib")
#pragma comment(lib, "libpomelo2_d.lib")

#include "uv.h"
#include "pomelo_trans.h"

namespace space_test_async
{

//--------------------test1: libuv-------------------//

static int shutdown_cb_called = 0;
static int connect_cb_called = 0;
static int write_cb_called = 0;
static int close_cb_called = 0;

static uv_connect_t connect_req;
static uv_shutdown_t shutdown_req;
static uv_write_t write_req;

void startup(void) 
{
#ifdef _WIN32
	struct WSAData wsa_data;
	int r = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	//ASSERT(r == 0);
#endif
}

uv_os_sock_t create_tcp_socket(void) 
{
	uv_os_sock_t sock;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
#ifdef _WIN32
	//ASSERT(sock != INVALID_SOCKET);
#else
	ASSERT(sock >= 0);
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

void read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) 
{
	//ASSERT(tcp != NULL);

	if (nread >= 0) {
		//ASSERT(nread == 4);
		//ASSERT(memcmp("PING", buf->base, nread) == 0);
	}
	else {
		//ASSERT(nread == UV_EOF);
		printf("GOT EOF\n");
		//uv_close((uv_handle_t*)tcp, close_cb);
	}
}

void connect_cb(uv_connect_t* req, int status) 
{
	uv_buf_t buf = uv_buf_init("PING", 4);
	uv_stream_t* stream;
	int r;

	//ASSERT(req == &connect_req);
	//ASSERT(status == 0);

	stream = req->handle;
	connect_cb_called++;

	//r = uv_write(&write_req, stream, &buf, 1, write_cb);
	//ASSERT(r == 0);

	/* Shutdown on drain. */
	//r = uv_shutdown(&shutdown_req, stream, shutdown_cb);
	//ASSERT(r == 0);

	/* Start reading */
	r = uv_read_start(stream, alloc_cb, read_cb);
	//ASSERT(r == 0);
}

void test1()
{
	Sleep(5000);

	struct sockaddr_in addr;
	uv_tcp_t client;
	uv_os_sock_t sock;
	int r;

	int nRet = uv_ip4_addr("127.0.0.1", 1234, &addr);
	//ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &addr));

	startup();
	sock = create_tcp_socket();

	r = uv_tcp_init(uv_default_loop(), &client);
	//ASSERT(r == 0);

	r = uv_tcp_open(&client, sock);
	//ASSERT(r == 0);

	r = uv_tcp_connect(&connect_req,
		&client,
		(const struct sockaddr*) &addr,
		connect_cb);
	//ASSERT(r == 0);

	uv_run(uv_default_loop(), UV_RUN_DEFAULT);

// 	ASSERT(shutdown_cb_called == 1);
// 	ASSERT(connect_cb_called == 1);
// 	ASSERT(write_cb_called == 1);
// 	ASSERT(close_cb_called == 1);
}

//--------------------test2: libpomelo-------------------//

#define PC_TEST_ASSERT(expr)                                          \
	do {                                                         \
	if (!(expr)) {                                           \
	fprintf(stderr,                                      \
	"Assertion failed in %s on line %d: %s\n",   \
	__FILE__,                                    \
	__LINE__,                                    \
#expr);                                      \
	abort();                                             \
	}                                                        \
	} while (0)


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

	PC_TEST_ASSERT(ex_data == EV_HANDLER_EX);
	printf("test: get event %s, arg1: %s, arg2: %s\n", pc_client_ev_str(ev_type),
		arg1 ? arg1 : "", arg2 ? arg2 : "");
}

static void request_cb(const pc_request_t* req, int rc, const char* resp)
{
	PC_TEST_ASSERT(rc == PC_RC_OK);
	PC_TEST_ASSERT(resp);

	printf("test get resp %s\n", resp);
	fflush(stdout);

	PC_TEST_ASSERT(pc_request_client(req) == client);
	PC_TEST_ASSERT(!strcmp(pc_request_route(req), REQ_ROUTE));
	PC_TEST_ASSERT(!strcmp(pc_request_msg(req), REQ_MSG));
	PC_TEST_ASSERT(pc_request_ex_data(req) == REQ_EX);
	PC_TEST_ASSERT(pc_request_timeout(req) == REQ_TIMEOUT);
}

static void notify_cb(const pc_notify_t* noti, int rc)
{
	PC_TEST_ASSERT(rc == PC_RC_OK);

	PC_TEST_ASSERT(pc_notify_client(noti) == client);
	PC_TEST_ASSERT(!strcmp(pc_notify_route(noti), NOTI_ROUTE));
	PC_TEST_ASSERT(!strcmp(pc_notify_msg(noti), NOTI_MSG));
	PC_TEST_ASSERT(pc_notify_ex_data(noti) == NOTI_EX);
	PC_TEST_ASSERT(pc_notify_timeout(noti) == NOTI_TIMEOUT);
}

void test2()
{
	pc_client_config_t config = PC_CLIENT_CONFIG_DEFAULT;
	int handler_id;
	pc_lib_init(NULL, NULL, NULL, NULL);

	client = (pc_client_t*)malloc(pc_client_size());

	PC_TEST_ASSERT(client);

	config.local_storage_cb = local_storage_cb;
	pc_client_init(client, (void*)0x11, &config);

	PC_TEST_ASSERT(pc_client_ex_data(client) == (void*)0x11);
	PC_TEST_ASSERT(pc_client_state(client) == PC_ST_INITED);

	handler_id = pc_client_add_ev_handler(client, event_cb, EV_HANDLER_EX, NULL);

	pc_client_connect(client, "127.0.0.1", 3010, NULL);

	SLEEP(1);
	pc_request_with_timeout(client, REQ_ROUTE, REQ_MSG, REQ_EX, REQ_TIMEOUT, request_cb);

	pc_notify_with_timeout(client, NOTI_ROUTE, NOTI_MSG, NOTI_EX, NOTI_TIMEOUT, notify_cb);
	SLEEP(50);

	pc_client_disconnect(client);

	pc_client_rm_ev_handler(client, handler_id);

	pc_client_cleanup(client);

	PC_TEST_ASSERT(pc_client_state(client) == PC_ST_NOT_INITED);

	free(client);

	pc_lib_cleanup();
}

}

void test_async(int nFlag)
{
	//space_test_async::test1();
	space_test_async::test2();

	//pc_client_size();

	while (nFlag)
	{
		Sleep(1);
	}

}
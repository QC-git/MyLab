#include <node.h>
#include "ServiceExport.h"
#include "RouterExport.h"
//#include "RpcWrapExport.h"
#include "RouterProcessorExport.h"
#include "RpcExport.h"
#include "RpcProcessorExport.h"
#include "Log.h"
#include "fstream"

using namespace clusterrouter;

void DummyLog(unsigned int lvl, const char* format, ...)
{

}

unsigned g_loglevel = 2;
LogOutput g_logoutput = DummyLog;

v8::Handle<v8::Value> CreateRouterProcessor(const v8::Arguments& args) {
    v8::HandleScope scope;
    return scope.Close(CRouterProcessorExport::NewInstance(args));
}

v8::Handle<v8::Value> CreateService(const v8::Arguments& args) {
    v8::HandleScope scope;
    return scope.Close(CServiceExport::NewInstance(args));
}

v8::Handle<v8::Value> CreateRouter(const v8::Arguments& args) {
    v8::HandleScope scope;
    return scope.Close(CRouterExport::NewInstance(args));
}

v8::Handle<v8::Value> CreateRpc(const v8::Arguments& args) {
    v8::HandleScope scope;
    return scope.Close(CRpcExport::NewInstance(args));
}

v8::Handle<v8::Value> CreateRpcProcessor(const v8::Arguments& args) {
    v8::HandleScope scope;
    return scope.Close(CRpcProcessorExport::NewInstance(args));
}

v8::Handle<v8::Value> InitLogine(const v8::Arguments& args) {
	v8::HandleScope scope;
	if(args.Length() != 2)
	{
		v8::ThrowException(v8::String::New("InitLogine param err"));
		return scope.Close(v8::Boolean::New(false));
	}

	int nLev = args[0]->Uint32Value();
	v8::String::Utf8Value param1(args[1]->ToString());
	std::string str1 = std::string(*param1);
	g_logoutput = InitLogEngine(nLev, str1.c_str());
	//printf("init logine lev is %d", nLev);
	return scope.Close(v8::Boolean::New(true));
}

//v8::Handle<v8::Value> CreateRpcWrap(const v8::Arguments& args) {
//    v8::HandleScope scope;
//    return scope.Close(CRpcWrapExport::NewInstance(args));
//}

void InitAll(v8::Handle<v8::Object> exports) {
	LOG_TRC("Enter InitAll");
    CServiceExport::Init();
    CRouterProcessorExport::Init();
    CRouterExport::Init();
    CRpcExport::Init();
    CRpcProcessorExport::Init();
    //CRpcWrapExport::Init();

    exports->Set(v8::String::NewSymbol("createService"),
        v8::FunctionTemplate::New(CreateService)->GetFunction());

	exports->Set(v8::String::NewSymbol("createRouter"),
        v8::FunctionTemplate::New(CreateRouter)->GetFunction());  

    exports->Set(v8::String::NewSymbol("createRouterProcessor"),
        v8::FunctionTemplate::New(CreateRouterProcessor)->GetFunction());

    exports->Set(v8::String::NewSymbol("createRpc"),
        v8::FunctionTemplate::New(CreateRpc)->GetFunction());

    exports->Set(v8::String::NewSymbol("createRpcProcessor"),
        v8::FunctionTemplate::New(CreateRpcProcessor)->GetFunction());

	exports->Set(v8::String::NewSymbol("initLogine"),
		v8::FunctionTemplate::New(InitLogine)->GetFunction());

	LOG_TRC("Exit InitAll");
}

NODE_MODULE(rpc, InitAll)





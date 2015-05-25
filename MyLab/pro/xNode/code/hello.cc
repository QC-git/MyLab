#include <node.h>

#include "x_Interface.h"

#pragma comment(lib, "node.lib")
#pragma comment(lib, "xServer.lib")

using namespace v8;

void Method(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);
	
	X_HSER->Init();
	
	ServerVersion();
	
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void init(Handle<Object> exports) {
	NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(addon, init)
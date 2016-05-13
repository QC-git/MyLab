#define BUILDING_NODE_EXTENSION

#include <node.h>
#include "CLWrapper.h"
#include "Log.h"


v8::Handle<v8::Value> CreateCppLoader(const v8::Arguments& args) {
	v8::HandleScope scope;
	return scope.Close(CLWrapper::NewInstance(args));
}

void Init(v8::Handle<v8::Object> exports) {
	//InitLogEngine(0);

	CLWrapper::Init();

	exports->Set(v8::String::NewSymbol("createCppLoader"),
		v8::FunctionTemplate::New(CreateCppLoader)->GetFunction());
}

NODE_MODULE(CppLoader, Init)





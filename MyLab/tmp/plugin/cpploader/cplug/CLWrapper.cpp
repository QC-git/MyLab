
#define BUILDING_NODE_EXTENSION
#include "stdio.h"
#include "CLWrapper.h"
#include "Log.h"


using namespace v8;

void DummyLog(unsigned int lvl, const char* format, ...)
{

}

unsigned g_loglevel = 2;
LogOutput g_logoutput = DummyLog;

Persistent<Function> CLWrapper::constructor;

CLWrapper::CLWrapper() 
#ifdef WIN32
	: m_plugImpl(new CWinLoader)
#else
	: m_plugImpl(new CLinuxLoader)
#endif
{
}

CLWrapper::~CLWrapper()
{
	if(m_plugImpl)
	{
		delete m_plugImpl;
	}
}

void CLWrapper::Init(/*Handle<ObjectTemplate> exports*/) {
	// Prepare constructor template
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("CLWrapper"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);
	// Prototype
	tpl->PrototypeTemplate()->Set(String::NewSymbol("create"),
		FunctionTemplate::New(Create)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("destory"),
		FunctionTemplate::New(Destory)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("update"),
		FunctionTemplate::New(Update)->GetFunction());
	constructor = Persistent<Function>::New(tpl->GetFunction());
	//exports->Set(v8::String::NewSymbol("CLWrapper"), constructor);
}

Handle<Value> CLWrapper::New(const Arguments& args) {
	HandleScope scope;

	if (args.IsConstructCall()) 
	{
		CLWrapper* obj = new CLWrapper();

		obj->Wrap(args.This());
		return scope.Close(args.This());
	} 
	else
	{
		// Invoked as plain function `MyObject(...)`, turn into construct call.
		const unsigned argc = 0;
		Handle<Value> argv[1] = {};
		return scope.Close(constructor->NewInstance(argc, argv));
	}
}

Handle<Value> CLWrapper::NewInstance(const Arguments& args) {
	HandleScope scope;

	const unsigned argc = 0;
	Handle<Value> argv[1] = {};
	Local<Object> instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}

Handle<Value> CLWrapper::Create(const Arguments& args) {
	LOG_TRC("Enter CLWrapper::Create");
	HandleScope scope;

	if(args.Length() != 4)
	{
		ThrowException(String::New("CLWrapper::Create param num err"));
		return scope.Close(Boolean::New(false));
	}

	CLWrapper* obj = ObjectWrap::Unwrap<CLWrapper>(args.This());
	if(!obj || !obj->m_plugImpl){
		ThrowException(String::New("CLWrapper::Create err"));
		return scope.Close(Boolean::New(false));
	}

	std::string module(*v8::String::Utf8Value(args[0]->ToString()));
    std::string sid(*v8::String::Utf8Value(args[1]->ToString()));
    std::string env(*v8::String::Utf8Value(args[2]->ToString()));
    g_loglevel = (unsigned int)(args[3]->NumberValue());
	LOG_DBG("the server start DLL name is %s", sid.c_str());
    if(!obj->m_plugImpl->Load(module.c_str()))
	{
		return scope.Close(Boolean::New(false));
	}

    g_logoutput = obj->m_plugImpl->InitLog(g_loglevel, sid.c_str());
	obj->m_plugImpl->Create(sid.c_str(), env.c_str());
	LOG_TRC("Exit CLWrapper::Create");
	return scope.Close(Boolean::New(true));
}

Handle<Value> CLWrapper::Destory(const v8::Arguments& args){
	HandleScope scope;

	CLWrapper* obj = ObjectWrap::Unwrap<CLWrapper>(args.This());
	if(!obj || !obj->m_plugImpl){
		ThrowException(String::New("CLWrapper::Destory err"));
		return scope.Close(Undefined());
	}

	obj->m_plugImpl->Destory();
	return scope.Close(Undefined());
}

Handle<Value> CLWrapper::Update(const v8::Arguments& args){
	HandleScope scope;

	CLWrapper* obj = ObjectWrap::Unwrap<CLWrapper>(args.This());
	if(!obj || !obj->m_plugImpl){
		ThrowException(String::New("CLWrapper::Update err"));
		return scope.Close(Undefined());
	}

	obj->m_plugImpl->Update();
	return scope.Close(Undefined());
}



#include "stdio.h"
#include "Define.h"
#include <string>
#include "ServiceExport.h"
#include "Interface.h"
#include "Log.h"

using namespace v8;
using namespace clusterrouter; 
Persistent<Function> CServiceExport::constructor;

CServiceExport::CServiceExport(const Env& env) : m_service(Service::Create(env))
{
}

CServiceExport::~CServiceExport()
{
    if(m_service)
    {
        m_service->Release();
    }
}

void CServiceExport::Init(/*Handle<ObjectTemplate> exports*/) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("CServiceExport"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    // Prototype
    tpl->PrototypeTemplate()->Set(String::NewSymbol("start"),
        FunctionTemplate::New(Start)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("stop"),
        FunctionTemplate::New(Stop)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("addAddr"),
        FunctionTemplate::New(AddAddr)->GetFunction());
    constructor = Persistent<Function>::New(tpl->GetFunction());
    //exports->Set(v8::String::NewSymbol("CServiceExport"), constructor);
}

Handle<Value> CServiceExport::New(const Arguments& args) {
    HandleScope scope;

    if(args.Length() != 4)
    {
		//printf("the args length is %d", args.Length());
        ThrowException(String::New("err parameters for NewService"));
        return Undefined();
    }

    if (args.IsConstructCall()) {
        Env env;
		v8::String::Utf8Value param1(args[0]->ToString());
		std::string str1 = std::string(*param1);
		strcpy_s(env.addr, str1.c_str());
		//printf("----------%s", str1.c_str());

	    v8::String::Utf8Value param2(args[1]->ToString());
	    std::string str2 = std::string(*param2);
		strcpy_s(env.dbip, str2.c_str());
		//printf("----------%s", str2.c_str());

		env.dbport = args[2]->Uint32Value();
		//printf("----------%d", env.dbport);

        env.objLife = args[3]->Uint32Value();
		//printf("----------%d", env.objLife);
        CServiceExport* obj = new CServiceExport(env);

        obj->Wrap(args.This());
        return scope.Close(args.This());
    } 
	else
	{
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const unsigned argc = 4;
        Handle<Value> argv[argc] = { args[0],  args[1], args[2], args[3]};
        return scope.Close(constructor->NewInstance(argc, argv));
    }
}

Handle<Value> CServiceExport::NewInstance(const Arguments& args) {
    HandleScope scope;

	const unsigned argc = 4;
	Handle<Value> argv[argc] = { args[0],  args[1], args[2], args[3]};
	Local<Object> instance = constructor->NewInstance(argc, argv);

    return scope.Close(instance);
}

Handle<Value> CServiceExport::Start(const Arguments& args) {
    HandleScope scope;

    // 在Create service的时候会自动Start
//     CServiceExport* obj = ObjectWrap::Unwrap<CServiceExport>(args.This());
//     if(!obj || !obj->m_service){
//         ThrowException(String::New("CServiceExport::Start err"));
//         return Undefined();
//     }
//     obj->m_service->Start();
    return scope.Close(Undefined());
}

Handle<Value> CServiceExport::Stop(const v8::Arguments& args){
    HandleScope scope;

    CServiceExport* obj = ObjectWrap::Unwrap<CServiceExport>(args.This());
    if(!obj || !obj->m_service){
        ThrowException(String::New("CServiceExport::Stop err"));
        return Undefined();
    }
    obj->m_service->Stop();
    return scope.Close(Undefined());
}

Handle<Value> CServiceExport::AddAddr(const v8::Arguments& args){
    HandleScope scope;

    CServiceExport* obj = ObjectWrap::Unwrap<CServiceExport>(args.This());
    if(!obj || !obj->m_service){
        ThrowException(String::New("CServiceExport::AddAddr err"));
        return Undefined();
    }

    if(!args[0]->IsString()){
        ThrowException(String::New("CServiceExport::AddAddr params err"));
        return Undefined();
    }

    v8::String::Utf8Value param1(args[0]->ToString());
    std::string str1 = std::string(*param1);
    obj->m_service->AddAddr(str1.c_str());
    return scope.Close(Undefined());
}

Service* CServiceExport::GetWrapped()
{
	return m_service;
}




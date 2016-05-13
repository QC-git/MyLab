#include "stdio.h"
#include "RpcProcessorExport.h"
#include "ProtoTrans.h"
#include "Log.h"
#include <string>

using namespace v8;
using namespace clusterrouter; 
Persistent<Function> CRpcProcessorExport::constructor;

CRpcProcessorExport::CRpcProcessorExport()/* : m_routerProc(RouterProcessor::Create())*/
{
}

CRpcProcessorExport::~CRpcProcessorExport()
{
    //if(m_routerProc)
    //{
    //    m_routerProc->Release();
    //}
}

void CRpcProcessorExport::Init(/*Handle<ObjectTemplate> exports*/) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("CRpcProcessorExport"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    // Prototype
    tpl->PrototypeTemplate()->Set(String::NewSymbol("regRpcProcess"),
        FunctionTemplate::New(RegRpcProcessor)->GetFunction());
    //printf("new CRpcProcessorExport::Init success111111!!!!!!!!!\n");
    constructor = Persistent<Function>::New(tpl->GetFunction());
    //printf("new CRpcProcessorExport::Init success22222222!!!!!!!!!\n");
    //exports->Set(v8::String::NewSymbol("CRpcProcessorExport"), constructor);
}

Handle<Value> CRpcProcessorExport::New(const Arguments& args) {
    //printf("new CRpcProcessorExport::New success!!!!!!!!\n");
    HandleScope scope;

    if (args.IsConstructCall()) {
#ifdef DEBUG
        //printf("---------------trace CRpcProcessorExport::New enter!");
#endif
        CRpcProcessorExport* obj = new CRpcProcessorExport;

        obj->Wrap(args.This());
        //printf("new CRpcProcessorExport::New success!!!!!!!!!\n");
#ifdef DEBUG
        //printf("---------------trace CRpcProcessorExport::New success!");
#endif
        return scope.Close(args.This());
    } else {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const unsigned argc = 0;
        Handle<Value> argv[1] = {};
        return scope.Close(constructor->NewInstance(argc, argv));
    }
}

Handle<Value> CRpcProcessorExport::NewInstance(const Arguments& args) {
    HandleScope scope;

    const unsigned argc = 0;
    Handle<Value> argv[1] = {};
    Local<Object> instance = constructor->NewInstance(argc, argv);

    return scope.Close(instance);
}

Handle<Value> CRpcProcessorExport::RegRpcProcessor(const v8::Arguments& args)
{
    HandleScope scope;
    CRpcProcessorExport* obj = ObjectWrap::Unwrap<CRpcProcessorExport>(args.This());
    if(!obj){
        LOG_ERR("CRpcProcessorExport::RegRpcProcessor err");
        return scope.Close(Undefined());
    }

    Local<Object> Obj = args[0]->ToObject();
    obj->m_jsRpcProcessor = Persistent<Object>::New(Obj);
#ifdef DEBUG
    /*printf("_________________the jsRpcProcessor's pointer is %d\n", obj->m_jsRpcProcessor);
    Local<Array> Properties = obj->m_jsRpcProcessor->GetPropertyNames();
    for(uint32_t i=0; i<Properties->Length(); i++){
        Local<Value> PropertyName = Properties->Get(i);
        Local<Value> Property = obj->m_jsRpcProcessor->Get(PropertyName);
        String::Utf8Value strUtf8(PropertyName->ToString());
        std::string name = std::string(*strUtf8);
        printf("_________________%s\n", name.c_str());
    }*/
#endif

    return scope.Close(Undefined());
}

void CRpcProcessorExport::OnRequest(const void* identity, unsigned char idLen, const void* data, unsigned short dLen, const void* idFrom, unsigned char fromLen, unsigned int reqId){
	LOG_TRC("Enter CRpcProcessorExport::OnRequest");
    HandleScope scope;

    Local<String> key = String::New("onRequest");
    if(!m_jsRpcProcessor->HasOwnProperty(key)){
        LOG_ERR("no onRequest property!!");
		LOG_TRC("Exit CRpcProcessorExport::OnRequest");
        scope.Close(Undefined());
        return;
    }

    Local<String> str = String::New(static_cast<const char*> (idFrom), fromLen);
    v8::String::Utf8Value v8str(str);
    std::string stridFrom = std::string(*v8str);
    Local<Value> pro = m_jsRpcProcessor->Get(key);
    Local<Function> func = Local<Function>::Cast(pro);
    Local<Object> Obj = g_protoConverter->DataToJsObject(const_cast<void*>(data), dLen);
    const int argc = 4;
    Handle<Value> argv[argc] = { String::New(static_cast<const char*> (identity), idLen), Obj, String::New(static_cast<const char*> (idFrom), fromLen), Number::New(reqId)};
    func->Call(Context::GetCurrent()->Global(), argc, argv);
    scope.Close(Undefined());
	LOG_TRC("Exit CRpcProcessorExport::OnRequest");
}

void CRpcProcessorExport::OnResponse(unsigned int requestId, RpcErr err, const void* data, unsigned short dLen)
{
	LOG_TRC("Enter CRpcProcessorExport::OnResponse");
    HandleScope scope;

    Local<String> key = String::New("onResponse");
    if(!m_jsRpcProcessor->HasOwnProperty(key)){
        LOG_ERR("no onResponse property");
		LOG_TRC("Exit CRpcProcessorExport::OnResponse");
        scope.Close(Undefined());
        return;
    }

    Local<Value> pro = m_jsRpcProcessor->Get(key);
    Local<Function> func = Local<Function>::Cast(pro);
    Local<Object> Obj;
    if (err == RpcErr_succ)
        Obj = g_protoConverter->DataToJsObject(data, dLen);
    else
    {
        Obj = Object::New();
        LOG_WRN("CRpcProcessorExport::OnResponse rpc call err[%d]", err);
    }
    const int argc = 3;
    Handle<Value> argv[argc] = { Number::New(requestId), Number::New(err), Obj };
    func->Call(Context::GetCurrent()->Global(), argc, argv);
    scope.Close(Undefined());
	LOG_TRC("Exit CRpcProcessorExport::OnResponse");
}



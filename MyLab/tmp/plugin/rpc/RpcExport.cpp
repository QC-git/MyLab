#include "stdio.h"
#include "RpcExport.h"
#include "Log.h"
#include "Interface.h"
#include <string>
#include <boost/scoped_array.hpp>
#include "RouterExport.h"
#include "RpcProcessorExport.h"
#include "ProtoTrans.h"

using namespace v8;
using namespace clusterrouter; 
Persistent<Function> CRpcExport::constructor;

const int _PROTOBUF_MSG_BUF_SIZE = 4096;

CRpcExport::CRpcExport(Router* router, RpcProcessor* prc)
    : m_pRpc(Rpc::Create(router, prc))
{

}

CRpcExport::~CRpcExport()
{
    if(m_pRpc)
    {
        m_pRpc->Release();
    }
}

void CRpcExport::Init(/*Handle<ObjectTemplate> exports*/) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("CRpcExport"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype
    tpl->PrototypeTemplate()->Set(String::NewSymbol("request"),
        FunctionTemplate::New(Request)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("response"),
        FunctionTemplate::New(Response)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("setTimeout"),
        FunctionTemplate::New(SetTimeout)->GetFunction());
    constructor = Persistent<Function>::New(tpl->GetFunction());
    //exports->Set(v8::String::NewSymbol("CRpcExport"), constructor);
}

Handle<Value> CRpcExport::New(const Arguments& args) {
    HandleScope scope;

    if(args.Length() != 2 || !args[0]->IsObject() || !args[1]->IsObject())
    {
        ThrowException(String::New("err parameters for CRpcExport"));
        return scope.Close(Undefined());
    }

    if (args.IsConstructCall()) {
        CRouterExport *pRouterExport = node::ObjectWrap::Unwrap<CRouterExport>(args[0]->ToObject());
        if(!pRouterExport){
            ThrowException(String::New("pRouterProcExport is null"));
            return scope.Close(Undefined());
        }

        Router* pRouter = pRouterExport->GetWrapped();

        CRpcProcessorExport *pRpcProcessorExport = node::ObjectWrap::Unwrap<CRpcProcessorExport>(args[1]->ToObject());
        if(!pRpcProcessorExport){
            ThrowException(String::New("pRpcProcessorExport is null"));
            return scope.Close(Undefined());
        }

        RpcProcessor* pRpcProcessor = pRpcProcessorExport->GetWrapped();

        CRpcExport* obj = new CRpcExport(pRouter, pRpcProcessor);
        obj->Wrap(args.This());
        return scope.Close(args.This());
    }
    else 
    {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const unsigned argc = 2;
        Handle<Value> argv[argc] = { args[0],  args[1] };
        return scope.Close(constructor->NewInstance(argc, argv));
    }
}

Handle<Value> CRpcExport::NewInstance(const Arguments& args) {
    HandleScope scope;

    const unsigned argc = 2;
    Handle<Value> argv[argc] = { args[0],  args[1] };
    Local<Object> instance = constructor->NewInstance(argc, argv);

    return scope.Close(instance);
}

Handle<Value> CRpcExport::Request(const Arguments& args) {
	LOG_TRC("Enter CRpcExport::Request");
    HandleScope scope;

    if(args.Length() != 3){
        LOG_ERR("CRpcExport::Request params err");
		LOG_TRC("Exit CRpcExport::Request");
        return scope.Close(Undefined());
    }

    CRpcExport* obj = ObjectWrap::Unwrap<CRpcExport>(args.This());
    if(!obj || !obj->m_pRpc){
        LOG_ERR("CRpcExport::Request err");
		LOG_TRC("Exit CRpcExport::Request");
        return scope.Close(Undefined());
    }

    v8::String::Utf8Value str(args[0]->ToString());
    std::string identity = std::string(*str);
    v8::String::Utf8Value arg4(args[2]->ToString());
    std::string name = std::string(*arg4);
    if (name.size()<5)
    {
        LOG_ERR("name[%s] size too small", name.c_str());
        return scope.Close(Number::New(0));
    }

    boost::scoped_array<char> buf;
    int nMsgLen = g_protoConverter->JsObjectToData(args[1]->ToObject(), name, buf);
    int reqId = obj->m_pRpc->Request(identity.c_str(), identity.length(), buf.get(), nMsgLen);
	LOG_TRC("Exit CRpcExport::Request");
    return scope.Close(Number::New(reqId));
}

Handle<Value> CRpcExport::Response(const v8::Arguments& args){
	LOG_TRC("Enter CRpcExport::Response");
    HandleScope scope;

    if(args.Length() != 5){
        LOG_ERR("Response require 5 params");
		LOG_TRC("Exit CRpcExport::Response");
        return scope.Close(Undefined());
    }

    CRpcExport* obj = ObjectWrap::Unwrap<CRpcExport>(args.This());
    if(!obj || !obj->m_pRpc){
        LOG_ERR("CRpcExport::Response err");
		LOG_TRC("Exit CRpcExport::Response");
        return scope.Close(Undefined());
    }

    int rid = args[0]->ToInt32()->Value();
    RpcErr err = (RpcErr)(args[1]->ToInt32()->Value());
    v8::String::Utf8Value str(args[2]->ToString());
    std::string identity = std::string(*str);
    v8::String::Utf8Value arg4(args[4]->ToString());
    std::string name = std::string(*arg4);
#ifdef DEBUG
    //printf("\n================the identity is %s!\n", identity.c_str());
    /*printf("================Trace Debug CRpcExport::Response!\n");
    Local<Object> Obj = args[3]->ToObject();
    Local<Array> Properties = Obj->GetPropertyNames();
    for(int i=0; i<Properties->Length(); i++){
        Local<Value> PropertyName = Properties->Get(i);
        Local<Value> Property = Obj->Get(PropertyName);
        String::Utf8Value strUtf8(PropertyName->ToString());
        std::string name = std::string(*strUtf8);
        printf("================%s\n", name.c_str());

    }*/
#endif
    if (name.size()<5)
    {
        LOG_ERR("name[%s] size too small", name.c_str());
        return scope.Close(Undefined());
    }
    boost::scoped_array<char> buf;
    int nMsgLen = g_protoConverter->JsObjectToData(args[3]->ToObject(), name, buf);
    obj->m_pRpc->Response(rid, err, identity.c_str(), identity.length(), buf.get(), nMsgLen);
	LOG_TRC("Exit CRpcExport::Response");
    return scope.Close(Undefined());
}

Handle<Value> CRpcExport::SetTimeout(const v8::Arguments& args){
    HandleScope scope;

    if(args.Length() != 1){
        ThrowException(String::New("CRpcExport::SetTimeout params err"));
        return scope.Close(Undefined());
    }

    CRpcExport* obj = ObjectWrap::Unwrap<CRpcExport>(args.This());
    if(!obj || !obj->m_pRpc){
        ThrowException(String::New("CRpcExport::RegObj err"));
        return scope.Close(Undefined());
    }

    obj->m_pRpc->SetTimeout(static_cast<unsigned int>(args[0]->NumberValue()));
    return scope.Close(Undefined());
}

Rpc* CRpcExport::GetWrapped()
{
    return m_pRpc;
}



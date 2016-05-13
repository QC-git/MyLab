#include "stdio.h"
#include "RouterProcessorExport.h"
#include "ProtoTrans.h"
#include "Log.h"
#include <string>

using namespace v8;
using namespace clusterrouter; 
Persistent<Function> CRouterProcessorExport::constructor;

CRouterProcessorExport::CRouterProcessorExport()/* : m_routerProc(RouterProcessor::Create())*/
{
    //printf("new CRouterProcessorExport::CRouterProcessorExport success!!!!!!!!!\n");
}

CRouterProcessorExport::~CRouterProcessorExport()
{
    //printf("new CRouterProcessorExport::~CRouterProcessorExport success!!!!!!!!\n");
    //if(m_routerProc)
    //{
    //    m_routerProc->Release();
    //}
}

void CRouterProcessorExport::Init(/*Handle<ObjectTemplate> exports*/) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("CRouterProcessorExport"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    // Prototype
    tpl->PrototypeTemplate()->Set(String::NewSymbol("regRouterProcess"),
        FunctionTemplate::New(RegRouterProcessor)->GetFunction());
    //printf("new CRouterProcessorExport::Init success111111!!!!!!!!!\n");
    constructor = Persistent<Function>::New(tpl->GetFunction());
    //printf("new CRouterProcessorExport::Init success22222222!!!!!!!!!\n");
    //exports->Set(v8::String::NewSymbol("CRouterProcessorExport"), constructor);
}

Handle<Value> CRouterProcessorExport::New(const Arguments& args) {
    //printf("new CRouterProcessorExport::New success!!!!!!!!\n");
    HandleScope scope;

    if (args.IsConstructCall()) {
        CRouterProcessorExport* obj = new CRouterProcessorExport();

        obj->Wrap(args.This());
        //printf("new CRouterProcessorExport::New success!!!!!!!!!\n");
        return scope.Close(args.This());
    } else {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const unsigned argc = 0;
        Handle<Value> argv[1] = {};
        //printf("new CRouterProcessorExport::New success!\n");
        return scope.Close(constructor->NewInstance(argc, argv));
    }
}

Handle<Value> CRouterProcessorExport::NewInstance(const Arguments& args) {
    HandleScope scope;

    const unsigned argc = 0;
    Handle<Value> argv[1] = {};
    Local<Object> instance = constructor->NewInstance(argc, argv);

    return scope.Close(instance);
}

Handle<Value> CRouterProcessorExport::RegRouterProcessor(const v8::Arguments& args)
{
    HandleScope scope;

    CRouterProcessorExport* obj = ObjectWrap::Unwrap<CRouterProcessorExport>(args.This());
    if(!obj){
        ThrowException(String::New("CRouterProcessorExport::RegRouterProcessor err"));
        return scope.Close(Undefined());
    }

    Local<Object> Obj = args[0]->ToObject();
    obj->m_jsRouterProcessor = Persistent<Object>::New(Obj);
#ifdef DEBUG
    /*printf("_________________the jsRouter's pointer is %d\n", obj->m_jsRouterProcessor);
    Local<Array> Properties = obj->m_jsRouterProcessor->GetPropertyNames();
    for(uint32_t i=0; i<Properties->Length(); i++){
        Local<Value> PropertyName = Properties->Get(i);
        Local<Value> Property = obj->m_jsRouterProcessor->Get(PropertyName);
        String::Utf8Value strUtf8(PropertyName->ToString());
        std::string name = std::string(*strUtf8);
        printf("_________________%s\n", name.c_str());
    }*/
#endif

    return scope.Close(Undefined());
}

void CRouterProcessorExport::InterfaceComImpl(Local<String> key, const void* identity, unsigned char idLen, void* data, unsigned short dLen)
{
    HandleScope scope;


#ifdef DEBUG
    /*if(m_jsRouterProcessor){
        printf("__________________Trace CRouterProcessorExport::InterfaceComImpl exit before!\n");
        return;
    }
    Local<Array> Properties = m_jsRouterProcessor->GetPropertyNames();
    printf("_________________the jsRouter's pointer is %d\n", m_jsRouterProcessor);
    printf("_________________the properties num is %d\n", Properties->Length());
    for(uint32_t i=0; i<Properties->Length(); i++){
        Local<Value> PropertyName = Properties->Get(i);
        Local<Value> Property = m_jsRouterProcessor->Get(PropertyName);
        String::Utf8Value strUtf8(PropertyName->ToString());
        std::string name = std::string(*strUtf8);
        printf("_________________%s\n", name.c_str());
    }*/
#endif

    if(!m_jsRouterProcessor->HasOwnProperty(key)){
        LOG_ERR("OnRouteinterface no the property");
        scope.Close(Undefined());
        return;
    }

    Local<Value> pro = m_jsRouterProcessor->Get(key);
    Local<Function> func = Local<Function>::Cast(pro);
    Local<Object> Obj = g_protoConverter->DataToJsObject(data, dLen);
    const int argc = 2;
    Handle<Value> argv[argc] = { String::New(static_cast<const char*> (identity)), Obj };
    func->Call(Context::GetCurrent()->Global(), argc, argv);
    scope.Close(Undefined());
}

void CRouterProcessorExport::OnRoute(const void* identity, unsigned char idLen, void* data, unsigned short dLen){
    HandleScope scope;

    Local<String> key = String::New("onRoute");
    this->InterfaceComImpl(key, identity, idLen, data, dLen);
    scope.Close(Undefined());
}


/*Handle<Value> CRouterProcessorExport::OnRoute(const void* identity, unsigned char idLen, void* data, unsigned short dLen) {
    //printf("new CRouterProcessorExport::OnRoute success!!!!!!!!\n");
    HandleScope scope;

    CRouterProcessorExport* obj = ObjectWrap::Unwrap<CRouterProcessorExport>(args.This());
    if(!obj || !obj->m_routerProc){
        ThrowException(String::New("CRouterProcessorExport::OnRoute err"));
        return scope.Close(Undefined());
    }

    String::Utf8Value arg(args[0]->ToString());
    std::string str = std::string(*arg);

    //ObjectWrap *pObject = node::ObjectWrap::Unwrap<ObjectWrap>(args[2]->ToObject());
    //if(!pObject){
    //    ThrowException(String::New("pObject is null"));
    //    return scope.Close(Undefined());
    //}

    String::Utf8Value arg1(args[2]->ToString());
    std::string str1 = std::string(*arg1);

    obj->m_routerProc->OnRoute( str.c_str(), 
                                static_cast<unsigned char>(args[1]->Int32Value()), 
                                (void*)str1.c_str(), 
                                static_cast<unsigned short>(args[3]->Int32Value()));

    return scope.Close(Undefined());
}

RouterProcessor* CRouterProcessorExport::GetWrapped()
{
    //printf("new CRouterProcessorExport::GetWrapped success!!!!!!!!\n");
    return m_routerProc;
}*/



#include "stdio.h"
#include "ServiceExport.h"
#include "RouterExport.h"
#include "RouterProcessorExport.h"
#include "Interface.h"
#include "Log.h"
#include "ProtoTrans.h"
#include <string>
#include <boost/scoped_array.hpp>

using namespace v8;
using namespace clusterrouter; 
Persistent<Function> CRouterExport::constructor;


CRouterExport::CRouterExport(const char* addr, RouterProcessor* pRp)
    : m_router(Router::Create(addr, pRp))
{

}

CRouterExport::CRouterExport(Service* local, RouterProcessor* pRp)
    :m_router(Router::Create(local, pRp))
{

}


CRouterExport::~CRouterExport()
{
    if(m_router)
    {
        m_router->Release();
    }
}

void CRouterExport::Init(/*Handle<ObjectTemplate> exports*/) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("CRouterExport"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype
    tpl->PrototypeTemplate()->Set(String::NewSymbol("update"),
        FunctionTemplate::New(Update)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("regObj"),
        FunctionTemplate::New(RegObj)->GetFunction());
//     tpl->PrototypeTemplate()->Set(String::NewSymbol("regBalance"),
//         FunctionTemplate::New(RegBalance)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("unReg"),
        FunctionTemplate::New(Unreg)->GetFunction());
    tpl->PrototypeTemplate()->Set(String::NewSymbol("route"),
        FunctionTemplate::New(Route)->GetFunction());
    constructor = Persistent<Function>::New(tpl->GetFunction());
    //exports->Set(v8::String::NewSymbol("CRouterExport"), constructor);
}

Handle<Value> CRouterExport::New(const Arguments& args) {
    HandleScope scope;

    if(args.Length() != 2 || !args[1]->IsObject())
    {
        ThrowException(String::New("err parameters for NewRouter"));
        return scope.Close(Undefined());
    }

    if (args.IsConstructCall()) {
#ifdef DEBUG
        /*printf("_________________%s", "Trace Debug CRouterExport::New!\n");
        Local<Object> Obj = args[1]->ToObject();
        Local<Array> Properties = Obj->GetPropertyNames();
        for(int i=0; i<Properties->Length(); i++){
            Local<Value> PropertyName = Properties->Get(i);
            Local<Value> Property = Obj->Get(PropertyName);
            String::Utf8Value strUtf8(PropertyName->ToString());
            std::string name = std::string(*strUtf8);
            printf("_________________%s\n", name.c_str());
            if(Property->IsString())
            {
                String::Utf8Value str(Property->ToString());
                std::string name = std::string(*str);
                printf("_________________%s\n", name.c_str());
            }
            else if(Property->IsNumber())
            {   
                printf("_________________%d\n", Property->ToNumber()->Value());
            }
            else if(Property->IsFunction())
            {
                Local<Function> func = Local<Function>::Cast(Property);
                Handle<Value> funcName = func->GetName();
                String::Utf8Value utf8FuncName(funcName);
                std::string cFuncName = std::string(*utf8FuncName);
                printf("_________________%s\n", cFuncName.c_str());
            }
            else
            {
                printf("_________________%s\n", "CRouterExport::New else branch");
            }
        }*/
#endif

        CRouterProcessorExport *pRouterProcExport = node::ObjectWrap::Unwrap<CRouterProcessorExport>(args[1]->ToObject());
        if(!pRouterProcExport){
            ThrowException(String::New("pRouterProcExport is null"));
            return scope.Close(Undefined());
        }

        /*RouterProcessor* pRouterProc = pRouterProcExport->GetWrapped();
        if(!pRouterProc){
            ThrowException(String::New("pRouterProc is null"));
            return scope.Close(Undefined());
        }*/
        //Local<Object> Obj = args[1]->ToObject();

        if(args[0]->IsString())
        {
            String::Utf8Value arg1(args[0]->ToString());
            std::string str = std::string(*arg1);
            CRouterExport* obj = new CRouterExport(str.c_str(), pRouterProcExport);
            obj->Wrap(args.This());
            //printf("_________________%s\n", "CRouterExport::New success 1!");
            return scope.Close(args.This());
        }
        else
        {
            if(!args[0]->IsObject())
            {
                ThrowException(String::New("err parameters for NewRouter"));
                return scope.Close(Undefined());
            }

            CServiceExport *pServiceExport = node::ObjectWrap::Unwrap<CServiceExport>(args[0]->ToObject());
            if(!pServiceExport){
                ThrowException(String::New("pServiceExport is null"));
                return scope.Close(Undefined());
            }

            Service* pService = pServiceExport->GetWrapped();
            if(!pService){
                ThrowException(String::New("pService is null"));
                return scope.Close(Undefined());
            }

            CRouterExport* obj = new CRouterExport(pService, pRouterProcExport);
            obj->Wrap(args.This());
            //printf("_________________%s\n", "CRouterExport::New success 2!");
            return scope.Close(args.This());
        }
    }
    else 
    {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        //printf("CRouterExport::New enter other path!!");
        const unsigned argc = 2;
        Handle<Value> argv[argc] = { args[0],  args[1] };
        return scope.Close(constructor->NewInstance(argc, argv));
    }
}

Handle<Value> CRouterExport::NewInstance(const Arguments& args) {
    HandleScope scope;

    const unsigned argc = 2;
    Handle<Value> argv[argc] = { args[0],  args[1] };
    Local<Object> instance = constructor->NewInstance(argc, argv);

    return scope.Close(instance);
}

Handle<Value> CRouterExport::Update(const Arguments& args) {
    HandleScope scope;

    CRouterExport* obj = ObjectWrap::Unwrap<CRouterExport>(args.This());
    if(!obj || !obj->m_router){
        LOG_ERR("CRouterExport::Update err");
        return scope.Close(Undefined());
    }

    obj->m_router->Update();
    return scope.Close(Undefined());
}

Handle<Value> CRouterExport::Route(const v8::Arguments& args){
	LOG_TRC("Enter CRouterExport::Route");
    HandleScope scope;

    if(args.Length() != 3){
		LOG_ERR("route require 3 params, the params length is %d", args.Length());
		LOG_TRC("Exit CRouterExport::RegObj");
       return scope.Close(Undefined());
    }

    CRouterExport* obj = ObjectWrap::Unwrap<CRouterExport>(args.This());
    if(!obj || !obj->m_router){
        LOG_ERR("CRouterExport::Route err");
		LOG_TRC("Exit CRouterExport::RegObj");
       return Undefined();
    }

    v8::String::Utf8Value arg(args[0]->ToString());
    std::string str = std::string(*arg);

    v8::String::Utf8Value arg2(args[2]->ToString());
    std::string name = std::string(*arg2);

    //todo要测试这样解出通用对象指针是否OK
    boost::scoped_array<char> buf;
    //void* ptr = External::Unwrap(args[2]->ToObject());
#ifdef DEBUG
    /*printf("_________________Trace Debug CRouterExport::Route!\n");
    Local<Object> Obj = args[1]->ToObject();
    Local<Array> Properties = Obj->GetPropertyNames();
    for(int i=0; i<Properties->Length(); i++){
        Local<Value> PropertyName = Properties->Get(i);
        Local<Value> Property = Obj->Get(PropertyName);
        String::Utf8Value strUtf8(PropertyName->ToString());
        std::string name = std::string(*strUtf8);
        printf("_________________%s\n", name.c_str());
        if(Property->IsString())
        {
            String::Utf8Value str(Property->ToString());
            std::string name = std::string(*str);
            printf("_________________%s\n", name.c_str());
        }
        else if(Property->IsNumber())
        {   
            printf("_________________%f\n", Property->ToNumber()->Value());
        }
        else
        {
            printf("_________________%s\n", "Trace CRouterExport::New else branch");
        }
    }*/
#endif
    if (name.size()<5)
    {
        LOG_ERR("name[%s] size too small", name.c_str());
        return scope.Close(Undefined());
    }

    int nMsgLen = g_protoConverter->JsObjectToData(args[1]->ToObject(), name, buf);
    //v8::String::Utf8Value arg2(args[2]->ToString());
    //std::string str2 = std::string(*arg2);
    //Object *pObject = node::ObjectWrap::Unwrap<Object>(args[2]->ToObject());
    //if(!pObject){
    //    ThrowException(String::New("pObject is null"));
    //    return scope.Close(Undefined());
    //}

    obj->m_router->Route( str.c_str(),
                          str.length(),
                          buf.get(),
                          nMsgLen);


	LOG_TRC("Exit CRouterExport::Route");
    return scope.Close(Undefined());
}

Handle<Value> CRouterExport::RegObj(const v8::Arguments& args){
	LOG_TRC("Enter CRouterExport::RegObj");
    HandleScope scope;

    if(args.Length() != 1)
	{
        LOG_ERR("RegObj require 1 param, and the params length is %d", args.Length());
		LOG_TRC("Exit CRouterExport::RegObj");
        return scope.Close(Undefined());
    }

    CRouterExport* obj = ObjectWrap::Unwrap<CRouterExport>(args.This());
    if(!obj || !obj->m_router)
	{
        LOG_ERR("RegObj err");
		LOG_TRC("Exit CRouterExport::RegObj");
        return scope.Close(Undefined());
    }

    v8::String::Utf8Value arg(args[0]->ToString());
    std::string str = std::string(*arg);
    obj->m_router->RegObj( str.c_str(), 
                           str.length() );

	LOG_TRC("Exit CRouterExport::RegObj");
    return scope.Close(Undefined());
}

/*Handle<Value> CRouterExport::RegBalance(const v8::Arguments& args){
	LOG_TRC("Enter CRouterExport::RegBalance");
    HandleScope scope;

    if(args.Length() != 3)
	{
        LOG_ERR("RegBalance require 3 params");
		LOG_TRC("Exit CRouterExport::RegBalance");
        return scope.Close(Undefined());
    }

    CRouterExport* obj = ObjectWrap::Unwrap<CRouterExport>(args.This());
    if(!obj || !obj->m_router)
	{
        LOG_ERR("RegBalance err");
		LOG_TRC("Exit CRouterExport::RegBalance");
        return scope.Close(Undefined());
    }

    v8::String::Utf8Value arg(args[0]->ToString());
    std::string str = std::string(*arg);
    v8::String::Utf8Value arg1(args[1]->ToString());
    std::string str1 = std::string(*arg1);
    obj->m_router->RegBalance( str.c_str(), 
                               str.length(),
							   str1.c_str(),
							   str1.length(),
                               args[2]->Uint32Value() );

	LOG_TRC("Exit CRouterExport::RegBalance");
    return scope.Close(Undefined());
}*/

Handle<Value> CRouterExport::Unreg(const v8::Arguments& args){
	LOG_TRC("Enter CRouterExport::Unreg");
    HandleScope scope;

    if((args.Length() != 1) || !args[0]->IsString())
	{
        LOG_ERR("Unreg require 1 param");
		LOG_TRC("Exit CRouterExport::Unreg");	
        return scope.Close(Undefined());
    }

    CRouterExport* obj = ObjectWrap::Unwrap<CRouterExport>(args.This());
    if(!obj || !obj->m_router)
	{
        LOG_ERR("Unreg err");
		LOG_TRC("Exit CRouterExport::Unreg");	
        return scope.Close(Undefined());
    }

    v8::String::Utf8Value arg(args[0]->ToString());
    std::string str = std::string(*arg);
    obj->m_router->Unreg( str.c_str(), 
                          str.length() );

	LOG_TRC("Exit CRouterExport::Unreg");	
    return scope.Close(Undefined());
}

Router* CRouterExport::GetWrapped()
{
    return m_router;
}



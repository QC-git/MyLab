#ifndef ROUTER_PROCESSOR_EXPORT_H
#define ROUTER_PROCESSOR_EXPORT_H

#include <node.h>
#include "Interface.h"

class CRouterProcessorExport : public node::ObjectWrap, public clusterrouter::RouterProcessor{
public:
    static void Init(/*v8::Handle<v8::ObjectTemplate> exports*/);
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    clusterrouter::RouterProcessor* GetWrapped() { return this; };

private:
    CRouterProcessorExport();
    ~CRouterProcessorExport();

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> RegRouterProcessor(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor;
    v8::Persistent<v8::Object> m_jsRouterProcessor;
    //clusterrouter::RouterProcessor* m_routerProc;


    //实现RouterProcessor接口
    virtual void OnRoute(const void* identity, unsigned char idLen, void* data, unsigned short dLen);
    //接口共同实现
    void InterfaceComImpl(v8::Local<v8::String> key, const void* identity, unsigned char idLen, void* data, unsigned short dLen);
};

#endif

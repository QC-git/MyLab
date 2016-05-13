
#ifndef ROUTER_EXPORT_H
#define ROUTER_EXPORT_H

#include <node.h>
#include "Interface.h"

class CRouterExport : public node::ObjectWrap {
public:
    static void Init(/*v8::Handle<v8::ObjectTemplate> exports*/);
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    clusterrouter::Router* GetWrapped();

private:
    CRouterExport(const char* addr, clusterrouter::RouterProcessor* pRp);
    CRouterExport(clusterrouter::Service* local, clusterrouter::RouterProcessor* pRp);
    ~CRouterExport();

    static v8::Handle<v8::Value> Update(const v8::Arguments& args);
    static v8::Handle<v8::Value> RegObj(const v8::Arguments& args);
    //static v8::Handle<v8::Value> RegBalance(const v8::Arguments& args);
    static v8::Handle<v8::Value> Unreg(const v8::Arguments& args);
    static v8::Handle<v8::Value> Route(const v8::Arguments& args);
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor;
    clusterrouter::Router* m_router;
    //clusterrouter::Rpc* m_pRpc;
};

#endif


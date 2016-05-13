
#ifndef RPC_EXPORT_H
#define RPC_EXPORT_H

#include <node.h>
#include "Interface.h"

class CRpcExport : public node::ObjectWrap {
public:
    static void Init(/*v8::Handle<v8::ObjectTemplate> exports*/);
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    clusterrouter::Rpc* GetWrapped();

private:
    CRpcExport(clusterrouter::Router* router, clusterrouter::RpcProcessor* prc);
    ~CRpcExport();

    static v8::Handle<v8::Value> Request(const v8::Arguments& args);
    static v8::Handle<v8::Value> Response(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetTimeout(const v8::Arguments& args);

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor;
    clusterrouter::Rpc* m_pRpc;
};

#endif


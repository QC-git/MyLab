

#ifndef RPC_PROCESSOR_EXPORT_H
#define RPC_PROCESSOR_EXPORT_H

#include <node.h>
#include "Interface.h"

class CRpcProcessorExport : public node::ObjectWrap, public clusterrouter::RpcProcessor{
public:
    static void Init(/*v8::Handle<v8::ObjectTemplate> exports*/);
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    clusterrouter::RpcProcessor* GetWrapped() { return this; }

private:
    CRpcProcessorExport();
    ~CRpcProcessorExport();

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> RegRpcProcessor(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor;
    v8::Persistent<v8::Object> m_jsRpcProcessor;
    //实现RouterProcessor接口
    virtual void OnRequest(const void* identity, unsigned char idLen, const void* data, unsigned short dLen, const void* idFrom, unsigned char fromLen, unsigned int reqId);
    virtual void OnResponse(unsigned int requestId, clusterrouter::RpcErr err, const void* data, unsigned short dLen);
};

#endif

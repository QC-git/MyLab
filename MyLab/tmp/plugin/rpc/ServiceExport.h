#ifndef SERVICE_EXPORT_H
#define SERVICE_EXPORT_H

#include <node.h>
#include "Interface.h"

class CServiceExport : public node::ObjectWrap {
public:
    static void Init(/*v8::Handle<v8::ObjectTemplate> exports*/);
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
	clusterrouter::Service* GetWrapped();

private:
    CServiceExport(const clusterrouter::Env& env);
    ~CServiceExport();

    static v8::Handle<v8::Value> Start(const v8::Arguments& args);
    static v8::Handle<v8::Value> Stop(const v8::Arguments& args);
    static v8::Handle<v8::Value> AddAddr(const v8::Arguments& args);
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor; 
    clusterrouter::Service* m_service;
};

#endif


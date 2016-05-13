

#ifndef CPLUG_EXPORT_H_
#define CPLUG_EXPORT_H_

#include <node.h>
#ifdef WIN32
#include "WinImpl.h"
#else
#include "LinuxImpl.h"
#endif

class CLWrapper : public node::ObjectWrap {
public:
	static void Init(/*v8::Handle<v8::ObjectTemplate> exports*/);
	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);

private:
	CLWrapper();
	~CLWrapper();

	static v8::Handle<v8::Value> Create(const v8::Arguments& args);
	static v8::Handle<v8::Value> Destory(const v8::Arguments& args);
	static v8::Handle<v8::Value> Update(const v8::Arguments& args);
	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor; 
#ifdef WIN32
	CWinLoader* m_plugImpl;
#else
    CLinuxLoader* m_plugImpl;
#endif
};

#endif

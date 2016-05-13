
#ifndef PROTO_TRANS_H
#define PROTO_TRANS_H

#include <node.h>
#include "google/protobuf/message.h"
#include <boost/scoped_array.hpp>
#include <boost/scoped_ptr.hpp>
#include "ProtoDynamic.h"

class CProtocolConverter
{
public:
    CProtocolConverter();
    ~CProtocolConverter();

	static CProtocolConverter* Instance()
	{
		static CProtocolConverter ins;
		return &ins;
	}
public:
    clusterrouter::ProtoDynamic* GetProtoDynamic();

    v8::Local<v8::Object> PbMsgToJsObject(google::protobuf::Message* msg);

    boost::shared_ptr<google::protobuf::Message> JsObjectToPbMsg(const v8::Local<v8::Object>& obj, 
                                                               const std::string& name);

    v8::Local<v8::Object> DataToJsObject(const void* data, int dLen);

    int JsObjectToData(const v8::Local<v8::Object>& obj, 
                       const std::string& name, 
                       boost::scoped_array<char>& buf);

private:
    boost::scoped_ptr<clusterrouter::ProtoDynamic> m_ProtoDynamic;
	bool JsObjectToPbMsg_i(const v8::Local<v8::Object>& obj, google::protobuf::Message* msg);
	bool TransRepeatedField(google::protobuf::Message* msg, v8::Local<v8::Value>& val, const google::protobuf::FieldDescriptor* fd);
	bool TransField(google::protobuf::Message* msg, v8::Local<v8::Value>& val, const google::protobuf::FieldDescriptor* fd);
	bool DeTransField(google::protobuf::Message* msg, v8::Local<v8::Object>& Obj, const google::protobuf::FieldDescriptor* fd);
	bool DeTransRepeatedField(google::protobuf::Message* msg, v8::Local<v8::Object>& Obj, const google::protobuf::FieldDescriptor* fd);
};

#define g_protoConverter (CProtocolConverter::Instance())

#endif
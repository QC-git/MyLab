
#include "ProtoTrans.h"
#include "node.h"
#include <string>
#include <boost/shared_ptr.hpp>
#include "Log.h"
#include "ProtoDynamic.h"
#include "google/protobuf/descriptor.h"

using namespace google::protobuf;
using namespace v8;
using namespace clusterrouter;

CProtocolConverter::CProtocolConverter()
    : m_ProtoDynamic(new ProtoDynamic)
{

}

CProtocolConverter::~CProtocolConverter()
{

}

ProtoDynamic* CProtocolConverter::GetProtoDynamic()
{
    return m_ProtoDynamic.get();
}

class ITypeCheck
{
protected:
	virtual ~ITypeCheck() {}
public:
	virtual bool Check(FieldDescriptor::Type type) = 0;
};

class CNumberCheck : public ITypeCheck
{
public:
	bool Check(FieldDescriptor::Type type){
		if( type != FieldDescriptor::TYPE_DOUBLE &&
			type != FieldDescriptor::TYPE_FLOAT && 
			type != FieldDescriptor::TYPE_INT64 &&
			type != FieldDescriptor::TYPE_UINT64 &&
			type != FieldDescriptor::TYPE_INT32 &&
			type != FieldDescriptor::TYPE_FIXED64 &&
			type != FieldDescriptor::TYPE_FIXED32 &&
			type != FieldDescriptor::TYPE_UINT32 &&
			type != FieldDescriptor::TYPE_SFIXED32 &&
			type != FieldDescriptor::TYPE_SFIXED64 &&
			type != FieldDescriptor::TYPE_SINT32 &&
			type != FieldDescriptor::TYPE_SINT64 && 
			type != FieldDescriptor::TYPE_ENUM ){
				LOG_INF("CNumberCheck fail, the type is %d", static_cast<int>(type));
				return false;
		}

		return true;
	}
};

class CBoolCheck : public ITypeCheck
{
public:

	bool Check(FieldDescriptor::Type type){
		if( type != FieldDescriptor::TYPE_BOOL){
			LOG_INF("CBoolCheck fail, the type is %d", static_cast<int>(type));
			return false;
		}

		return true;
	}
};

class CStringCheck : public ITypeCheck
{
public:
	bool Check(FieldDescriptor::Type type){
		if( type != FieldDescriptor::TYPE_STRING){
			LOG_INF("CStringCheck fail, the type is %d", static_cast<int>(type));
			return false;
		}

		return true;
	}
};

class CObjectCheck : public ITypeCheck
{
public:
	bool Check(FieldDescriptor::Type type){
		if( type != FieldDescriptor::TYPE_MESSAGE){
			LOG_INF("CObjectCheck fail, the type is %d", static_cast<int>(type));
			return false;
		}

		return true;
	}
};

class CArrayCheck : public ITypeCheck
{
public:
	bool Check(FieldDescriptor::Type type){
		//暂时先认为都可以
		return true;
	}
};

class COtherCheck : public ITypeCheck
{
public:

	bool Check(FieldDescriptor::Type type){
		LOG_INF("COtherCheck fail, the type is %d", static_cast<int>(type));
		return false;
	}
};

class CTypeCheckFactory
{
public:
	static ITypeCheck* CreateTc(Local<Value> val)
	{
		if(val->IsBoolean()){
			return BookCheck;
		}else if(val->IsString()){
			return StringCheck;
		}else if(val->IsNumber()){
			return NumberCheck;
		}else if(val->IsArray()){
			return ArrayCheck;
		}else if(val->IsObject()){
			return ObjectCheck;
		}else{
			return OtherCheck;
		}
	}

	static CBoolCheck* BookCheck;
	static CStringCheck* StringCheck;
	static CNumberCheck* NumberCheck;
	static CObjectCheck* ObjectCheck;
	static CArrayCheck* ArrayCheck;
	static COtherCheck* OtherCheck;
};

CBoolCheck* CTypeCheckFactory::BookCheck = new CBoolCheck;
CStringCheck* CTypeCheckFactory::StringCheck = new CStringCheck;
CNumberCheck* CTypeCheckFactory::NumberCheck = new CNumberCheck;
CObjectCheck* CTypeCheckFactory::ObjectCheck = new CObjectCheck;
CArrayCheck* CTypeCheckFactory::ArrayCheck = new CArrayCheck;
COtherCheck* CTypeCheckFactory::OtherCheck = new COtherCheck;

Local<Object> CProtocolConverter::PbMsgToJsObject(google::protobuf::Message* msg)
{
	LOG_TRC("Enter CProtocolConverter::PbMsgToJsObject");
	Local<Object> Obj = Object::New();
	if(!msg)
	{
		LOG_ERR("the msg pointer is null");
		return Obj;
	}

	const Descriptor* desc = msg->GetDescriptor();
	if(!desc)
	{
		LOG_ERR("the desc pointer is null");
		return Obj;
	}

	//包名和方法名
	/*Local<String> methodKey = String::New("method");
	const char* pszMethod = msg->GetDescriptor()->full_name().c_str();
	Local<String> method = String::New(pszMethod);
	Obj->Set(methodKey, method);*/

	int nFdCount = desc->field_count();
	for (int i=0; i<nFdCount; i++)
	{
		const FieldDescriptor* fd = desc->field(i);
		if(fd->is_repeated())
		{
			DeTransRepeatedField(msg, Obj, fd);
		}
		else
		{
			DeTransField(msg, Obj, fd);
		}
	}

	LOG_TRC("Exit CProtocolConverter::PbMsgToJsObject");
	return Obj;
}

bool CProtocolConverter::DeTransField(google::protobuf::Message* msg, Local<Object>& Obj, const FieldDescriptor* fd)
{
	const Reflection* rf = msg->GetReflection();
	if(!rf)
	{
		LOG_ERR("the rf is null!");
		return false;
	}

	const std::string& name = fd->name();
	Local<String> key = String::New(name.c_str());
	LOG_DBG("the property name is %s", name.c_str());
	FieldDescriptor::Type type = fd->type();
	switch(type)
	{
	case FieldDescriptor::TYPE_DOUBLE://         = 1,   // double, exactly eight bytes on the wire.
		{
			double val = rf->GetDouble(*msg, fd);
			Local<Number> Num = Number::New(val);
			Obj->Set(key, Num);
			LOG_DBG("the TYPE_DOUBLE property value is %lf", val);
		}
		break;
	case FieldDescriptor::TYPE_FLOAT://          = 2,   // float, exactly four bytes on the wire.
		{
			float val = rf->GetFloat(*msg, fd);
			double d = static_cast<double>(val);
			Local<Number> Num = Number::New(d);
			Obj->Set(key, Num);
			LOG_DBG("the TYPE_FLOAT property value is %f", val);
		}
		break;
	case FieldDescriptor::TYPE_BOOL://           = 8,   // bool, varint on the wire.
		{
			bool val = rf->GetBool(*msg, fd);
			Handle<Boolean> b = Boolean::New(val);
			Obj->Set(key, b);
			LOG_DBG("the TYPE_BOOL property value is %d", static_cast<int>(val));
		}
		break;
	case FieldDescriptor::TYPE_STRING://         = 9,   // UTF-8 text.
		{
			string val = rf->GetString(*msg, fd);
			Local<String> str = String::New(val.c_str());
			Obj->Set(key, str);
			LOG_DBG("the TYPE_STRING property value is %s", val.c_str());
		}
		break;
	case FieldDescriptor::TYPE_MESSAGE://        = 11,  // Length-delimited message.
		{
			google::protobuf::Message* MutableMsg = rf->MutableMessage(msg, fd);
			Local<Object> MutableObj = PbMsgToJsObject(MutableMsg);
			Obj->Set(key, MutableObj);
			LOG_DBG("the TYPE_MESSAGE property name is %s", fd->name().c_str());
		}
		break;
	case FieldDescriptor::TYPE_UINT32://         = 13,  // uint32, varint on the wire
	case FieldDescriptor::TYPE_FIXED32://        = 7,   // uint32, exactly four bytes on the wire.
		{
			uint32 val = rf->GetUInt32(*msg, fd);
			double dVal = static_cast<double>(val);
			Local<Number> Num = Number::New(dVal);
			Obj->Set(key, Num);
			LOG_DBG("the UINT32 property value is %u", val);
		}
		break;
	case FieldDescriptor::TYPE_UINT64://         = 4,   // uint64, varint on the wire.
	case FieldDescriptor::TYPE_FIXED64://        = 6,   // uint64, exactly eight bytes on the wire.
		{
			uint64 val = rf->GetUInt64(*msg, fd);
			double dVal = static_cast<double>(val);
			Local<Number> Num = Number::New(dVal);
			Obj->Set(key, Num);
			LOG_DBG("the UINT64 property value is %lu", val);
		}
		break;
	case FieldDescriptor::TYPE_SFIXED32://       = 15,  // int32, exactly four bytes on the wire
	case FieldDescriptor::TYPE_SINT32://         = 17,  // int32, ZigZag-encoded varint on the wire
	case FieldDescriptor::TYPE_INT32://          = 5,   // int32, varint on the wire.  Negative numbers
		{
			int32 val = rf->GetInt32(*msg, fd);
			double dVal = static_cast<double>(val);
			Local<Number> Num = Number::New(dVal);
			Obj->Set(key, Num);
			LOG_DBG("the INT32 property value is %d", val);
		}
		break;
	case FieldDescriptor::TYPE_SFIXED64://       = 16,  // int64, exactly eight bytes on the wire
	case FieldDescriptor::TYPE_SINT64://         = 18,  // int64, ZigZag-encoded varint on the wire
	case FieldDescriptor::TYPE_INT64://          = 3,   // int64, varint on the wire.  Negative numbers
		{
			int64 val = rf->GetInt64(*msg, fd);
			double dVal = static_cast<double>(val);
			Local<Number> Num = Number::New(dVal);
			Obj->Set(key, Num);
			LOG_DBG("the INT64 property value is %ld", val);
		}
		break;
		//case FieldDescriptor::Type::TYPE_BYTES://          = 12,  // Arbitrary byte array.
		//    {
		//        float val = rf->GetBytes(*msg, fd);
		//    }
		//    break;
		//case FieldDescriptor::Type::TYPE_GROUP://          = 10,  // Tag-delimited message.  Deprecated.
		//    {
		//        float val = rf->GetGroup(*msg, fd);
		//    }
		//    break;
		//case FieldDescriptor::TYPE_ENUM://           = 14,  // Enum, varint on the wire
		//	{
		//		const EnumValueDescriptor* val = rf->GetEnum(*msg, fd);
		//		Local<Number> Num = Number::New(val->number());
		//		Obj->Set(key, Num);
		//	}
		//	break;
	default:
		{
			LOG_ERR("the type %d is not support", static_cast<int>(type));
		}
		break;      
	}

	return true;
}

bool CProtocolConverter::DeTransRepeatedField(google::protobuf::Message* msg, Local<Object>& Obj, const FieldDescriptor* fd)
{
	const Reflection* rf = msg->GetReflection();
	if(!rf)
	{
		LOG_ERR("the rf is null!");
		return false;
	}

	Local<Array> ar = Array::New();
	const std::string& name = fd->name();
	Local<String> key = String::New(name.c_str());
	LOG_DBG("the property name is %s", name.c_str());
	FieldDescriptor::Type type = fd->type();
	for(int i=0; i<rf->FieldSize(*msg, fd); i++)
	{
		switch(type)
		{
		case FieldDescriptor::TYPE_DOUBLE://         = 1,   // double, exactly eight bytes on the wire.
			{
				double val = rf->GetRepeatedDouble(*msg, fd, i);
				Local<Number> Num = Number::New(val);
				ar->Set(i, Num);
				LOG_DBG("the TYPE_DOUBLE property value is %lf", val);
			}
			break;
		case FieldDescriptor::TYPE_FLOAT://          = 2,   // float, exactly four bytes on the wire.
			{
				float val = rf->GetRepeatedFloat(*msg, fd, i);
				double d = static_cast<double>(val);
				Local<Number> Num = Number::New(d);
				ar->Set(i, Num);
				LOG_DBG("the TYPE_FLOAT property value is %f", val);
			}
			break;
		case FieldDescriptor::TYPE_BOOL://           = 8,   // bool, varint on the wire.
			{
				bool val = rf->GetRepeatedBool(*msg, fd, i);
				Handle<Boolean> b = Boolean::New(val);
				ar->Set(i, b);
				LOG_DBG("the TYPE_BOOL property value is %d", static_cast<int>(val));
			}
			break;
		case FieldDescriptor::TYPE_STRING://         = 9,   // UTF-8 text.
			{
				string val = rf->GetRepeatedString(*msg, fd, i);
				Local<String> str = String::New(val.c_str());
				ar->Set(i, str);
				LOG_DBG("the TYPE_STRING property value is %s", val.c_str());
			}
			break;
		case FieldDescriptor::TYPE_MESSAGE://        = 11,  // Length-delimited message.
			{
				google::protobuf::Message* MutableMsg = rf->MutableRepeatedMessage(msg, fd, i);
				Local<Object> MutableObj = PbMsgToJsObject(MutableMsg);
				ar->Set(i, MutableObj);
				LOG_DBG("the TYPE_MESSAGE property name is %s", fd->name().c_str());
			}
			break;
		case FieldDescriptor::TYPE_UINT32://         = 13,  // uint32, varint on the wire
		case FieldDescriptor::TYPE_FIXED32://        = 7,   // uint32, exactly four bytes on the wire.
			{
				uint32 val = rf->GetRepeatedUInt32(*msg, fd, i);
				double dVal = static_cast<double>(val);
				Local<Number> Num = Number::New(dVal);
				ar->Set(i, Num);
				LOG_DBG("the UINT32 property value is %u", val);
			}
			break;
		case FieldDescriptor::TYPE_UINT64://         = 4,   // uint64, varint on the wire.
		case FieldDescriptor::TYPE_FIXED64://        = 6,   // uint64, exactly eight bytes on the wire.
			{
				uint64 val = rf->GetRepeatedUInt64(*msg, fd, i);
				double dVal = static_cast<double>(val);
				Local<Number> Num = Number::New(dVal);
				ar->Set(i, Num);
				LOG_DBG("the UINT64 property value is %lu", val);
			}
			break;
		case FieldDescriptor::TYPE_SFIXED32://       = 15,  // int32, exactly four bytes on the wire
		case FieldDescriptor::TYPE_SINT32://         = 17,  // int32, ZigZag-encoded varint on the wire
		case FieldDescriptor::TYPE_INT32://          = 5,   // int32, varint on the wire.  Negative numbers
			{
				int32 val = rf->GetRepeatedInt32(*msg, fd, i);
				double dVal = static_cast<double>(val);
				Local<Number> Num = Number::New(dVal);
				ar->Set(i, Num);
				LOG_DBG("the INT32 property value is %d", val);
			}
			break;
		case FieldDescriptor::TYPE_SFIXED64://       = 16,  // int64, exactly eight bytes on the wire
		case FieldDescriptor::TYPE_SINT64://         = 18,  // int64, ZigZag-encoded varint on the wire
		case FieldDescriptor::TYPE_INT64://          = 3,   // int64, varint on the wire.  Negative numbers
			{
				int64 val = rf->GetRepeatedInt64(*msg, fd, i);
				double dVal = static_cast<double>(val);
				Local<Number> Num = Number::New(dVal);
				ar->Set(i, Num);
				LOG_DBG("the INT64 property value is %ld", val);
			}
			break;
			//case FieldDescriptor::Type::TYPE_BYTES://          = 12,  // Arbitrary byte array.
			//    {
			//        float val = rf->GetBytes(*msg, fd);
			//    }
			//    break;
			//case FieldDescriptor::Type::TYPE_GROUP://          = 10,  // Tag-delimited message.  Deprecated.
			//    {
			//        float val = rf->GetGroup(*msg, fd);
			//    }
			//    break;
			//case FieldDescriptor::TYPE_ENUM://           = 14,  // Enum, varint on the wire
			//	{
			//		const EnumValueDescriptor* val = rf->GetEnum(*msg, fd);
			//		Local<Number> Num = Number::New(val->number());
			//		Obj->Set(key, Num);
			//	}
			//	break;
		default:
			{
				LOG_ERR("the type %d is not support", static_cast<int>(type));
			}
			break;      
		}
	}

	Obj->Set(key, ar);
	return true;
}

boost::shared_ptr<google::protobuf::Message> CProtocolConverter::JsObjectToPbMsg(const Local<Object>& obj, const std::string& name)
{
	LOG_TRC("Enter CProtocolConverter::JsObjectToPbMsg");
	boost::shared_ptr<google::protobuf::Message> msg = GetProtoDynamic()->CreateMessage(name.c_str());
	if(!msg)
	{
		LOG_ERR("the google protobuf msg[%s] create fail, may be the problem is cause by proto msg file", name.c_str());
		return msg;
	}

	this->JsObjectToPbMsg_i(obj, msg.get());
	LOG_TRC("Exit CProtocolConverter::JsObjectToPbMsg");
	return msg;
}

bool CProtocolConverter::JsObjectToPbMsg_i(const Local<Object>& obj, google::protobuf::Message* msg)
{
	LOG_TRC("Enter CProtocolConverter::JsObjectToPbMsg_i");
	if(!msg)
	{
		LOG_ERR("the msg pointer is null");
		return false;
	}

	const Descriptor* desc = msg->GetDescriptor();
	if(!desc)
	{
		LOG_ERR("the desc pointer is null");
		return false;
	}

	int fdCount = desc->field_count();
	for (int i=0; i<fdCount; ++i)
	{
		const FieldDescriptor* fd = desc->field(i);
		const std::string& name = fd->name();
		LOG_DBG("the property name is %s", name.c_str());
		Local<Value> val;
		if(obj->IsArray())
		{
			val = obj->Get(i);
		}
		else
		{
			Local<String> key = String::New(name.c_str());
			if(!obj->HasOwnProperty(key))
			{
                if (!fd->is_optional() && !fd->is_repeated())
				    LOG_WRN("obj no proto msg(%s) specified property and the property is %s", desc->full_name().c_str(), name.c_str());
				continue;
			}

			val = obj->Get(key);
		}

		bool bRet;
		if(fd->is_repeated())
			bRet = TransRepeatedField(msg, val, fd);
		else
			bRet = TransField(msg, val, fd);

		if(!bRet)
			return false;
	}

	LOG_TRC("Exit CProtocolConverter::JsObjectToPbMsg_i");
	return true;
}

bool CProtocolConverter::TransRepeatedField(google::protobuf::Message* msg, Local<Value>& pro, const FieldDescriptor* fd)
{
	if(!pro->IsArray())
	{
		LOG_ERR("repeated field must map a array type![%s]", fd->full_name().c_str());
		return false;
	}

	const Reflection* rf = msg->GetReflection();
	if(!rf)
	{
		LOG_ERR("the rf is null!");
		return false;
	}

	FieldDescriptor::Type type = fd->type();
	ITypeCheck* pTc = CTypeCheckFactory::CreateTc(pro);
	if(!pTc->Check(type)){
        LOG_ERR("type check fail[%s]", fd->full_name().c_str());
		return false;
	}

	Local<Array> ar = Local<Array>::Cast(pro);
	for(uint32_t i=0; i<ar->Length(); i++)
	{
		Local<Value> val = ar->Get(i);
		switch(type)
		{
		case FieldDescriptor::TYPE_DOUBLE://         = 1,   // double, exactly eight bytes on the wire.
			{
				double d = val->ToNumber()->Value();
				rf->AddDouble(msg, fd, d);
				LOG_DBG("the TYPE_DOUBLE property value is %d", d);
			}
			break;
		case FieldDescriptor::TYPE_FLOAT://          = 2,   // float, exactly four bytes on the wire.
			{
				double d = val->ToNumber()->Value();
				float f = static_cast<float>(d);
				rf->AddFloat(msg, fd, f);
				LOG_DBG("the TYPE_FLOAT property value is %f", f);
			}
			break;
		case FieldDescriptor::TYPE_BOOL://           = 8,   // bool, varint on the wire.
			{
				bool b = val->ToBoolean()->Value();
				rf->AddBool(msg, fd, b);
				LOG_DBG("the TYPE_BOOL property value is %d", static_cast<int>(b));
			}
			break;
		case FieldDescriptor::TYPE_STRING://         = 9,   // UTF-8 text.
			{
				String::Utf8Value str(val->ToString());
				std::string s = std::string(*str);
				rf->AddString(msg, fd, s);
				LOG_DBG("the TYPE_STRING property value is %s", s.c_str());
			}
			break;
		case FieldDescriptor::TYPE_MESSAGE://        = 11,  // Length-delimited message.
			{
				Local<Object> MutableObj = val->ToObject();
				google::protobuf::Message* MutableMsg = rf->AddMessage(msg, fd);
				JsObjectToPbMsg_i(MutableObj, MutableMsg);
				LOG_DBG("the TYPE_MESSAGE property value is %s", fd->name().c_str());
			}
			break;
			//case FieldDescriptor::TYPE_ENUM://           = 14,  // Enum, varint on the wire
			//	{
			//		double d = val->ToNumber()->Value();
			//		int i = static_cast<int>(d);
			//		rf->SetEnum(msg, fd, i); 
			//		LOG_DEBUG("CProtocolConverter::JsObjectToPbMsg_i the number property is %d", d);
			//	}
			//	break;
		case FieldDescriptor::TYPE_UINT32://         = 13,  // uint32, varint on the wire
		case FieldDescriptor::TYPE_FIXED32://        = 7,   // uint32, exactly four bytes on the wire.
			{
				double d = val->ToNumber()->Value();
				uint32 ui = static_cast<uint32>(d);
				rf->AddUInt32(msg, fd, ui);
				LOG_DBG("the uint32 property value is %d", ui);
			}
			break;
		case FieldDescriptor::TYPE_UINT64://         = 4,   // uint64, varint on the wire.
		case FieldDescriptor::TYPE_FIXED64://        = 6,   // uint64, exactly eight bytes on the wire.
			{
				double d = val->ToNumber()->Value();
				uint64 ui64 = static_cast<uint64>(d);
				rf->AddUInt64(msg, fd, ui64);
				LOG_DBG("the uin64 property value is %d", d);
			}
			break;
		case FieldDescriptor::TYPE_SFIXED32://       = 15,  // int32, exactly four bytes on the wire
		case FieldDescriptor::TYPE_SINT32://         = 17,  // int32, ZigZag-encoded varint on the wire
		case FieldDescriptor::TYPE_INT32://          = 5,   // int32, varint on the wire.  Negative numbers
			{
				double d = val->ToNumber()->Value();
				int32 i32 = static_cast<int32>(d);
				rf->AddInt32(msg, fd, i32);
				LOG_DBG("the sint32 property value is %d", i32);
			}
			break;
		case FieldDescriptor::TYPE_SFIXED64://       = 16,  // int64, exactly eight bytes on the wire
		case FieldDescriptor::TYPE_SINT64://         = 18,  // int64, ZigZag-encoded varint on the wire
		case FieldDescriptor::TYPE_INT64://          = 3,   // int64, varint on the wire.  Negative numbers
			{
				double d = val->ToNumber()->Value();
				int64 si64 = static_cast<int64>(d);
				rf->AddInt64(msg, fd, si64);
				LOG_DBG("the sint64 property value is %ld", si64);
			}
			break;
			//case FieldDescriptor::Type::TYPE_GROUP://          = 10,  // Tag-delimited message.  Deprecated.
			//    {
			//        float val = rf->GetGroup(*msg, fd);
			//    }
			//    break;
			//case FieldDescriptor::Type::TYPE_BYTES://          = 12,  // Arbitrary byte array.
			//    {
			//        float val = rf->GetBytes(*msg, fd);
			//    }
			//    break;
		default:
			{
				LOG_ERR("the type %d is not support", static_cast<int>(type));
			}
			break;      
		}
	}

	return true;
}

bool CProtocolConverter::TransField(google::protobuf::Message* msg, Local<Value>& val, const FieldDescriptor* fd)
{
	const Reflection* rf = msg->GetReflection();
	if(!rf)
	{
		LOG_ERR("the rf is null!");
		return false;
	}

	FieldDescriptor::Type type = fd->type();
	ITypeCheck* pTc = CTypeCheckFactory::CreateTc(val);
	if(!pTc->Check(type)){
		LOG_ERR("type check fail[%s]", fd->full_name().c_str());
		return false;
	}

	switch(type)
	{
	case FieldDescriptor::TYPE_DOUBLE://         = 1,   // double, exactly eight bytes on the wire.
		{
			double d = val->ToNumber()->Value();
			rf->SetDouble(msg, fd, d);
			LOG_DBG("the TYPE_DOUBLE property value is %d", d);
		}
		break;
	case FieldDescriptor::TYPE_FLOAT://          = 2,   // float, exactly four bytes on the wire.
		{
			double d = val->ToNumber()->Value();
			float f = static_cast<float>(d);
			rf->SetFloat(msg, fd, f);
			LOG_DBG("the TYPE_FLOAT property value is %f", f);
		}
		break;
	case FieldDescriptor::TYPE_BOOL://           = 8,   // bool, varint on the wire.
		{
			bool b = val->ToBoolean()->Value();
			rf->SetBool(msg, fd, b);
			LOG_DBG("the TYPE_BOOL property value is %d", static_cast<int>(b));
		}
		break;
	case FieldDescriptor::TYPE_STRING://         = 9,   // UTF-8 text.
		{
			String::Utf8Value str(val->ToString());
			std::string s = std::string(*str);
			rf->SetString(msg, fd, s);
			LOG_DBG("the TYPE_STRING property value is %s", s.c_str());
		}
		break;
	case FieldDescriptor::TYPE_MESSAGE://        = 11,  // Length-delimited message.
		{
			Local<Object> MutableObj = val->ToObject();
			google::protobuf::Message* MutableMsg = rf->MutableMessage(msg, fd);
			JsObjectToPbMsg_i(MutableObj, MutableMsg);
			LOG_DBG("the TYPE_MESSAGE property value is %s", fd->name().c_str());
		}
		break;
		//case FieldDescriptor::TYPE_ENUM://           = 14,  // Enum, varint on the wire
		//	{
		//		double d = val->ToNumber()->Value();
		//		int i = static_cast<int>(d);
		//		rf->SetEnum(msg, fd, i); 
		//		LOG_DEBUG("CProtocolConverter::JsObjectToPbMsg_i the number property is %d", d);
		//	}
		//	break;
	case FieldDescriptor::TYPE_UINT32://         = 13,  // uint32, varint on the wire
	case FieldDescriptor::TYPE_FIXED32://        = 7,   // uint32, exactly four bytes on the wire.
		{
			double d = val->ToNumber()->Value();
			uint32 ui = static_cast<uint32>(d);
			rf->SetUInt32(msg, fd, ui);
			LOG_DBG("the uint32 property value is %d", ui);
		}
		break;
	case FieldDescriptor::TYPE_UINT64://         = 4,   // uint64, varint on the wire.
	case FieldDescriptor::TYPE_FIXED64://        = 6,   // uint64, exactly eight bytes on the wire.
		{
			double d = val->ToNumber()->Value();
			uint64 ui64 = static_cast<uint64>(d);
			rf->SetUInt64(msg, fd, ui64);
			LOG_DBG("the uin64 property value is %d", d);
		}
		break;
	case FieldDescriptor::TYPE_SFIXED32://       = 15,  // int32, exactly four bytes on the wire
	case FieldDescriptor::TYPE_SINT32://         = 17,  // int32, ZigZag-encoded varint on the wire
	case FieldDescriptor::TYPE_INT32://          = 5,   // int32, varint on the wire.  Negative numbers
		{
			double d = val->ToNumber()->Value();
			int32 i32 = static_cast<int32>(d);
			rf->SetInt32(msg, fd, i32);
			LOG_DBG("the sint32 property value is %d", i32);
		}
		break;
	case FieldDescriptor::TYPE_SFIXED64://       = 16,  // int64, exactly eight bytes on the wire
	case FieldDescriptor::TYPE_SINT64://         = 18,  // int64, ZigZag-encoded varint on the wire
	case FieldDescriptor::TYPE_INT64://          = 3,   // int64, varint on the wire.  Negative numbers
		{
			double d = val->ToNumber()->Value();
			int64 si64 = static_cast<int64>(d);
			rf->SetInt64(msg, fd, si64);
			LOG_DBG("the sint64 property value is %ld", si64);
		}
		break;
		//case FieldDescriptor::Type::TYPE_GROUP://          = 10,  // Tag-delimited message.  Deprecated.
		//    {
		//        float val = rf->GetGroup(*msg, fd);
		//    }
		//    break;
		//case FieldDescriptor::Type::TYPE_BYTES://          = 12,  // Arbitrary byte array.
		//    {
		//        float val = rf->GetBytes(*msg, fd);
		//    }
		//    break;
	default:
		{
			LOG_ERR("the type %d is not support", static_cast<int>(type));
		}
		break;      
	}

	return true;
}

Local<Object> CProtocolConverter::DataToJsObject(const void* data, int dLen)
{
    LOG_TRC("Enter CProtocolConverter::DataToJsObject");
	if(NULL == data || dLen == 0)
	{
		LOG_ERR("the data is null");
		return Object::New();
	}

    const char* pc = reinterpret_cast<const char*>(data);
    const uint16_t* ps = reinterpret_cast<const uint16_t*>(data);
    uint16_t ns = *(ps+1);
    std::string name(pc+4, ns);
    LOG_DBG("the google proto msg name is %s\n", name.c_str());
    boost::shared_ptr<google::protobuf::Message> msg = GetProtoDynamic()->CreateMessage(name.c_str());
	if(!msg)
	{
        LOG_ERR("the google protobuf msg[%s] create fail, may be the problem is cause by proto msg file", name.c_str());
		return Object::New();
	}
    msg->ParseFromArray(pc+4+ns, dLen-4-ns);
	Local<Object> obj = PbMsgToJsObject(msg.get());

	//如果是发送，附上包名字
	const char* szName = msg->GetDescriptor()->full_name().c_str();
	if(NULL == strstr(szName, "Ack"))
	{
		Local<String> methodKey = String::New("method");
		Local<String> method = String::New(szName);
		obj->Set(methodKey, method);
	}
    LOG_TRC("Exit CProtocolConverter::DataToJsObject");
    return obj;
}

int CProtocolConverter::JsObjectToData(const Local<Object>& obj, const std::string& name, boost::scoped_array<char>& buf)
{
    LOG_TRC("Enter CProtocolConverter::JsObjectToData");
	boost::shared_ptr<google::protobuf::Message> pb = JsObjectToPbMsg(obj, name);
    if(!pb)
	{
        LOG_ERR("the pb is null");
        return 0;
    }

    LOG_DBG("msg name is %s", pb->GetDescriptor()->full_name().c_str());
    uint16_t ms = pb->ByteSize();
    uint16_t ns = (uint16_t)name.size();
    uint16_t as = 4+ns+ms;
    buf.reset(new char[as]);

    char* bf = buf.get();
    uint16_t* p = reinterpret_cast<uint16_t*>(bf);
    *p = as;
    *(p+1) = ns;
    memcpy(bf+4, name.c_str(), ns);
    if (!pb->SerializePartialToArray(bf+4+ns, ms))
    {
        LOG_ERR("proto serialize fail of %s", pb->GetDescriptor()->full_name().c_str());
    }
	LOG_TRC("Exit CProtocolConverter::JsObjectToData");
    return as;
}


// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test_person.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "test_person.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace test_proto_msg {

namespace {

const ::google::protobuf::Descriptor* Person_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Person_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_test_5fperson_2eproto() {
  protobuf_AddDesc_test_5fperson_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "test_person.proto");
  GOOGLE_CHECK(file != NULL);
  Person_descriptor_ = file->message_type(0);
  static const int Person_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, data1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, data2_),
  };
  Person_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Person_descriptor_,
      Person::default_instance_,
      Person_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Person, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Person));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_test_5fperson_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Person_descriptor_, &Person::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_test_5fperson_2eproto() {
  delete Person::default_instance_;
  delete Person_reflection_;
}

void protobuf_AddDesc_test_5fperson_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021test_person.proto\022\016test_proto_msg\"O\n\006P"
    "erson\022\n\n\002id\030\001 \002(\005\022\014\n\004name\030\002 \002(\t\022\r\n\005email"
    "\030\003 \001(\t\022\r\n\005data1\030\004 \002(\r\022\r\n\005data2\030\005 \002(\r", 116);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "test_person.proto", &protobuf_RegisterTypes);
  Person::default_instance_ = new Person();
  Person::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_test_5fperson_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_test_5fperson_2eproto {
  StaticDescriptorInitializer_test_5fperson_2eproto() {
    protobuf_AddDesc_test_5fperson_2eproto();
  }
} static_descriptor_initializer_test_5fperson_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Person::kIdFieldNumber;
const int Person::kNameFieldNumber;
const int Person::kEmailFieldNumber;
const int Person::kData1FieldNumber;
const int Person::kData2FieldNumber;
#endif  // !_MSC_VER

Person::Person()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:test_proto_msg.Person)
}

void Person::InitAsDefaultInstance() {
}

Person::Person(const Person& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:test_proto_msg.Person)
}

void Person::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  data1_ = 0u;
  data2_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:test_proto_msg.Person)
  SharedDtor();
}

void Person::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (this != default_instance_) {
  }
}

void Person::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Person::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Person_descriptor_;
}

const Person& Person::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_test_5fperson_2eproto();
  return *default_instance_;
}

Person* Person::default_instance_ = NULL;

Person* Person::New() const {
  return new Person;
}

void Person::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Person*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(id_, data1_);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
    data2_ = 0u;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Person::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:test_proto_msg.Person)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // required string name = 2;
      case 2: {
        if (tag == 18) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_email;
        break;
      }

      // optional string email = 3;
      case 3: {
        if (tag == 26) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email().data(), this->email().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_data1;
        break;
      }

      // required uint32 data1 = 4;
      case 4: {
        if (tag == 32) {
         parse_data1:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &data1_)));
          set_has_data1();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_data2;
        break;
      }

      // required uint32 data2 = 5;
      case 5: {
        if (tag == 40) {
         parse_data2:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &data2_)));
          set_has_data2();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:test_proto_msg.Person)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:test_proto_msg.Person)
  return false;
#undef DO_
}

void Person::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:test_proto_msg.Person)
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // optional string email = 3;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->email(), output);
  }

  // required uint32 data1 = 4;
  if (has_data1()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->data1(), output);
  }

  // required uint32 data2 = 5;
  if (has_data2()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->data2(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:test_proto_msg.Person)
}

::google::protobuf::uint8* Person::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:test_proto_msg.Person)
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // optional string email = 3;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->email(), target);
  }

  // required uint32 data1 = 4;
  if (has_data1()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->data1(), target);
  }

  // required uint32 data2 = 5;
  if (has_data2()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->data2(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:test_proto_msg.Person)
  return target;
}

int Person::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional string email = 3;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

    // required uint32 data1 = 4;
    if (has_data1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->data1());
    }

    // required uint32 data2 = 5;
    if (has_data2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->data2());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Person::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Person* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Person*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Person::MergeFrom(const Person& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
    if (from.has_data1()) {
      set_data1(from.data1());
    }
    if (from.has_data2()) {
      set_data2(from.data2());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Person::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Person::CopyFrom(const Person& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001b) != 0x0000001b) return false;

  return true;
}

void Person::Swap(Person* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(email_, other->email_);
    std::swap(data1_, other->data1_);
    std::swap(data2_, other->data2_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Person::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Person_descriptor_;
  metadata.reflection = Person_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace test_proto_msg

// @@protoc_insertion_point(global_scope)

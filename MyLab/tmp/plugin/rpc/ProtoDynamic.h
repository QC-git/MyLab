#ifndef __PROTO_DYNAMIC_H__
#define __PROTO_DYNAMIC_H__

#include "google/protobuf/compiler/importer.h"
#include "google/protobuf/dynamic_message.h"
#include "Log.h"
#include "boost/filesystem.hpp"
#include "boost/shared_ptr.hpp"

namespace clusterrouter
{

class ProtoDynamic : public google::protobuf::compiler::MultiFileErrorCollector
{
    typedef std::string string;
    google::protobuf::compiler::DiskSourceTree m_tree;
    google::protobuf::compiler::Importer m_importer;
    google::protobuf::DynamicMessageFactory m_fact;

    ProtoDynamic* This() { return this; }

    void AddError(const string& filename, int line, int column, const string& message)
    {
        LOG_ERR(message.c_str());
    }
public:
    ProtoDynamic()
        : m_importer(&m_tree, This())
        , m_fact(m_importer.pool())
    {
        const char* protopath = "./proto";
        m_tree.MapPath("", protopath);
        //m_fact.SetDelegateToGeneratedFactory(true);
        namespace fs = boost::filesystem;
        fs::path fullpath(protopath);
        if(!fs::exists(fullpath))
            return;
        fs::directory_iterator end_iter;
        for(fs::directory_iterator iter(fullpath);iter!=end_iter;iter++)
        {
            if(fs::is_regular(*iter) && fs::extension(iter->path())==".proto")
            {
                m_importer.Import(iter->path().leaf().string());
            }
        }
        
    }

    boost::shared_ptr<google::protobuf::Message> CreateMessage(const std::string& type_name)
    {
        boost::shared_ptr<google::protobuf::Message> message;
        const google::protobuf::Descriptor* descriptor = m_importer.pool()->FindMessageTypeByName(type_name);
        //google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
        if (descriptor)
        {
            const google::protobuf::Message* prototype = m_fact.GetPrototype(descriptor);
            //google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
            if (prototype)
            {
                message.reset(prototype->New());
            }
        }
        return message;
    }

    const google::protobuf::DescriptorPool& Pool() { return *m_importer.pool(); }
    google::protobuf::MessageFactory& Factory() { return m_fact; }
};

} // clusterrouter

#endif // __PROTO_DYNAMIC_H__
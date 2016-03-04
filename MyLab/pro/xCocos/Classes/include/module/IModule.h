/**
* Created by tweyseo on 15-10-28.
*/

#pragma once

namespace insroot
{
    class IModule
    {
    public:
        virtual ~IModule() {};
        virtual bool Init() = 0;
        virtual bool Fini() = 0;
        virtual void OnTimer(uint32_t curTime) = 0;
        virtual int32_t OnRcvMsg(uint32_t idActor, const char* buffer, uint16_t len, bool inner = false) = 0;
        virtual uint16_t Release() = 0;

        virtual void ListenEvent(uint32_t event)    {}
        virtual bool EventTriggerAble(uint32_t event)   { return false; }
        virtual void TriggerEvent_Disconnect(uint32_t sckId)  {}
    };
};
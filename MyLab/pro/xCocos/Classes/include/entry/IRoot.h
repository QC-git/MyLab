/**
* Created by tweyseo on 15-10-28.
*/

#pragma once


namespace insroot
{
    class IModule;

    class IRoot
    {
    public:
        virtual uint32_t GetID() const = 0;
        virtual void RegisterMsgType(uint32_t msgType, IModule* pModule) = 0;
        virtual uint16_t Release() = 0;
    };
};

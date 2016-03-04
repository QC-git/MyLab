/**
* Created by tweyseo on 15-10-28.
*/

#pragma once


namespace insroot
{
    class IinsGame
    {
    public:
        virtual uint16_t Release() = 0;
        virtual uint32_t GetID() const = 0;
        virtual void OnTimer(long long) = 0;
        virtual int32_t OnMsg(uint32_t uid, const char* msg, uint16_t len) = 0;
        virtual int32_t ProcessMsg(uint32_t uid, const char* msg, uint16_t len, bool inner = false) = 0;
        virtual bool SendToInstanceSrv(const char* pszInfo, uint32_t scidUser, uint32_t uInsSrv) = 0;
        virtual bool SendToMainSrv(uint32_t scid, const char* lpBuf) = 0;
        virtual bool SendLPMsg(const char* lpBuf, uint16_t size) = 0;
    };
};
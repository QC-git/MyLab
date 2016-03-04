/**
* Created by tweyseo on 15-10-28.
*/

#pragma once


namespace insroot
{
    class ISender
    {
    public:
        virtual void SendMsg(uint32_t sckId, const char* msg) = 0;
        virtual void InsMulticastMsg(const char* msg, uint16_t size, const uint32_t* sckIdList, uint16_t count) = 0;
        virtual bool SendToInstanceSrv(const char* pszInfo, uint32_t scidUser, uint32_t uInsSrv) = 0;
        virtual bool SendToMainSrv(uint32_t scid, const char* lpBuf) = 0;
        virtual bool SendLPMsg(const char* lpBuf, uint16_t size) = 0;
    };
};
#pragma once

#ifndef PACKED
#ifndef WIN32
#define PACKED __attribute__((packed))
#else
#define PACKED
#endif
#endif

const int IP_LEN = 256;
const int PATH_LEN = 256;
const int WEEK_HERO_COUNT = 17;
const int UID_MAX_LEN = 50;
const int NAME_MAX_LEN = 15;

struct LPInfo {
  char ip[16];
  unsigned short port;
};

struct ServerInfo {
  char EducomIp[IP_LEN];
  char TietongIp[IP_LEN];
  char NetcomIp[IP_LEN];
  char TelecomIp[IP_LEN];

  unsigned short ServicePort;
  unsigned short UdpServicePort;
};

struct LPAdditionInfo{
  char uid[UID_MAX_LEN];
  char usrname[NAME_MAX_LEN];
  unsigned int WeekFreeHero[WEEK_HERO_COUNT];
};

enum BSMode
{
  STANDALONE,
  EMBEDDED
};

class ILog{
public:
  virtual void Trace(const char*) = 0;
  virtual void Debug(const char*) = 0;
  virtual void Info(const char*) = 0;
  virtual void Warn(const char*) = 0;
  virtual void Error(const char*) = 0;
  virtual void Fatal(const char*) = 0;
};

struct ConfigData {
  BSMode bsMode;
  LPInfo lpInfo;
  ServerInfo serverInfo;
  LPAdditionInfo lpAdditionInfo;
  char resDir[PATH_LEN+2];
  ILog* logger;
};

#pragma pack(push, 1)
enum bs_Camp {
  bs_Camp_A = 0,
  bs_Camp_B,
  bs_Camp_Judge,
};

struct bs_Player {
  unsigned int accountId;
  bs_Camp camp;
  bool robot;
  short score;
  short averagerOther;
  short vipLevel;
  unsigned int expandAttr;
  unsigned int uinId;
  char szNickName[16];
}PACKED;
#pragma pack(pop)

struct BSClientInfo{
  char ip[IP_LEN];
  unsigned short port;
  unsigned int client_id;
  unsigned int WeekFreeHero[WEEK_HERO_COUNT];
};

class PoFakeClientHandler;

class IPoFakeClientImp
{
public:
  virtual ~IPoFakeClientImp() {}
public:
  virtual bool Init(PoFakeClientHandler* handler) = 0;
  virtual void Request(const char* route, const char* req, int routeId, int timeout) = 0;
};

class PoFakeClientHandler
{
public:
  virtual void OnResponse(int ret, int routeId, const char* resp) = 0;
  virtual void OnServerUserNotify(const char* route, const char* notify) = 0;
};

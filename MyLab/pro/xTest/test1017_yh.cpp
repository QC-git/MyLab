
#include "xTestService.hpp"
#include "xTest.h"

#include "test_boost/sl_asio/sl_Interface.h"
//#include "YH/net.h"

//#pragma comment(lib, "net.lib")   // 编译成动态库出现无法链接问题

namespace space_test_yh {

	struct Head {
		unsigned short size;
		unsigned short type;
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
	};

	struct MsgBSCreateGame {
		unsigned int lpRequestId;  // roomId
		unsigned int heroMode;
		unsigned int gameConf;
		unsigned short mapId;
		bool deny;
		unsigned short gameMode;
		unsigned int freeHeroWeek[17];
		unsigned int bossDaily[6];
		unsigned short teamAmount;
		unsigned int captainA;
		unsigned int captainB;
		unsigned short playerCount;
		bs_Player player[10];
	};
	struct MsgBSPlayerInfo {
		struct PlayerInfo {
			int title;
			int rank;
			unsigned int nameplateBadge;
			unsigned int nameplateTitle;
			unsigned int nameplateBaseborad;
			unsigned int vipLevel;
			int platformLevel;
			unsigned int talent1;
			unsigned int talent2;
			unsigned int talent3;
			unsigned int talent4;
			bool isBlueVip;
			bool isBlueYearVip;
			int blueVipLevel;
			int isSuperBlueVip;
			int ditch;
			char lgnShortName[10];
			char clanShortName[10];
			unsigned int PVEFeat;
			unsigned int LegionId;
		};

		struct PlayerSkin {
			int skin;
			bool checked;
		};

		unsigned int idAccount;
		PlayerInfo Data;
		unsigned short usAmmount;
		unsigned short usheroAmount;
		unsigned short usHeroFeatAmount;
		unsigned int heros[100];
		unsigned char heroFeats[100];
		PlayerSkin szSkinData[1];
	};

	struct MsgBSUpdateRoleHeroSkin
	{
		struct HeroInfo
		{
			unsigned int idAccount;
			unsigned int lookface;
			unsigned int skin;
		};

		unsigned short usAmount;
		HeroInfo szHeroInfo[1];
	};


#pragma pack(pop)

	sl_asio::TcpGuestPtr spClient;

	class CPipe : public sl_asio::IMessagePipe
	{
	public:
		CPipe()
		{

		}
		~CPipe()
		{

		}

		template<class _T>
		void InitMsgHead(_T& sMsg, unsigned short uType)
		{
			unsigned short uSize = sizeof(sMsg);
			memset(&sMsg, 0, uSize);

			sMsg.sHead.msgSize = uSize;
			sMsg.sHead.msgType = uType;
		};

#define YH_MESSAGE(_SMsg, _SData, _spMsg, _type, fn) \
		sl_asio::MsgPtr _spMsg; \
		{ \
			struct _SMsg \
			{ \
				sl_asio::MsgHead sHead; \
				_SData sData; \
			}; \
			_SMsg* _pMsg = new _SMsg; \
			_spMsg.reset(((sl_asio::MsgHead*)_pMsg)); \
			InitMsgHead<_SMsg>(*_pMsg, _type); \
			fn(); \
		} \


		virtual void OnConnected(int error_code, sl_asio::SckId sckId)
		{
			static int nStep = 0;
			nStep++;
			if (1 == nStep)
			{
				YH_MESSAGE(Msg, MsgBSCreateGame, spMsg, 50001, [&_pMsg]()
				{
					auto p = &_pMsg->sData;

					p->lpRequestId = 100;

					p->heroMode = 1102;
					p->gameConf = 1;
					p->deny = false;
					p->gameMode = p->heroMode;

					p->teamAmount = 1;

					p->mapId = 14;
					p->playerCount = 1;

					auto* player = &p->player[0];
					player->accountId = 1;
					player->uinId = 1;
					player->camp = bs_Camp_A;
					player->robot = false;
					player->averagerOther = 1200;
					strcpy(player->szNickName, "test");

				});

				spClient->Send(sckId, spMsg);



				YH_MESSAGE(Msg, MsgBSUpdateRoleHeroSkin, spMsg2, 50013, [&_pMsg]()
				{
					auto p = &_pMsg->sData;

					p->usAmount = 1;

					auto* player = &p->szHeroInfo[0];
					player->idAccount = 1;
					player->lookface = 37001;
					player->skin = 37001;

				});

				spClient->Send(sckId, spMsg2);


			}
			else if (2 == nStep)
			{
				

			}

		}

		virtual void OnProcessMsg(const char* msg, sl_asio::SckId sckId)
		{

		}

	private:

	};


	void test1()
	{

// 		CPipe* pPipe = new CPipe;
// 
// 		spClient = sl_asio::NetCreator::CreateTcpGuest(*pPipe);
// 		spClient->AsyncConnect("127.0.0.1", 5819);
// 
// 		spClient->Run();


	}


}

void test_yh()
{
	space_test_yh::test1();

	getchar();
}
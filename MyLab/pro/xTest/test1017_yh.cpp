

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

		virtual void OnConnected(int error_code, sl_asio::SckId sckId)
		{
			struct Msg
			{
				sl_asio::MsgHead head;
				MsgBSCreateGame data;
			};

			Msg msg;
			auto msgSize = sizeof(msg);
			memset(&msg, 0, msgSize);

			sl_asio::MsgHead* pHead = &msg.head;
			pHead->msgSize = msgSize;
			pHead->msgType = 50001;

			MsgBSCreateGame* cgame = &msg.data;
			cgame->lpRequestId = 1;
			cgame->gameConf = 1;
			cgame->teamAmount = 1;

// 			sl_asio::MsgPtr spMsg;// (pHead);
// 			spMsg.reset(pHead);
// 			spClient->Send(sckId, spMsg);

			char buffer[1024];
			((sl_asio::MsgHead*)buffer)->msgSize = msgSize;
			((sl_asio::MsgHead*)buffer)->msgType = 50001;
			memcpy(buffer + 4, cgame, msgSize-4);
			sl_asio::MsgPtr spMsg;// (pHead);
			spMsg.reset(((sl_asio::MsgHead*)buffer));
			spClient->Send(sckId, spMsg);

		}

	private:

	};



	void test1()
	{
		CPipe* pPipe = new CPipe;

		spClient = sl_asio::NetCreator::CreateTcpGuest(*pPipe);
		spClient->AsyncConnect("127.0.0.1", 5819);

		spClient->Run();
	}


}

void test_yh()
{
	space_test_yh::test1();

	getchar();
}
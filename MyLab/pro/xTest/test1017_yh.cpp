
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
			sMsg.sHead.msgSize = uType;
		};

#define YH_MESSAGE(_SMsg, _SData, _sMsg, _type, fn) \
		struct _SMsg\
		{\
		sl_asio::MsgHead sHead; \
		_SData sData; \
		}; \
		_SMsg _sMsg; \
		InitMsgHead<_SMsg>(_sMsg, _type); \
		fn();

		template<class _T>
		void SendMsg(sl_asio::TcpGuestPtr spClient, sl_asio::SckId nSckId, _T sMsg)
		{
			sl_asio::MsgPtr spMsg;// (pHead);
			spMsg.reset(((sl_asio::MsgHead*)&sMsg));
			spClient->Send(nSckId, spMsg);
		}

		virtual void OnConnected(int error_code, sl_asio::SckId sckId)
		{
			if (1)
			{
				YH_MESSAGE(Msg, MsgBSCreateGame, msg, 50001, [&msg]()
				{
					auto p = &msg.sData;

					p->lpRequestId = 1;
					p->gameConf = 1;
					p->teamAmount = 1;
				});

				SendMsg<Msg>(spClient, sckId, msg);
			}

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
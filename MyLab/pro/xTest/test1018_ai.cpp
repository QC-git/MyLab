
#include "x_all.h"

#include "xTest.h"

#include "test_ai/bt/test_BehaviorTree.hpp"
#include "test_ai/fsm/fsm.hpp"

// https://github.com/aigamedev/btsk

// https://github.com/r-lyeh/fsm

namespace space_test_ai
{

	struct CMyBehavior : public bt::Behavior
	{
		int m_iInitializeCalled;
		int m_iTerminateCalled;
		int m_iUpdateCalled;
		bt::Status m_eReturnStatus;
		bt::Status m_eTerminateStatus;

		int m_nTag;
		int m_nMode;

		CMyBehavior(int tag, int mode)
			: m_iInitializeCalled(0)
			, m_iTerminateCalled(0)
			, m_iUpdateCalled(0)
			, m_eTerminateStatus(bt::BH_INVALID)
		{
			m_nTag = tag;
			m_nMode = mode;
		}

		virtual ~CMyBehavior()
		{
		}

		virtual void onInitialize()
		{
			++m_iInitializeCalled;
		}

		virtual void onTerminate(bt::Status s)
		{
			++m_iTerminateCalled;
			m_eTerminateStatus = s;
		}

		virtual bt::Status update()
		{
			++m_iUpdateCalled;

			bt::Status ret;

			if (0 == m_nMode ) 
			{
				ret = bt::BH_RUNNING;
			}

			if (1 == m_nMode)
			{
				ret = bt::BH_SUCCESS;
			}

			if (2 == m_nMode)
			{
				ret = bt::BH_FAILURE;
			}

			if (3 == m_nMode)
			{
				if ( 0 == m_iUpdateCalled%3 )
				{
					m_iUpdateCalled = 0;
					ret = bt::BH_SUCCESS;
				}
				else
				{
					ret = bt::BH_RUNNING;
				}
				
			}

			LOG_F("tag %d tick %d", m_nTag, ret);
			
			return ret;
		}
	};


	void test1()
	{
		auto node1 = new bt::Parallel(bt::Parallel::RequireAll, bt::Parallel::RequireOne);
		auto node11 = new bt::Sequence();
		//auto leaf12 = new CMyBehavior(12, 0);
		auto leaf13 = new CMyBehavior(13, 1);
		//auto leaf14 = new CMyBehavior(14, 2);
		node1->addChild(node11);
		//node1->addChild(leaf12);
		node1->addChild(leaf13);
		//node1->addChild(leaf14);

		auto leaf121 = new CMyBehavior(121, 3);
		auto leaf122 = new CMyBehavior(122, 2);
		node11->addChild(leaf121);
		node11->addChild(leaf122);

	
		auto sta = node1->tick();
		sta = node1->tick();
		sta = node1->tick();
		sta = node1->tick();
		sta = node1->tick();

		printf("");
	}


	enum {
		opening,
		closing,
		waiting,
		playing,

		open,
		close,
		play,
		stop,
		insert,
		eject,
	};

	struct cd_player {

		// implementation variables
		bool has_cd;

		// implementation conditions / guards
		bool good_disk_format() { return true; }

		// implementation actions
		void open_tray()      { std::cout << "opening tray" << std::endl; }
		void close_tray()     { std::cout << "closing tray" << std::endl; }
		void get_cd_info()    { std::cout << "retrieving CD info" << std::endl; }
		void start_playback(const std::string &track) { std::cout << "playing track #" << track << std::endl; }

		// the core
		test_fsm::stack fsm;

		cd_player() : has_cd(false)
		{
			// define fsm transitions: on(state,trigger) -> do lambda
			fsm.on(opening, close) = [&](const test_fsm::args &args) {
				close_tray();
				if (!has_cd) {
					fsm.set(closing);
				}
				else {
					get_cd_info();
					fsm.set(waiting);
				}
			};
			fsm.on(opening, insert) = [&](const test_fsm::args &args) {
				has_cd = true;
				fsm.set(opening);
			};
			fsm.on(opening, eject) = [&](const test_fsm::args &args) {
				has_cd = false;
				fsm.set(opening);
			};

			fsm.on(closing, open) = [&](const test_fsm::args &args) {
				open_tray();
				fsm.set(opening);
			};

			fsm.on(waiting, play) = [&](const test_fsm::args &args) {
				if (!good_disk_format()) {
					fsm.set(waiting);
				}
				else {
					start_playback(args[0]);
					fsm.set(playing);
				}
			};
			fsm.on(waiting, open) = [&](const test_fsm::args &args) {
				open_tray();
				fsm.set(opening);
			};

			fsm.on(playing, open) = [&](const test_fsm::args &args) {
				open_tray();
				fsm.set(opening);
			};
			fsm.on(playing, stop) = [&](const test_fsm::args &args) {
				fsm.set(waiting);
			};

			// set initial fsm state
			fsm.set(opening);
		}
	};

	// usage

	int FsmSample1()
	{
		cd_player cd;

		for (;;) {
			std::cout << "[" << cd.fsm.get_state() << "] ";
			std::cout << "cmd? ";

			char cmd;
			std::cin >> cmd;

			switch (cmd) {
			case 'p': cd.fsm.command(play, 1 + rand() % 10); break;
			case 'o': cd.fsm.command(open); break;
			case 'c': cd.fsm.command(close); break;
			case 's': cd.fsm.command(stop); break;
			case 'i': cd.fsm.command(insert); break;
			case 'e': cd.fsm.command(eject); break;
			default: std::cout << "what?" << std::endl;
			}
		}
	}

	enum {
		walking = 'WALK',
		defending = 'DEFN',

		tick = 'tick',
	};

	struct ant_t {
		test_fsm::stack fsm;
		int health, distance, flow;

		ant_t() : health(0), distance(0), flow(1) {
			// define fsm transitions: on(state,trigger) -> do lambda
			fsm.on(walking, 'init') = [&](const test_fsm::args &args) {
				std::cout << "initializing" << std::endl;
			};
			fsm.on(walking, 'quit') = [&](const test_fsm::args &args) {
				std::cout << "exiting" << std::endl;
			};
			fsm.on(walking, 'push') = [&](const test_fsm::args &args) {
				std::cout << "pushing current task." << std::endl;
			};
			fsm.on(walking, 'back') = [&](const test_fsm::args &args) {
				std::cout << "back from another task. remaining distance: " << distance << std::endl;
			};
			fsm.on(walking, tick) = [&](const test_fsm::args &args) {
				std::cout << "\r" << "\\|/-"[distance % 4] << " walking " << (flow > 0 ? "-->" : "<--") << " ";
				distance += flow;
				if (1000 == distance) {
					std::cout << "at food!" << std::endl;
					flow = -flow;
				}
				if (-1000 == distance) {
					std::cout << "at home!" << std::endl;
					flow = -flow;
				}
			};
			fsm.on(defending, 'init') = [&](const test_fsm::args &args) {
				health = 1000;
				std::cout << "somebody is attacking me! he has " << health << " health points" << std::endl;
			};
			fsm.on(defending, tick) = [&](const test_fsm::args &args) {
				std::cout << "\r" << "\\|/-$"[health % 4] << " health: (" << health << ")   ";
				--health;
				if (health < 0) {
					std::cout << std::endl;
					fsm.pop();
				}
			};

			// set initial fsm state
			fsm.set(walking);
		}
	};

	int FsmSample2() 
	{
		ant_t ant;
		for (int i = 0; i < 12000; ++i) {
			if (0 == rand() % 10000) {
				ant.fsm.push(defending);
			}
			ant.fsm.command(tick);
		}

		std::stringstream ss;
		ant.fsm.debug(ss);
		std::cout << ss.str() << std::endl;

		return 0;
	}


	void test2()
	{
 		//FsmSample1();
		FsmSample2();
 	}


}


void test_ai()
{
	//space_test_ai::test1();
	space_test_ai::test2();

	getchar();
}
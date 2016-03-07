#include "Scene2d.h"
#include "Scene3d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Logic.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Scene2d::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Scene2d::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

Scene2d::~Scene2d()
{
	printf("\n Scene2d::~Scene2d() \n");
}

// on "init" you need to initialize your instance
bool Scene2d::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	m_bW = m_bS = m_bA = m_bD = false;

	m_rootNode = CCNode::create();
	addChild(m_rootNode);
	m_rootNode->setPosition(ccp(0, 0));
	m_centerPos = ccp(480, 320);

	// 	auto spt3D = Sprite3D::create();
	// 	m_rootNode->addChild(spt3D);
	// 	spt3D->setPosition(ccp(900, 0));
	// 	spt3D->setTexture("person.png");

	// 	m_rootNode2 = CSLoader::createNode("Scene3D.csb");
	// 	m_rootNode2->setPosition(ccp(900, 0));
	// 	this->addChild(m_rootNode2);
	// 	m_rootNode2->setVisible(false);
	//m_rootNode = CCTMXTiledMap::create("test1111.tmx");

	auto draw = CCDrawNode::create();
	m_rootNode->addChild(draw, 10);
	draw->drawPoint(Vec2(0, 500), 10, Color4F(0, 1, 1, 1));
	draw->drawRect(Vec2(0, 0), Vec2(400, 400), Color4F(0, 1, 1, 1));
	draw->drawLine(Vec2(400, 400), Vec2(400, 500), Color4F(0, 1, 1, 1));
	draw->drawCircle(Vec2(700, 150), 100, 0, 8, false, Color4F(0, 1, 1, 1));
	draw->drawCircle(Vec2(700, 500), 100, 0, 8, false, 2, 1, Color4F(0, 1, 1, 1));

	// 	m_sprite = CCSprite::create("person.png", CCRectMake(0, 0, 60, 60));
	// 	m_sprite->setPosition(ccp(480, 320));
	// 	m_rootNode->addChild(m_sprite);

	m_sprite = CSLoader::createNode("Hero.csb");
	m_sprite->setPosition(ccp(480, 320));
	auto heroAction = CSLoader::createTimeline("Hero.csb");
	m_sprite->runAction(heroAction);
	heroAction->gotoFrameAndPlay(0);
	m_rootNode->addChild(m_sprite);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](CCTouch* touch, CCEvent* event)
	{
		Vec2 pos = touch->getLocation();
		Vec2 pos2 = m_rootNode->convertToNodeSpace(pos);
		printf("\n %d, %.2f, %.2f \n", event->getType(), pos2.x, pos2.y);

		if (pos2.x < 0 || pos2.y < 0)
		{
			return true;
		}

		m_sprite->setPosition(pos2);

		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	_keyRecord = new KeyboardRecord(this);

	auto button = ui::Button::create("buttonA.png", "buttonB.png");
	this->addChild(button);
	button->setPosition(ccp(100, 500));
	button->setAnchorPoint(ccp(0, 0));
	button->ignoreContentAdaptWithSize(false);
	button->setSize(Size(50, 10));
	button->setVisible(true);
	button->addClickEventListener([=](Ref* ref) {
// 		static bool flag = false;
// 		m_rootNode->setVisible(flag);
// 		_layer3D->setVisible(!flag);
// 		flag ^= true;

		auto scene = Scene3d::createScene();
		Director::getInstance()->replaceScene(scene);
		//Director::sharedDirector()->replaceScene(TransitionFade::create(2, scene));
	});

	scheduleUpdate();
	schedule(schedule_selector(Scene2d::myUpdate), 0.1f);

	return true;
}

void Scene2d::update(float delta)
{
	Node::update(delta);

// 	static struct timeval lastTime;
// 	struct timeval curTime;
// 	gettimeofday(&curTime, NULL);
// 	printf("\n update(), delta = %.2f, delTime = %d \n", delta, (curTime.tv_usec - lastTime.tv_usec) / 1000);
// 	lastTime = curTime;


	auto diff = ccp(0, 0);
	float diffValue = 5;
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_W))
	{
		diff.y += diffValue;
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_S))
	{
		diff.y -= diffValue;
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_A))
	{
		diff.x -= diffValue;
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_D))
	{
		diff.x += diffValue;
	}

	FollowNode(m_sprite, m_rootNode, diff);

}


void Scene2d::myUpdate(float delta)
{
	Node::update(delta);

	static long lastTime = 0;
	long curTime;
	struct timeval cur;
	gettimeofday(&cur, NULL);
	curTime = cur.tv_sec % 3600 * 1000 + cur.tv_usec / 1000;

	//printf("\n myUpdate(), delta = %.2f, delTime = %d \n", delta, curTime - lastTime);
	lastTime = curTime;

	CenterNode(m_sprite, m_rootNode, ccp(480, 320));
}


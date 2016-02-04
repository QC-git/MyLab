#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "AppTest.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
	printf("\n HelloWorld::init() \n");
	CCLOG("\n HelloWorld::init() \n");
	fflush(stdout);

	//     auto rootNode = CSLoader::createNode("MainScene.csb");
	// 
	//     addChild(rootNode);

	CCDrawNode* draw = CCDrawNode::create();

	addChild(draw, 10);


	draw->drawLine(Vec2(50, 50), Vec2(500, 500), Color4F(0, 1, 1, 1));

	draw->drawLine(ccp(50, 60), ccp(500, 510), Color4F(0, 1, 1, 1));

	draw->drawCircle(Vec2(500, 150), 100, 0, 8, false, Color4F(0, 1, 1, 1));

	draw->drawCircle(Vec2(500, 500), 100, 0, 8, false, 2, 1, Color4F(0, 1, 1, 1));

	draw->drawPoint(Vec2(300, 150), 10, Color4F(0, 1, 1, 1));

	CCSprite* sprite = CCSprite::create("person.png");
	sprite->setPosition(ccp(100, 100));
	this->addChild(sprite);

	m_sprite = CCSprite::create("person.png", CCRectMake(0, 0, 60, 60));
	m_sprite->setPosition(ccp(300, 100));
	this->addChild(m_sprite);

	//test_main();

	scheduleUpdate();
	schedule(schedule_selector(HelloWorld::myUpdate), 0.1f);

    return true;
}

void HelloWorld::update(float delta)
{
	Node::update(delta);

//	static struct timeval lastTime;
//	struct timeval curTime;
//	gettimeofday(&curTime, NULL);
//	printf("\n update(), delta = %.2f, delTime = %d \n", delta, (curTime.tv_usec - lastTime.tv_usec) / 1000);
//	lastTime = curTime;

}


void HelloWorld::myUpdate(float delta)
{
	Node::update(delta);

	static long lastTime = 0;
	long curTime;
	struct timeval cur;
	gettimeofday(&cur, NULL);
	curTime = cur.tv_sec % 3600 * 1000 + cur.tv_usec / 1000;

	printf("\n myUpdate(), delta = %.2f, delTime = %d \n", delta, curTime - lastTime);
	lastTime = curTime;

	Vec2 pos = m_sprite->getPosition();
	pos.x += 5;
	m_sprite->setPosition(pos);

}
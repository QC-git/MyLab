#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
    
	//     auto rootNode = CSLoader::createNode("MainScene.csb");
	// 
	//     addChild(rootNode);

	CCDrawNode* draw = CCDrawNode::create();

	addChild(draw, 10);


	draw->drawLine(Vec2(50, 50), Vec2(500, 500), Color4F(0, 1, 1, 1));

	draw->drawCircle(Vec2(500, 150), 100, 0, 8, false, Color4F(0, 1, 1, 1));

	draw->drawCircle(Vec2(500, 500), 100, 0, 8, false, 2, 1, Color4F(0, 1, 1, 1));

	draw->drawPoint(Vec2(300, 150), 10, Color4F(0, 1, 1, 1));

    return true;
}

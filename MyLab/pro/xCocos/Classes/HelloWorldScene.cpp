#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "AppTest.h"

#include "Sprite3DTest/DrawNode3D.h"
#include "Logic.h"

USING_NS_CC;

using namespace cocostudio::timeline;


Rect VisibleRect::s_visibleRect;

void VisibleRect::lazyInit()
{
	// no lazy init
	// Useful if we change the resolution in runtime
	s_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
}

Rect VisibleRect::getVisibleRect()
{
	lazyInit();
	return s_visibleRect;
}

Vec2 VisibleRect::left()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}

Vec2 VisibleRect::right()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}

Vec2 VisibleRect::top()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y + s_visibleRect.size.height);
}

Vec2 VisibleRect::bottom()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y);
}

Vec2 VisibleRect::center()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}

Vec2 VisibleRect::leftTop()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height);
}

Vec2 VisibleRect::rightTop()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height);
}

Vec2 VisibleRect::leftBottom()
{
	lazyInit();
	return s_visibleRect.origin;
}

Vec2 VisibleRect::rightBottom()
{
	lazyInit();
	return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y);
}

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

	_camera = nullptr;
   
	m_bW = m_bS = m_bA = m_bD = false;

	printf("\n HelloWorld::init() \n");
	CCLOG("\n HelloWorld::init() \n");
	fflush(stdout);

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

// 	m_sprite = CSLoader::createNode("Hero.csb");
// 	m_sprite->setPosition(ccp(480, 320));
// 	auto heroAction = CSLoader::createTimeline("Hero.csb");
// 	m_sprite->runAction(heroAction);
// 	heroAction->gotoFrameAndPlay(0);
// 	m_rootNode->addChild(m_sprite);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::touchBegin, this);
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
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto eyboardListener = EventListenerKeyboard::create();
	eyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		printf("\n onKeyPressed(), keyCode %d \n", keyCode);

		Vec2 diff;

		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_W:
		{
											  m_bW = true;
		} break;
		case EventKeyboard::KeyCode::KEY_S:
		{
											  m_bS = true;
		} break;
		case EventKeyboard::KeyCode::KEY_A:
		{
											  m_bA = true;
		} break;
		case EventKeyboard::KeyCode::KEY_D:
		{
											  m_bD = true;
		} break;
		default:
			break;
		}

	};

	eyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		printf("\n onKeyPressed(), keyCode %d \n", keyCode);

		Vec2 diff;

		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_W:
		{
											  m_bW = false;
		} break;
		case EventKeyboard::KeyCode::KEY_S:
		{
											  m_bS = false;
		} break;
		case EventKeyboard::KeyCode::KEY_A:
		{
											  m_bA = false;
		} break;
		case EventKeyboard::KeyCode::KEY_D:
		{
											  m_bD = false;
		} break;
		default:
			break;
		}
	};
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(eyboardListener, this);

	auto button = ui::Button::create("buttonA.png", "buttonB.png");
	this->addChild(button);
	button->setPosition(ccp(100, 500));
	button->setAnchorPoint(ccp(0, 0));
	button->ignoreContentAdaptWithSize(false);
	button->setSize(Size(50, 10));
	button->setVisible(true);
	button->addClickEventListener([=](Ref* ref) {
		static bool flag = false;
		//m_rootNode->setVisible(flag);
		//m_rootNode2->setVisible(!flag);

		flag ^= true; 

		//Director::sharedDirector()->replaceScene(TransitionFade::create(2, scene));
		
		printf("");
	});

	//scheduleUpdate();
	//schedule(schedule_selector(HelloWorld::myUpdate), 0.1f);

	//test_main();

	_sprite3D = nullptr;
	auto s = Director::getInstance()->getWinSize();
// 	auto listener = EventListenerTouchAllAtOnce::create();
// 	listener->onTouchesBegan = CC_CALLBACK_2(Camera3DTestDemo::onTouchesBegan, this);
// 	listener->onTouchesMoved = CC_CALLBACK_2(Camera3DTestDemo::onTouchesMoved, this);
// 	listener->onTouchesEnded = CC_CALLBACK_2(Camera3DTestDemo::onTouchesEnded, this);
// 	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	auto layer3D = Layer::create();
	addChild(layer3D, 0);
	_layer3D = layer3D;
	_curState = State_None;
	addNewSpriteWithCoords(Vec3(0, 0, 0), "Sprite3DTest/girl.c3b", true, 0.2f, true);
	TTFConfig ttfConfig("fonts/arial.ttf", 20);

	auto containerForLabel1 = Node::create();
	_ZoomOutlabel = Label::createWithTTF(ttfConfig, "zoom out");
	_ZoomOutlabel->setPosition(s.width - 50, VisibleRect::top().y - 30);
	containerForLabel1->addChild(_ZoomOutlabel);
	addChild(containerForLabel1, 10);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchesZoomOut, this);
	listener1->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchesZoomOutEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, _ZoomOutlabel);

	auto containerForLabel2 = Node::create();
	_ZoomInlabel = Label::createWithTTF(ttfConfig, "zoom in");
	_ZoomInlabel->setPosition(s.width - 50, VisibleRect::top().y - 100);
	containerForLabel2->addChild(_ZoomInlabel);
	addChild(containerForLabel2, 10);

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->setSwallowTouches(true);
	listener2->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchesZoomIn, this);
	listener2->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchesZoomInEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, _ZoomInlabel);

	auto containerForLabel3 = Node::create();
	_RotateLeftlabel = Label::createWithTTF(ttfConfig, "rotate left");
	_RotateLeftlabel->setPosition(s.width - 50, VisibleRect::top().y - 170);
	containerForLabel3->addChild(_RotateLeftlabel);
	addChild(containerForLabel3, 10);

	auto listener3 = EventListenerTouchOneByOne::create();
	listener3->setSwallowTouches(true);
	listener3->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchesRotateLeft, this);
	listener3->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchesRotateLeftEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, _RotateLeftlabel);

	auto containerForLabel4 = Node::create();
	_RotateRightlabel = Label::createWithTTF(ttfConfig, "rotate right");
	_RotateRightlabel->setPosition(s.width - 50, VisibleRect::top().y - 240);
	containerForLabel4->addChild(_RotateRightlabel);
	addChild(containerForLabel4, 10);

	auto listener4 = EventListenerTouchOneByOne::create();
	listener4->setSwallowTouches(true);
	listener4->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchesRotateRight, this);
	listener4->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchesRotateRightEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener4, _RotateRightlabel);

	auto label1 = Label::createWithTTF(ttfConfig, "free ");
	auto menuItem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(HelloWorld::SwitchViewCallback, this, CameraType::Free));
	auto label2 = Label::createWithTTF(ttfConfig, "third person");
	auto menuItem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(HelloWorld::SwitchViewCallback, this, CameraType::ThirdPerson));
	auto label3 = Label::createWithTTF(ttfConfig, "first person");
	auto menuItem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(HelloWorld::SwitchViewCallback, this, CameraType::FirstPerson));
	auto menu = Menu::create(menuItem1, menuItem2, menuItem3, nullptr);

	menu->setPosition(Vec2::ZERO);

	menuItem1->setPosition(VisibleRect::left().x + 100, VisibleRect::top().y - 50);
	menuItem2->setPosition(VisibleRect::left().x + 100, VisibleRect::top().y - 100);
	menuItem3->setPosition(VisibleRect::left().x + 100, VisibleRect::top().y - 150);
	addChild(menu, 0);
	schedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateCamera), 0.0f);
	if (_camera == nullptr)
	{
		_camera = Camera::createPerspective(60, (GLfloat)s.width / s.height, 1, 1000);
		_camera->setCameraFlag(CameraFlag::USER1);
		_layer3D->addChild(_camera);
	}
	SwitchViewCallback(this, CameraType::ThirdPerson);
	DrawNode3D* line = DrawNode3D::create();
	//draw x
	for (int j = -20; j <= 20; j++)
	{
		line->drawLine(Vec3(-100, 0, 5 * j), Vec3(100, 0, 5 * j), Color4F(1, 0, 0, 1));
	}
	//draw z
	for (int j = -20; j <= 20; j++)
	{
		line->drawLine(Vec3(5 * j, 0, -100), Vec3(5 * j, 0, 100), Color4F(0, 0, 1, 1));
	}
	//draw y
	line->drawLine(Vec3(0, -50, 0), Vec3(0, 0, 0), Color4F(0, 0.5, 0, 1));
	line->drawLine(Vec3(0, 0, 0), Vec3(0, 50, 0), Color4F(0, 1, 0, 1));
	_layer3D->addChild(line);

	_layer3D->setCameraMask(2);

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


	auto diff = ccp(0,0);
	float diffValue = 5;
	if (m_bW) 
	{
		diff.y += diffValue;
	}
	if (m_bS)
	{
		diff.y -= diffValue;
	}
	if (m_bA)
	{
		diff.x -= diffValue;
	}
	if (m_bD)
	{
		diff.x += diffValue;
	}


	Vec2 pos = m_sprite->getPosition() + diff;
	m_sprite->setPosition(pos);
	m_rootNode->setPosition(m_rootNode->getPosition() - diff);


}


void HelloWorld::myUpdate(float delta)
{
	Node::update(delta);

	static long lastTime = 0;
	long curTime;
	struct timeval cur;
	gettimeofday(&cur, NULL);
	curTime = cur.tv_sec % 3600 * 1000 + cur.tv_usec / 1000;

	//printf("\n myUpdate(), delta = %.2f, delTime = %d \n", delta, curTime - lastTime);
	lastTime = curTime;

	auto pos = m_sprite->getPosition();
	auto pos2 = m_rootNode->convertToWorldSpace(pos);
	auto diff = pos2 - ccp(480, 320);

	m_rootNode->setPosition(m_rootNode->getPosition() - diff);

}

bool HelloWorld::touchBegin(CCTouch* touch, CCEvent* event)
{
	return true;
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	//printf("\n onKeyPressed(), keyCode %d \n", keyCode);
}



void HelloWorld::addNewSpriteWithCoords(Vec3 p, std::string fileName, bool playAnimation, float scale, bool bindCamera)
{
	auto sprite = Sprite3D::create(fileName);
	_layer3D->addChild(sprite);
	float globalZOrder = sprite->getGlobalZOrder();
	sprite->setPosition3D(Vec3(p.x, p.y, p.z));
	sprite->setGlobalZOrder(globalZOrder);
	if (playAnimation)
	{
		auto animation = Animation3D::create(fileName, "Take 001");
		if (animation)
		{
			auto animate = Animate3D::create(animation);
			sprite->runAction(RepeatForever::create(animate));
		}
	}
	if (bindCamera)
	{
		_sprite3D = sprite;
	}
	sprite->setScale(scale);
}

void HelloWorld::SwitchViewCallback(Ref* sender, CameraType cameraType)
{
	if (_cameraType == cameraType)
	{
		return;
	}
	_cameraType = cameraType;
	if (_cameraType == CameraType::Free)
	{
		_camera->setPosition3D(Vec3(0, 130, 130) + _sprite3D->getPosition3D());
		_camera->lookAt(_sprite3D->getPosition3D());

		_RotateRightlabel->setColor(Color3B::WHITE);
		_RotateLeftlabel->setColor(Color3B::WHITE);
		_ZoomInlabel->setColor(Color3B::WHITE);
		_ZoomOutlabel->setColor(Color3B::WHITE);
	}
	else if (_cameraType == CameraType::FirstPerson)
	{
		Vec3 newFaceDir;
		_sprite3D->getWorldToNodeTransform().getForwardVector(&newFaceDir);
		newFaceDir.normalize();
		_camera->setPosition3D(Vec3(0, 35, 0) + _sprite3D->getPosition3D());
		_camera->lookAt(_sprite3D->getPosition3D() + newFaceDir * 50);

		_RotateRightlabel->setColor(Color3B::WHITE);
		_RotateLeftlabel->setColor(Color3B::WHITE);
		_ZoomInlabel->setColor(Color3B::GRAY);
		_ZoomOutlabel->setColor(Color3B::GRAY);
	}
	else if (_cameraType == CameraType::ThirdPerson)
	{
		_camera->setPosition3D(Vec3(0, 130, 130) + _sprite3D->getPosition3D());
		_camera->lookAt(_sprite3D->getPosition3D());

		_RotateRightlabel->setColor(Color3B::GRAY);
		_RotateLeftlabel->setColor(Color3B::GRAY);
		_ZoomInlabel->setColor(Color3B::WHITE);
		_ZoomOutlabel->setColor(Color3B::WHITE);
	}
}

bool HelloWorld::onTouchesCommon(Touch* touch, Event* event, bool* touchProperty)
{
	auto target = static_cast<Label*>(event->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		*touchProperty = true;
		return true;
	}
	return false;
}

bool HelloWorld::onTouchesZoomOut(Touch* touch, Event* event)
{
	return HelloWorld::onTouchesCommon(touch, event, &_bZoomOut);
}
void HelloWorld::onTouchesZoomOutEnd(Touch* touch, Event* event)
{
	_bZoomOut = false;
}
bool HelloWorld::onTouchesZoomIn(Touch* touch, Event* event)
{
	return HelloWorld::onTouchesCommon(touch, event, &_bZoomIn);
}
void HelloWorld::onTouchesZoomInEnd(Touch* touch, Event* event)
{
	_bZoomIn = false;
}

bool HelloWorld::onTouchesRotateLeft(Touch* touch, Event* event)
{
	return HelloWorld::onTouchesCommon(touch, event, &_bRotateLeft);
}
void HelloWorld::onTouchesRotateLeftEnd(Touch* touch, Event* event)
{
	_bRotateLeft = false;
}
bool HelloWorld::onTouchesRotateRight(Touch* touch, Event* event)
{
	return HelloWorld::onTouchesCommon(touch, event, &_bRotateRight);
}
void HelloWorld::onTouchesRotateRightEnd(Touch* touch, Event* event)
{
	_bRotateRight = false;
}

void HelloWorld::updateCamera(float fDelta)
{
	if (_sprite3D)
	{
		if (_cameraType == CameraType::ThirdPerson)
		{
			updateState(fDelta);
			if (isState(_curState, State_Move))
			{
				move3D(fDelta);
				if (isState(_curState, State_Rotate))
				{
					Vec3 curPos = _sprite3D->getPosition3D();

					Vec3 newFaceDir = _targetPos - curPos;
					newFaceDir.y = 0;
					newFaceDir.normalize();
					Vec3 up;
					_sprite3D->getNodeToWorldTransform().getUpVector(&up);
					up.normalize();
					Vec3 right;
					Vec3::cross(-newFaceDir, up, &right);
					right.normalize();
					Vec3 pos = Vec3(0, 0, 0);
					Mat4 mat;
					mat.m[0] = right.x;
					mat.m[1] = right.y;
					mat.m[2] = right.z;
					mat.m[3] = 0.0f;

					mat.m[4] = up.x;
					mat.m[5] = up.y;
					mat.m[6] = up.z;
					mat.m[7] = 0.0f;

					mat.m[8] = newFaceDir.x;
					mat.m[9] = newFaceDir.y;
					mat.m[10] = newFaceDir.z;
					mat.m[11] = 0.0f;

					mat.m[12] = pos.x;
					mat.m[13] = pos.y;
					mat.m[14] = pos.z;
					mat.m[15] = 1.0f;
					_sprite3D->setAdditionalTransform(&mat);
				}
			}
		}
		if (_bZoomOut == true)
		{
			if (_camera)
			{
				if (_cameraType == CameraType::ThirdPerson)
				{
					Vec3 lookDir = _camera->getPosition3D() - _sprite3D->getPosition3D();
					Vec3 cameraPos = _camera->getPosition3D();
					if (lookDir.length() <= 300)
					{
						cameraPos += lookDir.getNormalized();
						_camera->setPosition3D(cameraPos);
					}
				}
				else if (_cameraType == CameraType::Free)
				{
					Vec3 cameraPos = _camera->getPosition3D();
					if (cameraPos.length() <= 300)
					{
						cameraPos += cameraPos.getNormalized();
						_camera->setPosition3D(cameraPos);
					}
				}
			}
		}
		if (_bZoomIn == true)
		{
			if (_camera)
			{
				if (_cameraType == CameraType::ThirdPerson)
				{
					Vec3 lookDir = _camera->getPosition3D() - _sprite3D->getPosition3D();
					Vec3 cameraPos = _camera->getPosition3D();
					if (lookDir.length() >= 50)
					{
						cameraPos -= lookDir.getNormalized();
						_camera->setPosition3D(cameraPos);
					}
				}
				else if (_cameraType == CameraType::Free)
				{
					Vec3 cameraPos = _camera->getPosition3D();
					if (cameraPos.length() >= 50)
					{
						cameraPos -= cameraPos.getNormalized();
						_camera->setPosition3D(cameraPos);
					}
				}
			}
		}
		if (_bRotateLeft == true)
		{
			if (_cameraType == CameraType::Free || _cameraType == CameraType::FirstPerson)
			{
				Vec3  rotation3D = _camera->getRotation3D();
				rotation3D.y += 1;
				_camera->setRotation3D(rotation3D);
			}
		}
		if (_bRotateRight == true)
		{
			if (_cameraType == CameraType::Free || _cameraType == CameraType::FirstPerson)
			{
				Vec3  rotation3D = _camera->getRotation3D();
				rotation3D.y -= 1;
				_camera->setRotation3D(rotation3D);
			}
		}
	}
}


void HelloWorld::move3D(float elapsedTime)
{
	if (_sprite3D)
	{
		Vec3 curPos = _sprite3D->getPosition3D();
		Vec3 newFaceDir = _targetPos - curPos;
		newFaceDir.y = 0.0f;
		newFaceDir.normalize();
		Vec3 offset = newFaceDir * 25.0f * elapsedTime;
		curPos += offset;
		_sprite3D->setPosition3D(curPos);
		if (_cameraType == CameraType::ThirdPerson)
		{
			Vec3 cameraPos = _camera->getPosition3D();
			cameraPos.x += offset.x;
			cameraPos.z += offset.z;
			_camera->setPosition3D(cameraPos);
		}
	}
}
void HelloWorld::updateState(float elapsedTime)
{
	if (_sprite3D)
	{
		Vec3 curPos = _sprite3D->getPosition3D();
		Vec3 curFaceDir;
		_sprite3D->getNodeToWorldTransform().getForwardVector(&curFaceDir);
		curFaceDir = -curFaceDir;
		curFaceDir.normalize();
		Vec3 newFaceDir = _targetPos - curPos;
		newFaceDir.y = 0.0f;
		newFaceDir.normalize();
		float cosAngle = std::fabs(Vec3::dot(curFaceDir, newFaceDir) - 1.0f);
		float dist = curPos.distanceSquared(_targetPos);
		if (dist <= 4.0f)
		{
			if (cosAngle <= 0.01f)
				_curState = State_Idle;
			else
				_curState = State_Rotate;
		}
		else
		{
			if (cosAngle > 0.01f)
				_curState = State_Rotate | State_Move;
			else
				_curState = State_Move;
		}
	}
}

bool HelloWorld::isState(unsigned int state, unsigned int bit) const
{
	return (state & bit) == bit;
}

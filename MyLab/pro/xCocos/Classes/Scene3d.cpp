#include "Scene2d.h"
#include "Scene3d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Sprite3DTest/DrawNode3D.h"

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

Scene* Scene3d::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Scene3d::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Scene3d::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	_camera = nullptr;

	auto button = ui::Button::create("buttonA.png", "buttonB.png");
	this->addChild(button);
	button->setPosition(ccp(100, 500));
	button->setAnchorPoint(ccp(0, 0));
	button->ignoreContentAdaptWithSize(false);
	button->setSize(Size(50, 10));
	button->setVisible(true);
	button->addClickEventListener([=](Ref* ref) {
		auto scene = Scene2d::createScene();
		Director::getInstance()->replaceScene(scene);
	});

	_sprite3D = nullptr;
	auto s = Director::getInstance()->getWinSize();
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Scene3d::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Scene3d::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Scene3d::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
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
	listener1->onTouchBegan = CC_CALLBACK_2(Scene3d::onTouchesZoomOut, this);
	listener1->onTouchEnded = CC_CALLBACK_2(Scene3d::onTouchesZoomOutEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, _ZoomOutlabel);

	auto containerForLabel2 = Node::create();
	_ZoomInlabel = Label::createWithTTF(ttfConfig, "zoom in");
	_ZoomInlabel->setPosition(s.width - 50, VisibleRect::top().y - 100);
	containerForLabel2->addChild(_ZoomInlabel);
	addChild(containerForLabel2, 10);

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->setSwallowTouches(true);
	listener2->onTouchBegan = CC_CALLBACK_2(Scene3d::onTouchesZoomIn, this);
	listener2->onTouchEnded = CC_CALLBACK_2(Scene3d::onTouchesZoomInEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, _ZoomInlabel);

	auto containerForLabel3 = Node::create();
	_RotateLeftlabel = Label::createWithTTF(ttfConfig, "camera up");
	_RotateLeftlabel->setPosition(s.width - 50, VisibleRect::top().y - 170);
	containerForLabel3->addChild(_RotateLeftlabel);
	addChild(containerForLabel3, 10);

	auto listener3 = EventListenerTouchOneByOne::create();
	listener3->setSwallowTouches(true);
	listener3->onTouchBegan = CC_CALLBACK_2(Scene3d::onTouchesCameraUp, this);
	listener3->onTouchEnded = CC_CALLBACK_2(Scene3d::onTouchesCameraUpEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, _RotateLeftlabel);

	auto containerForLabel4 = Node::create();
	_RotateRightlabel = Label::createWithTTF(ttfConfig, "camera down");
	_RotateRightlabel->setPosition(s.width - 50, VisibleRect::top().y - 240);
	containerForLabel4->addChild(_RotateRightlabel);
	addChild(containerForLabel4, 10);

	auto listener4 = EventListenerTouchOneByOne::create();
	listener4->setSwallowTouches(true);
	listener4->onTouchBegan = CC_CALLBACK_2(Scene3d::onTouchesCameraDown, this);
	listener4->onTouchEnded = CC_CALLBACK_2(Scene3d::onTouchesCameraDownEnd, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener4, _RotateRightlabel);

	auto label1 = Label::createWithTTF(ttfConfig, "free ");
	auto menuItem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(Scene3d::SwitchViewCallback, this, CameraType::Free));
	auto label2 = Label::createWithTTF(ttfConfig, "third person");
	auto menuItem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(Scene3d::SwitchViewCallback, this, CameraType::ThirdPerson));
	auto label3 = Label::createWithTTF(ttfConfig, "first person");
	auto menuItem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(Scene3d::SwitchViewCallback, this, CameraType::FirstPerson));
	auto menu = Menu::create(menuItem1, menuItem2, menuItem3, nullptr);

	menu->setPosition(Vec2::ZERO);

	menuItem1->setPosition(VisibleRect::left().x + 100, VisibleRect::top().y - 50);
	menuItem2->setPosition(VisibleRect::left().x + 100, VisibleRect::top().y - 100);
	menuItem3->setPosition(VisibleRect::left().x + 100, VisibleRect::top().y - 150);
	addChild(menu, 0);
	schedule(CC_SCHEDULE_SELECTOR(Scene3d::updateCamera), 0.0f);
	if (_camera == nullptr)
	{
		_camera = Camera::createPerspective(60, (GLfloat)s.width / s.height, 1, 1000);
		_camera->setCameraFlag(CameraFlag::USER1);
		_layer3D->addChild(_camera);
	}
	SwitchViewCallback(this, CameraType::ThirdPerson);
	DrawNode3D* line = DrawNode3D::create();


	DrawGrid(line, Vec3(-200, 0, -200), 40, 10);

	//draw y
	line->drawLine(Vec3(0, -50, 0), Vec3(0, 0, 0), Color4F(0, 0.5, 0, 1));
	line->drawLine(Vec3(0, 0, 0), Vec3(0, 50, 0), Color4F(0, 1, 0, 1));

	_layer3D->addChild(line);

	_layer3D->setCameraMask(2);

	//////////////////////////////////////////////////////////////////////////

	_textureCube = TextureCube::create("Sprite3DTest/skybox/left.jpg",
		"Sprite3DTest/skybox/right.jpg",
		"Sprite3DTest/skybox/top.jpg",
		"Sprite3DTest/skybox/bottom.jpg",
		"Sprite3DTest/skybox/front.jpg",
		"Sprite3DTest/skybox/back.jpg");
	//set texture parameters
	Texture2D::TexParams tRepeatParams;
	tRepeatParams.magFilter = GL_LINEAR;
	tRepeatParams.minFilter = GL_LINEAR;
	tRepeatParams.wrapS = GL_MIRRORED_REPEAT;
	tRepeatParams.wrapT = GL_MIRRORED_REPEAT;
	_textureCube->setTexParameters(tRepeatParams);

	// pass the texture sampler to our custom shader
	//state->setUniformTexture("u_cubeTex", _textureCube);

	// add skybox
	_skyBox = Skybox::create();
	_skyBox->setCameraMask(2);
	_skyBox->setTexture(_textureCube);
	_skyBox->setScale(700.f);

	// create terrain
	Terrain::DetailMap r("TerrainTest/dirt.jpg");
	Terrain::DetailMap g("TerrainTest/Grass2.jpg", 10);
	Terrain::DetailMap b("TerrainTest/road.jpg");
	Terrain::DetailMap a("TerrainTest/GreenSkin.jpg", 20);
	Terrain::TerrainData data("TerrainTest/heightmap16.jpg",
		"TerrainTest/alphamap.png",
		r, g, b, a, Size(32, 32), 40.0f, 2);
	_terrain = Terrain::create(data, Terrain::CrackFixedType::SKIRT);
	_terrain->setMaxDetailMapAmount(4);
	_terrain->setDrawWire(false);

	_terrain->setSkirtHeightRatio(3);
	_terrain->setLODDistance(64, 128, 192);

	_terrain->setCameraMask(2);

	// create two Sprite3D monster, one is transparent
	auto monster = Sprite3D::create("Sprite3DTest/orc.c3b");
	monster->setRotation3D(Vec3(0, 180, 0));
	monster->setPosition3D(Vec3(50, -10, 0));
	monster->setOpacity(128);
	monster->setCameraMask(2);
	_monsters[0] = monster;
	monster = Sprite3D::create("Sprite3DTest/orc.c3b");
	monster->setRotation3D(Vec3(0, 180, 0));
	monster->setPosition3D(Vec3(-50, -5, 0));
	monster->setCameraMask(2);
	_monsters[1] = monster;


	_layer3D->addChild(_skyBox);
	_layer3D->addChild(_terrain);
	_layer3D->addChild(_monsters[0]);
	_layer3D->addChild(_monsters[1]);

	//addNewSpriteWithCoords(Vec3(50, 0, 0), "Sprite3DTest/girl.c3b", false, 0.2f, false);

	_keyRecord = new KeyboardRecord(this);
	_cameraView = new CameraView(_camera, _sprite3D);

	return true;
}

void Scene3d::addNewSpriteWithCoords(Vec3 p, std::string fileName, bool playAnimation, float scale, bool bindCamera)
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

void Scene3d::SwitchViewCallback(Ref* sender, CameraType cameraType)
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

void Scene3d::onTouchesBegan(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	for (auto &item : touches)
	{
		auto touch = item;
		auto location = touch->getLocation();
	}
}
void Scene3d::onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	if (touches.size() == 1)
	{
		auto touch = touches[0];
		auto location = touch->getLocation();
		Point newPos = touch->getPreviousLocation() - location;
		if (_cameraType == CameraType::Free || _cameraType == CameraType::FirstPerson)
		{
			Vec3 cameraDir;
			Vec3 cameraRightDir;
			_camera->getNodeToWorldTransform().getForwardVector(&cameraDir);
			cameraDir.normalize();
			cameraDir.y = 0;
			_camera->getNodeToWorldTransform().getRightVector(&cameraRightDir);
			cameraRightDir.normalize();
			cameraRightDir.y = 0;
			Vec3 cameraPos = _camera->getPosition3D();
			cameraPos += cameraDir*newPos.y*0.1f;
			cameraPos += cameraRightDir*newPos.x*0.1f;
			_camera->setPosition3D(cameraPos);
			if (_sprite3D &&  _cameraType == CameraType::FirstPerson)
			{
				_sprite3D->setPosition3D(Vec3(_camera->getPositionX(), 0, _camera->getPositionZ()));
				_targetPos = _sprite3D->getPosition3D();
			}
		}
	}
}

void Scene3d::onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	for (auto &item : touches)
	{
		auto touch = item;
		auto location = touch->getLocationInView();
		if (_camera)
		{
			if (_sprite3D && _cameraType == CameraType::ThirdPerson && _bZoomOut == false && _bZoomIn == false && _bCameraUp == false && _bCameraDown == false)
			{
				Vec3 nearP(location.x, location.y, -1.0f), farP(location.x, location.y, 1.0f);

				auto size = Director::getInstance()->getWinSize();
				nearP = _camera->unproject(nearP);
				farP = _camera->unproject(farP);
				Vec3 dir(farP - nearP);
				float dist = 0.0f;
				float ndd = Vec3::dot(Vec3(0, 1, 0), dir);
				if (ndd == 0)
					dist = 0.0f;
				float ndo = Vec3::dot(Vec3(0, 1, 0), nearP);
				dist = (0 - ndo) / ndd;
				Vec3 p = nearP + dist *  dir;

				if (p.x > 100)
					p.x = 100;
				if (p.x < -100)
					p.x = -100;
				if (p.z > 100)
					p.z = 100;
				if (p.z < -100)
					p.z = -100;

				_targetPos = p;
			}
		}
	}
}

bool Scene3d::onTouchesCommon(Touch* touch, Event* event, bool* touchProperty)
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

bool Scene3d::onTouchesZoomOut(Touch* touch, Event* event)
{
	return Scene3d::onTouchesCommon(touch, event, &_bZoomOut);
}
void Scene3d::onTouchesZoomOutEnd(Touch* touch, Event* event)
{
	_bZoomOut = false;
}
bool Scene3d::onTouchesZoomIn(Touch* touch, Event* event)
{
	return Scene3d::onTouchesCommon(touch, event, &_bZoomIn);
}
void Scene3d::onTouchesZoomInEnd(Touch* touch, Event* event)
{
	_bZoomIn = false;
}

bool Scene3d::onTouchesCameraUp(Touch* touch, Event* event)
{
	return Scene3d::onTouchesCommon(touch, event, &_bCameraUp);
}
void Scene3d::onTouchesCameraUpEnd(Touch* touch, Event* event)
{
	_bCameraUp = false;
}
bool Scene3d::onTouchesCameraDown(Touch* touch, Event* event)
{
	return Scene3d::onTouchesCommon(touch, event, &_bCameraDown);
}
void Scene3d::onTouchesCameraDownEnd(Touch* touch, Event* event)
{
	_bCameraDown = false;
}

void Scene3d::updateCamera(float fDelta)
{
// 	if (_sprite3D)
// 	{
// 		if (_cameraType == CameraType::ThirdPerson)
// 		{
// 			updateState(fDelta);
// 			if (isState(_curState, State_Move))
// 			{
// 				move3D(fDelta);
// 				if (isState(_curState, State_Rotate))
// 				{
// 					Vec3 curPos = _sprite3D->getPosition3D();
// 
// 					Vec3 newFaceDir = _targetPos - curPos;
// 					newFaceDir.y = 0;
// 					newFaceDir.normalize();
// 					Vec3 up;
// 					_sprite3D->getNodeToWorldTransform().getUpVector(&up);
// 					up.normalize();
// 					Vec3 right;
// 					Vec3::cross(-newFaceDir, up, &right);
// 					right.normalize();
// 					Vec3 pos = Vec3(0, 0, 0);
// 					Mat4 mat;
// 					mat.m[0] = right.x;
// 					mat.m[1] = right.y;
// 					mat.m[2] = right.z;
// 					mat.m[3] = 0.0f;
// 
// 					mat.m[4] = up.x;
// 					mat.m[5] = up.y;
// 					mat.m[6] = up.z;
// 					mat.m[7] = 0.0f;
// 
// 					mat.m[8] = newFaceDir.x;
// 					mat.m[9] = newFaceDir.y;
// 					mat.m[10] = newFaceDir.z;
// 					mat.m[11] = 0.0f;
// 
// 					mat.m[12] = pos.x;
// 					mat.m[13] = pos.y;
// 					mat.m[14] = pos.z;
// 					mat.m[15] = 1.0f;
// 					_sprite3D->setAdditionalTransform(&mat);
// 				}
// 			}
// 		}
// 		if (_bZoomOut == true)
// 		{
// 			if (_camera)
// 			{
// 				if (_cameraType == CameraType::ThirdPerson)
// 				{
// 					Vec3 lookDir = _camera->getPosition3D() - _sprite3D->getPosition3D();
// 					Vec3 cameraPos = _camera->getPosition3D();
// 					if (lookDir.length() <= 300)
// 					{
// 						cameraPos += lookDir.getNormalized();
// 						_camera->setPosition3D(cameraPos);
// 					}
// 				}
// 				else if (_cameraType == CameraType::Free)
// 				{
// 					Vec3 cameraPos = _camera->getPosition3D();
// 					if (cameraPos.length() <= 300)
// 					{
// 						cameraPos += cameraPos.getNormalized();
// 						_camera->setPosition3D(cameraPos);
// 					}
// 				}
// 			}
// 		}
// 		if (_bZoomIn == true)
// 		{
// 			if (_camera)
// 			{
// 				if (_cameraType == CameraType::ThirdPerson)
// 				{
// 					Vec3 lookDir = _camera->getPosition3D() - _sprite3D->getPosition3D();
// 					Vec3 cameraPos = _camera->getPosition3D();
// 					if (lookDir.length() >= 50)
// 					{
// 						cameraPos -= lookDir.getNormalized();
// 						_camera->setPosition3D(cameraPos);
// 					}
// 				}
// 				else if (_cameraType == CameraType::Free)
// 				{
// 					Vec3 cameraPos = _camera->getPosition3D();
// 					if (cameraPos.length() >= 50)
// 					{
// 						cameraPos -= cameraPos.getNormalized();
// 						_camera->setPosition3D(cameraPos);
// 					}
// 				}
// 			}
// 		}
// 		if (_bRotateLeft == true)
// 		{
// 			if (_cameraType == CameraType::Free || _cameraType == CameraType::FirstPerson)
// 			{
// 				NodeRotate(_camera, 1);
// 			}
// 		}
// 		if (_bRotateRight == true)
// 		{
// 			if (_cameraType == CameraType::Free || _cameraType == CameraType::FirstPerson)
// 			{
// 				NodeRotate(_camera, -1);
// 			}
// 		}
// 	}

	auto cameraFllow = [this]() 
	{
// 		auto lookPos = _sprite3D->getPosition3D();
// 		float distance = 0;
// 		float height = 0;
// 		if (CameraType::FirstPerson == _cameraType)
// 		{
// 			distance = -0.1;
// 			height = 40;
// 			lookPos.y = height;
// 			
// 		}
// 		else if (CameraType::ThirdPerson == _cameraType)
// 		{
// 			distance = -150;
// 			height = 150;
// 		}
// 		
// 		NodeFollow(_camera, _sprite3D, distance, height);
// 		_camera->lookAt(lookPos);

		_cameraView->Update();
	};

	auto diff = ccp(0, 0);
	float diffValue = 5;
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_W))
	{
		NodeFoward(_sprite3D, 1);
		cameraFllow();
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_S))
	{
		NodeFoward(_sprite3D, -1);
		cameraFllow();
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_A))
	{
		NodeRotate(_sprite3D, 5);
		cameraFllow();
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_D))
	{
		NodeRotate(_sprite3D, -5);
		cameraFllow();
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_Q))
	{
		NodeShift(_sprite3D, 1);
		cameraFllow();
	}
	if (_keyRecord->IsPress(EventKeyboard::KeyCode::KEY_E))
	{
		NodeShift(_sprite3D, -1);
		cameraFllow();
	}
	if (_bZoomIn) 
	{
		_cameraView->Zoom(-1);
	}
	if (_bZoomOut)
	{
		_cameraView->Zoom(1);
	}
	if (_bCameraUp)
	{
		_cameraView->Rise(1);
	}
	if (_bCameraDown)
	{
		_cameraView->Rise(-1);
	}

}


void Scene3d::move3D(float elapsedTime)
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
void Scene3d::updateState(float elapsedTime)
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

bool Scene3d::isState(unsigned int state, unsigned int bit) const
{
	return (state & bit) == bit;
}

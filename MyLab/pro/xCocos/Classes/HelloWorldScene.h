#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

enum State
{
	State_None = 0,
	State_Idle = 0x01,
	State_Move = 0x02,
	State_Rotate = 0x04,
	State_Speak = 0x08,
	State_MeleeAttack = 0x10,
	State_RemoteAttack = 0x20,
	State_Attack = 0x40,
};
enum class CameraType
{
	Free = 0,
	FirstPerson = 1,
	ThirdPerson = 2,

};

class VisibleRect
{
public:
	static cocos2d::Rect getVisibleRect();

	static cocos2d::Vec2 left();
	static cocos2d::Vec2 right();
	static cocos2d::Vec2 top();
	static cocos2d::Vec2 bottom();
	static cocos2d::Vec2 center();
	static cocos2d::Vec2 leftTop();
	static cocos2d::Vec2 rightTop();
	static cocos2d::Vec2 leftBottom();
	static cocos2d::Vec2 rightBottom();
private:
	static void lazyInit();
	static cocos2d::Rect s_visibleRect;
};

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	virtual void update(float delta);

	void myUpdate(float delta);

	bool touchBegin(cocos2d::CCTouch * touch, cocos2d::CCEvent *event);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

public:
	cocos2d::Node* m_rootNode;
	cocos2d::Node* m_sprite;
	cocos2d::Vec2 m_centerPos;
	cocos2d::Node* m_rootNode2;
	bool m_bW;
	bool m_bS;
	bool m_bA;
	bool m_bD;


public:
	void updateCamera(float fDelta);
	void move3D(float elapsedTime);
	void updateState(float elapsedTime);
	bool isState(unsigned int state, unsigned int bit) const;

	void addNewSpriteWithCoords(cocos2d::Vec3 p, std::string fileName, bool playAnimation = false, float scale = 1.0f, bool bindCamera = false);
	void SwitchViewCallback(cocos2d::Ref* sender, CameraType cameraType);

	bool onTouchesCommon(cocos2d::Touch* touch, cocos2d::Event* event, bool* touchProperty);
	bool onTouchesZoomOut(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesZoomOutEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchesZoomIn(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesZoomInEnd(cocos2d::Touch* touch, cocos2d::Event* event);

	bool onTouchesRotateLeft(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesRotateLeftEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchesRotateRight(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesRotateRightEnd(cocos2d::Touch* touch, cocos2d::Event* event);

	std::string    _title;
	cocos2d::Layer*         _layer3D;
	cocos2d::Sprite3D*      _sprite3D;
	cocos2d::Vec3           _targetPos;
	CameraType     _cameraType;
	cocos2d::MenuItem*      _incRot;
	cocos2d::MenuItem*      _decRot;
	unsigned int   _curState;
	cocos2d::Camera*      _camera;
	cocos2d::MoveTo* _moveAction;
	bool _bZoomOut;
	bool _bZoomIn;
	bool _bRotateLeft;
	bool _bRotateRight;
	cocos2d::Label* _RotateRightlabel;
	cocos2d::Label* _RotateLeftlabel;
	cocos2d::Label* _ZoomInlabel;
	cocos2d::Label* _ZoomOutlabel;


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

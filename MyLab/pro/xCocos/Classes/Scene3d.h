#pragma once

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Logic.h"

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

class Scene3d : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

public:
	void updateCamera(float fDelta);
	void move3D(float elapsedTime);
	void updateState(float elapsedTime);
	bool isState(unsigned int state, unsigned int bit) const;

	void addNewSpriteWithCoords(cocos2d::Vec3 p, std::string fileName, bool playAnimation = false, float scale = 1.0f, bool bindCamera = false);
	void SwitchViewCallback(cocos2d::Ref* sender, CameraType cameraType);

	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);
	void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);

	bool onTouchesCommon(cocos2d::Touch* touch, cocos2d::Event* event, bool* touchProperty);
	bool onTouchesZoomOut(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesZoomOutEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchesZoomIn(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesZoomInEnd(cocos2d::Touch* touch, cocos2d::Event* event);

	bool onTouchesCameraUp(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesCameraUpEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchesCameraDown(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchesCameraDownEnd(cocos2d::Touch* touch, cocos2d::Event* event);

	std::string    _title;
	cocos2d::Layer*         _layer3D;
	cocos2d::Sprite3D*      _sprite3D;
	cocos2d::Vec3           _targetPos;
	CameraType     _cameraType;
	cocos2d::MenuItem*      _incRot;
	cocos2d::MenuItem*      _decRot;
	unsigned int   _curState;
	cocos2d::Camera*      _camera;
	cocos2d::Camera*      _testCamera;
	cocos2d::MoveTo* _moveAction;
	bool _bZoomOut    = false;
	bool _bZoomIn     = false;
	bool _bCameraUp   = false ;
	bool _bCameraDown = false;
	cocos2d::Label* _RotateRightlabel;
	cocos2d::Label* _RotateLeftlabel;
	cocos2d::Label* _ZoomInlabel;
	cocos2d::Label* _ZoomOutlabel;

	KeyboardRecord* _keyRecord;
	CameraView* _cameraView;
	CameraView* _testCameraView;

public:
	// init in init()
	std::vector<cocos2d::Camera *> _gameCameras;
	cocos2d::Node* _worldScene;
	cocos2d::Node* _dlgScene;
	cocos2d::Node* _osdScene;

	// init in createWorld3D()
	cocos2d::TextureCube*        _textureCube;
	cocos2d::Skybox*             _skyBox;
	cocos2d::Terrain*   _terrain;
	//Player *            _player;
	cocos2d::Node*               _monsters[2];

	// init in createUI()
	cocos2d::Node* _playerItem;
	cocos2d::Node* _detailItem;
	cocos2d::Node* _descItem;
	cocos2d::Node* _ui;

	// init in createPlayerDlg()
	cocos2d::Node* _playerDlg;
	// init in createDetailDlg()
	cocos2d::Node* _detailDlg;
	// init in createDescDlg()
	cocos2d::Node* _descDlg;
	enum SkinType
	{
		HAIR = 0,
		GLASSES,
		FACE,
		UPPER_BODY,
		HAND,
		PANTS,
		SHOES,
		MAX_TYPE,
	};

	std::vector<std::string> _skins[(int)SkinType::MAX_TYPE]; //all skins
	int                      _curSkin[(int)SkinType::MAX_TYPE]; //current skin index
	cocos2d::Sprite3D* _reskinGirl;

	// for capture screen
	static const int SNAPSHOT_TAG = 119;
	std::string _snapshotFile;

	// implement the "static create()" method manually
	CREATE_FUNC(Scene3d);
};


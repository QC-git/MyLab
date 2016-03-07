#pragma once

#include "cocos2d.h"

#include "Sprite3DTest/DrawNode3D.h"

void LogicMain();

//2D

#define ARC(x) ((float)(3.1415926*(x)/180.0))

#define LOG(fmt, ...)    printf("\n\n[LOG] "fmt" \n", __VA_ARGS__)

void FollowNode(cocos2d::CCNode* node, cocos2d::CCNode* superNode, cocos2d::Vec2& diff);

void CenterNode(cocos2d::CCNode* node, cocos2d::CCNode* superNode, cocos2d::Vec2& center);

class KeyboardRecord
{
public:
	KeyboardRecord(cocos2d::CCNode* node);
	~KeyboardRecord() {};

	bool IsPress(cocos2d::EventKeyboard::KeyCode keyCode);

private:
	char _flags[(int)(cocos2d::EventKeyboard::KeyCode::KEY_PLAY)];
};


//3D

void DrawGrid(cocos2d::DrawNode3D* drawNode, cocos2d::Vec3& anchor, int gridNum, float gridLength);

void NodeRotate(cocos2d::CCNode* node, float value);

void NodeFoward(cocos2d::CCNode* node, float value);

void NodeShift(cocos2d::CCNode* node, float value);

class CameraView
{
public:
	CameraView(cocos2d::Camera* camera, cocos2d::CCNode* node);
	~CameraView() {};

	void Rise(float angle);
	void Zoom(float distance);

	void Move(cocos2d::Vec3 dir, float value = 1);

	void Update();

private:
	cocos2d::Camera* _camera;
	cocos2d::CCNode* _node;
	float _d1, _d2, _angle, _offset;

};


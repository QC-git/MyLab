#pragma once

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Logic.h"

class Scene2d : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	virtual ~Scene2d();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	virtual void update(float delta);

	void myUpdate(float delta);

public:
	cocos2d::Node* m_rootNode;
	cocos2d::Node* m_sprite;
	cocos2d::Vec2 m_centerPos;
	cocos2d::Node* m_rootNode2;
	bool m_bW;
	bool m_bS;
	bool m_bA;
	bool m_bD;

	KeyboardRecord* _keyRecord;

	// implement the "static create()" method manually
	CREATE_FUNC(Scene2d);
};
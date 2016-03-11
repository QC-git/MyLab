
#include "Logic.h"


USING_NS_CC;

void LogicMain()
{

}

void FollowNode(cocos2d::CCNode* node, cocos2d::CCNode* superNode, cocos2d::Vec2& diff)
{
	auto pos = node->getPosition() + diff;
	auto superPos = superNode->getPosition() - diff;
	node->setPosition(pos);
	superNode->setPosition(superPos);
}

void CenterNode(cocos2d::CCNode* node, cocos2d::CCNode* superNode, cocos2d::Vec2& center)
{
// 	auto pos = node->getPosition();  // center 和 pos 需要同一坐标系
// 	auto pos2 = superNode->convertToWorldSpace(pos);
// 	auto diff = pos2 - center;   // pos2 = center + diff
// 	auto superPos = superNode->getPosition() - diff;
// 	superNode->setPosition(superPos);

	auto pos = node->getPosition();  // center 和 pos 需要同一坐标系
	auto centerPos = node->getParent()->convertToNodeSpace(center);
	auto diff = pos - centerPos;   // pos2 = center + diff
	auto superPos = superNode->getPosition() - diff;
	superNode->setPosition(superPos);
}
	
KeyboardRecord::KeyboardRecord(cocos2d::CCNode* node)
{
	memset(_flags, 0, sizeof(_flags));

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event)
	{
		_flags[(int)keyCode] = 1;
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		_flags[(int)keyCode] = 0;
	};

	auto eventDispatcher = node->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, node);
}

bool KeyboardRecord::IsPress(cocos2d::EventKeyboard::KeyCode keyCode)
{
	return (bool)_flags[(int)keyCode];
}

void DrawGrid(cocos2d::DrawNode3D* drawNode, cocos2d::Vec3& anchor, int gridNum, float gridLength)
{
	float lineLength = gridNum * gridLength;

	//draw x
	Vec3 start = anchor;
	Vec3 end = anchor;
	end.x += lineLength;
	for (int j = 0; j <= gridNum; j++)
	{
		drawNode->drawLine(start, end, Color4F(1, 0, 0, 1));
		start.z += gridLength;
		end.z += gridLength;
	}
	//draw z
	start = anchor;
	end = anchor;
	end.z += lineLength;
	for (int j = 0; j <= gridNum; j++)
	{
		drawNode->drawLine(start, end, Color4F(0, 0, 1, 1));
		start.x += gridLength;
		end.x += gridLength;
	}
}

void DrawCoordinateSystem(cocos2d::DrawNode3D* drawNode, float length)
{
	float a = 0;
	float b = length;
	drawNode->drawLine(Vec3(a, 0, 0), Vec3(b, 0, 0), Color4F(1, 0, 0, 1));  //x轴
	drawNode->drawLine(Vec3(0, a, 0), Vec3(0, b, 0), Color4F(0, 1, 0, 1));  //y轴
	drawNode->drawLine(Vec3(0, 0, a), Vec3(0, 0, b), Color4F(0, 0, 1, 1));  //z轴

	int num = (int)length;
	for (int i = 1; i <= num; i++)
	{
		drawNode->drawLine(Vec3(i, -1, 0), Vec3(i, 1, 0), Color4F(1, 1, 1, 1));  //x轴刻度
		drawNode->drawLine(Vec3(-1, i, 0), Vec3(1, i, 0), Color4F(1, 1, 1, 1));  //y轴刻度
	}

	for (float i = 0.1; i <= 0.9;)
	{
		drawNode->drawLine(Vec3(i, -1, 0), Vec3(i, 1, 0), Color4F(1, 1, 1, 1));  //x轴刻度
		drawNode->drawLine(Vec3(-1, i, 0), Vec3(1, i, 0), Color4F(1, 1, 1, 1));  //y轴刻度

		i += 0.1;
	}

}

//////////////////////////////////////////////////////////////////////////

cocos2d::Vec3 CalcMoveDir(cocos2d::Vec3 pos, cocos2d::Vec3 rot, float distance, float angle = 0)
{
	angle = angle + rot.y;
	float rad = ARC(angle);

	float x = distance * sin(rad);
	float z = distance * cos(rad);
	x += pos.x;
	z += pos.z;

	return Vec3(x, 0, z);
}

cocos2d::Vec3 CalcVector(float a1, float a2, float value)
{
	if ( 0 == value )
	{
		return Vec3(0, 0, 0);
	}

	float xy = value * cos(ARC(a2));
	float z = value * sin(ARC(a2));
	float y = xy * sin(ARC(a1));
	float x = xy * cos(ARC(a1));

	return Vec3(x, y, z);
}

cocos2d::Vec3 ChangeCoordinateSystem(cocos2d::Vec3& pos)
{
	return Vec3(pos.y, pos.z, pos.x);
}

cocos2d::Vec3 CalcVectorEx(float a1, float a2, float value)
{
	auto vector = CalcVector(a1, a2, value);
	return ChangeCoordinateSystem(vector);
}

cocos2d::Vec3 CalcNodePositon(cocos2d::Node* node, float horizontalAngle, float verticalAngle, float value)
{
	auto rot = node->getRotation3D();
	auto pos = node->getPosition3D();
	auto vector = CalcVectorEx(rot.y + horizontalAngle, verticalAngle, value);
	return pos + vector;
}

void NodeRotate(cocos2d::CCNode* node, float value)
{ 
	auto rotation3D = node->getRotation3D();  //printf("\n rotation3D.y = %.2f \n", rotation3D.y);
	rotation3D.y += value;
	node->setRotation3D(rotation3D);
}

void NodeFoward(cocos2d::CCNode* node, float value)
{
	auto pos = CalcNodePositon(node, 0, 0, value);
	node->setPosition3D(pos);
}

void NodeShift(cocos2d::CCNode* node, float value)
{
	auto pos = CalcNodePositon(node, 90, 0, value);
	node->setPosition3D(pos);
}

CameraView::CameraView(cocos2d::Camera* camera, cocos2d::CCNode* node)
	: _camera(camera)
	, _node(node)
{
	_d1 = 100;
	_d2 = 100;
	_angle = 45;
	_offset = 20;

	Update();
}

void CameraView::Rise(float angle)
{
	float a = _angle + angle;
	if (a >= 90 || a <= -90)
	{
		return;
	}
	_angle = a;
	Update();
}

void CameraView::Zoom(float distance)
{
	float d = _d1 + distance;
	if ( d > 300 || d < -10 )
	{
		return;
	}
	_d1 = d;
	Update();
}

void CameraView::Move(cocos2d::Vec2 screenPos1, cocos2d::Vec2 screenPos2)
{
	auto movePos1 = _camera->unprojectGL(Vec3(screenPos1.x, screenPos1.y, 0));
	auto movePos2 = _camera->unprojectGL(Vec3(screenPos2.x, screenPos2.y, 0));
	auto moveDir = movePos2 - movePos1;  //LOG("x = %.5f, y = %.5f, z = %.5f", moveDir.x, moveDir.y, moveDir.z);
	auto moveDir2 = moveDir * (_d1 + _d2);  

	auto cameraPos = _camera->getPosition3D();
	auto lookDir = _lookPos - cameraPos;
	auto lookDir2 = lookDir + moveDir2;

	auto lookPos = cameraPos + lookDir2;
	_camera->lookAt(lookPos);
	_lookPos = lookPos;

}

void CameraView::MoveNode(cocos2d::Vec2 screenPos)
{
	auto pos = _camera->unprojectGL(Vec3(screenPos.x, screenPos.y, 0));
	auto dir = pos - _camera->getPosition3D();

	float a = dir.x;
	float b = dir.y;
	float c = dir.z;

	float x0 = pos.x;
	float y0 = pos.y;
	float z0 = pos.z;

	float k1 = a / b;
	float k2 = c / b;

	float y = 0;
	float x = (y - y0) * k1 + x0;
	float z = (y - y0) * k2 + z0;

	_node->setPosition3D(Vec3(x, y, z));

}

void CameraView::Update()
{
	if (!_node)
	{
		return;
	}

	auto cameraPos = CalcNodePositon(_node, 0, -_angle, -_d1);
	auto lookPos = CalcNodePositon(_node, 0, -_angle, _d2);

	cameraPos.y += _offset;
	lookPos.y += _offset;

	_camera->setPosition3D(cameraPos);
	_camera->lookAt(lookPos);

	_lookPos = lookPos;
}


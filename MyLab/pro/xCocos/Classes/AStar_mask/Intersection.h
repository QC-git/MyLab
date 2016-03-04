#pragma once

#include "rts/vec.h"
#include <vector>
class CIntersection
{
public:
	CIntersection(void);
	~CIntersection(void);

public:
	// 判断线段与长方形是否相交
	static bool IntersectOfSegmentAndBox(Vec2f s0, Vec2f s1, Vec2f vBox0, Vec2f vBox1, Vec2f vBox2, Vec2f vBox3);

	static bool IntersectionOfAABBAndAABB(const Vec2f& vMin0, const Vec2f& vMax0, const Vec2f& vMin1, const Vec2f& vMax1, Vec2f* pMin, Vec2f* pMax);

	static bool IntersectionOfSegmentAndAABBWire(const Vec2f& vRayOrg, const Vec2f& vRayDir, const Vec2f& vMin, const Vec2f& vMax, Vec2f& vIntersection);

	//计算一个点是否在一个多边形内
	static bool PtInPolygon(const Vec2f& vPoint, std::vector<Vec2f> ptPolygon);
private:
	// 判断线段与线段是否相交
	static bool IntersectOfSegmentAndSegment(Vec2f v0, Vec2f v1, Vec2f v2, Vec2f v3);

	// 返回0，不相交；返回1，只有一个交点；返回2，两线段重叠并且交集是线段本身，返回值vIntersection是有效元素。
	static int Segments2DIntersection(Vec2f p0, Vec2f d0, Vec2f p1, Vec2f d1, Vec2f vIntersection[2]);

	// 用于计算两个区间[u0,u1] [v0,v1]的相交，其中u0<u1, v0<v1
	// 如果不相交， 返回0
	// 如果只有一个交点返回1，此时w[0]包含该点
	// 如果相交于一个区间，则返回2，区间的端点保存在w[0] w[1]中
	static int FindIntersection(float u0, float u1, float v0, float v1, float w[2]);
};

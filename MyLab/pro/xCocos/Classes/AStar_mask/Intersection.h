#pragma once

#include "rts/vec.h"
#include <vector>
class CIntersection
{
public:
	CIntersection(void);
	~CIntersection(void);

public:
	// �ж��߶��볤�����Ƿ��ཻ
	static bool IntersectOfSegmentAndBox(Vec2f s0, Vec2f s1, Vec2f vBox0, Vec2f vBox1, Vec2f vBox2, Vec2f vBox3);

	static bool IntersectionOfAABBAndAABB(const Vec2f& vMin0, const Vec2f& vMax0, const Vec2f& vMin1, const Vec2f& vMax1, Vec2f* pMin, Vec2f* pMax);

	static bool IntersectionOfSegmentAndAABBWire(const Vec2f& vRayOrg, const Vec2f& vRayDir, const Vec2f& vMin, const Vec2f& vMax, Vec2f& vIntersection);

	//����һ�����Ƿ���һ���������
	static bool PtInPolygon(const Vec2f& vPoint, std::vector<Vec2f> ptPolygon);
private:
	// �ж��߶����߶��Ƿ��ཻ
	static bool IntersectOfSegmentAndSegment(Vec2f v0, Vec2f v1, Vec2f v2, Vec2f v3);

	// ����0�����ཻ������1��ֻ��һ�����㣻����2�����߶��ص����ҽ������߶α�������ֵvIntersection����ЧԪ�ء�
	static int Segments2DIntersection(Vec2f p0, Vec2f d0, Vec2f p1, Vec2f d1, Vec2f vIntersection[2]);

	// ���ڼ�����������[u0,u1] [v0,v1]���ཻ������u0<u1, v0<v1
	// ������ཻ�� ����0
	// ���ֻ��һ�����㷵��1����ʱw[0]�����õ�
	// ����ཻ��һ�����䣬�򷵻�2������Ķ˵㱣����w[0] w[1]��
	static int FindIntersection(float u0, float u1, float v0, float v1, float w[2]);
};

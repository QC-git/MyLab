#include "Intersection.h"
#include "inttypes.h"

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

CIntersection::CIntersection(void)
{
}

CIntersection::~CIntersection(void)
{
}

bool CIntersection::IntersectOfSegmentAndBox(Vec2f s0, Vec2f s1, Vec2f vBox0, Vec2f vBox1, Vec2f vBox2, Vec2f vBox3)
{
	if (IntersectOfSegmentAndSegment(s0, s1, vBox0, vBox1))
	{
		return true;
	}

	if (IntersectOfSegmentAndSegment(s0, s1, vBox1, vBox2))
	{
		return true;
	}

	if (IntersectOfSegmentAndSegment(s0, s1, vBox2, vBox3))
	{
		return true;
	}

	if (IntersectOfSegmentAndSegment(s0, s1, vBox3, vBox0))
	{
		return true;
	}

	return false;
}

bool CIntersection::IntersectOfSegmentAndSegment(Vec2f v0, Vec2f v1, Vec2f v2, Vec2f v3)
{
	Vec2f vIntersect[2];
	if (CIntersection::Segments2DIntersection(v0, v1-v0, v2, v3-v2, vIntersect) > 0)
	{
		return true;
	}

	return false;
}


// ����0�����ཻ������1��ֻ��һ�����㣻����2�����߶��ص����ҽ������߶α�������ֵvIntersection����ЧԪ�ء�
// ��|kross(d0,d1)| / (|d0|*|d1|) = sinA <= 0.00001�� ��ƽ��
// s*(d0��d1)*(d0��d1) = ((p1-p0)��d1) * (d0��d1) => s = ((p1-p0)��d1) / (d0��d1)
// t*(d0��d1)*(d0��d1) = ((p1-p0)��d0) * (d0��d1) => t = ((p1-p0)��d0) / (d0��d1)
int CIntersection::Segments2DIntersection(Vec2f p0, Vec2f d0, Vec2f p1, Vec2f d1,  Vec2f vIntersection[2])
{
	// segments p0+s*d0 for s in [0,1], p1+t*d1 for t in [0,1]
	const float epsilon = 0.0001f;
	const float sqrEpsilon = epsilon*epsilon;

	Vec2f e = p1 - p0;
	float kross = d0.x*d1.y - d0.y*d1.x;//���
	float sqrKross = kross*kross;//�����ƽ��
	float sqrLen0 = d0.x*d0.x+d0.y*d0.y;
	float sqrLen1 = d1.x*d1.x+d1.y*d1.y;
	if (sqrKross > sqrEpsilon*sqrLen0*sqrLen1)//��ֱ�߲�ƽ��
	{
		float s = (e.x*d1.y - e.y*d1.x) / kross;
		if (s < 0 || s > 1)// ���㲻���߶�p0+s*d0 ��
		{
			return 0;
		}

		float t = (e.x*d0.y - e.y*d0.x) / kross;
		if (t < 0 || t > 1)// ���㲻���߶�p1+t*d1��
		{
			return 0;
		}

		vIntersection[0] = p0+d0*s;//��ý���
		return 1;
	}

	// ��ֱ��ƽ��

	// �ж�����p0p1 ������d0�Ƿ�ƽ��
	float sqrLenE = e.x*e.x + e.y*e.y;
	kross = e.x*d0.y - e.y*d0.x;
	sqrKross = kross*kross;
	if (sqrKross > sqrEpsilon*sqrLen0*sqrLenE)//����p0p1 ������d0 ��ƽ��
	{
		// ˵��d0 d1����ͬһ��ֱ����
		return 0;
	}

	// d0 d1��ͬһ��ֱ����
	float s0 = d0.dot(e) / sqrLen0;
	float s1 = s0 + d0.dot(d1)/sqrLen0;
	float w[2];
	float smin = min(s0, s1);
	float smax = max(s0, s1);

	int nMax = FindIntersection(0.0, 1.0, smin, smax, w);
	for (int i = 0;i< nMax;i++)
	{
		vIntersection[i] = p0 + d0*w[i];
	}
	return nMax;
}


// ���ڼ�����������[u0,u1] [v0,v1]���ཻ������u0<u1, v0<v1
// ������ཻ�� ����0
// ���ֻ��һ�����㷵��1����ʱw[0]�����õ�
// ����ཻ��һ�����䣬�򷵻�2������Ķ˵㱣����w[0] w[1]��
int CIntersection::FindIntersection(float u0, float u1, float v0, float v1, float w[2])
{
	//    u0-------------->u1
	// v0--->v1
	if (u1 < v0 || u0 > v1)
	{
		return 0;
	}

	if (u1 > v0)
	{
		if (u0 < v1)
		{
			if (u0<v0) 
				w[0]=v0;
			else 
				w[0]=u0;

			if (u1>v1) 
				w[1]=v1;
			else 
				w[1]=u1;

			return 2;
		}
		else
		{
			// u0 == v1
			w[0]=u0;
			return 1;
		}
	}
	else
	{
		//u1 == v0
		w[0] = u1;
		return 1;
	}
}
// 
// // ������AABB�ཻ
// // vRayDir�����ߵĳ��Ⱥͷ���
// // pReturnNormal�����ཻ��ķ�����
// bool CIntersection::IntersectionOfRayAndAABB(const D3DXVECTOR3& vRayOrg, const D3DXVECTOR3& vRayDir, const D3DXVECTOR3& vMin, const D3DXVECTOR3& vMax, float& fParametric, D3DXVECTOR3* pReturnNormal)
// {
// 	// Check for point inside box, trivial reject, and determine parametric distance to each front face.
// 	bool inside = true;
// 
// 	float xt, xn;
// 
// 	if (vRayOrg.x < vMin.x) 
// 	{
// 		xt = vMin.x - vRayOrg.x;
// 		if (xt > vRayDir.x) 
// 			return false;
// 
// 		xt /= vRayDir.x;
// 		inside = false;
// 		xn = -1.0f;
// 	} 
// 	else if (vRayOrg.x > vMax.x) 
// 	{
// 		xt = vMax.x - vRayOrg.x;
// 		if (xt < vRayDir.x) 
// 			return false;
// 
// 		xt /= vRayDir.x;
// 		inside = false;
// 		xn = 1.0f;
// 	} 
// 	else
// 		xt = -1.0f;    
// 
// 	float yt, yn;
// 
// 	if (vRayOrg.y < vMin.y) 
// 	{
// 		yt = vMin.y - vRayOrg.y;
// 		if (yt > vRayDir.y) 
// 			return false;
// 
// 		yt /= vRayDir.y;
// 		inside = false;
// 		yn = -1.0f;
// 	} 
// 	else if (vRayOrg.y > vMax.y) 
// 	{
// 		yt = vMax.y - vRayOrg.y;
// 		if (yt < vRayDir.y) 
// 			return false;
// 
// 		yt /= vRayDir.y;
// 		inside = false;
// 		yn = 1.0f;
// 	} 
// 	else 
// 		yt = -1.0f;    
// 
// 	float zt, zn;
// 
// 	if (vRayOrg.z < vMin.z) 
// 	{
// 		zt = vMin.z - vRayOrg.z;
// 		if (zt > vRayDir.z) 
// 			return false;
// 
// 		zt /= vRayDir.z;
// 		inside = false;
// 		zn = -1.0f;
// 	} 
// 	else if (vRayOrg.z > vMax.z) 
// 	{
// 		zt = vMax.z - vRayOrg.z;
// 		if (zt < vRayDir.z) 
// 			return false;
// 
// 		zt /= vRayDir.z;
// 		inside = false;
// 		zn = 1.0f;
// 	} 
// 	else 
// 		zt = -1.0f;    
// 
// 	// Inside box?
// 
// 	if (inside) 
// 	{
// 		if (pReturnNormal != NULL) 
// 		{
// 			*pReturnNormal = -vRayDir;
// 			D3DXVec3Normalize(pReturnNormal, pReturnNormal);
// 		}
// 
// 		fParametric = 0.0f;
// 		return true;
// 	}
// 
// 	// Select farthest plane - this is
// 	// the plane of intersection.
// 
// 	int which = 0;
// 	float t = xt;
// 
// 	if (yt > t) 
// 	{
// 		which = 1;
// 		t = yt;
// 	}
// 
// 	if (zt > t) 
// 	{
// 		which = 2;
// 		t = zt;
// 	}
// 
// 	switch (which) 
// 	{
// 	case 0: // intersect with yz plane
// 		{
// 			float y = vRayOrg.y + vRayDir.y * t;
// 
// 			if (y < vMin.y || y > vMax.y) 
// 				return false;
// 
// 			float z = vRayOrg.z + vRayDir.z * t;
// 			if (z < vMin.z || z > vMax.z) 
// 				return false;
// 
// 			if (pReturnNormal != NULL) 
// 			{
// 				pReturnNormal->x = xn;
// 				pReturnNormal->y = 0.0f;
// 				pReturnNormal->z = 0.0f;
// 			}
// 		} 
// 		break;
// 
// 	case 1: // intersect with xz plane
// 		{
// 			float x = vRayOrg.x + vRayDir.x * t;
// 			if (x < vMin.x || x > vMax.x) 
// 				return false;
// 
// 			float z = vRayOrg.z + vRayDir.z * t;
// 			if (z < vMin.z || z > vMax.z) 
// 				return false;
// 
// 			if (pReturnNormal != NULL) 
// 			{
// 				pReturnNormal->x = 0.0f;
// 				pReturnNormal->y = yn;
// 				pReturnNormal->z = 0.0f;
// 			}
// 
// 		} 
// 		break;
// 
// 	case 2: // intersect with xy plane
// 		{
// 			float x = vRayOrg.x + vRayDir.x * t;
// 			if (x < vMin.x || x > vMax.x) 
// 				return false;
// 
// 			float y = vRayOrg.y + vRayDir.y * t;
// 			if (y < vMin.y || y > vMax.y) 
// 				return false;
// 
// 			if (pReturnNormal != NULL) 
// 			{
// 				pReturnNormal->x = 0.0f;                                
// 				pReturnNormal->y = 0.0f;
// 				pReturnNormal->z = zn;
// 			}
// 		} 
// 		break;
// 	}
// 
// 	// Return parametric point of intersection
// 	fParametric = t;
// 	return true;
// }

// �ж���AABB�Ƿ��ཻ
bool CIntersection::IntersectionOfAABBAndAABB(const Vec2f& vMin0, const Vec2f& vMax0, const Vec2f& vMin1, const Vec2f& vMax1, Vec2f* pMin, Vec2f* pMax)
{
	// Check for no overlap
	if (vMin0.x > vMax1.x) return false;
	if (vMax0.x < vMin1.x) return false;
	if (vMin0.y > vMax1.y) return false;
	if (vMax0.y < vMin1.y) return false;

	// We have overlap.  Compute AABB of intersection, if they want it.
	if (pMin != 0)
	{
		pMin->x = max(vMin0.x, vMin1.x);
		pMin->y = max(vMin0.y, vMin1.y);
	}

	if (pMax != 0)
	{
		pMax->x = min(vMax0.x, vMax1.x);
		pMax->y = min(vMax0.y, vMax1.y);
	}

	return true;
}

bool CIntersection::IntersectionOfSegmentAndAABBWire(const Vec2f& vRayOrg, const Vec2f& vRayDir, const Vec2f& vMin, const Vec2f& vMax, Vec2f& vIntersection)
{
	Vec2f v0,v1,v2,v3;
	v0 = vMin;
	v1.x = vMin.x;
	v1.y = vMax.y;
	v2 = vMax;
	v3.x = vMax.x;
	v3.y = vMin.y;

	int rgReturn[4];
	Vec2f rgIntersect[4][2];
	rgReturn[0] = CIntersection::Segments2DIntersection(vRayOrg, vRayDir, v0, v1-v0, rgIntersect[0]);
	rgReturn[1] = CIntersection::Segments2DIntersection(vRayOrg, vRayDir, v1, v2-v1, rgIntersect[1]);
	rgReturn[2] = CIntersection::Segments2DIntersection(vRayOrg, vRayDir, v2, v3-v2, rgIntersect[2]);
	rgReturn[3] = CIntersection::Segments2DIntersection(vRayOrg, vRayDir, v3, v0-v3, rgIntersect[3]);

	bool bHasIntersection = false;
	for (int i = 0;i<4;i++)
	{
		if (rgReturn[i] > 0)
		{
			if (!bHasIntersection)
			{
				vIntersection = rgIntersect[i][0];
				bHasIntersection = true;
			}
			else
			{
				if(fabs(rgIntersect[i][0].x - vRayOrg.x) < fabs(vIntersection.x - vRayOrg.x) )
				{
					vIntersection = rgIntersect[i][0];
				}
			}
			
		}
	}

	return bHasIntersection;
}

//ԭ�� δ֪������ˮƽ������ ����Ϊż�����ڶ������
bool CIntersection::PtInPolygon(const Vec2f& vPoint, std::vector<Vec2f> ptPolygon)
{
	int nCross = 0;
	int nCount = ptPolygon.size();
	for (int i = 0; i < nCount; i++) 
	{
		Vec2f p1 = ptPolygon[i];
		Vec2f p2 = ptPolygon[(i + 1) % nCount];// ���һ�������һ��������
		if ( p1.y == p2.y )
			continue;

		if ( vPoint.y < min(p1.y, p2.y) )
			continue;
		if ( vPoint.y >= max(p1.y, p2.y) )
			continue;

		// �󽻵��x����
		double x = (double)(vPoint.y - p1.y) * (double)(p2.x - p1.x) / (double)(p2.y - p1.y) + p1.x;


		// ֻͳ��p1p2��p�������ߵĽ���

		if ( x > vPoint.x )
		{
			nCross++;
		}
	}

	// ����Ϊż�������ڶ����֮��
	return (nCross % 2 == 1);
}
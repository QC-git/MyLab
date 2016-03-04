/*********************************************************************\
 Copyright(c) 2010, TQ Digital Entertainment, All Rights Reserved
 Author:	Zhiye Tu
 Created:	2010-09-15
 Describe:	��������Ѱ·�Ľӿ�
			1.INavMeshMap����һ��xml��������Ϣ������id��������һ���ģ�
			2.INavMeshMap��Ҫָ������ϵ��Z������,����Y������,·��ƽ��ʱ
			  Ҫ�õ�,�����ô���·��ƽ������᲻��ȷ��
			3.IAStar����Ҫ��INavMeshMap�������������յ㣬���ɵ�·
			  ������GetNavMeshPath��
\*********************************************************************/
#pragma once

#include "Platform/PlatformDefine.h"

// ***************************************************************
#if PLATFORM == PLATFORM_WINDOWS
#ifdef NAVMESH_EXPORTS
#define NAVMESH_API __declspec(dllexport)
#else
#define NAVMESH_API __declspec(dllimport)
#endif
#else
#define NAVMESH_API
#endif

// ***************************************************************

// ƽ����ֵ
#define LOS_THRESHOLD 10 

// �����֮����̾���
#define POINT_MIN_LENGTH 0.12

// ***************************************************************

// ��������Ķ���
struct NAVMESH_VERT 
{
	long id;
	float x;
	float y;
	float z;

	NAVMESH_VERT(){}
	NAVMESH_VERT(long nID, float fX, float fY, float fZ) : id(nID), x(fX), y(fY), z(fZ){}
};

// ��ͨ��
struct NAVMESH_POINT
{
	float x;
	float y;
	float z;
	NAVMESH_POINT(){}
	NAVMESH_POINT(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ){}
};

// ��������Ĺ�ϵ��
struct NAVMESH_EDGE
{
	long id;
	long idPoly1;
	long idPoly2;
	long idVert1;
	long idVert2;
};

// ***************************************************************

// ����������͹����νӿ�INavMeshPoly,
// ��INavMeshMap�ͷ�ʱ�����ڲ���INavMeshPolyҲ�ͷŵ���
class INavMeshMap;
class INavMeshPoly
{
public:
	// ��ȡ�����ID����������
	virtual long GetID() const= 0;

	// ���ض��������
	virtual long GetVertsAmount() const = 0;

	// ���ݶ������˳ʱ������ ���ض����ID
	virtual long GetVertID(long nIndex) const = 0;

	// �жϴ˶�����Ƿ����idVert�����������򷵻ش˶������������֮������-1��
	virtual int GetVertIndex(long idVert) const = 0;

	// ��ȡ�ߵ�����
	virtual long GetEdgesAmount() const = 0;

	// ��ȡָ����������0��ʼ���ı�
	virtual long GetEdgeID(long nIndex) const = 0;

	// �ж϶�����Ƿ���Ч
	virtual bool IsValid() const = 0;

	// ��ȡAABB
	virtual bool GetAABB(OUT float& fMinX, OUT float& fMinY, OUT float& fMinZ, OUT float& fMaxX, OUT float& fMaxY, OUT float& fMaxZ) = 0;
};

// ��ͼ����������
class INavMeshMap
{
	// ���ýӿ�
public:
	// ��ͼ�� �ڴ��ͷ�
	virtual void Release() = 0;

	// ��ͼ����XML
	virtual bool Import(const char* strFileName) = 0;

	// ��̬������������
public:
	// ���ö���μ�������ϵĹ�ϵ���Ƿ���Ч������Ч����Ѱ·ʱ�����Ǵ˶���μ��˶������Ĺ�ϵ��(Ĭ����Ч)
	virtual void SetPolyValid(long idPoly, bool bValid) = 0;

	// �ж϶�����Ƿ���Ч
	virtual bool IsPolyValid(long idPoly) const = 0;

	// ���ù�ϵ���Ƿ���Ч������Ч����Ѱ·ʱ�����Ǵ˱�(Ĭ����Ч)
	virtual void SetEdgeValid(long idEdge, bool bValid) = 0;

	// �жϹ�ϵ���Ƿ���Ч
	virtual bool IsEdgeValid(long idEdge) const = 0;

	// �������
public:
	// ���ض��������
	virtual long GetVertsAmount() const = 0;

	// ���ݶ���ID�����ض��������(id���������Ǵ�0��ʼ�ģ�����Ĭ��id��������һ�µġ�)
	virtual bool GetVert(const long idVert, float &x, float &y, float &z) const = 0;
	virtual NAVMESH_VERT GetNavMeshVert(const long idVert) const = 0;

	// ����α���
public:
	// ���ض���ε�����
	virtual long GetPolysAmount() const = 0;

	// ���ݶ����ID���ض����(id���������Ǵ�0��ʼ�ģ�����Ĭ��id��������һ�µġ�)
	virtual INavMeshPoly* GetNavMeshPoly(const long idPoly) const = 0;

	// �߱���
public:
	// ���رߵ�����
	virtual long GetEdgesAmount() const = 0;

	// ���ݱ�ID���ع�ϵ��(������ͨ���ı�)(id���������Ǵ�0��ʼ�ģ�����Ĭ��id��������һ�µġ�)
	virtual NAVMESH_EDGE GetNavMeshEdge(long idEdge) const = 0;


	// ���ӽӿ�
public:
	// ��ȡID��������һ�㷵�ص���0��
	virtual long GetID() const = 0;

	// �ж��߶��뵼�������Ƿ��ཻ,���ض���Σ�ʧ�ܷ���NULL
	virtual INavMeshPoly* GetPolyBySegment(float x0, float y0, float z0, float x1, float y1, float z1, 
		OUT float* pIntersectionX, OUT float* pIntersectionY, OUT float* pIntersectionZ) const = 0;

	// ���ݱ�ID���ع�ϵ�ߵ��е�
	virtual void GetNavMeshEdgeCenter(long idEdge, float &x, float &y, float &z) const = 0;

	// ��ͼ����XML
	virtual bool Export(const char* strFileName, const char* strFileNameSuffix) = 0;

	// �ж��Ƿ�Z������
	virtual bool IsZAxis() const = 0;

	// ��ȡAABB
	virtual bool GetAABB(OUT float& fMinX, OUT float& fMinY, OUT float& fMinZ, OUT float& fMaxX, OUT float& fMaxY, OUT float& fMaxZ) = 0;
};


// A�Ƿ��ص�·���ڵ�
class INavMeshPath
{
public:
	// ·��������
	virtual long GetVertsAmount() const = 0;

	// ����·�������� ���ص�����
	virtual NAVMESH_POINT GetVert(long nIndex) const = 0;
	virtual bool GetVert(long nIndex, OUT float& x, OUT float& y, OUT float& z) const = 0;
};

// A��Ѱ·�㷨
class IAStar
{
public:
	// ������GetNavMeshAStar()��g_pNavMeshAStarʱ�����ͷ�
	// ��������CreateNavMeshAStar()�ſ����ͷ�
	virtual void Release() = 0;

	// ��ʼ��A�ǵ�ͼ����
	// nOptimizeΪ0��ʾ��ƽ��·��
	// nOptimizeΪ1��ʾ��·����LOSƽ��
	// nOptimizeΪ2��ʾ��·�����սǷ�ƽ��
	virtual void Init(const INavMeshMap* pNavMeshMap, int nOptimize = 2) = 0;

	// ����·��
	virtual bool GeneratePath(const NAVMESH_POINT& vStart, const NAVMESH_POINT& vEnd, int nOptimize = 2) = 0;
	virtual bool GeneratePath(float fStartX, float fStartY, float fStartZ, float fEndX, float fEndY, float fEndZ, int nOptimize = 2) = 0;

	// ��ȡ·���ڵ�
	virtual INavMeshPath* GetNavMeshPath() const = 0;
};

// �ϰ����ο�
class IClip
{
public:
	// ������GetNavMeshClip()��g_pNavMeshClipʱ�����ͷ�
	// ��������CreateNavMeshClip()�ſ����ͷ�
	virtual void Release() = 0;

	// ���οղ�������һ��polyʱ����pAStar������Ѱ·����
	virtual void Init(IN OUT INavMeshMap* pMap, IN OUT IAStar* pAStar) = 0;
	virtual void AddStar(IN OUT IAStar* pAStar) = 0;//���߳�ʱ�ж��ASTAR����ʱ��ӵ�2��3��4...n��

	// �����ϰ�������οղ���
	virtual void PutObstacle(const float x[], const float y[], const float z[], int nSegmentAmount, bool bAABBClipping) = 0;
};

// ������������(�����ֶ��ͷ�)
NAVMESH_API INavMeshMap* CreateNewNavMesh();

// ��ȡѰ·����(ȫ�־�̬,�Զ��ͷ�)
NAVMESH_API IAStar* GetNavMeshAStar();
#define g_pNavMeshAStar GetNavMeshAStar()

// ����Ѱ·����(�����ֶ��ͷ�)
NAVMESH_API IAStar* CreateNavMeshAStar();

// �ϰ����ο�(��̬,�Զ��ͷ�)
NAVMESH_API IClip* GetNavMeshClip();
#define g_pNavMeshClip GetNavMeshClip()

// �ϰ����ο�(�����ֶ��ͷ�)
NAVMESH_API IClip* CreateNavMeshClip();
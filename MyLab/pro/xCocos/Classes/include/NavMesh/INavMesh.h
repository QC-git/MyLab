/*********************************************************************\
 Copyright(c) 2010, TQ Digital Entertainment, All Rights Reserved
 Author:	Zhiye Tu
 Created:	2010-09-15
 Describe:	导航网格寻路的接口
			1.INavMeshMap包含一个xml的所有信息，其中id和索引是一样的；
			2.INavMeshMap中要指定坐标系是Z轴向上,还是Y轴向上,路径平滑时
			  要用到,若设置错误，路径平滑结果会不正确；
			3.IAStar对象要绑定INavMeshMap对象；输入起点和终点，生成的路
			  径点在GetNavMeshPath中
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

// 平滑阈值
#define LOS_THRESHOLD 10 

// 点与点之间最短距离
#define POINT_MIN_LENGTH 0.12

// ***************************************************************

// 导航网格的顶点
struct NAVMESH_VERT 
{
	long id;
	float x;
	float y;
	float z;

	NAVMESH_VERT(){}
	NAVMESH_VERT(long nID, float fX, float fY, float fZ) : id(nID), x(fX), y(fY), z(fZ){}
};

// 普通点
struct NAVMESH_POINT
{
	float x;
	float y;
	float z;
	NAVMESH_POINT(){}
	NAVMESH_POINT(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ){}
};

// 导航网格的关系边
struct NAVMESH_EDGE
{
	long id;
	long idPoly1;
	long idPoly2;
	long idVert1;
	long idVert2;
};

// ***************************************************************

// 导航网格中凸多边形接口INavMeshPoly,
// 当INavMeshMap释放时，其内部的INavMeshPoly也释放掉。
class INavMeshMap;
class INavMeshPoly
{
public:
	// 获取多边形ID（或索引）
	virtual long GetID() const= 0;

	// 返回顶点的数量
	virtual long GetVertsAmount() const = 0;

	// 根据多边形中顺时针索引 返回顶点的ID
	virtual long GetVertID(long nIndex) const = 0;

	// 判断此多边形是否包含idVert，若包含，则返回此顶点的索引；反之，返回-1；
	virtual int GetVertIndex(long idVert) const = 0;

	// 获取边的数量
	virtual long GetEdgesAmount() const = 0;

	// 获取指定索引（从0开始）的边
	virtual long GetEdgeID(long nIndex) const = 0;

	// 判断多边形是否有效
	virtual bool IsValid() const = 0;

	// 获取AABB
	virtual bool GetAABB(OUT float& fMinX, OUT float& fMinY, OUT float& fMinZ, OUT float& fMaxX, OUT float& fMaxY, OUT float& fMaxZ) = 0;
};

// 地图网格数据类
class INavMeshMap
{
	// 常用接口
public:
	// 地图类 内存释放
	virtual void Release() = 0;

	// 地图导入XML
	virtual bool Import(const char* strFileName) = 0;

	// 动态设置网格属性
public:
	// 设置多边形及多边形上的关系边是否有效，若无效，则寻路时不考虑此多边形及此多边形里的关系边(默认有效)
	virtual void SetPolyValid(long idPoly, bool bValid) = 0;

	// 判断多边形是否有效
	virtual bool IsPolyValid(long idPoly) const = 0;

	// 设置关系边是否有效，若无效，则寻路时不考虑此边(默认有效)
	virtual void SetEdgeValid(long idEdge, bool bValid) = 0;

	// 判断关系边是否有效
	virtual bool IsEdgeValid(long idEdge) const = 0;

	// 顶点遍历
public:
	// 返回顶点的数量
	virtual long GetVertsAmount() const = 0;

	// 根据顶点ID，返回顶点的坐标(id和索引都是从0开始的，所以默认id和索引是一致的。)
	virtual bool GetVert(const long idVert, float &x, float &y, float &z) const = 0;
	virtual NAVMESH_VERT GetNavMeshVert(const long idVert) const = 0;

	// 多边形遍历
public:
	// 返回多边形的数量
	virtual long GetPolysAmount() const = 0;

	// 根据多边形ID返回多边形(id和索引都是从0开始的，所以默认id和索引是一致的。)
	virtual INavMeshPoly* GetNavMeshPoly(const long idPoly) const = 0;

	// 边遍历
public:
	// 返回边的数量
	virtual long GetEdgesAmount() const = 0;

	// 根据边ID返回关系边(即可以通过的边)(id和索引都是从0开始的，所以默认id和索引是一致的。)
	virtual NAVMESH_EDGE GetNavMeshEdge(long idEdge) const = 0;


	// 附加接口
public:
	// 获取ID或索引（一般返回的是0）
	virtual long GetID() const = 0;

	// 判断线段与导航网格是否相交,返回多边形，失败返回NULL
	virtual INavMeshPoly* GetPolyBySegment(float x0, float y0, float z0, float x1, float y1, float z1, 
		OUT float* pIntersectionX, OUT float* pIntersectionY, OUT float* pIntersectionZ) const = 0;

	// 根据边ID返回关系边的中点
	virtual void GetNavMeshEdgeCenter(long idEdge, float &x, float &y, float &z) const = 0;

	// 地图导出XML
	virtual bool Export(const char* strFileName, const char* strFileNameSuffix) = 0;

	// 判断是否Z轴向上
	virtual bool IsZAxis() const = 0;

	// 获取AABB
	virtual bool GetAABB(OUT float& fMinX, OUT float& fMinY, OUT float& fMinZ, OUT float& fMaxX, OUT float& fMaxY, OUT float& fMaxZ) = 0;
};


// A星返回的路径节点
class INavMeshPath
{
public:
	// 路径点数量
	virtual long GetVertsAmount() const = 0;

	// 根据路径点索引 返回点坐标
	virtual NAVMESH_POINT GetVert(long nIndex) const = 0;
	virtual bool GetVert(long nIndex, OUT float& x, OUT float& y, OUT float& z) const = 0;
};

// A星寻路算法
class IAStar
{
public:
	// 当调用GetNavMeshAStar()或g_pNavMeshAStar时不能释放
	// 仅当调用CreateNavMeshAStar()才可以释放
	virtual void Release() = 0;

	// 初始化A星地图数据
	// nOptimize为0表示不平滑路径
	// nOptimize为1表示将路径按LOS平滑
	// nOptimize为2表示将路径按拐角法平滑
	virtual void Init(const INavMeshMap* pNavMeshMap, int nOptimize = 2) = 0;

	// 生成路径
	virtual bool GeneratePath(const NAVMESH_POINT& vStart, const NAVMESH_POINT& vEnd, int nOptimize = 2) = 0;
	virtual bool GeneratePath(float fStartX, float fStartY, float fStartZ, float fEndX, float fEndY, float fEndZ, int nOptimize = 2) = 0;

	// 获取路径节点
	virtual INavMeshPath* GetNavMeshPath() const = 0;
};

// 障碍物镂空
class IClip
{
public:
	// 当调用GetNavMeshClip()或g_pNavMeshClip时不能释放
	// 仅当调用CreateNavMeshClip()才可以释放
	virtual void Release() = 0;

	// 当镂空操作产生一堆poly时放入pAStar里用于寻路处理
	virtual void Init(IN OUT INavMeshMap* pMap, IN OUT IAStar* pAStar) = 0;
	virtual void AddStar(IN OUT IAStar* pAStar) = 0;//多线程时有多个ASTAR，此时添加第2、3、4...n个

	// 放置障碍物进行镂空操作
	virtual void PutObstacle(const float x[], const float y[], const float z[], int nSegmentAmount, bool bAABBClipping) = 0;
};

// 创建导航数据(必须手动释放)
NAVMESH_API INavMeshMap* CreateNewNavMesh();

// 获取寻路对象(全局静态,自动释放)
NAVMESH_API IAStar* GetNavMeshAStar();
#define g_pNavMeshAStar GetNavMeshAStar()

// 创建寻路对象(必须手动释放)
NAVMESH_API IAStar* CreateNavMeshAStar();

// 障碍物镂空(静态,自动释放)
NAVMESH_API IClip* GetNavMeshClip();
#define g_pNavMeshClip GetNavMeshClip()

// 障碍物镂空(必须手动释放)
NAVMESH_API IClip* CreateNavMeshClip();
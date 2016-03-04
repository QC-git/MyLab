#ifndef __I_ASTAR_MAP_H__
#define __I_ASTAR_MAP_H__

// #include "basecode.h"
#include "rts.h"
#include <cstddef>
enum ObstacleRule
{
	UserSet,		// 通过用户传参设置动\静态掩码
	AutoDynamic,	// 自动规则（起点附近范围考虑动态掩码）
    AutoDynamicEx,	// 自动规则扩展（起点附近范围考虑动态掩码）
};

class IPathSearchObject
{
protected:
    IPathSearchObject(){}
public:
    virtual ~IPathSearchObject(){}

    virtual void SetStartAndGoal(float fBeginX, float fBeginY, float fEndX, float fEndY, float radius) = 0;

    virtual void StaticObstacle(bool use) = 0;
    virtual bool StaticObstacle() const = 0;

    virtual void DynamicObstacle(bool use) = 0;
    virtual bool DynamicObstacle() const = 0;

    virtual void DynamicObstacleEx(bool use) = 0;
    virtual bool DynamicObstacleEx() const  = 0;

    virtual void Optimize(bool optimize) = 0;
    virtual bool Optimize() const = 0;

    virtual void DynamicObstacleOptimize(bool dOptimize) = 0;

    virtual void NodeLimited(int num) = 0;
    virtual int  NodeLimited(void) const = 0;

	virtual void SetObstacleRule(ObstacleRule eRule) = 0;

    virtual int  GetPointAmount() const = 0;
    virtual void GetPointByIndex(int nIndex, float& fX, float& fY, float& fZ) const = 0;

    static IPathSearchObject* CreateSearchObject();
};

class IAStarMap
{
protected:
    IAStarMap(){}
public:
    virtual ~IAStarMap(){}
    virtual void Release() = 0;

    virtual bool FindPath(IPathSearchObject* objs,int num) = 0;

    virtual bool IsValid(float x, float y, bool staticObstacle=true, bool dynamicObstacle=true,bool bUseDynamicObstacleEx = false) const = 0;
    virtual bool IsValid(float x, float y, float radius, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true,bool bUseDynamicObstacleEx = false) const = 0;

    virtual bool CanMove(float x, float y, float radius, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true,bool bUseDynamicObstacleEx=false) const = 0;

    //按格子数顺序添加障碍物掩码
    virtual void AddStaticObstacle(float x, float y) = 0;
    virtual void DelStaticObstacle(float x, float y) = 0;
    virtual void AddDynamicObstacle(float x, float y,float face, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE) = 0;
    virtual void DelDynamicObstacle(float x, float y, float face, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE) = 0;

    //按半径添加障碍物掩码
    virtual void AddStaticObstacle(float x, float y,float face, float radius,float retRadius=0.f,unsigned maskType = UNIT_MASK_TYPE_NONE) = 0;
    virtual void DelStaticObstacle(float x, float y,float face, float radius,float retRadius=0.f,unsigned maskType = UNIT_MASK_TYPE_NONE) = 0;

    virtual void AddDynamicObstacle(float x, float y,float face, float radius,float retRadius=0.f, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE) = 0;
    virtual void DelDynamicObstacle(float x, float y,float face, float radius,float retRadius=0.f, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE) = 0;

    virtual bool CalcClosestNode(float fx, float fy, float radius,float& cx,float& cy,float& cz, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true, bool bUseDynamicObstacleEx=false) const = 0;
    virtual bool CalcClosestNodeByCell(float fx, float fy, float radius,float& cx,float& cy,float& cz, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true, bool bUseDynamicObstacleEx=false,unsigned maxCell=20) const = 0;

    static IAStarMap* CreateAStarMap(const char* pszFile);
    static IAStarMap* CreateAStarMap(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count);
    static IAStarMap* CreateAStarMap(IAStarMap* map);
};

















#endif


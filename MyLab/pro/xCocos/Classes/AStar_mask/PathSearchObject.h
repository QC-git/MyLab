#pragma once

#include "rts/vec.h"
#include <vector>
#include "rts/IAStarMap.h"

class CPathSearchObject : public IPathSearchObject
{
public:
    CPathSearchObject(void);
    virtual ~CPathSearchObject(void){}

    void SetStartAndGoal(float fBeginX, float fBeginY, float fEndX, float fEndY, float radius);

    void StaticObstacle(bool use){m_staticObstacle=use;}
    bool StaticObstacle() const {return m_staticObstacle;}

    void DynamicObstacle(bool use){m_dynamicObstacle=use;}
    bool DynamicObstacle() const {return m_dynamicObstacle;}

    void DynamicObstacleEx(bool use){m_dynamicObstacleEx=use;}
    bool DynamicObstacleEx() const {return m_dynamicObstacleEx;}

    void Optimize(bool optimize) {m_optimize=optimize;}
    bool Optimize() const {return m_optimize;}

    void DynamicObstacleOptimize(bool dOptimize) {m_dynamicObstacleOptimize=dOptimize;}

    void NodeLimited(int num) {m_nodeLimited=num;}
    int  NodeLimited(void) const {return m_nodeLimited;}

	void SetObstacleRule(ObstacleRule eRule) {m_eObstacleRule = eRule; }

    int  GetPointAmount() const{return (int)m_vecPoints.size();}
    void GetPointByIndex(int nIndex, float& fX, float& fY, float& fZ) const;

    void Clear(){m_vecPoints.clear();}
    void AddPoint(const Vec2f& vPoint, float fHeight){m_vecPoints.push_back(Vec3f(vPoint.x,vPoint.y,fHeight));}
    void AddPoint(const Vec3f& vPoint){m_vecPoints.push_back(vPoint);}

protected:
    bool m_staticObstacle;
    bool m_dynamicObstacle;
    bool m_dynamicObstacleEx;			    // 扩展动态掩码
    bool m_optimize;
    bool m_dynamicObstacleOptimize;         //是否用扩展动态掩码优化
    int  m_nodeLimited;

	ObstacleRule m_eObstacleRule;			// 障碍规则
   

    float m_fBeginX;
    float m_fBeginY;
    float m_fEndX;
    float m_fEndY;
    float m_radius;
    std::vector<Vec3f> m_vecPoints;
    friend class CAStarMap;
};

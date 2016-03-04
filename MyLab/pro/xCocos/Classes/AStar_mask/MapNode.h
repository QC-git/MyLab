#pragma once

#include <cstdlib>
#include "rts/vec.h"
#include "AStarSearch.hpp"

class CAStarMap;

class CMapNode
{
protected:
    CAStarMap* m_map;
    int m_x;
    int m_y;
    float m_z;
    int m_nStaticObstacle;
    int m_nDynamicObstacle;
    int m_nDynamicObstacleEx;//扩展的动态障碍物

    //  1----2
    //  |    |
    //  |    |
    //  0----3
    Vec2f m_v0, m_v1, m_v2, m_v3;
    Vec2f m_vCenter;

    uint32_t m_hashCode;
public:
    CMapNode(){InitMapInfo(0,0,0,0);}
    CMapNode(CAStarMap* map){InitMapInfo(map,0,0,0);}
    CMapNode(CAStarMap* map,int x,int y,float z){InitMapInfo(map,x,y,z);}
    virtual ~CMapNode(void){}

    void InitMapInfo(CAStarMap* map,int x,int y,float z);

    void InitTilePoint(const Vec2f& vMin, const Vec2f& vMax)
    {
        m_v0 = vMin;
        m_v1.x = vMin.x;
        m_v1.y = vMax.y;
        m_v2 = vMax;
        m_v3.x = vMax.x;
        m_v3.y = vMin.y;
        m_vCenter = (m_v1+m_v3)/2;
    }

    int GoalDistanceEstimate( const CMapNode& nodeGoal ) const
    {
        //     return (int)m_vCenter.dist(nodeGoal.m_vCenter);
        int xd = abs(m_x - nodeGoal.m_x);
        int yd = abs(m_y - nodeGoal.m_y);
//         if(xd<0)xd=-xd;
//         if(yd<0)yd=-yd;
        return (xd+yd) * 10;
        //return (int)(100.0*sqrt((double)(xd*xd + yd*yd)));
    }

    int GetCost( const CMapNode &successor ) const
    {
        if ((successor.m_x!=m_x) && (successor.m_y!=m_y))
            return 14;

        return 10;
    }
    bool IsGoal( const CMapNode &nodeGoal ) const
    {
        return (m_x == nodeGoal.m_x) && (m_y == nodeGoal.m_y);
    }

    bool GetSuccessors( AStarSearch<CMapNode> *astarsearch, const CMapNode *parent_node,
        int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const;

    bool IsSameState( const CMapNode &rhs )const
    {
        return (m_x == rhs.m_x) && (m_y == rhs.m_y);
    }

    bool CompareTo(const CMapNode& rhs) const
    {
        return m_x<rhs.m_x || (m_x==rhs.m_x && m_y<rhs.m_y);
    }

    uint32_t getHashCode() const {return m_hashCode;}

    // 判断是否有效
    bool IsValid(bool bUseStaticObstacle = true, bool bUseDynamicObstacle = true,bool bUseDynamicObstacleEx = false) const;
    // 判断附近节点是否有效
    bool IsNeiborValid(int dwAgentCellSize,bool bUseStaticObstacle = true, bool bUseDynamicObstacle = true, bool bUseDynamicObstacleEx = true) const;
    //////////////////////////////////////////////////////////////////////////
    // 添加/删除 障碍物
    void AddStaticObstacle(){++m_nStaticObstacle;}
    void DelStaticObstacle(){if(m_nStaticObstacle>0)--m_nStaticObstacle;}

    //////////////////////////////////////////////////////////////////////////
    // 添加/删除 动态障碍物
    void AddDynamicObstacle(bool dynamicObstacleEx = true);/*{++m_nDynamicObstacle;}*/
    void DelDynamicObstacle(bool dynamicObstacleEx = true);/*{if(m_nDynamicObstacle>0)--m_nDynamicObstacle;}*/

    //////////////////////////////////////////////////////////////////////////
    // 高度值
    void SetHeight(float fHeight){m_z = fHeight;}
    float GetHeight() const {return m_z;}

    void GetBox(Vec2f& v0, Vec2f& v1, Vec2f& v2, Vec2f& v3) const {v0=m_v0;v1=m_v1;v2=m_v2;v3=m_v3;}
    const Vec2f& GetCenter() const {return m_vCenter;}
    void GetCenter(float& fx,float& fy) const {fx=m_vCenter.x;fy=m_vCenter.y;}

    void GetIndex(int& x,int& y) const {x=m_x;y=m_y;}
protected:
    const CMapNode* FilterInValidNode(int x,int y, const CMapNode *parent_node,
        int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const;
    bool FilterInValidNode(const CMapNode* nextNode, const CMapNode *parent_node,
        int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const;

    friend class CAStarMap;
};

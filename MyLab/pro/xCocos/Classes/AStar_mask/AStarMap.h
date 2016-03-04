#pragma once

#include "rts/IAStarMap.h"
#include "rts/vec.h"
#include "MapNode.h"
#include "PathSearchObject.h"
#include "Optimize.h"

class COptimize;
class CAStarMap : public IAStarMap
{
public:
    CAStarMap(const char* pszFileName);
    CAStarMap(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count);
    CAStarMap(CAStarMap* map);
    virtual ~CAStarMap(void);
    virtual void Release();

public:
    CMapNode* GetMapNode(int x, int y);
    CMapNode* GetMapNode(int nIndex);
    CMapNode* GetMapNodeByPoint(float fX, float fY);
    const CMapNode* GetMapNode(int x, int y) const;
    const CMapNode* GetMapNode(int nIndex) const;
    const CMapNode* GetMapNodeByPoint(float fX, float fY) const;

    bool PointToIndex(float fX, float fY, int& ix, int& iy) const;

    uint32_t Width() const {return m_width;}
    uint32_t Height() const {return m_height;}

public:
    int GetNodeAmount() const;

    virtual void AddStaticObstacle(float x, float y);
    virtual void DelStaticObstacle(float x, float y);
    virtual void AddDynamicObstacle(float x, float y,float face, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE);
    virtual void DelDynamicObstacle(float x, float y,float face, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE);

    virtual void AddStaticObstacle(float x, float y,float face, float radius,float retRadius=0.f,unsigned maskType = UNIT_MASK_TYPE_NONE);
    virtual void DelStaticObstacle(float x, float y,float face, float radius,float retRadius=0.f,unsigned maskType = UNIT_MASK_TYPE_NONE);

    virtual void AddDynamicObstacle(float x, float y,float face, float radius,float retRadius=0.f, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE);
    virtual void DelDynamicObstacle(float x, float y,float face, float radius,float retRadius=0.f, bool obstacleEx =false,unsigned maskType = UNIT_MASK_TYPE_NONE);

    virtual bool IsValid(float x, float y, bool staticObstacle=true, bool dynamicObstacle=true,bool bUseDynamicObstacleEx = false) const;
    virtual bool IsValid(float x, float y, float radius, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true,bool bUseDynamicObstacleEx = false) const;

    bool CanMove(int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle,bool bUseDynamicObstacleEx, int nTargetX, int nTargetY) const;
	bool CanMove(bool bUseStaticObstacle, bool bUseDynamicObstacle,bool bUseDynamicObstacleEx, int nTargetX, int nTargetY) const;
    virtual bool CanMove(float x, float y, float radius, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true,bool bUseDynamicObstacleEx=false) const;

	virtual bool FindPath(IPathSearchObject* objs,int num);

	virtual bool CalcClosestNode(float fx, float fy, float radius,float& cx,float& cy,float& cz, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true, bool bUseDynamicObstacleEx=false) const;
    virtual bool CalcClosestNodeByCell(float fx, float fy, float radius,float& cx,float& cy,float& cz, bool bUseStaticObstacle=true, bool bUseDynamicObstacle=true, bool bUseDynamicObstacleEx=false,unsigned maxCell=20) const ;
    bool Import(const char* pszFile);
    bool ImportMask(const char* pszFile);
    bool ImportData(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count);
    bool ImportTgrid(const char* pszFile);

protected:
    bool Create(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float nCellSize);
    void CalcObstacleArea(float x, float y,float radius,int& l,int& t,int& r,int& b) const;
    const CMapNode* CalcClosestNode(float fx, float fy, float radius, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const;
    void CalcObstacleArea_LeftRight(float x, float y,float radius,int& l,int& t,int& r,int& b) const;
    void CalcObstacleArea_Crc(float x, float y,float radius,int& l,int& t,int& r,int& b) const;
	void NormalizeMapCoord(float &c) const ;
	void GetNearPoint2D(float srcX, float srcY, float &x, float &y, float distance2d, float absAngle ) const ;



    enum MASK_OPERATOR
    {
        ADD_STATICMASK,
        DEL_STATICMASK,
        ADD_DYNAMICMASK,
        DEL_DYNAMICMASK
    };
    void MaskOperator(float x,float y,MASK_OPERATOR op, bool obstacleEx);
    void MaskOperator(int l,int t,int r,int b,MASK_OPERATOR op, bool obstacleEx);
	void MaskOperator(int l,int t,int r,int b,MASK_OPERATOR op, bool obstacleEx,float radius,float retRadius,float x, float y,unsigned maskType = UNIT_MASK_TYPE_NONE, float faceTo = 0.f);

protected:
	COptimize m_opt; // 作为成员变量减少内存分配时间
    CMapNode* m_nodes;
    int m_width;
    int m_height;

    Vec2f m_vMapMin;
    Vec2f m_vMapMax;
    float m_fYTileSize;
    float m_fXTileSize;
    AStarSearch<CMapNode> m_pathfinder;

    friend class CMapNode;
    friend class CTgridImporter;
};

#include "PathSearchObject.h"
#include "assert.h"

CPathSearchObject::CPathSearchObject(void)
{
    m_staticObstacle=m_dynamicObstacle=m_optimize=true;
    m_dynamicObstacleEx = false;
    m_nodeLimited = 0xffffffff;
    m_fBeginX=m_fBeginY=m_fEndX=m_fEndY=0.f;
    m_radius = 1.f;
    m_dynamicObstacleOptimize = true;

	m_eObstacleRule = UserSet;
}

void CPathSearchObject::SetStartAndGoal(float fBeginX, float fBeginY, float fEndX, float fEndY, float radius)
{
    m_fBeginX = fBeginX;
    m_fBeginY = fBeginY;
    m_fEndX   = fEndX;
    m_fEndY   = fEndY;
    m_radius  = radius;
//     m_agentCellSize = (int)ceil(pUnit->GetObjectSize()*2/MASK_SIZE);;
}

void CPathSearchObject::GetPointByIndex(int nIndex, float& fX, float& fY, float& fZ) const
{
    if (nIndex>(int)m_vecPoints.size()||nIndex<0)
    {
        assert(0);
        return;
    }
    const Vec3f& v = m_vecPoints[nIndex];
    fX=v.x;
    fY=v.y;
    fZ=v.z;
}

IPathSearchObject* IPathSearchObject::CreateSearchObject()
{
    return new CPathSearchObject();
}

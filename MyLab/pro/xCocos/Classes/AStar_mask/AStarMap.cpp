#include "AStarMap.h"
#include <assert.h>
#include <stdio.h>
#include "Optimize.h"
#include "Intersection.h"
#include "TgridImporter.h"
#include "BaseCommon.h"

#include "Log.h"

using namespace std;

CAStarMap::CAStarMap(const char* pszFileName)
        :m_nodes(NULL),m_fYTileSize(0),m_fXTileSize(0),m_width(0),m_height(0)
{
	//tq::DebugMsg(pszFileName);
    if (!Import(pszFileName))
    {
        assert(0);
    }
}

CAStarMap::CAStarMap(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count)
         :m_nodes(NULL),m_fYTileSize(0),m_fXTileSize(0),m_width(0),m_height(0)
{
    if (!ImportData(fMapMinX, fMapMinY, fMapMaxX,fMapMaxY,fCellSize,pNodes,count))
    {
        assert(0);
    }
}

CAStarMap::CAStarMap(CAStarMap* map)
        :m_nodes(NULL),m_fYTileSize(0),m_fXTileSize(0),m_width(0),m_height(0)
{
    if (!map)
    {
        assert(map);
        return;
    }
    CMapNode* srcNodes = map->m_nodes;
    if (!srcNodes)
    {
        assert(0);
        return;
    }
    m_width = map->m_width;
    m_height = map->m_height;

    m_vMapMin = map->m_vMapMin;
    m_vMapMax = map->m_vMapMax;
    m_fYTileSize = map->m_fYTileSize;
    m_fXTileSize = map->m_fXTileSize;

    int count = map->GetNodeAmount();
    m_nodes = new CMapNode[count];
    for (int i=0;i<count;++i)
    {
        CMapNode& dnode = m_nodes[i];
        CMapNode& snode = srcNodes[i];
        dnode.InitMapInfo(this,snode.m_x,snode.m_y,snode.m_z);
        dnode.m_nStaticObstacle = snode.m_nStaticObstacle;
        dnode.m_nDynamicObstacle = snode.m_nDynamicObstacle;
        dnode.m_v0 = snode.m_v0;
        dnode.m_v1 = snode.m_v1;
        dnode.m_v2 = snode.m_v2;
        dnode.m_v3 = snode.m_v3;
        dnode.m_vCenter = snode.m_vCenter;
    }
}

CAStarMap::~CAStarMap(void)
{
    SAFE_DELETE_ARRAY(m_nodes);
}

void CAStarMap::Release()
{
    delete this;
}

bool CAStarMap::Create(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float nCellSize)
{
    SAFE_DELETE_ARRAY(m_nodes);

    m_fYTileSize = nCellSize;
    m_fXTileSize = nCellSize;
    m_vMapMin = Vec2f(fMapMinX,fMapMinY);
    m_vMapMax = Vec2f(fMapMaxX, fMapMaxY);

    // 计算X Y的格子数量
    m_width = (int)ceil(fabs(m_vMapMax.x - m_vMapMin.x)/m_fXTileSize);
    m_height = (int)ceil(fabs(m_vMapMax.y - m_vMapMin.y)/m_fYTileSize);
    if (m_width == 0)
    {
        m_width = 1;
    }
    if (m_height == 0)
    {
        m_height = 1;
    }

    m_nodes = new CMapNode[GetNodeAmount()];
    for (int i=0;i<m_width;++i)
    {
        for (int j=0;j<m_height;++j)
        {
            Vec2f vTileMin, vTileMax;
            vTileMin.x = m_vMapMin.x + i*m_fXTileSize;
            vTileMin.y = m_vMapMin.y + j*m_fYTileSize;
            vTileMax.x = vTileMin.x + m_fXTileSize;
            vTileMax.y = vTileMin.y + m_fYTileSize;

            CMapNode* node = GetMapNode(i,j);
            node->InitMapInfo(this,i,j,0);
            node->InitTilePoint(vTileMin,vTileMax);
        }
    }

    return true;
}

int CAStarMap::GetNodeAmount() const
{
    return m_height*m_width;
}

bool CAStarMap::Import(const char* pszFile)
{
//    char szExt[16] = "";
//    _splitpath(pszFile, NULL, NULL, NULL, szExt);
    const char* szExt = "";
    auto len = strlen(pszFile);
    for (auto c = pszFile + len; c != pszFile; c--){
        if(*c == '.'){
            szExt = c;
            break;
        }
    }

	if (0 == stricmp(szExt, ".mask"))
    {
        return ImportMask(pszFile);
    }
	else if (0 == stricmp(szExt, ".tgrid"))
    {
        return ImportTgrid(pszFile);
    }

    return false;
}

bool CAStarMap::ImportData(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count)
{
    Create(fMapMinX, fMapMinY, fMapMaxX, fMapMaxY, (float)fCellSize);
    if (count == 0)
    {
        return false;
    }

    for (size_t i=0 ; i< count; ++i)
    {
        const SRtsNode& node = pNodes[i];
        bool bValid = (node.nValid == 0?false:true);
        CMapNode* pNode = this->GetMapNode(node.nIndex);
        if (pNode == NULL)
        {
            continue;
        }

        if (!bValid)
        {
            pNode->AddStaticObstacle();
        }

        pNode->SetHeight(node.fHeight);
    }
    return true;
}

bool CAStarMap::ImportTgrid(const char* pszFile)
{
    CTgridImporter import;
    if(!import.Create(pszFile, this))
    {
        return false;
    }

    return true;
}

bool CAStarMap::ImportMask(const char* pszFile)
{
    FILE* pFile = fopen(pszFile, "r");
    if (NULL == pFile)
    {
        return false;
    }

    char szBuf[2048];
    if (fgets(szBuf, 2048, pFile))
    {
        float fMapMinX, fMapMinY, fMapMaxX, fMapMaxY;
        float fCellSize;
        if(sscanf(szBuf, "%f %f %f %f %f", &fMapMinX, &fMapMinY, &fMapMaxX, &fMapMaxY, &fCellSize) != 5)
        {
            return false;
        }

        Create(fMapMinX, fMapMinY, fMapMaxX, fMapMaxY, (float)fCellSize);
    }

    while(fgets(szBuf, 2048, pFile))
    {
        if (szBuf[0] == '\0')
        {
            continue;
        }

        int nIndex, nValid;
        float fHeight;
        if(sscanf(szBuf, "%d %d %f", &nIndex, &nValid, &fHeight) == 3)
        {
            bool bValid = (nValid == 0?false:true);
            CMapNode* pNode = this->GetMapNode(nIndex);
            if (pNode == NULL)
            {
                continue;
            }

            if (!bValid)
            {
                pNode->AddStaticObstacle();
            }

            pNode->SetHeight(fHeight);

        }
    }

    fclose(pFile);
    return true;
}

bool CAStarMap::IsValid(float x, float y, bool staticObstacle, bool dynamicObstacle,bool bUseDynamicObstacleEx) const
{
    const CMapNode* pNode = GetMapNodeByPoint(x, y);
    if (pNode == NULL)
    {
        return false;
    }
    return pNode->IsValid(staticObstacle,dynamicObstacle,bUseDynamicObstacleEx);
}

bool CAStarMap::IsValid(float x, float y, float radius, bool bUseStaticObstacle, bool bUseDynamicObstacle,bool bUseDynamicObstacleEx) const
{
    return CanMove(x,y,radius,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx);
//     int agentCell = (int)ceil(radius*2/m_fXTileSize);
//     int ix,iy;
//     PointToIndex(x,y,ix,iy);
//     return CanMove(agentCell,bUseStaticObstacle,bUseDynamicObstacle,ix,iy);
}


void CAStarMap::MaskOperator(float x,float y,MASK_OPERATOR op, bool obstacleEx)
{
    CMapNode* pNode = GetMapNodeByPoint(x, y);
    if (pNode == NULL)
    {
        return;
    }

    switch (op)
    {
    case ADD_STATICMASK:
        pNode->AddStaticObstacle();
        break;
    case DEL_STATICMASK:
        pNode->DelStaticObstacle();
        break;
    case ADD_DYNAMICMASK:
        pNode->AddDynamicObstacle(obstacleEx);
        break;
    case DEL_DYNAMICMASK:
        pNode->DelDynamicObstacle(obstacleEx);
        break;
    default:
        assert(0);
        break;
    }
}

void CAStarMap::MaskOperator(int l,int t,int r,int b,MASK_OPERATOR op, bool obstacleEx,float radius,float retRadius,float x, float y,unsigned maskType, float faceTo)
{
	std::vector<Vec2f> vPoints;
	if ( maskType == UNIT_MASK_TYPE_RECTANGLE )
	{
		Vec2f vPoint0;
		Vec2f vPoint1;
		Vec2f vPoint2;
		Vec2f vPoint3;
		GetNearPoint2D(x,y,vPoint0.x,vPoint0.y,retRadius,faceTo-M_PI/2.f);
		vPoints.push_back(vPoint0);
		GetNearPoint2D(x,y,vPoint1.x,vPoint1.y,retRadius,faceTo+M_PI/2.f);
		vPoints.push_back(vPoint1);
		GetNearPoint2D(vPoint1.x,vPoint1.y,vPoint2.x,vPoint2.y,radius,faceTo);
		vPoints.push_back(vPoint2);
		GetNearPoint2D(vPoint0.x,vPoint0.y,vPoint3.x,vPoint3.y,radius,faceTo);
		vPoints.push_back(vPoint3);
	}

	CMapNode* pSrcNode = GetMapNodeByPoint(x, y);
	if (pSrcNode == NULL)
	{
		return;
	}
	for (int i=l;i<=r;++i)
	{
		for (int j=t;j<=b;++j)
		{
			CMapNode* pNode = GetMapNode(i,j);
			if (pNode)
			{
				if ( maskType == UNIT_MASK_TYPE_CIRCULAR && (pNode->m_vCenter.dist(pSrcNode->m_vCenter) > radius) )
				{
					continue;
				}
				else if (maskType==UNIT_MASK_TYPE_CONCENTRIC)
				{
					if ((pNode->m_vCenter.dist(pSrcNode->m_vCenter) > radius) ||(pNode->m_vCenter.dist(pSrcNode->m_vCenter) < retRadius) )
					{
						continue;
					}
				}
				else if ( maskType == UNIT_MASK_TYPE_RECTANGLE )
				{
					//分别计算出4个顶点
					//  1----2
					//  |    |
					//  |    |
					//  0----3
					if( !CIntersection::PtInPolygon(pNode->m_vCenter, vPoints) )
					{
						continue;
					}
				}
				switch (op)
				{
				case ADD_STATICMASK:
					pNode->AddStaticObstacle();
					break;
				case DEL_STATICMASK:
					pNode->DelStaticObstacle();
					break;
				case ADD_DYNAMICMASK:
					pNode->AddDynamicObstacle(obstacleEx);
					break;
				case DEL_DYNAMICMASK:
					pNode->DelDynamicObstacle(obstacleEx);
					break;
				default:
					assert(0);
					break;
				}
			}
		}
	}
}

void CAStarMap::MaskOperator(int l,int t,int r,int b,MASK_OPERATOR op, bool obstacleEx)
{
    for (int i=l;i<=r;++i)
    {
        for (int j=t;j<=b;++j)
        {
            CMapNode* pNode = GetMapNode(i,j);
            if (pNode)
            {
                switch (op)
                {
                case ADD_STATICMASK:
                    pNode->AddStaticObstacle();
                    break;
                case DEL_STATICMASK:
                    pNode->DelStaticObstacle();
                    break;
                case ADD_DYNAMICMASK:
                    pNode->AddDynamicObstacle(obstacleEx);
                    break;
                case DEL_DYNAMICMASK:
                    pNode->DelDynamicObstacle(obstacleEx);
                    break;
                default:
                    assert(0);
                    break;
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// 添加/删除 障碍物
void CAStarMap::AddStaticObstacle(float x, float y)
{
    MaskOperator(x,y,ADD_STATICMASK,false);
}

void CAStarMap::DelStaticObstacle(float x, float y)
{
    MaskOperator(x,y,DEL_STATICMASK,false);
}

void CAStarMap::AddDynamicObstacle(float x, float y,float face, bool obstacleEx,unsigned maskType)
{
    MaskOperator(x,y,ADD_DYNAMICMASK,obstacleEx);
}

void CAStarMap::DelDynamicObstacle(float x, float y,float face, bool obstacleEx,unsigned maskType )
{
    MaskOperator(x,y,DEL_DYNAMICMASK,obstacleEx);
}

void CAStarMap::CalcObstacleArea_LeftRight(float x, float y,float radius,int& l,int& t,int& r,int& b) const
{
    //1.左右对齐方式
    int agentCell = (int)ceil(radius*2/m_fXTileSize);
    int ix,iy;
    PointToIndex(x,y,ix,iy);
    r = ix+(agentCell/2);
    b = iy+(agentCell/2);
    l = r-agentCell+1;
    t = b-agentCell+1;
}

void CAStarMap::CalcObstacleArea_Crc(float x, float y,float radius,int& l,int& t,int& r,int& b) const
{
    //2.周圈均匀分布方式
    float left,top,bottom,right;
    left   = x - radius;
    top    = y - radius;
    right  = x + radius;
    bottom = y + radius;

    PointToIndex(left,top,l,t);
    PointToIndex(right,bottom,r,b);
}

void CAStarMap::CalcObstacleArea(float x, float y,float radius,int& l,int& t,int& r,int& b) const
{
#ifdef USE_CRC_AREA
    CalcObstacleArea_Crc(x,y,radius,l,t,r,b);
#else
    CalcObstacleArea_LeftRight(x,y,radius,l,t,r,b);
#endif
}

void CAStarMap::AddStaticObstacle(float x, float y,float face, float radius,float retRadius,unsigned maskType)
{
	int l,t,r,b;
	if ( maskType == UNIT_MASK_TYPE_RECTANGLE )
	{
		Vec2f pos;
		GetNearPoint2D(x,y,pos.x,pos.y,radius/2.f,face);
		CalcObstacleArea(pos.x,pos.y,radius/2.f+retRadius/2.f,l,t,r,b);
	}
	else
		CalcObstacleArea(x,y,radius,l,t,r,b);
    //MaskOperator(l,t,r,b,ADD_STATICMASK,false);
	MaskOperator(l,t,r,b,ADD_STATICMASK,false,radius,retRadius,x,y,maskType,face);
}

void CAStarMap::DelStaticObstacle(float x, float y,float face, float radius,float retRadius,unsigned maskType)
{
	int l,t,r,b;
	if ( maskType == UNIT_MASK_TYPE_RECTANGLE )
	{
		Vec2f pos;
		GetNearPoint2D(x,y,pos.x,pos.y,radius/2.f,face);
		CalcObstacleArea(pos.x,pos.y,radius/2.f+retRadius/2.f,l,t,r,b);
	}
	else
		CalcObstacleArea(x,y,radius,l,t,r,b);
    //MaskOperator(l,t,r,b,DEL_STATICMASK,false);
	MaskOperator(l,t,r,b,DEL_STATICMASK,false,radius,retRadius,x,y,maskType,face);
}

void CAStarMap::AddDynamicObstacle(float x, float y,float face, float radius,float retRadius, bool obstacleEx,unsigned maskType)
{
	int l,t,r,b;
	if ( maskType == UNIT_MASK_TYPE_RECTANGLE )
	{
		Vec2f pos;
		GetNearPoint2D(x,y,pos.x,pos.y,radius/2.f,face);
		CalcObstacleArea(pos.x,pos.y,radius/2.f+retRadius/2.f,l,t,r,b);
	}
	else
		CalcObstacleArea(x,y,radius,l,t,r,b);
    MaskOperator(l,t,r,b,ADD_DYNAMICMASK,obstacleEx,radius,retRadius,x,y,maskType,face);
}

void CAStarMap::DelDynamicObstacle(float x, float y, float face,float radius,float retRadius, bool obstacleEx,unsigned maskType)
{
	int l,t,r,b;
	if ( maskType == UNIT_MASK_TYPE_RECTANGLE )
	{
		Vec2f pos;
		GetNearPoint2D(x,y,pos.x,pos.y,radius/2.f,face);
		CalcObstacleArea(pos.x,pos.y,radius/2.f+retRadius/2.f,l,t,r,b);
	}
	else
		CalcObstacleArea(x,y,radius,l,t,r,b);
    MaskOperator(l,t,r,b,DEL_DYNAMICMASK,obstacleEx,radius,retRadius,x,y,maskType,face);
}

// 判断宽度为dwAgentSize的单位能不能到达目标点
bool CAStarMap::CanMove(int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle,bool bUseDynamicObstacleEx, int nTargetX, int nTargetY) const
{
    assert(dwAgentSize >= 1);
    int Xupr = nTargetX+(dwAgentSize/2);
    int Xlow = Xupr-dwAgentSize+1;
    int Yupr = nTargetY+(dwAgentSize/2);
    int Ylow = Yupr-dwAgentSize+1;

    for (int k0 = Xlow;k0<=Xupr;k0++)
    {
        for (int k1 = Ylow;k1<=Yupr;k1++)
        {
            const CMapNode* pMapNode = GetMapNode(k0, k1);
            if (pMapNode == NULL)
            {
                continue;
            }

            if(!pMapNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
            {
                return false;
            }
        }
    }
    return true;
}

bool CAStarMap::CanMove(bool bUseStaticObstacle, bool bUseDynamicObstacle,bool bUseDynamicObstacleEx, int nTargetX, int nTargetY) const
{
	const CMapNode* pMapNode = GetMapNode(nTargetX, nTargetY);
	if (pMapNode == NULL)
	{
		assert(0);
		return false;
	}

	if(!pMapNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
	{
		return false;
	}

	return true;
}

bool CAStarMap::CanMove(float x, float y, float radius, bool bUseStaticObstacle, bool bUseDynamicObstacle,bool bUseDynamicObstacleEx) const
{
	//DEBUG_TRY

    int il,it,ir,ib;
    CalcObstacleArea(x,y,radius,il,it,ir,ib);
    for (int i=il;i<=ir;++i)
    {
        for (int j=it;j<=ib;++j)
        {
            const CMapNode* pMapNode = GetMapNode(i, j);
            if (pMapNode == NULL)
            {
                continue;
            }

            if(!pMapNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
            {
                return false;
            }
        }
    }

	//DEBUG_CATCH(" CAStarMap:: CAStarMap::CanMove");
    return true;
}

// 指定范围点附近有效果的点
bool CAStarMap::CalcClosestNodeByCell(float fx, float fy, float radius,float& cx,float& cy,float& cz, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx,unsigned maxCell) const
{
    if (CanMove(fx, fy , radius, bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
    {
        return GetMapNodeByPoint(fx, fy);
    }

    int m,n;
    PointToIndex(fx, fy, m, n);
    Vec2i vbg(m,n);

    const CMapNode* pNearest = NULL;
    float fNearestF = 0.0f;

    int nMaxRadius = maxCell;
    for (int i = m-nMaxRadius;i<=m+nMaxRadius;i++)
    {
        for (int j = n-nMaxRadius;j<=n+nMaxRadius;j++)
        {
            const CMapNode* p = GetMapNode(i, j);
            if (p == NULL)
            {
                continue;
            }
            const Vec2f& center = p->GetCenter();
            if (p != NULL && CanMove(center.x,center.y,radius, bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
            {
                float fDisF = Vec2f(fx, fy).dist2q(center);
                if (pNearest == NULL
                    || (fDisF < fNearestF))
                {
                    pNearest = p;
                    fNearestF = fDisF;
                }
            }
        }
    }
    bool ret = true;
    if (!pNearest)
    {
        ret = false;
        pNearest = GetMapNodeByPoint(fx,fy);
        if (!pNearest)
        {
            assert(0);
            return false;
        }
    }
    pNearest->GetCenter(cx,cy);
    cz = pNearest->GetHeight();
    return ret;
}



// 查找点附近的有效节点
bool CAStarMap::CalcClosestNode(float fx, float fy, float radius,float& cx,float& cy,float& cz, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
	//DEBUG_TRY

    const CMapNode* node = CalcClosestNode(fx,fy,radius,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx);
    bool ret = true;
    if (!node)
    {
        ret = false;
        node = GetMapNodeByPoint(fx,fy);
        if (!node)
        {
            assert(0);
            return false;
        }
    }
    node->GetCenter(cx,cy);
    cz = node->GetHeight();

	/*DEBUG_CATCH(" CAStarMap:: CalcClosestNode");*/

    return ret;

	//DEBUG_CATCH(" CAStarMap:: CalcClosestNode");
}

const CMapNode* CAStarMap::CalcClosestNode(float fx, float fy, float radius, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
    if (CanMove(fx, fy , radius, bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
    {
        return GetMapNodeByPoint(fx, fy);
    }

    int m,n;
    PointToIndex(fx, fy, m, n);
    Vec2i vbg(m,n);

    const CMapNode* pNearest = NULL;
    float fNearestF = 0.0f;

    int nMaxRadius = 20;
    for (int i = m-nMaxRadius;i<=m+nMaxRadius;i++)
    {
        for (int j = n-nMaxRadius;j<=n+nMaxRadius;j++)
        {
            const CMapNode* p = GetMapNode(i, j);
            if (p == NULL)
            {
                continue;
            }
            const Vec2f& center = p->GetCenter();
            if (p != NULL && CanMove(center.x,center.y,radius, bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx))
            {
                float fDisF = Vec2f(fx, fy).dist2q(center);
                if (pNearest == NULL
                    || (fDisF < fNearestF))
                {
                    pNearest = p;
                    fNearestF = fDisF;
                }
            }
        }
    }

    return pNearest;
}


CMapNode* CAStarMap::GetMapNode(int x, int y)
{
    if (x>=0&&y>=0&&x<m_width&&y<m_height)
        return &m_nodes[(x*m_height)+y];
    else
        return NULL;
}

CMapNode* CAStarMap::GetMapNode(int nIndex)
{
    assert(nIndex>=0&&nIndex<(m_width*m_height));
    return &m_nodes[nIndex];
}

bool CAStarMap::PointToIndex(float fX, float fY, int& ix, int& iy) const
{
    if (fX < m_vMapMin.x || fY < m_vMapMin.y
        || fX > m_vMapMax.x || fY > m_vMapMax.y)
    {
        assert(0);
        ix=iy=0;
        return false;
    }
    ix = (int)/*floorf*/((fX - m_vMapMin.x)/m_fXTileSize);
    iy = (int)/*floorf*/((fY - m_vMapMin.y)/m_fYTileSize);
    return true;
}

CMapNode* CAStarMap::GetMapNodeByPoint(float fX, float fY)
{
    int ix,iy;
    if (!PointToIndex(fX,fY,ix,iy))
    {
        return NULL;
    }
    return GetMapNode(ix,iy);
}

void CAStarMap::GetNearPoint2D(float srcX, float srcY, float &x, float &y, float distance2d, float absAngle ) const
{
	x = srcX + distance2d * cos(absAngle);
	y = srcY + distance2d * sin(absAngle);

	NormalizeMapCoord(x);
	NormalizeMapCoord(y);
}

void CAStarMap::NormalizeMapCoord(float &c) const
{
	if(c > 16384 - 0.5)
		c = 16384 - 0.5;
	else if(c < -(16384 - 0.5))
		c = -(16384 - 0.5);
}

const CMapNode* CAStarMap::GetMapNode(int x, int y) const
{
    if (x>=0&&y>=0&&x<m_width&&y<m_height)
        return &m_nodes[(x*m_height)+y];
    else
        return NULL;
}

const CMapNode* CAStarMap::GetMapNode(int nIndex) const
{
    assert(nIndex>=0&&nIndex<(m_width*m_height));
    return &m_nodes[nIndex];
}

const CMapNode* CAStarMap::GetMapNodeByPoint(float fX, float fY) const
{
    int ix,iy;
    if (!PointToIndex(fX,fY,ix,iy))
    {
        return NULL;
    }
    return GetMapNode(ix,iy);
}

bool CAStarMap::FindPath(IPathSearchObject* iobjs,int num)
{
	if (iobjs == NULL)
	{
		return false;
	}
    CPathSearchObject* objs = dynamic_cast<CPathSearchObject*>(iobjs);
    if(!objs)
    {
        assert(objs);
        return false;
    }


    CPathSearchObject& obj = objs[0];
#ifdef _DEBUG
	int agentCell = (int)ceil(obj.m_radius*2/m_fXTileSize);
#else
	int agentCell = (int)ceil(obj.m_radius*2/m_fXTileSize);
#endif // _DEBUG
//     CMapNode* start = CalcClosestNode(agentCell,obj.m_staticObstacle,obj.m_dynamicObstacle,obj.m_fBeginX,obj.m_fBeginY);
//     CMapNode* end = CalcClosestNode(agentCell,obj.m_staticObstacle,obj.m_dynamicObstacle,obj.m_fEndX,obj.m_fEndY);
//     if (start == NULL)
//     {
        const CMapNode* start = GetMapNodeByPoint(obj.m_fBeginX,obj.m_fBeginY);
//     }
//     if (end == NULL)
//     {
        const CMapNode* end = GetMapNodeByPoint(obj.m_fEndX,obj.m_fEndY);
//     }

	//DEBUG_TRY

    if (!start || !end)
    {
        obj.Clear();
        return false;
    }

    if (start == end)
    {
        obj.Clear();
        obj.AddPoint(Vec3f(obj.m_fBeginX,obj.m_fBeginY,start->GetHeight()));
        obj.AddPoint(Vec3f(obj.m_fEndX,obj.m_fEndY,end->GetHeight()));
        return true;
    }

	bool bAutoUseDynamic = obj.m_eObstacleRule == AutoDynamic;
    m_pathfinder.SetSpecParam(obj.m_staticObstacle,obj.m_dynamicObstacle,obj.m_dynamicObstacleEx, agentCell, obj.m_eObstacleRule);
    m_pathfinder.SetStartAndGoalStates(*start,*end);

	//DEBUG_CATCH("CAStarMap::FindPath:: m_pathfinder.SetSpecParam");

	if (obj.m_nodeLimited < 0)
	{
		assert(0);
	}
    unsigned int limit = obj.m_nodeLimited;
    unsigned int i=1;
	//DEBUG_TRY

    while(m_pathfinder.SearchStep()==AStarSearch<CMapNode>::SEARCH_STATE_SEARCHING)
    {
        ++i;
        if (i>limit)
        {
            m_pathfinder.CancelSearch();
            break;
        }
    }

	//DEBUG_CATCH("CAStarMap::FindPath:: m_pathfinder.SearchStep()");


	//DEBUG_TRY

    obj.Clear();
    if (m_pathfinder.GetStepCount()<2)
    {
        return false;
    }

	// 路径平滑
    vector<const CMapNode*> vecNodes;
    const CMapNode* node = m_pathfinder.GetSolutionStart();
    start = node;
    while(node)
    {
        if (vecNodes.size()>limit)
        {
            assert(0);
            return false;
        }
        vecNodes.push_back(node);
		node = m_pathfinder.GetSolutionNext();
    }

	if (!obj.m_optimize)
	{
		for (size_t i = 0; i < vecNodes.size(); i++)
		{
			const CMapNode* pNode = vecNodes[i];
			obj.m_vecPoints.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));
		}
		return true;
	}

	int nLastUseDynamicNodePos = 0;
	if (obj.m_eObstacleRule == AutoDynamic || obj.m_eObstacleRule == AutoDynamicEx)
	  nLastUseDynamicNodePos = vecNodes.size() - m_pathfinder.GetUnUseDynamicNodeCount() - 1;

	// 这个最好找个适当的地方调用
	m_opt.Init(this);
	m_opt.Process(vecNodes,obj.m_vecPoints,start,agentCell,obj.m_staticObstacle,obj.m_dynamicObstacle,obj.m_dynamicObstacleEx, nLastUseDynamicNodePos,obj.m_dynamicObstacleOptimize);

    return true;
}

IAStarMap* IAStarMap::CreateAStarMap(const char* pszFile)
{
    return new CAStarMap(pszFile);
}

IAStarMap* IAStarMap::CreateAStarMap(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count)
{
    return new CAStarMap(fMapMinX,fMapMinY,fMapMaxX,fMapMaxY,fCellSize,pNodes,count);
}

IAStarMap* IAStarMap::CreateAStarMap(IAStarMap* map)
{
    return new CAStarMap(dynamic_cast<CAStarMap*>(map));
}

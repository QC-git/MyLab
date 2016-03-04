#include "MapNode.h"
#include "AStarMap.h"

void CMapNode::InitMapInfo(CAStarMap* map,int x,int y,float z)
{
    m_nStaticObstacle=0;
    m_nDynamicObstacle=0;
    m_nDynamicObstacleEx=0;
    m_map=map;m_x=x;m_y=y;m_z=z;
    if (map) m_hashCode = (m_x*m_map->Height()+m_y);
    else m_hashCode = 0;
}

const CMapNode* CMapNode::FilterInValidNode(int x,int y, const CMapNode *parent_node, int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
    const CMapNode* nextNode = m_map->GetMapNode(x,y);
    if (!FilterInValidNode(nextNode,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx))
    {
        return NULL;
    }

    return nextNode;
}

bool CMapNode::FilterInValidNode(const CMapNode* nextNode, const CMapNode *parent_node, int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
    if (!nextNode || nextNode==parent_node)
    {
        return false;
    }
    if (!m_map->CanMove(dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx,nextNode->m_x,nextNode->m_y))
    {
        return false;
    }
    return true;
}


bool CMapNode::GetSuccessors( AStarSearch<CMapNode> *astarsearch, const CMapNode *parent_node, int dwAgentSize, bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
    bool cml=false;
    bool cmr=false;
    bool cmt=false;
    bool cmb=false;
    const CMapNode* nextNode;

    // left
    nextNode = m_map->GetMapNode(m_x-1,m_y);
    if (nextNode)
    {
        if (FilterInValidNode(nextNode,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx))
        {
            astarsearch->AddSuccessor(nextNode);
			cml=nextNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx);
        }
    }
    //top
    nextNode = m_map->GetMapNode(m_x,m_y-1);
    if (nextNode)
    {
        if (FilterInValidNode(nextNode,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx))
        {
            astarsearch->AddSuccessor(nextNode);
			cmt=nextNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx);
        }
    }
    //right
    nextNode = m_map->GetMapNode(m_x+1,m_y);
    if (nextNode)
    {
        if (FilterInValidNode(nextNode,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx))
        {
            astarsearch->AddSuccessor(nextNode);
			cmr=nextNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx);
        }
    }
    //bottom
    nextNode = m_map->GetMapNode(m_x,m_y+1);
    if (nextNode)
    {
        if (FilterInValidNode(nextNode,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx))
        {
            astarsearch->AddSuccessor(nextNode);
			cmb=nextNode->IsValid(bUseStaticObstacle, bUseDynamicObstacle,bUseDynamicObstacleEx);
        }
    }

    if (cmt)
    {
        //topleft
        if (cml)
        {
            nextNode = FilterInValidNode(m_x-1,m_y-1,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx);
            if (nextNode)
            {
                astarsearch->AddSuccessor(nextNode);
            }
        }
        //topright
        if (cmr)
        {
            nextNode = FilterInValidNode(m_x+1,m_y-1,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx);
            if (nextNode)
            {
                astarsearch->AddSuccessor(nextNode);
            }
        }
    }

    if (cmb)
    {
        //bottomleft
        if (cml)
        {
            nextNode = FilterInValidNode(m_x-1,m_y+1,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx);
            if (nextNode)
            {
                astarsearch->AddSuccessor(nextNode);
            }
        }
        //bottomright
        if (cmr)
        {
            nextNode = FilterInValidNode(m_x+1,m_y+1,parent_node,dwAgentSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx);
            if (nextNode)
            {
                astarsearch->AddSuccessor(nextNode);
            }
        }
    }
    return true;
}


bool CMapNode::IsValid(bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
    if (bUseStaticObstacle)
    {
        if (m_nStaticObstacle > 0)
        {
            return false;
        }
    }
    if (bUseDynamicObstacle)
    {
        if (m_nDynamicObstacle > 0)
        {
            return false;
        }
    }

    if (bUseDynamicObstacleEx)
    {
        if (m_nDynamicObstacleEx > 0)
        {
            return false;
        }
    }
    return true;
}

bool CMapNode::IsNeiborValid(int dwAgentCellSize,bool bUseStaticObstacle, bool bUseDynamicObstacle, bool bUseDynamicObstacleEx) const
{
    //const CMapNode* node;
    //node = m_map->GetMapNode(m_x-1,m_y-1);
    for (int i=m_x-1;i<=m_x+1;++i)
    {
        for (int j=m_y-1;j<=m_y+1;++j)
        {
            if(!m_map->CanMove(dwAgentCellSize,bUseStaticObstacle,bUseDynamicObstacle,bUseDynamicObstacleEx,i,j))
            {
                return false;
            }
        }
    }
    return true;

//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x,m_y-1);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x+1,m_y-1);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x-1,m_y);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x+1,m_y);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x-1,m_y+1);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x,m_y+1);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     node = m_map->GetMapNode(m_x+1,m_y+1);
//     if (!node->IsValid(bUseStaticObstacle,bUseDynamicObstacle))
//     {
//         return false;
//     }
//     return true;
}

void CMapNode::AddDynamicObstacle(bool dynamicObstacleEx)
{
    if (dynamicObstacleEx)
    {
        ++m_nDynamicObstacleEx;
    }
    else
    {
        ++m_nDynamicObstacle;
    }
}

void CMapNode::DelDynamicObstacle(bool dynamicObstacleEx)
{
    if(!dynamicObstacleEx && m_nDynamicObstacle>0)
        --m_nDynamicObstacle;
    if (dynamicObstacleEx && m_nDynamicObstacleEx>0)
        --m_nDynamicObstacleEx;
}




#include "Optimize.h"
#include "Intersection.h"
#include "assert.h"
#include "AStarMap.h"
#include "inttypes.h"
#include <algorithm>

using namespace std;

COptimize::COptimize(void)
{
}

COptimize::~COptimize(void)
{
}

bool COptimize::Init(CAStarMap* pMap, OPTIMIZE_ALGORITHM eAlgorithm, CENTER_POINT_POSITION eCenter)
{
	if (!pMap)
		return false;

	m_eAlgorithm= eAlgorithm;
	m_eCenter	= eCenter;
	m_pMap		= pMap;
	return true;
}

void COptimize::Process(VEC_NODE& deqPathNode, VEC_D3DXVECTOR3& vecOut, const CMapNode* pBeginNode, int dwAgentCellSize, bool bStatic, bool bDynamic,  bool bDynamicEx, int nLastUseDynamicNodePos,bool dOptimize)
 {
	m_pVecPathNode = &deqPathNode;
	m_pVecOut = &vecOut;
	m_pBeginNode = pBeginNode;
	m_dwAgentCellSize = dwAgentCellSize;

 	m_bUseStaticObstacle = bStatic;
 	m_bUseDynamicObstacle = bDynamic;
    m_bUseDynamicObstacleEx = bDynamicEx;
    m_dOptimize  = dOptimize;

	m_nLastUseDynamicNodePos = nLastUseDynamicNodePos;

#ifdef _PERFORMANCE_TEST_
	// debug经过测试对一段很长的路径los的效率是30m tick左右
	// 而MergeVisibleNodes的效率大概在10m tick左右
	// 新算法的优化效率是原算法的3倍，所得路径点缩短为原来1/10
	LARGE_INTEGER nTickBegin;
	LARGE_INTEGER nTickEnd;
	::QueryPerformanceCounter(&nTickBegin);
#endif
	if (OPTIMIZE_LOS == m_eAlgorithm)
	{
		LOS();
	}
	else if (OPTIMIZE_MVN == m_eAlgorithm)
	{
		MergeVisibleNodes(*m_pVecPathNode, *m_pVecOut);
	}
	else
	{
		assert(false);
	}
#ifdef _PERFORMANCE_TEST_
	::QueryPerformanceCounter(&nTickEnd);
	LARGE_INTEGER feq;
	::QueryPerformanceFrequency(&feq);
	int nTimeMS = int((nTickEnd.QuadPart - nTickBegin.QuadPart)*1000000 / feq.QuadPart);
	nTimeMS = 0;
#endif // _DEBUG
}

void COptimize::LinearMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nSize)
{
	// 双游标扫描
	// 如果要进一步平滑路径点可以增加折半回溯之类的操作，消耗时间会有所增加
	int nIndex1 = 0;
	int nIndex2 = 2;

	const CMapNode* pNode = vecNode[nIndex1];
	vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));

	while(nIndex2 != nSize)
	{
		const CMapNode* pNode1 = vecNode[nIndex1];
		const CMapNode* pNode2 = vecNode[nIndex2];

		if (!pNode1 && pNode2)
		{
			assert(0);
			nIndex1 = nIndex2;
			nIndex2++;
			continue;
		}

		if (this->CanSeeEx(pNode1, pNode2) )//&& nIndex != (nEnd-1))
		{
			nIndex2++;
		}
		else
		{
			// 如果 p1看不见p2，则插入p2前一个点，因为p2前一个点在寻路时肯定能通过p2
			nIndex2--;

			if (nIndex2 != 0)
			{
				const CMapNode* pNodePre = vecNode[nIndex2];
				vecOut.push_back(Vec3f(pNodePre->GetCenter().x, pNodePre->GetCenter().y, pNodePre->GetHeight()));
			}

			// 如果相邻2个点不可达,可能是算法严格性问题,跳过该点
			if (nIndex1 == nIndex2)
			{
				nIndex1++;
				nIndex2+=2;
				continue;
			}

			//nIndex2++;

			nIndex1 = nIndex2;
			nIndex2+=2;//nIndex2++;
			if (nIndex2 >= nSize)
			{
				// 到最后一个点，插入之前保存的index1
				if (nIndex1 != 0)
				{
					pNode = vecNode[nIndex1];
					vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));
				}
			}
			//vecOut.push_back(Vec3f(pNode2->GetCenter().x, pNode2->GetCenter().y, pNode2->GetHeight()));
		}
	}

	pNode = vecNode[nSize-1];
	vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));
}

void COptimize::DichotomyMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nSize)
{
	nSize--;
	int nIndex1 = 0;
	int nIndex2 = nSize;
	int nPass = nIndex1 + 1;
	int nBlock = nSize;
	int nTemp = 0;

	const CMapNode* pNode = vecNode[nIndex1];
	vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));

	while(1)
	{
		nTemp++;
		if (nTemp > 10000 )
		{
			assert(0);
			break;
		}

		const CMapNode* pNode1 = vecNode[nIndex1];
		const CMapNode* pNode2 = vecNode[nIndex2];

		if (this->CanSeeEx(pNode1, pNode2) )//&& nIndex != (nEnd-1))
		{
			if (nIndex2 == nSize)
			{
				pNode = pNode2;
				vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));
				break;
			}
			else if (nIndex2 == (nBlock-1))
			{
				pNode = pNode2; //vecNode[nIndex2];
				vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));

				nIndex1 = nIndex2;
                nPass = nIndex1 + 1;
				nIndex2 = nBlock = nSize;
			}
			else
			{
				nPass = nIndex2;
				nIndex2 += (int)((nBlock-nIndex2)/2);
			}
		}
		else
		{
			nBlock = nIndex2;
			if (nPass == nBlock)
			{
				pNode = vecNode[nPass];
				vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));

				nIndex1 = nPass;
                nPass = nIndex1 + 1;
				nIndex2 = nBlock = nSize;
			}
			else
			{
				nIndex2 = nPass + (int)((nIndex2-nPass)/2);
			}
		}
	}
}

void COptimize::MergeVisibleNodes(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut)
{
	int nSize = static_cast<int>(vecNode.size());
	if (nSize <= 2)
	{
		for (VEC_NODE::const_iterator iter = vecNode.begin(); iter != vecNode.end(); iter++)
		{
			const CMapNode* pNode = *iter;
			if (!pNode)
				continue;

			vecOut.push_back(Vec3f(pNode->GetCenter().x, pNode->GetCenter().y, pNode->GetHeight()));
		}
		return;
	}
#ifdef _DEBUG
	for (VEC_NODE::const_iterator iter = vecNode.begin(); iter != vecNode.end(); iter++)
	{
		const CMapNode* pNode = *iter;
		if (!pNode)
			continue;

		int z = 0;
	}
#endif

#ifdef _DEBUG
	static int nMergeFunction = MERGE_FUNCTION_DICHOTOMY;
#else
	int nMergeFunction = MERGE_FUNCTION_DICHOTOMY;
#endif // _DEBUG
	
	if (nMergeFunction == MERGE_FUNCTION_LINEAR)
	{
		this->LinearMerge(vecNode, vecOut, nSize);
	}
	else if (nMergeFunction == MERGE_FUNCTION_DICHOTOMY)
	{
		if (m_nLastUseDynamicNodePos == 0)
			DichotomyMerge(vecNode, vecOut, nSize);
		else
			AutoDynamicMerge(vecNode, vecOut, m_nLastUseDynamicNodePos);
	}
	else
	{
		assert(0);
		return;
	}
	return;
}

void COptimize::AutoDynamicMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nLastUseDynamicNodePos)
{
    int nNodeCount = static_cast<int>(vecNode.size());

	if (nLastUseDynamicNodePos < nNodeCount)
	{
        m_bUseStaticObstacle = true;
        if (m_dOptimize)
        {
            m_bUseDynamicObstacle   = true;
            m_bUseDynamicObstacleEx = false;
        }
        else
        {
            m_bUseDynamicObstacle   = false;
            m_bUseDynamicObstacleEx = true;
        }
		VEC_NODE frontNodes(vecNode.begin(), vecNode.begin() + nLastUseDynamicNodePos);
        this->DichotomyMerge(frontNodes, vecOut, static_cast<int>(frontNodes.size()));
	}

	if (nLastUseDynamicNodePos + 1 < nNodeCount)
	{
		m_bUseStaticObstacle = true;
		m_bUseDynamicObstacle = false;
        m_bUseDynamicObstacleEx = false;
		VEC_D3DXVECTOR3 vecD3dVector;
		VEC_NODE backNodes(vecNode.begin() + nLastUseDynamicNodePos, vecNode.end());
        this->DichotomyMerge(backNodes, vecD3dVector, static_cast<int>(backNodes.size()));
		vecOut.insert(vecOut.end(), vecD3dVector.begin(), vecD3dVector.end());
	}
}

void COptimize::LOS()
{
	vector<bool> vecOptimizeNode(m_pVecPathNode->size());
	CalcOptimizeNodes(vecOptimizeNode);

	const int dwThredhold = 16;

	int nBeginIndex = 0;
	int nEndIndex = dwThredhold;

	const CMapNode* pV0 = this->GetPathNode(nBeginIndex);
    const CMapNode* pDest = this->GetPathNode(static_cast<unsigned int>(m_pVecPathNode->size() - 1));
	if (!pV0 || !pDest)
	{
		return;
	}
	if (m_pVecOut == NULL)
	{
		return;
	}

	if (m_pVecPathNode == NULL)
	{
		return;
	}
	m_pVecOut->push_back(Vec3f(pV0->GetCenter().x, pV0->GetCenter().y, pV0->GetHeight()));


	//DEBUG_TRY

	while (pV0 != pDest)
	{
		if (nEndIndex > (int)m_pVecPathNode->size() -1)
		{
            nEndIndex = static_cast<int>(m_pVecPathNode->size() - 1);
		}

		nEndIndex = CalcFarestOptimizeIndex(nBeginIndex, nEndIndex, vecOptimizeNode);

		const CMapNode* pV1 = GetPathNode(nEndIndex);
		if (pV1 == NULL)
		{
			return;
		}
		if (pV0 == pV1)
		{
			pV0 = GetPathNode(++nBeginIndex);
			
			if (pV0 ==NULL)
			{
				return;
			}

			// 此注释的功能表示先到中点，再到目标点
// 			if (nEndIndex == 0)
// 			{
// 				m_pVecOut->push_back(pV1->GetAbsoluteCenter());
// 			}
// 			
// 			if (nBeginIndex == m_pVecPathNode->size() -1)
// 			{
// 				m_pVecOut->push_back(pV0->GetAbsoluteCenter());
// 				m_pVecOut->push_back(pV0->GetCenter());
// 			}
// 			else
// 			{
				m_pVecOut->push_back(Vec3f(pV0->GetCenter().x, pV0->GetCenter().y, pV0->GetHeight()));
//			}
			
			nEndIndex = nBeginIndex + dwThredhold;
		}
		else if(this->CanSee(pV0, pV1))
		{
			m_pVecOut->push_back(Vec3f(pV1->GetCenter().x, pV1->GetCenter().y, pV1->GetHeight()));

			pV0 = pV1;
			nBeginIndex = nEndIndex;
			nEndIndex += dwThredhold;
			if (nEndIndex > (int)m_pVecPathNode->size() -1)
			{
                nEndIndex = static_cast<int>(m_pVecPathNode->size() - 1);
			}
		}
		else
		{
			nEndIndex--;
		}
	}

	//DEBUG_CATCH("COptimize::LOS:: while (pV0 != pDest);");
}

// 合并无障碍路径
// 其实用deque会比vec好很多，不过所有地方都用vec，测试时就先不改了
/*
bool COptimize::MergeVisibleNodes(DEQ_NODE* pDeqPathNode)
{
	if(!pDeqPathNode)
		return true;

	int nIndex = 0;
	int nEnd = pDeqPathNode->size();
	for (DEQ_NODE::iterator iter = pDeqPathNode->begin(); iter != pDeqPathNode->end();)
	{
		const CMapNode* pNode0 = *iter;
		const CMapNode* pNode1 = *(++iter);
		if (iter + 1 == pDeqPathNode->end())
		{
			break;
		}

		if (this->CanSee(pNode0, pNode1) )//&& nIndex != (nEnd-1))
		{
			iter = pDeqPathNode->erase(iter);
			iter--;
		}
	}

	return true;
}
*/

bool COptimize::CanSeeEx(const CMapNode* pN0, const CMapNode* pN1)
{
	if (pN0 == NULL || pN1 == NULL)
	{
		return false;
	}

	if (pN0 == pN1)
	{
		return true;
	}

	// 注释掉，当邻接节点中有障碍物时就不可走了
	// 	if (this->IsNeiborNode(pN0, pN1))
	// 	{
	// 		return true;
	// 	}

	VEC_NODE vecObstacle;
	//if(!this->FindObstacles(pN0, pN1, vecObstacle))
	if(!this->FindObstaclesEx(pN0, pN1, vecObstacle, m_dwAgentCellSize, m_eCenter))
	{
		return false;
	}

	return true;
}

bool COptimize::CanSee(const CMapNode* pN0, const CMapNode* pN1)
{
	if (pN0 == NULL || pN1 == NULL)
	{
		return false;
	}

	if (pN0 == pN1)
	{
		return true;
	}

	// 注释掉，当邻接节点中有障碍物时就不可走了
// 	if (this->IsNeiborNode(pN0, pN1))
// 	{
// 		return true;
// 	}

	VEC_NODE vecObstacle;
	if(!this->FindObstacles(pN0, pN1, vecObstacle))
	{
		return true;
	}

	for (unsigned dw = 0;dw<vecObstacle.size();dw++)
	{
		const CMapNode* p = vecObstacle[dw];
		if (p == NULL)
		{
			continue;
		}

		Vec2f v0, v1, v2, v3;
        p->GetBox(v0, v1, v2, v3);

		if( CIntersection::IntersectOfSegmentAndBox(pN0->GetCenter(), pN1->GetCenter(), v0, v1, v2, v3))
		{
			return false;
		}
	}

	return true;
}

const CMapNode* COptimize::GetPathNode(unsigned dwIndex)
{
	if (dwIndex < 0 || dwIndex >= m_pVecPathNode->size())
	{
		return NULL;
	}

	//DEQ_NODE::iterator iter = m_pDeqPathNode->find(dwIndex);
	//if (iter == m_pDeqPathNode->end())
	//	return NULL;
	//return *iter;

	return m_pVecPathNode->at(dwIndex);
}

bool COptimize::FindObstacles( const CMapNode* pN0, const CMapNode* pN1, VEC_NODE& vecObstacleNode )
{
	assert(pN0 != NULL && pN1 != NULL);
	assert(vecObstacleNode.empty());

	int x0 = 0, x1 = 0, y0 = 0, y1 = 0;
	pN0->GetIndex(x0, y0);
	pN1->GetIndex(x1, y1);
	int nMinX = min(x0, x1);
	int nMaxX = max(x0, x1);
	int nMinY = min(y0, y1);
	int nMaxY = max(y0, y1);

	for (int i = nMinX;i<= nMaxX;i++)
	{
		for (int j = nMinY;j<= nMaxY;j++)
		{
			const CMapNode* p = m_pMap->GetMapNode(i, j);
			if (p == NULL)
			{
				continue;
			}

			// 忽略掉起点障碍物
			if (p == m_pBeginNode)
			{
				continue;
			}

			if (p->IsValid(m_bUseStaticObstacle, m_bUseDynamicObstacle,m_bUseDynamicObstacleEx))//可走
			{
				if (m_dwAgentCellSize > 1)
				{
					if (m_pMap->CanMove(m_dwAgentCellSize, m_bUseStaticObstacle, m_bUseDynamicObstacle,m_bUseDynamicObstacleEx, i, j))
					{
						continue;
					}
				}
				else if(m_dwAgentCellSize <= 1)
				{
					continue;
				}
			}

			vecObstacleNode.push_back(p);
		}
	}

	return true;
}

bool COptimize::FindObstaclesEx(const CMapNode* pN0, const CMapNode* pN1, VEC_NODE& vecObstacleNode, const int nObjRaidus, const CENTER_POINT_POSITION eCenter)
{
	assert(pN0 != NULL && pN1 != NULL);
	int x1, y1, x2, y2;
	pN0->GetIndex(x1, y1);
	pN1->GetIndex(x2, y2);

	int nLeft = (m_dwAgentCellSize - 1) / 2;
	int nRight = m_dwAgentCellSize / 2;
	int nBottom = nLeft;
	int nTop = nRight;

	int minX = min(x1, x2);
	int maxX = max(x1, x2);
	int minY = min(y1, y2);
	int maxY = max(y1, y2);

	minX -= nLeft;
	maxX += nRight;
	minY -= nBottom;
	maxY += nTop;

	// 重心点线：y = ax + b
	// 下边缘线：y = ax + bb；上边缘线：y = ax + be
	float a = 0.0;
	float b = 0.0;
	float bb = 0.0;
	float be = 0.0;

	if (x1 != x2 && y1 != y2)
	{
		a = float(y2 - y1) / (x2 - x1);
		b = y1 - a * x1;

		if (a > 0)
		{
			bb = b - (a * (nRight + 0.5f) + nBottom + 0.5f);
			be = b + (a * (nLeft + 0.5f) + nTop + 0.5f);
		}
		else
		{
			float tempA = abs(a);
			bb = b - (tempA * (nLeft + 0.5f) + nBottom + 0.5f);
			be = b + (tempA * (nRight + 0.5f) + nTop + 0.5f);
		}
	}

	int beginY, endY;
	for (int x = minX; x <= maxX; x++)
	{
		if (x1 == x2 || y1 == y2)	// f(x): y = b or f(x): x = b
		{
			beginY = minY;
			endY = maxY;
		}
		else if (a > 0) 
		{
			beginY = int(floor(a * (x - 0.5) + bb + 0.5));
			endY = int(ceil(a * (x + 0.5) + be - 0.5));
			beginY = max(beginY, minY);
			endY = min(endY, maxY);
		}
		else if (a < 0)
		{
			beginY = int(floor(a * (x + 0.5) + bb + 0.5));
			endY = int(ceil(a * (x - 0.5) + be - 0.5));
			beginY = max(beginY, minY);
			endY = min(endY, maxY);
		}

 		for (int y = beginY; y <= endY; y++)
 		{
			const CMapNode* p = m_pMap->GetMapNode(x, y);
			if (p == NULL)
			{
				continue;
			}

			// 忽略掉起点障碍物
			if (p == m_pBeginNode)
			{
				continue;
			}

			if (p->IsValid(m_bUseStaticObstacle, m_bUseDynamicObstacle,m_bUseDynamicObstacleEx))
			{
				continue;
			}

			return false;
 		}
	}

	return true;
}

void COptimize::CalcOptimizeNodes(vector<bool>& vecOptimizeNodes )
{
	int nIndex = 0;
	for (VEC_NODE::const_iterator iter = m_pVecPathNode->begin();iter != m_pVecPathNode->end();iter++, nIndex++)
	{
		const CMapNode* pAStarNode = *iter;

        if (pAStarNode->IsNeiborValid(m_dwAgentCellSize,m_bUseStaticObstacle, m_bUseDynamicObstacle,m_bUseDynamicObstacleEx))
        {
            vecOptimizeNodes[nIndex] = true;
        }
        else
        {
            vecOptimizeNodes[nIndex] = false;
        }
	}
}

int COptimize::CalcFarestOptimizeIndex(int nBeginIndex, int nEndIndex, const vector<bool>& vecOptimizeNodes)
{
	if (nBeginIndex == nEndIndex)
	{
		return nBeginIndex;
	}

	if(vecOptimizeNodes[nBeginIndex] == false && vecOptimizeNodes[nBeginIndex+1] == false)
	{
		return nBeginIndex;
	}

	if (vecOptimizeNodes[nBeginIndex] == false)
	{
		for (int i = nBeginIndex+1;i <= nEndIndex;i++)
		{
			if(!vecOptimizeNodes[i])
			{
				return i-1;
			}
		}
	}
	else 
	{
		for (int i = nBeginIndex+1;i <= nEndIndex;i++)
		{
			if(!vecOptimizeNodes[i])
			{
				return i;
			}
		}
	}

	return nEndIndex;
}
#pragma once

#include <vector>
#include <deque>
#include "rts/vec.h"
#include "MapNode.h"
#include "inttypes.h"

//#define _PERFORMANCE_TEST_

//typedef std::deque<const CMapNode*> DEQ_NODE;
typedef std::vector<const CMapNode*> VEC_NODE;
typedef std::vector<Vec3f> VEC_D3DXVECTOR3;

enum CENTER_POINT_POSITION
{
	CENTER_POINT_CENTER = 0,	// ���ĵ���(n/2, n/2)��λ�ã�nΪ����߳�
	CENTER_POINT_LEFT_BOTTOM,	// ���ĵ������½�
};

enum OPTIMIZE_ALGORITHM
{
	OPTIMIZE_LOS,	// tzy д��ԭʼ�㷨
	OPTIMIZE_MVN,	// Raynor�Ľ������㷨
};

enum MERGE_FUNCTION
{
	MERGE_FUNCTION_NONE = 0,
	MERGE_FUNCTION_LINEAR,		// ���Ժϲ����������·��
	MERGE_FUNCTION_DICHOTOMY,	// ���ַ�������ƽ��·��(����ʵ�����Ч���ձ����Щ)
};

class COptimize
{
public:
	COptimize(void);
	~COptimize(void);

public:
	void Process(VEC_NODE& vecPathNode, VEC_D3DXVECTOR3& vecOut, const CMapNode* pBeginNode, int dwAgentCellSize, bool bStatic, bool bDynamic,  bool bDynamicEx,int nLastUseDynamicNodePos,bool dOptimize=true);
	bool Init(CAStarMap* pMap, OPTIMIZE_ALGORITHM eAlgorithm = OPTIMIZE_MVN, CENTER_POINT_POSITION eCenter = CENTER_POINT_CENTER);

	void SetAlgorithm(OPTIMIZE_ALGORITHM eAlgorithm)				{ m_eAlgorithm = eAlgorithm; }
	void SetCenterPointPositon(CENTER_POINT_POSITION eCenter)		{ m_eCenter = eCenter; }

private:
	void LOS();
	const CMapNode* GetPathNode(unsigned dwIndex);

	//bool MergeVisibleNodes(DEQ_NODE* pVecPathNode);
	//bool MergeVisibleNodes(VEC_D3DXVECTOR3& vecNodes);

	bool CanSee(const CMapNode* pN0, const CMapNode* pN1);
	bool FindObstacles(const CMapNode* pN0, const CMapNode* pN1, VEC_NODE& vecObstacleNode);

    void CalcOptimizeNodes(std::vector<bool>& vecOptimizeNodes);
    int CalcFarestOptimizeIndex(int nBeginIndex, int nEndIndex, const std::vector<bool>& vecOptimizeNodes);

	// Raynor�Ż��㷨
protected:
	void LinearMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nSize);		// ��������·��
	void DichotomyMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nSize);	// ����ƽ��·��
	//void IncreaseMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nSize);
	void MergeVisibleNodes(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut);
	bool CanSeeEx(const CMapNode* pN0, const CMapNode* pN1);

	void AutoDynamicMerge(const VEC_NODE& vecNode, VEC_D3DXVECTOR3& vecOut, int nLastUseDynamicNodePos);

	// nObjRaidusΪѰ·����뾶
	// eCenter��ʾ������ĵ��λ��
	bool FindObstaclesEx(const CMapNode* pN0, const CMapNode* pN1, VEC_NODE& vecObstacleNode, const int nObjRaidus, const CENTER_POINT_POSITION eCenter);
	// End

private:
	CENTER_POINT_POSITION		m_eCenter;	// ������ʾ���ĵ��λ��
	OPTIMIZE_ALGORITHM			m_eAlgorithm;

	VEC_NODE* m_pVecPathNode;
	VEC_D3DXVECTOR3* m_pVecOut;
	const CMapNode* m_pBeginNode;

	CAStarMap* m_pMap;
	int m_dwAgentCellSize;

	bool m_bUseStaticObstacle;
	bool m_bUseDynamicObstacle;
    bool m_bUseDynamicObstacleEx;
    bool m_dOptimize;

	int m_nLastUseDynamicNodePos;

};

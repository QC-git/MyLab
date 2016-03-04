#include "AStar_mask\AStarMap.h"
#include <assert.h>
#include <stdio.h>
#include "AStar_mask\Optimize.h"
#include "AStar_mask\Intersection.h"
#include "AStar_mask\TgridImporter.h"
#include "BaseCommon.h"

#include "Log.h"

ConfigData g_config_data;

CAStarMap* m_astarmap = NULL;

void test_main()
{
	m_astarmap = new CAStarMap("E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\res\\new_threeway.mask");


	auto nodeNum = m_astarmap->GetNodeAmount();

	for (int i = 0; i < nodeNum; i++) 
	{
		auto node = m_astarmap->GetMapNode(i);
		printf("\n %d \n", node->GetCenter().x);
	}
}


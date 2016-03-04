#include "TgridImporter.h"
#include "AStarMap.h"
/*#include "windows.h"*/
#include <algorithm>
#include "assert.h"

//��ʾ���ļ���д�Ļ�������С
unsigned long long CTgridImporter::m_uPackBufSize = 4096*2;

CTgridImporter::CTgridImporter()
{
	m_pFile = NULL;
}

CTgridImporter::~CTgridImporter(void)
{
	if (m_pFile != NULL)
	{
		fclose(m_pFile);
		m_pFile = NULL;
	}

	SAFE_DELETE_ARRAY(m_pPackFileBuf);
}

bool CTgridImporter::Create( const char* pszFile , CAStarMap* pMap)
{
	m_pMap = pMap;

	// ---------------------------------------------------------------------
	// ��ȡ�ļ���Ϣ
	// ---------------------------------------------------------------------
	m_uPackFilePos =0; //��ʾ���ļ���ʱ���ļ�ָ��λ��
	m_uPackFileSize =0; //��ʾ���ļ���ʱ���ļ���С
	m_pPackFileBuf =NULL; //��ʾ���ļ���ʱ�Ļ�����
	m_uPackFileRealSize =0; //��ʾ���ļ���ʱ�Ļ�����ʵ�ʴ�С
	m_uPackFileBufBasePos =0; //��ʾ���ļ���ʱ�Ļ�������ʼ�ļ�ָ��λ��

	m_pFile = fopen(pszFile, "rb");
	if (m_pFile == NULL)
	{
		return false;
	}

	m_uPackFilePos =0;

	//���ļ�ָ���ƶ����ļ���ǰβ��
	fseek(m_pFile, 0, SEEK_END);

	//����ļ���ǰ����
	m_uPackFileSize = (unsigned long long)ftell(m_pFile);
	if (m_uPackFileSize == 0)
	{
		fclose(m_pFile);
		m_pFile = NULL;
		return false;
	}

    auto temp = std::max(1ULL, m_uPackBufSize);
    m_uPackFileRealSize = std::min(m_uPackFileSize, temp);
	m_pPackFileBuf =new char[(size_t)m_uPackFileRealSize];
	::fseek (m_pFile, 0, SEEK_SET);
	::fread (m_pPackFileBuf, sizeof(char), (size_t)m_uPackFileRealSize, m_pFile);
	::fseek (m_pFile, 0, SEEK_SET);
	m_uPackFileBufBasePos =0;


	// ---------------------------------------------------------------------
	// �����ļ���ʽ
	// ---------------------------------------------------------------------
	if (m_uPackFileSize < NEW_TGRID_HEADER_SIZE)
	{
		return false;
	}

	if(this->ReadU8() == 'T'
		&& this->ReadU8() == 'G'
		&& this->ReadU8() == 'R'
		&& this->ReadU8() == 'I'
		&& this->ReadU8() == 'D')
	{
		if (this->ReadU8() == 0)
		{
			if (this->BuildFromVersion_0())
			{
				return true;
			}
		}
	}

	return false;
}

uint8 CTgridImporter::ReadU8()
{
	uint8 Temp;
	ReadData((char *)(&Temp), sizeof(Temp), 
		m_pFile, m_uPackFilePos, m_uPackFileSize,
		m_pPackFileBuf, m_uPackFileRealSize, m_uPackFileBufBasePos);
	return Temp;
}

void CTgridImporter::ReadData(char *pBuf, uint64 uBufSize,
			  FILE* hFile, uint64 &uPackFilePos, uint64 uPackFileSize,
			  char *pPackFileBuf, uint64 uPackFileRealSize, uint64 &uPackFileBufBasePos)
{
	if(!hFile || !pPackFileBuf || !pBuf){ //���ļ���Ч�Ļ�
		throw 1;
	}

	if(uPackFilePos<0 || uPackFilePos>=uPackFileSize){ //���ļ�ָ��Խ��Ļ���ֱ�ӷ���
		return;
	}

	if(uPackFilePos<uPackFileBufBasePos || uPackFilePos>=uPackFileBufBasePos+uPackFileRealSize){ //���ļ�ָ�볬���������߽�Ļ�
		uPackFileBufBasePos =uPackFilePos;
		::fseek (hFile, (long)uPackFileBufBasePos, SEEK_SET);
        ::fread(pPackFileBuf, sizeof(char), (size_t)std::min(uPackFileRealSize, uPackFileSize - uPackFileBufBasePos), hFile); //���»�����
	}

	//��ȡ���ݵ�ǰ��
	uBufSize = std::min(uBufSize, uPackFileSize-uPackFilePos); //����Ҫ��ȡ�������ܳ���

	uint64 uReadLen = std::min(uBufSize, uPackFileBufBasePos+uPackFileRealSize-uPackFilePos); //��ʾһ�ζ�ȡ�����ݳ���
	::memcpy (pBuf, pPackFileBuf+(uPackFilePos-uPackFileBufBasePos), (size_t)uReadLen);
	pBuf +=uReadLen;
	uBufSize -=uReadLen;
	uPackFilePos +=uReadLen;

	//��ȡ���ݵ��м��
	while(uBufSize>=uPackFileRealSize){ 
		uPackFileBufBasePos +=uPackFileRealSize;
		::fseek (hFile, (long)uPackFileBufBasePos, SEEK_SET);
		::fread (pBuf, sizeof(char), (size_t)uPackFileRealSize, hFile);
		pBuf +=uPackFileRealSize;
		uBufSize -=uPackFileRealSize;
		uPackFilePos +=uPackFileRealSize;
	}

	//��ȡ���ݵ�β��
	if(uPackFilePos>=uPackFileBufBasePos+uPackFileRealSize){
		uPackFileBufBasePos +=uPackFileRealSize;
		::fseek (hFile, (long)uPackFileBufBasePos, SEEK_SET);
		::fread (pPackFileBuf, sizeof(char), (size_t)std::min(uPackFileRealSize, uPackFileSize-uPackFileBufBasePos), hFile); //���»�����
		if(uBufSize>0){
			::memcpy (pBuf, pPackFileBuf, (size_t)uBufSize);
			uPackFilePos +=uBufSize;
		}
	}
}

template<class T>
T ReadData(FILE* fp)
{
	assert(fp != NULL);

	T ret;
	fread(&ret, sizeof(T), 1, fp);
	return ret;
}


bool CTgridImporter::BuildFromVersion_0()
{
	fseek(m_pFile, NEW_TGRID_HEADER_SIZE, SEEK_SET);

	// get cell size
	m_pMap->m_fXTileSize = m_pMap->m_fYTileSize = ::ReadData<float>(m_pFile);

	// get number of cell rows
	uint16 uNumCellRows =  ::ReadData<uint16>(m_pFile);
	if (uNumCellRows == 0 || uNumCellRows == (uint16)~0) {
// 		g_pTheWorld->ReportAnError("row count in %s exceed the limit",
// 			this->m_resInfo[1].c_str());
		return false;
	}

	// get number of cell columns
	uint16 uNumCellColumns =  ::ReadData<uint16>(m_pFile);
	if (uNumCellColumns == 0 || uNumCellColumns == (uint16)~0) {
// 		g_pTheWorld->ReportAnError("column count in %s exceed the limit",
// 			this->m_resInfo[1].c_str());
		return false;
	}

	m_pMap->m_width = uNumCellColumns;
	m_pMap->m_height = uNumCellRows;

	// get start point
	struct float2 
	{
		float x;
		float y;
	};
	float2 vStartPoint = ::ReadData<float2>(m_pFile);
	m_pMap->m_vMapMin = Vec2f(vStartPoint.x, vStartPoint.y);
	m_pMap->m_vMapMax.x = m_pMap->m_vMapMin.x + m_pMap->m_width*m_pMap->m_fXTileSize;
	m_pMap->m_vMapMax.y = m_pMap->m_vMapMin.y + m_pMap->m_height*m_pMap->m_fYTileSize;

    m_pMap->Create(m_pMap->m_vMapMin.x,m_pMap->m_vMapMin.y,m_pMap->m_vMapMax.x,m_pMap->m_vMapMax.y,m_pMap->m_fXTileSize);
	// get cell prop
	uint16 i;
	for (i = 0; i < uNumCellRows; ++i) {
		for(uint16 j = 0; j < uNumCellColumns; ++j)
		{
			uint32 uProp = ::ReadData<uint32>(m_pFile);
			//this->arrCells[ i * this->uNumCellColumns + j ].uProp = uProp;
			CMapNode* pNode = m_pMap->GetMapNode(j, i);
			if ((uProp& 0x1) != 0 )
			{
				pNode->AddStaticObstacle();
			}
		}
	}

	// get grid point
	uint16 uNumGridRows = uNumCellRows + 1;
	uint16 uNumGridColumns = uNumCellColumns + 1;

	struct GRID_POINT
	{
		float fHeight;
		Vec3f vNormal;
	};
	std::vector<GRID_POINT> arrGridPoints;

	arrGridPoints.resize( uNumGridRows * uNumGridColumns);
	for (uint16 i = 0; i < uNumGridRows; ++i) {
		for (uint16 j = 0; j < uNumGridColumns; ++j) {
			uint32 uIndex = i * uNumGridColumns + j;
			arrGridPoints[uIndex].fHeight = ::ReadData<float>(m_pFile);
			arrGridPoints[uIndex].vNormal = ::ReadData<Vec3f>(m_pFile);
		}
	}

	// UpdateCellHeight
	for(size_t i=0; i<uNumCellRows; ++i )
	{
		for(uint16 j=0; j<uNumCellColumns; ++j )
		{
			float gp0 = arrGridPoints[ i * uNumGridColumns + j ].fHeight;
			float gp1 = arrGridPoints[ i * uNumGridColumns + j + 1 ].fHeight;
			float gp2 = arrGridPoints[ ( i + 1 ) * uNumGridColumns + j ].fHeight;
			float gp3 = arrGridPoints[ ( i + 1 ) * uNumGridColumns + j + 1 ].fHeight;

			CMapNode* pNode = m_pMap->GetMapNode(j, static_cast<int>(i));
			pNode->SetHeight(( gp0 + gp1 + gp2 + gp3 ) * 0.25f);
		}
	}

	return true;
}

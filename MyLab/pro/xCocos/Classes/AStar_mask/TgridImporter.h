#pragma once

// #include "IBase.h"
#include "stdio.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

class CAStarMap;

class CTgridImporter
{
public:
	CTgridImporter();
	~CTgridImporter(void);

	bool Create(const char* pszFile, CAStarMap* pMap);

private:
	uint8 ReadU8();
	void ReadData(char *pBuf, uint64 uBufSize, FILE* hFile, uint64 &uPackFilePos, uint64 uPackFileSize, char *pPackFileBuf, uint64 uPackFileRealSize, uint64 &uPackFileBufBasePos);
	bool BuildFromVersion_0();
private:
	FILE* m_pFile;

	static const int NEW_TGRID_HEADER_SIZE = 6;

	unsigned long long m_uPackFilePos; //表示包文件读时的文件指针位置
	unsigned long long m_uPackFileSize; //表示包文件读时的文件大小

	char *m_pPackFileBuf; //表示包文件读时的缓冲区
	unsigned long long m_uPackFileRealSize; //表示包文件读时的缓冲区实际大小
	unsigned long long m_uPackFileBufBasePos; //表示包文件读时的缓冲区起始文件指针位置


	static unsigned long long m_uPackBufSize; //表示包文件读写的缓冲区大小

	CAStarMap* m_pMap;
};

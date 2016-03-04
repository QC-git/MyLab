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

	unsigned long long m_uPackFilePos; //��ʾ���ļ���ʱ���ļ�ָ��λ��
	unsigned long long m_uPackFileSize; //��ʾ���ļ���ʱ���ļ���С

	char *m_pPackFileBuf; //��ʾ���ļ���ʱ�Ļ�����
	unsigned long long m_uPackFileRealSize; //��ʾ���ļ���ʱ�Ļ�����ʵ�ʴ�С
	unsigned long long m_uPackFileBufBasePos; //��ʾ���ļ���ʱ�Ļ�������ʼ�ļ�ָ��λ��


	static unsigned long long m_uPackBufSize; //��ʾ���ļ���д�Ļ�������С

	CAStarMap* m_pMap;
};

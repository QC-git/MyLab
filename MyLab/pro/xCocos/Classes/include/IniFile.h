#pragma once
#include <string>
#include <vector>
#include <map>
//#include "windows.h"
using namespace std;
//////////////////////////////////////////////////////////////////////
// 使用说明：
// 由 [KEY] 行和内容行(NAME=TEXT)组成。[KEY]行的([)必须顶行
// 支持 /* 和 */ 的注释行，带这两个符号的整行都是注释
// 每一行的行末可以带 // 注释符
// KEY、NAME和TEXT，每个都会被剪掉首尾空格
//////////////////////////////////////////////////////////////////////

#define _USE_STRING2ID

class CIniFile  
{
protected:
	std::string m_strPath;

	struct Value 
	{
		std::string name;
		std::string value;
		std::string line;
	};
	typedef std::vector< Value >		ValueVector;

	struct Section 
	{
		std::string name;
		ValueVector vv;
	};
	typedef std::vector< Section >		SectionVector;

	SectionVector m_sections;
	typedef std::map< std::string, unsigned > Section2Index;
	Section2Index m_section2Index;
	ValueVector::iterator FindValueVector(ValueVector& vv, const char* valuename);

public:
	int FindValue(int keynum, const char* valuename);
	int FindKey(const char* keyname);

public:
	std::string error;

public:
	CIniFile();
	CIniFile(const char* inipath);

	virtual ~CIniFile();

	void SetPath(const char* newpath);
	const char* GetPath() { return m_strPath.c_str(); }

	bool ReadFile();
	bool ReadFile(const char* newpath);
	void WriteFile(); 
	void Reset();

	const char* GetKeyName(int nKeyIndex);
	const char* GetValue(int  nKeyIndex, const char* sValueName);

	int GetKeyAmount();						// [KEY]的数量
	int GetLineAmount(const char* keyname);		// 无(=)的整行数量，-1表示无KEY的错误
	int GetValueAmount(const char* keyname);	// 有(=)的整行数量，-1表示无KEY的错误

	const char* GetValue(const char* keyname, const char* valuename); 
	int GetValueI(const char* keyname, const char* valuename); 
	int GetValueI(int keyname, const char* valuename); 
    int GetValueHex(const char* keyname, const char* valuename);
    int GetValueHex(int keyname, const char* valuename);

	double GetValueF(const char* keyname, const char* valuename);
	const char* GetLine(const char* keyname, int idx); 

	bool SetValue(const char* key, const char* valuename, const char* value, bool create = 1);
	bool SetValueI(const char* key, const char* valuename, int value, bool create = 1);
	bool SetValueF(const char* key, const char* valuename, double value, bool create = 1);
	bool SetValueLine(const char* key, const char* valueline, bool create = 1);

public:

	void GetPos(const char* keyname, const char* valuename, int* x, int* y);
};


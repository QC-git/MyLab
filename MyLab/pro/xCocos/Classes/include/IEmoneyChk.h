// IEmoneyChk.h: interface for the IEmoneyChk class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IEMONEYCHK_H__EB1C337D_2ADD_4D1B_8C86_3B260DD5BA22__INCLUDED_)
#define AFX_IEMONEYCHK_H__EB1C337D_2ADD_4D1B_8C86_3B260DD5BA22__INCLUDED_

//#include "windows.h"
/*#include "common.h"*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// #ifdef EMONEYCHK_EXPORTS
// #define EMONEYCHK_API __declspec(dllexport)
// #else
// #define EMONEYCHK_API __declspec(dllimport)
// #endif
#define EMONEYCHK_API

class EMONEYCHK_API IEmoneyChk  
{
public:
	virtual ~IEmoneyChk();
	static IEmoneyChk*	CreateNew() { return NULL; } //  TODO::MILO 12/3/2015
	virtual U32	Release() =0;

public:
	virtual U32 CalcCardChkSum(int nCardType, int nAccountID, int idRef)		=0;
	virtual U32 CalcRMBChkSum(int nAccountID, int number)						=0;	
	virtual U32 CalcItemChkSum(int nItemType, int nItemID)					=0;
	virtual U32 CalcItemExChkSum(int nItemType, int nItemID, UCHAR nData1, UCHAR nData2, UCHAR nAddLev)		=0;
	virtual U32 CalcRobotChkSum(UCHAR nLevel, UCHAR nModelLev, int nRobotID)									=0;
	virtual U32 CalcUserChkSum(int nMoney, U64 nMoneySaved, int nUserID)									=0;
	virtual U32 CalcUserXChkSum(U64 nStone0, int nStone1, int nStone2, int nUserID)						=0;
};

#endif // !defined(AFX_IEMONEYCHK_H__EB1C337D_2ADD_4D1B_8C86_3B260DD5BA22__INCLUDED_)

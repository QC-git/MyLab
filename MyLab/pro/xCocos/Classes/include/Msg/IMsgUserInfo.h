// -*- C++ -*-

//=============================================================================
/**
 *  @file    IMsgUserInfo.h
 *
 *  $Id: IMsgUserInfo.h  2009-01-13 14:33:41 $
 *
 *  @author xxx
 */
//=============================================================================

#ifndef _MSG_IMSGUSERINFO_H_
#define _MSG_IMSGUSERINFO_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "Define.h"
#pragma pack(1)

NAMESPACE_BEGIN(msguserinfo)
		
enum
{
	MSG_USERINFO_ACT_LOGIN		=0,					//��½���迪ʼ
	MSG_USERINFO_ACT_UPDATE		=1,					//����
	MSG_QUERY_USERINFO			=2,					//��ѯ���������Ϣ
	MSG_USERINFO_CHANGE_ROBOT	=3,					// �����ڸ�������Ķ���(TO CLIENT)
};




typedef struct
{	                 
	USHORT			usMsgSize;
	USHORT			usMsgType;
	
	OBJID			id;              // 2009-7-19 5:16:02   LSC  ��������  ͬʱ�ͻ���Ҳ�޸���
	
	USHORT			usAction;
	U64			u64Exp;			// ��ʦ����	
	UCHAR			ucLevel;		// ��ʦ�ȼ�
	UCHAR			ucVipLev;		// ���Vip�ȼ�
	U32			dwLookFace;		// ��ò

	U32			dwRMB;
	int             nTotalizeGame; 
	int             nWinGame;
	int             nKillHeroAmount;
	int             nAssistAmount;
	int             nKillEmplacementAmount;
	int             nKillDogfaceAmount;    
	// for str packer
	char			szBuf[1];
}MSG_USER_INFO;

/*     
      

typedef struct    //  ԭ���� �ṹ�� 
{
	USHORT			usMsgSize;
	USHORT			usMsgType;
	USHORT			usAction;
	OBJID			id;
	UCHAR			ucLevel;		// ��ʦ�ȼ�
	UCHAR			ucGeNaKoolLevel;//���ɿ�ȼ�
	U64			u64Exp;			// ��ʦ����
	USHORT			usPK;			// ��ʦPKֵ
	UCHAR			ucVipLev;		// ���Vip�ȼ�
	U32			dwTitle;		// ��ʦ�ƺ�
	U32			dwMilitaryRank1;
	U32			dwMilitaryRank2;
	U32			dwMilitaryRank3;
	U32			dwMilitaryRank4;	// ��ʦ����

  U32			dwLookFace;			// ��ò
  U32			dwMoney;
  OBJID			idTransfromMagic;	//�������ڴ��ĸ����ܱ��ι���
  U64			u64Stone0;
  U32			dwStone1;
  U32			dwStone2;
  U32			dwDeed;				// �����׶�
  OBJID			idSpirit;
  U32			dwRobotType;		// ��������
  int				nInsizeSize;		// ���òմ�С
  U32			usHair;
  UCHAR			ucCamp;
  USHORT			usColor ;           //������ɫ 
  U32			dwRMB;
  UCHAR			ucExpType;			//��ʦ����ֵ����                   // 2009-7-19 10:17:33   LSC  ������
  U32			dwList1;
  U32			dwList2;
  UCHAR			ucProfession;
  
	UCHAR			ucPeerage;			//��λ
	//	UCHAR			ucDunKeeperRank;	//���³ǳ����׼�
	//add by ccw_xxx
	U32           dwEmoney3;
	int             nVipShow;
	int				nKillNum;//ɱ������
	// for str packer
	char			szBuf[1];
}MSG_USER_INFO; 
/*
*/
NAMESPACE_END(msguserinfo)

#pragma pack()

#endif //_MSG_IMSGUSERINFO_H_

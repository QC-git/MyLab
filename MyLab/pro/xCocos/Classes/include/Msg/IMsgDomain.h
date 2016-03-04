//==========================================================================
/**
*  @file   IMsgAction.h
*
*  $Id: IMsgAction.h 2009-01-07 16:03:40Z $
*
*  @author xxx <xxx@gmail.com>
*  
*/
//==========================================================================
#ifndef _MSG_IMSGDOMAIN_H_
#define _MSG_IMSGDOMAIN_H_

#include "Define.h"

namespace msgdomain
{
	enum
	{
		_DOMAIN_CREATE		= 0,  //��������
		_DOMAIN_FAIL		= 1,  //��������ʧ��	
		_DOMAIN_DESTROY		= 2,  //��������
		_DOMAIN_ENTER		= 3,  //��ҽ�������
		_DOMAIN_LEAVE		= 4,  //����뿪����
// 		_DOMAIN_ON_CENTER	= 5,  // ��ҵ���������
// 		_DOMAIN_LEAVE_CENTER= 6,  //����뿪��������
		_DOMAIN_MAP_REPLY_LEV_LOW     = 5,   //��ͼ�����Ѿ���ͬ���͵���
		_DOMAIN_MAP_REPLY_CONQUER     = 6,   //������ͻ��������
		_DOMAIN_MAP_REPLY_NUM_HIGH    = 7,   //��ͼ����������Ѿ���������
		_DOMAIN_REGION_REPLY_VALID_HIGH = 8, //������Ч�����Ѿ���������
		_DOMAIN_REGION_REPLY_EXIST_HIGH = 9, //����ͼ����������Ѿ���������
		_DOMAIN_REGION_REPLY_CONQUER =10,   //������ͻ��������
		_DOMAIN_LASTTIME			 = 20, //tc�������ʱ��
	};
	
	typedef struct 
	{
		USHORT		usMsgSize;
		USHORT		usMsgType;

		USHORT		usAction;

		OBJID		idPlayer;

		OBJID		idRegion;       //����ID
		uint32	    dwType;			//���������

		int			nPosX;			//�������ĵ�x����Ϊ��ҽ���������ϢʱΪ�����λ������x
		int			nPosY;			//�������ĵ�y����Ϊ��ҽ���������ϢʱΪ�����λ������y

		uint32		dwCx;         //����ĳ�
		uint32		dwCy;			//����Ŀ�

		OBJID	    idOwnPlayer;	     //���򴴽��ߵ�ID����Ϊ��ҽ���������ϢʱΪ�����ID
		uint32		dwProfessionExp;	//������ְҵ����
		uint32		dwProfessionLev;	//������ְҵ�ȼ�

		uint32		dwAccessTime;      // ������ĳ���ʱ��
		OBJID		idSyndicate;	   // ��������ID
		UCHAR		ucMagicLev;		   // ���ܵȼ�
		NAMESTR		strPlayerName;	   //����������
		NAMESTR     strBelongName;     //������������ϵ
	}MSG_DOMAIN;
	
}

#endif

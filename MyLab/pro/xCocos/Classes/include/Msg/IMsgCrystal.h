//==========================================================================
/**
 *  @file   IMsgCrystal.h
 *
 *  $Id: IMsgWalk.h 2009-01-07 16:03:40Z $
 *
 *  @author xxx <xxx@gmail.com>
 *  
 */
//==========================================================================
#ifndef _IMSGCRYSTAL_H_
#define _IMSGCRYSTAL_H_

namespace msgcrystal
{
	enum
	{
		CRYSTAL_INFO,  //ˮ��ʹ����Ϣ     to cilent size=6,data[0]:ˮ������,data[1]:ˮ�����Ѽ�¼0,data[2]:ˮ�����Ѽ�¼1,data[3]:ˮ�����Ѽ�¼2,data[4]:ˮ�����Ѽ�¼3��data[5]:ˮ�����Ѽ�¼4
		CRYSTAL_QUERY, //��ѯˮ��ʹ����Ϣ to server size=0
		CRYSTAL_USE,   //ʹ��ˮ��         to server size=1,data[0]:������Ϣ
		//2007-3-10 tcp add ����ˮ���������õı��� begin
		CRYSTAL_GUI_SETUP_QUERY,  //����ˮ������������Ϣ��ѯ to server size=0
		CRYSTAL_GUI_SETUP_INFO,   //����ˮ������������ 
								  //to cilent size=2 
								  //data[0]��:��һ�ֽ�Gui0,�ڶ��ֽ�Gui1 �����ֽ�Gui2 �����ֽ�Gui3
								  //data[1]��:��һ�ֽ�Gui4,�ڶ��ֽ�Gui5 							  
		CRYSTAL_GUI_SETUP_SAVE,   //����ˮ������������Ϣ���� to server size=2	
								  //to cilent size=2 
								  //data[0]��:��һ�ֽ�Gui0,�ڶ��ֽ�Gui1 �����ֽ�Gui2 �����ֽ�Gui3
								  //data[1]��:��һ�ֽ�Gui4,�ڶ��ֽ�Gui5 							  	
		//2007-3-10 tcp add ����ˮ���������õı��� end	
		CRYSTAL_SKILLLEARN,		// 2007.04.06 ������ˮ��ѧϰ���� TS data[0]=Type����Ŷ�1000~1999Ϊ������ר�ã� TC data[0]=Type�ɹ���data[0]=0ʧ��
		CRYSTAL_UPDATE,   //ˮ�����ø��� to Client nIndex:CrystalUsage0-CrystalUsage4��һ������, data[0]:CrystalUsage0-CrystalUsage4��һ��ֵ
	};

	typedef struct : tq::MSG_HEAD
	{
		BYTE Action;
		union
		{
		BYTE size; 
			BYTE nIndex; 
		};
		unsigned int data[1];
	}MSG_CRYSTAL;
}

#endif

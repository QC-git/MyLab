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
		CRYSTAL_INFO,  //水晶使用信息     to cilent size=6,data[0]:水晶点数,data[1]:水晶消费记录0,data[2]:水晶消费记录1,data[3]:水晶消费记录2,data[4]:水晶消费记录3，data[5]:水晶消费记录4
		CRYSTAL_QUERY, //查询水晶使用信息 to server size=0
		CRYSTAL_USE,   //使用水晶         to server size=1,data[0]:类型信息
		//2007-3-10 tcp add 能量水晶界面设置的保存 begin
		CRYSTAL_GUI_SETUP_QUERY,  //能量水晶界面设置信息查询 to server size=0
		CRYSTAL_GUI_SETUP_INFO,   //能量水晶界面设置信 
								  //to cilent size=2 
								  //data[0]的:第一字节Gui0,第二字节Gui1 第三字节Gui2 第四字节Gui3
								  //data[1]的:第一字节Gui4,第二字节Gui5 							  
		CRYSTAL_GUI_SETUP_SAVE,   //能量水晶界面设置信息保存 to server size=2	
								  //to cilent size=2 
								  //data[0]的:第一字节Gui0,第二字节Gui1 第三字节Gui2 第四字节Gui3
								  //data[1]的:第一字节Gui4,第二字节Gui5 							  	
		//2007-3-10 tcp add 能量水晶界面设置的保存 end	
		CRYSTAL_SKILLLEARN,		// 2007.04.06 用能量水晶学习技能 TS data[0]=Type（编号段1000~1999为技能树专用） TC data[0]=Type成功，data[0]=0失败
		CRYSTAL_UPDATE,   //水晶设置更新 to Client nIndex:CrystalUsage0-CrystalUsage4的一个索引, data[0]:CrystalUsage0-CrystalUsage4的一个值
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

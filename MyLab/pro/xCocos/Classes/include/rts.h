#pragma once

struct SRtsNode
{
    int nIndex;
    int nValid;
    float fHeight;

    SRtsNode()
    {
        nIndex  = 0;
        nValid  = 0;
        fHeight = 0.f;
    }
};


enum UNIT_MASK_TYPE
{
	UNIT_MASK_TYPE_NONE=0,		//正常的正方形掩码
	UNIT_MASK_TYPE_CIRCULAR,	//圆形掩码
	UNIT_MASK_TYPE_CONCENTRIC,	//同心圆掩码
	UNIT_MASK_TYPE_RECTANGLE,	//矩形掩码掩码
};

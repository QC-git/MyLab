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
	UNIT_MASK_TYPE_NONE=0,		//����������������
	UNIT_MASK_TYPE_CIRCULAR,	//Բ������
	UNIT_MASK_TYPE_CONCENTRIC,	//ͬ��Բ����
	UNIT_MASK_TYPE_RECTANGLE,	//������������
};

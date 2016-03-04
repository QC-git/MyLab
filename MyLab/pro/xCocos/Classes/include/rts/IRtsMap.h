#pragma once

#include "rts.h"

//��ͼ�ϰ�������
struct S3DPosition
{
    float x;
    float y;
    float z;

    S3DPosition()
    {
        x = 0.f;
        y = 0.f;
        z = 0.f;
    }
};

class IMaskData
{
protected:
    IMaskData(){}
public:
    static IMaskData* LoadMaskData(const char* pszFileName);
    static IMaskData* LoadMaskData(float fMapMinX, float fMapMinY, float fMapMaxX, float fMapMaxY, float fCellSize, const SRtsNode *pNodes, size_t count);
    static IMaskData* CreateMapData(IMaskData* MapData);
    virtual ~IMaskData(){}

    virtual USHORT Release() = 0; 
public:
    //��λ����������������
    virtual bool IsBlock(float x,float y,float radius) = 0;

    //��ĳ��λ�ø�����վ�ĵ�
    virtual  bool CalcClosestNode(float fx, float fy, float radius,float& cx,float& cy,float& cz) const = 0;
    virtual  bool CalcClosestNodeByCell(float fx, float fy, float radius,float& cx,float& cy,float& cz,unsigned maxCell=20) const = 0;
    virtual  int FindPath(float fx, float fy, float cx,float cy,float raid=0.5f) = 0;
    virtual  void GetPointByIndex(int nIndex, float& fX, float& fY, float& fZ) const = 0;
};


//��ͼ����ص�֪ͨ����
class IRtsMapCallBack
{
public:
    //λ��
    virtual void Relation(unsigned id,float x,float y,float face, unsigned type=0){}
    //����Ŀ��
    virtual void Goal(unsigned id,float x,float y,float face, unsigned Goaltype=0){}

    //�ص�·����
    virtual void Path(unsigned id, S3DPosition* positon, unsigned size){};

    //�ص�ɾ��
    virtual void RemoveObj(unsigned id){};
    //֡�仯
    virtual void OnFrame(unsigned frameNum){}
    //����ͬ������,�㲥���������ն�
    virtual void Sync(const char* msg,unsigned size){}
    //����ͬ��
    virtual void DirectSync(unsigned id,const char* msg,unsigned size){}
};

//�ͻ���ʹ�õĵ�ͼ
class IRtsMapTerminal
{
protected:
    IRtsMapTerminal(){}
public:
    static IRtsMapTerminal* CreateRtsMap(IMaskData* maskData,IMaskData* maskDataPlayer,IRtsMapCallBack* cb);
    virtual ~IRtsMapTerminal(){}
public:
    //����ͬ��
    virtual void OnSync(const char* msg,unsigned size) = 0;
    //����ģ��
    virtual void Update() = 0;

    //�ͷ�
    virtual void Release() = 0;

    //
    virtual  int  GetDelay() = 0;
};

//�����ʹ�õĵ�ͼ
class IRtsMap : public IRtsMapTerminal
{
protected:
    IRtsMap(){}
public:
    static IRtsMap* CreateRtsMap(IMaskData* maskData,IMaskData* maskDataPlayer,IRtsMapCallBack* cb);
    virtual ~IRtsMap(){}

public:
    enum UNIT_TYPE
    {
        UTYPE_DOTAGROUND=0,
        UTYPE_DOTAAIR
    };

    virtual void AddObj(unsigned id,UNIT_TYPE unittype,float x,float y,float radius,float radiusEx,float face,float faceTrunRate, float fDestDis, float speed,bool needSynAll=false, bool bMaskFlagStatic=false, unsigned maskType = 0) = 0;
    virtual void RemoveObj(unsigned id) = 0;
    virtual void ChangeSpeed(unsigned id,float fx,float fy,float speed) = 0;

    virtual void Seek(unsigned id,float fx,float fy,float dx,float dy, bool bNotifyPath=false) = 0;
	virtual void Move(unsigned id,float dirx,float diry) = 0;
    virtual void Follow(unsigned selfID,float fx,float fy,unsigned toID, float dis) = 0;
    virtual void Stop(unsigned id,float fx,float fy) = 0;
    virtual void SetBlock(unsigned id,bool bBlock) = 0;
    virtual void SetLock(unsigned id,bool block) = 0;
    virtual void Blink(unsigned id,float fx,float fy, bool bSetwardArc=false) = 0;
    virtual void Force(unsigned id,float fx,float fy,float dx,float dy,float speed, unsigned forcetype=0,bool bsetFace=true) = 0;
    virtual void ForceTargetSide(unsigned id,float fx,float fy,unsigned idTo,float speed, unsigned forcetype=0) = 0;
	virtual void Curve(unsigned id,float fx,float fy,float dx,float dy,float speed,float CurveSwing,float CurveCycle, unsigned forcetype=0) = 0;
	virtual void Circle(unsigned id,float fx,float fy,float dx,float dy,unsigned targetId, float speed, float circleRange, unsigned forcetype=0) = 0;
    virtual void SetDir(unsigned id,float fx,float fy, bool bClearCmd=false) = 0;


    virtual void GetNeighbors(float x,float y,float radius,unsigned objs[],unsigned size) = 0;
    virtual void ChangeFollowDis(unsigned id,float fx,float fy,float followdis) = 0;
public:
    virtual void SetFrameTime(float time) = 0;
    virtual void IncreaseFrame() = 0;
    virtual unsigned GetFrameNum() = 0;
    virtual void SynClientFram() = 0;
    virtual void ForceSyn(unsigned id) = 0;
};





////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2008, TQ Digital Entertainment, All Rights Reserved
// Author:  Wu yongmin
// Created: 2008/03/11
////////////////////////////////////////////////////////////////////////

#ifndef _TQ_DEFINE_H_
#define _TQ_DEFINE_H_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786 4002 4800)
#pragma warning(disable:4503)
#pragma warning(disable: 4996)	// 过时的字符串操作函数警告
#pragma warning (disable:4819)	// Unknown compiler version - please run the configure tests and report the results , Boost 版本问题, 我在Boost\config\compiler\visualc.hpp注释了

#pragma warning(error: 4005)	// macro redefinition 
#pragma warning(error: 4002)	// too many actual parameters for macro 'identifier' 
#pragma warning(error: 4390)	// ';' : empty controlled statement found; is this the intent? 
#pragma warning(error: 4307)	// integral constant overflow 
#pragma warning(error: 4551)	// function call missing argument list
#pragma warning(error: 4706)	//assignment within conditional expression
#pragma warning(error: 4715)	// 'function' : not all control paths return a value 

#pragma warning(disable:4244)
#pragma warning(disable:4512)
#pragma warning(disable:4267)
#pragma warning(disable:4127)

//开关
#define STRICT_CHECK	//严格检查开关，开启后性能会受影响
#define LOG_CLASSNAME	//log中带当前所在类名

#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
//#include <hash_map>
#include <algorithm>
#include <math.h>
#include <bitset>

/*#include <Log.h>*/
//#include "BaseCode.h"
#include "Types.h"
/*#include <Msg.h>*/
#include <StrID.h>
#include "mycom.h"

// #include <BaseCode/ActionModeAnalyse.h>
// #include <BaseCode/AutoLink.h>
// #include <BaseCode/AutoLinkSet.h>
// #include <BaseCode/Blacklist.h>
// #include <BaseCode/Console.h>
#include <BaseCode/Heap.h>
// #include <BaseCode/Multiton.h>
// #include <BaseCode/Random.h>
// #include <BaseCode/RefCount.h>
// #include <BaseCode/Responder.h>
// #include <BaseCode/SyncObjs.h>
#include <BaseCode/String.h>
#include <BaseCode/StringPacker.h>
#include <BaseCode/Timer.h>
// #include <BaseCode/Thread.h>
// #include <BaseCode/Ini.h>
// #include <BaseCode/TlsData.h>

#include <BaseCode/TUnmanagedPtr.h>
#include <BaseCode/Template.h>
// #include <BaseCode/SafeArray.h>
#include <BaseCode/SafeVector.h>
#include <BaseCode/TSingleton.h>
// #include <BaseCode/UnManagedPtrSet.h>
// #include <BaseCode/TArray.h>
#include <BaseCode/TMap.h>
#include <BaseCode/TPtrMap.h>
// #include <BaseCode/TPtrMultiMap.h>
// #include <BaseCode/TPtrSet.h>
// #include <BaseCode/TMultiMap.h> // template already been defined
// #include <Baseode/AutoPtr.h>
// #include <BaseCode/AutoPtrC.h>
//#include <BaseCode/TPtrMultiMap.h>
//#include <BaseCode/TPtrSet.h>
//#include <BaseCode/TMultiMap.h> // template already been defined
#include <BaseCode/AutoPtr.h>
//#include <BaseCode/AutoPtrC.h>
#include <BaseCode/TGameObj.h>
#include <BaseCode/TGameObjMap.h>

// #include <BaseCode/TGameObjSet.h>
// #include <BaseCode/TGameObjList.h>
// #include <BaseCode/TGameObjMultiMap.h>
// #include <BaseCode/TGameObjShareMap.h>
// #include <BaseCode/TGameObjShareSet.h>
// #include <BaseCode/TIndex.h>
// #include <BaseCode/VarType.h>
// #include <BaseCode/TRemoteData.h>

//#include <BaseCode/TGameObjSet.h>
//#include <BaseCode/TGameObjList.h>
//#include <BaseCode/TGameObjMultiMap.h>
//#include <BaseCode/TGameObjShareMap.h>
//#include <BaseCode/TGameObjShareSet.h>
//#include <BaseCode/TIndex.h>
//#include <BaseCode/VarType.h>
//#include <BaseCode/TRemoteData.h>
// #include <DB/IDB.h>
// #include <DB/TDBDataSet.h>
// #include <TDBData.h>
#include <TDBDataMap.h>
// #include <TDBDataSet.h>

// const int INDEX_NONE			= -1;

typedef int PORTID;     //端口ID,系统自增

#include "EnumDef.h"
#include "ConstDef.h"
#include "StructDef.h"
#include "ProtoMsg.h"
#include "KNMsg.h"
#include "MsgDefine.h"
#include "BaseCommon.h"
//#include "TDBDataManager.h"
// #include "IFindPathBaseOnMask.h"

//#ifdef _DEBUG
//#include "vld.h"
//#endif

#define MOD_ADAPTER             "adapter"
#define MOD_BATTLE_ADAPTER      "battle_adapter"
#define MOD_BATTLE_ENTITY       "battle_entity"
#define MOD_CLACFORMER          "clacformer"
#define MOD_CONDITION           "condition"
#define MOD_CREATUREAI          "creatureai"
#define MOD_CREATURESKILL       "creatureskill"
#define MOD_MOVEMENTGENERATOR   "movementgenerator"
#define MOD_STATEMANAGER        "statemanager"
#define MOD_NETMANAGER          "netmanager"
#define MOD_DAMAGE              "damage"
#define MOD_PLAYERAI            "playerai"

static const int INDEX_NONE = -1;

using namespace std;

#endif // end of define _GS_DEFINE_H_

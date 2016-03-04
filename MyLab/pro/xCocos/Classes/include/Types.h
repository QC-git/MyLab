//*********************************************************************
//
// Copyright (c) 2004
// All Rights Reserved
//
// Author: Wu yongmin
// Created: 2005/11/18
// ChangeBy: ccw_xxx
//*********************************************************************

#ifndef _TQ_TYPES_H_
#define _TQ_TYPES_H_

#pragma once

#pragma warning(disable:4786)

#include <cstdint>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
//#include <hash_map>
//#include <hash_set>

#include "Platform.h"

// type...
typedef uint8_t		  U8;
typedef int8_t		  I8;
typedef	uint16_t      U16;
typedef	int16_t       I16;
typedef	uint32_t      U32;
typedef	int32_t       I32;
typedef	uint64_t      U64;
typedef int64_t		  I64;
typedef double		  F64;
typedef float		  F32;

typedef	U32           SNID;   //SessionID �����/��ҵĵ�Sessionid ��������ҵ�SNID = ��ҵ�SCID ��
typedef	U32	          SCID;   //socket client id 
typedef int32_t		  PORTID;     //�˿�ID,ϵͳ����
typedef uint32_t      TIME;
	
typedef	unsigned int      UINT32;
typedef unsigned long	  UINT64;

#define		IPP_OF(x)				((void**)&(x))
#define		TYPENAME				class

// macro defines...
#undef	NULL
#define NULL    0

#undef	IN
#define IN

#undef	OUT
#define OUT

#undef	INOUT
#define INOUT

#undef	COPY_MAP
#define COPY_MAP

#define	SYSTEM_NAME 			"SYSTEM"			// �㲥��Ϣʱ����ϵͳ�������ִ�
#define ROOMATE_NAME			"ROOMMATES"	
#define	ALLUSERS_NAME			"ALLUSERS"			// TALK�д�����ҡ������ִ�
#define	REPLAY_OK_STR			"ANSWER_OK"			// �������ʺŻ�LOGINʱ���صĳɹ���־����
#define NEW_ROLE_STR			"NEW_ROLE"			// ����������
#define	ERROR_DUPLICATE_NAME	"���������Ѵ���!"
#define PSW_SHIELD_NO_CARD		"��û�����뱣����Ҫ����"

//////////////////////////////////////////////////////////////////////
// �汾��
const int	GAME_VERSION	= 123;						// ���汾�ţ��ͻ��˺ͷ���������ͬ���������С�
const int	SERVER_VERSION	= 20081215;					// �������汾�ţ�SERVERÿ�θ���ʱ���ɸ��ģ�������ʾ��
const int	NPCSERVER_VERSION	= 987654321;			// NPC������������汾��
const int	NPCSERVER_VERSION_RELOGIN	= 987654322;	// NPC������������汾��
	
//////////////////////////////////////////////////////////////////////
// NPC�������ʺ�
#define		NPCSERVER_ACCOUNT 	"NpcServer Tqdig"		// NPC��������¼��
#define		NPCSERVER_PASSWORD	"skl8934##VJICW "		// NPC����������

// max size define
const int	IPSTR_SIZE			= 16;				// IP���ռ�
const int	MAX_FIELDSIZE		= 256;				// �洮���ֶεĿռ��С��mysql �Ĵ������ֶ���󳤶�+1
const int	MAX_PARAMSIZE		= 256;				// action param space
const int	MAX_TENETSIZE		= 256;				// announce
const int	SPIRIT_NAMESIZE		= 32;				// ���������
const int	SHIP_NAMESIZE		= 32;				// �ɴ������������ֳ���

// ������س���
const int	PERCENT_BASE			= 100;
const int	ADJUST_PERCENT_BASE		= 30100;						// 
const int	ADJUST_PERCENT			= 1000000;						// ADJUSTʱ��>=30000 ��ʾ����
const int	ADJUST_SET				= -30000;						// ADJUSTʱ��<=-30000 ��ʾ����(-1*num - 30000)
const int	ADJUST_FULL				= -32768;						// ADJUSTʱ��== -32768 ��ʾ����
const int	DEFAULT_DEFENCE2		= 10000;						// ���ݿ�ȱʡֵ


const int	_MAX_MSGSIZE		= 1024;
const int	_MAX_NAMESIZE		= 16;
const int	_MAX_LONGNAMESIZE	= 36;

const int	_MAX_WORDSSIZE		= 256;
const int	_MAX_EMOTIONSIZE	= 16;
const int	_MAX_STR_MSGSIZE	= 256;
const int	_MAX_MACSIZE		= 40;
const int	_MAX_STRINGSIZE		= 32;

const int	_MAX_ACCOUNTSIZE	= 16;
const int	_MAX_PSWSIZE		= 16;
const int	_MAX_IDLETIME		= 600;	// 600s idle time
const int	_MAX_PACKAGE		= 8;

const int   _MAX_FRIENDCOUNT    = 20;

const int  _MAX_MULTICAST_COUNT = 100;

enum CLAN_TYPE
{
	//A=1����ɽ�ɣ�A=2�������ɣ�A=3�������ţ�A=4�������ɣ�A=5�����¹���
	CLAN_SHUSHAN	= 1,
	CLAN_BOLAI		,
	CLAN_SHURA		,
	CLAN_TANTRA		,
	CLAN_MOON		,
};

typedef uint32_t   OBJID;
typedef uint32_t   SVRID;				//��������ID,�������ļ�ָ��


//////////////////////////////////////////////////////////////////////////
typedef uint32_t			COORDINATE_INDEX;    // 2009-8-17 18:53:08   LSC
typedef uint32_t			ITEMID;
typedef uint32_t			NPCID;
typedef uint32_t			MAPID;
typedef uint32_t			USERID;
typedef uint32_t			MONSTERID;
//////////////////////////////////////////////////////////////////////////


// ID�ռ�
const OBJID	SCENEID_FIRST		= 000001;			// SCENE�ĵ�һ��ID
const OBJID	SYSNPCID_FIRST		= 00001;			// SYSNPC�ĵ�һ��ID			// fixed to database id
const OBJID	SYSNPCID_LAST		= 99999;			// SYSNPC�����һ��ID		// fixed to database id
const OBJID	DYNANPCID_FIRST		= 100001;			// DYNANPC�ĵ�һ��ID
const OBJID	DYNANPCID_LAST		= 199999;			// DYNANPC�����һ��ID
const OBJID	SCENEID_LAST		= 299999;			// SCENE�����һ��ID

const OBJID BOOTH_ID_FIRST      = 300001;
const OBJID BOOTH_ID_LAST       = 300199;

const OBJID	AISERVERID_FIRST	= 400001;			// NPC�ĵ�һ��ID
const OBJID	MONSTERID_FIRST		= 400001;			// MONSTER�ĵ�һ��ID
const OBJID	MONSTERID_LAST		= 499999;			// MONSTER�����һ��ID
const OBJID	PETID_FIRST			= 500001;			// PET�ĵ�һ��ID
const OBJID	PETID_LAST			= 599999;			// PET�����һ��ID

const OBJID	PETHEROID_FIRST		= 600001;			// PetHero�ĵ�һ��ID
const OBJID	PETHEROID_LAST		= 699999;			// PetHero�����һ��ID

const OBJID	AISERVERID_LAST		= 699999;			// NPC�����һ��ID

const OBJID	CALLPETID_FIRST		= 700001;			// CALLPET�ĵ�һ��ID
const OBJID	CALLPETID_LAST		= 799999;			// CALLPET�����һ��ID

const OBJID DOMAINID_FIRST		= 800000;			//DOMAIN����ĵ�һ��ID
const OBJID DOMAINID_LAST		= 899999;			//DOMAIN��������һ��ID
const OBJID TRAPID_FIRST		= 900001;			// ħ������ĵ�һ��ID
const OBJID MAGICTRAPID_FIRST	= 900001;			// ���ħ���ĵ�һ��ID
const OBJID MAGICTRAPID_LAST	= 989999;			// ���ħ�������һ��ID
const OBJID SYSTRAPID_FIRST		= 990001;			// ϵͳ����ĵ�һ��ID
const OBJID SYSTRAPID_LAST		= 999999;			// ϵͳ��������һ��ID		// fixed to database id
const OBJID TRAPID_LAST			= 999999;			// ħ����������һ��ID		// fixed to database id

const OBJID PLAYER_ID_FIRST		= 1000000;			// Player�ĵ�һ��ID
const OBJID PLAYER_ID_LAST		= 1999999999;		// Player�����һ��ID
const OBJID CLIENT_ID_FIRST		= 4000000000;		// Ϊ�ͻ��˱�����ID�ռ�
const OBJID DYNAMIC_MAP_ID		= 1000000;			// ��̬��ͼID

const OBJID COPY_MAPID_FIRST    = 4000000000;       // ������ͼ�ĵ�һ��ID
const OBJID COPY_MAPID_LAST     = 4294967295;       // ������ͼ�����һ��ID

const OBJID ITEM_ID_FIRST       = 1;                //��Ʒ�ĵ�һ��ID
const OBJID ITEM_ID_LAST        = 1999999999;       //��Ʒ�����һ��ID
const OBJID ITEMEX_ID_FIRST     = 2000000000;       //������Ʒ�ĵ�һ��ID
const OBJID ITEMEX_ID_LAST      = 2000000000;       //������Ʒ�ĵ�һ��ID
  
const OBJID SPIRIT_ID_FIRST		= 2000000000;		// Spirit �ĵ�һ�� ID
const OBJID SPIRIT_ID_LAST		= 2999999999;		// Spirit �����һ�� ID

const OBJID DEVIL_ID_FIRST		= 3000000000;		// DEVIL �ĵ�һ�� ID
const OBJID DEVIL_ID_LAST		= 3099999999;		// DEVIL �����һ�� ID

const OBJID WORLD_ID_FIRST		= 100;		      // WORLD �ĵ�һ�� ID
const OBJID WORLD_ID_LAST		= 199;		      // WORLD �����һ�� ID
// enum
enum { ID_NONE = 0, ID_SYS = -3, ID_NEWBIE = -2, ID_INVALID = -1/*0xffffffff*/  };
enum GENDER		{ GENDER_NONE = 0, GENDER_MALE, GENDER_FEMALE};

// Ŀǰ֧��24λ�������ͼ������Ͷ����Ҫ��չ��ͼ���Һ���
// ����� OBJ_XXX Ҫ��ʵ�����֣�OBJ_MONSTER �� IMonster ��ʾ���岻ͬ
enum OBJTYPE 
{ 
	OBJ_NONE		= 0,		
	// Role
	OBJ_USER		= 1 << 0, 
	OBJ_MONSTER		= 1 << 1, 
	OBJ_PET			= 1 << 2, 
	OBJ_NPC			= 1 << 3,
	OBJ_DYNANPC		= 1 << 4,
    OBJ_SYNPET      = 1 << 5,
	OBJ_SPIRIT      = 1 << 6, 
	
	// Goods
	OBJ_ITEM		= 1 << 7,
    OBJ_MONEY		= 1 << 8,
	OBJ_MAPITEM		= 1 << 9,
	OBJ_BOOTH       = 1 << 10,
		
	// MapObj
	OBJ_TRAP        = 1 << 11,
	OBJ_TERRAIN		= 1 << 12,
	OBJ_TREE		= 1 << 13,
	OBJ_RIVER		= 1 << 14,
	OBJ_COVER		= 1 << 15,
	OBJ_SCENE		= 1 << 16,
	OBJ_3DEFFECT	= 1 << 17,
	OBJ_SOUND		= 1 << 18,
	OBJ_GAME        = 1 << 19,
	OBJ_TMP			= 1 << 20,	//�ͻ���ר������
 	OBJ_DEVIL		= 1 << 21,	
	// Team
	OBJ_TEAM		= 1 << 22,

	OBJ_ROLE		= OBJ_USER | OBJ_PET | OBJ_MONSTER | OBJ_NPC | OBJ_DYNANPC | OBJ_SPIRIT | OBJ_TRAP | OBJ_SYNPET | OBJ_DEVIL,
	OBJ_MAPTHING	= OBJ_ROLE | OBJ_MONEY | OBJ_MAPITEM | OBJ_BOOTH | OBJ_DEVIL,
	OBJ_MAP			= OBJ_ROLE | OBJ_ITEM 
						| OBJ_TERRAIN | OBJ_TREE | OBJ_RIVER | OBJ_COVER | OBJ_SCENE 
						| OBJ_3DEFFECT | OBJ_SOUND,
};

enum TEAM_TYPE
{
	TEAM_TYPE_NONE,
	TEAM_TYPE_TRADECARAVAN,
};

enum TEAM_SORT 
{ 
	TEAM_SORT_NONE	  =0,
	TEAM_SORT_MONSTER,
	TEAM_SORT_NPC,
};

enum NPC_SORT 
{ 
	NPC_SORT_NONE	= 0,
	NPC_SORT_TRADECARAVAN,
};

enum MONSTER_SORT 
{ 
	MONSTER_SORT_NONE	= 0,
};

//////////////////////////////////////////////////////////////////////////
// ר�Ŵ洢��ҵ���ʱ״̬�� �����Զ����� �����
// 2009-6-20 17:06:48   LSC 
// ������ʱ��Ӽ���
enum ONLINE_TEM_STATUS
{
	ONLINE_TEM_STATUS_NONE			= 0,
	ONLINE_TEM_STATUS_BOOTH			= 1 << 0,  // ��Ҵ��ڰ�̯��
	ONLINE_TEM_STATUS_WAYLAY	    = 1 << 1,  // ��Ҵ���������  ai��� ���￴����
	ONLINE_TEM_STATUS_GODBLESS      = 1 << 2,  // ��֮ף��״̬   ����status �в����� �ʼ������� !


};




//////////////////////////////////////////////////////////////////////
template<int I>
struct auto_long_
{
	auto_long_() : hide_data(I) {}
	auto_long_<I>& operator =(long n)	{ hide_data=n; return *this; }
	auto_long_<I>& operator +=(long n)		{ hide_data+=n; return *this; }
	auto_long_<I>& operator -=(long n)		{ hide_data-=n; return *this; }
	long operator ++()		{ return ++hide_data; }
	long operator --()		{ return --hide_data; }
	long operator ++(int)	{ return hide_data++; }
	long operator --(int)	{ return hide_data--; }
	operator long() const	{ return hide_data; }

	long	hide_data;
};
typedef	auto_long_<0>	auto_long;


//////////////////////////////////////////////////////////////////////
template<int I>
struct auto_bool_
{
	auto_bool_() : hide_data(I) {}
	auto_bool_<I>& operator =(bool n)	{ hide_data=n; return *this; }
	operator bool() const	{ return hide_data; }

	bool	hide_data;
};
typedef	auto_bool_<false>	auto_bool;

//////////////////////////////////////////////////////////////////////
template<TYPENAME T>
struct auto_object
{
	auto_object() : hide_ptr(0) {}
	auto_object<T>& operator =(T* p)	{ hide_ptr=p; return *this; }
	operator T*() const	{ return hide_ptr; }

	T*	hide_ptr;
};

//////////////////////////////////////////////////////////////////////
template<TYPENAME T>
struct auto_point
{
	auto_point() : hide_ptr(0) {}
	auto_point<T>& operator =(T* p)	{ hide_ptr=p; return *this; }
	operator T*() const	{ return hide_ptr; }
	T* operator ->() const	{ return hide_ptr; }

	T*	hide_ptr;
};

//////////////////////////////////////////////////////////////////////
template<TYPENAME T>
class hide_type
{
	T	hide_data;
public:
	T&	HideData()		{ return hide_data; }
};


struct OBJPOS {
	USHORT x, y, z;
	OBJPOS(USHORT nPosX = 0, USHORT nPosY = 0, USHORT nPosZ = 0) 
		: x(nPosX), y(nPosY), z(nPosZ) {}
	
	bool operator == (const OBJPOS& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	//by lhm
	bool operator !=(const OBJPOS& rhs) const
	{
		return x!=rhs.x || y != rhs.y || z != rhs.z;
	}
	
	//by lhm ����stl����Ҫ����"<"�������򣬱Ƚ����� ͨ�� ����
	bool operator < (const OBJPOS& rhs) const	
	{
		return ((x*x + y*y) < (rhs.x*rhs.x + rhs.y*rhs.y));
	}	

	OBJPOS& operator = (const OBJPOS& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}
};
/*
inline bool operator<(const OBJPOS& a, const OBJPOS& b)	{ return a.x < b.x || (!(b.x < a.x) && a.y < b.y); }
inline bool operator>(const OBJPOS& a, const OBJPOS& b)	{ return b < a;}
inline bool operator<=(const OBJPOS& a, const OBJPOS& b)	{ return !(b < a);}
inline bool operator>=(const OBJPOS& a, const OBJPOS& b)	{ return !(a < b);}
*/

struct OBJSIZE {
	int w, h, l;
	OBJSIZE(int nWidth = 0, int nHeight = 0, int nLength = 0) 
		: w(nWidth), h(nHeight), l(nLength) {}
	bool operator == (const OBJSIZE& rhs) const
	{
		return w == rhs.w && h == rhs.h && l == rhs.l;
	}
	OBJSIZE& operator = (const OBJSIZE& rhs)
	{
		w = rhs.w;
		h = rhs.h;
		l = rhs.l;
		return *this;
	}
};

//struct Pix 
//{
//	int x, y;
//	Pix(int nX = 0, int nY = 0) 
//		: x(nX), y(nY){}
//	
//	bool operator == (const Pix& rhs) const
//	{
//		return x == rhs.x && y == rhs.y;
//	}
//	Pix& operator = (const Pix& rhs)
//	{
//		x = rhs.x;
//		y = rhs.y;
//		return *this;
//	}
//};
//inline bool operator<(const Pix& a, const Pix& b)	{ return a.x < b.x || (!(b.x < a.x)); }
//inline bool operator>(const Pix& a, const Pix& b)	{ return b < a;}
//inline bool operator<=(const Pix& a, const Pix& b)	{ return !(b < a);}
//inline bool operator>=(const Pix& a, const Pix& b)	{ return !(a < b);}
//#define Pix OBJPOS 

struct MAPTHING_INFO_ST
{
	OBJTYPE ObjType;
	OBJID   idObj;

	MAPTHING_INFO_ST()
	{
		this->ObjType = OBJ_NONE;
		this->idObj = ID_NONE;
	}

	bool IsValid()
	{
		return (this->ObjType > 0 && this->idObj > 0);
	}

};

typedef	char			SQLBUF[1024];
typedef	char			MSGBUF[1024];
typedef	char			MESSAGESTR[1048];
typedef	char			NAMESTR[16];
typedef	char			PARAMBUF[256];
// set
typedef std::vector<OBJID>		ID_VEC;
typedef ID_VEC::iterator		ID_VEC_IT;
typedef std::deque<OBJID>		ID_DEQ;
typedef std::set<OBJID>	        ID_SET;
typedef ID_SET::iterator		ID_SET_IT;
typedef std::map<INT, OBJID>	ID_MAP;
typedef ID_MAP::iterator		ID_MAP_IT;
typedef ID_MAP::const_iterator	ID_MAP_CIT;
typedef std::unordered_set<OBJID>	ID_HASH_SET;
typedef std::map<int, ID_HASH_SET> ID_MAP_SET;
typedef std::vector<MAPTHING_INFO_ST> MAPTHING_SET;
typedef std::vector<int> SET_FUNCTIONCODE;
typedef std::vector<OBJPOS> OBJPOSVec;
typedef	POINT	CMyPos;
typedef OBJPOS	Pix;

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#endif // end of define _TQ_TYPES_H_

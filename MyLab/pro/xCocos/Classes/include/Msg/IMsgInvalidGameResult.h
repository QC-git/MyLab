#pragma once

#include "BaseCode/BaseMacro.h"

NAMESPACE_BEGIN(msginvalidgameresult)


#pragma pack(push, 1)

enum EResult
{
    eResult_Win,
    eResult_Lose,
    eResult_Abort,
};


struct INVALID_GAMING_RESULT
{
	uint32_t	result;					// ս�������EResult
	int32_t     score;                  // ��û��߼��ٵ�ƥ���
	uint32_t	heroType;				// ѡ���Ӣ��--�ⳡս��ѡ���Ӣ��ͳ��
	uint32_t	equip1;                 // װ��1
	uint32_t	equip2;					// װ��2
	uint32_t	equip3;					// װ��3
	uint32_t	equip4;					// װ��4
	uint32_t	equip5;					// װ��5
	uint32_t	equip6;					// װ��6
	uint32_t	killHeroAmount;			// ��ɱӢ������	[�ۼ�]
	uint32_t	secondaryAttackAmount;	// ������		[�ۼ�]
	uint32_t	killNeutralityAmount;	// ��������
	uint32_t    dieAmount;              // ��������
	uint32_t	gameTime;				// ������ʼʱ��
	uint32_t	endTime;				// ������ʼʱ��
	uint32_t    gameMode;               // ��Ϸģʽ

	uint32_t	worldId;
	uint32_t	accountId;
};

typedef struct
{
	USHORT	usMsgSize;
	USHORT	usMsgType;

	INVALID_GAMING_RESULT results[10];
}MSG_INVALID_GAME_RESULTS, *PMSG_INVALID_GAME_RESULTS;

#pragma pack(pop)

NAMESPACE_END(msginvalidgameresult)

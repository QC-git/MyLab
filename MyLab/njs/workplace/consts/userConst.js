/**
 * Created by tweyseo on 2015/5/27.
 */


module.exports = {
    moduleName: {
        info: 'info',
	    item: 'item',
        hero: 'hero',
        lottery: 'lottery'
    },
    notifyRoute: {
        //user
        userExpUpdate: "userExpUpdate",
        resUpdate: "resUpdate",
        shopPointUpdate: "shopPointUpdate",
        itemUpdate: "itemUpdate",
        powerUpdate: "powerUpdate",
        actionType: "actionType",
        rankScoreUpdate: "rankScoreUpdate",
        durabilityUpdate: "durabilityUpdate",
        //lastStatus: "user.lastStatus",

        //hero
        addHero: "addHero",
        updateHero: "updateHero",
        heroLevelUp: "heroLevelUp",
        heroExpUpdate: "heroExpUpdate",
        updateExpOrb: "updateExpOrb",

        //room
        processGameResult: "processGameResult",
        processUserLeave: "processUserLeave",
        processUserEnterMatch: "processUserEnterMatch",
        processUserLeaveMatch: "processUserLeaveMatch",
        processUserPunishMatch: "processUserPunishMatch",
        gameAward: "gameAward",

        //lottery
        updateLotteryTime: "updateLotteryTime",

        chat: {
            onChat: "onChat",                            // 普通聊天
            onFriendPrivateChat: "onFriendPrivateChat"   // 好友私聊
        },

        //task
        updateTaskData: "updateTaskData",
        updateAllTaskData: "updateAllTaskData",

        friend: {
            invite: "friend.invite",    //好友申请
            accept: "friend.accept",    //接受申请
            reject: "friend.reject"     //拒绝申请
        },

        room: {
            roomUpdate: "room.roomUpdate",
            roomConnect: "room.roomConnect",
            userLogout: "room.userLogout",
            userReady: "room.userReady",
            userUnReady: "room.userUnReady",
            gameStart: "room.gameStart",
            gameRobot: "room.gameRobot",
            matchConfirm: "processUserConfirmMatch",
            matchFlag: "match.matchFlag",
            matchReject: "match.matchReject",
            matchTimeout: "processUserConfirmTimeOut"
        },

        team: {
            onKick: "team.onKick",       //被踢了
            onInvite: "team.onInvite",    //被邀请
            onUpdate: "team.onUpdate",    // 队伍更新
            onChat: "team.onChat",
            onLeave: "team.onLeave"
        }
    },
    user: {
        maxLevel: 60,
        maxHeroLvl: 10,
        maxGold: 1000000000,   //2147483647,
        maxIngot: 1000000000  //2147483647
    },

    tutorial: {
        CHAPTER_1: 1,
        CHAPTER_2: 2,
        CHAPTER_MAX: 2
    },

    ingotUse: {
        buyPower: "buyPower",
        buyItem: "buyItem",
        composeHero: "composeHero",
        gameAward: "gameAward",
        lotteryHero: "lotteryHero",
        lotteryEquip: "lotteryEquip"
    },
    lottery: {
        type: {
            hero: 1,            //英雄
            equip: 2            //装备
        },
        mod: {
            freeNormal: 1,      //普通免费
            free: 2,            //代币免费
            payGold: 3,         //金币
            payIngot: 4,        //代币
            costItem: 5         //消耗物品
        }
    },
    mall:{
        cType:{                 //商品类型
            hero:1,             //英雄
            item:2              //装备
        },
        mType:{                 //购买方式
            gold:1,             //金币
            ingot:2,            //钻石
            shopPoint: 3        //商店积分
        }
    },
    camp:{
        eCamp_A:0,
        eCamp_B:1,
        eCamp_Judge:2
    },
    task:{
        taskType:{
            1:"完成对战",
            2:"赢得对战",
            3:"连胜对战"
        },
        taskMode:{
            1:"1v1",
            2:"3v3",
            3:"5v5"
        }
    },
    room: {
        eMode: {
            SINGLE: 0,
            CUSTOM: 1,
            MATCH_1V1: 11,
            MATCH_3V3: 12,
            MATCH_5V5: 13,
            MATCH_1V1_ROBOT: 21,
            MATCH_3V3_ROBOT: 22,
            MATCH_5V5_ROBOT: 23
        },
        eStatus: {
            NONE: 0,
            INIT: 1,
            CHGHERO: 2,     //选英雄
            STARTING: 3,
            GAME_END: 4,
            FAIL: 99
        },
        actionType: {
            chgCamp: 0,                //选择阵营
            chgRole: 1,                //选择英雄角色
            tryChgRole: 2,             //尝试选择英雄角色
            enterChgRole: 3,           //进入选人界面
            chgRoleFail: 4,            //英雄选择失败
            chgName: 5,                //改名
            tryChgRoleSkin: 6,        //尝试更换英雄角色皮肤
            tryChgRoleSkinFail: 7    //尝试更换英雄角色皮肤失败
        },
        eCause: {
            NONE: 0,
            ENTER: 1,
            LEAVE: 2,
            SET_ROOM: 3,
            SET_USER: 4,
            GAME_END: 5
        },
        eCamp:{
            eCamp_A: 0,
            eCamp_B: 1,
            eCamp_Judge: 2
        },
        eGameResult: {
            eWin: 0,
            eLose: 1,
            eAbort: 2,
            eAbortEX: 3,				//逃跑
            eWinEx: 4,				//推到对方主堡胜利
            eFailEx: 5,				//推到对方主堡失败
            ePunish: 6,				//惩罚
            eReturnLadder: 7,		//返回天梯
            eSingleWin: 8,
            eNegative: 9,			//消极比赛
            eWaiGua10: 10,			// 检测到外挂
            ePunish_DECSCORE: 11	    //ban人匹配秒退 扣分
        },
        eSet: {
            eMapId: 0,
            ePassword: 1,  // 设置摩玛
            eOwner: 2,  // 设置房主
            eCampNum: 3,  // 设置阵营人数
            eCampPos: 4,    // 设置阵营位置锁定或解锁
            eRobot: 5   // 设置机器人
        }
    },
    "team": {
        eCause: {
            NONE: 0,
            ENTER: 1,
            LEAVE: 2,
            LOGIN: 3,
            LOGOUT: 4,
            KICK: 5,
            DISBAND: 6
        }
    }
};
module.exports = {
    OK: 0,
    FAIL: 1,
    DB_Err: 2,
    RPC_Err: 3,
    Mod_Error: 422,     //实体错误
    Param_Err: 406,     //参数错误
    Unauthorized: 401,  //用户未登录
    Forbidden: 403,     //权限不足
    Not_Found: 404,     //资源不存在
    Conflict: 409,      //资源冲突

    //权限相关
    Auth: {
        Invalid_Version: 1000,      //版本错误
        Repeat_Login: 1001,         //重复登录
        Invalid_accType: 1002,      //非法访问
        Param_Err: 1003,            //参数错误
        Not_Exist_In_99: 1004,      //账号不存在
        Psw_Err: 1005,              //密码错误
        Sql_Err: 1006,              //数据库错误
        Game_No_Active: 1007,       //游戏未激活
        Not_Exist_In_Game: 1008,    //不在游戏中
        DB_Err: 1009,               //数据错误
        QQ_OpenId_Not_Exist: 1010,  //QQ openID不存在
        QQ_Token_Expired: 1011,     //QQ token无效
        Request_QQ_Fail: 1012,      //请求(QQ)错误
        QQ_Not_Login: 1013          //QQ未登录
    },

    //角色
    User: {
        Not_Exist: 2000,            //角色不存在
        Create_Params_Err: 2001,    //创建角色:参数错误
        Create_Module_Err: 2002,    //模快錯誤
        DB_Err: 2003,               //数据库錯誤
        Invalid_Sesuid: 2004,       //无效的Sessuid
        Name_InValid: 2005,         //名字无效
        LevelMax: 2006,             //达到最大等级
        ParamsErr: 2007,            //参数错误(各种操作)
        GoldMax: 2008,              //金币达最大
        IngotMax: 2009,             //元宝达最大
        NameExist: 2010,            //名字已存在
        Name_Forbidden: 2011,       //名字禁用
        NoBuyPowerTimes: 2012,      //没有购买次数
        GoldLess: 2013,             //金币不足
        IngotLess: 2014,             //元宝不足
        ShopPointLess: 2023,        //商店积分不足

	    SkillPointLack: 2015,       // 技能点不足
        MaxPurchase: 2016,          // 最大购买次数
        MaxSkillLevel: 2017,        // 最高等级

        BadgeLess: 2018,            // 徽章不足
        BadgeNotFit: 2019,           // 徽章不匹配

        BallOrbLess: 2020,          // 经验球不足
        BallOrbNotFit: 2021,        // 经验球不匹配

        LevelLess: 2022,             // 等级不足
        Not_Online: 2023             // 用户不在线
    },

    //物品
    Item: {
        Not_Exist: 3000,    //不存在
        Is_Take_ON: 3001,   //已装备
        Is_Used: 3002,      //已占用
        DB_Err: 3003,       //数据库错误
        index_Err: 3004,    //装备位置错误,
        Is_Occupied: 3005,  //位置已被占用
        MaxNum: 3006,       //达到最大数量
        TidFixErr: 3007,    //Tid不一致
        NumLess: 3018,      //数量不足
        MaxLevel: 3019,     //达到最大等级
        DurabilityLess: 3020//耐久度不足
    },

    //英雄
    Hero: {
        Exist: 4000,        //已存在
        DebrisLess: 4001,   //碎片不够(合成)
        NoExist: 4002,      //不存在
        ParamsErr: 4003,    //参数错误
        StarMax: 4004,      //达到最大阶
        LevelMax: 4005,     //达到最大等级
        HasSkill: 4006,     //已经有了技能
        NoSkill: 4007,      //没有技能
        DataUpdate: 4008,   //数据更新
        LevelLess: 4009,    //等级不足
        StepMax:4010,       //品阶上限
        HasWhole: 4011      //有完整的英雄
    },

    //副本
    Instance: {
        FAIL: 5001,
        NO_ID: 5002,        //副本ID错误
        NO_FIT:5003         //条件不满足
    },

    //技能
    Skill:{
        Not_Exist: 6001, // 技能不存在
        Locked: 6002 // 技能未解锁
    },

    //抽奖
    Lottery: {
        ParamsErr: 7000,    //参数错误
        NoCount: 7003,      //次数不够
        HasCD: 7001,        //cd未冷却
        HasNoItem: 7002     //没有消耗品
    },

    //好友
    Friend: {
        isFriend: 8000,         //已是好友
        isNotFriend: 8001,      //不是好友
        isApplied: 8002,        //已经申请
        MaxFriendNumber: 8003   //好友上限
    },

    //任务
    Task: {
        NotCompleted: 9000,       //任务未完成
        AlreadyReceived: 9001,    //任务已领取
        PointLess: 9002           //竞技点不足
    },

    //房间
    Room: {
        UnKnown: 10000,
        RoomModIsLock: 10010,   // 房间模块被锁定
        NoRoom: 10021,          // 没有找到房间
        NoSupport: 10022,       // 不支持该功能
        NoOwner: 10023,         // 不是房主
        NoFindUser: 10024,      // 没有找到成员
        NoReady: 10025,         // 没有准备
        NoSupportMode: 10026,   // 不支持该模式
        NoMatch: 10027,         // 不在匹配
        RoomIsFail: 10031,      // 房间异常
        RoomIsIdle: 10032,      // 房间空闲
        RoomIsStart: 10033,     // 房间已经启动
        RoomIsFull: 10041,      // 房间已经满员
        CampIsFull: 10042,      // 阵营已经满员
        UserIsOwner: 10043,     // 用户是房主
        BsIsRefuse: 10044,      // 战斗服务器拒绝
        UserIsInRoom: 10045,    // 用户已经在房间内
        RoomIdDup: 10046,       // 房间ID重复
        ParamsError: 10047,      // 参数错误
        LockError: 10048,        // 锁定失败
        UserIsInPos: 10049,       // 当前位置有人
        NoFoundRobot: 10050,     // 没有找到机器人
        UserIsInTeam: 10051,      // 用户在队伍中
        PosIsLock: 10052,          // 位置已经锁住
        ConfirmIdDup: 10053,       // 确认id重复
        IsPunishing: 10054          // 被惩罚

    },

    //宝石
    Gem: {
        Not_Exist: 11000,       //没有找到
        Invalid_Pos: 11001,     //无效栏位
        NoActive: 11002,        //未激活
        HasLock: 11003,          //未开锁
        HasGem: 11004,          //此栏位有宝石
        NoGem: 11005,
        HasSame: 11006,         //有相同的宝石
        HasReleaseLock: 11007        //已经解锁
    },

    //天赋
    Talent: {
        NotExist: 12000,        //没有找到
        InvalidPos: 12001,      //无效栏位
        NoActive: 12002,        //未激活
        HasLock: 12003,         //未开锁
        HasTalent: 12004,       //此栏位有天赋
        NoTalent: 12005,
        HasSame: 12006,         //有相同的天赋
        HasReleaseLock: 12007,  //已经解锁
        PageMax: 12008          //天赋页上限
    },

    //队伍：
    Team: {
        UnKnown: 13000,
        HasTeam: 13001,       // 已经在队伍中
        NoTeam: 13002,         // 没有队伍
        NoFound: 13003,    // 没有找到队伍
        NoFoundUser: 13004,  // 队伍中没有找到用户
        NoOwner: 13005,    // 不是队长
        ParamsError: 13006,  // 参数错误
        UserIsBusy: 13007,    // 用户正忙
        NoReady: 13008,        // 未准备
        IsPunishing: 13009          // 被惩罚

    },

    //聊天
    Chat:{
        MaxAmount:14001     //人数上限
    }
};

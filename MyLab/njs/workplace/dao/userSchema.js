(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var ec = depInj('ec');
    var prizeHero = depInj('json', 'tpl/prizeHero');

    var Schema = mongoose.Schema;
    var heroSchema = require('./heroSchema').schema,
        heroEvaluateSchema = require('./heroEvaluateSchema').schema,
        itemSchema = require('./itemSchema').schema,
        instanceSchema = require('./instanceSchema').schema,
        expOrbSchema = require('./expOrbSchema.js').schema,
        badgeSchema = depInj('dao', 'badgeSchema').schema,
        matchSchema = depInj('dao', 'matchSchema').schema,
        talentSchema = depInj('dao', 'talentSchema').schema,
        signInSchema = depInj('dao', 'signInSchema').schema,
        heroRecEquipSchema = depInj('dao', 'heroRecEquipSchema').schema;


    var UserSchema = new Schema({
        _id:    {type: String, index: true, unique: true, required: true},
        areaId: {type: Number, default: 1},             //区号
        name:   {type: String/*, index: true, unique: true*/},
        sex:    {type: Number, default: 0},             //性别
        head:   {type: String},                          //头像
        level:  {type: Number, default: 1, max: 255},
        exp:    {type: Number, default: 0},             //经验
        power:  {type: Number, default: 0},             //体力
        buyPowerTimes: {type: Number, default: 0},      //体力购买次数
        gold:   {type: Number, default: 0},             //金币
        ingot:  {type: Number, default: 0},             //元宝
        vipLvl: {type: Number, default: 0},
        skillPoint: {type: Number, default: 0},
        shopPoint:  {type: Number, default: 0},      //商店积分
        lastSPChangeTime:   {type: Date, default: Date.now},  //上次技能点修改时间
        purchaseSPTimes:    {type: Number, default: 0},

        signIn: {type: signInSchema},               //签到信息

        //lottery
        heroOrder:                  {type: Number, default: 0},     //英雄令(抽卡使用)
        lotteryHeroLuck:            {type: Number, default: 1},     //英雄抽奖幸运值
        freeCountNormal:            {type: Number, default: prizeHero.rule.freeCount},  //普通免费次数
        freeCount:                  {type: Number, default: prizeHero.rule.freeCount},  //元宝免费次数
        lastLotteryHeroTimeNormal:  {type: Date, default: 0},       //上一次免费抽英雄的时间(普通)
        lastLotteryHeroTime:        {type: Date, default: 0},       //上一次免费抽英雄的时间(元宝)
        lastLotteryEquipTime:       {type: Date, default: 0},       //上一次免费抽装备的时间

        heros: [heroSchema],                // 英雄
        heroEvaluates: [heroEvaluateSchema],// 英雄功勋
        items: [itemSchema],                // 物品
        badges: [badgeSchema],              // 徽章
        expOrb: [expOrbSchema],
        talents: [talentSchema],            // 天赋
        matchRecord: [matchSchema],         // 比赛记录
        instanceRecord: [instanceSchema],    // 副本记录

        heroRecEquips: [heroRecEquipSchema],     //英雄推荐装备列表
        serialNumber: {type: String},      // 最后登录设备序列号
        ip: {type: String},                // 最后登录ip
        createTime: {type: Date, default: Date.now},
        lastLoginTime: {type: Date, default: Date.now},
        lastLogoutTime: {type: Date, default: Date.now},

        rankScore: {type: Number, default: 1200},      // 匹配赛分数
        maxRankScore: {type: Number, default: 1200},      // 最大匹配赛分数
        ladderScore: {type: Number, default: 1200},    // 排位赛分数
        maxLadderScore: {type: Number, default: 1200},    // 最大排位赛分数
        tutorialInfo: {type: Number, default: 0},      // 新手任务

        matchNegativeTime: {type: Date, default: Date.now},　　// 匹配消极时间
        matchNegativeCount:　{type: Number, default: 0},       // 匹配消极次数

        loginVersion: {type: String, default: ''}              //当前登陆版本

    }, {collection: "user", versionKey: false});

    UserSchema.pre('save', function (next, cb) {
        //console.log();
        //if(!this.issave){
        //    this.issave = true;
        //    next();
        //}else{
        //
        //    cb(new Error("save duplicate"));
        //}
        tryToSave(this, next, cb);
    });

    var tryToSave = function (self, next, cb) {
        if (!self.issave) {
            self.issave = true;
            next();
        } else {
            self.lastsave = next;
            logger.warn('save duplicate, wait to next');
            cb(null,self);
            //self.tryTimes += 1;
            //if (self.tryTimes >= 3) {
            //    cb(ec.DB_Err, {data: 'save duplicate, tryTimes over' + self.tryTimes});
            //    return;
            //}
            //setTimeout(function () {
            //    tryToSave(self, next, cb);
            //}, 1000);
        }
    };

    UserSchema.post('save', function () {
        this.issave = false;
        if(this.lastsave){
            this.lastsave();
            this.lastsave = null;
        }
        //this.tryTimes = 0;
    });

    UserSchema.statics.findByName = function (name, cb) {
        this.findOne({name: name}, cb);
    };

    UserSchema.statics.findByNameAndAreaId = function (name, areaId, cb) {
        this.findOne({name: name, areaId: areaId}, cb);
    };

    UserSchema.methods.updateLoginTime = function () {
        this.lastLoginTime = Date.now();
    };

    UserSchema.methods.updateLogoutTime = function () {
        this.lastLogoutTime = Date.now();
    };

    UserSchema.methods.addResource = function (params, cb) {
        if (params.gold > 0 && this.gold >= userConst.user.maxGold) {
            cb(ec.User.GoldMax);
            return;
        }
        if (params.ingot > 0 && this.ingot >= userConst.user.maxIngot) {
            cb(ec.User.IngotMax);
            return;
        }

        if (userConst.user.maxGold - this.gold < params.gold) {
            this.gold = userConst.user.maxGold;
        } else {
            this.gold += params.gold;
        }
        if (userConst.user.maxIngot - this.ingot < params.ingot) {
            this.ingot = userConst.user.maxIngot;
        } else {
            this.ingot += params.ingot;
        }
        cb(ec.OK);
    };

    //UserSchema.methods.reduceResource = function (params) {
    //    if (this.gold < params.gold) {
    //        this.gold = 0;
    //    } else {
    //        this.gold -= params.gold;
    //    }
    //
    //    if (this.ingot < params.ingot) {
    //        this.ingot = 0;
    //    } else {
    //        this.ingot -= params.ingot;
    //    }
    //};

    //exports.Model = mongoose.model('User', UserSchema);

    var UserModel = mongoose.model('User', UserSchema);
    UserModel.prototype.issave = false;
    UserModel.prototype.lastsave = null;
    exports.Model = UserModel;

})();

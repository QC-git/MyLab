/**
 * Created by Lingg on 2016/1/28.
 */


(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var ec = depInj('ec');
    var Schema = mongoose.Schema;

    var battleRstSchema = new Schema({
        heroId: {type: Number},             //使用英雄
        win: {type: Number},                //1: win  0:lose
        mode: {type: String},             //战斗模式
        endTime: {type: String},            //结束时间 2016.01.12 12:38
        exp: {type: Number},
        gold: {type: Number},               //结算获得的金币
        btTime: {type: Number},             //战斗时长 16 minutes
        score: {type: Number},              //得分
        killHeroNum: {type: Number},                //击杀
        dieNum: {type: Number},                 //死亡
        secAttNum: {type: Number},              //助攻
        moreKill: {type: Number},               //最高多杀
        seriesKill: {type: Number},          //连杀
        endureDamage: {type: Number},           //承受的伤害量
        getMoney: {type: Number},               //获得金钱(不含卖)
        totalDamage: {type: Number, default: 0},            //输出总伤害
        killBatmen: {type: Number, default: 0},             //击杀小兵
        killNeutral : {type: Number, default: 0},           //击杀中立生物
        killBuild: {type: Number, default: 0},      //摧毁建筑(炮台+兵营)
        honor: {type: String},                //荣誉
        equipInfo: {type: [Number]},             //装备信息

        //功勋
        evaluate: {type: Number},
        oldEvaluateLevel: {type: Number},
        oldEvaluate: {type: Number},
        curEvaluateLevel: {type: Number},
        curEvaluate: {type: Number}
    }, {versionKey: false});


    var battleRstsSchema = new Schema({
        _id: {type: String, ref: 'User'},
        info: [battleRstSchema]
    }, {collection: "battleRst", versionKey: false});


    battleRstsSchema.statics.findByUid = function (uid, cb) {
        this.findOne({_id: uid}, cb);
    };

    module.exports.schema = battleRstsSchema;
    module.exports = mongoose.model('battleRst', battleRstsSchema);
})();

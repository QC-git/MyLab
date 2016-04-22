/**
 * Created by Lingg on 2016/4/18.
 */


(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'battle_record',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true,
                defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            uid:        {type: 'string'},
            heroId:     {type: 'integer'},             //使用英雄
            win:        {type: 'integer'},                //1: win  0:lose
            mode:       {type: 'string'},             //战斗模式
            endTime:    {type: 'string'},            //结束时间 2016.01.12 12:38
            exp:        {type: 'integer'},
            gold:       {type: 'integer'},               //结算获得的金币
            btTime:     {type: 'integer'},             //战斗时长 16 minutes
            score:      {type: 'integer'},              //得分
            killHeroNum: {type: 'integer'},                //击杀
            dieNum:     {type: 'integer'},                 //死亡
            secAttNum:  {type: 'integer'},              //助攻
            moreKill:   {type: 'integer'},               //最高多杀
            seriesKill: {type: 'integer'},          //连杀
            endureDamage: {type: 'integer'},           //承受的伤害量
            getMoney:   {type: 'integer'},               //获得金钱(不含卖)
            totalDamage: {type: 'integer', defaultsTo: 0},            //输出总伤害
            killBatmen: {type: 'integer', defaultsTo: 0},             //击杀小兵
            killNeutral: {type: 'integer', defaultsTo: 0},           //击杀中立生物
            killBuild:  {type: 'integer', defaultsTo: 0},      //摧毁建筑(炮台+兵营)
            honor:      {type: 'string'},                //荣誉
            equipInfo:  {type: 'array'},             //装备信息

            //功勋
            evaluate:           {type: 'integer'},
            oldEvaluateLevel:   {type: 'integer'},
            oldEvaluate:        {type: 'integer'},
            curEvaluateLevel:   {type: 'integer'},
            curEvaluate:        {type: 'integer'},

            // Add a reference to User
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

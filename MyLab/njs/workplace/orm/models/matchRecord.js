(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'matchrecord',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },

            uid: {type: "string"},
            mode: {type: "integer"},

            total: {type: "integer", defaultsTo: 0},                   // 总场数
            victory: {type: "integer", defaultsTo: 0},                 // 胜利场数

            killHeroAmount:{type: "integer", defaultsTo: 0},          // 击杀英雄数
            secondaryAttackAmount:{type: "integer", defaultsTo: 0},   // 击杀英雄数
            evaluateState: {type: "array"},         // 评价数组说明[mvp,破敌,偏将,英灵,牺牲,破营,富豪]

            seriesVictory: {type: "integer", defaultsTo: 0},           // 连胜
            maxSeriesVictory: {type: "integer", defaultsTo: 0},        // 最高连胜

            escape: {type: "integer", defaultsTo: 0},                   // 逃跑

            owner: {
                model: 'user'
            }

        }
    };

    module.exports = Model;
})();
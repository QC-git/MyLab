(function () {
    'use strict';


    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var matchSchema = new Schema({
        mode: {type: Number},

        total: {type: Number, default: 0},                   // 总场数
        victory: {type: Number, default: 0},                 // 胜利场数

        killHeroAmount:{type: Number, default: 0},          // 击杀英雄数
        secondaryAttackAmount:{type: Number, default: 0},   // 击杀英雄数
        evaluateState: [{type: Number, default: 0}],         // 评价数组说明[mvp,破敌,偏将,英灵,牺牲,破营,富豪]

        seriesVictory: {type: Number, default: 0},           // 连胜
        maxSeriesVictory: {type: Number, default: 0}         // 最高连胜

    }, {versionKey: false});

    module.exports.schema = matchSchema;
    module.exports = mongoose.model('match', matchSchema);
})();
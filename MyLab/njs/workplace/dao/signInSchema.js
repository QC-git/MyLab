/**
 * Created by Lingg on 2016/1/20.
 */


(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var ec = depInj('ec');
    var Schema = mongoose.Schema;


    var signInSchema = new Schema({
        info: {type: [Number],
            default: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        },         //月签到信息 取最大31天
        accumulateDays: {type: Number, default: 0},                     //累积签到天数
        remedyDays:     {type: Number, default: 0},                     //补签天数
        lastSignInTime: {type: Number, default: 0},                     //最后一次签到时间
        awardReceive:   {type: [Number], default: [0, 0, 0, 0, 0, 0, 0]}       //累积签到奖励领取
    }, {versionKey: false});

    /*
    signInSchema.methods.reset = function () {
        this.info = initSignInData;
        this.accumulateDays = 0;
        this.remedyDays = 0;
        this.awardReceive = initAwardReceive;
    };
    */

    module.exports.schema = signInSchema;
    module.exports = mongoose.model('signIn', signInSchema);
})();

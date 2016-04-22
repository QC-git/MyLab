/**
 * Created by Lingg on 2016/4/15.
 */

(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'signin',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },

            info: {
                type: 'array',
                defaultsTo: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]      //月签到信息 取最大31天
            },

            accumulateDays: {type: 'integer', defaultsTo: 0},                     //累积签到天数
            remedyDays:     {type: 'integer', defaultsTo: 0},                     //补签天数
            lastSignInTime: {type: 'integer', defaultsTo: 0},                     //最后一次签到时间

            awardReceive:   {                                   //累积签到奖励领取
                type: 'array',
                defaultsTo: [0, 0, 0, 0, 0, 0, 0]},

            owner: {model: 'user'}
        }
    };

    module.exports = Model;
})();

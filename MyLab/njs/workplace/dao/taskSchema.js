(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var dailyListSchema = new Schema({
        _id: {type: Number, default: 0}
    });
    var mainTaskListSchema = new Schema({
        _id: {type: Number, default: 0}
    });
    var taskListSchema = new Schema({
        _id: {type: Number, default: 0},
        completeStatus: {type: Number, default: 0}, //任务完成状态 0:未完成 1:完成 2:已领取
        times: {type: Number, default: 0}
    });
    var taskLogsSchema = new Schema({
        taskMode: {type: Number, default: 0},
        win: {type: Number, default: 0},
        createTime:{type:Date,default:Date.now}
    });

    var schema = new Schema({
        _id: {type: String, ref: 'User'},
        dailyPoint: {type: Number, default: 0},
        totalPoint: {type: Number, default: 0},
        dailyList: [dailyListSchema],
        taskList: [taskListSchema],
        mainTaskList: [mainTaskListSchema],
        taskLogs: [taskLogsSchema],
        version: {type:Number,default:0},
        lastResetTime:{type:Date,default:0}
    }, {versionKey: false});

    module.exports.schema = schema;
    module.exports = mongoose.model('task', schema);
})();
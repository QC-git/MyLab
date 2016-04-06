(function () {
    'use strict';
    //require('./../util/global');

    var mongoose = require('./mongoose').mongoose;
    var ec = depInj('ec');

    var Schema = mongoose.Schema;

    var systemNotificationSchema = new Schema({
        type:{type: Number, default: 1},
        order: {type: Number, default: 0},
        startTime: {type: Date, default: Date.now},
        interval: {type: Number, default: 10},
        endTime: {type: Date, default: Date.now},
        content: {type: String, default: ''}
    }, {versionKey: false});


    module.exports.schema = systemNotificationSchema;
    module.exports = mongoose.model('systemnotification', systemNotificationSchema);
})();

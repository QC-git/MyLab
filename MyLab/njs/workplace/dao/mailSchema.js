(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var itemSchema = depInj('dao', 'itemSchema').schema;
    var Schema = mongoose.Schema;
    var sysMailSchema = new Schema({
        _id: {type: Number},
        isRead: {type: Number, default: 0},
        isReceived: {type: Number, default: 0},
        createTime: {type: Date, default: Date.now},
        updateTime: {type: Date, default: Date.now}
    });

    var schema = new Schema({
        _id: {type: String, index: true, unique: true, required: true, ref: 'User'},
        version: {type:Number,default:0},
        sysMails: [sysMailSchema]
    }, {versionKey: false});

    //schema.post('save', function (doc) {
    //    console.log('%s has been saved', doc);
    //})

    module.exports = mongoose.model('mail', schema);
})();
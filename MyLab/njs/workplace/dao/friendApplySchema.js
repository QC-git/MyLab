(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var ec = depInj('ec');
    var Schema = mongoose.Schema;

    var schema = new Schema({
        uid: {type: String, ref: 'User'},
        fid: {type: String, ref: 'User'},
        createTime: {type: Date, default: Date.now},
        updateTime: {type: Date, default: Date.now}
    }, {versionKey: false});

    //schema.pre('save', function (next) {
    //    console.log("===========this",this);
    //    next();
    //});
    //schema.post('save', function (doc) {
    //    console.log("===========doc",doc);
    //});

    module.exports = mongoose.model('friendApply', schema);
})();

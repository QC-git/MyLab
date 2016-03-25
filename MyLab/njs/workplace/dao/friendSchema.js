(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var ec = depInj('ec');
    var Schema = mongoose.Schema;

    var schema = new Schema({
        _id : { type: String, index: true, unique: true, required: true},
        fids: [{type: String, ref: 'User'}],
        createTime: {type: Date, default: Date.now},
        updateTime: {type: Date, default: Date.now}
    }, {versionKey: false});

    module.exports = mongoose.model('friend', schema);
})();

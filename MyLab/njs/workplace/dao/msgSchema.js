(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var userConst = depInj('userConst');
    var ec = depInj('ec');
    var Schema = mongoose.Schema;

    var schema = new Schema({
        route: {type: String},
        uid: {type: String, ref: 'User'},
        msgs: {type: Schema.Types.Mixed},
        createTime: {type: Date, default: Date.now},
        updateTime: {type: Date, default: Date.now}
    }, {versionKey: false});

    module.exports = mongoose.model('msg', schema);
})();

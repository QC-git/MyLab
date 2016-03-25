(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var instanceSchema = new Schema({
        id: {type: Number},
        challenge_count: {type: Number, default: 0},   // 挑战次数
        star_level: {type: Number, default: 0, max: 3}  // 最高星级
    }, {versionKey: false});

    module.exports.schema = instanceSchema;
    module.exports = mongoose.model('instance', instanceSchema);
})();
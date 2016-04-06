/**
 * Created by Lingg on 2016/3/30.
 */

(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var schema = new Schema({
        bsID: { type: Number },
        rEquips: { type: [], default: [-1, -1, -1, -1, -1, -1]},
    }, {versionKey: false});

    module.exports.schema = schema;
    module.exports = mongoose.model('heroRecEquip', schema);
})();

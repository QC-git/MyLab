(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var schema = new Schema({
        _id: { type: Number},
        number: {type: Number, default: 0}
    });

    module.exports.schema = schema;
    module.exports = mongoose.model('badge', schema);
})();
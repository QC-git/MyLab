(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var gemGroupSchema = new Schema({
        _id: false,
        talent: {type: Number},
        gems: [{type: String}]
    });

    var schema = new Schema({
        name: {type: String, required: true},
        gemGroups: [gemGroupSchema]
    }, {versionKey: false});

    module.exports.schema = schema;
    module.exports.gemGroupModel = mongoose.model('gemGroup', gemGroupSchema);
    module.exports.model = mongoose.model('talent', schema);
})();
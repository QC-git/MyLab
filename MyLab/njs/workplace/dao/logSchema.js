(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var schema = new Schema({
        action: {type: String},
        data: {type: Schema.Types.Mixed},
        createTime: {type: Date, default: Date.now}
    }, {versionKey: false});

    module.exports.schema = schema;
    schema.statics.insertLog = function (data, cb) {
        var datas = data.data;
        if (!datas || !_.isArray(datas)) {
            cb(ec.Param_Err);
            return;
        }
        //datas.pop();
        var modData = datas[0];
        this.create(modData, cb);
    };
    module.exports = mongoose.model('log', schema);
})();
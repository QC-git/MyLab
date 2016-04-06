(function () {
    'use strict';


    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var rankSchema = new Schema({
        type: {type: Number, default: 0},
        list: {type: [Schema.Types.Mixed]},      //排行数据，名次排列
        updateTime: {type: Date}
    }, {collection: "rank", versionKey: false});

    module.exports.schema = rankSchema;
    module.exports.Model = mongoose.model('rank', rankSchema);
})();
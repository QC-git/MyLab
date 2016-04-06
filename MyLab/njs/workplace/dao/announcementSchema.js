(function () {
    'use strict';

    var mongoose = require('./mongoose').mongoose;
    var ec = depInj('ec');

    var Schema = mongoose.Schema;

    var announcementSchema = new Schema({
        //_id : { type: ObjectId, index: true, unique: true, default: new mongoose.Types.ObjectId()},
        //id: {type: Number, default: 1},
        order: {type: Number, default: 0},
        title: {type: String, default: ''},
        content: {type: String, default: ''},
        createTime: {type: Date, default: Date.now}
    }, {collection: "announcement", versionKey: false});

    /*announcementSchema.statics.findById = function(id, cb) {
        this.findOne({id: id}, cb);
    };*/

    module.exports.schema = announcementSchema;
    module.exports = mongoose.model('announcement', announcementSchema);
})();

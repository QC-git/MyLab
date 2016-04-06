(function () {
    'use strict';
    //require('./../util/global');

    var mongoose = require('./mongoose').mongoose;
    var ec = depInj('ec');

    var Schema = mongoose.Schema;

    var chatAnnouncementSchema = new Schema({
        order: {type: Number, default: 0},
        content: {type: String, default: ''}
    }, {versionKey: false});


    module.exports.schema = chatAnnouncementSchema;
    module.exports = mongoose.model('chatannounce', chatAnnouncementSchema);
})();

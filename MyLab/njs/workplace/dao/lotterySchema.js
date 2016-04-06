/**
 * Created by Lingg on 2015/8/11.
 */

(function () {
    'use strict';
    //require('./../util/global');

    var mongoose = require('./mongoose').mongoose;
    var ec = depInj('ec');

    var Schema = mongoose.Schema;

    var lotterySchema = new Schema({
        type: {type: Number},                   //type: hero/equip
        record: {
            type: [
                {
                    name: String,           //user name
                    itemName: String,
                    quality: Number,        //品质
                    date: {type: Date, default: Date.now}
                }
            ],
            default: []
        }
    }, {collection: "lottery", versionKey: false});

    lotterySchema.statics.findAll = function(cb) {
        this.find({}, cb);
    };

    lotterySchema.statics.findByType = function(type, cb) {
        this.find({type: type}, cb);
    };

    lotterySchema.methods.addRecord = function (data) {
        this.record.push(data);

        var size = this.record.length;
        if (size > 10) {
            this.record.splice(0, size - 10);
        }
    };

    module.exports.schema = lotterySchema;
    module.exports = mongoose.model('lottery', lotterySchema);
})();

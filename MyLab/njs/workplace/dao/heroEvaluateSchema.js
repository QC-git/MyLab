/**
 * Created by shihuayang on 3/30/2016.
 */


(function () {
    'use strict';
    //require('/./../util/global');

    var ec = depInj('ec');
    var mongoose = require('./mongoose').mongoose;
    var Schema = mongoose.Schema;

    var HeroEvaluateSchema = new Schema({
        //_id is serial
        hid: {type: Number},            //hero id
        evaluate: {type: Number, default: 0},
        evaluateLevel: {type: Number, default: 0, max: 30}

    }, {versionKey: false});

    HeroEvaluateSchema.statics.findByUser_HeroId = function(uid, hid, cb) {
        this.findOne({hid: hid, uid: uid}, cb);
    };

    HeroEvaluateSchema.statics.findByUserId = function(uid, cb) {
        this.find({uid: uid}, cb);
    };

    module.exports.schema = HeroEvaluateSchema;
    module.exports = mongoose.model('heroEvaluate', HeroEvaluateSchema);
})();


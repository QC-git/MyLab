(function () {
    'use strict';
    var utils = depInj('utils');
    var async = require('async');
    var lodash = require('lodash');
    var _ = require('underscore');
    var utilEx = depInj("utilEx");

    var primaryKey = '_id';
    var merge = utils.merge;


    var Mod = function () {
    };

    var prop = Mod.prototype;

    prop.saveList = function(list, fn, cb) {
        var LadderRank = orm.collections.ladderrank;
        if (!cb) {
            cb = fn;
            fn = function() {};
        }
        LadderRank.query("DELETE FROM ladderrank", function(err) {
            if (err) {
                cb(err);
                return;
            }
            utilEx.doEach(list, function(i, item) {
                LadderRank.create(item).exec(function(err) {
                    if (err) {
                        fn(err);
                    }
                });
            });
            cb(null);
        });

    };

    prop.loadList = function(cb) {
        var LadderRank = orm.collections.ladderrank;
        LadderRank.find({}).exec(function(err, list) {
            if (err) {
                cb(err);
                return;
            }
            if (!list) {
                err = new Error("no data");
            }
            cb(err, list);
        });
    };

    module.exports = new Mod();
})();

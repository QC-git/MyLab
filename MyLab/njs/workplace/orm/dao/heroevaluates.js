/**
 * Created by shihuayang on 4/18/2016.
 */


(function () {
    'use strict';
    var utils = depInj('utils');
    var async = require('async');
    var primaryKey = '_id';
    var Mod = function () {
    };
    var prop = Mod.prototype;
    var merge = utils.merge;

    prop.set = function (mod, cb) {
        var mergeHeroEvaluate = function (cb) {
            var dao = orm.collections.heroevaluate;
            merge(dao, mod, function (err, data) {
                utils.invokeCallback(cb, err, data);
            });
        };

        mergeHeroEvaluate(cb);

        //async.waterfall([mergefriend],function(err,result){
        //    cb(err,result);
        //});
    };

    prop.get = function (_id, cb) {
        var dao = orm.collections.heroevaluate;
        dao.findOneBy_id(_id).exec(function (err, data) {
            if (err) {
                logger.warn('get heroevaluate err,', _id, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };
})();
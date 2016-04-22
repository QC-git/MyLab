/**
 * Created by Lingg on 2016/4/15.
 */

(function () {
    'use strict';
    var utils = depInj('utils');

    var merge = utils.merge;
    var dataName = 'signin';

    var Mod = function () {

    };

    var pro = Mod.prototype;
    pro.set = function (mod, cb) {
        var dao = orm.collections[dataName];
        merge(dao, mod, function (err, data) {
            utils.invokeCallback(cb, err, data);
        });
    };

    pro.get = function (_id, cb) {
        var dao = orm.collections[dataName];
        dao.findOneBy_id(_id).exec(function (err, data) {
            if (err) {
                logger.warn('-----------------get signin err:\n', _id, err);
            }
            utils.invokeCallback(cb, err, data);
        });
    };

    var createData = function (uid) {
        return {
            _id: uid,
            info: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            accumulateDays: 0,
            remedyDays: 0,
            lastSignInTime: 0,
            awardReceive: [0, 0, 0, 0, 0, 0, 0]
        };
    };

    module.exports = new Mod();
    module.exports.createData = createData;
})();

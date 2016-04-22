/**
 * Created by Lingg on 2016/4/18.
 */

(function () {
    'use strict';
    var utils = depInj('utils');

    var merge = utils.merge;
    var dataName = 'battle_record';


    var Mod = function () {

    };

    var pro = Mod.prototype;
    pro.set = function (mod, cb) {
        var dao = orm.collections[dataName];
        merge(dao, mod, function (err, data) {
            utils.invokeCallback(cb, err, data);
        });
    };

    pro.get = function (uid, cb) {
        var dao = orm.collections[dataName];
        dao.findByUid(uid).exec(function (err, data) {
            if (err) {
                logger.warn('-----------------get battle_record err:\n', uid, err);
            }
            utils.invokeCallback(cb, err, data);
        });
    };

    pro.deleteRecord = function (_id, cb) {
        var dao = orm.collections[dataName];
        dao.destroy(_id).exec(function (err, data) {
            if (err) {
                logger.warn('-----------------battle_record delete err:\n', uid, err);
            }
            utils.invokeCallback(cb, err, data);
        });
    };

    var createId = function () {
        return utils.GenUuid();
    };

    module.exports = new Mod();
    module.exports.createId = createId;
})();

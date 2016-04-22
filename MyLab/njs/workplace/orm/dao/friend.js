/**
 * Created by shihuayang on 4/13/2016.
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

    var select = ['name', 'level', 'head', 'vipLvl', 'createTime', 'lastLoginTime', 'lastLogoutTime'];

    prop.set = function (mod, cb) {
        var mergefriend = function(cb){
            var dao = orm.collections.friend;
            merge(dao, mod, function (err, data) {
                utils.invokeCallback(cb, err, data);
            });
        };

        mergefriend(cb);

        //async.waterfall([mergefriend],function(err,result){
        //    cb(err,result);
        //});
    };

    prop.get = function (_id, cb) {
        var dao = orm.collections.friend;
        dao.findOneBy_id(_id).exec(function (err, data) {
            if (err) {
                logger.warn('get friend err,', _id, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getFriend = function (uid, fid, cb) {
        var dao = orm.collections.friend;
        dao.findOne({owner: uid, fid: fid}).exec(function (err, data) {
            if (err) {
                logger.warn('get friend err,', _id, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.remove = function (uid, fid, cb) {
        var dao = orm.collections.friend;
        dao.destroy().where({owner: uid, fid: fid}).exec(function (err) {
            cb(err);
        });
    };

    prop.getFriendsByIds = function (fids, offset, limit, order, cb) {
        var dao = orm.collections.user;
        dao.find({_id: fids})
            //.populate('friends', {'fid': fids})
            .limit(limit)
            .skip(offset)
            .sort(order)
            .exec(function (err, data) {
                if (err) {
                    logger.warn('get user err,', uid, err);
                }

                utils.invokeCallback(cb, err, data);
        });
    };

    prop.getFriends = function (uid, cb) {
        var dao = orm.collections.friend;
        dao.find({owner: uid}).exec(function (err, friends) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, friends);
        });
    };

    prop.hasFriends = function (uid, fid, cb) {
        var dao = orm.collections.friend;
        dao.findOne({owner: uid, fid: fid}).exec(function (err, friend) {
            if (err) {
                logger.warn('get friend err,', uid, err);
                utils.invokeCallback(cb, err);
                return;
            }

            var res = 1;
            if (_.isUndefined(friend)) {
                res = 0;
            }

            utils.invokeCallback(cb, null, res);
        });
    };

    prop.getFriendsCount = function (uid, cb) {
        var dao = orm.collections.friend;
        dao.count().where({'owner': uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getUsersByConds = function (conds, cb) {
        var dao = orm.collections.user;
        dao.find(conds).select(select).exec(function (err, user) {
            if (err) {
                logger.warn('get user err,', conds, err);
                utils.invokeCallback(cb, err);
            }

            utils.invokeCallback(cb, null, user);
        });
    };

    //获取随机的用户，排除fids
    prop.getRandomUsers = function (areaId, fids, cb) {
        var dao = orm.collections.user;
        var time = new Date();
        time.setHours(0);
        time.setMinutes(0);
        time.setSeconds(0);
        time.setMilliseconds(0);
        var conditions = {lastLoginTime: {'>': time}};
        conditions.areaId = areaId;
        if (_.isArray(fids) && !_.isEmpty(fids)) {
            conditions._id = {'!': fids};
        }

        var limit = 10;
        dao.count(conditions).limit(5000).exec(function (err, data) {
            if (err) {
                logger.error('count user failed. ' + JSON.stringify(conditions) + ', err:' + err);
                cb(ec.DB_Err);
                return;
            }
            if (!data) {
                cb(ec.Not_Found);
                return;
            }
            var end = data - limit;
            if (end < 0) {
                end = 0;
            }
            //mongodb没有random功能,暂时采用skip方法 by feitianbubu 2015年8月25日 14:48:31
            var skip = _.random(0, end);
            dao.find(conditions).select(select).skip(skip).limit(limit).sort({lastLoginTime: 1}).exec(function (err, data) {
                if (err) {
                    cb(ec.DB_Err);
                    return;
                }
                if (!data) {
                    cb(ec.Not_Found);
                    return;
                }
                cb(ec.OK, data);
            });
        });
    };

    module.exports = new Mod();
})();
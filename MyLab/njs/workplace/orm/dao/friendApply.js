/**
 * Created by shihuayang on 4/12/2016.
 */
(function () {
    'use strict';
    var utils = depInj('utils');
    var async = require('async');
    var primaryKey = '_id';
    var Mod = function () {
    };
    var prop = Mod.prototype;

    var merge = function (dao, mod, options, cb) {
        if ('function' === typeof options) {
            cb = options;
            options = {};
        }
        var _id = mod[primaryKey];
        var create = function (cb) {
            dao.create(mod, function (err, data) {
                if (err) {
                    logger.warn('mod data set err', mod, data, err);
                }
                mod._id = data._id;
                utils.invokeCallback(cb, err, data);
            })
        }
        if (!_id) {
            create(cb);
            return;
        }
        dao.findOneBy_id(_id).then(function (data) {
            if (!data) {
                create(cb);
                return;
            }
            data = _.extend(data, mod);
            data.save(function (err) {
                if(err){
                    logger.warn('mod data set err', data, err);
                }
                utils.invokeCallback(cb, err, data);
            });
        }).catch(function (err) {
            logger.warn('mod data get err', mod, err);
            utils.invokeCallback(cb, ec.DB_Err);
        });
    }

    prop.set = function (mod, cb) {

        var mergefriendApply = function(cb){
            var dao = orm.collections.friendapply;
            merge(dao, mod, function (err, data) {
                utils.invokeCallback(cb, err, data);
            });
        };

        async.waterfall([mergefriendApply],function(err,result){
            cb(err,result);
        });
    };

    prop.get = function (_id, cb) {
        var dao = orm.collections.friendapply;
        dao.findOneBy_id(_id).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', _id, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.remove = function (_id, cb) {
        var dao = orm.collections.friendapply;
        dao.destroy({_id: _id}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', _id, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    //Accepting Friend 待接受的好友，自己请求对方加为好友
    prop.getAcceptingFriendsCount = function (uid, cb) {
        var dao = orm.collections.friendapply;
        dao.count().where({'uid': uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getAllAcceptingFriends = function (uid, cb) {
        var dao = orm.collections.friendapply;
        dao.find().where({'uid': uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getAcceptingFriendsByPage = function (uid, page, limit, cb) {
        var dao = orm.collections.friendapply;
        dao.find().where({'uid': uid}).paginate({page: page, limit: limit}).exec(function (err, data) {
            if (err) {
                logger.warn('get friendApply err,', uid, err);
                utils.invokeCallback(cb, ec.DB_Err);
                return;
            }

            if (_.isEmpty(data)) {
                utils.invokeCallback(cb, ec.OK, data);
                return;
            }

            var fids = _.pluck(data, 'fid');
            var daoUser = orm.collections.user;
            daoUser.find({'_id': fids}).exec(function (err, data) {
                if (err) {
                    logger.warn('get user err,', uid, err);
                }

                utils.invokeCallback(cb, err, data);
            });
        });
    };

    prop.getAcceptingFriend = function (uid, fid, cb) {
        var dao = orm.collections.friendapply;
        dao.findOne({uid: uid, fid: fid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.hasAcceptingFriends = function (uid, fid, cb) {
        var dao = orm.collections.friendapply;
        dao.count().where({'uid': uid, 'fid': fid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
                utils.invokeCallback(cb, err);
                return;
            }

            utils.invokeCallback(cb, err, data == 1);
        });
    };

    //Applied Friend 请求的好友，对方请求自己加为好友
    prop.getAppliedFriendsCount = function (uid, cb) {
        var dao = orm.collections.friendapply;
        dao.count().where({'fid': uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getAllAppliedFriends = function (uid, cb) {
        var dao = orm.collections.friendapply;
        dao.find().where({'fid': uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getAppliedFriendsByPage = function (uid, page, limit, cb) {
        var dao = orm.collections.friendapply;
        dao.find().where({'fid': uid}).paginate({page: page, limit: limit}).exec(function (err, data) {
            if (err) {
                logger.warn('get friendApply err,', uid, err);
                utils.invokeCallback(cb, ec.DB_Err);
                return;
            }

            if (_.isEmpty(data)) {
                utils.invokeCallback(cb, ec.OK, data);
                return;
            }

            var uids = _.pluck(data, 'uid');
            var daoUser = orm.collections.user;
            daoUser.find({'_id': uids}).exec(function (err, data) {
                if (err) {
                    logger.warn('get user err,', uid, err);
                }

                utils.invokeCallback(cb, err, data);
            });
        });
    };

    prop.getAppliedFriends = function (uid, fid, cb) {
        var dao = orm.collections.friendapply;
        dao.find({uid: fid, fid: uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.getAppliedFriend = function (uid, fid, cb) {
        var dao = orm.collections.friendapply;
        dao.findOne({uid: fid, fid: uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
            }

            utils.invokeCallback(cb, err, data);
        });
    };

    prop.hasAppliedFriends = function (uid, fid, cb) {
        var dao = orm.collections.friendapply;
        dao.count().where({'uid': fid, 'fid': uid}).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', uid, err);
                utils.invokeCallback(cb, err);
                return;
            }

            utils.invokeCallback(cb, err, data == 1);
        });
    };

    module.exports = new Mod();
})();
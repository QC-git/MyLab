(function () {
    'use strict';
    var utils = depInj('utils');
    var async = require('async');
    var lodash = require('lodash');

    var primaryKey = '_id';
    var merge = utils.merge;


    var Mod = function () {
        this.preMod = {};
    };

    var prop = Mod.prototype;
    prop.set = function (mod, cb) {
        var self = this;
        if(mod._mergeStatus){
            logger.warn('mod _mergeStatus waiting for next time to set.........');
            setTimeout(function(){self.set(mod,cb)},200);
            return;
        }
        var nextMod = self.nextMod;
        nextMod = lodash.cloneDeep(mod);
        mod._mergeStatus = 1;
        self.setDo(nextMod,function(err){
            mod._mergeStatus = 0;
            self.preMod = lodash.cloneDeep(mod);
            cb(err);
        });
    }
    prop.setDo = function (mod, cb) {
        var self = this;
        var mergeUser = function(cb){
            var dao = orm.collections.user;
            merge(dao, mod, function (err, data) {
                utils.invokeCallback(cb, err, data);
            });
        };

        var childNames = ['hero','item','talent','herorecequip','heroevaluate','matchrecord'];
        childNames.forEach(function(childName){
            var keyNames = childName+'s';
            var heros = mod[keyNames];
            var preHeros = self.preMod[keyNames];
            _.map(heros,function(hero){
                var _dirty = _.every(preHeros,function(preHero){
                    if(preHero){
                        delete preHero._dirty;
                    }
                    return !_.isEqual(hero,preHero);
                });
                hero._dirty = _dirty;
                return hero;
            })
        });

        var mergeChilds = function (cName, cb) {
            var keyName = cName+'s';
            var childs = mod[keyName];
            var childDao = orm.collections[cName];
            if (_.isEmpty(childs)) {
                utils.invokeCallback(cb, null,mod);
                return;
            }
            var mergeChild = function (child,cb) {
                // 如果对象不存在或者非_dirty状�?则不�?��改动
                if(!child || !child._dirty){
                    utils.invokeCallback(cb,null);
                    return;
                }
                child.owner = mod[primaryKey];
                merge(childDao,child,cb);
            }

            async.mapSeries(childs, mergeChild, function (err, results) {
                mod[keyName] = results;
                utils.invokeCallback(cb, err, mod);
            });
        };

        //var mergeHeros = function(cb){
        //    mergeChilds('hero', cb);
        //};
        //var mergeItems = function(cb){
        //    mergeChilds('item', cb);
        //};
        //var mergeTalents = function(cb){
        //    mergeChilds('talent', cb);
        //};
        //var mergeHeroRecEquips = function(cb){
        //    mergeChilds('herorecequip', cb);
        //};
        //var mergeHeroEvaluates = function(cb){
        //    mergeChilds('heroevaluate', cb);
        //};
        //var mergeMatchRecord = function(cb){
        //    mergeChilds('matchrecord', cb);
        //};
        //
        //var setFunObj = [mergeUser, mergeHeros, mergeItems, mergeTalents, mergeHeroRecEquips, mergeHeroEvaluates, mergeMatchRecord];

        mergeUser(function(err){
            if (err) {
                cb(err);
                return;
            }
            async.mapSeries(childNames,mergeChilds, function (err, result) {
                cb(err, result);
            });
        });
    };

    prop.get = function (_id, cb) {
        var dao = orm.collections.user;
        dao.findOneBy_id(_id).populate(['heros', 'items', 'talents', 'herorecequips','matchrecords']).exec(function (err, data) {
            if (err) {
                logger.warn('get user err,', _id, err);
            }

            // todo 兼容数据,后期可去
            if (data) {
                data.heros = data.heros || [];
                data.heroEvaluates = data.heroEvaluates || [];
                data.instanceRecord = data.instanceRecord || [];
                data.matchRecord = data.matchRecord || [{mode:11,total:0,victory:0,killHeroAmount:0,evaluateState:[],secondaryAttackAmount:0,seriesVictory:0,maxSeriesVictory:0}];
                data.expOrb = data.expOrb || [];
                data.talents = data.talents || [];
                data.items = data.items || [];
                data.herorecequips = data.herorecequips || [];
                data.heroEvaluates = data.heroEvaluates || [];
            }

            utils.invokeCallback(cb, err, data);
        });
    };
    //获取各区账号角色
    prop.getPlayers = function(params,cb){
        var accountId = params.accountId;
        var dao = orm.collections.user;
        var select  = ['_id','name','areaId','level','head','lastLoginTime'];
        dao.find({_id: accountId + '#1'}).select(select).sort({'lastLoginTime':'desc'}).exec(function (err, data) {
            var code = ec.OK;
            if(err){
                logger.warn('getPlayers err',err);
                code = ec.DB_Err;
            }
            cb(code,data);
        });
    };

    prop.findByNameAndAreaId = function (name, areaId, cb) {
        var dao = orm.collections.user;
        dao.find({name: name, areaId: areaId}).exec(function (err, data) {
            if (err) {
                cb(ec.DB_Err);
            } else if (data && !_.isEmpty(data)) {
                cb(ec.User.NameExist);
            } else {
                cb(ec.OK);
            }
        });
    };
    module.exports = new Mod();
})();

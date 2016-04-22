/**
 * Created by Administrator on 2015/1/15.
 */
var utils = require("./utils");
var dispatcher = require('./dispatcher');

var router = function(app){
    this.app = app;
    this.routers = {};
}

/**
 *
 * @param {obj}
 * @param {String}
 * @memberOf
 */
router.prototype.route = function(srvType, id, cb) {
    var self = this;
    var route = localLookup(this, srvType, id);
    if(route){
        utils.invokeCallback(cb, route);
        return;
    }

    var servers = this.app.getServersByType("locator");
    if (!servers || servers.length == 0) {
        utils.invokeCallback(cb, null);
        return;
    }

    var self = this;
    var locatorId = {};
    if (id != '*')
        locatorId= dispatcher.dispatch(id, servers).id;
    else
        locatorId = dispatcher.dispatch(self.app.getServerId(), servers).id;

    this.app.rpcStub.rpcInvoke(locatorId, "locatorRemote.getServerId", {typeId: srvType, id: id}, function(err, res){
        if(res.err){
            //todo log err;
            utils.invokeCallback(cb, null);
        }else{
            if (id != '*')
                localCache(self, srvType, id, res.sid);
            utils.invokeCallback(cb, res.sid);
        }
    });
};

router.prototype.routeMulti = function(srvType, ids, cb) {
    var self = this;
    //var route = localLookup(this, srvType, id);  //多个ids时，考虑如何本地备份
    //if(route){
    //    utils.invokeCallback(cb, route);
    //    return;
    //}

    var servers = this.app.getServersByType("locator");
    if (!servers || servers.length == 0) {
        utils.invokeCallback(cb, null);
        return;
    }

    var self = this;
    var locatorId = dispatcher.dispatch(self.app.getServerId(), servers).id;
    this.app.rpcStub.rpcInvoke(locatorId, "locatorRemote.getServerIds", {typeId: srvType, ids: ids}, function(err, res){
        if(res.err){
            //todo log err;
            utils.invokeCallback(cb, null);
        }else{
            //if (id != '*')
            //    localCache(self, srvType, id, res.sid);
            utils.invokeCallback(cb, res.sids);
        }
    });
};

/**
 *
 * @param {obj}
 * @param {String}
 * @memberOf
 */
var localLookup = function(mod, srvType, id){
    var srvRouter = mod.routers[srvType];
    if(srvRouter){
        var route = srvRouter[id];
        if(route){
            return route;
        }
    }

    return null;
}

/**
 *
 * @param {obj}
 * @param {String}
 * @memberOf
 */
var localCache = function(mod, srvType, id, sid){
    var lSrvRouter = mod.routers[srvType];
    if(!lSrvRouter){
        lSrvRouter = mod.routers[srvType] = {};
    }
    lSrvRouter[id] = sid;
}

module.exports = router;

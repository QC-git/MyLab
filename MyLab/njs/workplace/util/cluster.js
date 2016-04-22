var util = require('util');
var utils = require("./utils");
var dispatcher = require('./dispatcher');
var async = require('async');

var CACHE_OVERTIMER = 1000 * 60 * 10;  //10m
var KEEPLOCAL_TIMER = 1000 * 60 * 10;  //10m

var local_ary = [];

var Router = function (app) {
    this.app = app;
    this.routers = {};

    setInterval(clearOverData.bind(null, this), CACHE_OVERTIMER);
    setInterval(checkLocal.bind(null, this), KEEPLOCAL_TIMER);
}

var pro = Router.prototype;

/**
 *
 * @param {obj}
 * @param {String}
 * @memberOf
 */
pro.route = function (srvType, id, cb) {
    var self = this;
    var route = lookup(self, srvType, id);
    if (route) {
        utils.invokeCallback(cb, route);
        return;
    }

    var servers = self.app.getServersByType("locator");
    if (!servers || servers.length == 0) {
        utils.invokeCallback(cb, null);
        return;
    }

    var locatorId;
    if (id != '*')
        locatorId = dispatcher.dispatch(id, servers).id;
    else
        locatorId = dispatcher.dispatch(self.app.getServerId(), servers).id;

    //todo:后续id可能会支持其他类型
    if (!!id && typeof id === 'string') {
        this.app.rpcStub.rpcInvoke(locatorId, "locator.getServerId", {typeId: srvType, id: id}, function (err, res) {
            if (res.err) {
                //todo log err;
                utils.invokeCallback(cb, null);
            } else {
                cache(self, srvType, id, res.sid);
                utils.invokeCallback(cb, res.sid);
            }
        });
    } else {
        utils.invokeCallback(cb, null);
    }
};

pro.routeMulti = function (srvType, ids, cb) {
    var self = this;
    var servers = this.app.getServersByType("locator");
    if (!servers || servers.length == 0 || !util.isArray(ids)) {
        utils.invokeCallback(cb, null);
        return;
    }

    var routeInfo = [];
    var query = [];
    for (var i = 0; i < servers.length; ++i) {
        query.push([]);
    }

    for (var i = 0; i < ids.length; ++i) {
        var id = ids[i];
        if (!id) {
            continue;
        }
        var route = lookup(self, srvType, id);
        if (route) {
            var v = {};
            v.id = id;
            v.sid = route;
            routeInfo.push(v);
        } else {
            query[dispatcher.index(i, servers)].push(id);
        }
    }

    async.map(Object.keys(query), function (seq, next) {
        var _ids = query[seq];
        var locatorId = servers[seq].id;
        self.app.rpcStub.rpcInvoke(locatorId, "locator.getServerIds", {typeId: srvType, ids: _ids}, function (err, res) {
            if (res.err) {
                //todo log err;
                next(null, []);
            } else {
                var sids = res.sids;
                for (var i = 0; i < sids.length; ++i)
                    cache(self, srvType, sids[i].id, sids[i].sid);
                next(null, sids);
            }
        });
    }, function (err, res) {
        for (var i = 0; i < res.length; ++i) {
            routeInfo = routeInfo.concat(res[i]);
        }
        utils.invokeCallback(cb, routeInfo);
    });
};

var lookup = function (self, srvType, id) {
    if (id == '*')
        return null;

    var rt = self.routers[srvType];
    if (rt) {
        var v = rt[id];
        if (v)
            return v.sid;
    }
    return null;
}

var curTime = new Date().getTime();
setInterval(function () {
    curTime = new Date().getTime();
}, 10000);


var cache = function (self, srvType, id, sid) {
    if (id == '*')
        return;
    var rt = self.routers[srvType];
    if (!rt)
        rt = self.routers[srvType] = {};
    var v = rt[id] = {};
    v.sid = sid;
    v.time = curTime;
}

var clearOverData = function (self) {
    var router = self.routers;
    for (var i in router) {
        var v = router[i];
        if (curTime - v.time > CACHE_OVERTIMER) {
            delete router[i];
        }
    }
}

var checkLocal = function (self) {
    var add = [];
    var svrs = self.app.getServersByType('locator');
    for (var i = 0; i < svrs.length; ++i) {
        add.push([]);
    }
    for (var i = 0; i < local_ary.length; ++i) {
        var local = local_ary[i];
        for (var id in local)
            add[dispatcher.index(id, svrs)].push(id);
    }

    var msg = {};
    msg.typeId = self.app.getServerType();
    msg.sid = self.app.getServerId();

    for (var i = 0; i < add.length; ++i) {
        var lst = add[i];
        if (lst.length == 0)
            continue;
        else if (lst.length < 500) {
            msg.keep = lst;
            self.app.rpcStub.sendMsg(svrs[i].id, 'locator.updateLoader', msg);
        } else {
            var sp = 0;
            while (sp < lst.length) {
                msg.keep = lst.slice(sp, 500);
                self.app.rpcStub.sendMsg(svrs[i].id, 'locator.updateLoader', msg);
                sp += 500;
            }
        }
    }
}

module.exports.createClusterContainer = function () {
    var local = {};
    local_ary.push(local);
    return local;
}

var ins;
module.exports.getRouter = function (app) {
    if (!ins) {
        ins = new Router(app);
        var svrType = app.getServerType();
        var locators = app.getServersByType('locator');
        var svrId = app.getServerId();
        for (var i = 0; i < locators.length; ++i) {
            app.rpcStub.sendMsg(locators[i].id, 'locator.updateLoader', {typeId: svrType, sid: svrId});
        }
    }
    return ins;
}


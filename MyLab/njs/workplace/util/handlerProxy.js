(function () {
    'use strict';

    var utils = require('./utils'),
        ec = require('../shared/errorCode'),
        userMgr = require('../domain/userCenter'),
        userConst = require('../consts/userConst');

    exports.Create = function () {

        var Handler = function (app, handler) {
            this.app = app;
            initHandler(handler)
        };

        var genHandlerFunc = function (methodName, handler) {
            return function (msg, session, next) {
                var app = this.app;
                var sesuid = utils.newSesuid(session.uid, session.id);
                userMgr.getModule(app, sesuid, userConst.moduleName.info, function (err, user) {
                    if (err) {
                        next(null, {
                            code: ec.User.Not_Exist
                        });
                        return;
                    }
                    var innerFunc = handler[methodName];
                    try {
                        if (innerFunc.length === 4) {
                            innerFunc(user, msg, app, next);
                        } else {
                            var res = innerFunc(user, msg, app);
                            next(null, {
                                code: ec.OK,
                                data: res
                            });
                        }
                    } catch (e) {
                        exports.catchException(e, next);
                    }
                });
            };
        };

        var initHandler = function (handler) {
            for (var methodName in handler) {
                if (handler.hasOwnProperty(methodName) && typeof handler[methodName] === 'function') {
                    Handler.prototype[methodName] = genHandlerFunc(methodName, handler)
                }
            }
        };

        return Handler;
    };

    exports.catchException = function (e, next) {
        logger.warn(e.stack);
        var message = e.message;
        var code = parseInt(message) || ec.FAIL;
        var res = {
            code: code
        };
        if (ec.FAIL === code) {
            res.data = message;
        }
        next(null, res);
    }

    /**
     * 调用方法并捕获异常
     * @param thisObj
     * @param methodName
     * @param params
     * @param next
     */
    exports.invokeSafe = function (thisObj, methodName, params, next) {
        var res;
        try {
            if (!_.isArray(params)) {
                params = [params];
            }
            //thisObj[func].bind(thisObj)
            res = thisObj[methodName].apply(thisObj, params);
        } catch (e) {
            exports.catchException(e, next);
            return;
        }
        if ('function' === typeof params.pop()) {
            return;
        }
        if ('function' === typeof next) {
            next(null, {code: ec.OK, data: res});
        }
    }

})();
var route = module.exports;
require('./global');
var ec = depInj('ec');

route.Connector = function(frontendId, msg, app, cb) {
	if(!frontendId) {
		cb(new Error('frontend error'));
		return;
	}

	cb(null, frontendId);
};

route.userCenter = function(session, msg, app, cb) {
    if ( "string" === session ) {
        cb(null, session);
        return;
    }
    //todo 在handle层加权限验证 暂时兼容uid为空时路由到userCenter的问题 by feitianbubu 2015年12月25日 13:51:41
    if(!session.uid){
        logger.warn('session.uid is null sessionId=',session.id);

        //todo 下面代码为了兼容性暂时保存,下版本需要去掉 by feitianbubu 2016年1月6日 17:32:55
        //cb(ec.Unauthorized);
        //return;
        session.uid = session.get('accountId');
    }
    app.router.route("userCenter", session.uid, function(sid) {
        cb(null, sid);
    });
};

route.room = function(session, msg, app, cb) {
	if ( "string" === session ) {
		cb(null, session);
		return;
	}

	var sid = session.get("roomSid");
	if ( undefined != sid ) {
		cb(null, sid);
		return;
	}

	console.log("[=================WARN=================] no found room sid from session");
	cb(null, "room-server-1");
};

route.chat = function(session, msg, app, cb) {
    if ( "string" === session ) {
        cb(null, session);
        return;
    }

    app.router.route("chat", session.uid, function(sid) {   //todo: chat临时先用uid路由，到时候兴敏修改chat服务器时，一并修改
        cb(null, sid);
    });
};

route.friend = function(session, msg, app, cb) {
    if ( "string" === session ) {
        cb(null, session);
        return;
    }

    app.router.route("friend", session.uid, function(sid) {
        cb(null, sid);
    });
};

route.task = function(session, msg, app, cb) {
    if ( "string" === session ) {
        cb(null, session);
        return;
    }

    app.router.route("task", session.uid, function(sid) {
        cb(null, sid);
    });
};

var uuid = require('node-uuid');
var ObjectId = require('../dao/mongoose').mongoose.Types.ObjectId;
var underscore = require('underscore');
var utils = module.exports;

// control variable of func "myPrint"
var isPrintFlag = false;
// var isPrintFlag = true;

/**
 * Check and invoke callback function
 */
utils.invokeCallback = function(cb) {
  if(!!cb && typeof cb === 'function') {
    cb.apply(null, Array.prototype.slice.call(arguments, 1));
  }
};

/**
 * clone an object
 */
utils.clone = function(origin) {
  if(!origin) {
    return;
  }

  var obj = {};
  for(var f in origin) {
    if(origin.hasOwnProperty(f)) {
      obj[f] = origin[f];
    }
  }
  return obj;
};

utils.size = function(obj) {
  if(!obj) {
    return 0;
  }

  var size = 0;
  for(var f in obj) {
    if(obj.hasOwnProperty(f)) {
      size++;
    }
  }

  return size;
};

// print the file name and the line number ~ begin
function getStack(){
  var orig = Error.prepareStackTrace;
  Error.prepareStackTrace = function(_, stack) {
    return stack;
  };
  var err = new Error();
  Error.captureStackTrace(err, arguments.callee);
  var stack = err.stack;
  Error.prepareStackTrace = orig;
  return stack;
}

function getFileName(stack) {
  return stack[1].getFileName();
}

function getLineNumber(stack){
  return stack[1].getLineNumber();
}

utils.myPrint = function() {
  if (isPrintFlag) {
    var len = arguments.length;
    if(len <= 0) {
      return;
    }
    var stack = getStack();
    var aimStr = '\'' + getFileName(stack) + '\' @' + getLineNumber(stack) + ' :\n';
    for(var i = 0; i < len; ++i) {
      aimStr += arguments[i] + ' ';
    }
    console.log('\n' + aimStr);
  }
};
// print the file name and the line number ~ end

utils.GenUuid = function(){
    return uuid.v1();
};

utils.isEmptyObj = function(obj) {
    for(var o in obj) {
        return false;
    }

    return true;
};

utils.getCurTime = function() {
    var nowTime = new Date();
    return nowTime.getTime();
};


utils.newOId = function(){
    var id = new ObjectId();
    return id.toString();
};

utils.newSesuid = function(uid, sessionId) {
    return uid + '@' + sessionId;
};

utils.resolveSesuid = function(sesuid) {
    var ret = sesuid.split('@');
    if (ret.length != 2) {
        return {uid: ret[0], sessionId: 0}
    }

    return {uid: ret[0], sessionId: ret[1]};
};
utils.resolveUid = function(uid) {
    var ret = uid.split('#');
    if (ret.length != 2) {
        return {accountId: ret[0], areaId: 0}
    }

    return {accountId: ret[0], areaId: ret[1]};
};

utils.extend = function(d, s) {
    if (!s) {
        return d;
    }

    for (var p in s) {
        d[p] = s[p];
    }

    return d;
};

utils.deepExtend = function (d, s) {
  var res;
  if (underscore.isArray(s)) {
    res = [];
    for (var i = 0; i < s.length(); i++) {
      res.push(utils.deepExtend(d[i], s[i]));
    }
  } else if (underscore.isObject(s)) {
    res = {};
    for (var name in s) {
      if (s.hasOwnPropery(name)) {
        res[name] = utils.deepExtend(d[name], s[name]);
      }
    }
  } else {
    res = s;
  }

  return res;
};

utils.getSecond = function (millionSecond) {
    return Math.floor(millionSecond / 1000);
};

//转换data为client兼容格式
var convertData2Client = function (data) {
    if(_.isString(data) || _.isNumber(data)){
        return data;
    }
    if (_.isNull(data) || _.isUndefined(data)) {
        return 0;
    }
    if ('ObjectID' === data.constructor.name) {
        return data;
    }

    if (_.isArray(data) || 'MongooseDocumentArray' === data.constructor.name) {
        var resArray = [];
        _.each(data,function (v) {
            resArray.push(convertData2Client(v));
        });
        return resArray;
    }
    if (_.isObject(data)) {
        //如果是model则取_doc
        data = data._doc || data;
        var res = _.mapObject(data, function (val) {
            return convertData2Client(val);
        });
        return res;
    }
    return data;
}

utils.convertData2Client = function (data) {
    return convertData2Client(data);
};

/*
 * Date format
 */
utils.format = function(date, format) {
    format = format || 'MMddhhmm';
    var o = {
        "M+": date.getMonth() + 1, //month
        "d+": date.getDate(), //day
        "h+": date.getHours(), //hour
        "m+": date.getMinutes(), //minute
        "s+": date.getSeconds(), //second
        "q+": Math.floor((date.getMonth() + 3) / 3), //quarter
        "S": date.getMilliseconds() //millisecond
    };

    if (/(y+)/.test(format)) {
        format = format.replace(RegExp.$1, (date.getFullYear() + "").substr(4 - RegExp.$1.length));
    }

    for (var k in o) {
        if (new RegExp("(" + k + ")").test(format)) {
            format = format.replace(RegExp.$1, RegExp.$1.length === 1 ? o[k] :
                ("00" + o[k]).substr(("" + o[k]).length));
        }
    }
    return format;
};

/**
 * 备份日志
 */
utils.bakLogs = function (dirname,logsName) {
    var fs = require('fs');
    var path = require('path');
    var logsPath = path.join(dirname, logsName);
    var logsExist = fs.existsSync(logsPath);
    if (logsExist) {
        var bakPath = path.join(dirname, logsName + '_bak');
        var dateTime = utils.format(new Date(),'yyyyMMddhhmmss');
        var bakTimePath = path.join(bakPath, logsName + '_' + dateTime);
        try {
            var bakExist = fs.existsSync(bakPath);
            if (!bakExist) {
                fs.mkdirSync(bakPath);
            }
            fs.renameSync(logsPath, bakTimePath);
            fs.mkdirSync(logsPath);
        } catch (e) {
            if (e && e.errno !== 50) {
                console.warn(logsName + ' bak error', e);
            }
        }
    }
};

utils.encryptPwd = function (pwd) {
    var salt = 'skynono15980702203';
    var res = utils.md5(pwd+salt);
    return res;
}

utils.md5 = function (str) {
    var crypto = require('crypto');
    return crypto.createHash('md5').update(str).digest('hex');
}


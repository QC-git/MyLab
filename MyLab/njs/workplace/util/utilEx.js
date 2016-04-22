
var loadSchemeByKey = function(Mod, key, isCreate, cb) {
    if ( !cb && "function" === typeof isCreate ) {
        cb = isCreate;
        isCreate = true;
    }
    Mod.findById(key, function(err, scheme) {
        if (err) {
            cb(err);
        } else if (!scheme) {
            if (!isCreate) {
                cb(new Error("loadSchemeById fail, no scheme"));
            }else {
                //console.log("loadSchemeById, new Mod", id);
                var mod = new Mod({_id: key});
                mod.save(function(err, scheme) {
                    if ( err || !scheme ) {
                        cb(new Error("loadSchemeById fail, new Mod, err:" + err ));
                    }else {
                        cb(null, scheme);
                    }
                })
            }
        } else {
            cb(null, scheme);
        }
    })
};

var loadSchemeByAttr = function(Mod, attr, isCreate, cb) {
    if ( !cb && "function" === typeof isCreate ) {
        cb = isCreate;
        isCreate = true;
    }

    Mod.findOne(attr, function(err, scheme) {
        if (err) {
            cb(err);
        } else if (!scheme) {
            if (!isCreate) {
                cb(new Error("loadSchemeByType fail, no scheme"));
            }else {
                console.log("loadSchemeByType, new Mod", attr);
                var mod = new Mod(attr);
                mod.save(function(err, scheme) {
                    if ( err || !scheme ) {
                        cb(new Error("loadSchemeByType fail, new Mod, err:" + err ));
                    }else {
                        cb(null, scheme);
                    }
                })
            }
        } else {
            cb(null, scheme);
        }
    })
};

var loadSchemeList = function(Mod, params, cb) {
    var find = params.find || {};
    var condition = params.condition || {};
    var limit = params.limit || 0;
    var sort = params.sort || {};

    var query = Mod.find(condition, find);
    if ( limit || limit > 0 ) {
        query.limit(limit);
    }
    query.sort(sort);
    query.exec(cb);
};

function doRepeat(num, fn, cb) {
    for (var i= 0; i<num; i++) {
        if ( fn(i)) {
            break;
        }
    }
    if ( "function" == typeof cb ) {
        cb();
    }
}

function doEach(vec, fn, cb) {
    for (var i= 0; i<vec.length; i++) {
        if ( fn(i, vec[i]) ) {
            break;
        }
    }
    if ( "function" == typeof cb ) {
        cb();
    }
}

function doEachEx(obj, fn, cb) {
    for (var key in obj) {
        if ( fn(key, obj[key]) ) {
            break;
        }
    }
    if ( "function" == typeof cb ) {
        cb();
    }
}

function doParallel(vec, fn, cb) {
    var tol = vec.length;
    if ( tol == 0 ) {
        cb(null);
        return;
    }

    var cnt = 0;
    var suc = 0;
    for (var i= 0; i<vec.length; i++) {
        fn(i, vec[i], function(err) {
            cnt++;
            if (!err) {
                suc++;
            }
            if ( cnt === tol ) {
                if ( suc === tol ) {
                    cb(null);
                }else {
                    cb(new Error("doParallel, no all suc"));
                }
            }
        });
    }
}

function doParallelEx(obj, fn, cb) {
    var vec = [];
    for (var key in obj) {
        vec.push(obj[key]);
    }
    doParallel(vec, fn, cb);
}

function doEachEx2(obj, fn, cb) {
    cb = cb || function() {};
    for (var key in obj) {
        var obj2 = obj[key];
        for (var key2 in obj2 ) {
            if ( fn(key, key2, obj2[key2]) ) {
                cb();
                return;
            }
        }
    }
    cb();
}

function objectSize(obj) {
    var cnt = 0;
    for (var key in obj) {
        cnt++;
    }
    return cnt;
}

function randObjectKey(obj) {
    for (var key in obj) {
        return key;
    }
}

function randObject(obj) {
    for (var key in obj) {
        return obj[key];
    }
}

function minValue(a, b) {
    if ( a <= b ) {
        return a;
    }
    return b;
}

function minValueEx(a, b, ignore) {
    if ( b == ignore ) {
        return a;
    }
    return minValue(a, b);
}

function maxValue(a, b) {
    if ( a >= b ) {
        return a;
    }
    return b;
}

function cloneAll(obj) {
    var sink = {};
    if (obj instanceof Array) {
        sink = [];
    }
    for ( var key in obj ) {
        var val = obj[key];
        sink[key] = ( "object" === typeof val || val instanceof Array ) ? arguments.callee(val) : val;
    }
    return sink;
}

function cloneByAttr(obj, attr) {  // mongoose 测试
    var sink = {};
    for ( var key in attr ) {
        sink[key] = obj[key];
    }
    return sink;
}

function cloneForResetKey(pre, suf, obj) {
    var tmp;
    var sink = {};
    for ( var key in obj ) {
        tmp = pre + key + suf;
        sink[tmp] = obj[key];
    }
    return sink;
}

function ListKeyHelper(listName, listCount) {
    this.listName = listName;
    this.listCount = listCount;
}

ListKeyHelper.prototype.checkPos = function(pos) {
    return pos >= 1 && pos <= this.listCount;
};

ListKeyHelper.prototype.getKey = function(pos) {
    return this.listName + pos.toString();
};

ListKeyHelper.prototype.setValue = function(obj, pos, value) {
    if ( !this.checkPos(pos) ) {
        return false;
    }
    var key = this.getKey(pos);
    obj[key] = value;
    return true;
};

ListKeyHelper.prototype.getValue = function(obj, pos) {
    if ( !this.checkPos(pos) ) {
        return null;
    }
    var key = this.getKey(pos);
    return obj[key];
};

ListKeyHelper.prototype.getPos = function(obj, value) {
    if ( this.listCount < 1 ) {
        return;
    }
    var self = this;
    var pos  = 0;
    var key;
    doRepeat(self.listCount, function(i) {
        i++;
        key = self.getKey(i);
        if ( value == obj[key] ) {
            pos = i;
            return true;
        } //console.log(i);
    });
    return pos;
};

ListKeyHelper.prototype.getAllData = function(obj) {
    if ( this.listCount < 1 ) {
        return null;
    }
    var self = this;
    var sink = {};
    var key, value;
    doRepeat(self.listCount, function(i) {
        i++;
        key = self.getKey(i);
        value = obj[key];
        sink[key] = value;
    });
    return sink;
};

function ListHelper(list, keyName) {
    this.list = list;
    this.keyName = keyName;
    this.map = {};
    this.updateMap();
}

ListHelper.prototype.updateMap = function() {
    var self = this;
    var keyName = self.keyName;
    self.map = {};
    doEach(self.list, function(i, item) {
        var _key = item[keyName];
        self.map[_key] = item;
    })
};

ListHelper.prototype.updateMapByKey = function(key) {
    var self = this;
    var keyName = self.keyName;
    var sink = null;
    doEach(self.list, function(i, item) {
        var _key = item[keyName];
        if ( key == _key ) {
            sink = self.map[_key] = item;
            return true;
        }
    });
    return sink;
};

ListHelper.prototype.get = function(key) {
    return this.map[key];
};

ListHelper.prototype.getList = function() {
    return this.list;
};

ListHelper.prototype.getListEx = function(attrList) {
    var list = [];
    var self = this;
    doEach(self.list, function(i, item) {
        var sink = cloneByAttr(item, attrList);
        list.push(sink);
    });
    return list;
};

ListHelper.prototype.push = function(obj) {
    var key = obj[this.keyName];
    if (!key) {
        return false;
    }
    this.list.push(obj);
    this.map[key] = obj;
    return true;
};

ListHelper.prototype.pushKey = function(key, isReload) {
    var obj = {};
    obj[this.keyName] = key;
    this.list.push(obj);
    if (!isReload) {
        this.map[key] = obj;
    } else {
        obj = this.updateMapByKey(key);
    }

    return obj;
};

function MapQueue(mark) {
    this.map = {};
    this.sn = 0;
    this.mark = mark;
    this.length = 0;
}

MapQueue.prototype.check = function(print) {  // 检测map中id是否按顺序排列且数量与已知长度一致
    var num = 0;
    var map = this.map;
    var limit = 0;
    var fail = false;
    for ( var key in map ) {
        var keyNum = parseInt(key);
        if ( isNaN(keyNum) && keyNum < limit ) {
            fail = true;
            break;
        }
        limit = keyNum;
        num++;
    }
    if ( print ) {
        console.log(map, !fail, num, this.length);
    }
    return !fail && num === this.length;
};

MapQueue.prototype.size = function() {
    return this.length;
};

MapQueue.prototype.push = function(value) {
    var _id = ++this.sn;
    var map = this.map;
    if ( map[_id] ) {
        return 0;
    }
    map[_id] = value;
    this.length++;
    if ( this.mark && typeof value === "object" ) {
        value._id = _id;
    }
    return _id;
};

MapQueue.prototype.insert = function(id, value) {
    if ( this.get(id) ) {
        return false;
    }
    this.map[id] = id;
    this.length++;
    if ( this.mark && typeof value === "object" ) {
        value._id = id;
    }
    return true;
};

MapQueue.prototype.pop = function() {
    var map = this.map;
    for ( var key in map ) {
        var item = map[key];
        delete map[key];
        this.length--;
        return item;
    }
};

MapQueue.prototype.popList = function(num) {
    var sink = [];
    var self = this;
    doRepeat(num, function(i) {
        var item = self.pop();
        if ( undefined !== item) {
            sink.push(item);
        }else {
            //console.log("@@@@@@@@@@@@@@@", item);
        }
    });
    return sink;
};

MapQueue.prototype.get = function(id) {
    return this.map[id];
};

MapQueue.prototype.remove = function(id) {
    if ( !this.get(id) ) {
        return false;
    }
    delete this.map[id];
    this.length--;
    return true;
};

MapQueue.test = function() {

    var self =  new MapQueue(true);
    var ret;

    ret = self.pop();  console.log(ret);
    ret = self.popList(3);  console.log(ret);

    doRepeat(100, function(i) {
        self.push(i+1);
    });

    ret = self.pop();  console.log(ret);
    ret = self.pop();  console.log(ret);
    ret = self.pop();  console.log(ret);
    ret = self.popList(3);  console.log(ret);

    ret = self.remove(7);  console.log(ret);
    ret = self.remove(9);  console.log(ret);
    ret = self.remove(11);  console.log(ret);
    ret = self.remove(33);  console.log(ret);
    ret = self.remove(55);  console.log(ret);
    ret = self.remove(77);  console.log(ret);
    ret = self.remove(99);  console.log(ret);

    ret = self.insert(1, 1);  console.log(ret);
    ret = self.insert(5, 5);  console.log(ret);
    ret = self.insert(9, 9);  console.log(ret);
    ret = self.insert(33, 33);  console.log(ret);
    ret = self.insert(77, 77);  console.log(ret);

    ret = self.check(true); console.log(ret);
};

function MatchQueue() {
    this._nodeMap = {};
    this._sn = 0;
    this._nodeNum = 0;
    this._nodeSize = 0;
}

MatchQueue.prototype.check = function(print) {  // 检测map中id是否按顺序排列且数量与已知长度一致
    var nodeNum = 0;
    var nodeSize = 0;
    var limit = 0;
    var fail = false;
    doEachEx(this._nodeMap, function(key, node) {
        var keyNum = parseInt(key);
        if ( isNaN(keyNum) && keyNum < limit ) {
            fail = true;
            return true;
        }
        limit = keyNum;
        nodeNum++;
        nodeSize += node.getSize();
    });
    var suc = !fail && this._nodeNum === nodeNum && this._nodeSize == nodeSize;
    if ( !suc && print ) {
        console.log(this._nodeMap, this._nodeNum, this._nodeSize, !fail, nodeNum, nodeSize);
    }
    return suc;
};

MatchQueue.prototype.getNodeNum = function() {
    return this._nodeNum;
};

MatchQueue.prototype.getUserNum = function() {
    return this._nodeSize;
};

MatchQueue.prototype.pushList = function(userList) {
    if ( !userList || 0 == userList.length ) {
        return null;
    }
    var newId = ++this._sn;
    if ( 0 == newId ) {
        return null;
    }
    var node = new MatchNode(newId, userList);
    if ( !this.pushNode(node) ) {
        return null
    }
    node.time = new Date().getTime();
    return node;
};

MatchQueue.prototype.pushNode = function(node) {
    var nodeId = node.getId();
    if ( this._nodeMap[nodeId] ) {
        return false;
    }
    this._nodeMap[nodeId] = node;
    this._nodeSize += node.getSize();
    this._nodeNum++;
    return true;
};

MatchQueue.prototype.pushNodeList = function(nodeList, ignoreId) {
    if ( !nodeList ) {
        return;
    }
    var self = this;
    doEach(nodeList, function(i, node) {
        if ( node.getId() == ignoreId ) {
            return;
        }
        self.pushNode(node);
    })
};

MatchQueue.prototype.removeNode = function(node) {
    var nodeId = node.getId();
    if ( !this._nodeMap[nodeId] ) {
        return false;
    }
    delete this._nodeMap[nodeId];
    this._nodeSize -= node.getSize();
    this._nodeNum--;
    return true;
};

MatchQueue.prototype.removeNodeList = function(nodeList) {
    var self = this;
    doEach(nodeList, function(i, node) {
        self.removeNode(node);
    })
};

MatchQueue.prototype.selectNodeList = function(num, check) {
    if ( num <= 0 ) {
        return null;
    }
    var nodeList = [];
    var selectNum = 0;
    doEachEx(this._nodeMap, function(key, node) {
        var nodeSize = node.getSize();
        if ( selectNum + nodeSize <= num ) {
            selectNum += nodeSize;
            nodeList.push(node);
        }
        if ( selectNum == num ) {
            return true;
        }
    });
    if ( check && selectNum != num ) {
        return null;
    }
    return nodeList;
};

MatchQueue.prototype.popNodeList = function(num, check) {
    if ( 0 == num ) {
        return [];
    }
    var nodeList = this.selectNodeList(num, check);
    if ( nodeList ) {
        this.removeNodeList(nodeList);
    }
    return nodeList;
};

MatchQueue.prototype.each = function(fn) {
    doEachEx(this._nodeMap, function(key, node) {
        return fn(node);
    });
};

function MatchNode(id, userList) {
    this._id = id;
    this._userList = userList;
}
MatchNode.prototype.getId = function() {
    return this._id;
};

MatchNode.prototype.getSize = function() {
    return this._userList.length;
};

MatchNode.prototype.each = function(fn) {
    doEach(this._userList, function(i, user) {
        fn(user);
    })
};

MatchNode.prototype.visit = function(list) {
    this.each(function(user) {
        list.push(user);
    })
};

MatchNode.prototype.getUserList = function() {
    return this._userList;
};

function PosManager(limit) {
    this.limit = limit;
    this.list = [];
    this.flagList = [];

    var self = this;
    doRepeat(limit, function(i) {
        self.flagList[i] = 0;
    })
}

PosManager.prototype.getList = function() {
    return this.list;
};

PosManager.prototype.getPosFlagList = function() {
    return this.flagList;
};

PosManager.prototype.getPosFlag = function(pos) {
    return this.flagList[pos];
};

PosManager.prototype.getPosFlagNum = function(flag) {
    var num = 0;
    doEach(this.flagList, function(i, item) {
        if ( flag === item ) {
            num++;
        }
    });
    return num;
};

PosManager.prototype.getData = function(pos) {
    if ( !this._safePos(pos) ) {
        return null;
    }

    return this.list[pos];
};

PosManager.prototype.havePos = function() {
    return !!this.getFreeNum();
};

PosManager.prototype.isFree = function(pos) {
    return this._safePos(pos) &&  !this.list[pos] && !this.isLock(pos);
};

PosManager.prototype.getFreeNum = function() {
    var num = 0;
    var self = this;
    doRepeat(this.limit, function(i) {
        var obj = self.list[i];
        var lock = self.flagList[i];
        if ( !obj && !lock ) {
            num++;
        }
    });
    return num;
};

PosManager.prototype.getFreePos = function() {
    return this._getFreePos();
};

PosManager.prototype.lock = function(pos, flag) {
    if ( !this._safePos(pos) ) {
        return false;
    }
    if (flag) {
        if ( this.list[pos] ) {
            return false; // 这个位置已经有人， 不能再锁住
        }
    }
    this.flagList[pos] = flag;  // 1是锁， 2是其它
    return true;
};

PosManager.prototype.isLock = function(pos) {
    return this.flagList[pos];
};

PosManager.prototype.push = function(id) {
    if ( this._isDup(id) ) {
        return -1;
    }

    var pos = this._getFreePos();
    if ( pos < 0 ) {
        return -1;
    }
    this.list[pos] = id;
    return pos;
};

PosManager.prototype.set = function(id, pos) {
    if ( this._isDup(id) ) {
        return false;
    }

    if ( !this._safePos(pos) ) {
        return false;
    }

    if ( this.isLock(pos) ) {
        return false;
    }

    this.list[pos] = id;
    return true;
};

PosManager.prototype.clear = function(pos) {
    if ( !this._safePos(pos) ) {
        return false;
    }
    this.list[pos] = null;
    return true;
};

PosManager.prototype._safePos = function(pos) {
    if ( isNaN(pos) || pos < 0 || pos >= this.limit ) {
        return false;
    }
    return true;
};

PosManager.prototype._haveData = function(pos) {
    return !!this.list[pos];
};

PosManager.prototype._isDup = function(id) {
    if ( !id ) {
        return false;
    }
    var dup = false;
    var self = this;
    doRepeat(this.limit, function(i) {
        var item = self.list[i];
        if ( item == id ) {
            dup = true;  // 数据重复了
            return true;
        }
    });
    return dup;
};

PosManager.prototype._getFreePos = function() {
    var pos = -1;
    var self = this;
    doRepeat(this.limit, function(i) {
        var obj = self.list[i];
        var lock = self.flagList[i];
        if ( !obj && !lock ) {
            //self.nextFreePos = i+1;
            pos = i;
            return true;
        }
    });
    return pos;
};

function Box(createFn) {
    this._sands = {};
    this._createFn = createFn;
}

Box.prototype.enter = function(key, info) {
    if (!key) {
        return errorFn("Box.prototype.enter, no key", null);
    }

    if ( this._sands[key] ) {
        return errorFn("Box.prototype.enter, key dup", null);
    }

    var sand = this._createFn(key, info);
    this._sands[key] = sand;
    if ( sand.onEnter ) {
        sand.onEnter(info);
    }

    return sand;
};

Box.prototype.leave = function(key, info) {
    if (!key) {
        return errorFn("Box.prototype.leave, no key", false);
    }

    var sand = this._sands[key];
    if (!sand) {
        return errorFn("Box.prototype.leave, no found sand", false);
    }

    if ( sand.onLeave ) {
        sand.onLeave(info);
    }
    delete this._sands[key];

    return true;
};

Box.prototype.get = function(key) {
    return this._sands[key];
};

Box.prototype.each = function(fn) {
    doEachEx(this._sands, function(key, sand) {
        return fn(sand);
    })
};

Box.prototype.sandNum = function() {
    var num = 0;
    this.each(function(sand) {
        num++;
    });
    return num;
};

function BoxEx() {
    this._map = {};
    this._num = 0;
}

BoxEx.prototype.get = function(key) {
    return this._map[key];
};

BoxEx.prototype.getInfo = function(key) {
    var user = this.get(key);
    if (user) {
        return user._info;
    }
};

BoxEx.prototype.getTime = function(key) {
    var user = this.get(key);
    if (user) {
        return user._time;
    }
};

BoxEx.prototype.getSize = function() {
    return this._num;
};

BoxEx.prototype.insert = function(key, info, check) {
    if (!key) {
        return;
    }

    if ( check && this.get(key) ) {
        return;
    }

    var data = this._map[key] = {};
    data._key = key;
    data._info = info;
    data._time = new Date().getTime();

    this._num++;

    return data;
};

BoxEx.prototype.drop = function(key) {
    if ( this.get(key) ) {
        this._num--;
    }

    delete this._map[key];
};

BoxEx.prototype.each = function(fn) {
    doEachEx(this._map, function(key, data) {
        return fn(key, data);
    })
};

Vote.NONE = 0;
Vote.AGREE = 1;
Vote.REFUSE = 2;

function Vote() {
    this.flagMap = {};
}

Vote.prototype.addUser = function(uid) {
    this.flagMap[uid] = Vote.NONE;
};

Vote.prototype.setFlag = function(uid, flag) {
    if ( isNaN(this.flagMap[uid]) ) {
        return false;
    }
    this.flagMap[uid] = flag ? Vote.AGREE : Vote.REFUSE;
    return true;
};

Vote.prototype.getFlags = function() {
    var sink = [];
    doEachEx(this.flagMap, function(key, flag) {
        var info = {};
        info.uid = key;
        info.flag = flag;
        sink.push(info);
    });
    return sink;
};

Vote.prototype.isAgree = function(uid) {
    var flag = this.flagMap[uid];
    return flag == Vote.AGREE;
};

Vote.prototype.isAllAgree = function() {
    var ret = true;
    doEachEx(this.flagMap, function(key, flag) {
        if ( flag != Vote.AGREE ) {
            ret = false;
            return true;
        }
    });
    return ret;
};

function Level(exp, lv, maxLevel, expMap) {
    this._exp = exp;
    this._lv = lv;
    this._init(expMap, maxLevel);
}

Level.prototype._init = function(expMap, maxLevel) {
    var totalExpMap = {};
    var total = 0;
    totalExpMap[0] = total;
    if ( !checkNumber(maxLevel) ) {
        maxLevel = 0;
    }
    doRepeat(maxLevel, function(i) {
        var lv = i + 1;
        var value = expMap[lv];
        if ( !checkNumber(value) || value < 0 ) {
            value = 0;
        }
        total += value;
        totalExpMap[lv] = total;
    });
    this._maxLevel = maxLevel;
    this._totalExpMap = totalExpMap;
};

Level.prototype._alignExpLevel = function(flag, fn) {  //是否可以连续升级
    var curLevel = this._lv;
    var curExp = this._exp;
    var oldLevel = curLevel;

    //console.log("Level.prototype._alignExpLevel, ", curLevel, curExp);

    var loop = 0;
    var maxLoop = 10;
    do {
        if (curLevel >= this._maxLevel) {
            break;
        }

        var nextLevel = curLevel + 1;
        var nextExp = this._totalExpMap[nextLevel];
        if (!nextExp || nextExp > curExp) {
            break;
        }

        if (fn) {
            fn(curLevel, nextLevel);
        }
        curLevel = nextLevel;
        //console.log("Level.prototype._alignExpLevel, ", curLevel, curExp);

        loop++;
        if (loop>=maxLoop) {  //做保护
            break;
        }

    }while(flag);

    if ( curLevel > oldLevel ) {
        this._lv = curLevel;
        return {"oldLevel": oldLevel, "level": curLevel};
    }
};

Level.prototype.getExp = function() {
    return this._exp;
};

Level.prototype.getLevel = function() {
    return this._lv;
};

Level.prototype.addExp = function(exp, fn) {  //成功升级返回true
    this._exp += exp;
    this._alignExpLevel(true, fn);
    return this._exp;
};

Level.prototype.addLevel = function() {
    return false
};

function getListItem(list, attrName, attrValue) {
    var data = null;
    doEach(list, function(i, item) {
        if ( attrValue == item[attrName] ) {
            data = item;
            return true;
        }
    });
    return data;
}

function mergeList(list1, list2) {
    var list = [];
    doEach(list1, function(i, item) {
        list.push(item);
    });
    doEach(list2, function(i, item) {
        list.push(item);
    });
    return list;
}

function getTime(now) {
    if ( "number" == typeof now ) {
        return now;
    }
    return new Date().getTime();
}

function getNumber(num) {
    if ( "number" == typeof num ) {
        return num;
    }
    return 0;
}

function getDelayTime(delay, now) {
    return getNumber(delay) + getTime(now);
}

function DelayTime(delay, now) {
    this.delay = getNumber(delay);
    this.last = getTime(now);
}

DelayTime.prototype.reset = function(now) {
    this.last = getTime(now);
};

DelayTime.prototype.isExpire = function(now) {
    if ( 0 ===  this.last ) {
        this.reset(now);
        return true;
    }

    var cur = getTime(now);
    var dif = cur - this.last;

    if ( dif < 0 ) {
        console.log("time is roll back");
        this.reset(now);
        return false;
    }

    if ( dif > this.delay ) {
        this.reset(now);
        return true;
    }

    return false;
};

function UpdateTime(params, last) {
    this._cycle = params.cycle || 1000;     // 禁止检测周期
    this._weekDay = params.weekDay || 0;    // 每周周几更新， 0是周天, -1是无效
    this._hour = params.hour || 0;          // 每天几时更新

    if ( "everyDay" == params.rule ) {
        this._cycle = 60 * 60 * 1000;
        this._weekDay = -1;
    } else if ( "everyWeek" == params.rule ) {
        this._cycle = 24 * 60 * 60 * 1000;
    }else {
        this._cycle = 60 * 60 * 1000;  // everyDay
        this._weekDay = -99;
    }

    last = last || 0;
    this._align(last);
    //this._debug("UpdateTime");
}

UpdateTime.prototype._debug = function(tag) {
    console.log("tag = " + tag + ", last date = " +  new Date(this._last) + ", next date = " + new Date(this._next) + ", data = ", this);
};

UpdateTime.prototype._align = function(curTime) {
    this._last = curTime;
    this._next = this._last + this._cycle;
};

UpdateTime.prototype.getLast = function() {
    return this._last;
};

UpdateTime.prototype.checkNext = function() {
    var curDate = new Date;
    var curTime = curDate.getTime();

    if ( 0 == this._last ) {
        this._align(curTime);
        return true;
    }

    if ( curTime < this._next ) {
        return false;
    }

    var curWeekDay = curDate.getDay();
    if ( this._weekDay > 0 && curWeekDay != this._weekDay ) {
        return false;
    }
    var curHour = curDate.getHours();
    if ( curHour != this._hour ) {
        return false;
    }

    this._align(curTime);
    return true;
};

function getRemainTime(lastTime, costTime) {
    var curDate = new Date;
    var curTime = curDate.getTime();
    var difTime = curTime - lastTime;
    if ( difTime <= 0 ) {
        return costTime;
    }
    if ( difTime >= costTime ) {
        return 0;
    }
    return costTime - difTime;
}

function checkNumber(data) {
    return "number" == typeof data;
}

function checkString(data) {
    return "string" == typeof data;
}

function checkObject(data) {
    return "object" == typeof data;
}


function loadValue(sink, src, attr, cb) {
    var value = src[attr];
    if ( "undefined" == typeof value ) {
        cb(new Error("no " + attr));
        return false;
    }
    sink[attr] = value;
    return true;
}

var rpcServer = function(app, uid, type, route, msg, cb) {
    if(!app.router){
        cb(ec.Service_Unavailable);
        return;
    }
    app.router.route(type, uid, function(sid) {
        if (!sid) {
            cb(new Error("no found sid"));
            return;
        }
        app.rpcStub.rpcInvoke(sid, route, msg, cb);
    })
};

var createCallBack = function(msg, next, log) {
    return function(code, info) {
        if (!info) {
            info = {};
        }
        info.code = code;
        if (!info.msg) {
            info.msg = msg;
        }
        if ( log && code ) {
            log(code);
        }
        next(null, info);
    }
};

var gThrowEnable = false;

var errorFn = function(err, ret, fn) {
    if ( "function" === ret ) {
        fn = ret;
        ret = undefined;
    }

    if (fn) {
        fn(new Error(err));
    }

    if (!gThrowEnable) {
        return ret;
    }

    throw {error: new Error(err)};
};

var gDebugEnable = true;
var gDebugList = [
    "",
    "DEBUG",
    "room",
    "room mgr",
    "room match",
    "Handler room",
    "Remote room",
    "Remote room msg",
    "Handler connector",
    "Handler team",
    "Remote team",
    "Handler userInfo"
];
function Debugger(name) {
    this.enable = gDebugEnable;
    this.name = name;
}

Debugger.prototype.enabled = function () {
    var self = this;
    if (!self.enable) {
        return false;
    }

    var find = false;
    doEach(gDebugList, function(i, item) {
        if ( item === self.name ) {
            find = true;
            return true;
        }
    });

    return find;
};

Debugger.prototype.log = function() {
    var self = this;
    if ( !self.enabled() ) {
        return;
    }
    var vec = Array.prototype.slice.call(arguments, 0);
    if ( self.name ) {
        var name = "["+self.name+"]";
        vec.splice(0, 0, name);
    }
    console.log.apply(null, vec);
    //var str = JSON.stringify(vec);
    //console.log(str);
};

var tag = function(name) {
    return new Debugger(name);
};

var log = function() {
    var vec = Array.prototype.slice.call(arguments, 0);
    vec.splice(0, 0, "[LOG]");
    console.log.apply(null, vec);
    //var str = JSON.stringify(vec);
    //console.log(str);
};

var notifyClient = function(app, userList, msgName, msg, cb) {
    cb = cb || function(){
        };
    var users = [];
    doEach(userList, function(i, userInfo) {
        users.push({sid: userInfo.connSid, sessionId: userInfo.sessionId});
    });
    if ( 0 == users.length ) {
        return;
    }
    var channelService = app.get('channelService');
    channelService.pushMessageBySessionId(msgName, msg, users, function(err) {
        if (err) {
            cb(new Error("ConfirmNode.prototype.notifyClient, pushMessageBySessionId fail, err = " + err));
        }
    });
};

var notifyCenter = function(app, userList, msgName, msg, cb) {
    cb = cb || function() {};
    msg = msg || {};
    doParallel(userList, function(i, user, fn) {
        var notifyMsg = {};
        notifyMsg.uid = user.uid;
        notifyMsg.sessionId = user.sessionId;
        notifyMsg.data = msg;
        app.rpcStub.sendMsg(user.userSid, msgName, notifyMsg);
        fn(null);
    }, function() {
        cb(null);
    });
};

module.exports = {
    loadSchemeByKey: loadSchemeByKey,
    loadSchemeByAttr: loadSchemeByAttr,
    loadSchemeList: loadSchemeList,

    doRepeat: doRepeat,
    doEach: doEach,
    doEachEx: doEachEx,
    doEachEx2: doEachEx2,
    doParallel: doParallel,
    doParallelEx: doParallelEx,
    objectSize: objectSize,
    randObjectKey: randObjectKey,
    randObject: randObject,
    minValue: minValue,
    maxValue: maxValue,
    minValueEx: minValueEx,

    cloneAll: cloneAll,
    cloneByAttr: cloneByAttr,
    cloneForResetKey: cloneForResetKey,

    ListKeyHelper: ListKeyHelper,
    ListHelper: ListHelper,
    MapQueue: MapQueue,
    MatchQueue: MatchQueue,
    MatchNode: MatchNode,
    PosManager: PosManager,
    Box: Box,
    BoxEx: BoxEx,
    Vote: Vote,
    Level: Level,

    getListItem: getListItem,
    mergeList: mergeList,

    getTime: getTime,
    getDelayTime: getDelayTime,
    DelayTime: DelayTime,
    UpdateTime: UpdateTime,

    getRemainTime: getRemainTime,

    checkNumber: checkNumber,
    checkString: checkString,
    checkObject: checkObject,

    rpcServer: rpcServer,

    createCallBack: createCallBack,
    errorFn: errorFn,

    tag: tag,
    log: log,

    notifyClient: notifyClient,
    notifyCenter: notifyCenter

};
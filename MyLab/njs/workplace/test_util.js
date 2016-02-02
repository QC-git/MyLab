

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

function CycleTime(cycle, start) {
    this.cycle = getNumber(cycle);
    if ( this.cycle < 5000 ) {  //����ʱ�䣬 ��СΪ5��
        this.cycle = 5000;
    }

    this.start = getNumber(start);
    if ( 0 == this.start ) {
        this.start = getTime();
    }

    this.last  = 0;
    this.next = this.start;
}

CycleTime.prototype.getNextTime = function() {
    return this.next;
};

CycleTime.prototype.checkUpdate = function() {
    var cur =  getTime();
    if ( cur > this.next  ) {
        this.last = cur;
        this.resetNextTime();
        return true;
    }

    return false;
};

CycleTime.prototype.resetNextTime = function() {
    var cycle = this.cycle;
    var last  = this.last;

    this.next = this.next + cycle;  // ��ǰʱ�������������Զִ�в���

    if ( last >= this.next ) {  //���ɴ�ʱ��
        var multi = (last- this.next) / cycle;
        multi = parseInt(multi) + 1;
        this.next = this.next + cycle * multi;

        var dif = this.next - last;
        console.log("CycleTime exception,  next update will no attach, so adjust the dif = " + dif);
    }

};

function UpdateTime(params, last) {
    this._cycle = params.cycle || 1000;    // 禁止检测周期
    this._weekDay = params.weekDay || -1;  // 每周周几更新， 0是周天, -1是无效
    this._hour = params.hour || 0;         // 每天几时更新
    last = last || 0;
    this._align(last);
    this._debug("UpdateTime");
}

UpdateTime.prototype._debug = function(tag) {
    console.log("tag = " + tag + ", last date = " +  new Date(this._last) + ", next date = " + new Date(this._next) + ", data = ", this);
};

UpdateTime.prototype._align = function(curTime) {
    this._last = curTime;
    this._next = this._last + this._cycle;
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

var CYCLE_DAY  = 86400000;  // 24 * 3600 * 1000
var CYCLE_WEEK = 604800000; // CYCLE_DAY * 7

function UpdateWeek(updateDay) {
    updateDay = getNumber(updateDay);
    if ( updateDay < 1 || updateDay > 7 ) {
        updateDay = 1;
    }
    this.updateDay = updateDay;

    var date = new Date();
    var day  = date.getDay() || 7;
    var difDay = updateDay - day;
    if ( difDay < 0 ) {  // ��ȥ�ļ���
        difDay += 7;
    }

    var start = date.getTime();
    start += difDay * CYCLE_DAY;
    this.updateTime = new CycleTime(CYCLE_WEEK, start);
}

UpdateWeek.prototype.getNextTime = function() {
    return this.updateTime.getNextTime();
};

UpdateWeek.prototype.checkUpdate = function() {
    return this.updateTime.checkUpdate();
};

function getWeek(time) {
    var curTime, week, date = new Date(time);
    var weekDay = date.getDay() || 7;
    date.setDate( date.getDate() + 4 - weekDay );  //����ʵ�ʵ�ƫ��
    curTime = date.getTime();
    date.setMonth(0);
    date.setDate(1);
    week = Math.floor(Math.round((curTime - date) / CYCLE_WEEK )) + 1;
    return week;
}

function getWeekEx(time, startDay) {
    startDay = getNumber(startDay);
    if ( startDay < 1 || startDay > 7 ) {
        startDay = 1;
    }
    startDay -= 1;

    var curTime, week, date = new Date(time);

    var weekDay = date.getDay() || 7;
    weekDay -= startDay;
    if ( weekDay < 1 ) {
        weekDay += 7;
    }

    date.setDate(date.getDate() + 4 - weekDay );  //����ʵ�ʵ�ƫ��
    curTime = date.getTime();
    date.setMonth(0);
    date.setDate(1);
    week = Math.floor(Math.round((curTime - date.getTime()) / CYCLE_WEEK )) + 1;
    return week;
}

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

function doParallel(vec, fn, cb) {
    var tol = vec.length;
    var cnt = 0;
    var suc = 0;
    for (var i= 0; i<vec.length; i++) {
        fn(vec[i], function(err) {
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

ListKeyHelper.prototype.check = function(pos) {
    return pos >= 1 && pos <= this.listCount;
};

ListKeyHelper.prototype.getKey = function(pos) {
    return this.listName + pos.toString();
};

ListKeyHelper.prototype.setValue = function(obj, pos, value) {
    if ( !this.check(pos) ) {
        return false;
    }
    var key = this.getKey(pos);
    obj[key] = value;
    return true;
};

ListKeyHelper.prototype.getValue = function(obj, pos) {
    if ( !this.check(pos) ) {
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
        return;
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

function ListMap(attr) {  // 让list同时具有map的特性
    this.list = [];
    this.map = {};     // 保存list的下标
    this.attr = attr; // 当表示属性不存在时，可以认为list下直接存的是key
}

ListMap.prototype.key = function(item) {
    var key;
    if ( "undefined" === typeof this.attr ) {  // 当表示属性不存在时，可以认为list下直接存的是key
        key = item;
    } else {
        key = item[this.attr];
    }
    return key;
};

ListMap.prototype.get = function(key) {
    var mark = this.map[key];
    if ( isNaN(mark) ) {
        return;
    }
    return this.list[mark];
};

ListMap.prototype.insert = function(key, item, isHead) {
    var mark = this.map[key];
    if ( isNaN(mark) ) {  // 内存中不存在
        if (isHead) {
            this.list.unshift(item);
        }else {
            this.list.push(item);
        }
        this.map[key] = this.list.length - 1;
    } else {
        this.list[mark] = item;
    }
    return true;
};

ListMap.prototype.remove = function(item) {
    var key = this.key(item);
    if ( "undefined" === typeof key ) {
        return false;
    }
    return this.removeByKey(key);
};

ListMap.prototype.removeByKey = function(key) {
    var mark = this.map[key];
    if ( isNaN(mark) ) {
        return false;
    }
    delete this.map[key];
    this.list.splice(mark, 1);
    return true;
};

ListMap.prototype.at = function(mark) {
    return this.list[mark];
};

ListMap.prototype.push = function(item) {
    var key = this.key(item);
    if ( "undefined" === typeof key ) {
        return false;
    }
    return this.insert(key, item);
};

ListMap.prototype.pop = function() {
    var item = this.at(0);
    if ( !item ) {
        return null;
    }
    if ( !this.remove(item) ) {
        return null;
    }
    return item;
};

ListMap.prototype.unshift = function(item) { // 向头部插入
    var key = this.key(item);
    if ( "undefined" === typeof key ) {
        return false;
    }
    return this.insert(key, item, true);
};

ListMap.prototype.shift = function() { // 从头部取出
    var size = this.size();
    var item = this.at(size-1);
    if ( !item ) {
        return null;
    }
    if ( !this.remove(item) ) {
        return null;
    }
    return item;
};

ListMap.prototype.shiftList = function(num) {
    var self = this;
    var sink = [];
    doRepeat(num, function(i) {
        var item = self.shift();
        if ( !item ) {
            return true;
        }
        sink.push(item);
    });
    return sink;
};

ListMap.prototype.size = function() {
    return this.list.length;
};

ListMap.test = function() {

};

function MapQueue(mark) {
    this.map = {};
    this.sn = 0;
    this.mark = mark;
    this.length = 0;
}

MapQueue.prototype.check = function(print) {
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

function MultiList(multi, depth) {
    this.multi = multi || 1;
    this.data = {};

    var self = this;
    doRepeat(multi, function(i) {
        var obj = self.data[i] = {};
        obj.depth = depth || 1;
        obj.list = [];
    })
}

MultiList.prototype.count = function(index){
    var obj = this.data[index];
    if (!obj) {
        return 0;
    }
    var cnt = 0;
    doEach(obj.list, function(i, item) {
        if ( !item ) {
            cnt++;
        }
    });
    return cnt;
};

MultiList.prototype.capacity = function(index) {
    var obj = this.data[index];
    if (!obj) {
        return 0;
    }
    return obj.depth;
};

MultiList.prototype.setCapacity = function(index, capacity) {
    var obj = this.data[index];
    if (!obj) {
        return false;
    }

    if ( obj.depth > capacity ) {
        for (var i = capacity; i<obj.depth; i++) {
            var item = obj.list[i];
            if (item) {
                return false;
            }
        }
    }

    obj.depth = capacity;
    return true;
};

MultiList.prototype.isFull = function(index) {
    return this.count(index) > this.capacity(index);
};

MultiList.prototype.isAllFull = function() {
    var self = this;
    var full = true;
    doEachEx(this.data, function(index, obj) {
        if ( !self.isFull(index) ) {
            full = false;
            return true;
        }
    });
    return full;
};

MultiList.prototype.get = function(index, pos) {
    var obj = this.data[index];
    if (!obj) {
        return false;
    }
    return obj.list[pos];
};

MultiList.prototype.getRandPos = function(index) {
    var obj = this.data[index];
    if (!obj) {
        return;
    }
    var pos;
    doRepeat(obj.depth, function(i) {
        if ( !obj.list[i] ) {
            pos = i;
            return true;
        }
    });
    return pos;
};

MultiList.prototype.push = function(item) {
    var _index;
    var find;
    var self = this;
    doEachEx(this.data, function(index, obj) {
        if ( !self.isFull(index) ) {
            _index = index;
            find = true;
            return true;
        }
    });
    if (!find) {
        return false;
    }

    return this.pushByIndex(item, _index);
};

MultiList.prototype.pushByIndex = function(item, index) {
    var pos = this.getRandPos(index);
    if ( isNaN(pos) ) {
        return false;
    }
    return this.pushByPos(item, index, pos);
};

MultiList.prototype.pushByPos = function(item, index, pos) {
    var obj = this.data[index];
    if ( !obj || !item ) {
        return false;
    }
    if ( pos >= obj.depth ||  obj.list[pos] ) {
        return false;
    }
    obj.list[pos] = item;
    return true;
};

function PosManager(limit) {
    this.limit = limit;
    this.posList = [];
    this.lockList = [];
    this.lastFreePos = 0;
}

PosManager.prototype.getLockList = function() {
    return this.lockList;
};

PosManager.prototype.lock = function(pos, flag) {
    if ( !this._safePos(pos) ) {
        return false;
    }
    if (flag) {
        if ( this.posList[pos] ) {
            return false; // 这个位置已经有人， 不能再锁住
        }
    }
    this.lockList[pos] = flag ? true : false;
    return true;
};

PosManager.prototype.push = function(obj) {
    var pos = this._getFreePos();
    if ( pos < 0 ) {
        return false;
    }
    this.posList[pos] = obj;
    obj[pos] = pos;
    return true;
};

PosManager.prototype.set = function(obj, pos) {
    if ( !this._safePos(pos) ) {
        return false;
    }
    this.posList[pos] = obj;
    obj[pos] = pos;
    return true;
};

PosManager.prototype.clear = function(obj, pos) {
    if ( !this._safePos(pos) ) {
        return false;
    }
    this.posList[pos] = null;
    obj[pos] = -1;
    return true;
};

PosManager.prototype._safePos = function(pos) {
    if ( isNaN(pos) || pos < 0 || pos >= this.limit ) {
        return false;
    }
    return true;
};

PosManager.prototype._isLock = function(pos) {
    return this.lockList[pos];
};

PosManager.prototype._haveData = function(pos) {
    return !!this.posList[pos];
};

PosManager.prototype._getFreePos = function() {
    pos = this.lastFreePos;
    pos++;
    if ( this._safePos(pos) && !this._isLock(pos) && !this._haveData(pos) ) {
        return pos;
    }
    pos = -1;
    var self = this;
    doRepeat(this.limit, function(i) {
        var obj = self.posList[i];
        var lock = self.lockList[i];
        if ( !obj && !lock ) {
            self.lastFreePos = pos;
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

Box.eAction = {
    Enter: 0,
    Leave: 1
};

Box.eErrCode = {
    UnKnown: 0,
    HasInBox: 1,
    NoInBox: 2,
    ParamsError: 3
};

Box.prototype.enter = function(key, info) {
    if (!key) {
        return errorFn(Box.eErrCode.ParamsError, false);
    }

    if ( this._sands[key] ) {
        return errorFn(Box.eErrCode.HasInBox, false);
        //return false;
    }

    var action = Box.eAction.Enter;
    if ( !this.check(action, key, info) ) {
        return errorFn(Box.eErrCode.UnKnown, false);
        //return false;
    }

    var sand = this._createFn(key, info);
    this._sands[key] = sand;
    if ( sand.onEnter ) {
        sand.onEnter(info);
    }

    this.notify(action);
    return true;
};

Box.prototype.leave = function(key, info) {
    if (!key) {
        return errorFn(Box.eErrCode.ParamsError, false);
    }

    var sand = this._sands[key];
    if (!sand) {
        return errorFn(Box.eErrCode.NoInBox, false);
        //return false;
    }

    var action = Box.eAction.Leave;
    if ( !this.check(action, key, info) ) {
        return errorFn(Box.eErrCode.UnKnown, false);
        //return false;
    }

    if ( sand.onLeave ) {
        sand.onLeave(info);
    }
    delete this._sands[key];

    this.notify(action);
    return true;
};

Box.prototype.get = function(key) {
    return this._sands[key];
};

Box.prototype.each = function(fn) {
    doEachEx(this._sands, function(key, sand) {
        fn(sand);
    })
};

Box.prototype.sandNum = function() {
    var num = 0;
    this.each(function(sand) {
        num++;
    });
    return num;
};

Box.prototype.check = function(flag, key, info) {
    return true;
};

Box.prototype.notify = function(flag) {

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

var gThrowEnable = true;

//var errorFn = function(code, fn)
var errorFn = function(code, ret, fn) {
    if ( "function" === ret ) {
        fn = ret;
        ret = undefined;
    }

    if (fn) {
        fn(code);
    }

    if (!gThrowEnable) {
        return ret;
    }
    //throw new Error(code);
    throw {isErrorEx: true, code: code};
};

var gDebugEnable = true;
var gDebugList = [
    "",
    "DEBUG",
    "A"
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
};

var tag = function(name) {
    return new Debugger(name);
};

var log = function() {
    var vec = Array.prototype.slice.call(arguments, 0);
    vec.splice(0, 0, "[LOG]");
    console.log.apply(null, vec);
};



module.exports = {
    getTime: getTime,
    getNumber: getNumber,
    getDelayTime: getDelayTime,

    DelayTime: DelayTime,
    CycleTime: CycleTime,
    UpdateTime: UpdateTime,
    UpdateWeek: UpdateWeek,

    ListKeyHelper: ListKeyHelper,

    getWeek: getWeek,
    getWeekEx: getWeekEx,

    doRepeat: doRepeat,
    doEach: doEach,
    doEachEx: doEachEx,
    doEachEx2: doEachEx2,
    doParallel: doParallel,
    doParallelEx: doParallelEx,

    cloneAll: cloneAll,
    cloneByAttr: cloneByAttr,
    cloneForResetKey: cloneForResetKey,

    getListItem: getListItem,
    errorFn: errorFn,

    tag: tag,
    log: log

};

///////////////////////////////////������///////////////////////////////////////

//var updateTimer1 = new CycleTime(30*1000, 0);
//var updateTimer2 = new CycleTime(30*1000);
//var delayTimer1 = new DelayTime(30*1000);
//var tick = 0;
//var check1 = function() {
//
//    var t2 = getTime() - t1; // �����õ��������Լ1s
//
//    tick++;
//
//    var ret = updateTimer1.checkUpdate();
//    var ret2 = updateTimer2.checkUpdate();
//
//    var ret3 = delayTimer1.isExpire();
//    if (ret3) {
//        delayTimer1.reset();
//    }
//
//    if ( ret || ret2 || ret3 ) {
//        console.log("");
//        console.log("t2 = "+t2);
//        console.log("updateTimer1, ret = "+ret);
//        console.log("updateTimer2, ret2 = "+ret2);
//        console.log("delayTimer1,  ret3 = "+ret3);
//    }
//
//};
//
//var check2 = function() {
//
//};
//
//var t1 = getTime();
//setInterval(check1, 1000);
//
//console.log(getDelayTime(10));
//console.log(getDelayTime(10, 10));

//var date = new Date();
//var weekDay  = date.getDay();
//var monthDay = date.getDate();
//
//console.log(date);
//console.log(weekDay);
//console.log(monthDay);
//
//date.setDate(-1);
//console.log(date);
//date.setDate(3);
//console.log(date);

//console.log("===========UpdateWeek==============");
//
//var weekUpdate;
//weekUpdate = new UpdateWeek(0);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(1);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(2);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(3);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(4);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(5);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(6);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(7);
//console.log(new Date(weekUpdate.getNextTime()));
//weekUpdate = new UpdateWeek(8);
//console.log(new Date(weekUpdate.getNextTime()));
//
//console.log("===========getWeek==============");
//
//var time = getTime();
//console.log(getWeek(time));
//time = getTime() + CYCLE_WEEK;
//console.log(getWeek(time));
//time = getTime() + CYCLE_WEEK * 2;
//console.log(getWeek(time));
//time = getTime() + CYCLE_WEEK * 3;
//console.log(getWeek(time));
//time = getTime() - CYCLE_WEEK;
//console.log(getWeek(time));
//time = getTime() - CYCLE_WEEK * 2;
//console.log(getWeek(time));
//time = getTime() - CYCLE_WEEK * 3;
//console.log(getWeek(time));
//
//console.log("===========getWeekEx==============");
//
//time = getTime();
//console.log(getWeekEx(time));
//console.log(getWeekEx(time, 0));
//console.log(getWeekEx(time, 1));
//console.log(getWeekEx(time, 2));
//console.log(getWeekEx(time, 3));
//console.log(getWeekEx(time, 4));
//console.log(getWeekEx(time, 5));
//console.log(getWeekEx(time, 6));
//console.log(getWeekEx(time, 7));
//console.log(getWeekEx(time, 8));
//
//console.log("===========getWeekEx 2==============");
//
//var date2 = new Date;
//date2.setDate(1);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(2);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(3);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(4);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(5);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(6);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(7);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//date2.setDate(8);
//time = date2.getTime();
//console.log(date2, getWeekEx(time, 5));
//
//console.log("===========getWeekEx 3==============");
//
//date2 = new Date;
//date2.setDate(1);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(2);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(3);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(4);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(5);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(6);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(7);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//date2.setDate(8);
//time = date2.getTime();
//console.log(date2, getWeekEx(time));
//
//console.log("===========doRepeat==============");
//
//var vec = [];
//var obj = {};
//doRepeat(10, function(i) {
//    console.log(i);
//    vec[i] = {};
//    vec[i].a = i+100;
//    obj[i] = {};
//    obj[i].b = i+200;
//}, function() {
//    console.log("end");
//});
//
//doEach(vec, function(i, obj) {
//    if (obj) {
//        obj.pos = i;
//    }
//    if ( 5 == i ) {
//        return true;
//    }
//}, function() {
//    console.log("end, vec = ", vec);
//});
//
//doEachEx(obj, function(key, obj) {
//    if (obj) {
//        obj.pos = key;
//    }
//    if ( 5 == key ) {
//        return true;
//    }
//}, function() {
//    console.log("end, obj = ", obj);
//});

//console.log("===========cloneAll==============");
//
//var a = {};
//a.a = 1;
//a.b = {};
//a.b.c = 2;
//
//console.log(cloneAll(a));
//
//var v = [];
//v[1] = a;
//
//var v1 = [];
//v1[0] = v;
//console.log(cloneAll(v));
//console.log(cloneAll(v1));

//console.log("===========cloneForResetKey==============");
//
//console.log(cloneForResetKey("abc.", "", {"abc": 1}));

//console.log("===========ListKeyHelper==============");
//
//var obj = {};
//obj.list1 = 111;
//obj.list2 = 222;
//obj.list3 = 333;
//
//var adapter = new ListKeyHelper("list", 3);
//
//adapter.setValue(obj, 2, 22222);
//console.log(obj);
//
//console.log("==1==", adapter.getValue(obj, 0));
//console.log("==1==", adapter.getValue(obj, 1));
//console.log("==1==", adapter.getValue(obj, 2));
//console.log("==1==", adapter.getValue(obj, 3));
//console.log("==1==", adapter.getValue(obj, 4));
//
//console.log("==2==", adapter.getPos(obj, 0));
//console.log("==2==", adapter.getPos(obj, 111));
//console.log("==2==", adapter.getPos(obj, 222));
//console.log("==2==", adapter.getPos(obj, 333));
//console.log("==2==", adapter.getPos(obj, 444));
//
//console.log(obj);
//console.log(adapter.getAllData(obj));
//
//var list = [];
//list.push({a:1, b:11});
//list.push({a:2, b:22});
//
//console.log(getListItem(list, "a", 1));
//console.log(getListItem(list, "a", 2));

//console.log("===========debug==============");
//
//ab = "ab";
//tag("").log("hello", 123, ab);
//tag("A").log("hello", 123, ab);
//tag("AA").log("hello", 123, ab);
//log("hello", 123, ab);
//
//hello 123 ab
//[A] hello 123 ab
//[LOG] hello 123 ab


//console.log("===========doEachEx2==============");
//
//var obj = {
//    "1": {
//        "11": "a",
//        "22": "b"
//    },
//    "2": {
//        "11": "c",
//        "22": "d"
//    }
//};
//
//doEachEx2(obj, function(key1, key2, obj) {
//    console.log(key1, key2, obj);
//}, function() {
//    console.log("end");
//});
//
//doEachEx2(obj, function(key1, key2, obj) {
//    console.log(key1, key2, obj);
//    if ( 2 == key1 && 11 == key2 ) {
//        return true;
//    }
//}, function() {
//    console.log("end");
//});
//
//1 11 a
//1 22 b
//2 11 c
//2 22 d
//end
//1 11 a
//1 22 b
//2 11 c
//end

//var iconv = require("../modules/iconv-lite/lib");
//
//var str = "帅";
//console.log(str);
//console.log(new Buffer(str));
//console.log(str.charCodeAt(0));
//console.log(String.fromCharCode(35831,27714));
//console.log(new Buffer(String.fromCharCode(35831,27714)));
//console.log(String.fromCharCode(232, 175, 183, 230, 177, 130));

//console.log(new Buffer(str));
//console.log(iconv.encode(str, "gbk"));

//请求
//<Buffer e8 af b7 e6 b1 82>
//35831
//请求
//<Buffer e8 af b7 e6 b1 82>
//è¯·æ±

//var data1 = iconv.encode(str, "utf8");  console.log(data1.toString(), data1);
//
//var data2 = iconv.encode(str, "gbk");   console.log("data = ", data2);
//data2 = iconv.decode(data2, "gbk");     console.log("data = ", data2);
//
//
//var data3 = iconv.encode(str, "gbk");   console.log("data = ", data3);
//data3 = iconv.decode(data3, "utf8");    console.log("data = ", data3);
//data3 = iconv.encode(data3, "utf8");    console.log("data = ", data3);
//data3 = iconv.decode(data3, "gbk");     console.log("data = ", data3);

//gbk编码转utf时， 出现不可逆性

//str = iconv.decode(new Buffer([0x68, 0x65, 0x6c, 0x6c, 0x6f]), 'win1251');

//var t = new Date(1439990673341);
//console.log(t);
//console.log(t.getTime());

//console.log("===========ListMap==============");
//
//ListMap.test();

//console.log("===========MapQueue==============");
//
//MapQueue.test();

function FakeBoxService() {
    this.boxes = {};
    this.sn = 0;
}

FakeBoxService.prototype.create = function(boxId, uid, info) {
    this.sn++;

    if ( !boxId ) {
        return errorFn(Box.eErrCode.ParamsError, null);
    }

    if ( this.boxes[boxId] ) {
        return errorFn(FakeBox.eErrCode.IdDup, null);
    }

    var box = new FakeBox(this, boxId, function(key, info) {
        return new FakeBoxUser(key, info);
    });

    if ( !box.enter(uid, info) ) {
        return null;
    }

    this.boxes[boxId] = box;

    return box;
};

FakeBoxService.prototype.handler = function(boxId) {
    return this.boxes[boxId];
};

FakeBoxService.prototype.release = function(boxId) {
    console.log("FakeBoxService.prototype.release, boxId = ", boxId);
    delete this.boxes[boxId];
};

function FakeBox(mgr, id, createFn) {
    Box.call(this, createFn);
    this._mgr = mgr;
    this._id = id;
}

var util = require("util");
util.inherits(FakeBox, Box);

FakeBox.eErrCode = {
    IdDup: 10
};

FakeBox.prototype.leave = function(uid, info) {
    if ( !Box.prototype.leave.call(this, uid, info) ) {
        return false;
    }

    if ( 0 == this.sandNum() ) {
        this._mgr.release(this._id);
    }
    return true;
};

FakeBox.prototype.notify = function(flag) {
    var list = [];
    this.each(function(user) {
        list.push(user.getId());
    });
    console.log("FakeBox.prototype.notify, list = ", list);
};

function FakeBoxUser(uid, info) {
    this._uid = uid;
    this._info = info;
}

FakeBoxUser.prototype.getId = function() {
    return this._uid;
};

FakeBoxUser.prototype.onEnter = function() {
    console.log("FakeBoxUser.prototype.onEnter ", this.getId());
};

FakeBoxUser.prototype.onLeave = function() {
    console.log("FakeBoxUser.prototype.onLeave ", this.getId());
};

FakeBoxService.test = function() {

    console.log("FakeBoxService.test");

    console.log(Box.prototype);
    console.log(FakeBoxService.prototype);

    try {
        var mgr = new FakeBoxService();

        var box = mgr.create("box-1", "1", {});
        console.log(box ? true: false);
        console.log(box.enter("2"));
        console.log(box.enter("3"));

        console.log(box.leave("1"));
        console.log(box.leave("2"));
        console.log(box.leave("3"));

        console.log(box.leave("3"));
    } catch (e) {
        console.log(e.code);
    }

};

//FakeBoxService.test();

UpdateTime.test = function() {
    var params = {
        cycle: 60 * 60 * 1000,
        hour: 2
    };
    var timer = new UpdateTime(params);
    setInterval(function() {
        console.log("cur date = ", new Date);
        var res = timer.checkNext();
        if (res) {
            timer._debug("checkNext suc");
        }
    }, 10000);

};
UpdateTime.test();
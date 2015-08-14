

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

function UpdateTime(cycle, start) {
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

UpdateTime.prototype.getNextTime = function() {
    return this.next;
};

UpdateTime.prototype.checkUpdate = function() {
    var cur =  getTime();
    if ( cur > this.next  ) {
        this.last = cur;
        this.resetNextTime();
        return true;
    }

    return false;
};

UpdateTime.prototype.resetNextTime = function() {
    var cycle = this.cycle;
    var last  = this.last;

    this.next = this.next + cycle;  // ��ǰʱ�������������Զִ�в���

    if ( last >= this.next ) {  //���ɴ�ʱ��
        var multi = (last- this.next) / cycle;
        multi = parseInt(multi) + 1;
        this.next = this.next + cycle * multi;

        var dif = this.next - last;
        console.log("UpdateTime exception,  next update will no attach, so adjust the dif = " + dif);
    }

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
    this.updateTime = new UpdateTime(CYCLE_WEEK, start);
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

function checkNumber(data) {
    return "number" == typeof data;
}

function checkString(data) {
    return "string" == typeof data;
}

function checkObject(data) {
    return "object" == typeof data;
}

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
    UpdateTime: UpdateTime,
    UpdateWeek: UpdateWeek,

    getWeek: getWeek,
    getWeekEx: getWeekEx,

    doRepeat: doRepeat,
    doEach: doEach,
    doEachEx: doEachEx,
    doEachEx2: doEachEx2,

    cloneAll: cloneAll,
    cloneByAttr: cloneByAttr,
    cloneForResetKey: cloneForResetKey,

    ListKeyHelper: ListKeyHelper,
    ListHelper: ListHelper,
    getListItem: getListItem,

    tag: tag,
    log: log
};

///////////////////////////////////������///////////////////////////////////////

//var updateTimer1 = new UpdateTime(30*1000, 0);
//var updateTimer2 = new UpdateTime(30*1000);
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



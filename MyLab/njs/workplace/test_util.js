

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
    if ( this.cycle < 5000 ) {  //限制时间， 最小为5秒
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

    this.next = this.next + cycle;  // 当前时间往后调可能永远执行不到

    if ( last >= this.next ) {  //不可达时间
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
    if ( difDay < 0 ) {  // 过去的几天
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
    date.setDate( date.getDate() + 4 - weekDay );  //计算实际的偏移
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

    date.setDate(date.getDate() + 4 - weekDay );  //计算实际的偏移
    curTime = date.getTime();
    date.setMonth(0);
    date.setDate(1);
    week = Math.floor(Math.round((curTime - date.getTime()) / CYCLE_WEEK )) + 1;
    return week;
}

///////////////////////////////////测试区///////////////////////////////////////

//var updateTimer1 = new UpdateTime(30*1000, 0);
//var updateTimer2 = new UpdateTime(30*1000);
//var delayTimer1 = new DelayTime(30*1000);
//var tick = 0;
//var check1 = function() {
//
//    var t2 = getTime() - t1; // 从设置到出发相隔约1s
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

console.log("===========UpdateWeek==============");

var weekUpdate;
weekUpdate = new UpdateWeek(0);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(1);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(2);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(3);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(4);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(5);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(6);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(7);
console.log(new Date(weekUpdate.getNextTime()));
weekUpdate = new UpdateWeek(8);
console.log(new Date(weekUpdate.getNextTime()));

console.log("===========getWeek==============");

var time = getTime();
console.log(getWeek(time));
time = getTime() + CYCLE_WEEK;
console.log(getWeek(time));
time = getTime() + CYCLE_WEEK * 2;
console.log(getWeek(time));
time = getTime() + CYCLE_WEEK * 3;
console.log(getWeek(time));
time = getTime() - CYCLE_WEEK;
console.log(getWeek(time));
time = getTime() - CYCLE_WEEK * 2;
console.log(getWeek(time));
time = getTime() - CYCLE_WEEK * 3;
console.log(getWeek(time));

console.log("===========getWeekEx==============");

time = getTime();
console.log(getWeekEx(time));
console.log(getWeekEx(time, 0));
console.log(getWeekEx(time, 1));
console.log(getWeekEx(time, 2));
console.log(getWeekEx(time, 3));
console.log(getWeekEx(time, 4));
console.log(getWeekEx(time, 5));
console.log(getWeekEx(time, 6));
console.log(getWeekEx(time, 7));
console.log(getWeekEx(time, 8));

console.log("===========getWeekEx 2==============");

var date2 = new Date;
date2.setDate(1);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(2);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(3);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(4);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(5);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(6);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(7);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));
date2.setDate(8);
time = date2.getTime();
console.log(date2, getWeekEx(time, 5));

console.log("===========getWeekEx 3==============");

date2 = new Date;
date2.setDate(1);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(2);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(3);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(4);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(5);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(6);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(7);
time = date2.getTime();
console.log(date2, getWeekEx(time));
date2.setDate(8);
time = date2.getTime();
console.log(date2, getWeekEx(time));
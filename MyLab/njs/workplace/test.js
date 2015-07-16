//var addon = require('../bin/Debug/xNode')
//
//;
//console.log(addon.hello()); // 'world'

console.log("------------------1-----------------");

//function Person()
//{
//	this.name = "zh";
//
//	Person.prototype.age = 123;
//}
//
//var man1 = new Person();
//var man2 = new Person();
//console.log(man1);
//console.log(man2);
//console.log(man1.age);
//Person.prototype.age = 321;
//console.log(man2.age);
//
//var a = {};
//var b;
//console.log(a);
//console.log(b);


console.log("------------------2-----------------");   // 实现类似虚函数调用

function CBase()
{
    this.name = "zh";  // 外部可以访问

    var helloName = "hello";  // 可以访问

    var priHello = function()   // 外部无法调用
    {
        console.log("priHello, base", helloName);  // 无法访问this指针
    };

    this.thsHello = function()  // 外部可以调用
    {
        console.log("thsHello, base", this.name, helloName);
    };

    this.hello = function()  // 外部可以调用
    {
        console.log("hello, base");
    };

}

CBase.prototype.hello = function()  // 外部可以调用
{
    console.log("prototype.hello, base");
    this.thsHello();
};

function CSub1()
{
    this.thsHello = function()
    {
        console.log("thsHello, sub1");
    }
}
//
//function CSub2()
//{
//    var hello = function()
//    {
//        console.log("hello, sub2");
//    }
//}
var base = new CBase();
var sub1 = new CSub1();
//var sub1 = new CSub1;
//var sub2 = new CSub2;
console.log("1");
base.hello();   // 优先内部的函数

console.log("2");
base.thsHello();

console.log("3");
CBase.prototype.hello.call(base);  // prototype 函数内部有访问this指针时，需添加实例

//console.log("3.1");
//CBase.hello.call(base);  // 无法调用

console.log("3.2");  // 测试虚函数
CBase.prototype.hello.call(sub1);  // 依然调用的是 CBase

console.log("4");
console.log(base);

console.log("5");
console.log(base.name);

//sub1.hello();
//sub2.hello();


console.log("------------------3-----------------");   // 测试文件内的变量周期

function C3()
{
    var v1 = -1;
    this.v2 = -1;

    this.set_v1 = function(v)
    {
        v1 = v;
    };

    this.get_v1 = function()
    {
        return v1;
    };

    this.set_v2 = function(v)
    {
        this.v2 = v;
    };

    this.get_v2 = function()
    {
        return this.v2;
    };

    this.set_v3 = function(v)
    {
        C3.prototype.v3 = v;  // 使用 this.prototype.v3 调用失败， 使用 this.v3, 则默认指向对象内部
    };

    this.get_v3 = function()
    {
        return C3.prototype.v3;
    }
}

C3.prototype.v3 = 0;
C3.prototype.v4 = 0;
C3.prototype.v5 = 0;

C3.prototype.set_v4 = function(v)
{
    this.v4 = v;
};

C3.prototype.get_v4 = function()
{
    return this.v4;
};

C3.prototype.set_v5 = function(v)
{
    C3.prototype.v5 = v;
};

C3.prototype.get_v5 = function()
{
    return C3.prototype.v5;
};


var c3 = C3(0, 0);
console.log(c3);  // undefined

var c3 = new C3();
var c3_sub = new C3();

console.log(c3); // { v2: -1 , [Function] }
console.log(c3.get_v1()); // -1
console.log(c3.get_v2()); // -1
console.log(c3.get_v3()); // 0

c3.set_v1(1);
c3.set_v2(2);
c3.set_v3(3);
c3.set_v4(4);
c3.set_v5(5);

console.log(c3.get_v1()); // 1
console.log(c3.get_v2()); // 2
console.log(c3.get_v3()); // 3
console.log(c3.get_v4()); // 4
console.log(c3.get_v5()); // 5
console.log(c3_sub.get_v1()); // -1
console.log(c3_sub.get_v2()); // -1
console.log(c3_sub.get_v3()); // 3
console.log(c3_sub.get_v4()); // 0
console.log(c3_sub.get_v5()); // 5

console.log("------------------4-----------------");   // 测试文件间的变量周期

var o1 = require('./module1/other.js');
var o2 = require('./module1/other.js');

console.log(o1);
//{ v4: -1,
//v5: -1,
//    set_v3: [Function],
//    get_v3: [Function],
//    set_v4: [Function],
//    get_v4: [Function],
//    set_v5: [Function],
//    get_v5: [Function],
//    set_v2: [Function],
//    get_v2: [Function],
//    C1: [Function: C],
//C2: { v1: -1, set_v1: [Function], get_v1: [Function] } }

//console.log(o1.get_v1());  // error
console.log(o1.get_v2());  // -1
console.log(o1.get_v3());  // -1
//console.log(o1.get_v4());  // error
console.log(o1.get_v5());  // -1

o1.set_v2(2);
o1.set_v3(3);
o1.set_v4(4);
o1.set_v5(5);

console.log(o1.get_v2());  // 2
console.log(o2.get_v2());  // 2

console.log(o1.get_v3());  // 3
console.log(o2.get_v3());  // 3

console.log(o1.get_v4());  // 4
console.log(o2.get_v4());  // 4

console.log(o1.get_v5());  // 5
console.log(o2.get_v5());  // 5

// 综上结论， require返回的是一个全局对象

var o1_c1 = o1.C1;
var o2_c1 = o2.C1;

var o1_c2 = o1.C2;
var o2_c2 = o2.C2;

var o1_c3 = new o1.C1;
var o2_c3 = new o2.C1;

console.log(o1_c1);  // [Function: C]
console.log(o1_c2);  // { v1: -1, set_v1: [Function], get_v1: [Function] }

o1_c2.set_v1(1);

console.log(o1_c2.get_v1());  // 1
console.log(o2_c2.get_v1());  // 1

o1_c3.set_v1(2);
console.log(o1_c3.get_v1());  // 2
console.log(o2_c3.get_v1());  // -1


console.log("------------------5-----------------");   // 测试文件间的输出

var o11 = require('./other1.js');
var o22 = require('./other2.js');
var o23 = require('./other2.js');

console.log(o11);  // [Function: CC]
console.log(o22);  // { v1: -1, set_v1: [Function], get_v1: [Function] }

o22.set_v1(1);

//console.log(o11.get_v1());  // error
console.log(o22.get_v1()); // 1
console.log(o23.get_v1()); // 1

var o12 = new o11;
var o13 = new o11;

o12.set_v1(1);
console.log(o12.get_v1()); // 1
console.log(o13.get_v1()); // -1

console.log("------------------5-----------------");   // 测试文件间的参数输入

var o33 = require('./other3');
var o44 = require('./other4');

console.log(o33);  // [Function: CC]
console.log(o44);  // [Function: CC]

var o331 = new require('./other3')(1);
var o332 = new o33(2);
var o333 = new require('./other3');
var o334 = o333(4);
//var o335 = o332(5); // error

console.log(o331);  // undefined
console.log(o332);  // { v1: 2, set_v1: [Function], get_v1: [Function] }
console.log(o333);  // [Function: CC]
console.log(o334);  // undefined

var o441 = require('./other4')(1);
var o442 = o44(2);

console.log(o441);  // 2
console.log(o442);  // 3

console.log(global.varA); // undefined
console.log(global.varB); // g 在 other4中 定义

var g_var3 = "g_var3";

function C5() {
    ;
};

C5.prototype.f_var4 = "g_var4";

var c5 = new C5;

console.log("------------------6-----------------");   // 测试文件下的文件

//var o61 = require('./module1');  // error
var o62 = require('./module2');
//var o63 = require('./module3');  // error

console.log(o62);

// 总结：访问一个文件价， 默认访问该文件夹下的index.js

console.log("------------------7-----------------");   // 测试内嵌数组

function oriData()
{
    console.log("args = ", arguments);
    this.name = 1;
}

function subData()
{
    this.name = 11;
}

var sub = new subData();

var d1 = new oriData({
    name1 : 11,
    name2 : 22
},
{
    name1 : 11,
    name2 : 22
});

var d2 = new oriData();

//var d3 = new oriData(  // 无法直接传json格式 需要放在对象里
//    name1 : 11,
//    name2 : 22
//);

var d4 = new oriData({
    name1 : { name11: { name111:111, name112:112 }, name12:{  name121:121 }, name13:13 },
    name2 : 2
});

var json = { j1:1, j2:2 };

var d5 = new oriData({
    name1  : 1,
    name2  : [],
    name3  : [subData],
    name4  : [sub],
    name5  : [subData, subData],
    name6  : [subData, sub],
    name7  : [sub, sub],
    name8  : subData,
    name9  : sub,
    name10 : json

});

console.log(d1);  // args =  { '0': { name1: 11, name2: 22 }, '1': { name1: 11, name2: 22 } }       { name: 1 }
console.log(d2);  // args =  {}                                                                     { name: 1 }
//console.log(d3);  //
console.log(d4);  // { '0':
                  // { name1: { name11: [Object], name12: [Object], name13: 13 },
                  //   name2: 2 } }   // 打印深度有限
console.log(d5);


console.log("------------------8-----------------");   //

//var crc = require('./crc');
//
//console.log(crc);

//var m4 = require('./module4');

//console.log(m4);


console.log("------------------9-----------------"); // 观察调试时  数字和字符串不同的表示

var num = 01;
var str = "01";

//for (var i in list)  // i 表现为 字符串

console.log("------------------10-----------------");

var map = [];

map["a"] = 111;
map["b"] = 222;
map[1] = 333;
map[2] = 444;

console.log(map);
console.log(map["a"]);
console.log(map["b"]);
console.log(map[1]);
console.log(map[2]);
console.log(map[10]);

//[ , 333, 444, a: 111, b: 222 ]
//111
//222
//333
//444
//undefined

var vec = [];
vec[0] = 111;
vec[1] = 222;
vec["a"] = 333;
vec["b"] = 444;

console.log(vec);
console.log(vec[1]);
console.log(vec[2]);
console.log(vec["a"]);
console.log(vec["b"]);
console.log(vec["ab"]);

//[ 111, 222, a: 333, b: 444 ]
//222
//undefined
//333
//444
//undefined

console.log("------------------11-----------------");  // 测试异步执行引擎

//var async = require('async');
//
//function C11()
//{
//    var v1 = -1;
//    this.v2 = -1;
//
//    this.set_v1 = function(v)
//    {
//        v1 = v;
//    };
//
//    this.get_v1 = function(cb)
//    {
//        cb(null);
//        return v1;
//    };
//
//}
//
//func = [];
//var c = new C11();
//
//var callback = function(err){
//    console.log(err);
//};
//
//func.push(c.get_v1(callback));
//
//async.waterfall(func, function(err){
//    console.log(err);
//});

console.log("------------------12-----------------");  // 测试 Array.prototype.slice.call 和 arguments

var args = Array.prototype.slice.call({ '0': 1, '1': { a: 1, b: 2 }, '2': 3, '3': 4, '4': 5 , 'length':5});
console.log(args); // [ 1, { a: 1, b: 2 }, 3, 4, 5 ]
var args = Array.prototype.slice.call({ '0': 1, '1': { a: 1, b: 2 }, '2': 3, '3': 4, '4': 5});
console.log(args); // []
var args = Array.prototype.slice.call({ 'a': 1, '1': { a: 1, b: 2 }, '2': 3, '3': 4, '4': 5 , 'length':5});
console.log(args); // [ , { a: 1, b: 2 }, 3, 4, 5 ]
var args = Array.prototype.slice.call({ '0': 1, '1': { a: 'aaa', b: 3 }, '2': 3, '3': 4, '4': 5 , 'length':3});
console.log(args); // [ 1, { a: 'aaa', b: 3 }, 3 ]
var args = Array.prototype.slice.call({ '0': 1, '1': { a: 'bbb', b: 3 }, '2': 3, '3': 4, '4': 5 , 'length':3}, { '0': 1, '1': { a: 'bbb', b: 3 }, '2': 3, '3': 4, '4': 5 , 'length':3});
console.log(args); // [ 1, { a: 'bbb', b: 3 }, 3 ]
var args = Array.prototype.slice.call({ '0': 1, '1': { a: 'ccc', b: 3 }, '2': 3, '3': 4, '4': 5 , 'length':3}, 1);
console.log(args); // [ { a: 'ccc', b: 3 }, 3 ]
var args = Array.prototype.slice.call({ '0': 1, '1': { a: 'ddd', b: 3 }, '2': 3, '3': 4, '4': 5 , 'length':3}, 2);
console.log(args); // [ 3 ]

var f = function(){
    console.log(arguments); // { '0': 1, '1': { a: 1, b: 2 }, '2': 3, '3': 4, '4': 5 }
    var args =  Array.prototype.slice.call(arguments);
    console.log(args);  // [ 1, { a: 1, b: 2 }, 3, 4, 5 ]

    var args2 = args.concat(args);
    console.log(args2); // [ 1, { a: 1, b: 2 }, 3, 4, 5, 1, { a: 1, b: 2 }, 3, 4, 5 ]

    //var arg3 = arguments.concat(arguments);  // error
    //console.log("arg3 = ", arg3);

    var arg3 = args.concat(arguments);
    console.log("arg3 = ", arg3);
    //   [ 1,
    //    { a: 1, b: 2 },
    //    3,
    //    4,
    //    5,
    //    { '0': 1, '1': { a: 1, b: 2 }, '2': 3, '3': 4, '4': 5 } ]
};

f(1,{a:1, b:2},3,4,5);

var vec = [f]; // [ [Function] ]
console.log(vec);

var vec = [f, 123, "abc"]; // [ [Function], 123, 'abc' ]
console.log(vec);

var f1 = function() {
    console.log(arguments);
};

f1.call(null, 1, 2, "a", "b");  // { '0': 1, '1': 2, '2': 'a', '3': 'b' }   // this = global
f1.call({a:"aa", b:"bb"}, 1, 2, "a", "b"); // { '0': 1, '1': 2, '2': 'a', '3': 'b' } // this. object

console.log("------------------13-----------------");

f1.apply(null, [1, 2, "cc", "dd"]);  // { '0': 1, '1': 2, '2': 'cc', '3': 'dd' }
f1.apply(null, { '0': 1, '1': 2, '2': 'a', '3': 'b' }); // { '0': 1, '1': 2, '2': 'cc', '3': 'dd' }
f1.apply(null, { '0': 1, '1': 2, '2': 'a', '3': 'b' , 'length': 2}); // { '0': 1, '1': 2 }
f1.apply(null, { '0': 1, '1': 2, '2': 'a', '3': 'b' , 'length': 5}); // { '0': 1, '1': 2, '2': 'a', '3': 'b', '4': undefined }
f1.apply(null, { '0': 1, '1': 2, '2': 'a', 'm': 'b' , 'length': 5}); // { '0': 1, '1': 2, '2': 'a', '3': undefined, '4': undefined }
f1.apply(null, { '0': 1, '1': 2, '2': 'a', '7': 'b' , 'length': 5}); // { '0': 1, '1': 2, '2': 'a', '3': undefined, '4': undefined }

var args =  Array.prototype.slice.call({ '0': 1, '1': 2, '2': 'cc', '3': 'dd' }); // []
console.log(args);

var args =  Array.prototype.slice.call({ '0': 1, '1': 2, '2': 'cc', '3': 'dd' ,  'length': 2}); // [ 1, 2 ]
console.log(args);

var args =  Array.prototype.slice.call({ '0': 1, 'a': 2, '2': 'cc', '3': 'dd',  'length': 3}, 1); // [ , 'cc' ]
console.log(args);

var args =  Array.prototype.slice.call({ '0': 1, 'a': 2, '2': 'cc', '3': 'dd',  'length': 3}, 4); // []
console.log(args);

console.log("------------------14-----------------");

var C14 = function () {
  ;
};

C14.x1 = 111;
C14.x2 = function() {

};

var c14 = new C14();

//c14.prototype.x3 = 333;

console.log(C14); // { [Function] x1: 111, x2: [Function] }
console.log(c14); {}

function C14_1(){
    this.name = "123";
    this.x11 = 11;
};

C14_1.x1 = 111;
C14_1.x2 = function() {

};

C14_1.prototype.x3 = 333;

c14_1 = new C14_1();

//c14_1.prototype.x4 = 444;

console.log(C14_1); // { [Function: C14_1] x1: 111, x2: [Function] }
console.log(c14_1); {}  // { name: '123' }

//console.log(c14_1.hasOwnProperty()); // { [Function: C14_1] x1: 111, x2: [Function] }
//c14_1["name"] = "n";
console.log(c14_1.hasOwnProperty("name"));  // true
console.log(c14_1.hasOwnProperty("x11"));   // true
console.log(c14_1.hasOwnProperty("x1"));    // false
console.log(c14_1.hasOwnProperty("x3"));    // false
//console.log(c14_1.hasp("x3"));

function C14_2(){

    C14_1.call(this);

    this.name2 = "123";
    this.x112 = 11;
};

c14_2 = new C14_2();

console.log(c14_2);  // { name: '123', x11: 11, name2: '123', x112: 11 }
console.log(c14_2.hasOwnProperty("name"));  // true
console.log(c14_2.hasOwnProperty("x11"));   // true

console.log("------------------15-----------------");

var vec15 = [];
vec15.push(1);
vec15.push(3);
vec15.push(5);

console.log(vec15);

console.log("------------------16-----------------");   // 判断日期

{
    function getWeek(date) {
        var time,week,checkDate = new Date(date);
        checkDate.setDate(checkDate.getDate() + 4 - (checkDate.getDay() || 7));  //计算实际的偏移
        time = checkDate.getTime();
        checkDate.setMonth(0);
        checkDate.setDate(1);
        week=Math.floor(Math.round((time - checkDate) / 86400000) / 7) + 1;
        return week;
    }

    var t1 = Date.now();
    var t2 = new Date();
    var t3 = t2.getTime();
    var t4 = new Date(t3);
    var t5 = t4.getDate();   // 返回天数 范围 1-31
    var t6 = t4.getDay();    // 获取当前天数为周几 范围0-6 周天为0
    var week = getWeek(t1);

    console.log("");
}


console.log("------------------17-----------------");   // 判断类型

var type1;
var type2 = false;
var type3 = 0;
var type4 = function(){};
var type5 = "123";

console.log(typeof type1);
console.log(typeof typeof type1);
console.log(typeof type2);
console.log(typeof type3);
console.log(typeof type4);
console.log(typeof type5);
//undefined
//string
//boolean
//number
//function
//string

console.log( "undefined" === typeof type1 );
console.log( "boolean" === typeof type2 );
console.log( "number" === typeof type3 );
console.log( "undefined" === typeof type3 );
//true
//true
//true
//false

console.log("------------------18-----------------");   // 判断类型


var v1 = {};
var v2 = [];
v1[9] = 9;
v2[9] = 9;
console.log(v1.length); // undefined
console.log(v2.length);
console.log(v1); // { '9': 9 }
console.log(v2); // [ , , , , , , , , , 9 ]

console.log("------------------19-----------------");   // 保留小数位数


var n19 = 123.13579;
var n19_1 = n19.toExponential();  // 以下全为字符串
var n19_2 = n19.toFixed(2);
var n19_3 = n19.toFixed(9);
var n19_4 = n19.toPrecision(2);
var n19_5 = n19.toPrecision(9);
console.log(n19_1); // 1.2313579e+2 指数计数法
console.log(n19_2);      // 123.14  // 小数保留指定位数
console.log(n19_3);      // 123.135790000
console.log(n19_4);      // 1.2e+2  // 整体保留指定位数
console.log(n19_5);      // 123.135790

//var f19_0 = parseFloat(1);
var f19_1 = parseFloat(n19_1);
var f19_2 = parseFloat(n19_2); //

//解析和指数想成会消耗内存

var f19_3 = Math.round(n19*100) / 100;
console.log(f19_3); // 123.14

var multi = Math.pow(10, 2);
var f19_4 = Math.round( n19 * multi ) / multi;
console.log(f19_4); // 123.14

console.log("------------------20-----------------");

var obj = {
    obj1: 1,
    obj2: 2
};

console.log("obj = "+ obj);
console.log("obj = ", obj);

console.log("------------------21-----------------");

var vec21 = [
    'get'
    , 'post'
    , 'put'
    , 'head'
    , 'delete'
    , 'options'
    , 'trace'
    , 'copy'
    , 'lock'
    , 'mkcol'
    , 'move'
    , 'propfind'
    , 'proppatch'
    , 'unlock'
    , 'report'
    , 'mkactivity'
    , 'checkout'
    , 'merge'
    , 'm-search'
    , 'notify'
    , 'subscribe'
    , 'unsubscribe'
    , 'patch'
];

console.log(vec21.indexOf());
console.log(vec21.indexOf("get"));
console.log(vec21.indexOf("post"));
console.log(~vec21.indexOf());
console.log(~vec21.indexOf("get"));
console.log(~vec21.indexOf("post"));

//-1
//0
//1
//0
//-1
//-2


console.log("------------------22-----------------");

var v22;

var v;

v = v22+0;
console.log(v);

v = v22+1;
console.log(v);

v = v22*0;
console.log(v);

v = v22*1;
console.log(v);
console.log( typeof  v );
console.log(v.toString() );

v = 2/0;
console.log(v);
console.log( typeof  v );
console.log(v.toString() );

//NaN
//NaN
//NaN
//NaN
//number
//NaN
//Infinity
//number
//Infinity


console.log("------------------23-----------------");

var v23 = [];
v23[10] = 0;
v23.forEach(function(a, b, c, d) {
    console.log(a, b, c, d);
});

// 0 10 [ , , , , , , , , , , 0 ] undefined

console.log("------------------24-----------------");

function func1() {
    console.log(arguments.length);
}

function func2(a) {
    console.log(arguments.length, a);
}

function func3(a, b) {
    console.log(arguments.length, a, b);
}

func1();
func2(1);
func3(1, 2, 3);

//0
//1 1
//3 1 2


//var addon = require('../bin/Debug/xNode')
//
//;
//console.log(addon.hello()); // 'world'


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


console.log("------------------25-----------------");

var os = require('os');

var info = {};

info.hostname = os.hostname;

info.type = os.type;

info.platform = os.platform;

info.arch = os.arch;

info.release = os.release;

info.uptime = os.uptime;

info.loadavg = os.loadavg;

info.totalmem = os.totalmem;

info.freemem = os.freemem;

info.cpus = os.cpus;

info.networkInterfaces = os.networkInterfaces;

info.versions = function(){return process.versions};

info.arch = function(){return process.arch};

info.platform = function(){return process.platform};

info.memoryUsage = process.memoryUsage;

info.uptime = process.uptime;

//console.log(info);

function getBasicInfo() {
    var result = {};
    for (var key in info) {
        result[key] = info[key]();
    }
    return result;
}

var result = getBasicInfo();

console.log(result);

//{ hostname: 'ND--20150717EAU',
//    type: 'Windows_NT',
//    platform: 'win32',
//    arch: 'ia32',
//    release: '6.1.7601',
//    uptime: 0.126,
//    loadavg: [ 0, 0, 0 ],
//    totalmem: 17119252480,
//    freemem: 12172103680,
//    cpus:
//    [ { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//        speed: 3591,
//        times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] },
//        { model: 'Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz',
//            speed: 3591,
//            times: [Object] } ],
//        networkInterfaces:
//    { 'æ¬å°è¿æ¥': [ [Object], [Object] ],
//        'Loopback Pseudo-Interface 1': [ [Object], [Object] ] },
//    versions:
//    { http_parser: '2.3',
//        node: '0.12.2',
//        v8: '3.28.73',
//        uv: '1.4.2-node1',
//        zlib: '1.2.8',
//        modules: '14',
//        openssl: '1.0.1m' },
//    memoryUsage: { rss: 16199680, heapTotal: 9555584, heapUsed: 3662836 } }


console.log("------------------30-----------------");  // 测试相互引用内存泄露

var buf30 = {};

//var a = require('a');

var func30 = function() {
    var buf = buf30[1] = {};
    var A = buf.A = {};
    var B = buf.B = {};
    //var A = buf;
    //var B = {};

    A.vec = [];
    A.include = B;

    B.vec = [];
    B.include = A;

    var vec, limit, tmp;

    vec = A.vec;
    limit = 500;
    while(limit--) {
        tmp = new Buffer(1024*1024);
        vec.push(tmp);
    }

    vec = B.vec;
    limit = 500;
    while(limit--) {
        tmp = new Buffer(1024*1024);
        vec.push(tmp);
    }

};

var func30_1 = function() {
    var vec = [];
    var limit = 1000, tmp;
    while(limit--) {
        tmp = new Buffer(1024*1024);
        vec.push(tmp);
    }
};

//func30();
////delete buf30[1];
//func30_1();
//
//setInterval(function(){
//    console.log(1111);
//    func30_1();
//}, 1000);




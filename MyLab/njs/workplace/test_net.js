
var util = require("./test_util");
var async = require("../modules/async");
var net = require('net');

var HOST = '127.0.0.1';
var PORT = 1234;
var gSn = 0;

function NetClient(ip, port, cb) {
    cb = cb || function() {};
    var self = this;
    var sock = new net.Socket();
    sock.connect(port,ip, function() {
        if ( port > 65535 ) {
            port -= 65536;
        }
        console.log("connect to: ", ip, port);
        //sock.destroy();
    });

    sock.on('data', function(data) {
        console.log('receive ', ip, port, data.toString("utf8"));
        //client.destroy();
    });

    sock.on('close', function() {
        console.log('sock closed', ip, port);
        cb();
    });

    sock.on('error', function(err) {
        //console.log('sock error', ip, port, err);
    });

    self.sock = sock;
    self.sn = ++gSn;
}



var portList = [
    135,
    316,
    1025,
    1026,
    1028,
    1030,
    1060,
    1062,
    1234,
    //1545,  // 靠谱助手
    //1546,  // 靠谱助手
    //1547,  // 靠谱助手
    //1548,  // 靠谱助手
    2122,
    2861,
    2871,
    3005,
    3010,
    //3306,  // mysql
    3389,
    4300,
    4301,
    5037,
    5399,
    6379,
    6399,
    6555,
    6942,
    7399,
    9399,
    9873,
    9874,
    9875,
    9876,
    9984,
    9990,
    10101,
    11807,
    22468,
    22469,
    22471,
    22500,
    22666,
    23401,
    25000,
    //27017,  //mongodb
    41415,
    46361,
    63342
];

var list = [];

util.doEach(portList, function(i, port) {
    console.log("new client", port);
    list[i] = new NetClient(HOST, port);
    //list[i] = i+600;
});

//var list2 = {};
//async.eachSeries(list, function(item, fn) {  // 执行错误，后续停止执行
//    console.log("eachSeries", item);
//    list2[item] = new NetClient(HOST, item, fn);
//    //fn(null);
//}, function(err) {
//    console.log("async.eachSeries cb", err);
//});



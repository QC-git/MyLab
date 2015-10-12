
var util = require("./test_util");
var net = require("net");
var dns = require('dns');
var http = require("http");
var async = require("../modules/async");
var iconv = require("../modules/iconv-lite/lib");
//var sockIo = require("../modules/socket.io");

var HOST = '127.0.0.1';
var PORT = 9527;
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
        console.log('receive ', ip, port);
        console.log(data);

        var data1 = data.toString("utf8");
        var data2 = iconv.decode(data, "gbk");
        console.log(data1);
        console.log(data2);
    });

    sock.on('close', function() {
        console.log('sock closed', ip, port);
        cb();
    });

    sock.on('error', function(err) {
        console.log('sock error', ip, port, err);
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

function test1() {
    console.log("\n test1 \n");

    //var list = [];
    //
    //util.doEach(portList, function(i, port) {
    //    console.log("new client", port);
    //    list[i] = new NetClient(HOST, port);
    //    //list[i] = i+600;
    //});

    //var list2 = {};
    //async.eachSeries(list, function(item, fn) {  // 执行错误，后续停止执行
    //    console.log("eachSeries", item);
    //    list2[item] = new NetClient(HOST, item, fn);
    //    //fn(null);
    //}, function(err) {
    //    console.log("async.eachSeries cb", err);
    //});

    var client = new NetClient(HOST, PORT);
}

function test2() {
    console.log("\n test2 \n");

    var func;
    func = function() {
        var s = "www.google.com";
        dns.resolve4(s, function (err, addresses) {
            console.log(s, err, addresses);
        } );
    };
    func();

    func = function() {
        var s = "www.baidu.com";
        dns.resolve4(s, function (err, addresses) {
            console.log(s, err, addresses);
        } );
    };
    func();

    func = function() {
        var s = "www.taobao.com";
        dns.resolve4(s, function (err, addresses) {
            console.log(s, err, addresses);
        } );
    };
    func();
}

function test3() {
    console.log("\n test3 \n");

    //console.log(http);
//    STATUS_CODES:
//    { '100': 'Continue',
//        '101': 'Switching Protocols',
//        '102': 'Processing',
//        '200': 'OK',
//        '201': 'Created',
//        '202': 'Accepted',
//        '203': 'Non-Authoritative Information',
//        '204': 'No Content',
//        '205': 'Reset Content',
//        '206': 'Partial Content',
//        '207': 'Multi-Status',
//        '300': 'Multiple Choices',
//        '301': 'Moved Permanently',
//        '302': 'Moved Temporarily',
//        '303': 'See Other',
//        '304': 'Not Modified',
//        '305': 'Use Proxy',
//        '307': 'Temporary Redirect',
//        '400': 'Bad Request',
//        '401': 'Unauthorized',
//        '402': 'Payment Required',
//        '403': 'Forbidden',
//        '404': 'Not Found',
//        '405': 'Method Not Allowed',
//        '406': 'Not Acceptable',
//        '407': 'Proxy Authentication Required',
//        '408': 'Request Time-out',
//        '409': 'Conflict',
//        '410': 'Gone',
//        '411': 'Length Required',
//        '412': 'Precondition Failed',
//        '413': 'Request Entity Too Large',
//        '414': 'Request-URI Too Large',
//        '415': 'Unsupported Media Type',
//        '416': 'Requested Range Not Satisfiable',
//        '417': 'Expectation Failed',
//        '418': 'I\'m a teapot',
//        '422': 'Unprocessable Entity',
//        '423': 'Locked',
//        '424': 'Failed Dependency',
//        '425': 'Unordered Collection',
//        '426': 'Upgrade Required',
//        '428': 'Precondition Required',
//        '429': 'Too Many Requests',
//        '431': 'Request Header Fields Too Large',
//        '500': 'Internal Server Error',
//        '501': 'Not Implemented',
//        '502': 'Bad Gateway',
//        '503': 'Service Unavailable',
//        '504': 'Gateway Time-out',
//        '505': 'HTTP Version Not Supported',
//        '506': 'Variant Also Negotiates',
//        '507': 'Insufficient Storage',
//        '509': 'Bandwidth Limit Exceeded',
//        '510': 'Not Extended',
//        '511': 'Network Authentication Required' },

//console.log(http.ClientRequest);

    //var options = {};
//options.host = "127.0.0.1";
//options.port = 1234;
//options.method = "GET";
//options.path = "/";
//var req = new http.ClientRequest(options);
//req.setHeader("X", "hello");
//req.sendDate = true;
//req.on('error', function(e) {
//    console.log(e);
//});
//console.log("", req._header, typeof req._header, !!req._header);
//console.log("_headers = ", req._headers);
//console.log("_headerNames = ", req._headerNames);
//console.log("_renderHeaders = ", req._renderHeaders());
//string false
//_headers =  { host: '127.0.0.1:1234', x: 'hello' }
//_headerNames =  { host: 'Host', x: 'X' }
//_renderHeaders =  { Host: '127.0.0.1:1234', X: 'hello' }

//req.end();
//
//console.log("", req._header, typeof req._header, !!req._header);
//GET / HTTP/1.1
//Host: 127.0.0.1:1234
//X: hello
//Date: Sun, 16 Aug 2015 10:26:19 GMT
//Connection: keep-alive
// string true

}


function test4() {
    console.log("\n test4 \n");

    //var req2 = http.request(options, function (res) {
//    console.log('STATUS: ' + res.statusCode);
//    console.log('HEADERS: ' + JSON.stringify(res.headers));
//    res.setEncoding('utf8');
//    res.on('data', function (chunk) {
//        console.log('BODY: ' + chunk);
//    });
//});
//req2.on('error', function (e) {
//    console.log('problem with request: ' + e.message);
//});
//req2.end();

}

//////////////////////////////////////////////////


function test_net() {
    test1();
    //test2();
    //test3();
    //test4();
}

test_net();





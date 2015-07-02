
var async = require("../modules/async");

async.waterfall([  // 回调参数的个数必须等于下一层的参数个数， 参数传递过程是对号入座，传递个数不对导致cb异常
    function(cb){
        cb(null, 1, 2);
    },
    function(arg1, arg2, cb){
        console.log("waterfall", arg1, arg2);
        cb(null, 3, 4, 0);
    },
    function(arg1, arg2, arg3, cb){
        console.log("waterfall", arg1, arg2, arg3);
        cb(null, 5);
    },
    function(arg4, cb){
        console.log("waterfall", arg4);
        cb(null);
    }
], function(err){
    console.log("async.waterfall cb", err);
});

async.eachSeries([1,3,2], function(item, fn) {  // 执行错误，后续停止执行
    console.log("eachSeries", item);
    fn(null);
    }, function(err) {
    console.log("async.eachSeries cb", err);
});

async.each([1,3,2], function(item, fn) {  // 执行错误，后续继续执行
    console.log("each", item);
    fn(null);
}, function(err) {
    console.log("async.each cb", err);
});

async.series([  // 会搜集返回值
        function(cb){
            cb(null, 1);
        },
        function(cb){
            cb(null, 1, [2, 3]);
        },
        function(cb){
            cb(null);
        }
], function(err, results){
    console.log("async.series cb", err,  results);
});

var async = require("../modules/async");

async.waterfall([  // 回调参数的个数必须等于下一层的参数个数， 参数传递过程是对号入座，传递个数不对导致cb异常
    function(fn){
        fn(null, 1, 2);
    },
    function(arg1, arg2, fn){
        console.log("waterfall", arg1, arg2);
        fn(null, 3, 4, 0);
    },
    function(arg1, arg2, arg3, fn){
        console.log("waterfall", arg1, arg2, arg3);
        fn(null, 5);
    },
    function(arg4, fn){
        console.log("waterfall", arg4);
        fn(null);
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
        function(fn){
            fn(null, 1);
        },
        function(fn){
            fn(null, 1, [2, 3]);
        },
        function(fn){
            fn(null);
        }
], function(err, results){
    console.log("async.series cb", err,  results);
});
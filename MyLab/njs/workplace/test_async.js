
var async = require("../modules/async");

async.waterfall([  // �ص������ĸ������������һ��Ĳ��������� �������ݹ����ǶԺ����������ݸ������Ե���cb�쳣
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

async.eachSeries([1,3,2], function(item, fn) {  // ִ�д��󣬺���ִֹͣ��
    console.log("eachSeries", item);
    fn(null);
    }, function(err) {
    console.log("async.eachSeries cb", err);
});

async.each([1,3,2], function(item, fn) {  // ִ�д��󣬺�������ִ��
    console.log("each", item);
    fn(null);
}, function(err) {
    console.log("async.each cb", err);
});

async.series([  // ���Ѽ�����ֵ
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
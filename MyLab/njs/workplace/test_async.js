
var async = require("../modules/async");

async.waterfall([  // �ص������ĸ������������һ��Ĳ��������� �������ݹ����ǶԺ����������ݸ������Ե���cb�쳣
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
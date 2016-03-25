var mongoose = require('mongoose');
var async = require('async');
var logger = require('pomelo-logger').getLogger(__filename);

var initMongoose = function (config) {
    // 在这里决定进程共用一个连接或每个collection一个连接
    var res = 'mongodb://' + config.host + ':' + config.port + '/' + config.database;
    var options = {
        user: config.user,
        pass: config.pass
    }
    async.series([
        function (callback) {
            mongoose.connect(res, options, callback);
        }
    ], function (err) {
        if (err) {
            logger.error(err);
        }
    });

    //mongoose.createConnection('mongodb://127.0.0.1:27017/NodeJS');
};

module.exports.initMongoose = initMongoose;
module.exports.mongoose = mongoose;
/**
 * Created by tweyseo on 2015/6/30.
 */


var SQLClient = require('./../mysql/mysql');


var mySQLClient = {};

var initMySQL = function(dbName, config) {
    mySQLClient[dbName] = new SQLClient(config);
};

var getMySQLClient = function(dbName) {
    return mySQLClient[dbName];
};

module.exports.initMySQL = initMySQL;
module.exports.getMySqlClient = getMySQLClient;


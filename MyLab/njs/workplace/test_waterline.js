
process.env.LOG_QUERIES = 'true'; //是否显示sql语句
var ormMgr = require("./orm");
var utilEx = require("./util/utilEx");
var async = require("async");
var Waterline = require('waterline');

console.log(ormMgr);

var orm = null;

var LoadData = function(mod, attr, isCreate, cb) {
    if ( "function" == typeof isCreate ) {
        cb = isCreate;
        isCreate = false;
    }
    var Dao = orm.collections[mod];
    if (!Dao) {
        cb(new Error("no found dao"));
        return;
    }

    if (!isCreate) {
        Dao.find(attr).exec(function(err, res) {
            var data = null;
            if ( !err ) {
                if ( !res || res.length > 1 ) {
                    err = new Error("data length error " + JSON.stringify(res) );
                }else {
                    data = res[0];
                }
            }
            cb(err, data);
        });
    }else {
        Dao.findOrCreate(attr).exec(function(err, data) {
            if (!err) {
                if (!data) {
                    err = new Error("no data");
                }
            }
            cb(err, data);
        });
    }

};

var LoadDataList = function(mod, attr, cb) {
    var Dao = orm.collections[mod];
    Dao.find(attr).exec(function(err, list) {
        if ( !err && !list ) {
            list = [];
        }
        cb(err, list);
    });
};

var testAttributes = {
    name: 'string',
    time: {type: 'datetime', defaultsTo: new Date()},
    list: {type: 'array', defaultsTo: []}
};

var testCollection = Waterline.Collection.extend({
    identity: 'testtbl',
    connection: 'default',
    attributes: testAttributes
});

var createAttributes = function() {
    var sink = {};
    utilEx.doEachEx(testAttributes, function(key, item) {
        if ( item && item.defaultsTo ) {
            sink[key] = item.defaultsTo;
        }
    });
    return sink;
};

ormMgr.orm.loadCollection(testCollection);

ormMgr.init(function(err,models) {
    //console.log(arguments);
    orm = models;

    var User = orm.collections.user;
    var Hero = orm.collections.hero;
    var MatchRecord = orm.collections.matchrecord;
    var LadderRank = orm.collections.ladderrank;

    if (false) {
        User.findOneBy_id("56c97fc3d70301c188a29d2a#1").exec(function (err, data) {
            console.log(arguments);
        });

        User.findOne({ _id: "56c97fc3d70301c188a29d2a#1" }).exec(function(err, users) {
            console.log(arguments);
        });

        User.find({ _id: "56c97fc3d70301c188a29d2a#1" }).exec(function(err, users) {
            console.log(arguments);
        });

        User.findOne({ _id: "56c97fc3d70301c188a29d2a#1" }).exec(function(err, users) {
            console.log(arguments);
        });

        User.findOrCreate({ _id: "123" }).exec(function(err, users) {
            console.log(arguments);
        });

        MatchRecord.update({ _id: "123456", mode: 2 }, {total: 101}).exec(function() {
            console.log(arguments);
        });

        MatchRecord.update({ _id: "123456", mode: 1 }, {total: 101}).then(function() {
            console.log(arguments);
        });

        MatchRecord.findOrCreate({ uid: "123456", mode: 1 }).exec(function() {
            console.log(arguments);
        });
        MatchRecord.findOrCreate({ uid: "123456", mode: 2 }).exec(function() {
            console.log(arguments);
        });
        MatchRecord.find({ uid: "123456" }).exec(function() {
            console.log(arguments);
        });

        LoadData("matchrecord", { uid: "123456", mode: 1 }, function() {
            console.log(arguments);
        });

        LoadData("matchrecord", { uid: "123456", mode: 13 }, true, function() {
            console.log(arguments);
        });

        LoadDataList("matchrecord", { uid: "123456"}, function() {
            console.log(arguments);
        });

        LadderRank.query("DELETE FROM matchrecord", function() {
            console.log(arguments);
        });

        //var sql = "SELECT * FROM hero WHERE owner = " + "\"" + item._id + "\"";  console.log("sql = ", sql);

    }

    var TestTbl = orm.collections.testtbl;
    console.log(createAttributes());
    //TestTbl.findOrCreate({ name: "a8" }).exec(function(err, res) {
    //    var date = res.time;
    //    console.log(res);
    //});

});




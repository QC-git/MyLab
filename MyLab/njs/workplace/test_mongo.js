
var Mongoose = require("mongoose")
    , Schema = Mongoose.Schema
    , ObjectId = Mongoose.Types.ObjectId;


var loadSchemeByKey = function(Mod, key, isCreate, cb) {
    if ( !cb && "function" === typeof isCreate ) {
        cb = isCreate;
        isCreate = true;
    }
    Mod.findById(key, function(err, scheme) {
        if (err) {
            cb(err);
        } else if (!scheme) {
            if (!isCreate) {
                cb(new Error("loadSchemeById fail, no scheme"));
            }else {
                //console.log("loadSchemeById, new Mod", id);
                var mod = new Mod({_id: key});
                mod.save(function(err, scheme) {
                    if ( err || !scheme ) {
                        cb(new Error("loadSchemeById fail, new Mod, err:" + err ));
                    }else {
                        cb(null, scheme);
                    }
                })
            }
        } else {
            cb(null, scheme);
        }
    })
};

var loadSchemeByAttr = function(Mod, attr, isCreate, cb) {
    if ( !cb && "function" === typeof isCreate ) {
        cb = isCreate;
        isCreate = true;
    }

    Mod.findOne(attr, function(err, scheme) {
        if (err) {
            cb(err);
        } else if (!scheme) {
            if (!isCreate) {
                cb(new Error("loadSchemeByType fail, no scheme"));
            }else {
                console.log("loadSchemeByType, new Mod", attr);
                var mod = new Mod(attr);
                mod.save(function(err, scheme) {
                    if ( err || !scheme ) {
                        cb(new Error("loadSchemeByType fail, new Mod, err:" + err ));
                    }else {
                        cb(null, scheme);
                    }
                })
            }
        } else {
            cb(null, scheme);
        }
    })
};

var loadSchemeList = function(Mod, params, cb) {
    var query = Mod.find(params.condition, params.find);
    query.limit(params.limit);
    query.sort(params.sort);
    query.exec(cb);
};

var initMongoose = function(Handle, config, cb) {
    var res = 'mongodb://' + config.host +":" + config.port + "/" + config.database;
    Handle.connect(res, cb);
};

////////////////////////////////////////////////////////

require('./util_lp/global');
var async = require("async");
var util  = require("./test_util");
var UserModel = depInj("dao", "userSchema").Model;
var utilEx  =  depInj("utilEx");

async.waterfall([
    function(cb){
        var dbConfig = {
            "host" : "192.168.243.21"
            , "port" : "27017"
            , "database" : "myCos"
            , "user" : "1"
            , "password" : "1"
        };
        initMongoose(Mongoose, dbConfig, function(err) {
            console.log("initMongoose, err = ", err);
            cb(err);
        });
    },

    //{condition: {"rankScore": {$gt: 1200}}, find:{name: 1, "matchRecord.mode": 1, "matchRecord.total": 1, "matchRecord.victory": 1, "rankScore": 1}, limit:100, sort:{"rankScore": -1}

    //db.user.find({ lastLoginTime: {$gt: ISODate("2016-03-25T0:0:0.788+08:00")} })

    //db.user.count({ lastLoginTime: {$gt: ISODate("2016-03-25T0:0:0+08:00")} })

    //E:\QC-nd\db\cos-env\DEV_ENV\mongodb\bin>mongorestore -h 127.0.0.1 -d myCos  --directoryperdb cosLegend

    function(cb) {
        var date1 = new Date();
        date1.setMonth(2);
        date1.setDate(25);

        var date2 = new Date();
        date2.setMonth(2);
        date2.setDate(18);

        var query = UserModel.find({}, {lastLoginTime: 1});

        console.log(date1);
        console.log(date2);

        var limitTime1 = date1.getTime();
        var limitTime2 = date2.getTime();

        var count1 = 0;
        var count2 = 0;

        query.exec(function(err, list) {
            console.log(list.length);
            utilEx.doEach(list, function(i, item) {
                //console.log(item.lastLoginTime);
                var loginTime = item.lastLoginTime.getTime();
                if ( loginTime > limitTime1 ) {
                    count1++;
                }
                if ( loginTime > limitTime2 ) {
                    count2++;
                }

            });
            console.log("count = ", count1, count2);
        });
        cb(null);
    }
], function(err){
    console.log("async.waterfall cb", err);
});




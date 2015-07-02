
var mongoose = require("../modules/mongoose")
    , Schema = mongoose.Schema
    , ObjectId = mongoose.Types.ObjectId;

//console.log("mongoose = ", mongoose);
//console.log("Schema = ", Schema);
//console.log("ObjectId = ", ObjectId);


var Comment = new Schema();

Comment.add({
    title     : { type: String, index: true }
    , date      : Date
    , body      : String
    , comments  : [Comment]
});

var BlogPost = new Schema({
    title     : { type: String, index: true }
    , slug      : { type: String, lowercase: true, trim: true }
    , date      : Date
    , buf       : Buffer
    , comments  : [Comment]
    , creator   : Schema.ObjectId
});

var Person = new Schema({
    name: {
        first: String
        , last : String
    }
    //, email: { type: String, required: true, index: { unique: true, sparse: true } }
    , alive: Boolean
    , num0 : {type: Number, default: 0}
    , num1 : {type: Number, default: 1}
    , type : {type: Number, default: 0}
}, {collection: "person", versionKey:false});

Person.statics.findByType = function(type, cb) {
    this.findOne({type: type}, cb);
};

mongoose.model('BlogPost', BlogPost);
var PersonModel = mongoose.model("person", Person);

var loadSchemeById = function(id, Mod, isCreate, cb) {
    if ( !cb && "function" === typeof isCreate ) {
        cb = isCreate;
        isCreate = true;
    }
    Mod.findById(id, function(err, scheme) {
        if (err) {
            cb(err);
        } else if (!scheme) {
            if (!isCreate) {
                cb(new Error("loadSchemeById fail, no scheme"));
            }else {
                console.log("loadSchemeById, new Mod", id);
                var mod = new Mod({_id: id});
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

var loadSchemeByAttr = function(attr, Mod, isCreate, cb) {
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

var dbConfig = {
    "host" : "127.0.0.1"
    , "port" : "27017"
    , "database" : "test"
    , "user" : "1"
    , "password" : "1"
};
var initMongoose = function(config) {
    var res = 'mongodb://' + config.host +":" + config.port + "/" + config.database;
    mongoose.connect(res, function(err) {
        console.log("mongoose.connect cb ", err);
    });
};
initMongoose(dbConfig);

var strId;

var TABLE_NAME_1 = "person1";

var Person1 = new Schema({
    map: {type: Schema.Types.Mixed},
    vec: [Schema.Types.Mixed],
    num: Schema.Types.Mixed,
    list:
    [
         {
             data1: Schema.Types.Mixed,
             data2: Number
         }
    ]

}, {collection: TABLE_NAME_1, versionKey:false});
var PersonModel1 = mongoose.model(TABLE_NAME_1, Person1);


var TABLE_NAME_2 = "person2";
var Person2 = new Schema({
    id_1: Number,
    id_2: String,
    id_3: Number
}, {collection: TABLE_NAME_2, versionKey:false});
var PersonModel2 = mongoose.model(TABLE_NAME_2, Person2);

////////////////////////////////////////////////////////

var async = require("../modules/async");

async.waterfall([  // 回调参数的个数必须等于下一层的参数个数， 参数传递过程是对号入座，传递个数不对导致cb异常
    //function(cb){
    //    console.log("\n-----------------1");
    //    strId = "800000008000000080000001";
    //    loadSchemeById(strId, PersonModel, function(err, scheme) {
    //        console.log("loadSchemeById cb", err, scheme);
    //        cb(null);
    //    });
    //},
    //function(cb){
    //    console.log("\n-----------------2");
    //    strId = "800000008000000080000002";
    //    loadSchemeByAttr({}, PersonModel, function(err, scheme) {
    //        console.log("loadSchemeByType cb", err, scheme);
    //        cb(null);
    //    });
    //},
    //function(cb){
    //    console.log("\n-----------------3");
    //    strId = "800000008000000080000003";
    //    loadSchemeById(strId, PersonModel1, function(err, scheme) {
    //        console.log("loadSchemeById cb", err, scheme);
    //
    //        var map = {};
    //        map[1] = 111;
    //        tmp = {};
    //        map[9] = tmp;
    //        tmp.a = "a";
    //        tmp.b = "b";
    //
    //        var vec = [];
    //        vec.push(1);
    //        vec.push(2);
    //
    //        scheme.map = map;
    //        scheme.vec = vec;
    //        scheme.num = 1;
    //        var item = scheme.list[0];
    //        if (!item) {
    //            scheme.list.push({data1:{}, data2: 2});
    //        }
    //
    //        scheme.save(function(err) {
    //            console.log("scheme.save, strId = " + strId + ", err: " + err);
    //            cb(null);
    //        });
    //    });
    //},
    //function(cb){
    //    console.log("\n-----------------4");
    //    strId = "800000008000000080000003";
    //    loadSchemeById(strId, PersonModel1, function(err, scheme) {
    //        console.log("loadSchemeById cb", err, scheme);
    //
    //        scheme.markModified('map');
    //        scheme.markModified('vec');
    //        //scheme.markModified('list.data1');
    //
    //        var map = scheme.map;
    //        var vec = scheme.vec;
    //
    //        map[6] = 6666;
    //        vec.push(5);
    //
    //        var tmp = map[9];
    //        tmp.b = 2;
    //        tmp.c = "c";
    //
    //        //vec[100] = 100;
    //        scheme.num += 2;
    //        //console.log("map = " + map + ", vec = " + vec);
    //
    //        var item = scheme.list[0];
    //        var data1 = item.data1;
    //        if ( !data1 ) {
    //            item.markModified("data1");
    //
    //            data1 = item.data1 = {};
    //            data1.a = 0;
    //            data1.b = {};
    //            data1.b.c = 0;
    //        } else {
    //            item.markModified("data1");
    //        }
    //        data1.a += 1;
    //        data1.b.c += 1;
    //
    //        item.data2 += 1;
    //
    //        scheme.save(function(err) {
    //            console.log("scheme.save, strId = " + strId + ", err: " + err);
    //            cb(null);
    //        });
    //    });
    //},
    //function(cb){
    //    console.log("\n-----------------5");
    //    loadSchemeById(strId, PersonModel1, function(err, scheme) {
    //        console.log("loadSchemeById cb", err, scheme, "\n++++", scheme.list[0].data1);
    //        cb(null);
    //    });
    //},
    function(cb){
        console.log("\n-----------------6");
        var attr = {id_1:1, id_2:"2", id_3: 3};
        loadSchemeByAttr(attr, PersonModel2, function(err, scheme) {
            console.log("loadSchemeByAttr cb", err, scheme);
            cb(null);
        });
    }
], function(err){
    console.log("async.waterfall cb", err);
});
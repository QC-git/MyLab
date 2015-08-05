
var Mongoose = require("../modules/mongoose")
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

/////////////////////////////////////////����///////////////////////////////////////////
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

Mongoose.model('BlogPost', BlogPost);
var PersonModel = Mongoose.model("person", Person);


var strId;

var TABLE_NAME_2 = "person2";
var Person2 = new Schema({
    id_1: Number,
    id_2: String,
    id_3: {type: Number, default: -1},
    id_4: Schema.Types.Mixed
}, {collection: TABLE_NAME_2, versionKey:false});
var PersonModel2 = Mongoose.model(TABLE_NAME_2, Person2);

var TABLE_NAME_1 = "person1";

var Person1_1 = new Schema({
    a: Number
});

var PersonModel1_1 = Mongoose.model("", Person1_1);

var Person1 = new Schema({
    map: {type: Schema.Types.Mixed},
    vec: [Schema.Types.Mixed],
    mix: Schema.Types.Mixed,
    num: {type: Number, default: -1},
    list: [
         {
             data1: Schema.Types.Mixed,
             data2: {type: Number, default: -1}
         }
    ],
    map2: {
        data1: Number,
        data2: Number
        //data3: Person1_1
    },
    person1: [Person1_1]

   // person2: {type: Person2}

}, {collection: TABLE_NAME_1, versionKey:false});

Person1.statics.func = function() {
    console.log("Person1.statics.func");
};

Person1.methods.func1 = function() {
    console.log("PersonModel1.methods.func1");
};

Person1.methods.func2 = function() {
    console.log("PersonModel2.methods.func2");
    this.func1();
};

var PersonModel1 = Mongoose.model(TABLE_NAME_1, Person1);



////////////////////////////////////////////////////////

var async = require("../modules/async");
var util  = require("./test_util");

async.waterfall([  // �ص������ĸ������������һ��Ĳ��������� �������ݹ����ǶԺ����������ݸ������Ե���cb�쳣
    function(cb){   // ��ʼ�����ݿ�
        var dbConfig = {
            "host" : "127.0.0.1"
            , "port" : "27017"
            , "database" : "test"
            , "user" : "1"
            , "password" : "1"
        };

        initMongoose(Mongoose, dbConfig, function(err) {
            console.log("1, initMongoose, err = ", err);
            cb(err);
        });
    },
    //function(cb){  // ��ʼ���������
    //    util.doRepeat(100, function(i) {
    //        var obj = new ObjectId();
    //        loadSchemeById(PersonModel2, obj, function(err, scheme) {
    //            console.log("2, loadSchemeById cb", err, scheme);
    //            scheme.id_1 = i;
    //            scheme.id_2 = i*10;
    //            scheme.id_3 = i*100;
    //            scheme.id_4 = {};
    //            scheme.id_4.id_4_1 = i*1000;
    //            scheme.id_4.id_4_2 = i*10000;
    //            scheme.save(function(err) {
    //                if (err) {
    //                    console.log("scheme.save fail, err = ", err);
    //                    return;
    //                }
    //
    //                if ( 100 == i ) {
    //                    cb(null);
    //                }
    //
    //            });
    //
    //        });
    //    });
    //},
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
    function(cb){
        console.log("\n-----------------5");
        loadSchemeByKey(PersonModel1, "800000008000000080000004", function(err, scheme) {
            console.log("loadSchemeById cb", err, scheme);

            var obj = new PersonModel1_1();
            scheme.person1.push(obj);

            obj.a = 999;

            console.log(obj);
            console.log(scheme.person1);

            var p1 = scheme.person1[0];
            var p2 = scheme.person1[1];

            p1.a =9999999;
            p2.a =9999999;

            console.log(scheme.person1);
            //scheme.list.push({data2: 111111});
            //scheme.list.push({data2: 222222});
            //var mark = 0;
            //scheme.list[mark].data2 = mark + 1;
            //scheme.save(function() {});
            //util.doEach(scheme.list, function(i, item) {
            //    var data = {};
            //    //data = item;
            //    console.log("");
            //});
            //scheme.func2();
            cb(null);
        });
    }
    //function(cb){
    //    console.log("\n-----------------5-1");
    //    loadSchemeList(PersonModel1, {condition: {"list.data2": {$gt:0}}, find:{}, limit:1000, sort:{}}, function(err, list) {
    //        console.log("loadSchemeList cb", err, list.length, list);
    //        //var item = list[1];
    //        //item.list[1].data2 +=10;
    //        //item.map2.data1 = 2;
    //        ////list[0].markModified("list");
    //        //console.log("item = ", item);
    //        //
    //        //list[0].list.push({});
    //        //item.person1.push({});
    //        //item.save(function(err){console.log(err)});
    //
    //        //var p1 = item.person1[0];
    //        //p1.a = 2;
    //        //p1.save(function(err){console.log(err)});
    //        //item.save(function(err){console.log(err)});
    //
    //        cb(null);
    //    });
    //}
    //function(cb){
    //    console.log("\n-----------------6");
    //    var attr = {id_1:1, id_2:"2", id_3: 3};
    //    loadSchemeByAttr(PersonModel2, attr, function(err, scheme) {
    //        console.log("6, loadSchemeByAttr cb", err, scheme);
    //        cb(null);
    //    });
    //}
    //function(cb){
    //        console.log("\n-----------------7");
    //        loadSchemeList(PersonModel2, {"id_3":1, "id_4.id_4_2":1  }, 1, {"id_4.id_4_2": -1}, function(err, results) {
    //            console.log("7, err = ", err, ", results = ", results);
    //            //var data = util.cloneByAttr(results[0], {"id_1":3, "id_4.id_4_2":1});
    //            //console.log("7, err = ", err, ", data = ", data);
    //            cb(null);
    //        })
    //    }
], function(err){
    console.log("async.waterfall cb", err);
});
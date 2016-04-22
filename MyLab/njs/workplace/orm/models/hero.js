(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'hero',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            hid: {type: 'integer'},            //hero id
            name: {type: 'string'},
            level: {type: 'integer', defaultsTo: 1},          //等级
            exp: {type: 'integer', defaultsTo: 0},              //经验
            quality: {type: 'integer', defaultsTo: 1},        //品质
            debris: {type: 'integer', defaultsTo: 0},         //碎片数量
            skinIds: {type: 'array'},
            type: {type: 'integer', defaultsTo: 1}, //0： 未拥有的英雄， 1：普通英雄， 2：契约英雄
            expireTime: {type: 'datetime'}, //契约英雄过期时间

            // Add a reference to User
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

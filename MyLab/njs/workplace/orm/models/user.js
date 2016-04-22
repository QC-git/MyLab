(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'user',
        attributes: {
            _id: {type: 'string', primaryKey: true, required: true}, //生成规则为accountId+'#'+areaId
            areaId: {type: 'integer', defaultsTo: 1},           //区号
            name: {type: 'string', unique: true},
            sex: {type: 'integer', defaultsTo: 0},             //性别
            head: {type: 'string', defaultsTo: ''},            //头像
            level: {type: 'integer', defaultsTo: 1},
            exp: {type: 'integer', defaultsTo: 0},             //经验
            gold: {type: 'integer', defaultsTo: 0},             //金币
            ingot: {type: 'integer', defaultsTo: 0},             //元宝
            vipLvl: {type: 'integer', defaultsTo: 0},
            shopPoint: {type: 'integer', defaultsTo: 0},      //商店积分

            serialNumber: {type: 'string'},      // 最后登录设备序列号
            ip: {type: 'string'},                // 最后登录ip
            createTime: {type: 'datetime', defaultsTo: new Date()},
            lastLoginTime: {type: 'datetime', defaultsTo: new Date()},
            lastLogoutTime: {type: 'datetime', defaultsTo: new Date()},

            rankScore: {type: 'integer', defaultsTo: 1200},      // 匹配赛分数
            maxRankScore: {type: 'integer', defaultsTo: 1200},      // 最大匹配赛分数
            ladderScore: {type: 'integer', defaultsTo: 1200},    // 排位赛分数
            maxLadderScore: {type: 'integer', defaultsTo: 1200},    // 最大排位赛分数
            tutorialInfo: {type: 'integer', defaultsTo: 0},      // 新手任务

            matchNegativeTime: {type: 'datetime', defaultsTo: new Date()},　　// 匹配消极时间
            matchNegativeCount: {type: 'integer', defaultsTo: 0},       // 匹配消极次数

            loginVersion: {type: 'string', defaultsTo: ''},              //当前登陆版本

            heros: {
                collection: 'hero',
                via: 'owner'
            },
            herorecequips: {
                collection: 'herorecequip',
                via: 'owner'
            },
            items: {
                collection: 'item',
                via: 'owner'
            },
            talents: {
                collection: 'talent',
                via: 'owner'
            },
            friends: {
                collection: 'friend',
                via: 'owner'
            },
            matchrecords: {
                collection: 'matchrecord',
                via: 'owner'
            }
        }
    };

    module.exports = Model;
})();

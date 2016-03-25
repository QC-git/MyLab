/**
 * Created by Lingg on 2015/7/20.
 */


(function () {
    'use strict';
    require('././global');

    var mongoose = require('./mongoose').mongoose;
    var skillCfg = depInj('tpl', 'skill');
    var ec = depInj('ec');

    var itemSchema = require('./itemSchema').schema;
    var Schema = mongoose.Schema;

    var HeroSchema = new Schema({
        //_id is serial
        hid: {type: Number},            //hero id
        //uid: {type: String},          //user id
        name: {type: String},
        skinIds: [Number],
        level: {type: Number, default: 1, max: 255},
        skills: {
            type: [
                {id: Number, level: {type: Number, default: 1}}
            ],
            default: []
        },
        exp: {type: Number, default: 0},
        items: [itemSchema],
        quality: {type: Number, default: 1},        //品质
        debris: {type: Number, default: 0},         //碎片数量
        teamPos: {type: Number, default: 0},        // 出阵位置
        step: {                                     // 徽章
            level:{type:Number,default:0},
            badges:{type: String, default: '000000'}
        }
    }, {versionKey: false});

    HeroSchema.statics.findByUser_HeroId = function(uid, hid, cb) {
        this.findOne({hid: hid, uid: uid}, cb);
    };

    HeroSchema.statics.findByUserId = function(uid, cb) {
        this.find({uid: uid}, cb);
    };

    HeroSchema.methods.addSkill = function (skillId, cb) {
        if (this.hasSkill(skillId)) {
            cb(ec.Hero.HasSkill);
            return ;
        }
        this.skills.push({id: skillId});
        cb(ec.OK, this.skills);
    };

    HeroSchema.methods.addExp = function (expValue, cb) {
        cb(ec.OK);
    };

    HeroSchema.methods.upgradeSkill = function (skillId, cb) {
        var skillUpgrade = skillCfg.upgrade;
        var len = this.skills.length;
        for (var i = 0; i < len; ++i) {
            if (this.skills[i].id == skillId) {
                if (this.skills[i].level >= skillUpgrade.length) {
                    cb(ec.Hero.LevelMax);
                } else {
                    this.skills[i].level += 1;
                    cb(ec.OK, this.skills);
                }
                return ;
            }
        }
        cb(ec.Hero.NoSkill);
    };

    HeroSchema.methods.hasSkill = function (skillId) {
        var len = this.skills.length;
        for (var i = 0; i < len; ++i) {
            if (this.skills[i].id == skillId) {
                return true;
            }
        }
        return false;
    };

    module.exports.schema = HeroSchema;
    module.exports = mongoose.model('hero', HeroSchema);
})();

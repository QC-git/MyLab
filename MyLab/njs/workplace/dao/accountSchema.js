var mongoose = require('./mongoose').mongoose;
var Schema = mongoose.Schema;
var ObjectId = mongoose.Types.ObjectId; // not Schema.Types.ObjectId;
var utils = require('pomelo/lib/util/utils');

var AccountQQSchema = new Schema({
    //_id就是uid
    //_id : { type: ObjectId, index: true, unique: true, default: new mongoose.Types.ObjectId()},
    openId: String,
    openKey: String,
    pf: String,                              // 唤起平台_账号体系-注册渠道-操作系统-安装渠道-账号体系-appid-openid.例如：desktop_m_qq-73213123-android-73213123-qq-100703379-A65A1614A2F930A0CD4C2FB2C4C5DBE1
    cid: {type: String, default: ''},       // 自定义id, 用于绑定工号 或 客户端短号
    testKey: {type: String, default: ''},   // 体验密码
    time: Number
}, {versionKey: false});

AccountQQSchema.statics.findById = function (uid, cb) {
    this.findOne({_id: ObjectId(uid)}, cb);
};

AccountQQSchema.statics.findByOpenId = function (openId, cb) {
    this.findOne({openId: openId}, cb);
};

AccountQQSchema.statics.updateOrAddByOpenId = function (conditions, fields, cb) {
    this.findOneAndUpdate(conditions, {$set: fields}, {upsert: true, "new": true}, cb);
};

var accountQQModel = mongoose.model('account', AccountQQSchema);

//

module.exports.updateOrAddQQAccount = function (conditions, fields, cb) {
    accountQQModel.updateOrAddByOpenId(conditions, fields, function (err, res) {
        if (err) {
            logger.warn('local auth DB error: ' + err);
            utils.invokeCallback(cb, ec.DB_Err);
            return;
        }

        if (!res) {
            logger.warn('update or add failed.');
        }
        utils.invokeCallback(cb, err, res);
    })
};
module.exports.Model = accountQQModel;
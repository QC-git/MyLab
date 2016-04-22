(function () {
    'use strict';
    var utils = depInj('utils');
    var Mod = function () {
    };
    var prop = Mod.prototype;

    prop.findAndCreate = function (_id, cb) {
        var taskOrm = orm.collections.task;
        taskOrm.findOneBy_id(_id).exec(function (err, data) {
            if (err) {
                logger.warn('get task err,', _id, err);
            }
            if(!data){
                taskOrm.create({_id:_id},function(err,data){
                    utils.invokeCallback(cb, err, data);
                });
                return;
            }
            utils.invokeCallback(cb, err, data);
        });
    }
    prop.update = function(conditions,values,cb){
        var taskOrm = orm.collections.task;
        var _id = conditions._id;
        var version = conditions.version;
        var nextVersion = version+1;
        //taskOrm.update(conditions,values,cb);
        // todo 经测试waterling自带update没有实时修改数据库, 暂时采用原生查询解决乐观锁问题
        var queryStr = 'update task set version='+nextVersion+' where _id= "'+_id+'" and version = '+version;
        taskOrm.query(queryStr,function(err,data){
            //logger.info('=================',_id,version,queryStr, data);
            if(data && data.affectedRows){
                cb(null);
                return;
            }
            logger.warn(_id, 'check version(', version, ') lock Conflict',queryStr, data);
            cb(ec.Conflict);
        });
    };
    module.exports = new Mod();
})();
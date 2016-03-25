/**
 * Close connection pool.
 */

var SqlClient = function(opts) {
    this._pool = require('./dao-pool').createMysqlPool(opts);
};
module.exports = SqlClient;


SqlClient.prototype.insert = function(sql, args, cb){
    this.query(sql, args, cb);
};

SqlClient.prototype.update = function(sql, args, cb){
    this.query(sql, args, cb);
};

SqlClient.prototype.delete = function(sql, args, cb){
    this.query(sql, args, cb);
};

SqlClient.prototype.query = function(sql, args, cb){
    var self = this;
    query(self._pool, sql, args, cb);
};

/**
 * shutdown database
 */
SqlClient.prototype.shutdown = function() {
    this._pool.destroyAllNow();
};


/**
 * Excute sql statement
 * @param {String} sql Statement The sql need to excute.
 * @param {Object} args The args for the sql.
 * @param {fuction} cb Callback function.
 *
 */
var query = function(pool, sql, args, cb){
    pool.acquire(function(err, client) {
        if (!!err) {
            console.error('[sqlqueryErr] '+err.stack);
            return;
        }
        client.query(sql, args, function(err, res) {
            pool.release(client);
            cb(err, res);
        });
    });
};



var _poolModule = require('generic-pool');

/*
 * Create mysql connection pool.
 */
var createMysqlPool = function(opts) {
	return _poolModule.Pool({
		name: 'mysql',
		create: function(callback) {
			var mysql = require('mysql');
			var client = mysql.createConnection({
				host: opts.host,
				user: opts.user,
                port: opts.port,
				password: opts.password,
				database: opts.database
			});
			callback(null, client);
		},
		destroy: function(client) {
			client.end();
		},
		max: 10,
		idleTimeoutMillis : 30000,
		log : false
	});
};

exports.createMysqlPool = createMysqlPool;

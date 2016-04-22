(function () {
    'use strict';
    require('../util/global');
    var fs = require('fs');
    var Waterline = require('waterline');
    var orm = new Waterline();
    var mysqlAdapter = require('sails-mysql');
    var connection = {
        adapter: 'default',
        host: 'localhost',
        port: 3306,
        user: 'root',
        password: '',
        database: 'coslegend',
        // Optional
        charset: 'utf8',
        collation: 'utf8_swedish_ci',
        pool: true,
        connectionLimit: 20,
        waitForConnections: true
    };
    var options = {
        // Setup Adapters
        // Creates named adapters that have been required
        adapters: {
            'default': mysqlAdapter,
            mysql: mysqlAdapter
        },
        // Build Connections Config
        // Setup connections using the named adapter configs
        connections: {},
        defaults: {
            migrate: 'create'
        }
    };
    var defalutModel = {
        connection: 'default',
        //autoPK: false,
        autoCreatedAt: true,
        autoUpdatedAt: true
    };

    var init = function (cb) {
        fs.readdirSync(__dirname + '/models').forEach(function (filename) {
            if (/\.js$/.test(filename)) {
                var model = depInj('orm', 'models/' + filename);
                model = _.extend(defalutModel, model);
                var collection = Waterline.Collection.extend(model);
                orm.loadCollection(collection)
            }
        });
        //['user', 'hero'].forEach(function (def) {
        //    var model = depInj('dao', 'models/' + def);
        //    model = _.extend(defalutModel, model);
        //    var collection = Waterline.Collection.extend(model);
        //    orm.loadCollection(collection)
        //});
        var connectionName = defalutModel.connection;
        options.connections[connectionName] = connection;
        orm.initialize(options, function (err, models) {
            if (err) {
                logger.warn('orm database init fails!', err, options);
            }
            cb(err, models);
            logger.info('orm database init success!');
        });
    };

    var sync = function () {
        exports.init(function (err, ontology) {
            if (err) {
                return console.error(err);
            }
        });
    }
    //sync();
    module.exports.orm = orm;
    module.exports.init = init;
})();
(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'task',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true
            },
            dailyPoint: {type: 'integer', defaultsTo: 0},
            totalPoint: {type: 'integer', defaultsTo: 0},
            dailyList: {type: 'array',defaultsTo:[]},
            taskList: {type: 'array',defaultsTo:[]},
            mainTaskList: {type: 'array',defaultsTo:[]},
            taskLogs: {type: 'array',defaultsTo:[]},
            version: {type: 'integer', defaultsTo: 0},
            lastResetTime: {type: 'datetime', defaultsTo: new Date()},

            // Add a reference to User
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

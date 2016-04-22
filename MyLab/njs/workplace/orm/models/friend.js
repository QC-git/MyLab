/**
 * Created by shihuayang on 4/12/2016.
 */

(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'friend',
        //connection: 'default',
        //autoPK: false,
        //autoCreatedAt: true,
        autoUpdatedAt: true,
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },

            createTime: {type: 'datetime', defaultsTo: new Date()},

            fid: {
                model: 'user'
            },

            // Add a reference to User
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

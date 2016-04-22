(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'talent',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            name: {type: 'string'},

            gemGroups: {type:'json'},
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

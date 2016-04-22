(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'item',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            id: {type: 'integer'},
            type: {type: 'integer'},
            num: {type: 'integer', defaultsTo: 1},
            durability: {type: 'integer'},

            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

/**
 * Created by Lingg on 2016/4/15.
 */

(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'herorecequip',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            bsID: { type: 'integer' },
            rEquips: { type: 'array', defaultsTo: [-1, -1, -1, -1, -1, -1]},
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

/**
 * Created by shihuayang on 4/18/2016.
 */

(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'heroevaluate',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            hid: { type: 'integer' },
            evaluate: {type: 'integer', default: 0},
            evaluateLevel: {type: 'integer', default: 0, max: 30},
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

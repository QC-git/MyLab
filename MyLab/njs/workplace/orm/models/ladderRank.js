(function () {
    'use strict';
    var utils = depInj('utils');
    var Model = {
        identity: 'ladderrank',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },

            uid: {type: "string"},
            pos: {type: "integer", defaultsTo: 0},

            ladderScore: {type: "integer", defaultsTo: 0},

            name: {type: "string", defaultsTo: ""},
            head: {type: "string", defaultsTo: ""},

            total: {type: "integer", defaultsTo: 0},                   // �ܳ���
            victory: {type: "integer", defaultsTo: 0}                 // ʤ������

        }
    };

    module.exports = Model;
})();
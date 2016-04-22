/**
 * Created by Lingg on 2016/4/15.
 */

(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'signin',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true, defaultsTo: function () {
                    return utils.GenUuid();
                }
            },

            info: {
                type: 'array',
                defaultsTo: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]      //��ǩ����Ϣ ȡ���31��
            },

            accumulateDays: {type: 'integer', defaultsTo: 0},                     //�ۻ�ǩ������
            remedyDays:     {type: 'integer', defaultsTo: 0},                     //��ǩ����
            lastSignInTime: {type: 'integer', defaultsTo: 0},                     //���һ��ǩ��ʱ��

            awardReceive:   {                                   //�ۻ�ǩ��������ȡ
                type: 'array',
                defaultsTo: [0, 0, 0, 0, 0, 0, 0]},

            owner: {model: 'user'}
        }
    };

    module.exports = Model;
})();

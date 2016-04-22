/**
 * Created by Lingg on 2016/4/18.
 */


(function () {
    'use strict';
    var utils = depInj('utils');


    var Model = {
        identity: 'battle_record',
        attributes: {
            _id: {
                type: 'string', primaryKey: true, required: true,
                defaultsTo: function () {
                    return utils.GenUuid();
                }
            },
            uid:        {type: 'string'},
            heroId:     {type: 'integer'},             //ʹ��Ӣ��
            win:        {type: 'integer'},                //1: win  0:lose
            mode:       {type: 'string'},             //ս��ģʽ
            endTime:    {type: 'string'},            //����ʱ�� 2016.01.12 12:38
            exp:        {type: 'integer'},
            gold:       {type: 'integer'},               //�����õĽ��
            btTime:     {type: 'integer'},             //ս��ʱ�� 16 minutes
            score:      {type: 'integer'},              //�÷�
            killHeroNum: {type: 'integer'},                //��ɱ
            dieNum:     {type: 'integer'},                 //����
            secAttNum:  {type: 'integer'},              //����
            moreKill:   {type: 'integer'},               //��߶�ɱ
            seriesKill: {type: 'integer'},          //��ɱ
            endureDamage: {type: 'integer'},           //���ܵ��˺���
            getMoney:   {type: 'integer'},               //��ý�Ǯ(������)
            totalDamage: {type: 'integer', defaultsTo: 0},            //������˺�
            killBatmen: {type: 'integer', defaultsTo: 0},             //��ɱС��
            killNeutral: {type: 'integer', defaultsTo: 0},           //��ɱ��������
            killBuild:  {type: 'integer', defaultsTo: 0},      //�ݻٽ���(��̨+��Ӫ)
            honor:      {type: 'string'},                //����
            equipInfo:  {type: 'array'},             //װ����Ϣ

            //��ѫ
            evaluate:           {type: 'integer'},
            oldEvaluateLevel:   {type: 'integer'},
            oldEvaluate:        {type: 'integer'},
            curEvaluateLevel:   {type: 'integer'},
            curEvaluate:        {type: 'integer'},

            // Add a reference to User
            owner: {
                model: 'user'
            }
        }
    };

    module.exports = Model;
})();

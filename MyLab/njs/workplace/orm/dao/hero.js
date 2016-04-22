/**
 * Created by Lingg on 2016/4/15.
 */

(function () {
    'use strict';
    var utils = depInj('utils');

    var createData = function (bsID) {
        return {_id: utils.GenUuid(), bsID: bsID, rEquips: [-1, -1, -1, -1, -1, -1]};
    };


    module.exports = {
        createData: createData
    };


})();

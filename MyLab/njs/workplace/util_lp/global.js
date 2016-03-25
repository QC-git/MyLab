
(function () {
	'use strict';
	
	var depInj = {
		userConst: require('../consts/userConst'),
		mgr: function (mgrName) {
			return require('../domain/' + mgrName);
		},
		dao: function (schemaName) {
			return require('../dao/' + schemaName);
		},
		/*
		const: function(constName){
			return require('../consts/'+constName);
		},
		*/
		config: function(confName){
			return require('../../config/'+confName);
		},
		tpl: function(tplName){
			return require('../../config/tpl/'+tplName);
		},
		json: function(jsName){
			return require('../../config/'+jsName + '.json');
		},
		util: function(filename){
			return require('./'+filename);
		},
		utils: require('./utils'),
		utilEx: require("./utilEx"),
		ec: require('../shared/errorCode'),
		base: function(filename){
			return require('../../'+filename);
		}
	};

	global.depInj = function (depName) {
		var dep = depInj[depName];
		if (typeof dep === 'function') {
			var args = Array.prototype.slice.call(arguments, 1);
			return dep.apply(null, args);
		} else {
			return dep;
		}
	};
	global._ = require('underscore');
	global.ec = require('../shared/errorCode');
	global.logger = require('pomelo-logger').getLogger('common', __filename);
})();
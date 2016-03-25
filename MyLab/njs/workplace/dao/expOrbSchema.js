(function () {
	'use strict';

	var mongoose = require('./mongoose').mongoose;
	var userConst = depInj('userConst');
	var ec = depInj('ec');
	var Schema = mongoose.Schema;

	var expOrbSchema = new Schema({
		id: { type: Number},
		count: {type: Number, default: 0}
	});


	exports.schema = expOrbSchema;
	exports.Model = mongoose.model('expOrb', expOrbSchema);
})();

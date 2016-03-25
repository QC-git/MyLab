(function () {
	'use strict';

	var mongoose = require('./mongoose').mongoose;
	var userConst = depInj('userConst');
	var ec = depInj('ec');
	var Schema = mongoose.Schema;

	var skillSchema = new Schema({
		id: { type: Number},
		level: {type: Number, default: 0}
	});


	exports.schema = skillSchema;
	exports.Model = mongoose.model('skill', skillSchema);
})();
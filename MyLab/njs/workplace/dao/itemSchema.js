(function () {
	'use strict';

	var mongoose = require('./mongoose').mongoose;
	var Schema = mongoose.Schema;
	
	var schema = new Schema({
        id: { type: Number },
        num: { type: Number ,default:1},
		durability: {type:Number}
	}, {versionKey: false});

	//schema.pre('save', function (next) {
	//	console.log('===================',this);
	//	next();
	//});

    module.exports.schema = schema;
    module.exports = mongoose.model('item', schema);
})();
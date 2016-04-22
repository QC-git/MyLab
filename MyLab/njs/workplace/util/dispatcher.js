var crc = require('crc');

module.exports.dispatch = function(id, servers) {
	var index = Math.abs(crc.crc32(id) % servers.length);
	return servers[index];
};

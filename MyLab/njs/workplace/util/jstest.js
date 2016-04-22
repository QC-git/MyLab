/**
 * Created by tweyseo on 2015/6/2.
 */

var base = 'E:/MobileApp/local/Server/game-server';
require('pomelo-logger').configure(base + "/config/log4js.json", {serverId: 'logtest', base: base});

var logger = require('pomelo-logger').getLogger('user',__filename);
logger.info('---------------------');


var redis = require('redis');

var gRedis = null;

try {
    gRedis = redis.createClient();
}catch(e) {
    //console.log(e);
}

gRedis.on("error", function (err) {
    //console.error("err = ", err);
});

gRedis.once("ready", function() {
    console.error(arguments);
});

if (0) {
    gRedis.keys("room:1:*", function(err, list) {
        console.log(arguments);
        if (!err) {
            var cmdList = [];
            list.forEach(function(item, i) {
                cmdList.push(['get', item]);
            });
            gRedis.multi(cmdList).exec(function() {
                console.log(arguments);
            });
        }
    });
}

if (1) {
    gRedis.flushdb();
    //gRedis.flushall();
}




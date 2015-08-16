
var util = require("./test_util");
var net = require('net');

var HOST = '127.0.0.1';
var PORT = 1234;

//net.createServer(function(sock) {
//    console.log('CONNECTED: ' + sock.remoteAddress + ':' + sock.remotePort);
//
//    sock.on('data', function(data) {
//        console.log('DATA ' + sock.remoteAddress + ': ' + data);
//        sock.write('You said "' + data + '"');
//    });
//
//    sock.on('close', function(data) {
//        console.log('CLOSED: ' + sock.remoteAddress + ' ' + sock.remotePort);
//    });
//
//}).listen(PORT, HOST);

console.log('Server listening on ' + HOST +':'+ PORT);
var server = net.createServer();
server.listen(PORT, HOST);

server.on('connection', function(sock) {
    console.log('connection: ' + sock.remoteAddress +':'+ sock.remotePort);
    //sock.write("welcome to X net");

    sock.on('close', function() {
        console.log('connection closed: ' + sock.remoteAddress +':'+ sock.remotePort);
    });

    sock.on('error', function(err) {
        //console.log('connection error', err);
    });

    sock.on("data", function(data) {
        console.log('connection data', data);
        console.log(data.toString("utf-8"));
    })

});

server.on("error", function(err) {
    console.log("error:", err);
});
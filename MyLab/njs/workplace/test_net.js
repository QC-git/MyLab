
var net = require('net');

var HOST = '127.0.0.1';
var PORT = 1234;

//net.createServer(function(sock) {
//
//    // ���ǻ��һ������ - �������Զ�����һ��socket����
//    console.log('CONNECTED: ' +
//        sock.remoteAddress + ':' + sock.remotePort);
//
//    // Ϊ���socketʵ�����һ��"data"�¼�������
//    sock.on('data', function(data) {
//        console.log('DATA ' + sock.remoteAddress + ': ' + data);
//        // �ط������ݣ��ͻ��˽��յ����Է���˵�����
//        sock.write('You said "' + data + '"');
//    });
//
//    // Ϊ���socketʵ�����һ��"close"�¼�������
//    sock.on('close', function(data) {
//        console.log('CLOSED: ' +
//            sock.remoteAddress + ' ' + sock.remotePort);
//    });
//
//}).listen(PORT, HOST);
//
//console.log('Server listening on ' + HOST +':'+ PORT);
////�����Ҳ�������Բ�ͬ�ķ�ʽ����TCP���ӣ�����ʽ����"connection"�¼�:
//
//    var server = net.createServer();
//server.listen(PORT, HOST);
//console.log('Server listening on ' +
//    server.address().address + ':' + server.address().port);
//
//server.on('connection', function(sock) {
//
//    console.log('CONNECTED: ' +
//        sock.remoteAddress +':'+ sock.remotePort);
//    // ����������ǰ����ͬ
//
//});

var client = new net.Socket();
client.connect(PORT, HOST, function() {

    console.log('CONNECTED TO: ' + HOST + ':' + PORT);
    //client.write("I am Chuck Norris! hahaha !");
    //client.write("I am Chuck Norris!, 你好，ni hao !");

    var buf = new Buffer("--1,2,3,4,5,6,7,8,9,10,11,12,13,14,15");
    buf[0] = 0;
    buf[1] = 15;
    console.log(buf);
    //client.write(buf);
});

client.on('data', function(data) {

    console.log('DATA: ' + data);
    //client.destroy();
});

client.on('close', function() {
    console.log('Connection closed');
});


var client1 = new net.Socket();
client1.connect(PORT, HOST, function() {

    console.log('1, CONNECTED TO: ' + HOST + ':' + PORT);
    //client.write("I am Chuck Norris! hahaha !");
    //client.write("I am Chuck Norris!, 你好，ni hao !");

    var buf = new Buffer("--1,2,3,4,5,6,7,8,9,10,11,12,13,14,15");
    buf[0] = 0;
    buf[1] = 15;
    console.log(buf);
    client.write(buf);
});

client1.on('data', function(data) {

    console.log('DATA1: ' + data);
    //client.destroy();
});

client1.on('close', function() {
    console.log('Connection1 closed');
});
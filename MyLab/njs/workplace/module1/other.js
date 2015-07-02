

var v1 = -1;
var v2 = -1;
var v3 = -1;
this.v4 = -1;
this.v5 = -1;
//var v6 = -1;

var set_v1 = function(v)
{
    v1 = v;
};

var get_v1 = function()
{
    return v1;
};

var set_v2 = function(v)
{
    v2 = v;
};

var get_v2 = function()
{
    return v2;
};

this.set_v3 = function(v)
{
    v3 = v;
};

this.get_v3 = function()
{
    return v3;
};

this.set_v4 = function(v)
{
    v4 = v;
};

this.get_v4 = function()
{
    return v4;
};

this.set_v5 = function(v)
{
    this.v5 = v;
};

this.get_v5 = function()
{
    return this.v5;
};

function C()
{
    this.v1 = -1;

    this.set_v1 = function(v)
    {
        this.v1 = v;
    };

    this.get_v1 = function()
    {
        return this.v1;
    }
}

function CC()
{
    this.v1 = -1;

    this.set_v1 = function(v)
    {
        this.v1 = v;
    };

    this.get_v1 = function()
    {
        return this.v1;
    }
}

module.exports.set_v2 = set_v2;
module.exports.get_v2 = get_v2;
module.exports.C1 = C;
module.exports.C2 = new C;  //- 任何文件 requore该文件获取的对象都是相同的， 推导：该文件是先被执行装载，再被其它文件调用

//module.exports = CC;
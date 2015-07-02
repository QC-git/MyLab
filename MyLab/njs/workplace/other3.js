



function CC(v)
{
    this.v1 = v;

    this.set_v1 = function(v)
    {
        this.v1 = v;
    };

    this.get_v1 = function()
    {
        return this.v1;
    }
}

module.exports = CC;
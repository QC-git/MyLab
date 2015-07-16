
function adjustFloat(v) {
    return Math.round(v*100)/100;
}

function calcVec(vec1, vec2) {
    var result = 0;
    for (var i= 0, l=vec1.length; i<l; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

function calcEquation(coef, x) {
    return coef.A * x * x + coef.B * x + coef.C;
}

function calcDiv(v1, v2) {
    if ( 0 == v2 ) {
        v2 = 1;
    }
    return v1 / v2;
}

//////////////////////²âÊÔ/////////////////////

console.log(adjustFloat(12321.1251231));
console.log(adjustFloat(12321));
console.log(adjustFloat(12321.0000231));

console.log(calcVec([1, 2, 3], [4, 5, 6]));
console.log(calcVec([1, 2, 3], [4, 5]));

console.log(calcEquation({A:1, B:2, C:3}, 2));

console.log(calcDiv(1, 2));
console.log(calcDiv(1, 0));

//12321.13
//12321
//12321
//32
//NaN
//11
//0.5
//1
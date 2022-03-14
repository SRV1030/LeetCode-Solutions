// https://leetcode.com/problems/ugly-number

/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function(n) {
    for(let i=2;i<6 && n;i++){
        if(n%i===0)n/=i;
    }
    return n===1;
};
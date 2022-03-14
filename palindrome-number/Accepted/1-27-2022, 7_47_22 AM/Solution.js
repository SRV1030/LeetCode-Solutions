// https://leetcode.com/problems/palindrome-number

/**
 * @param {number} x
 * @return {boolean}
 */
const isPalindrome = function(x) {
    if(x<0) return false;
    let dg=[];
    while(x>0){
        dg.push(x%10);
        x=Math.trunc(x/10);
    }
    for(let i=0;i<Math.floor(dg.length/2);i++)
        if(dg[i]!==dg[dg.length-i-1]) return false;
    return true;
};
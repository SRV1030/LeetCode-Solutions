// https://leetcode.com/problems/count-items-matching-a-rule

/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
var countMatches = function(items, ruleKey, ruleValue) {
    let c=0;
    items.forEach((item)=>{
        let v=(ruleKey==="type")?item[0]:(ruleKey==="color")?item[1]:item[2];
        if(v===ruleValue)c++;
    })
    return c;
};
/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let x='';
    let i=0,j=0
    for(;i<word1.length && j<word2.length;){
        if(i<=j)x+=word1[i++];
        else x+=word2[j++]
    }
    while(i<word1.length)x+=word1[i++];
    while(j<word2.length)x+=word2[j++];
    return x;    
};
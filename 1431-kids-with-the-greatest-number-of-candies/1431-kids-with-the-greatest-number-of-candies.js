/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    var mx=candies.reduce((a, b) => Math.max(a, b));;
    var ans=[];
    candies.forEach((i)=>{
            if(i+extraCandies>=mx)ans.push(true);
            else ans.push(false);
        }
      );    
    return ans;
};
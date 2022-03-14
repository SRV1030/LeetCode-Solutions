// https://leetcode.com/problems/find-target-indices-after-sorting-array

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var targetIndices = function(nums, target) {
    nums.sort((a,b)=>{return a-b;});
    let arr=[];
    for(let i=0;i<nums.length;i++)
        if(nums[i]===target)arr.push(i);
    return arr;
};
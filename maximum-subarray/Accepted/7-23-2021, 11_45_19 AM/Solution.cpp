// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lm=0,gm=nums[0];
        for(auto i:nums){
            lm=lm+i;
            if(lm>gm)gm=lm; 
            if(lm<0)lm=0;
        }
        return gm;
    }
};
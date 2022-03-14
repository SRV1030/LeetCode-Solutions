// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

class Solution {
public:
    int mxor=0;
    int rec(vector<int>& nums,int i,int cor){
        if(i==nums.size()) return cor==mxor?1:0;
        if(cor==mxor) return pow(2,nums.size()-i);
        return rec(nums,i+1,cor)+rec(nums,i+1,cor|nums[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto& i:nums)mxor|=i;
        return rec(nums,0,0);
    }
};
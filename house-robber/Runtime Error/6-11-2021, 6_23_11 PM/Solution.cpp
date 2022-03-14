// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int t[n];
        t[0]=nums[0];
        t[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++) t[i]=max(t[i-2]+nums[i],t[i-1]);
        return t[n-1];
        
    }
};
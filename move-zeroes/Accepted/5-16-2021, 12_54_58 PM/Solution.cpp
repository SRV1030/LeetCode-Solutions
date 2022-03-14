// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums)if(i)v.push_back(i);
        int n=nums.size()-v.size();
        while(n--)v.push_back(0);
        nums=v;
    }
};
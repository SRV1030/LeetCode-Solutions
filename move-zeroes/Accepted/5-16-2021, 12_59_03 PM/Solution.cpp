// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int c=0,lp=0;c<n;c++)
            if(nums[c])swap(nums[c],nums[lp++]);
    }
};
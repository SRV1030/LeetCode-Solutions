// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=-1;
        for(int i=0;i<nums.size();i++)
            if(nums[i]) swap(nums[++l],nums[i]);
    }
};
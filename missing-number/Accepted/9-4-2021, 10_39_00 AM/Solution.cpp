// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),r=0;
        for(int i=0;i<n;i++)r^=(i^nums[i]);
        return n^r;
    }
};
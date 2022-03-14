// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0,n=nums.size();
        for(int i=0;i<n;i++) x^=i^nums[i];
        return x^n;
    }
};
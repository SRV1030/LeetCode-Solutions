// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        for(auto& i:nums)x^=i;
        return x;
    }
};
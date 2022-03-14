// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto& i:nums)x^=i;
        return x;
    }
};
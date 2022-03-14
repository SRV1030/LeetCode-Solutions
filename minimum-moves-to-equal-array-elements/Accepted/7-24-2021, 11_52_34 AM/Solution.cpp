// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int r=0;
        for(auto& i:nums)r+=(i-mn);
        return r;
    }
};
// https://leetcode.com/problems/concatenation-of-array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>& n=nums;
        nums.insert(nums.end(),n.begin(),n.end());
        return nums;
        
    }
};
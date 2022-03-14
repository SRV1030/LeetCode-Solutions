// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return max((nums[0]-1)*(nums[1]-1),(nums[nums.size()-1]-1)*(nums[nums.size()-2]-1));
    }
};
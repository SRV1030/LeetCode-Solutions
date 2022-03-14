// https://leetcode.com/problems/maximum-xor-for-each-query

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans;
        int xr =(1<<maximumBit)-1;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
            ans.emplace_back(xr);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
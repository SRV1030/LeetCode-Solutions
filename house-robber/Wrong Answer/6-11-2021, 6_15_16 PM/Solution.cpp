// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int e=0,o=0;
        for(int i=0;i<nums.size();i++){
            if(i%2)o+=nums[i];
            else e+=nums[i];
        }
        return max(o,e);
        
    }
};
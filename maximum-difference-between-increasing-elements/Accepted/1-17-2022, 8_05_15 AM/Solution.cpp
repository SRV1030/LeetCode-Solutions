// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn=nums[0],ans=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>mn) ans=max(ans,nums[i]-mn);
            mn=min(mn,nums[i]);
        }
        return ans;
    }
};
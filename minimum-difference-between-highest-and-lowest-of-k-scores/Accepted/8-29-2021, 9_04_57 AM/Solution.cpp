// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0 || k==1) return 0;
        sort(nums.begin(),nums.end());
        int mn=INT_MAX;
        for(int i=0;i<n-k+1;i++)
            if(mn>(nums[i+k-1]-nums[i]))mn=nums[i+k-1]-nums[i];
        return mn;
    }
};
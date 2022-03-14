// https://leetcode.com/problems/target-sum

class Solution {
public:
    int c=0;
    vector<vector<int>>dp;
    int solve(vector<int>& nums, int s,int i){
        if(s==0) return 1;
        if(i<0) return 0;  
        if(dp[i][s]!=-1)return dp[i][s];
        if(s>=nums[i])return dp[i][s]=solve(nums,s-nums[i],i-1)+solve(nums,s,i-1);
        return dp[i][s]=solve(nums,s,i-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(auto&i:nums)s+=i;
        s=(s-target);
        if(s<0 || s%2==1) return 0;
        s/=2;
        dp=vector<vector<int>>(nums.size()+1,vector<int>(s+1,-1));
        return solve(nums,s,nums.size()-1);
    }
};
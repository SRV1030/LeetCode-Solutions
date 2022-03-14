// https://leetcode.com/problems/coin-change-2

class Solution {
public:
    int dp[301][5001];
    int solve(int i,vector<int>& nums, int target){ 
        if(i==0) return 0;
        if(target==0) return 1; 
        if(dp[i][target]!=-1) return dp[i][target];
        if(nums[i-1]>target) return dp[i][target]=solve(i-1,nums,target);
        return solve(i-1,nums,target)+solve(i,nums,target-nums[i-1]);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
        if(amount == 0) return 1;
        if(n==0) return 0;
        return solve( n, coins,amount);        
    }
};
// https://leetcode.com/problems/combination-sum-iv


// https://leetcode.com/problems/combination-sum-iv/discuss/1701806/comparing-coin-change-2-and-combination-sum-4-
class Solution {
public:
    int dp[10001];
    int solve(int i,vector<int>& nums, int target){          
        if(target==0) return 1;
        if(i==nums.size() || target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        return dp[target]=solve(i,nums,target-nums[i])+solve(i+1,nums,target);
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,target);
    }
};
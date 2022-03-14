// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    long long dp[100001][2];
    int solve(vector<int>& nums,int idx,int sg){
        if(idx==nums.size()) return 0;
        if(dp[idx][sg]!=-1) return dp[idx][sg];
        int o1=solve(nums,idx+1,sg),o2=LLONG_MIN;
        if(sg) o2=nums[idx]+solve(nums,idx+1,0);
        else o2=-nums[idx]+solve(nums,idx+1,1);
        return dp[idx][sg]=max(o1,o2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,1);
    }
};
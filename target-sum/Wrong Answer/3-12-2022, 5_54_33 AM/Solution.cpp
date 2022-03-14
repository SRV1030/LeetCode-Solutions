// https://leetcode.com/problems/target-sum

class Solution {
public:
    int sm=0;
    vector<vector<int>>dp;
    int solve(vector<int>& nums, int s,int i){
        if(i==nums.size()){
            if(s==sm) return 1;
            return 0;
        }  
        if(dp[i][s+1000]!=-1)return dp[i][s+1000];
        return dp[i][s+1000]=solve(nums,s+nums[i],i+1)+solve(nums,s,i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(auto&i:nums)s+=i;
        s=(s-target);
        if(s%2==1) return 0;
        s/=2;
        sm=s;
        dp=vector<vector<int>>(nums.size()+1,vector<int>(s+2000+5,-1));
        return solve(nums,0,0);
    }
};
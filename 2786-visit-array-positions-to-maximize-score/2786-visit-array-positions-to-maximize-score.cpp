class Solution {
public:
    vector<vector<long>> dp;
    int x;
    long solve(vector<int>& nums, int cur,bool isOdd){
        if(cur==size(nums)) return 0;
        if(dp[cur][isOdd]!=-1) return dp[cur][isOdd];
        long o1=solve(nums,cur+1,isOdd);
        long o2=nums[cur]+solve(nums,cur+1,nums[cur]&1);
        if(isOdd!=(nums[cur]&1))o2-=x;
        return dp[cur][isOdd]=max(o1,o2);
    }
    long long maxScore(vector<int>& nums, int x1) {
        dp=vector<vector<long>>(size(nums)+2,vector<long>(2,-1));
        x=x1;
        return solve(nums,0,nums[0]&1);
    }
};
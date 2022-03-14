// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,vector<int> &nums)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=-1e9;
        for(int k=i;k<j;k++)
        {
            int temp=solve(i,k,nums)+solve(k+1,j,nums)+nums[k]*nums[i-1]*nums[j];
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        memset(dp,-1,sizeof(dp));
        return solve(1,nums.size()-1,nums);
    }
};
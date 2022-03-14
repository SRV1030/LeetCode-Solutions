// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool subs(vector<int>& nums,int s){
        int n=nums.size();
        bool dp[n+1][s+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=s;j++){
                if(j==0) dp[i][j]=true;
                else if(i==0) dp[i][j]=false;
                else{
                    if(j>=nums[i-1]) dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    else dp[i][j]= dp[i-1][j];
                }                
            }
        return dp[n][s];
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto&i:nums)s+=i;
        if(s%2) return false;
        return subs(nums,s/2);
    }
};
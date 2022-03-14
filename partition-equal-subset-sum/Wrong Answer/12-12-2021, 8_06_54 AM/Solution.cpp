// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool subsum(vector<int> &nums,int s){
        bool dp[nums.size()+1][s+1];
        for(int i=0;i<=nums.size();i++)
            for(int j=0;j<=s;j++){
                if(j==0)dp[i][j]=true;
                else if(i==0)dp[i][j]=false;
                else{
                    if(nums[i-1]<=j)dp[i][j]=dp[i-1][j]||dp[i][j-nums[i-1]];
                    else dp[i][j]=dp[i-1][j];
                }
            }
        return dp[nums.size()][s];
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto&i:nums)s+=i;
        if(s%2) return false;
        return subsum(nums,s/2);
    }
};
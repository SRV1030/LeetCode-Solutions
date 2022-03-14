// https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations

class Solution {
public:
    vector<vector<int>>dp;
    int MXC=1e9+7;
    int solve(int i,int k,int n,vector<int> &nums){
        if(i==n) return 0;
        if(k<0) return MXC;
        if(dp[i][k]!=-1) return dp[i][k];
        int mxr=0,sr=0,cost=MXC;
        for(int j=i;j<n;j++){
            mxr=max(mxr,nums[j]);
            sr+=nums[j];
            cost=min(cost,mxr*(j-i+1)-sr+solve(j+1,k-1,n,nums));
        }
        return dp[i][k]=cost;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return solve(0,k,n,nums);
    }
};
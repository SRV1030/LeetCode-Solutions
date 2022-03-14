// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int dp[5001][71];    
    int findmat(vector<vector<int>>&mat,int i,int sum,int &target){
        if(i>=mat.size()){
            return abs(sum-target);
        }
        if(dp[sum][i]!=-1){
            return dp[sum][i];
        }
        int ans=INT_MAX;
        for(int j=0;j<mat[i].size();j++){
            ans=min(ans,findmat(mat,i+1,sum+mat[i][j],target));
        }
        return dp[sum][i]=ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat,int target) {
        memset(dp,-1,sizeof(dp));
        int n=mat.size();
        return findmat(mat,0,0,target);
    }
};
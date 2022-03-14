// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1= t1.size(),n2=t2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0)dp[i][j]=0;
                else{
                    if(t1[i-1]==t2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        return dp[n1][n2];
    }
};
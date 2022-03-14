// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int sz=1e4+2,mx=1e9;
    vector<int>dp = vector<int>(sz,mx);
    int numSquares(int n) {
        if(n<=3)return dp[n]=n;
        if(dp[n]!=mx)return dp[n];
        for(int i=1;i*i<=n;i++)
            dp[n]=min(dp[n],1+numSquares(n-i*i));
        return dp[n];
    }
};
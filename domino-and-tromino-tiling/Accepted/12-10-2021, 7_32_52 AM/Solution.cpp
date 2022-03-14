// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int md=1e9+7;
    int numTilings(int n) {
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        int dp[n+1];
        dp[0]=1;dp[1]=1;dp[2]=2;
        for(int i=3;i<=n;i++)dp[i]=((dp[i-1]%md*2)%md+dp[i-3]%md)%md;
        return dp[n]%md;
    }
};
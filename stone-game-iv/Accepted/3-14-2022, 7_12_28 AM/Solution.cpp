// https://leetcode.com/problems/stone-game-iv

class Solution {
public:
    int dp[100001]={0};
    bool winnerSquareGame(int n) {
        if(n==1) return true;
        if(n==2) return false;
        if(dp[n]) return dp[n]==1;
        for(int k=1;k*k<=n;k++)
            if(!winnerSquareGame(n-k*k)){
                dp[n]=1;
                return true;
            }
        dp[n]=-1;
        return false;
    }
};
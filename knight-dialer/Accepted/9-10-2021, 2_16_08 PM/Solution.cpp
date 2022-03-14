// https://leetcode.com/problems/knight-dialer

class Solution {
public: int md=1e9+7;
    int knightDialer(int n) {
        unordered_map<int,vector<int>>mp;
        mp[0]={4,6};
        mp[1]={6,8};
        mp[2]={7,9};
        mp[3]={4,8};
        mp[4]={0,3,9};
        mp[5]={};
        mp[6]={0,1,7};
        mp[7]={2,6};
        mp[8]={1,3};
        mp[9]={2,4};
        vector<vector<int>>dp(n+1,vector<int>(10));
        for(int i=0;i<10;i++)dp[1][i]=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<10;j++)
                for(auto &n:mp[j])
                    dp[i][j]=(dp[i][j]+dp[i-1][n])%md;
        for(int j=0;j<9;j++)
            dp[n][9]=(dp[n][9]+dp[n][j])%md;
        return dp[n][9];
    }
};
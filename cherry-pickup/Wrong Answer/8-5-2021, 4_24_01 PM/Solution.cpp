// https://leetcode.com/problems/cherry-pickup

class Solution {
public: int dp[50][50][50],n;
    int util(int r1,int c1,int c2,vector<vector<int>>& g){
        int r2=c1+r1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || g[r1][c1]==-1 || g[r2][c2]==-1) return 0;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        int ans=g[r1][c1];
        if(c1!=c2)ans+=g[r2][c2];
        int t=max(util(r1+1,c1,c2,g),util(r1,c1+1,c2+1,g));
        t=max(t,util(r1+1,c1,c2+1,g));
        t=max(t,util(r1,c1+1,c2,g));
        return dp[r1][c1][c2]=ans+t;
    }
    int cherryPickup(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
        n=g.size();
        return util(0,0,0,g);
    }
};
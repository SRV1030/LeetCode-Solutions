class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& g,int i,int j,int pv){
        if(min(i,j)<0 || i>=m || j>=n || g[i][j]<=pv ) return -1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+max({solve(g,i-1,j+1,g[i][j]),solve(g,i,j+1,g[i][j]),solve(g,i+1,j+1,g[i][j])});
    }
    
    int maxMoves(vector<vector<int>>& g) {
        m=size(g),n=size(g[0]);
        int mx=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;++i) mx=max(solve(g,i,0,-1),mx);
        return mx;
    }
};
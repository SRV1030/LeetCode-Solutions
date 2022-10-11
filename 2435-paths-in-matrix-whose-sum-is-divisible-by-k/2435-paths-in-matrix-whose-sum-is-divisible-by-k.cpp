class Solution {
public:
    int m,n;
    vector<vector<vector<int>>>dp;
    long md=1e9+7;
    int check(int i,int j,int k,vector<vector<int>>& g,int c_sm){        
        if(i==m-1 && j==n-1){
            if((c_sm+g[i][j])%k) return 0;
            return 1;
        }
        if(i==m || j==n) return 0;
        if(dp[i][j][c_sm]!=-1) return dp[i][j][c_sm];
        int r=check(i+1,j,k,g,(c_sm+g[i][j])%k),d=check(i,j+1,k,g,(c_sm+g[i][j])%k);
        return dp[i][j][c_sm]=(r+d)%md;     
    }
    int numberOfPaths(vector<vector<int>>& g, int k) {
        m=size(g);
        n=size(g[0]);
        dp=vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return check(0,0,k,g,0);        
    }
};
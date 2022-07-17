class Solution {
public:
    int dp[51][51][51],md=1e9+7;
    int findPath(int m, int n, int mx, int i, int j){
        if(i==m || j==n || i<0 || j<0)return 1;
        if(mx==0) return 0;
        if(dp[i][j][mx]!=-1) return dp[i][j][mx];
        int ans=0;
        ans=(ans+findPath(m,n,mx-1,i+1,j))%md;
        ans=(ans+findPath(m,n,mx-1,i-1,j))%md;
        ans=(ans+findPath(m,n,mx-1,i,j+1))%md;
        ans=(ans+findPath(m,n,mx-1,i,j-1))%md;
        return dp[i][j][mx]= ans;
    }
    int findPaths(int m, int n, int mx, int i, int j) {
        memset(dp,-1,sizeof(dp));
        return findPath(m,n,mx,i,j)%md;
    }
};


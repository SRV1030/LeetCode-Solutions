class Solution {
public:
    // bool rc=false;
    int r,c;
    int dp[101][101][205];
    bool solve(vector<vector<char>>& g,int i,int j,int op){
        if(i<0 || i>=r || j<0 || j>=c) return false;
        if(g[i][j]=='(')op++;
        else op--;        
        if(op<0) return false;
        if(dp[i][j][op]!=-1) return  dp[i][j][op]==1;
        if(i==r-1 && j==c-1 && op==0){
           dp[i][j][op]=1; 
           return true; 
        }  
        return dp[i][j][op]=solve(g,i+1,j,op)||solve(g,i,j+1,op);        
    }
    bool hasValidPath(vector<vector<char>>& g) {
        r=g.size(),c=g[0].size();
        memset(dp,-1,sizeof(dp));
        if(g[0][0]==')' || g[r-1][c-1]=='(') return false;
        solve(g,0,0,0);
        return dp[r-1][c-1][0]==1;
    }
};
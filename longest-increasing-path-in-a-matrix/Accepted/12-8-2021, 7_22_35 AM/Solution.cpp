// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    vector<vector<int>> dp;
    int r,c,dis=1;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];
        int cd=1;
        for(int d=0;d<4;d++){
            int x1=i+dx[d], y1=j+dy[d];
            if(x1<0 || x1>=r || y1<0 || y1>=c || matrix[x1][y1]<=matrix[i][j]) continue;
            cd = max(cd, 1+dfs(x1,y1,matrix));
        }
       return dp[i][j]=cd;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r=matrix.size();
        c=matrix[0].size();
        dp=vector<vector<int>>(r+1,vector<int>(c+1,-1));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                dis=max(dis,(dfs(i,j,matrix)));
        return dis;            
    }
};
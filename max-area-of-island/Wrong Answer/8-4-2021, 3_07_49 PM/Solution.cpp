// https://leetcode.com/problems/max-area-of-island

class Solution {
public: int mx,n,m;
    void dfs(vector<vector<int>>& grid,int i,int j,int s){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1) return;
        if(mx<s)mx=s;
        grid[i][j]=2;
        dfs(grid,i+1,j,s+1);
        dfs(grid,i,j+1,s+1);
        dfs(grid,i-1,j,s+1);
        dfs(grid,i,j-1,s+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        mx=0;m=grid.size();n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,1);
                }
            }
        return mx+1;
    }
};
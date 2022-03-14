// https://leetcode.com/problems/max-area-of-island

class Solution {
public: int mx,n,m,s;
    void dfs(vector<vector<int>>& grid,int i,int j,int &s){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1){
            if(mx<s)mx=s;
            return;
        } 
        s++;
        grid[i][j]=2;
        dfs(grid,i+1,j,s);
        dfs(grid,i,j+1,s);
        dfs(grid,i-1,j,s);
        dfs(grid,i,j-1,s);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        mx=0;m=grid.size();n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int s=0;
                    dfs(grid,i,j,s);
                }
            }
        return mx;
    }
};
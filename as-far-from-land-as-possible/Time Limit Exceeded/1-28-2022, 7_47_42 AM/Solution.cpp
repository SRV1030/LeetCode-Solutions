// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int mx=-1;
    void dfs(vector<vector<int>>& grid,int i,int j,int dist){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || (grid[i][j]!=0 && grid[i][j]<=dist)) return;
        // if(dist-1>mx)mx=dist-1;
        grid[i][j]=dist;
        dfs(grid,i+1,j,dist+1);
        dfs(grid,i-1,j,dist+1);
        dfs(grid,i,j+1,dist+1);
        dfs(grid,i,j-1,dist+1);
    }
    int maxDistance(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    dfs(grid,i,j,1);
                } 
        for(auto&i:grid)
            for(auto&j:i)if(j>1 && j-1>mx)mx=j-1;
        return mx;
    }
};
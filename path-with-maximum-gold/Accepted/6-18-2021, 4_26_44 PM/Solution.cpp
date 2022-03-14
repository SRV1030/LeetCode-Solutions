// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:int ans=0,m,n;
    void count(vector<vector<int>>& grid,int i,int j,int c){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return; 
        c+=grid[i][j];
        ans=max(ans,c);
        int v=grid[i][j];
        grid[i][j]=0;
        count(grid,i+1,j,c);
        count(grid,i-1,j,c);
        count(grid,i,j+1,c);
        count(grid,i,j-1,c);
        grid[i][j]=v;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int c=0;
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(grid[i][j]!=0)
                 // cout<<grid[i][j]<<" ";
                     count(grid,i,j,c);
             }
                
        }
           
        return ans;
    }
};
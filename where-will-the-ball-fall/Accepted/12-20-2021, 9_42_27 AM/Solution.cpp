// https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    int r,c;
    int dp[101][101];
    bool isvalid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int finder(vector<vector<int>>& grid,int i,int j){
        if(i==r) return j;  
        if(dp[i][j]!=0)return dp[i][j];
        if(grid[i][j]==1 && isvalid(i,j+1) && grid[i][j+1]==1) return dp[i+1][j+1]=finder(grid,i+1,j+1);
        if(grid[i][j]==-1 && isvalid(i,j-1) && grid[i][j-1]==-1) return dp[i+1][j-1]=finder(grid,i+1,j-1);
        return -1;       
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        memset(dp,0,sizeof(dp));
        vector<int>ans;
        for(int j=0;j<c;j++)ans.push_back(finder(grid,0,j));
        return ans;
        
    }
};
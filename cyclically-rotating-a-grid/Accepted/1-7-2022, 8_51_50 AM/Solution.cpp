// https://leetcode.com/problems/cyclically-rotating-a-grid

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int cnt=0,m=grid.size(),n=grid[0].size(),l=0,u=0,r=n-1,d=m-1;
        while(cnt<m*n){
            vector<int>arr;
            for(int i=l;i<=r;i++,cnt++)arr.push_back(grid[u][i]);
            for(int i=u+1;i<=d;i++,cnt++)arr.push_back(grid[i][r]);
            for(int i=r-1;i>=l;i--,cnt++)arr.push_back(grid[d][i]);
            for(int i=d-1;i>u;i--,cnt++)arr.push_back(grid[i][l]);
            int s=arr.size(),c=0;
            for(int i=l;i<=r;i++,c++)grid[u][i]=arr[(k+c)%s];
            for(int i=u+1;i<=d;i++,c++)grid[i][r]=arr[(k+c)%s];
            for(int i=r-1;i>=l;i--,c++)grid[d][i]=arr[(k+c)%s];
            for(int i=d-1;i>u;i--,c++)grid[i][l]=arr[(k+c)%s];
            l++;
            u++;
            d--;
            r--;
        }
        return grid;
    }
};
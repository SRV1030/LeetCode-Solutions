// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    void solve(vector<vector<int>>& obs,int i,int j,int m,int n,int &c){
        if(i==m-1 && j==n-1)c++;
        if(i+1<m && obs[i+1][j]==0)solve(obs,i+1,j,m,n,c);
        if(j+1<n && obs[i][j+1]==0)solve(obs,i,j+1,m,n,c);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int c=0,i=0,j=0,m=obs.size(),n=obs[0].size();
        if( obs[0][0]==1) return 0;
        solve(obs,i,j,m,n,c);
        return c;
    }
};
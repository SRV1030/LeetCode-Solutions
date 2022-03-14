// https://leetcode.com/problems/unique-paths-ii

class Solution {
public: int t[101][101];
    int solve(vector<vector<int>>& obs,int i,int j,int m,int n,int &c){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(t[i][j]!=-1) return t[i][j];
        if(obs[i][j]==1) return t[i][j]=0;
        t[i][j]=solve(obs,i+1,j,m,n,c)+solve(obs,i,j+1,m,n,c);
        return t[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int c=0,i=0,j=0,m=obs.size(),n=obs[0].size();
        if( obs[0][0]==1) return 0;
        memset(t,-1,sizeof(t));
        
        return solve(obs,i,j,m,n,c);
    }
};
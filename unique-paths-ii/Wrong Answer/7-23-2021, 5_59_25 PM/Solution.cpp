// https://leetcode.com/problems/unique-paths-ii

class Solution {
// public: int t[101][101];
//     int solve(vector<vector<int>>& obs,int i,int j,int m,int n){
//         if(i>=m || j>=n) return 0;
//         if(t[i][j]!=-1) return t[i][j];
//         if(obs[i][j]==1) return t[i][j]=0;        
//         if(i==m-1 && j==n-1) return 1;
//         t[i][j]=solve(obs,i+1,j,m,n)+solve(obs,i,j+1,m,n);
//         return t[i][j];
//     }
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size(),n=obs[0].size();
        int t[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obs[i][j]) t[i][j]=0;
                else if(i==0 || j==0) t[i][j]=1;
                else t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};
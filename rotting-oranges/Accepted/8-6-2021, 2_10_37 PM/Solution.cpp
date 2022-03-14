// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& g,int i,int j,bool start,int c){
        if(i<0 || i>=m || j<0 || j>=n || g[i][j]==0 ||(g[i][j]<0 && -g[i][j]<c)) return;
        if(g[i][j]==2 && !start) return;
        g[i][j]=-c;
        dfs(g,i+1,j,false,c+1);
        dfs(g,i,j+1,false,c+1);
        dfs(g,i-1,j,false,c+1);
        dfs(g,i,j-1,false,c+1);
            
    }
    int orangesRotting(vector<vector<int>>& g) {
        m=g.size(),n=g[0].size();
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(g[i][j]==2){
                   dfs(g,i,j,true,0);
               }
           }
        }
        int mx=0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(g[i][j]==1) return -1;
               mx=max(mx,abs(g[i][j]));
           }
        }
        return mx;
    }
};
// https://leetcode.com/problems/rotting-oranges

class Solution {
public:int m,n;
    void dfs(int i,int j,vector<vector<int>>& g,bool start,int c){
         if(i<0 || i>=m || j<0 || j>=n || g[i][j]==0|| g[i][j]<0 && -g[i][j]<c )
            return;
        if(g[i][j]==2 && !start)
            return;
        g[i][j]=-c;
        dfs(i+1,j,g,false,c+1);
        dfs(i,j+1,g,false,c+1);
        dfs(i-1,j,g,false,c+1);
        dfs(i,j-1,g,false,c+1);
    }
    int orangesRotting(vector<vector<int>>& g) {
        m=g.size();
        n=g[0].size();  
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==2)
                    dfs(i,j,g,true,0);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1)
                    return -1;
                ans=max(ans,abs(g[i][j]));
            }
        }
        return ans;
    }
};
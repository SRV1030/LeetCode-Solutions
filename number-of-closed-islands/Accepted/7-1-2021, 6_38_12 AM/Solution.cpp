// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:int n,m,f;
    void dfs(int i,int j,vector<vector<int>>& g){
         if(i<0||i>=n||j<0||j>=m||g[i][j]!=0)
        {
            if(i<0||i>=n||j<0||j>=m)f=1;
            return;
        }
        g[i][j]=2;
        dfs(i+1,j,g);
        dfs(i,j+1,g);
        dfs(i-1,j,g);
        dfs(i,j-1,g);
    }
    int closedIsland(vector<vector<int>>& g) {
        n=g.size(),m=g[0].size();
        int c=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==0){
                    f=0;
                    dfs(i,j,g);
                    if(f==0)c++;
                }
        return c;
    }
};
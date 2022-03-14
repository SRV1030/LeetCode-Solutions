// https://leetcode.com/problems/count-sub-islands

class Solution {
public:
    int m,n,c=0;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(vector<vector<int>>& g1,vector<vector<int>>& g2,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || g2[i][j]==0 || g2[i][j]==2) return true;
        if(g1[i][j]==0) return false;
        g2[i][j]=2;
        bool r=true;
        for(int d=0;d<4;d++)
            r&=dfs(g1,g2,i+dir[d][0],j+dir[d][1]); 
        return r;
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        m=g1.size(),n=g1[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(g2[i][j]==1){
                    if(dfs(g1,g2,i,j)) c++;
                }
            }
        return c;        
    }
};
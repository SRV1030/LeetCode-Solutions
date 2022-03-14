// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public: int ans=INT_MAX,n;
    void dfs(vector<vector<int>>& g,int i,int j,int c){
        // cout<<c<<" ";
        if(i<0 || j<0 || i>=n || j>=n || g[i][j]!=0) return;
        c++;
        if(i==n-1 && j==n-1)ans=min(ans,c);
        g[i][j]=2;
        dfs(g,i+1,j,c);
        dfs(g,i,j+1,c);
        dfs(g,i-1,j,c);
        dfs(g,i,j-1,c);
        dfs(g,i+1,j+1,c);
        dfs(g,i+1,j-1,c);
        dfs(g,i-1,j+1,c);
        dfs(g,i-1,j-1,c);   
        g[i][j]=0;        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        if(g[0][0]!=0) return -1;
        int c=0;
        n=g.size();
        dfs(g,0,0,c);
        return ans==INT_MAX?-1:ans;
    }
};
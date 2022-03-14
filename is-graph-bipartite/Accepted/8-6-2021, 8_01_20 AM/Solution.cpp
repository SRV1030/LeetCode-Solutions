// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public: bool f=true;
    void dfs(vector<vector<int>>& g,int src,int col ,int p,vector<int>&vis){
        if(!f) return;
        vis[src]=col;
        for(auto i:g[src]){
            if(!vis[i]) dfs(g,i,3-col,src,vis);
            else if(i!=p && vis[i]==vis[src]) f=false;
        }
    }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(g,i,1,-1,vis);
            if(!f) return f;
        }
        return f;
    }
};
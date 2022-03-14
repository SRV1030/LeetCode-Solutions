// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public: bool f=true;
    vector<int> vis;
    void dfs(vector<vector<int>>& g,int src,int col,int p){
        if(!f) return;
        vis[src]=col;
        for(auto& i:g[src]){
            if(!vis[i]) dfs(g,i,3-col,src);
            else if(i!=p && vis[i]==vis[src]) f=false;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {        
        int n=graph.size();
        vis=vector<int>(n);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,i,1,-1);
            if(!f) return f;
        }
        return f;
    }
};
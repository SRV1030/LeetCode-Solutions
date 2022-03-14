// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:bool f=true;
    void dfs(int u,int par,int col,vector<vector<int>>& g,vector<int> &vis){
        vis[u]=col;
        for(auto i:g[u]){
            if(vis[i]==-1) dfs(i,u,3-col,g,vis);
            else if(par!=i && col==vis[i]){
                f=false;
                return;
            } 
        }
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        vector<int>v(g.size(),-1);
        dfs(0,0,1,g,v);
        return f;
        
    }
};
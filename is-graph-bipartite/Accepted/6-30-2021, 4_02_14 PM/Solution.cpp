// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:bool f=true;
    void dfs(int u,int par,int col,vector<vector<int>>& g,vector<int> &vis){
        vis[u]=col;
        for(auto i:g[u]){
            if(vis[i]==-1) dfs(i,u,3-col,g,vis);
            else if(par!=i && col==vis[i]){
                f=false;
                break;
            } 
        }
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        vector<int>v(g.size(),-1);
        for(int i=0;i<g.size();i++){
            if(v[i]==-1)
                dfs(i,-1,1,g,v);
            if(!f) return f;
        }            
        return f;        
    }
};
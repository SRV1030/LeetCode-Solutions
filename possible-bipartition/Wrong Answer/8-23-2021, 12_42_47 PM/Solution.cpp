// https://leetcode.com/problems/possible-bipartition

class Solution {
public:bool f=true;
    void dfs(vector<vector<int>> &g,vector<int>&vis,int col,int src,int p){
        if(!f) return;
        vis[src]=col;
        for(auto& i:g[src]){
            if(!vis[i])
                dfs(g,vis,3-col,i,src);
            else if(i!=p && vis[i]==vis[src]) f=false;
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>g(n+1);
        for(auto& i:dislikes)g[i[0]].push_back(i[1]);
        vector<int>vis(n+1);
        for(int i=1;i<=n;i++){
            if(!vis[i] && !g[i].empty())dfs(g,vis,1,i,-1);
            if(!f) return f;
        }
        return f;
    }
};
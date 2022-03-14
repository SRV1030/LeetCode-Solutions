// https://leetcode.com/problems/flower-planting-with-no-adjacent

class Solution {
public:
    void dfs(vector<vector<int>>& g,vector<int> &vis,int src,int col){
        vis[src]=col;
        for(auto& i:g[src]){
            if(!vis[i]){
                col=col==4?1:col+1;
                dfs(g,vis,i,col);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>vis(n);
        vector<vector<int>>g(n);
        for(auto&e:paths){
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(g,vis,i,1);
        return vis;
    }
};
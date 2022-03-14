// https://leetcode.com/problems/flower-planting-with-no-adjacent

class Solution {
public:
    void dfs(vector<vector<int>>& g,vector<int> &vis,int src){
        vector<int>used(5);
        for(auto& i:g[src])used[vis[i]]=1;
        for(int i=1;i<=4;i++){
            if(!used[i]){
                vis[src]=i;
                break;
            }
        }
        for(auto& i:g[src])
            if(!vis[i])dfs(g,vis,i);
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
                dfs(g,vis,i);
        return vis;
    }
};
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    void dfs(vector<vector<int>> &g,int i,int j,vector<int> &vis,vector<vector<int>> &ans){
        vis[i]=1;
        for(auto&x:g[i]){
            if(!vis[x]){
                ans[x].emplace_back(j);
                dfs(g,x,j,vis,ans);
            }
            
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<vector<int>> ans(n);
        for(auto&i:edges) g[i[0]].push_back(i[1]);        
        for(int i=0;i<n;i++){
            vector<int>vis(n);
            dfs(g,i,i,vis,ans);
        }
        return ans;
    }
};
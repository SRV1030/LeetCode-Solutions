// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double mx=0.0;
    void dfs(vector<vector<pair<int,double>>>&g,vector<int>&vis,int ne,double prob,int end){
        if(ne==end){
            mx=max(mx,prob);
            return;
        }
        vis[ne]=1;
        for(auto&i:g[ne])
            if(!vis[i.first]) dfs(g,vis,i.first,prob*i.second,end);        
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        for(auto&i:g[start]){
            vector<int>vis(n);
            vis[start]=1;
            dfs(g,vis,i.first,i.second,end);
        }
        return mx;
    }
};
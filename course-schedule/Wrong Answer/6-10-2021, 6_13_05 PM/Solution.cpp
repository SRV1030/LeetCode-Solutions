// https://leetcode.com/problems/course-schedule

class Solution {
public: bool cycle=false;
     void dfs(vector<int> &vis,vector<int>g[],int u){
        if(cycle) return;       
        
        for(auto i:g[u]){
            vis[u]=1;
            if(vis[i]==1) cycle=true;
            if(!vis[i]) dfs(vis,g,i);
        }
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>g[n];
        for(auto i:pre)g[i[0]].push_back(i[1]);
        vector<int>vis(n,0);
        cycle=false;
        for(int i=0;i<n;i++)if(!vis[i])dfs(vis,g,i);
        return !cycle;
    }
};
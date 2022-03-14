// https://leetcode.com/problems/course-schedule

class Solution {
public: bool cycle=false;
     void dfs(vector<int> &vis,int p,vector<int>g[],int u){
        if(cycle) return;       
        vis[u]=1;
        for(auto i:g[u]){            
            if(i==p) cycle=true;
            if(!vis[i]) dfs(vis,u,g,i);
        }
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>g[n];
        for(auto i:pre)g[i[1]].push_back(i[0]);
        vector<int>vis(n,0);
        vector<int>visd(n,0);
        cycle=false;
        for(int i=0;i<n;i++)if(!vis[i])dfs(vis,-1,g,i);
        return !cycle;
    }
};
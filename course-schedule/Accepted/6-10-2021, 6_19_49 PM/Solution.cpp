// https://leetcode.com/problems/course-schedule

class Solution {
public: bool cycle=false;
     void dfs(vector<int> &vis,vector<int> &visd,vector<int>g[],int u){
        if(cycle) return;       
        vis[u]=1;
        visd[u]=1;
        for(auto i:g[u]){            
            if(visd[i]==1) cycle=true;
            if(!vis[i]) dfs(vis,visd,g,i);
        }
        visd[u]=0;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>g[n];
        for(auto i:pre)g[i[1]].push_back(i[0]);
        vector<int>vis(n,0);
        vector<int>visd(n,0);
        cycle=false;
        for(int i=0;i<n;i++)if(!vis[i])dfs(vis,visd,g,i);
        return !cycle;
    }
};
// https://leetcode.com/problems/course-schedule

class Solution {
public:vector<vector<int>> g;
        bool cycle=false;
    void dfs(vector<int> &vis,vector<int> &visp,int u){
        if(cycle) return;
        vis[u]=1;
        visp[u]=1;
        for(auto i:g[u]){
            if(visp[i]) cycle=true;
            if(!vis[i] && !cycle)
                dfs(vis,visp,i);
        }
        visp[u]=0;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        g=vector<vector<int>>(n);
        for(auto i:pre)g[i[0]].push_back(i[1]);
        vector<int> vis(n),visp(n);
        for(int i=0;i<n;i++){
             if(!vis[i])
                dfs(vis,visp,i);
            if(cycle) break;
        }           
        return !cycle;
    }
};
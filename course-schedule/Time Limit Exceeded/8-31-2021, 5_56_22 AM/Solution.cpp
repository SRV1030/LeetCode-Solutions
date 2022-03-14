// https://leetcode.com/problems/course-schedule

class Solution {
public: bool cy=false;
    void dfs(vector<vector<int>>g,vector<int>&vis,vector<int>&visP,int src){
        if(cy) return;
        vis[src]=1;
        visP[src]=1;
        for(auto& i:g[src]){
            if(visP[i]) cy=true;
            if(!vis[i] && !cy)
                dfs(g,vis,visP,i);
        }
        visP[src]=0;
    }
    bool canFinish(int nC, vector<vector<int>>& preq) {
        vector<vector<int>>g(nC);
        for(auto& i:preq)g[i[0]].push_back(i[1]);
        vector<int>vis(nC);
        vector<int>visP(nC);
        for(int i=0;i<nC;i++){
            if(!vis[i])
                dfs(g,vis,visP,i);
            if(cy) break;
        }
        return !cy;
    }
};
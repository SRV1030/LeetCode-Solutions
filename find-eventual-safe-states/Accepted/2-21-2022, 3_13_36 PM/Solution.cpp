// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    bool dfs(vector<vector<int>>& g,int i,vector<int>&vis){
        if(vis[i]!=0) return vis[i]==2;
        vis[i]=1;
        for(auto&j:g[i]){
            if(vis[j]==1)  return false;
            if(!vis[j] && !dfs(g,j,vis)) return false;
        }
        vis[i]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<int>ans,vis(g.size(),0);
        for(int i=0;i<g.size();i++)
            if(dfs(g,i,vis)) ans.emplace_back(i);
        return ans;
    }
};
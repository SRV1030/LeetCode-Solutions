// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int> &vis,int src,int trg,int p){
        if(src==trg) return true;
        vis[src]=true;
        for(auto i:g[src]){
            if(src==p && i==trg) continue;
            if(!vis[i])
                if(dfs(g,vis,i,trg,src))
                    return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        vector<vector<int>>g(e.size()+1);
        for(auto i:e){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=e.size()-1;i>=0;i--){
            vector<int>vis(e.size()+1,0);
            if(dfs(g,vis,e[i][0],e[i][1],e[i][0]))
                return e[i];
        }
        return {};
    }
};
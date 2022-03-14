// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    void dfs(vector<vector<int>>& g,int src,vector<int> &vis){
        vis[src]=1;
        for(auto& i:g[src]){
            if(!vis[i])
                dfs(g,i,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>>g(n);
        for(auto& i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int>vis(n);
        int ans=-1;//total separated connections-1 is the answer
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(g,i,vis);
                ans++;
            }
        }
        return ans;
    }
};
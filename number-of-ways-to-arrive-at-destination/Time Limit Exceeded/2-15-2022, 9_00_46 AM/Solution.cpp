// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    int mn=0,c=0;
    vector<int>vis;
    void dfs(int src,int d,vector<vector<pair<int,int>>> &adj,int cost){
        if(cost>mn) return;
        if(src==d){
            if(cost==mn)c++;
            return;
        }
        // vis[src]=1;
        for(auto&j:adj[src]){
            // if(!vis[j.first]) 
            dfs(j.first,d,adj,cost+j.second);
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> paths(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(auto&i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        paths[0]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int i=q.front();
                q.pop();
                for(auto& j:adj[i]){
                    if(paths[j.first]>paths[i]+j.second){
                        paths[j.first]=paths[i]+j.second;
                        q.push(j.first);
                    }
                }
            }
        }
        mn=paths[n-1];
        vis=vector<int>(n);
        dfs(0,n-1,adj,0);
        return c;
    }
};


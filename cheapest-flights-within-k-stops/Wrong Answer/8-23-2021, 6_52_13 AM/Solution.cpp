// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>g(n);
        for(auto& i:flights) g[i[0]].push_back({i[1],i[2]});
        vector<int>dist(n,INT_MAX),vis(n,false);
        dist[src]=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(src);
        k+=1;
        while(!pq.empty() && k--){
            int s=pq.top();
            pq.pop();
            vis[s]=true;
            for(auto& i:g[s]){
                if(!vis[i.first] && dist[i.first]>dist[s]+i.second){
                    dist[i.first]=dist[s]+i.second;
                    pq.push(i.first);
                } 
            }
        }
        return dist[dst]==INT_MAX? -1:dist[dst];
    }
};
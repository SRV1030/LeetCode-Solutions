// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    void addEdge(int u,int v,int wt,vector<pair<int,int>>adj[]){
        adj[u].push_back({v,wt});
        return;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<n;i++)
            addEdge(flights[i][0],flights[i][1],flights[i][2],adj);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // queue<pair<int,int>>pq;
        vector<int>distance(n,INT_MAX);
        pq.push({0,src});
        distance[src] = 0;
        k+=1;
        while(!pq.empty()&&k--){
            int s = pq.size();
            for(int i=0;i<s;i++){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto x:adj[node]){
                if(dist + x.second <=distance[x.first]){
                    distance[x.first] = dist + x.second;
                    pq.push({dist + x.second,x.first});
                    }
                }
            }
        }
        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};
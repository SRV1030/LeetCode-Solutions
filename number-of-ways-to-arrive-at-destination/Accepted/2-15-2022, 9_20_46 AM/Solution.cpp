// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

#define ll long long int

class Solution {
public:
    ll mn=0,c=0,md=1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> paths(n,LONG_MAX),ways(n);
        vector<vector<pair<int,int>>>adj(n);
        for(auto&i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        paths[0]=0;
        ways[0]=1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty()){
           auto [w,i]=pq.top();
           pq.pop();            
           for(auto& j:adj[i]){
               if(paths[j.first]>paths[i]+j.second){
                   paths[j.first]=paths[i]+j.second;
                   ways[j.first]=ways[i];
                   pq.push({paths[j.first],j.first});
               }
               else if(paths[j.first]==j.second+w){
                   ways[j.first]+=ways[i];
                   ways[j.first]%=md;
               }
           }
        } 
        return ways[n-1];
    }
};


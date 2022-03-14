// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:times)mp[i[0]].push_back({i[1],i[2]});
        pq.push({k,0});
        vector<int>dis(n+1,INT_MAX);
        dis[0]=-1;
        dis[k]=0;
        while(!pq.empty()){
            int i=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            if(!mp.count(i))continue;
            for(auto j:mp[i]){
                if(dis[j.first]>j.second+d){
                    dis[j.first]=j.second+d;
                    // cout<<j.first<<" "<<dis[j.first]<<" ";
                    pq.push({j.first,dis[j.first]});
                }
            }
        }
        int mx=-1;
        for(auto i:dis)mx=max(i,mx);
        return mx==INT_MAX?-1:mx;
        
    }
};
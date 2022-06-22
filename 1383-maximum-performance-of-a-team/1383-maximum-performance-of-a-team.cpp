class Solution {
public:
    int md=1e9+7;    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v;
        priority_queue<int,vector<int>,greater<>>pq;
        for(int i=0;i<size(speed);++i)v.push_back({efficiency[i],speed[i]});
        sort(begin(v),end(v));
        long sm=0,mx=0;
        for(int i=size(v)-1;i>=0;--i){
            sm+=v[i].second;
            pq.push(v[i].second);
            while(pq.size()>k){
                sm-=pq.top();
                pq.pop();
            }
            mx=max(mx,sm*v[i].first);
        }
        return mx%md;
    }
};
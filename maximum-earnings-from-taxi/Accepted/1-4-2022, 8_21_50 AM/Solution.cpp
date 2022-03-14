// https://leetcode.com/problems/maximum-earnings-from-taxi

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        for(auto&i:rides)i[2]+=(i[1]-i[0]);
        map<long long,long long>mp;
        sort(rides.begin(),rides.end(),greater<vector<int>>());
        long long mx=0;
        for(auto& r:rides){
            auto j= mp.lower_bound(r[1]);
            long long v=j==mp.end()?0:j->second;
            mx=max(mx,r[2]+v);
            mp[r[0]]=mx;
        }
        return mx;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto& i:mp){
            pq.push({i.second,i.first});
            // cout<<pq.top().second<<" ";
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
        
    }
};
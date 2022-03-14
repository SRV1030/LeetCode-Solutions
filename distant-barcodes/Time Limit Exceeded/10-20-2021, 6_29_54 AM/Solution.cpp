// https://leetcode.com/problems/distant-barcodes

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(auto&i:barcodes)mp[i]++;
        for(auto&[k,v]:mp)pq.push({v,k});
        while(!pq.empty()){
            pair<int,int> f=pq.top();
            pq.pop();
            pair<int,int> s=pq.top();
            pq.pop();
            res.push_back(f.second);
            res.push_back(s.second);
            f.first--;s.first--;
            if(f.first>0) pq.push(f);
            if(s.first>0) pq.push(s);
        }
        return res;
    }
};
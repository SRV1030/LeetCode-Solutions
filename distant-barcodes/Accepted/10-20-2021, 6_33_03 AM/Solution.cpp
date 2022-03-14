// https://leetcode.com/problems/distant-barcodes

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(auto&i:barcodes)mp[i]++;
        for(auto&[k,v]:mp)pq.push({v,k});
        bool fs;
        while(!pq.empty()){
            fs=false;
            pair<int,int> f=pq.top(),s;
            pq.pop();
            if(!pq.empty()){
                s=pq.top();
                pq.pop();
                fs=true;
            }
            res.push_back(f.second);
            if(fs){
                res.push_back(s.second);
                s.first--;
            }
            f.first--;
            if(f.first>0) pq.push(f);
            if(fs && s.first>0) pq.push(s);
        }
        return res;
    }
};
// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    struct comp {
        bool operator() (const pair<int,string> a, const pair<int,string> b) {
            if((a.first < b.first) || ((a.first == b.first) && (a.second >b.second)))
                return true;
            return false;
        }
    };
          
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto& i:words)mp[i]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        for(auto& i:mp)
            pq.push({i.second,i.first});
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
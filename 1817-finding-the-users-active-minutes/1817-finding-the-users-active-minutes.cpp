class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>mp;
        vector<int>ans(k);
        for(auto&i:logs)mp[i[0]].insert(i[1]);
        for(auto&[k,v]:mp)++ans[v.size()-1];
        return ans;
    }
};
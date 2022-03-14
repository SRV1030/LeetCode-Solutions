// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto& i:changed)mp[i]++;
        sort(changed.begin(),changed.end());
        for(auto& i:changed){
            if(mp[i]==0) continue;
            if(mp[2*i]==0 || mp[0]==1) return {};
            ans.push_back(i);
            mp[2*i]--;
            mp[i]--;
        }
        return ans;
    }
};
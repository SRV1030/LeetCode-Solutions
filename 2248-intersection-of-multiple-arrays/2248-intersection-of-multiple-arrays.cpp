class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums)
            for(auto&j:i)mp[j]++;
        set<int>res;
        for(auto&[k,v]:mp){
            if(v==nums.size())res.insert(k);
        }
        return vector<int>(res.begin(),res.end());
    }
};
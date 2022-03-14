// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums)mp[i]++;
        vector<int> ans;
        for(auto&[k,v]:mp)
            if(v==1 && !mp.count(k-1) && !mp.count(k+1))ans.push_back(k);
        return ans;
    }
};
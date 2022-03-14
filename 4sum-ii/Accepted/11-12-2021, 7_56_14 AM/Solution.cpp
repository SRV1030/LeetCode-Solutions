// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mp;
        for(auto& i:nums1)
            for(auto& j:nums2)mp[i+j]++;
        int c=0;
        for(auto& i:nums3)
            for(auto& j:nums4)c+=mp[-(i+j)];
        return c;
    }
};
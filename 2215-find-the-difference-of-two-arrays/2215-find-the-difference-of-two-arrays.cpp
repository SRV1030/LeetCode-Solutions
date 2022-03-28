class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end());
        vector<vector<int>> ans(2);
        for(auto&i:s1)if(!s2.count(i))ans[0].push_back(i);     
        for(auto&i:s2)if(!s1.count(i))ans[1].push_back(i); 
        return ans;
    }
};
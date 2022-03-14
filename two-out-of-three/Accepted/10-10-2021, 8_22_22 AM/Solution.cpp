// https://leetcode.com/problems/two-out-of-three

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int>s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end()),s3(nums3.begin(),nums3.end());
        unordered_map<int,int>mp;
        for(auto&i:s1)mp[i]++;
        for(auto&i:s2)mp[i]++;
        for(auto&i:s3)mp[i]++;
        vector<int> res;
        for(auto& i:mp)if(i.second>=2)res.push_back(i.first);
        return res;
    }
};
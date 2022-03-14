// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(auto&i:nums1)mp[i]++;
        for(auto&i:nums2){
            if(mp.count(i)){
                v.push_back(i);
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        }
        return v;
    }
};
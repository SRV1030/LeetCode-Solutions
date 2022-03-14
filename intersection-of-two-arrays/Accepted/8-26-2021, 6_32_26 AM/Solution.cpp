// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int>mp;
        vector<int>v;
        for(auto&i:nums1)mp[i]++;
        for(auto&i:nums2){
            if(mp.count(i)){
                v.push_back(i);
                mp.erase(i);
            }
        }
        return v;  
    }
};
// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) && abs(mp[nums[i]]-i)<=k) return true;
            mp[nums[i]]=i;
        }
        return false;
    }
};
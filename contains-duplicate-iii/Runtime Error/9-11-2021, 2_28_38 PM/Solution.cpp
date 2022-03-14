// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<=0 || t<0) return false;
        multiset<int>window;
        for(int i=0;i<nums.size();i++){
            if(i>k)window.erase(nums[i-k-1]);
            auto s=window.lower_bound(nums[i]-t);
            if(s!=window.end() && *s<=nums[i]+t) return true;
            window.insert(nums[i]);
        }        
        return false;
    }
};
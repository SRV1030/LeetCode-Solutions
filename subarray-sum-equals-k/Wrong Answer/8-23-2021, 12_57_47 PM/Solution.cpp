// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int s=0,mx=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s==k)mx=i+1;
            if(mp.count(s-k))mx=max(mx,i-mp[s-k]);
            mp[s]=i;
        }
        return mx;
    }
};
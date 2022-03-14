// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto& i:nums)if(!i)i=-1;
        unordered_map<int,int>mp;
        int s=0,mx=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s==0)mx=i+1;
            else if(mp.count(s))mx=max(mx,i-mp[s]);
            else mp[s]=i;
        }
        return mx;
    }
};
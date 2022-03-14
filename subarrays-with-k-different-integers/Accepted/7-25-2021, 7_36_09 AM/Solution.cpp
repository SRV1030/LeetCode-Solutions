// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n=nums.size();
        int i=0,j=0,c=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j++]]++;
            while(mp.size()>k){
                if(mp[nums[i]]==1)mp.erase(nums[i]);
                else mp[nums[i]]--;
                i++;
            }
            c+=(j-i);
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};